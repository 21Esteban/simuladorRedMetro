#ifndef ESTACION_H
#define ESTACION_H
#include<string>

using namespace std;

class Estacion
{

private:
    string nombre;
    bool isTransferStation;

public:
    Estacion();
    //sobrecarga de constructor
    Estacion(string nombre , bool isTransferStation);

    string getNombre() const;
    string getCategoria() const;
    bool getIsTransferStation() const ;
};

#endif // ESTACION_H
