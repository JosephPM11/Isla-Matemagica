#ifndef TEXTOS_H
#define TEXTOS_H

#include <iostream>
#include "ascii.h"
using namespace std;

//TEXTO SECTORES MODO CAMPAÑA
void descripcion_s1(){
    gotoxy(5, 20);
	cout<<"Sector 1: Numeracion"<<endl;
	gotoxy(5, 22);
	cout<<"Bienvenido a la                , aventurero."<<endl;
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(21, 22);
	cout<<"Isla Matemagica"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 23);
	cout<<"Tu primer desafio te lleva al Sector de la"<<endl;
	gotoxy(5, 24);
	cout<<"Numeracion, donde los numeros han perdido su"<<endl;
	gotoxy(5, 25);
	cout<<"orden natural. Restaura la armonia enfrentandote"<<endl;
	gotoxy(5, 26);
	cout<<"a criaturas que personifican el caos de los numeros."<<endl;
}

void descripcion_s2(){
	gotoxy(5, 20);
	cout<<"Sector 2: Conjuntos"<<endl;
	gotoxy(5, 22);
	cout<<"Despues de restaurar el orden numerico, te adentras"<<endl;
	gotoxy(5, 23);
	cout<<"en el Sector de los Conjuntos. Aqui, los elementos"<<endl;
	gotoxy(5, 24);
	cout<<"se han dispersado y los conjuntos se han roto."<<endl;
	gotoxy(5, 25);
	cout<<"Enfrentate a enemigos que distorsionan las"<<endl;
	gotoxy(5, 26);
	cout<<"agrupaciones y devuelve el equilibrio a este sector."<<endl;
}

void descripcion_s3(){
	gotoxy(5, 20);
	cout<<"Sector 3: Operaciones combinadas"<<endl;
	gotoxy(5, 22);
	cout<<"Con los conjuntos en orden, te encuentras"<<endl;
	gotoxy(5, 23);
	cout<<"ahora en el Sector de las Operaciones Combinadas."<<endl;
	gotoxy(5, 24);
	cout<<"Los operadores se han vuelto salvajes, creando"<<endl;
	gotoxy(5, 25);
	cout<<"resultados impredecibles. Derrota a los enemigos"<<endl;
	gotoxy(5, 26);
	cout<<"que manipulan las operaciones y restablece el"<<endl;
	gotoxy(5, 27);
	cout<<"calculo correcto."<<endl;
}

void descripcion_s4(){
	gotoxy(5, 20);
	cout<<"Sector 4: Ecuaciones"<<endl;
	gotoxy(5, 22);
	cout<<"Avanzando en tu aventura, llegas al Sector de"<<endl;
	gotoxy(5, 23);
	cout<<"las Ecuaciones. Las soluciones estan fuera de"<<endl;
	gotoxy(5, 24);
	cout<<"control, y las ecuaciones ya no se equilibran."<<endl;
	gotoxy(5, 25);
	cout<<"Enfrentate a las entidades que han desestabilizado"<<endl;
	gotoxy(5, 26);
	cout<<"las igualdades y devuelve la estabilidad matematica."<<endl;
}

void descripcion_s5(){
	gotoxy(5, 20);
	cout<<"Sector 5: Figuras geometricas"<<endl;
	gotoxy(5, 22);
	cout<<"Finalmente, te encuentras en el Sector de las"<<endl;
	gotoxy(5, 23);
	cout<<"Figuras Geometricas. Las formas perfectas se han"<<endl;
	gotoxy(5, 24);
	cout<<"deformado y los angulos se han desviado. Derrota"<<endl;
	gotoxy(5, 25);
	cout<<"a los enemigos que alteran la geometria y recupera"<<endl;
	gotoxy(5, 26);
	cout<<"la armonia en las figuras geometricas de la isla."<<endl;
}

//TEXTO SECTORES MODO CAMPAÑA

#endif