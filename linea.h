#ifndef LINEA_H
#define LINEA_H
#include<string>
#include"ArrayDinamico.h"
#include"estacion.h"
#include <ctime>
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
    //metodo para obtener una estacion ;

    Estacion* getEstacion(string nombre);

    //anadirEstacion

    void anadirEstacion(string nombre, bool setTransferStation);

    //metodo para obtener los tiempos entre estaciones
    int *getTiempoEntreEstaciones();

    //metodo que me retorna el numero de estaciones de la linea

    int numEstaciones();


    //metodo para imprimir las estaciones
    void mostrarEstaciones();

    void mostrarEstacionesYCostes();

    void eliminarEstacion(string nombre);

    //metodo para calcularTiempoDeLlegada

    time_t calcularTiempoDeLlegada(string estacionSalida, string estacionLlegada, time_t horaSalida);
};

#endif // LINEA_H
