#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "nodo.h"
#include <iostream>
using namespace std;

template<class T>
class Lista_Circular{
    private:
        Node<T> *head = nullptr;

    public:
        Node<T>* buscar_nodo(T data);
        void insertar_nodo(T data);
        bool eliminar_nodo(T data);
        bool lista_vacia();
        void print();
};

template<class T>
Node<T> *Lista_Circular<T>::buscar_nodo(T data){
    if (head == nullptr) return nullptr;

    Node<T> *temp = head;

    do {
        if (temp->getData() == data) {
            return temp;
        }
        temp = temp->getNext();
    } while (temp != head);

    return nullptr;
}

template<class T>
void Lista_Circular<T>::insertar_nodo(T data){
    Node<T> *newNode = new Node<T>(data);

    if (head == nullptr) { // Si la lista está vacía, el nuevo nodo es el único nodo
        newNode->setNext(newNode); // El nuevo nodo apunta a sí mismo
        head = newNode;
    } else if (head->getData() >= data) {// Insertar al inicio
        Node<T> *last = head;
        while (last->getNext() != head) {
            last = last->getNext();
        }
        newNode->setNext(head);
        last->setNext(newNode);
        head = newNode;
    } else {// Insertar en medio o al final
        Node<T> *temp = head;

        while (temp->getNext() != head && temp->getNext()->getData() < data) {
            temp = temp->getNext();
        }

        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }
}

template <class T>
bool Lista_Circular<T>::eliminar_nodo(T data){
    if (head == nullptr) {
        return false;
    }

    Node<T> *temp = head;
    Node<T> *prev = nullptr;

    // Encontrar el nodo a eliminar
    do {
        if (temp->getData() == data) {
            break;
        }
        prev = temp;
        temp = temp->getNext();
    } while (temp != head);

    if (temp->getData() != data) {
        return false; // El nodo no se encontró
    }

    if (temp == head && temp->getNext() == head) {
        // Caso especial: solo hay un nodo en la lista
        head = nullptr;
    } else if (temp == head) {
        // Eliminar el nodo inicial
        Node<T> *last = head;
        while (last->getNext() != head) {
            last = last->getNext();
        }
        head = head->getNext();
        last->setNext(head);
    } else {
        // Eliminar un nodo en medio o al final
        prev->setNext(temp->getNext());
    }

    delete temp;
    return true;
}

template<class T>
void Lista_Circular<T>::print(){
    if (head == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Node<T>* temp = head;
    do {
        cout << temp->getData() << " -> ";
        temp = temp->getNext();
    } while (temp != head);
    cout << "INICIO" << endl;
}

#endif