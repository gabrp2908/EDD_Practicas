#ifndef COLA_H
#define COLA_H
#include "node.h"
#include "persona.h"
#include <iostream>
using namespace std;

template<class T>
class Cola{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

    public:
        void push_nodo(T data);
        T pop_nodo();
        void print();
        void print_orden();
};

template <class T>
void Cola<T>::push_nodo(T data){
    Node<T> *newNode = new Node<T>(data);
    
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode); 
        tail = newNode;
    }
}

template <class T>
T Cola<T>::pop_nodo(){
    T variable;
    if(head == nullptr){ // Cola vacia
        return variable;
    }

    Node<T> *temp = head;
    variable = temp->getData();
    head = head->getNext();
    delete temp;
    return variable;
}

template <class T>
void Cola<T>::print(){ 
    Node<T> *temp = head;
    while (temp != nullptr){
        cout << temp->getData() << " <- ";
        temp = temp->getNext();
    }
    cout << "Ultimo" << endl;
}

template <class T>
void Cola<T>::print_orden(){ 
    if (head == nullptr) {
        cout << "La cola está vacía." << endl;
        return;
    }
    
    Node<T> *actual = head;
    Node<T> *temp = nullptr;
    T variable;

    //Ordenamiento segun la edad
    while (actual != nullptr) { //Mientras actual no sea null
        temp = actual->getNext(); //temp recorre cada nodo desde head
        while (temp != nullptr) { //Mientras temp no haya llegado al final de la cola
            if (actual->getData().edad > temp->getData().edad) { //Si la edad en el nodo apuntado por actual es mayor a la apuntada por tem
                variable = actual->getData(); //se guarda el valor del nodo apuntado por actual
                actual->setData(temp->getData()); // se pasan los datos de temp a actual
                temp->setData(variable); //se asigna la variable en el nodo apuntado por temp
            }
            temp = temp->getNext(); 
        }
        actual = actual->getNext();
    }

    print();
}

#endif
