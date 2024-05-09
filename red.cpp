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
    cout<<"Lineas de la Red "<<this->nombre<< " \n  numero de lineas : "<<this->numLineas << " \n";

    if(this->lineas.obtenerTamaño() == 0){
        cout<<"No hay lineas en la red " << this->getNombre()<<"\n";
        return ;
    }

    for(int i=0;i<lineas.obtenerTamaño();i++){
        //aqui voy a ingresar a cada linea y luego de ingresar a cada una voy a llamar el metodo que muestra su nombre.
        cout<<lineas[i].getNombre()<<" ";
    }
    cout<<endl;
}

void Red::anadirLinea(char nombre){
    //creamos la linea y ahora la metemos al arreglo de lineas de la red
    this->lineas.anadir(Linea (nombre));
    this->numLineas++;
}


Linea* Red::getLinea(char nombre){
    Linea * lineaPtr;
    for(int i = 0; i<lineas.obtenerTamaño();i++){
        if(nombre == lineas[i].getNombre()){
            lineaPtr = &lineas[i];
            cout<<" \nLinea "<<lineaPtr->getNombre()<<" encontrada con exito ... \n" ;
            //cout<<&lineas[i]<<endl;
            return lineaPtr;
        }
    }
    cout<<"La linea no existe \n";
    return nullptr;

}

Linea* Red::getLineas(){
    return this->lineas.primeraDireccion();

}

int Red::getNumeroDeLineas(){
    return this->lineas.obtenerTamaño();
}

void Red::eliminarLinea(char nombreLinea) {
    //primero recorremos las lineas
    for (int i = 0; i < this->lineas.obtenerTamaño(); i++) {
        if (this->lineas[i].getNombre() == nombreLinea) {
            // Verificamos si la linea tiene estaciones de transferencia
            Estacion* estacion = this->lineas[i].getEstaciones();
            //ahora recorremos cada estacion
            for (int j = 0; j < this->lineas[i].numEstaciones(); j++) {
                if (estacion[j].getIsTransferStation()) {
                    cout << "La linea " << nombreLinea << " no puede ser eliminada porque tiene estaciones de transferencia.\n";
                    return;
                }
            }
            // Si no hay estaciones de transferencia, eliminar la linea
            lineas.eliminarEn(i);
            cout << "La linea " << nombre << " ha sido eliminada.\n";
            return;
        }
    }
    cout << "La linea " << nombre << " no existe.\n";
}
