#include "red.h"

Red::Red(string nombre) {
    this->nombre = nombre;
}

string Red::getNombre(){
    return this->nombre;
}

void Red::setNombre(string nombre){
    this->nombre = nombre;
}

//este metodo nos devuelve la primera posicion del arreglo
void Red::mostrarLineas(){
    cout<<"Lineas de la Red "<<this->nombre<< "\n " ;
    for(int i=0;i<lineas.obtenerTamaño();i++){
        //aqui voy a ingresar a cada linea y luego de ingresar a cada una voy a llamar el metodo que muestra su nombre.
        cout<<lineas[i].getNombre();
    }
}

void Red::anadirLinea(char nombre){
    //creamos la linea y ahora la metemos al arreglo de lineas de la red
    this->lineas.anadir(Linea (nombre));
}


Linea Red::getLinea(char nombre){
    for(int i = 0; i<lineas.obtenerTamaño();i++){
        if(nombre == lineas[i].getNombre()){
            cout<<lineas[i].getNombre();
            return lineas[i];
        }
    }
    cout<<"La linea no existe \n";

    return -1;

}
