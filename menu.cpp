#include "menu.h"

void menu_principal(){
    int opcion;

    do {
        cout << "Menu:\n";
        cout << "1. Opcion 1\n";
        cout << "2. Opcion 2\n";
        cout << "3. Opcion 3\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Has seleccionado la opcion 1.\n";
            // Aqui va el codigo para la opcion 1
            break;
        case 2:
            cout << "Has seleccionado la opcion 2.\n";
            // Aqui va el codigo para la opcion 2
            break;
        case 3:
            cout << "Has seleccionado la opcion 3.\n";
            // Aqui va el codigo para la opcion 3
            break;
        case 4:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 4);
}
