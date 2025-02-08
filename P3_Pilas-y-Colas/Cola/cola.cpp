#include <iostream>
#include "cola.h"
using namespace std;

int main(){
    Cola<int> cola;

    cola.push_nodo(5);
    cola.push_nodo(2);
    cola.push_nodo(22);
    cola.push_nodo(10);
    cola.push_nodo(78);
    cola.push_nodo(3);

    cout << "cola: " << endl;
    cola.print();

    cola.pop_nodo();
    cola.push_nodo(8);
    cola.pop_nodo();

    cout << "cola actualizada: " << endl;
    cola.print();

    return 0;
}