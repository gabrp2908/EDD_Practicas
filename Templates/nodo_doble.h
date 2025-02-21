#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <class T>
class Node{
    private:
        T data; //El nodo tiene un dato generico
        Node<T> *next = nullptr; //El nodo tiene un puntero interno
        Node<T> *prev = nullptr;

    public:
        Node(T, Node<T> *); //Constructor del nodo
        Node(T);
        ~Node(); //Destructor
        T getData(); //Devuelve el valor almacenado en data
        void setData(T); //Establece el valor del dato
        Node<T> *getNext(); //Devuelve el puntero al nodo siguiente
        void setNext(Node<T> *); //Establece el puntero al nodo siguiente
        Node<T> *getPrev();
        void setPrev(Node<T> *);
        void print(); //Imprime contenido del nodo
};

template <class T>
Node<T>::Node(T data, Node<T> *next){ //Construye el nodo indicando dato y puntero
    this->data = data;
    this->next = next;
}

template <class T>
Node<T>::Node(T data){ //Construye el nodo indicando solo el dato y definiendo el puntero como null por default
    this->data = data;
}

template <class T>
Node<T>::~Node() { // Definición del destructor
}

template <class T>
T Node<T>::getData(){ //Devuelve el valor dentro del nodo
    return this->data;
}

template <class T>
void Node<T>::setData(T data){ //Se asigna valor al nodo
   this->data = data;
}

template <class T>
Node<T>* Node<T>::getNext(){ //Donde está el puntero
    return this->next;
}

template<class T>
void Node<T>::setNext(Node<T>* next){ //Asignar dirección del puntero
    this->next = next;
}

template <class T>
Node<T>* Node<T>::getPrev(){ //Donde está el puntero
    return this->prev;
}

template<class T>
void Node<T>::setPrev(Node<T>* prev){ //Asignar dirección del puntero
    this->prev = prev;
}

template <class T>
void Node<T>::print(){ //Imprime el valor del dato y la dirección de memoria a la que apunta next
    cout << "Dato del nodo: "<<this->data << endl;
    cout << "Direccion del nodo siguiente: " << this->next << endl;
    cout << "Direccion del nodo anterior: " << this->prev << endl;
}

#endif