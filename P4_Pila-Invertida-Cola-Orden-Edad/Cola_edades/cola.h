#ifndef COLA_H
#define COLA_H

#include "node.h"
#include <iostream>
using namespace std;

template<class T>
class Cola {
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    void push_nodo(T data);
    T pop_nodo();
    void print();
    void ordenar();
};

template <class T>
void Cola<T>::push_nodo(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <class T>
T Cola<T>::pop_nodo() {
    T variable;
    if (head == nullptr) { // Cola vacía
        return variable;
    }

    Node<T> *temp = head;
    variable = temp->getData();
    head = head->getNext();
    delete temp;
    return variable;
}

template <class T>
void Cola<T>::print() {
    Node<T> *temp = head;
    while (temp != nullptr) {
        cout << temp->getData().nombre << ", " << temp->getData().edad << ", " << temp->getData().peso << " <- ";
        temp = temp->getNext();
    }
    cout << "Ultimo" << endl << endl;
}

template <class T>
void Cola<T>::ordenar() {
    if (head == nullptr) {
        cout << "La cola esta vacia" << endl;
        return;
    }

    Node<T> *actual = head;
    Node<T> *temp = nullptr;
    T variable;

    while (actual != nullptr) {
        temp = actual->getNext(); //temp apunta al siguiente nodo del apuntado por actual
        while (temp != nullptr) {
            if (actual->getData().edad > temp->getData().edad) { //si el dato del nodo apuntado por actual es mayor al apuntado por tem
                variable = actual->getData(); //se almacena el dato del nodo actual
                actual->setData(temp->getData()); //se asigna a actual los datos de temp
                temp->setData(variable); //se asigna a temp el dato almacenado en variable
            }
            temp = temp->getNext();
        }
        actual = actual->getNext();
    }

    print();
}

#endif