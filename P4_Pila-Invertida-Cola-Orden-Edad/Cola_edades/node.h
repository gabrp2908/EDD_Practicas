#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

struct Persona {
    int edad;
    float peso;
    string nombre;
};

template <class T>
class Node {
private:
    T persona;  
    Node<T> *next = nullptr;

public:
    Node(T data, Node<T> *next); // Constructor del nodo
    Node(T data); 
    ~Node();
    T getData(); 
    void setData(T data);
    Node<T> *getNext();
    void setNext(Node<T> *next);
    void print();
};

template <class T>
Node<T>::Node(T data, Node<T> *next) {
    this->persona = data;
    this->next = next;
}

template <class T>
Node<T>::Node(T data) {
    this->persona = data;
    this->next = nullptr;
}

template <class T>
Node<T>::~Node() {
}

template <class T>
T Node<T>::getData() {
    return this->persona;
}

template <class T>
void Node<T>::setData(T data) {
    this->persona = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <class T>
void Node<T>::print() {
    cout << "Nombre: " << this->persona.nombre << ", Edad: " << this->persona.edad << ", Peso: " << this->persona.peso << endl;
    cout << "Siguiente: " << this->next << endl;
}

#endif