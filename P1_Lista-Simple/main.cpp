#include <iostream>
#include "list.h"
using namespace std;

int main(){
    List<int> lista;

    lista.insertar_nodo(20);
    lista.insertar_nodo(9);
    lista.insertar_nodo(2);
    lista.insertar_nodo(5);
    lista.insertar_nodo(1);

    cout << "Lista: " << endl;
    lista.print();

    lista.eliminar_nodo(5);

    cout << "Lista actualizada: " << endl;
    lista.print();

    return 0;
}