#include "estacion.h"
#include <string>

Estacion::Estacion() {
    this->nombre =  ' ';
    this->isTransferStation = false;
}

Estacion::Estacion(string nombre , bool isTransferStation) {
    this->nombre =  nombre;
    this->isTransferStation = isTransferStation;
}


string Estacion::getNombre() const {
    return this->nombre;
}

bool Estacion::getIsTransferStation() const {
    return this->isTransferStation;
}
