#ifndef ESTACION_H
#define ESTACION_H
#include<string>

using namespace std;

class Estacion
{

private:
    string nombre;
    string categoria;

public:
    Estacion();
    //sobrecarga de constructor
    Estacion(string nombre , string categoria);

    string getNombre() const;
    string getCategoria() const;
};

#endif // ESTACION_H
