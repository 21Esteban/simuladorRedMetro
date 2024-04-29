#ifndef RED_H
#define RED_H
#include<string>
#include "ArrayDinamico.h"
#include "linea.h"
using namespace std ;

class Red
{
private:
    string nombre;
    int numLineas = 0;
    ArrayDinamico<Linea> lineas;

public:
    Red(string nombre);
    string getNombre();
    void mostrarLineas();
    void setNombre(string nombre);
    void anadirLinea(char nombre);
    Linea getLinea(char nombre);

};

#endif // RED_H
