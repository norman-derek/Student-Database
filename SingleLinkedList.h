#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        virtual ~ListNode();

        T data;
        ListNode<T> *next;
};

template <class T>
ListNode<T>::ListNode(){
    data = NULL;
    next = NULL;
};

template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
    //research this
    next = NULL; //is this all we need? idk...
}


template <class T>
class SingleLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        SingleLinkedList();
        virtual ~SingleLinkedList();

        ListNode<T>* getFront(); 
        void insertFront(T d);
        T removeFront();
        ListNode<T>* removeNode(T d);
        // int deleteAtPos(int pos);
        ListNode<T>* find(T d);
        bool isEmpty();
        unsigned int getSize();
        void printList();
};

template <class T>
SingleLinkedList<T>::SingleLinkedList(){
    //empty list
    size = 0;
    front = NULL;
    back = NULL;

}

template <class T>
SingleLinkedList<T>::~SingleLinkedList(){
    //research 
    //hint: theres a loop
    ListNode<T>* curr = front;
    while( curr != NULL){
        ListNode<T>* next = curr->next;
        delete curr;
        curr = next;
    }
    front = 0;
}

template <class T>
void SingleLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    node->next = front;
    front = node;
    ++size;
}

template <class T>
ListNode<T>* SingleLinkedList<T>::getFront(){
    return front;
}

template <class T>
T SingleLinkedList<T>::removeFront(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("List is empty!");
    }

    ListNode<T> temp = front;
    ListNode<T>* oldfront = front;
    front = front->next;
    oldfront->next = NULL;
    --size;
    delete oldfront;
    return temp;
}

template <class T>
ListNode<T>* SingleLinkedList<T>::find(T d){
    //int pos = -1;

    ListNode<T>* curr = front;
    while (curr != NULL){
        //++pos;
        if(curr->data == d){
            //return pos;
            break;
        }
        curr = curr->next;
    }
    //check if curr is NULL which signifies value not in linked list
    if(curr == NULL){
        //pos = NULL; // or -1
        return NULL;
    }

    ListNode<T>* temp = curr;
    delete curr;
    return temp;
}

template <class T>
bool SingleLinkedList<T>::isEmpty(){
    return (size == 0);
}

template <class T>
unsigned int SingleLinkedList<T>::getSize(){
    return size;
}

template <class T>
ListNode<T>* SingleLinkedList<T>::removeNode(T value){
    ListNode<T>* node = find(value); //find the node and verify it exists

    if(node == NULL){
        return NULL;
    }

    ListNode<T>* curr = front;
    ListNode<T>* prev = front;

    while (curr != node){
        prev = curr;
        curr = curr->next;
    }

    if(curr == front){
        front = front->next;
        curr->next = NULL;

    } else if (curr == back){
        prev->next = NULL;
        back = prev;
    } else {
        prev->next = curr->next;
        curr->next = NULL;
    }

    --size;
    return curr;
}

template <class T>
void SingleLinkedList<T>::printList(){
    ListNode<T>* curr = front;
    if(isEmpty()){
        throw runtime_error("List is empty!");
    } else {
        cout << "[ ";
        while (curr != NULL){
            if(curr->next == NULL){
                cout << curr->data << " ]" << endl;
            } else {
                cout << curr->data << ", ";
            }

            curr = curr->next;
        }
    }
}

// void SingleLinkedLIst::insertBack(int d){
//     ListNode *node = new ListNode;

//     node->next = NULL;

// }

#endif