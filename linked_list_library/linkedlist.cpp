#include "linkedlist.h"

#include <iostream>

namespace agata {

MyLinkedList::MyLinkedList()
:head(nullptr) {}

MyLinkedList::~MyLinkedList() {

    while (head != nullptr) {
    
        std::cout << "Deleting node " << head->name << std::endl;
        /* before deleting myself, store my pointer as a pointer called next
        so that we can reassign it later on (after the deletion of head) as the new head */
        struct Node* next = head->next;
        delete head;
        head = next;
    }
}

void MyLinkedList::Insert(std::string name) { // inserting at the beginning of the list
    struct Node* node = new Node();
    node->name = name;
    node->next = head;
    head = node;
}

void MyLinkedList::Print() {
    for (struct Node* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->name << std::endl;
    }
}

void MyLinkedList::Delete(std::string name) {
    struct Node* prev = head;
    struct Node* curr = head;

    while (curr != nullptr) {
        /* when the name is found, first connect the current node's next pointer
        to the previous node's next pointer. If one were to delete the current node first, 
        then one would not know what it was pointing to. */
        if (curr->name == name) {
            prev->next = curr->next;
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next; // needed to traverse through the nodes
    }
}

int MyLinkedList::Length(){
    int count = 0;
    for (struct Node* curr = head; curr != nullptr; curr = curr->next) {
        count += 1;
    }
    std::cout << "List length: " << count << std::endl;
    return count;
}

} // namespace agata


