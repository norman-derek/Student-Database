/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Template class for binary search tree
*/
#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T k);
        virtual ~TreeNode();

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){ //constructor
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T> 
TreeNode<T>::TreeNode(T k){ //overloaded constructor
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){ //destructor
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        T contains(T value);
        bool deleteNode(T k);
        bool isEmpty();

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d);
        void printNodes();
        void printNodesInorder(); //prints nodes in ascending order 
        void printNodesPostorder(); //prints nodes in descending order
        void recPrint(TreeNode<T> *node);
        void recInorderPrint(TreeNode<T> *node); //recursivley traverses tree in order and prints nodes
        void recPostorderPrint(TreeNode<T> *node); //recursivley traverses tree in postorder
        void recDelete(TreeNode<T> *node); //used to traverse tree to delete nodes in destructor
        
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){ //constructor
    root = NULL;
}

template <class T>
BST<T>::~BST(){ //destructor
    recDelete(root);
    root = NULL;
}

/*
* method recPrint, recursivley prints the nodes in the BST
* Takes single parameter of TreeNode pointer representing the node to start at
*/
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

/*
* method recInorderPrint, traverses the tree recursivley inorder
* Takes single parameter, node, of TreeNode<T> representing the node to start at
*/
template <class T>
void BST<T>::recInorderPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    recInorderPrint(node->left);
    node->key->Print();
    recInorderPrint(node->right);
}

/*
* method recPostorderPrint, recursivley traverses the bst postorder
* Takes single parameter of TreeNode<T>* representing the node to start at
*/
template <class T>
void BST<T>::recPostorderPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    recPostorderPrint(node->right);
    node->key->Print();
    recPostorderPrint(node->left);
}

/*
* method recDelete, recursivley traverses tree to delete nodes. 
* Takes single parameter TreeNode<T>* representing the node to start at
*/
template <class T>
void BST<T>::recDelete(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    recPrint(node->left);
    recPrint(node->right);
    delete node;
}

/*
* method printNodes, prints the entire tree
*/
template <class T>
/* this function prints the entire tree */
void BST<T>::printNodes(){
    recPrint(root);
}

/*
* method printNodesInorder, prints the BST in ascending order
*/
template <class T>
void BST<T>::printNodesInorder(){
    recInorderPrint(root);
}

/*
* method printNodesPostorder, prints the BST in descending order
*/
template <class T>
void BST<T>::printNodesPostorder(){
    recPostorderPrint(root);
}

/*
* method isEmpty, returns if the BST is empty or not
* returns a bool representing if the BST is empty or not
*/
template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

/*
* method getMin, returns the min of the BST
* Returns T* representing a pointer to the min node
*/
template <class T>
T* BST<T>::getMin(){
    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current->left != NULL){
        current = current->left;
    }

    return &(current->key);
}

/*
* method getMax, returns the max of the BST
* Returns T* representing a pointer to the max node
*/
template <class T>
T* BST<T>::getMax(){
    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current->right != NULL){
        current = current->right;
    }

    return &(current->key);
}

/*
* method insert, inserts a node in the BST
* Takes a single parameter T, representing the data to be inserted in the tree
*/
template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    if(isEmpty()){
        root = node;
    } else {
        //the tree is not empty 
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true){
            parent = current;

            if(value->getID() < current->key->getID()){
                //we go left
                current = current->left;
                if(current == NULL){
                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            } else {
                //we go right
                current = current->right;
                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }

    }
}

// template <class T>
// bool BST<T>::Search(T value){
//     if(isEmpty()){
//         return NULL;
//     }
//     TreeNode<T> current = root;

//     while(current->key->getID() != value->getID()){
//         if(value->getID() < current->key->getID()){
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//         if(current == NULL){
//             return NULL;
//         }
//     }

//     return true;
// }

/*
* method contains, checks if the BST contains a piece of data and if it does returns it otherwise it returns null
* Takes single parameter T representing the data you want to check if the BST contains
* Returns T, representing the data that you are checking if the BST contains, returns null if the BST does not contain the input data
*/
template <class T>
T BST<T>::contains(T value){
    if(isEmpty()){
        return NULL;
    }
    TreeNode<T> *current = root;

    while(current->key->getID() != value->getID()){
        if(value->getID() < current->key->getID()){
            current = current->left;
        } else {
            current = current->right;
        }
        if(current == NULL){
            return NULL;
        }
    }


    T data = current->key;
    // delete current;
    return data;
}

/*
* method deleteNode, deletes the node given the data
* Takes single parameter T, representing the node to delete from the BST
* Returns a bool representing whether or not the node was able to be deleted
*/
template <class T>
bool BST<T>::deleteNode(T k){
    if(isEmpty()){
        return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (current->key->getID() != k->getID()){
        parent = current;
        if (k->getID() < current->key->getID()){
            isLeft = true;
            current = current->left;
        } else {
            isLeft = false;
            current = current->right;
        }
        if(current == NULL){
            return false;
        }
    }

    //we found the node/value, now let's proceed to delete
    //could be a leaf, have one child, or have two children
    
    /* no children, node to be deleted is leaf */
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if (isLeft){
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } 
    /*one child, node to be deleted is external node */
    else if (current->right == NULL){
        //node to be deleted has a left child (no right)
        if(current == root){
            root = current->left;
        }
        else if (isLeft){
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }

        }
    else if (current->left == NULL){
        //node to be deleted has a right child (no left)
        if(current == root){
            root = current->right;
        }
        else if (isLeft){
            parent->left = current->right;
        }
        else {
            parent->right = current->right;
        }
    }
    else {
        //node to be deleted has two children. );
        TreeNode<T> *successor = getSuccessor(current);
        
        if(current == root){
            root = successor;
        }
        else if (isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }

        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;

    }

    delete current;
    return true; 

}

/*
* method getSucccessor, get the successor of a node in the BST
* Takes single parameter d representing the node you want the successor of
* returns TreeNode<T>* representing the successor of the node
*/
template <class T>
/* d represents the node to be delete */
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d; //pointer to successors parent
    TreeNode<T> *successor = d; //pointer to successor
    TreeNode<T> *current = d->right; //pointer to current node 

    while (current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    //we found successor but we need to check if the successor is a descendant of the right child. 
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }

}


#endif