#include <iostream>

void modifyNumber(int* pointer) {
    // dereferencing and reassigning the value (changing the value the pointer points to)
  *pointer = 12345;
}

int main() {
    int y = 100;
    int x = 42;
    // initialize a pointer to the x variable
    int * x_ptr = &x;

    // print the address of x
    std::cout << x_ptr << ", " << std::to_string(long(x_ptr)) << std::endl;
    
    // pass this pointer as an arg into the func to change the value of x
    modifyNumber(x_ptr);
    
    std::cout << x << ", " << y << std::endl;

    // make the x pointer point to y
    x_ptr = &y;

    // pass the x_ptr again to the func to change the value x_ptr points to
    modifyNumber(x_ptr);

    // x and y should have the same value now
    std::cout << x << ", " << y << std::endl;
    return 0;

}