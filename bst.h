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
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T> 
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value);
        bool deleteNode(T k);
        bool isEmpty();

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d);
        void printNodes();
        void printNodesInorder(); //prints nodes in ascending order 
        void recPrint(TreeNode<T> *node);
        void recInorderPrint(TreeNode<T> *node); //recursivley traverses tree in order and prints nodes
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    root = NULL;
    //do some research
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void BST<T>::recInorderPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    recInorderPrint(node->left);
    cout << node->key << endl;
    recInorderPrint(node->right);
}

template <class T>
/* this function prints the entire tree */
void BST<T>::printNodes(){
    recPrint(root);
}

template <class T>
void BST<T>::printNodesInorder(){
    recInorderPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

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

            if(value < current->key){
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

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty()){
        return false;
    }
    TreeNode<T> current = root;

    while(current->key != value){
        if(value < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
        if(current == NULL){
            return false;
        }
    }

    return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
    if(isEmpty()){
        return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (current->key != k){
        parent = current;
        if (k < current->key){
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