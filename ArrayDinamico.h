#ifndef ARRAYDINAMICO_H
#define ARRAYDINAMICO_H

using namespace std;
#include<iostream>



template<class T>
class ArrayDinamico
{

private:

    T* arrayPtr;
    unsigned short int size;


public:
    ArrayDinamico() {
        this->arrayPtr = nullptr;
        this->size = 0;
    }

    /*~ArrayDinamico() {
        cout<<"eliminando....";
        delete[] arrayPtr;
    }*/

    //metodos para añadir un elemento a mi arreglo dinamico

    void anadir(T elemento) {
        //creamos un nuevo arreglo dinamico del tamaño  del arreglo que teniamos mas 1 para poder insetar el nuevo elemento
        T* newArray = new T[size + 1];
        //copiamos el arreglo viejo al nuevo
        for (int i = 0; i < size; i++) {
            newArray[i] = arrayPtr[i];
        }

        //ahora agregamos el ultimo elemento al nuevo arreglo
        newArray[size] = elemento;
        delete[] arrayPtr;
        //cout<<"acabo de eliminar el array viejo " ;
        // y ahora hacemos que el puntero arrayPtr apunte al nuevo arreglo
        arrayPtr = newArray;
        //y por ultimo modificamos el atributo de size
        size++;
    }

    void insertarEn(T elemento, int indice) {
        // Verifica si el índice es válido
        /*if (indice < 0 || indice > size) {
            cout << "Indice inválido. No se anadira el elemento." << endl;
            return;
        }*/

        // Crea un nuevo arreglo dinámico del tamaño del arreglo que teníamos más 1 para poder insertar el nuevo elemento
        T* newArray = new T[size + 1];

        // Copia los elementos del arreglo viejo al nuevo hasta el índice
        for (int i = 0; i < indice; i++) {
            newArray[i] = arrayPtr[i];
        }

        // Inserta el nuevo elemento en el índice
        newArray[indice] = elemento;

        // Copia el resto de los elementos del arreglo viejo al nuevo
        for (int i = indice; i < size; i++) {
            newArray[i + 1] = arrayPtr[i];
        }

        // Libera la memoria del arreglo viejo
        delete[] arrayPtr;

        // Ahora hacemos que el puntero arrayPtr apunte al nuevo arreglo
        arrayPtr = newArray;

        // Por último, incrementamos el atributo de size
        size++;
    }



    void eliminarEn(int indice){
        //par apoder eliminar un indice lo que hacemos es copiar el arreglo nuevamente pero sin ese elemento y ya

        //creamos un nuevo arreglo dinamico con la misma cantidad del viejo -1
        T* newArray = new T[this->obtenerTamaño()-1] ;

        for (int i = 0, j = 0; i < this->obtenerTamaño(); i++){
            // Ahora vamos copiando cada elemento del array viejo y lo pasamos al nuevo
            if(i != indice){
                newArray[j] = arrayPtr[i];
                j++;
            }
        }

        //por ultimo liberamos la memoria del arreglo viejo

        delete[] arrayPtr;

        //y ahora hacemos que apunte al nuevo Array

        arrayPtr = newArray;

        size--;

    }


    int obtenerTamaño() const {
        return size;
    }

    //adicional a eso hacemos un metodo que nos imprima el arreglo

    void mostrarArreglo() const {
        for (int i = 0 ; i<this->size;i++){
            cout<<*(arrayPtr+i)<<endl;
        }
    }

    //metodo que nos devuelve la primera posicion de memoria del array para poder interactuar con el

    T* primeraDireccion(){
        return this->arrayPtr;
    }

    //   Para sobrecargar un operador primero se determina el tipo de dato que se retornará
    // como resultado; luego, se usa la palabra reservada OPERATOR seguida del operador
    // que se desea sobrecargar y, finalmente, el parámetro de entrada que suele ser
    // utilizado como uno de sus operandos

    //sobrecargamos el operador []
    T& operator[](int index) const {
        return arrayPtr[index];
    }

    //sobrecargamos el operador << para imprimir los objetos
    // T operator<<()
};

//intente dividir esta class template en el archivo h y su implementacion en el cpp pero no encontre forma por unos errores que se me presentaba , entonces al leer este foro https://forum.qt.io/topic/77470/how-to-use-class-templates me decidi a implementarlo todo en el .h (cabecera)


#endif // ARRAYDINAMICO_H
