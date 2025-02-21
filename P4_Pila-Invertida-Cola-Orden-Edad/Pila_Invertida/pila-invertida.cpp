#include <iostream>
#include "pila.h"
using namespace std;

int main(){
    Pila<int> pila;
    
    pila.push_nodo(5);
    pila.push_nodo(2);
    pila.push_nodo(10);

    cout << "pila original: " << endl;
    pila.print();

    pila.InvertirPila();

    cout << "pila invertida: " << endl;
    pila.print();

    return 0;
}