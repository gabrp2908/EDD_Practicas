#ifndef PILA_H
#define PILA_H
#include "../node.h"
#include <iostream>
using namespace std;

template<class T>
class Pila{
    private:
        Node<T> *head = nullptr;

    public:
        void push_nodo(T data);
        T pop_nodo();
        void print();
};

template <class T>
void Pila<T>::push_nodo(T data){
    Node<T> *newNode = new Node<T>(data);
    
    if(head==nullptr){
        newNode->setNext(head);
        head = newNode;
        return;
    }
    newNode->setNext(head);
    head = newNode;
}

template <class T>
T Pila<T>::pop_nodo(){
    T variable;
    if(head==nullptr){ //PILAa vacia
        return variable;
    };

    Node<T> *temp = head;
    variable = temp->getData();
    head = head->getNext();
    delete temp;
    return variable;
};

template <class T>
void Pila<T>::print(){
    Node<T> *temp = head;
    while (head != nullptr){
        cout << pop_nodo() << endl;
    }
    }
#endif