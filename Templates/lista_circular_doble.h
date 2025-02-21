#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "nodo_doble.h"
#include <iostream>
using namespace std;

template<class T>
class Lista_Circular_Doble {
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
Node<T>* Lista_Circular_Doble<T>::buscar_nodo(T data) {
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
void Lista_Circular_Doble<T>::insertar_nodo(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (head == nullptr) {
        // Si la lista está vacía, el nuevo nodo es el único nodo
        newNode->setNext(newNode); // El nuevo nodo apunta a sí mismo
        newNode->setPrev(newNode); // El nuevo nodo también apunta a sí mismo como anterior
        head = newNode;
    } else if (head->getData() >= data) {
        // Insertar al inicio
        Node<T> *last = head->getPrev(); // El último nodo es el anterior al head

        newNode->setNext(head);
        newNode->setPrev(last);

        head->setPrev(newNode);
        last->setNext(newNode);

        head = newNode; // El nuevo nodo es ahora el head
    } else {
        // Insertar en medio o al final
        Node<T> *temp = head;

        while (temp->getNext() != head && temp->getNext()->getData() < data) {
            temp = temp->getNext();
        }

        newNode->setNext(temp->getNext());
        newNode->setPrev(temp);

        temp->getNext()->setPrev(newNode);
        temp->setNext(newNode);
    }
}

template <class T>
bool Lista_Circular_Doble<T>::eliminar_nodo(T data) {
    if (head == nullptr) {
        return false; // Lista vacía
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
        Node<T> *last = head->getPrev(); // El último nodo

        head = head->getNext(); // El nuevo head es el siguiente nodo
        head->setPrev(last);    // El nuevo head apunta al último nodo
        last->setNext(head);    // El último nodo apunta al nuevo head
    } else {
        // Eliminar un nodo en medio o al final
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
    }

    delete temp;
    return true;
}

template<class T>
void Lista_Circular_Doble<T>::print() {
    if (head == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Node<T>* temp = head;
    do {
        cout << temp->getData() << " <-> ";
        temp = temp->getNext();
    } while (temp != head);
    cout << "INICIO" << endl;
}

#endif