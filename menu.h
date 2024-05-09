#ifndef MENU_H
#define MENU_H

#include<iostream>
#include"red.h"
#include <string>

using namespace std ;



//prototipo

void menu_principal(Red redMetro);
char validarNombreLinea(Red &redMetro);
Linea *buscarLinea(Red& redmetro , bool opcion);
//funcion sobrecargada
Linea *buscarLinea(Red& redmetro);
Linea *buscarLineaParaEstacionDeTransferencia(Red& redmetro,char lineaAnterior);
string validarNombreEstacion(Linea *lineaPtr);
bool validateSetIsTransferStation();
void buscarEstacion(Linea* lineaPtr);
int CuantasEstacionesHay(Red redMetro);
#endif // MENU_H

