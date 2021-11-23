/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Main 
*/

#include "bst.h"

int main(int argc, char** argv)
{
    BST<int> *tree = new BST<int>();

    tree->insert(5);
    tree->insert(30);
    tree->insert(1000);
    tree->insert(3);
    tree->insert(10);
    tree->insert(200);
    tree->printNodesInorder();

    return 0;
}
