#include "bst3.hpp"



int main() {
    // instantiate the object
    agata::MyBSTree<int> my_tree = agata::MyBSTree<int>();
    my_tree.insert(5);
    my_tree.insert(1);
    my_tree.insert(8);
    my_tree.insert(2);
    my_tree.insert(6);
    my_tree.insert(9);
    my_tree.insert(3);
    my_tree.printValues();
    my_tree.size();

    return 0;
}