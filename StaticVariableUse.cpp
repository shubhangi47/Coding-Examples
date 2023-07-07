/* Application example of static - To ensure that two objects of the same class receive the same integer value, you can use a static member 
variable shared among all instances of the class.

This approach ensures that any changes made to the static member variable are reflected in all instances of the class, allowing them to share 
the same integer value.
*/


#include <iostream>

class MyClass {
private:
    static int sharedValue;

public:
    int getValue() const {
        return sharedValue;
    }

    void setValue(int value) {
        sharedValue = value;
    }
};

int MyClass::sharedValue = 100;

int main() {
    MyClass obj1, obj2;

    obj1.setValue(42);
    std::cout << "obj1 value: " << obj1.getValue() << std::endl;

    std::cout << "obj2 value: " << obj2.getValue() << std::endl;

    return 0;
}


// output -  obj1 value: 42
//           obj2 value: 42   
			 
// output when obj1.setValue(42); is commented then - 	 obj1 value: 100
//                                                       obj2 value: 100   		 
			 
			 
			 
			 

