#include "linkedlist.hpp"
#include <iostream>


int main() {

    agata::MyLinkedList<std::string> my_list = agata::MyLinkedList<std::string>();

    my_list.Insert("Adam");

    my_list.Insert("Bob");

    my_list.Insert("Cecilia");

    my_list.Print();

    my_list.Length();

    std::cout << "============" << std::endl;

    my_list.Delete("Bob");

    my_list.Print();

    std::cout << "============" << std::endl;
    my_list.Length();

    return 0;
}