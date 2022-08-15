#include "linkedlist.h"
#include <iostream>


int main() {

    std::string first_name = "Adam";

    agata::MyLinkedList my_list = agata::MyLinkedList();

    my_list.Insert(first_name);

    std::string second_name = "Bob";

    my_list.Insert(second_name);

    std::string third_name = "Cecilia";

    my_list.Insert(third_name);

    my_list.Print();

    my_list.Length();

    std::cout << "============" << std::endl;

    my_list.Delete("Bob");

    my_list.Print();

    std::cout << "============" << std::endl;
    my_list.Length();
    
    return 0;
}