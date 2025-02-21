#ifndef COLA_H
#define COLA_H
#include "nodo.h"
#include <iostream>
using namespace std;

template<class T>
class Cola{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

    public:
        Node<T>* buscar_nodo(T data);
        void push_nodo(T data);
        T pop_nodo();
        void print();
};

template <class T>
void Cola<T>::push_nodo(T data){
    Node<T> *newNode = new Node<T>(data);
    
    if(head==nullptr){
        newNode->setNext(head);
        head = newNode;
        tail = newNode;
        return;
    } else{
        tail->setNext(newNode); 
        tail = newNode;
    }
};

template <class T>
T Cola<T>::pop_nodo(){
    T variable;
    if(head==nullptr){ //Cola vacia
        return variable;
    };

    Node<T> *temp = head;
    variable = temp->getData();
    head = head->getNext();
    delete temp;
    return variable;
};

template <class T>
void Cola<T>::print(){ 
    Node<T> *temp = head;
    while (temp != nullptr){
        cout << temp->getData() << " <- ";
        temp = temp->getNext();
    }
    cout << "Ultimo" << endl;
    }

#endif