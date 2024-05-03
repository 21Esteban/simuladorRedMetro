#include <iostream>
#include "red.h"
#include "menu.h"

using namespace std;

int main()
{

    Red metro("metro");

    menu_principal(metro);



    /*metro.getLinea('a');

    metro.anadirLinea('a');
    metro.anadirLinea('b');
    Linea linea = metro.getLinea('a');
    cout<<linea.getNombre();*/

    cout << "Hello World!" << endl;
    return 0;
}
