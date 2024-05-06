#ifndef LINEA_H
#define LINEA_H
#include<string>
#include"ArrayDinamico.h"
#include"estacion.h"
using namespace std;

class Linea
{

private:
    char nombre;
    ArrayDinamico<Estacion> estaciones;
    ArrayDinamico<int> tiempoEntreEstaciones;
public:
    Linea();
    Linea(char nombre);
    char getNombre();
    //metodo para obtener las estaciones de las lineas (retorna la memoria del primer elemento del arreglo)
    Estacion* getEstaciones();
    //metodo para añadir estaciones a la linea

    //anadirEstacion

    void anadirEstacion(string nombre, bool setTransferStation);

    //metodo para obtener los tiempos entre estaciones
    int *getTiempoEntreEstaciones();

    //metodo que me retorna el numero de estaciones de la linea

    int numEstaciones();

    //metodo que se va a ejecutar tambien al añadir una estacion para insetar costo a la linea


    //tener en cuenta que la relacion entre arreglos se va a hacer entre los arreglos mediante indices correspondientes


    //metodo para imprimir las estaciones
    void mostrarEstaciones();
};

#endif // LINEA_H
