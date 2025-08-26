#include <iostream>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <vector>
#include <algorithm>
/*
Steps to create server
1. create the socket
. get the ip and port
. bind the ip and port to the socket
. listen on the socket
. accept
. recv and send
. close the socket
.cleanup the lib
*/

void InteractwithClient(int client_fd,std::vector<int>& clients){
std::cout << "client connected " << std::endl;   

char buffer[1024] = {0};
while(1){
read(client_fd, buffer, 1024);
std::cout << " msg from client : " << buffer << std::endl;

// send message to all other clients
for(auto client : clients){
    if(client != client_fd){
    send(client_fd, buffer, std::strlen(buffer), 0);  
    }
  }
}
auto it = std::find(clients.begin(),clients.end(),client_fd);
if(*it != client_fd){
  clients.erase(it);
}

close(client_fd);
}

int main(){
  std::cout << "server program started" << std::endl;
  // type man socket on linux terminal for complete API socket info ->socket(int domain, int type, int protocol

  int server_fd =  socket( AF_INET,  SOCK_STREAM, 0);

  // Note to check return type of every networking APIs used 
  if(server_fd == -1){
    std::cerr << "Server Socket creation failed\n";
    return -1;
  }

  // create address structure

  /* Note that the address and the port are always stored in network byte order.  In particular, this means that you need to call htons(3) 
  on the number that is assigned to a port.  All address/port manipulation functions in the standard library work in network byte order.*/
  unsigned int port = 12345;
  sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;    /* address family: AF_INET */
  serveraddr.sin_port =htons(port) ;    /* port in network byte order */
  serveraddr.sin_addr.s_addr = INADDR_ANY ; /* internet address ,here local host */

  // bind 
  if (bind(server_fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
    std::cerr << "Bind failed\n";
    close(server_fd);
    return -1;
}
// listen on the sockt 
if (listen(server_fd, 3) < 0) { // 3 indicate the amount of client server can have in queue
    std::cerr << "Listen failed\n";
    close(server_fd);
    return -1;
}
std::cout << "server has started listening on port : " << port << std::endl;

// accept : it connect to the particular client and new socket formed is clientsocket . accept() completes the network handshake, 
//lets us handle each client separately via the socket file descriptor, and even gives us the client address if needed

int addrlen = sizeof(serveraddr);
std::vector<int> clients;
// to accept multiple client request, accept API should be always running ..
while(1){
int client_fd = accept(server_fd, (struct sockaddr*)&serveraddr, (socklen_t*)&addrlen);
if (client_fd < 0) {
    std::cerr << "Accept failed\n";
    close(server_fd);    
    return -1;
}
clients.push_back(client_fd);
std::thread t1(InteractwithClient,client_fd,std::ref(clients));
t1.detach();
}


close(server_fd); 

return 0;
}
