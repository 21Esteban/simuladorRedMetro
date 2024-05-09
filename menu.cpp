#include "menu.h"
#include "red.h"
#include <cstdlib>
//simular un timeout para mejorar la experiencia de usuario
#include <thread>
#include <chrono>
#include "estacion.h"
#include <limits>

void menu_principal(Red redMetro){

    int opcion;
    char nombre;
    Linea *linea;
    Estacion *estacion;
    string nombreEstacion;
    bool transferStation;
    int contador ;
    string estacionSalida, estacionLlegada;
    time_t horaSalida;
    time_t horaLlegada;
    do {
        system("cls");
        cout << "\n Bienvenido al sistema metro! :\n\n";
        cout << "\n Menu:\n";
        cout << "1. Agregar una linea\n";
        cout << "2. Agregar estacion\n";
        cout << "3. Eliminar una estacion\n";
        cout << "4. Saber cuantas lineas hay en la red Metro\n";
        cout << "5. Buscar estacion en una linea\n";
        cout << "6. Eliminar linea de la red Metro (solo pueden eliminarse las que no tengan estaciones de transferencia) \n";
        cout << "7. Saber cuantas estacione tiene la red Metro\n";
        cout << "8. Calcular tiempo de llegada \n";
        cout << "9. salir\n";

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << " \n Agregar una linea .\n";
            // Aqui va el codigo para la opcion 1
            //funcion para validar el nombre de la linea
            nombre = validarNombreLinea(redMetro);
            if (nombre =='0'){
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }
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

            if(transferStation){

                linea = buscarLineaParaEstacionDeTransferencia(redMetro,linea->getNombre());
                if(linea == nullptr){
                    return;
                }
                linea->anadirEstacion(nombreEstacion,true);
            }


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
                redMetro.mostrarLineas();
                this_thread::sleep_for(chrono::seconds(2));
            break;

        case 5 :
            cout<<"Busqueda de Estacion \n";
            linea = buscarLinea(redMetro);
            if(linea == nullptr){
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }
            buscarEstacion(linea);
            this_thread::sleep_for(chrono::seconds(2));
            break;
        case 6 :
           cout<<"Eliminar Linea de la red \n";

            cout<<"Ingrese el nombre de la linea que desea eliminar \n - ";
           cin>>nombre;
            redMetro.eliminarLinea(nombre);
           this_thread::sleep_for(chrono::seconds(2));
           break;
        case 7:
            cout<<"Numero de estaciones de la red metro \n" ;

            contador = CuantasEstacionesHay(redMetro);
            cout<<"En la red Metro hay un total de "<<contador<< " estaciones";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        case 8:
            cout << "Calculando tiempo de llegada \n";
            redMetro.mostrarLineas();

            linea = buscarLinea(redMetro);
            if(linea == nullptr){
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }
            linea->mostrarEstacionesYCostes();
            cout << " \n Introduce la estacion de salida: ";
            cin >> estacionSalida;
            cout << "Introduce la estacion de llegada: ";
            cin >> estacionLlegada;
             horaSalida = time(0); // Obtiene la hora actual
             horaLlegada = linea->calcularTiempoDeLlegada(estacionSalida, estacionLlegada, horaSalida);
            if (horaLlegada != -1) {
                struct tm * tiempo = localtime(&horaLlegada);
                cout << "La hora de llegada es: " << tiempo->tm_hour << ":" << tiempo->tm_min << "\n";
            }
            break;
        case 9 :
            cout<<"saliendo ...";
            return;
            break;

        default:
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    } while (opcion < 8);
}

