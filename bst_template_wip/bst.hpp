#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

namespace agata {


template <typename T>
class MyTree{
    public:
    MyTree() //constructor
    :root(nullptr){}

    //destructor
    ~MyTree() {
        //std::cout << "Deleting node..." << node->value<<std::endl;

    }
    // methods: insert, delete, length, print (in-order traversal to get values in sorted order), find?
    void Insert(T value) {
        // create a node
        // assign value
        // if no root, make the node my root
        // traverse - the node's key must be greater than all the keys in its left subtree and less than the ones in its right subtree

    }


private: //making root private + creating a structure Node
    struct Node {
        T value;
        struct Node* left;
        struct Node* right;
    };

    struct Node* root;
};

} //namespace agata

#endif //TREE_HPP
