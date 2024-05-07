#include "menu.h"
#include "red.h"
#include <cstdlib>
//simular un timeout para mejorar la experiencia de usuario
#include <thread>
#include <chrono>
#include "estacion.h"

void menu_principal(Red redMetro){

    int opcion;
    char nombre;
    Linea *linea;

    Estacion *estacion;

    string nombreEstacion;
    bool transferStation;

    do {
       // system("cls");
        cout << "Menu:\n";
        cout << "1. Agregar una linea\n";
        cout << "2. Agregar estacion\n";
        cout << "3. Eliminar una estacion\n";
        cout << "4. Saber cuantas lineas hay en la red Metro\n";
        cout << "6. Buscar estacion en una linea\n";
        cout << "7. Eliminar linea de la red Metro (solo pueden eliminarse las que no tengan estaciones de transferencia) \n";
        cout << "8. Saber cuantas estacione tiene la red Metro\n";

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << " \n Agregar una linea .\n";
            // Aqui va el codigo para la opcion 1
            //funcion para validar el nombre de la linea
            nombre = validarNombreLinea();
            redMetro.anadirLinea(nombre);
            cout<<" Linea creada correctamente ...\n\n";
            //timeout
            this_thread::sleep_for(chrono::seconds(2));
            break;
        case 2:

            cout << " \n Agregar estacion .\n";
            // Aqui va el codigo para la opcion 2
            //funcion para validar la creacion de la estacion,
            redMetro.mostrarLineas();

            linea = buscarLinea(redMetro,true);

            if(linea == nullptr){
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }

            //funcion que pregunta que nombre se le va a colocar a la estacion
            nombreEstacion = validarNombreEstacion(linea);
            transferStation = validateSetIsTransferStation();

           // linea->mostrarEstaciones();

            //funcion que lo que va a hacer es , si no hay estaciones entonces no va a hacer nada , si hay una estacion va a decir entre

            linea->anadirEstacion(nombreEstacion,transferStation);
            cout<<"Estacion creada con exito \n";

            linea->mostrarEstacionesYCostes();


           this_thread::sleep_for(chrono::seconds(2));
            break;
        case 3:
            cout << "\n Eliminar estacion .\n";
            redMetro.mostrarLineas();
            linea = buscarLinea(redMetro,false);
            //una vez buscada la linea lo que debemos hacer es mostrar las estaciones de esa linea y luego preguntar que estacion eliminar

            if(linea == nullptr){
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }

            linea->mostrarEstaciones();
            //validamos que esa estacion se encuentre en esa linea

            cout <<"Ingrese el nombre de la estacion a eliminar : \n";
            cin>>nombreEstacion;

            //aqui , agregar una funcion que valide que el nombre si se encuentre en la estacion !!!!!!!

            linea->eliminarEstacion(nombreEstacion);

            linea->mostrarEstacionesYCostes();

            cout<<" \n Estacion eliminada correctamente \n";

             this_thread::sleep_for(chrono::seconds(3));
            break;
        case 4:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    } while (opcion < 8);
}

char validarNombreLinea(){
    char nombre;
    cout<<"Ingrese el nombre de la linea (solo 1 caracter): \n";
    cin>>nombre;
    return nombre;
}


 Linea *buscarLinea(Red& redmetro , bool opcion){
    char linea;



    if(redmetro.getNumeroDeLineas() == 0){
        cout<<"no puedes agregar estaciones porque no hay lineas en la red \n";
        return nullptr;
    }


    cout << "\n Ingrese la linea en la que desee " << (opcion ? "agregar" : "eliminar") << " una estacion \n";
    cin>>linea;

    //ahora vamos a buscar la linea para ver si se pueden agregar estaciones
    Linea* lineaPtr = redmetro.getLinea(linea);
    //cout<<lineaPtr<<endl;
    return lineaPtr;


    //ahora que hemos buscado la linea y sabemos que esta , debemos de mostrarle al cliente cuentas estaciones tiene la linea y entre que estaciones quiere agregar la nueva
    //para poder mostrarle las estaciones debemos de tener el objeto linea y acceder a su lista de estaciones , para eso necesito obtener la referencia del objeto linea y una vez lo tenga voy a poder

}


string validarNombreEstacion(Linea *lineaPtr){
    string nombreEstacion;
    bool valido = false;
    Estacion *PrimeraEstacion =  lineaPtr->getEstaciones();

    do{
        //validamos que el nombre de la estacion no se repite
        cout<<"Ingrese el nombre de la estacion : \n - ";
        cin>>nombreEstacion;

        valido = true;
        Estacion *temp = PrimeraEstacion;
        for(int i = 0 ; i < lineaPtr->numEstaciones() ; i++){
            if((temp + i)->getNombre() == nombreEstacion){
                valido = false;
                break;
            }
        }

    } while (!valido);

    cout<<"Nombre valido \n";
    return nombreEstacion;
}

bool validateSetIsTransferStation(){
    string entrada;

    do {
        cout<<"La estacion es una estacion de transferencia (si/no) \n";
        cin>>entrada;

        if(entrada == "si" ||  entrada =="SI"){
            return true;
        }else if (entrada == "no" || entrada == "NO"){
            return false;
        }
    } while (entrada != "si" &&  entrada !="SI" && entrada != "no" && entrada != "NO");

    return false; // Esta línea es necesaria para evitar una advertencia de que no todas las rutas de código devuelven un valor.
}

void mostrarIndicesDeEstaciones(Linea *lineaPtr){

}
