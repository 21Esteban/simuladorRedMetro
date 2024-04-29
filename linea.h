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

};

#endif // LINEA_H
