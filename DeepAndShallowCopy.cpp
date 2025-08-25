// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
class myclass{
    private:
    char * data =  nullptr ;
    public:
    // constructor to create obj at first place
    myclass(const char* val) {
        std::cout << "obj creating ctor" << " \n" ;
        data = new char[std::strlen(val) + 1];
        std::strcpy(data,val) ;
    }
    // shallow copy constrcutor
    myclass(const myclass& other){
        std::cout << "shallow ctor" << " \n" ;
        data = other.data ;
    }
    // deep copy 
    myclass(const myclass& other,bool deepcopy  ){
        std::cout << "deep ctor" << " \n" ;
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data,other.data) ;
    }
   // Display function
    void display() {
        std::cout << data << std::endl;
    }
    
    // address showing func
    void showaddress(){
        std::cout <<  " address of data  " << static_cast<void*>(data) <<" \n" ;
    }

};
int main() {
    myclass a("hello") ;
    myclass b(a,1); 
    myclass c(a);
    a.display() ;
    a.showaddress() ;
    c.display() ;
    c.showaddress() ;
    b.display();
    b.showaddress() ;

    return 0;
}


/*
Output : 
obj creating ctor 
deep ctor 
shallow ctor 
hello
 address of data  0x396a86c0 
hello
 address of data  0x396a86c0 
hello
 address of data  0x396a86e0 


=== Code Execution Successful ===


*/
