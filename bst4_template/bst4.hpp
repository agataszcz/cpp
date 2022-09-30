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

        // using private helper to prevent users from tinkering with root
        void deleteNode (T value){
            deleteNodeValue(m_root, value);
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

        struct Node* deleteNodeValue(struct Node* curr, T value){
            // search for the value to be deleted from the tree
            if (!curr) return curr;
            // if the value is smaller than root, search the left subtree
            else if (value < curr->value) {
                curr->left = deleteNodeValue(curr->left, value);
            }
            else if (value > curr->value) {
                //same for the right subtree
                curr->right = deleteNodeValue(curr->right, value);
            }
            else { // the value to be deleted was found
                // case 1: leaf node: just delete the leaf node
                if (!curr->left && !curr->right) {
                    delete curr;
                    curr = NULL;
                }
                // case 2: one child
                else if (!curr->left) {
                    struct Node* temp = curr;
                    curr = curr->right;
                    delete temp;
                }
                else if (!curr->right){
                    struct Node* temp = curr;
                    curr = curr->left;
                    delete temp;                    
                }
                // case 3: two children
                else {
                    struct Node* temp = findMin(curr->right);
                    curr->value = temp->value;
                    curr->right = deleteNodeValue(curr->right, temp->value);

                }
            }
            return curr;
        }

        // TODO: implement findMin


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
