#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "nodo_doble.h"
#include <iostream>
using namespace std;

template<class T>
class Lista_Doble{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

    public:
        Node<T>* buscar_nodo(T data);
        void insertar_nodo(T data);
        bool eliminar_nodo(T data);
        bool lista_vacia();
        void print();
};

template<class T>
Node<T> *Lista_Doble<T>::buscar_nodo(T data){
    Node<T> *temp = head;

    while(temp != nullptr && temp->getData() != data){
        temp = temp->getNext();
    }
    return temp;
}

template<class T>
void Lista_Doble<T>::insertar_nodo(T data){
    Node<T> *newNode = new Node<T>(data);

    //Insertar en lista vacia
    if (head==nullptr){
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertar al inicio
    if(head->getData() >=data){  //si el nuevo dato es menor al apuntado por head
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
        return;
    }

    //Insertar al final
    if(tail->getData()<data){ //si el nuevo dato es mayor al apuntado por tail
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
        return;
    }

    //Inserta en medio 
    Node<T> *temp=head;
    while(temp->getNext() != nullptr && temp->getNext()->getData() < data){ 
        newNode->setNext(temp->getNext());
        if(temp->getNext()!=nullptr){
            temp->getNext()->setPrev(newNode);
        }
    }
    newNode->setNext(temp->getNext());
    temp->getNext()->setPrev(newNode);
    temp->setNext(newNode);
    newNode->setPrev(temp);
}

template <class T>
bool Lista_Doble<T>::eliminar_nodo(T data){
    if(head==nullptr){ //Lista vacia
        return false;
    };

    if(head->getData()==data){ //Si nodo al que apunta data es el que se busca (Inicio lista)
        Node<T> *temp = head;
        head = head->getNext(); 
        if(head!=nullptr){
            head->setPrev(nullptr);
        } else {
            tail = nullptr;
        }

        delete temp;
        return true;
    }

    //Final o en medio de la lista
    Node<T> *actual = head;

    while(actual != nullptr && actual->getData() != data){ //Mientras actual no apunte a null ni al dato buscado 
        actual = actual->getNext(); //actual se mueve al siguiente nodo
    }

    if(actual == nullptr){ //El nodo no se encontró
        return false;
    }

    if(actual->getNext() !=nullptr){
        actual->getNext()->setPrev(actual->getPrev());
    } else{
        tail = actual->getPrev();
    }
    
    if(actual->getPrev()!=nullptr){
        actual->getPrev()->setNext(actual->getNext());
    }

    delete actual;
    return true; //Se eliminó el nodo
}

//imprimir lista
template<class T>
void Lista_Doble<T>::print(){
    Node<T>* temp=head;
    while (temp!=nullptr){
        cout << temp->getData() << " <-> ";
        temp = temp->getNext();
    }
    cout << "FIN" << endl;
}


#endif