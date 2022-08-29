#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>

namespace agata {

template <typename T> // T for data type in Node
class MyBSTree {
    public:
        MyBSTree() // constructor with the initializer list
            :root(nullptr), treesize(0) {}

        // destructor calls the private helper method for ease of maintenance
        ~MyBSTree() {
            DeleteTree(root);
        }

        void Insert(const T& value) { // pass by reference since value does not get modified
            // if no root, create one. Otherwise traverse the tree left or right depending on value,
            // keeping track of parent for inserting a node as its left or right child.
            if (!root) {
                root = new Node(value);
                treesize++;
                return;
            }

            struct Node* curr = root;
            struct Node* parent = nullptr;

            while (curr) {
                parent = curr;
                if (curr->value > value) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }

            if (parent->value > value) {
                parent->left = new Node(value);
                treesize++;
            } else {
                parent->right = new Node(value);
                treesize++;
            }
        }

        // traverse inorder to get values in sorted order
        // using the private Inorder helper method for ease of maintenance 
        void Print() {
            Inorder(root);
        }

        void Size(){
            std::cout << "Tree Size: "<< treesize << std::endl;
        }

    private:
        struct Node { // users do not need Node, hence keeping it private
            explicit Node(T value)
                :value(value), left(nullptr), right(nullptr) {}
            T value;
            struct Node* left;
            struct Node* right;
        };

        void Inorder(struct Node* curr) {
            if (curr) {
                Inorder(curr->left); // check my left subtree
                std::cout << curr->value << std::endl;
                Inorder(curr->right); // check my right subtree 
            }
        }

        void DeleteTree(struct Node* curr){ // deleting in post-order manner
            if (curr) {
                DeleteTree(curr->left); // check my left subtree
                DeleteTree(curr->right); // check my right subtree
                std::cout << "Deleting curr " << curr->value <<std::endl;
                delete curr;
            }
        }

        struct Node* root; // making root private for safety
        int treesize; // not needed by users hence keeping this private 
    };

} // namespace agata

#endif // BSTREE_HPP
