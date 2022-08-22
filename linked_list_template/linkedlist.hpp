#ifndef MY_LINKED_LIST_HPP
#define MY_LINKED_LIST_HPP

#include <string>
#include <iostream>

namespace agata {

/**
 * The structure Node is wrapped in a MyLinkedList class
 * for a smoother user experience.
 * This class is designed to do the following:
 * - insert a data (string) into the list
 * - print the data stored in the list
 * - find a specific data (string) in the list and delete its node
 * - print the list length (number of elements stored in the list)
 */

template <typename T>
class MyLinkedList {
    public:
        MyLinkedList()
        :head(nullptr) {}

        ~MyLinkedList() {
            while (head) {

                std::cout << "Deleting node " << head->data << std::endl;
                // before deleting myself, store my pointer as a pointer called next
                // so that we can reassign it later on (after the deletion of head) as the new head
                struct Node* next = head->next;
                delete head;
                head = next;
            }
        }

        // Inserts a data into the list at the list beginning.
        void Insert(const T& data) { // passing by reference since data does not get changed in this method
            struct Node* node = new Node();
            node->data = data;
            node->next = head;
            head = node;
        }

        // Prints all the datas in the list.
        void Print() {
            // for (struct Node* curr = head; curr != nullptr; curr = curr->next) {
            for (Node* curr = head; curr; curr=curr->next) {
                std::cout << curr->data << std::endl;
            }
        }

        // Finds the specific data and deletes its node from the list.
        void Delete(T data) {
            struct Node* prev = head;
            struct Node* curr = head;

            while (curr) {
                // when the data is found, first connect the current node's next pointer
                // to the previous node's next pointer. If one were to delete the current node first, 
                // then one would not know what it was pointing to.
                if (curr->data == data) {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }

                prev = curr;
                curr = curr->next; // needed to traverse through the nodes
             }
        }

        // Returns the list length (the number of elements stored in the list)
        int Length(){
            int count = 0;
            for (Node* curr = head; curr; curr = curr->next) {
                count++;
            }
            std::cout << "List length: " << count << std::endl;
            return count;
        }

    private:
        struct Node {
            T data;
            struct Node* next;
        };
        /*
        the head is private to prevent users from accidentally setting the head
        to NULL which could potentially crash this program.
        */
        struct Node* head;
};

} // namespace agata

#endif // MY_LINK_LIST_HPP