#include "cola.h"

int main() {
    Cola<Persona> cola;

    Persona p1 = {22, 72.5, "Gabriela"};
    Persona p2 = {20, 60.8, "Billy"};
    Persona p3 = {30, 80.1, "Melinna"};
    Persona p4 = {10, 78.2, "Erick"};

    cola.push_nodo(p1);
    cola.push_nodo(p2);
    cola.push_nodo(p3);
    cola.push_nodo(p4);

    cout << "Cola original:" << endl;
    cola.print();

    cout << "Cola ordenada por edad:" << endl;
    cola.ordenar();

    return 0;
}