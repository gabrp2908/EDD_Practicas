#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>
using namespace std;

template<class T>
class List{
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
Node<T> *List<T>::buscar_nodo(T data){
    Node<T> *temp = head;

    while(temp != nullptr && temp->getData() != data){
        temp = temp->getNext();
    }
    return temp;
}

template<class T>
void List<T>::insertar_nodo(T data){
    Node<T> *newNode = new Node<T>(data);

    // Insertar al inicio
    if(head==nullptr || head->getData() >= data){ //head es null
        newNode->setNext(head); //nuevo nodo apunta al no apuntado por actualmente
        head = newNode; //head apunta al nuevo nodo
        return;
    }
    
    //Insertar en medio o al final
    Node<T> *temp = head;

    while(temp->getNext() != nullptr && temp->getNext()->getData() < data){ //temp no es null y nodo siguiente es menor al que quiero ingresar
        temp = temp->getNext(); //temp se mueve al siguiente nodo
    }

    newNode->setNext(temp->getNext()); //nuevo nodo apunta al siguiente nodo de temp
    temp->setNext(newNode); //temp apunta a nuevo nodo

}

template <class T>
bool List<T>::eliminar_nodo(T data){
    if(head==nullptr){ //Lista vacia
        return false;
    };

    if(head->getData()==data){ //Si nodo al que apunta data es el que se busca (Inicio lista)
        Node<T> *temp = head;
        head = head->getNext(); //head apunta al siguiente nodo
        delete temp;
        return true;
    }

    //Final o en medio de la lista
    Node<T> *actual = head;
    Node<T> *prev = nullptr;

    while(actual != nullptr && actual->getData() != data){ //Mientras actual no apunte a null ni al dato buscado
        prev = actual; //prev se posiciona en actual
        actual = actual->getNext(); //actual se mueve al siguiente nodo
    }

    if(actual == nullptr){ //El nodo no se encontró
        return false;
    }

    prev->setNext(actual->getNext()); //actualiza puntero next del nodo anterior al borrado para que apunte al siguiente del borrado

    delete actual;
    return true; //Se eliminó el nodo
}

//imprimir lista
template<class T>
void List<T>::print(){
    Node<T>* temp=head;
    while (temp!=nullptr){
        cout << temp->getData() << " -> ";
        temp = temp->getNext();
    }
    cout << "FIN" << endl;
}


#endif