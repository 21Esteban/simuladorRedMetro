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


void Linea::anadirEstacion(string nombre, bool setTransferStation)
{
    short int respuesta;
    short int tiempo;

    // Si no hay estaciones, simplemente añade la nueva estación
    if (this->estaciones.obtenerTamaño() == 0)
    {
        this->estaciones.anadir(Estacion(nombre, setTransferStation));
    }
    else if (this->estaciones.obtenerTamaño() >= 1) // Si ya hay estaciones
    {
        this->mostrarEstaciones();

        // Pregunta al usuario dónde quiere insertar la nueva estación
        do
        {
            cout << " \n Desea agregar la estacion entre en que posicion (las estacion en ese indice no sera eliminada , simplemente se desplazara hacia la derecha) \n";
            cin >> respuesta;

            if (respuesta <= 0 || respuesta > this->estaciones.obtenerTamaño() + 1)
            {
                cout << "Indice no valido. Por favor, intente de nuevo.\n";
            }
        } while (respuesta <= 0 || respuesta > this->estaciones.obtenerTamaño() + 1);

        // Si el usuario quiere añadir la estación al final
        if (respuesta == this->estaciones.obtenerTamaño() + 1)
        {
            this->estaciones.anadir(Estacion(nombre, setTransferStation));
            cout << "cual es el tiempo de recorrido entre la estacion " << this->estaciones[respuesta - 2].getNombre() << " y la estacion " << nombre << " : ";
            cin >> tiempo;
            this->tiempoEntreEstaciones.insertarEn(tiempo, respuesta-2);
            return;
        }
        else // Si el usuario quiere insertar la estación en otra posición
        {
            this->estaciones.insertarEn(Estacion(nombre, setTransferStation), respuesta-1);
        }

        // Si la estación no es la primera, pregunta el tiempo de recorrido
        if (respuesta > 1)
        {
            cout << "cual es el tiempo de recorrido entre la estacion " << this->estaciones[respuesta - 2].getNombre() << " y la estacion " << nombre << " : ";
            cin >> tiempo;
            this->tiempoEntreEstaciones.insertarEn(tiempo, respuesta-2);
        }

        // Pregunta el tiempo de recorrido hasta la siguiente estación
        if (respuesta <= this->estaciones.obtenerTamaño())
        {
            cout << "cual es el tiempo de recorrido entre la estacion " << nombre << " y la estacion " << this->estaciones[respuesta].getNombre() << " : ";
            cin >> tiempo;
            this->tiempoEntreEstaciones.insertarEn(tiempo, respuesta-1);
        }

        //this->mostrarEstacionesYCostes();
    }
}


void Linea::mostrarEstaciones(){

    if(estaciones.obtenerTamaño() == 0){
        cout<<"no hay estaciones en la linea" << this->getNombre() <<"\n";
        return;
    }

    cout<<"Lista de estaciones asociadas a la linea " <<this->getNombre();

    for(int i = 0; i<estaciones.obtenerTamaño();i++){
        cout<<"\n"<<estaciones[i].getNombre()<<"("<<i+1<<")"<< "   ";

    }


}

void Linea::mostrarEstacionesYCostes()
{
    cout << "Lista de estaciones asociadas a la linea " << this->getNombre() << " con sus costes \n";

    for (int i = 0; i < estaciones.obtenerTamaño(); i++)
    {
        cout << estaciones[i].getNombre() ;

        // Solo muestra el coste si el índice es válido en tiempoEntreEstaciones
        if (i < tiempoEntreEstaciones.obtenerTamaño()) {
            cout << " --- " << this->tiempoEntreEstaciones[i] << " --- ";
        }

        //cout << "\n";
    }
}


int Linea::numEstaciones(){
    return this->estaciones.obtenerTamaño();
}
