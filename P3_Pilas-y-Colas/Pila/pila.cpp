#include <iostream>
#include "pila.h"
using namespace std;

int main(){
    Pila<int> pila;

    pila.push_nodo(5);
    pila.push_nodo(2);
    pila.push_nodo(22);
    pila.push_nodo(10);
    pila.push_nodo(78);
    pila.push_nodo(3);

    cout << "pila: " << endl;
    pila.print();

    pila.pop_nodo();

    cout << "pila actualizada: " << endl;
    pila.print();

    return 0;
}