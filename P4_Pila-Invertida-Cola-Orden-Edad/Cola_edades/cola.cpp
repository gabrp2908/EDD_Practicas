#include <iostream>
#include "cola.h"
#include "persona.h"
using namespace std;

int main(){
    Cola<Persona> cola;

    // Añadir personas a la cola
    cola.push_nodo(Persona(22, 75.2, "Gabriela"));
    cola.push_nodo(Persona(25, 68.3, "Sebastian"));
    cola.push_nodo(Persona(18, 65.3, "Enger"));
    cola.push_nodo(Persona(32, 80.2, "Melinna"));

    // Imprimir la cola en el orden original
    cout << "Cola en orden original:" << endl;
    cola.print();

    // Imprimir la cola ordenada por edad
    cout << "Cola ordenada por edad:" << endl;
    cola.print_orden();

    return 0;
}
