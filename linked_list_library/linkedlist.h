#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <string>

namespace agata {

/**
The structure Node has two parts: name (type string)
and a pointer called next pointing to the next node
*/
struct Node {
    std::string name;
    struct Node* next;
};

/**
 * The structure Node is wrapped in a MyLinkedList class
 * for a smoother user experience.
 * This class is designed to do the following:
 * - insert a name (string) into the list
 * - print the names stored in the list
 * - find a specific name (string) in the list and delete its node
 * - print the list length (number of elements stored in the list)
 */

class MyLinkedList {
    public:
        MyLinkedList();

        // Remember to free all the memory.
        ~MyLinkedList();

        // Inserts a name into the list at the list beginning.
        void Insert(std::string name);

        // Prints all the names in the list.
        void Print();

        // Finds the specific name and deletes its node from the list.
        void Delete(std::string name);

        // Returns the list length (the number of elements stored in the list)
        int Length();

    private:
        /*
        the head is private to prevent users from accidentally setting the head
        to NULL which could potentially crash this program.
        */
        struct Node* head;
};

} // namespace agata

#endif // MY_LINK_LIST_H