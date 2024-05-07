#ifndef MENU_H
#define MENU_H

#include<iostream>
#include"red.h"

using namespace std ;



//prototipo.

void menu_principal(Red redMetro);
char validarNombreLinea();
Linea *buscarLinea(Red& redmetro , bool opcion)

//prototipo


string validarNombreEstacion(Linea *lineaPtr);
bool validateSetIsTransferStation();
#endif // MENU_H