char validarNombreLinea(Red &metro){
    string nombre;
    cout<<"Ingrese el nombre de la linea (solo 1 caracter): \n";
    cin>>nombre;
    //recorremos el arreglo de lineas para comparar el nombre introducido con cada linea
    if(nombre.length()>1){
        cout<<"El nombre de la linea debe ser unicamente de un solo caracter \n";
        return '0';
    }

    for (int i = 0 ; i<metro.getNumeroDeLineas();i++){
        if(metro.getLineas()[i].getNombre() == nombre[0]){
            cout<<"No se pudo crear la Linea ya que existe una linea creada con ese nombre. \n";
            return '0';
        }
    }
    return nombre[0];
}

 Linea *buscarLinea(Red& redmetro , bool opcion){
    string linea;


    if(redmetro.getNumeroDeLineas() == 0){
        cout<<"no puedes agregar estaciones porque no hay lineas en la red \n";
        return nullptr;
    }

    cout << "\n Ingrese la linea en la que desee " << (opcion ? "agregar" : "eliminar") << " una estacion \n";
    cin>>linea;

    if(linea.length()>1){
        cout<<"El nombre de la linea debe ser unicamente de un caracter \n";
        return nullptr;
    }
    //ahora vamos a buscar la linea para ver si se pueden agregar estaciones
    Linea* lineaPtr = redmetro.getLinea(linea[0]);
    //cout<<lineaPtr<<endl;
    return lineaPtr;


    //ahora que hemos buscado la linea y sabemos que esta , debemos de mostrarle al cliente cuentas estaciones tiene la linea y entre que estaciones quiere agregar la nueva
    //para poder mostrarle las estaciones debemos de tener el objeto linea y acceder a su lista de estaciones , para eso necesito obtener la referencia del objeto linea y una vez lo tenga voy a poder

}

//sobrecargamos la funcion buscarLinea

Linea *buscarLinea(Red& redmetro){
    string entrada;

    if(redmetro.getNumeroDeLineas() == 0){
        cout<<"No puedes buscar estaciones porque no hay lineas en la red \n";
        return nullptr;
    }

    do {
        cout << "\n Ingrese la linea en la que desee buscar estacion \n";
        cin >> entrada;

        if(entrada.length() > 1) {
            cout << "Por favor, ingrese una linea valida (de longitud 1) .\n";
        }
    } while(entrada.length() > 1);




    // Ahora vamos a buscar la linea para ver si se pueden agregar estaciones
    Linea* lineaPtr = redmetro.getLinea(entrada[0]);
    return lineaPtr;
}


Linea *buscarLineaParaEstacionDeTransferencia(Red& redmetro,char lineaAnterior){
    char linea;
    cout<<" \n Cual es la otra linea a la que pertenece la estacion de transferencia : \n";

    if(redmetro.getNumeroDeLineas() < 2){
        cout<<"No hay suficientes lineas para realizar estaciones de transferencia \n";
        return nullptr;
    }

    cout << "\n Ingrese la linea para la estacion de transferencia\n";
    cin>>linea;

    if(linea == lineaAnterior){
        cout<<"No puedes escoger la misma linea \n";
        return nullptr;
    }

    // Ahora vamos a buscar la linea para ver si se pueden agregar estaciones
    Linea* lineaPtr = redmetro.getLinea(linea);
    return lineaPtr;
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

    return false; // Esta linea es necesaria para evitar una advertencia de que no todas las rutas de código devuelven un valor.
}

void buscarEstacion(Linea* lineaPtr){
    string nombreEstacion;
    Estacion *PrimeraEstacion =  lineaPtr->getEstaciones();


        //buscamos la estacion en la linea dada
        cout<<"Ingrese el nombre de la estacion a buscar : \n - ";
        cin>>nombreEstacion;


        Estacion *temp = PrimeraEstacion;
        for(int i = 0 ; i < lineaPtr->numEstaciones() ; i++){
            if((temp + i)->getNombre() == nombreEstacion){
                cout<<"La estacion "<<temp->getNombre() <<" se encuentra en la linea " <<lineaPtr->getNombre()<<"\n";
                return;
            }
        }
        cout<<"La estacion no existe en la linea "<<lineaPtr->getNombre();
        return;
}

int CuantasEstacionesHay(Red redMetro){
    //primero entramos a cada linea
    int contador = 0;


    for( int i = 0; i < redMetro.getNumeroDeLineas(); i++){
        //ahora entramos a cada estacion y lo sumamos
        contador = contador + redMetro.getLineas()[i].numEstaciones();
    }

    return contador;

}
