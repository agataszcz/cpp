#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>

namespace agata {

template <typename T> // T for data type in Node
class MyBSTree {
    public:
        MyBSTree() // constructor with the initializer list
            :m_root(nullptr) {}

        // destructor calls the private helper method for ease of maintenance
        ~MyBSTree() {
            deleteTree(m_root);
        }

        // passing by reference since value does not get modified; 
        // calling a private helper method for safety and ease of maintenance
        void insert(const T& value) {
            insertRecursive(m_root, value);
        } 
            
        // traverse inorder to get values in sorted order
        // using the private printInorder helper method for ease of maintenance 
        void printValues() {
            printInorder(m_root);
        }

        // calling a private helper method for ease of maintenance
        void size() {
            std::cout << "Tree Size: " << getSize(m_root) << std::endl;
        }

    private:
        struct Node { // users do not need Node, hence keeping it private
            explicit Node(T value)
                :value(value), left(nullptr), right(nullptr) {}
            T value;
            struct Node* left;
            struct Node* right;
        };

        void deleteTree(struct Node* curr){ // deleting in post-order manner
            if (curr) {
                deleteTree(curr->left); // check my left subtree
                deleteTree(curr->right); // check my right subtree
                std::cout << "Deleting curr " << curr->value <<std::endl;
                delete curr;
            }
        }

        // calculate the tree size recursively by adding nodes in the left subtree to the nodes in the right subtree
        // and adding 1 for the root node
        int getSize(struct Node* curr) {
            // base case: empty tree (no root)
            if (!curr) return 0;
            return 1 + getSize(curr->left) + getSize(curr->right);
        }

        // passing node* by reference to make sure that the head (curr) gets updated correctly
        void insertRecursive(struct Node* &curr, const T& value) {
            if (!curr) {
                curr = new Node(value);
                return;
            }
            // if the given value is less than root node, recur for the left subtree; otherwise recur for the right subtree
            if (value < curr->value){
                insertRecursive(curr->left, value);
            }
            else {
                insertRecursive(curr->right, value);
            }
        }

        void printInorder(struct Node* curr) {
            if (curr) {
                printInorder(curr->left); // check my left subtree
                std::cout << curr->value << std::endl;
                printInorder(curr->right); // check my right subtree
            }
        }

        struct Node* m_root; // making root private for safety
    };

} // namespace agata

#endif // BSTREE_HPP
