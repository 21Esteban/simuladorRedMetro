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

//metodo para obtener las estaciones de las lineas

//para poder obtener las esataciones , primero vamos a acceder a el arreglo de estaciones y vamos a obtener el arrayPtr para asi poder obtener todos los elementos , aunque vamos a tener otro metodo que nos los imprima

Estacion* Linea::getEstaciones(){
    return this->estaciones.primeraDireccion();

}

int* Linea::getTiempoEntreEstaciones(){
    return this->tiempoEntreEstaciones.primeraDireccion();

}



void Linea::mostrarEstaciones(){

    if(estaciones.obtenerTamaño() == 0){
        cout<<"no hay estaciones en la linea" << this->getNombre() <<"\n";
        return;
    }

    for(int i = 0; i<estaciones.obtenerTamaño();i++){
        cout<<estaciones[i].getNombre();
    }
}


int Linea::numEstaciones(){
    return this->estaciones.obtenerTamaño();
}
