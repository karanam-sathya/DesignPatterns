//Facade pattern hides the complexities of the system and provides
//an interface to the client using which the client can access the system.
//This type of design pattern comes under structural pattern as this pattern
//adds an interface to existing system to hide its complexities.
//Example say we are using different APIs from different libraries to perform some specific task.
//than instead of writing that code in client we will provide an Facade class to the client. which
//will do all the operations of the libraries in a structured way.
#include <iostream>

// Complex subsystems
class Subsystem1 {
public:
    void operation1() {
        std::cout << "Subsystem1 operation1\n";
    }
};

class Subsystem2 {
public:
    void operation2() {
        std::cout << "Subsystem2 operation2\n";
    }
};

class Subsystem3 {
public:
    void operation3() {
        std::cout << "Subsystem3 operation3\n";
    }
};

// Facade
class Facade {
public:
    void operation() {
        subsystem1.operation1();
        subsystem2.operation2();
        subsystem3.operation3();
    }
private:
    Subsystem1 subsystem1;
    Subsystem2 subsystem2;
    Subsystem3 subsystem3;
};

// Client code
int main() {
    Facade facade;
    facade.operation();
    return 0;
}
