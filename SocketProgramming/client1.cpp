#include <iostream>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <thread>




/*
Steps to create client
1. create socket
2. connect to server
3. send and receive
4. close the socket
*/
void SendMessage(int client_fd){
    std::cout << " enter your chat name : " << std::endl;
    std::string name;
    std::getline(std::cin,name);
    std::string message;
    while(1){
    std::getline(std::cin,message);
    std::string msg =  name + " : " + message ;
    if (send(client_fd, msg.c_str(), msg.size(), 0) < 0 ){
        std::cout << "error sending message " <<std::endl;
        break;
    }
    if(message == "quit"){
         std::cout << " stopping application  " <<std::endl;
        break;

    }
}
 close(client_fd);
}

void ReceiveMessage(int client_fd){

 char buffer[4096]; 
 std::string msg = "";
 while(1){
    if(read(client_fd, buffer, 4096) < 0 ){
    std::cout << "error reading message " <<std::endl;
    break;
    }else{
        msg = std::string(buffer,strlen(buffer));
       std::cout << msg <<std::endl;  
    }    
}
 close(client_fd);
}
int main(){

std::cout << "client program started" << std::endl;

int client_fd =  socket( AF_INET,  SOCK_STREAM, 0);

  // Note to check return type of every networking APIs used 
  if(client_fd == -1){
    std::cerr << "Client Socket creation failed\n";
    return -1;
  }

  // Server address
  unsigned int port = 12345;
  sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;    /* address family: AF_INET */
  serveraddr.sin_port =htons(port) ;    /* port in network byte order */
  serveraddr.sin_addr.s_addr = INADDR_ANY ; /* internet address ,here local host */


    // Connect to server
    if (connect(client_fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        std::cerr << "not able to connect to server \n";
        close(client_fd);
        return -1;
    }
    std::cout << "client has successfully connected to server : " << std::endl;

    std::thread senderThread(SendMessage,client_fd);
    std::thread receiveThread(ReceiveMessage,client_fd); 
    senderThread.join();
    receiveThread.join();

    return 0 ;
}
