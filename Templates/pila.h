#ifndef PILA_H
#define PILA_H
#include "nodo.h"
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
        void InvertirPila();
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
    if(head==nullptr){ //PILA vacia
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
    while (temp != nullptr){
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
};

template <class T>
void Pila<T>::InvertirPila(){
    Pila<T> Aux1;
    Pila<T> Aux2;

    Node<T> *temp = head;

    // Pasar de la pila original a Auxiliar 1
    while (temp != nullptr) {
        Aux1.push_nodo(temp->getData());
        temp = temp->getNext();
    }

    // Pasar de la Auxiliar1 a Auxiliar2
    while (Aux1.head != nullptr) {
        Aux2.push_nodo(Aux1.pop_nodo());
    }

    // Reiniciar la pila original
    head = nullptr;

    // Pasar de Auxiliar2 a Original
    while (Aux2.head != nullptr) {
        push_nodo(Aux2.pop_nodo());
    }
}

#endif