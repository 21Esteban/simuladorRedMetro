#include <iostream>
#include "red.h"


using namespace std;

int main()
{

    Red metro("metro");

    metro.getLinea('a');

    metro.anadirLinea('a');
    metro.anadirLinea('b');
    Linea linea = metro.getLinea('a');
    cout<<linea.getNombre();

    cout << "Hello World!" << endl;
    return 0;
}
