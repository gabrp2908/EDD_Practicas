#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream> // Necesario para std::ostream
using namespace std;

class Persona {
public:
    int edad;
    float peso;
    string nombre;

    // Constructor por defecto
    Persona() : edad(0), peso(0.0), nombre("") {}

    // Constructor con parámetros
    Persona(int e, float p, string n) : edad(e), peso(p), nombre(n) {}
};

// Sobrecarga del operador << como función no miembro
ostream& operator<<(ostream& os, const Persona& p) {
    os << "Nombre: " << p.nombre << ", Edad: " << p.edad << ", Peso: " << p.peso;
    return os;
}

#endif