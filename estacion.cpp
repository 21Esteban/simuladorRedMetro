#include "estacion.h"
#include <string>

Estacion::Estacion() {
    this->nombre =  ' ';
    this->categoria = "normal";
}

Estacion::Estacion(string nombre , string categoria) {
    this->nombre =  nombre;
    //importante,,, Hay que hacer una validacion para la categoria , que solo se reciban los siguientes estados [normal,transferencia]
    this->categoria = categoria;
}


string Estacion::getNombre() const {
    return this->nombre;
}

string Estacion::getCategoria() const {
    return this->categoria;
}
