#include "bst2.hpp"



int main() {
    // instantiate the object
    agata::MyBSTree<int> my_tree = agata::MyBSTree<int>();
    my_tree.Insert(5);
    my_tree.Insert(1);
    my_tree.Insert(8);
    my_tree.Insert(2);
    my_tree.Insert(6);
    my_tree.Insert(9);
    my_tree.Print();
    my_tree.Size();

    return 0;
}