#include "linea.h"

//constructor por defecto

Linea::Linea() {
    this->nombre = ' ';  // o cualquier valor por defecto que quieras
}

Linea::Linea(char nombre) {
    this->nombre = nombre;
}

char Linea::getNombre(){
    return this->nombre;
}
