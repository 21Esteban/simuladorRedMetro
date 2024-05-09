#include <iostream>
#include "red.h"
#include "menu.h"

using namespace std;

int main()
{

    Red metro("metro");

    menu_principal(metro);



    cout << "Programa finalizado con exito!" << endl;
    return 0;
}
