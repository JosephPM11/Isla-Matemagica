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

//TEXTO ITEMS
void descripcion_poci_suma(){
	gotoxy(5, 20);
	cout<<"Pocion de Sumas (20 MONEDAS)"<<endl;
	gotoxy(5, 22);
	cout<<"Concentrado matematico en un frasco."<<endl;
	gotoxy(5, 23);
	cout<<"Esta pocion curativa devuelve de"<<endl;
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(35, 23);
	cout<<"1 a 3"<<endl;
	gotoxy(5, 24);
	cout<<"puntos de vida"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(19, 24);
	cout<<", canalizando la energía"<<endl;
	gotoxy(5, 25);
	cout<<"de las sumas para sanar tus heridas."<<endl;
}

void descripcion_poli_poder(){
	gotoxy(5, 20);
	cout<<"Poliedro de Poder (40 MONEDAS)"<<endl;
	gotoxy(5, 22);
	cout<<"Un poderoso poliedro imbuido de fuerza"<<endl;
	gotoxy(5, 23);
	cout<<"magica. Al usarlo,"<<endl;
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(22, 23);
	cout<<" aumenta tu ataque de"<<endl;
	gotoxy(5, 24);
	cout<<"1 a 2 puntos"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(18, 24);
	cout<<"liberando su energia geometrica"<<endl;
	gotoxy(5, 25);
	cout<<"para fortalecer tus ataques."<<endl;
}

void descripcion_escu_frac(){
	gotoxy(5, 20);
	cout<<"Escudo Fractal (30 MONEDAS)"<<endl;
    gotoxy(5, 22);
    cout<<"Un escudo mistico con patrones infinitos."<<endl;
	gotoxy(5, 23);
	cout<<"Al usarlo,"<<endl;
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(16, 23);
	cout<<"te protege del ataque enemigo"<<endl;
	gotoxy(5, 24);
	cout<<"por 1 o 2 turnos"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(21, 24);
	cout<<", utilizando la complejidad"<<endl;
	gotoxy(5, 25);
	cout<<"de los fractales para desviar los golpes."<<endl;
}
//TEXTO ITEMS

//TEXTO AVATARES
void descripcion_avatar1(){
	gotoxy(5, 20);
	cout<<"Geometra (1000 MONEDAS)"<<endl;
	gotoxy(5, 22);
	cout<<"Tu destreza en combate basada en principios"<<endl;
	gotoxy(5, 23);
	cout<<"matematicos aumenta tu salud y fuerza,"<<endl;
	gotoxy(5, 24);
	cout<<"pero tu habilidad para hacer magia se"<<endl;
	gotoxy(5, 25);
	cout<<"reduce debido a tu enfoque en la fuerza bruta."<<endl;
}

void descripcion_avatar2(){
	gotoxy(5, 20);
	cout<<"Numeromante (1000 MONEDAS)"<<endl;
	gotoxy(5, 22);
	cout<<"Tu conexion con la magia curativa aumenta"<<endl;
	gotoxy(5, 23);
	cout<<"grandemente tu salud, pero tu fuerza y"<<endl;
	gotoxy(5, 24);
	cout<<"habilidad para otras magias se reducen"<<endl;
	gotoxy(5, 25);
	cout<<"debido a tu enfoque en la proteccion."<<endl;
}

void descripcion_avatar3(){
	gotoxy(5, 20);
	cout<<"Teoremagista (1000 MONEDAS)"<<endl;
	gotoxy(5, 22);
	cout<<"Tu dominio de los teoremas magicos incrementa"<<endl;
	gotoxy(5, 23);
	cout<<"tu habilidad magica, aunque tu salud y"<<endl;
	gotoxy(5, 24);
	cout<<"fuerza fisica se ven reducidas debido a"<<endl;
	gotoxy(5, 25);
	cout<<"la dedicacion a tus estudios."<<endl;
}
//TEXTO AVATARES

#endif