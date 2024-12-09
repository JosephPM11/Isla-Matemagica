#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cstdlib>

#include "sector1.h"
#include "sector2.h"
#include "ascii.h"
#include "textos.h"

using namespace std;
char usuario[20]; char contrasenha[20];

//Color
int *color,dir_color=1;
//Avatar
int *avatar,dir_avatar=0;
	//Avatares desbloqueados
int *des_avatar1,dir_des_avatar1=0;
int *des_avatar2,dir_des_avatar2=0;
int *des_avatar3,dir_des_avatar3=0;
//Recompensas
int *recomp1,dir_recomp1=0;
int *recomp2,dir_recomp2=0;
int *recomp3,dir_recomp3=0;
//Dinero
int *dinero,dir_dinero=1000;
//Exp
int *exp,dir_exp=0;
//Objetos
int *poci_suma,dir_poci_suma=0;
int *poli_poder,dir_poli_poder=0;
int *escu_frac,dir_escu_frac=0;

int *ataque_extra,dir_ataque_extra=0;
int *proteccion,dir_proteccion=0;
//Habilidades
	//Ataque critico
int *cant_ataq_crit,dir_cant_ataq_crit=2;

//Vida jugador
int *vida_jugador,dir_vida_jugador=10;
//Vida enemigos
int *vida_enemigo1_s1,dir_vida_enemigo1_s1=10;

//Color de fondo y texto
const int BACKGROUND_CYAN = BACKGROUND_BLUE | BACKGROUND_GREEN;

void menu();

// Función para fondo (Para evitar error de que no se coloree todo)
void fillConsoleBackground(int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (hConsole == INVALID_HANDLE_VALUE) return;

    // Obtener la información actual del buffer de la consola
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Rellenar la consola con el color de fondo deseado
    FillConsoleOutputAttribute(hConsole, backgroundColor, cellCount, homeCoords, &count);

    // Colocar el cursor en la esquina superior izquierda
    SetConsoleCursorPosition(hConsole, homeCoords);
}

void s1_opc_1();
void s1_opc_2();
void s1_opc_3();
void s1_opc_4();
void s1_opc_5();

void s2_opc_1();
void s2_opc_2();
void s2_opc_3();
void s2_opc_4();
void s2_opc_5();

void modo_campana();
void modo_campana_opc_1();
void modo_campana_opc_2();
void modo_campana_opc_3();
void modo_campana_opc_4();
void modo_campana_opc_5();

void modo_campana(){
	modo_campana_opc_1();
}

//Modo Campana opc 1
void modo_campana_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                     
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	
	setColor(FOREGROUND_BLUE);
	//Sector 1
	token_s1(15,9);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	descripcion_s1(); //Descripción
	
	//Sector 2
	token_s2(35,10);
	//Sector 3
	token_s3(55,10);
    //Sector 4
	token_s4(75,10);
    //Sector 5
	token_s5(95,10);

	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: modo_campana_opc_2();break; //Flecha derecha
		case 75: modo_campana_opc_5();break; //Flecha izquierda
		case 13: s1_opc_1();break; //Enter
		default:modo_campana_opc_1();break;
	}
}

//Modo Campana opc 2
void modo_campana_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                     
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	
	//Sector 1
	token_s1(15,10);
	setColor(FOREGROUND_BLUE);
	//Sector 2
	token_s2(35,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	descripcion_s2(); //Descripción

	//Sector 3
	token_s3(55,10);
    //Sector 4
	token_s4(75,10);
    //Sector 5
	token_s5(95,10);
    
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: modo_campana_opc_3();break; //Flecha derecha
		case 75: modo_campana_opc_1();break; //Flecha izquierda
		case 13: s2_opc_1();break; //Enter
		default:modo_campana_opc_2(); break;
	}
}

//Modo Campana opc 3
void modo_campana_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                     
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	
	//Sector 1
	token_s1(15,10);
	//Sector 2
	token_s2(35,10);

    setColor(FOREGROUND_BLUE);
	//Sector 3
	token_s3(55,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	descripcion_s3(); //Descripción

    //Sector 4
	token_s4(75,10);
    //Sector 5
	token_s5(95,10);
    
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: modo_campana_opc_4();break; //Flecha derecha
		case 75: modo_campana_opc_2();break; //Flecha izquierda
		case 13: 
		gotoxy(5, 28);
		cout<<"Completa el sector anterior para desbloquear";
		getch();
		modo_campana_opc_3();
		break; //Enter
		default: modo_campana_opc_3(); break;
	}
}

//Modo Campana opc 4
void modo_campana_opc_4(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                     
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	
	//Sector 1
	token_s1(15,10);
	//Sector 2
	token_s2(35,10);

	//Sector 3
	token_s3(55,10);
    
  	setColor(FOREGROUND_BLUE);
    //Sector 4
	token_s4(75,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	descripcion_s4(); //Descripción

    //Sector 5
	token_s5(95,10);
    
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: modo_campana_opc_5();break; //Flecha derecha
		case 75: modo_campana_opc_3();break; //Flecha izquierda
		case 13:
		gotoxy(5, 28);
		cout<<"Completa el sector anterior para desbloquear";
		getch();
		modo_campana_opc_4();
		break; //Enter
		default:modo_campana_opc_4(); break;
	}
}

//Modo Campana opc 5
void modo_campana_opc_5(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                     
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	
	//Sector 1
	token_s1(15,10);
	//Sector 2
 	token_s2(35,10);
	//Sector 3
	token_s3(55,10);
   	//Sector 4
	token_s4(75,10);
    
    setColor(FOREGROUND_BLUE);
    //Sector 5
	token_s5(95,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	descripcion_s5(); //Descripción

	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: modo_campana_opc_1();break; //Flecha derecha
		case 75: modo_campana_opc_4();break; //Flecha izquierda
		case 13:
		gotoxy(5, 28);
		cout<<"Completa el sector anterior para desbloquear";
		getch();
		modo_campana_opc_5();
		break; //Enter
		default: modo_campana_opc_5(); break;
	}
}

//S1 opc 1
void s1_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	setColor(FOREGROUND_BLUE);
	cout<<"\n\n       o Nivel 1"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	//Se utilizan 2 getch() cuando se quiere usar flechas para evitar el valor basura (224)
	//Forma de detectar una tecla normal y una flecha sin tener que pedir siempre otro valor (en que caso que no sea flecha)
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s1_opc_5();break; //Flecha arriba
		case 80: s1_opc_2();break; //Flecha abajo
		case 13: 
		batallas_s1(1,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s1_opc_1(); break;
	}
	modo_campana();
}

//S1 opc 2
void s1_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 2"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s1_opc_1();break; //Flecha arriba
		case 80: s1_opc_3();break; //Flecha abajo
		case 13: 
		batallas_s1(2,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s1_opc_2(); break;
	}
	modo_campana();
}

//S1 opc 3
void s1_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 3"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s1_opc_2();break; //Flecha arriba
		case 80: s1_opc_4();break; //Flecha abajo
		case 13: 
		batallas_s1(3,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s1_opc_3(); break;
	}
	modo_campana();
}

//S1 opc 4
void s1_opc_4(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 4"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s1_opc_3();break; //Flecha arriba
		case 80: s1_opc_5();break; //Flecha abajo
		case 13: 
		batallas_s1(4,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s1_opc_4(); break;
	}
	modo_campana();
}

//S1 opc 5
void s1_opc_5(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 5: Boss Battle"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s1_opc_4();break; //Flecha arriba
		case 80: s1_opc_1();break; //Flecha abajo
		case 13: 
		batallas_s1(5,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s1_opc_5(); break;
	}
	modo_campana();
}


//S2 opc 1
void s2_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	setColor(FOREGROUND_BLUE);
	cout<<"\n\n       o Nivel 1"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver al menu (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	//Se utilizan 2 getch() cuando se quiere usar flechas para evitar el valor basura (224)
	//Forma de detectar una tecla normal y una flecha sin tener que pedir siempre otro valor (en que caso que no sea flecha)
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: modo_campana_opc_1(); //Volver a la pantalla anterior
		case 72: s2_opc_5();break; //Flecha arriba
		case 80: s2_opc_2();break; //Flecha abajo
		case 13: 
		batallas_s2(1,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s2_opc_1(); break;
	}
	modo_campana();
}

//S2 opc 2
void s2_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 2"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu(); //Volver a la pantalla anterior
		case 72: s2_opc_1();break; //Flecha arriba
		case 80: s2_opc_3();break; //Flecha abajo
		case 13: 
		batallas_s2(2,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s2_opc_2(); break;
	}
	modo_campana();
}

//S2 opc 3
void s2_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 3"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 4"<<endl;
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu(); //Volver a la pantalla anterior
		case 72: s2_opc_2();break; //Flecha arriba
		case 80: s2_opc_4();break; //Flecha abajo
		case 13: 
		batallas_s2(3,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s2_opc_3(); break;
	}
	modo_campana();
}

//S2 opc 4
void s2_opc_4(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 4"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"     o Nivel 5: Boss Battle"<<endl;
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu(); //Volver a la pantalla anterior
		case 72: s2_opc_3();break; //Flecha arriba
		case 80: s2_opc_5();break; //Flecha abajo
		case 13: 
		batallas_s2(4,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s2_opc_4(); break;
	}
	modo_campana();
}

//S1 opc 5
void s2_opc_5(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	cout<<"\n\n     o Nivel 1"<<endl;
	cout<<"     o Nivel 2"<<endl;
	cout<<"     o Nivel 3"<<endl;
	cout<<"     o Nivel 4"<<endl;
	setColor(FOREGROUND_BLUE);
	cout<<"       o Nivel 5: Boss Battle"<<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//Volver a la seleccion de sectores (Presiona 0)
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu(); //Volver a la pantalla anterior
		case 72: s2_opc_4();break; //Flecha arriba
		case 80: s2_opc_1();break; //Flecha abajo
		case 13: 
		batallas_s2(5,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac); break; //Enter
		default: s2_opc_5(); break;
	}
	modo_campana();
}

void rangos(){
	if(*exp>2000){
		//Color rosado
		setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"Maestro Matemago"<<endl;
		//Color blanco
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	else{
		if((*exp>=1301)&&(*exp<=2000)){
		//Color rosado
		setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"Algebrista Arcano"<<endl;
		//Color blanco
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else{
			if((*exp>=901)&&(*exp<=1300)){
				//Color rosado
				setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout<<"Geomago"<<endl;
				//Color blanco
				setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else{
				if((*exp>=401)&&(*exp<=900)){
					//Color rosado
					setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout<<"Aritnomante"<<endl;
					//Color blanco
					setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
				else{
					//Color rosado
					setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout<<"Aprendiz de magos"<<endl;
					//Color blanco
					setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
			}
		}
	}	
}

void arbol_habilidades(){
	cout<<"Hola";
}

void perfil();

void cambio_avatar(){
	system("CLS");
	cout<<"\n";
		cout<<" Selecciona el avatar que desees poner: "<<endl;
		cout<<"\n";
		cout<<"   1. Avatar 1"<<endl;
		cout<<"   2. Avatar 2"<<endl;
		cout<<"   3. Avatar 3"<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"(Escribe 0 para retroceder)"<<endl;
		cin>>numero;
		
		switch(numero){
			case 0:
			perfil();break;
			case 1:
			if(*des_avatar1==1){
				*avatar=1;
				cout<<"\nEl avatar ha sido cambiado"<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			else{
				cout<<"No tienes este avatar :("<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			break;
			case 2: 
			if(*des_avatar2==1){
				*avatar=2;
				cout<<"\nEl avatar ha sido cambiado"<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			else{
				cout<<"No tienes este avatar :("<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			break;
			case 3: 
			if(*des_avatar3==1){
				*avatar=3;
				cout<<"\nEl avatar ha sido cambiado"<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			else{
				cout<<"No tienes este avatar :("<<endl;
				cout<<"\n";
				system("pause");
				cambio_avatar();
			}
			break;
			default: cout<<"Fuera de rango";break;
		}
}

void perfil(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    titulo_perfil();
	cout<<"\n\n\n     =========================="<<endl;
		cout<<"      Usuario: "<<usuario<<endl;
		cout<<"     =========================="<<endl;
		gotoxy(14, 13);
		rangos();
		gotoxy(14, 14);
		cout<<"Dinero: "<<*dinero<<endl;
		gotoxy(14, 15);
		cout<<"Exp: "<<*exp<<"/2000"<<endl;
		gotoxy(14, 16);
		cout<<"Vida: "<<*vida_jugador<<endl;
		//cout<<"\t       Ataque: "<<*exp<<"/2000"<<endl;
		
		switch(*avatar){
			case 0: avatar0(7,13);break;
			case 1: avatar1(7,13);break;
			case 2: avatar2(7,13);break;
			case 3: avatar3(7,13);break;
			default:cout<<"Fuera de rango";break;
		}

		gotoxy(45, 8);
		cout<<"---------INVENTARIO---------"<<endl;
		gotoxy(46, 9);
		cout<<"1. Pocion de sumas (x"<<*poci_suma<<")"<<endl;
		gotoxy(46, 10);
		cout<<"2. Poliedro de poder (x"<<*poli_poder<<")"<<endl;
		gotoxy(46, 11);
		cout<<"3. Escudo fractal (x"<<*escu_frac<<")"<<endl;
		gotoxy(45, 12);
		cout<<"----------------------------"<<endl;

		gotoxy(45, 16);
		cout<<"---------HABILIDADES--------"<<endl;
		gotoxy(46, 17);
		cout<<"1. Ataque critico (2/2)"<<endl;
		/*gotoxy(46, 18);
		cout<<"2. Poliedro de poder - Aumenta tu ataque de 1 a 2 (x"<<*poli_poder<<")"<<endl;
		gotoxy(46, 19);
		cout<<"3. Escudo fractal - El enemigo no puede actuar por 1 o 2 turnos (x"<<*escu_frac<<")"<<endl;*/
		gotoxy(45, 18);
		cout<<"----------------------------"<<endl;
		
		//Volver al menu (Presiona 0)
		gotoxy(91, 1);
    	cout<< "Volver al menu (Presiona 0)" << endl;
   	 	//Cambiar de Avatar (Presiona a/A)
    	gotoxy(97, 2);
    	cout<< "Avatares (Presiona A)" << endl;
    	
    	tecla= getch();
		if(tecla==224){
		tecla= getch();
		}
		//Teclas posibles
		switch (tecla){
		case 48: menu();break; //Volver al menu
		case 97:cambio_avatar();break;//Tecla a //Avatares
		case 65:cambio_avatar();break;//Tecla A //Avatares
		default:perfil();break;
	}
}

void tienda();

void obj_tienda_opc_1();
void obj_tienda_opc_2();
void obj_tienda_opc_3();

void avatar_tienda_opc_1();
void avatar_tienda_opc_2();
void avatar_tienda_opc_3();
void tienda(){
	obj_tienda_opc_1();
}

//Obj Tienda opc 1
void obj_tienda_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                       
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	
	mesa_tienda();
	titulo_items_tienda();
	
	setColor(FOREGROUND_BLUE);
	ascii_poci_suma(35,10);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	descripcion_poci_suma();//Descripción

	ascii_poli_poder(55,10);
	ascii_escu_frac(79,10);
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Avatares (Presiona q/Q)
    gotoxy(97, 2);
    cout<< "Avatares (Presiona Q)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: obj_tienda_opc_2();break; //Flecha derecha
		case 75: obj_tienda_opc_3();break; //Flecha izquierda
		case 13: 
			if(*dinero>=20){
				*dinero-=20;
				*poci_suma+=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado una Pocion de Sumas!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				obj_tienda_opc_1();
			}
			else{
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este objeto :("<<endl;
				cout<<"\n";
				getch();
				obj_tienda_opc_1();
			}
			break; //Enter
		case 81:avatar_tienda_opc_1();break;//Tecla q //Avatares
		case 113:avatar_tienda_opc_1();break;//Tecla Q //Avatares
		default:obj_tienda_opc_1();break;
	}
}

//Obj Tienda opc 2
void obj_tienda_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	
	mesa_tienda();
	titulo_items_tienda();
	ascii_poci_suma(35,11);
	setColor(FOREGROUND_BLUE);
	ascii_poli_poder(55,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	descripcion_poli_poder();

	ascii_escu_frac(79,10);
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Avatares (Presiona q/Q)
    gotoxy(97, 2);
    cout<< "Avatares (Presiona Q)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: obj_tienda_opc_3();break; //Flecha derecha
		case 75: obj_tienda_opc_1();break; //Flecha izquierda
		case 13: 
			if(*dinero>=40){
				*dinero-=40;
				*poli_poder+=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado un Poliedro de Poder!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				obj_tienda_opc_2();
			}
			else{	
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este objeto :("<<endl;
				cout<<"\n";
				getch();
				obj_tienda_opc_2();
			}
			break; //Enter
		case 81:avatar_tienda_opc_1();break;//Tecla q //Avatares
		case 113:avatar_tienda_opc_1();break;//Tecla Q //Avatares
		default:obj_tienda_opc_2(); break;
	}
}

//Obj Tienda opc 3
void obj_tienda_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	
	mesa_tienda();
	titulo_items_tienda();
	ascii_poci_suma(35,11);
	ascii_poli_poder(55,10);

    setColor(FOREGROUND_BLUE);
    //Escudo Fractal
	ascii_escu_frac(79,9);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    descripcion_escu_frac();
	
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Avatares (Presiona q/Q)
    gotoxy(97, 2);
    cout<< "Avatares (Presiona Q)" << endl;
	
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: obj_tienda_opc_1();break; //Flecha derecha
		case 75: obj_tienda_opc_2();break; //Flecha izquierda
		case 13: 
			if(*dinero>=30){
				*dinero-=30;
				*escu_frac+=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado un Escudo Fractal!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				obj_tienda_opc_3();
			}
			else{
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este objeto :("<<endl;
				cout<<"\n";
				getch();
				obj_tienda_opc_3();
			}
			break; //Enter
		case 81:avatar_tienda_opc_1();break;//Tecla q //Avatares
		case 113:avatar_tienda_opc_1();break;//Tecla Q //Avatares
		default: obj_tienda_opc_3(); break;
	}
}

//Avatar Tienda opc 1
void avatar_tienda_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                                       
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	
	mesa_tienda();
	titulo_avatares_tienda();

	setColor(FOREGROUND_BLUE);
	avatar1(35,11);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	descripcion_avatar1();
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 27);
	cout<<"+1 Poliedro de Poder (c/batalla)   +3 vida"<<endl;
	gotoxy(5, 28);
	cout<<"+5 ataque                          -2 pt habilidad"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	avatar2(56,12);
	avatar3(79,12);
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Items (Presiona q/Q)
    gotoxy(100, 2);
    cout<< "Items (Presiona Q)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: avatar_tienda_opc_2();break; //Flecha derecha
		case 75: avatar_tienda_opc_3();break; //Flecha izquierda
		case 13: 
			if(*dinero>=1000){
				*dinero-=1000;
				*des_avatar1=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado el Avatar 1!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				avatar_tienda_opc_1();
			}
			else{
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este avatar :("<<endl;
				cout<<"\n";
				getch();
				avatar_tienda_opc_1();
			}
			break; //Enter
		case 81:obj_tienda_opc_1();break;//Tecla q //Items
		case 113:obj_tienda_opc_1();break;//Tecla Q //Items
		default:avatar_tienda_opc_1();break;
	}
}

//Avatar Tienda opc 2
void avatar_tienda_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	mesa_tienda();
	titulo_avatares_tienda();

	avatar1(35,12);
	setColor(FOREGROUND_BLUE);
	avatar2(56,11);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	descripcion_avatar2();
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 27);
	cout<<"+1 Pocion de Salud (c/batalla)     +10 vida"<<endl;
	gotoxy(5, 28);
	cout<<"-3 ataque                          -1 pt habilidad"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	avatar3(79,12);
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Items (Presiona q/Q)
    gotoxy(100, 2);
    cout<< "Items (Presiona Q)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: avatar_tienda_opc_3();break; //Flecha derecha
		case 75: avatar_tienda_opc_1();break; //Flecha izquierda
		case 13: 
			if(*dinero>=1000){
				*dinero-=1000;
				*des_avatar2=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado el Avatar 2!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				avatar_tienda_opc_2();
			}
			else{	
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este avatar :("<<endl;
				cout<<"\n";
				getch();
				avatar_tienda_opc_2();
			}
			break; //Enter
		case 81:obj_tienda_opc_1();break;//Tecla q //Avatares
		case 113:obj_tienda_opc_1();break;//Tecla Q //Avatares
		default:avatar_tienda_opc_2(); break;
	}
}

//Avatar Tienda opc 3
void avatar_tienda_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_tienda();
	//Dinero
	gotoxy(5, 7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	
	mesa_tienda();
	titulo_avatares_tienda();
	avatar1(35,12);
	avatar2(56,12);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
 
	setColor(FOREGROUND_BLUE);
	avatar3(79,11);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	descripcion_avatar3();
	//Color rosado
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 27);
	cout<<"+1 Escudo Fractal (c/batalla)      -5 vida"<<endl;
	gotoxy(5, 28);
	cout<<"-1 ataque                          +2 pt habilidad"<<endl;
	//Color blanco
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Items (Presiona q/Q)
    gotoxy(100, 2);
    cout<< "Items (Presiona Q)" << endl;
	
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77: avatar_tienda_opc_1();break; //Flecha derecha
		case 75: avatar_tienda_opc_2();break; //Flecha izquierda
		case 13: 
			if(*dinero>=1000){
				*dinero-=1000;
				*des_avatar3=1;
				gotoxy(5, 27);
				cout<<"-> !Has comprado el Avatar 3!"<<endl;
				gotoxy(8, 28);
				cout<<"Se ha agregado a tu inventario"<<endl;
				getch();
				avatar_tienda_opc_3();
			}
			else{
				gotoxy(5, 27);
				cout<<"-> No cuentas con el dinero suficiente"<<endl;
				gotoxy(8, 28);
				cout<<"para comprar este avatar :("<<endl;
				cout<<"\n";
				getch();
				avatar_tienda_opc_3();
			}
			break; //Enter
		case 81:obj_tienda_opc_1();break;//Tecla q //Avatares
		case 113:obj_tienda_opc_1();break;//Tecla Q //Avatares
		default: avatar_tienda_opc_3(); break;
	}
}

void recompensas(){
	system("CLS");
	cout<<"\n  Recibe recompensas al llegar a ciertos niveles de experiencia"<<endl;
	cout<<"\n----------RECOMPENSAS-----------"<<endl;	
	cout<<"\n";
	if(*recomp1==0){
		cout<<"   Recompensa 1 (Bloqueada)"<<endl;
	}
	else{
		if(*recomp1==1){
			cout<<"   Recompensa 1 (Por reclamar)"<<endl;
		}
		else{
			cout<<"   Recompensa 1 (Reclamada)"<<endl;
		}
	}
	
	if(*recomp2==0){
		cout<<"   Recompensa 2 (Bloqueada)"<<endl;
	}
	else{
		if(*recomp2==1){
			cout<<"   Recompensa 2 (Por reclamar)"<<endl;
		}
		else{
			cout<<"   Recompensa 2 (Reclamada)"<<endl;
		}
	}
	
	if(*recomp3==0){
		cout<<"   Recompensa 3 (Bloqueada)"<<endl;
	}
	else{
		if(*recomp3==1){
			cout<<"   Recompensa 3 (Por reclamar)"<<endl;
		}
		else{
			cout<<"   Recompensa 3 (Reclamada)"<<endl;
		}
	}
	cout<<"\n--------------------------------"<<endl;
	
	do{
		cout<<"\n";
		cout<<"(Escribe 0 para salir al menu)"<<endl;
		cin >> numero;
		switch(numero){
			case 0: menu(); break;
			case 1:
				if(*recomp1==0){
					cout<<"Esta recompensa esta bloqueada"<<endl;
					cout<<"\n";
					system("pause");
					recompensas();
				}
				else{
					if(*recomp1==1){
						cout<<"Has conseguido: 1 Pocion de Sumas"<<endl;
						cout<<"\n";
						*poci_suma+=1;
						*recomp1=2;
					
						system("pause");
						recompensas();
					}
					else{
						cout<<"\n";
						cout<<"Ya reclamaste esta recompensa"<<endl;
						cout<<"\n";
						system("pause");
						recompensas();
					}
				}
				break;
			case 2:
				if(*recomp2==0){
					cout<<"Esta recompensa esta bloqueada"<<endl;
					cout<<"\n";
					system("pause");
					recompensas();
				}
				else{
					if(*recomp2==1){
						cout<<"Has conseguido: 1 Poliedro de Poder"<<endl;
						cout<<"\n";
						*poli_poder+=1;
						*recomp2=2;
						system("pause");
						recompensas();
					}
					else{
						cout<<"\n";
						cout<<"Ya reclamaste esta recompensa"<<endl;
						cout<<"\n";
						system("pause");
						recompensas();
					}
				}
				break;
			case 3:
				if(*recomp3==0){
					cout<<"Esta recompensa esta bloqueada"<<endl;
					cout<<"\n";
					system("pause");
					recompensas();
				}
				else{
					if(*recomp3==1){
						cout<<"Has conseguido: 1 Escudo Fractal"<<endl;
						cout<<"\n";
						*escu_frac+=1;
						*recomp3=2;
						system("pause");
						recompensas();	
					}
					else{
						cout<<"\n";
						cout<<"Ya reclamaste esta recompensa"<<endl;
						cout<<"\n";
						system("pause");
						recompensas();
					}
				}
				break;
		}
	} while ((numero<0)&&(numero>3));
}

void cambiar_nombre();
void cambiar_contrasenha();

void configuracion(){
   do{
	  	system("CLS");
		cout<<"\n----------CONFIGURACION-----------"<<endl;
		cout<<"\n";
		cout<<"1. Cambiar nombre"<<endl;
		cout<<"2. Cambiar contraseña"<<endl;
		cout<<"\n";
		cout<<"---------------------------------------"<<endl;
		cout<<"(Escribe 0 para salir de la configuracion)"<<endl;
	    cin >> numero;
	
	    switch (numero) {
	    	case 0:
	    		menu();
	    		break;
	        case 1:
	        	cambiar_nombre();
	            break;
	        case 2:
	            cambiar_contrasenha();
	            break;
	        default:
	            cout << "Fuera de rango";
	            break;
	    }
	} while ((numero<0)or(numero>2));
}

void cambiar_nombre(){
	system("CLS");
	cout<<"Nombre actual: "<<usuario<<endl;
	cout<<"Nuevo nombre: "; cin>>usuario;
	cout<<"\n";
	system("pause");
	configuracion();
}

void cambiar_contrasenha(){
	system("CLS");
	cout<<"Contrasenha actual: "<<contrasenha<<endl;
	cout<<"Nueva contrasenha: "; cin>>contrasenha;
	cout<<"\n";
	system("pause");
	configuracion();
}

void menu_opc_1();
void menu_opc_2();
void menu_opc_3();
void menu_opc_4();
void menu_opc_5();
void menu_opc_6();

void menu(){
	//Verificar atributos de avatar
	if(*des_avatar1==1){
		*vida_jugador+=6;
	}
	if(*des_avatar2==1){
		*vida_jugador+=3;
	}
	if(*des_avatar3==1){
		*vida_jugador-=5;
	}
	//Verificar exp para desbloquear recompensas
	if(*exp>=100){
		*recomp1=1;
	}
	if(*exp>=400){
		*recomp2=1;
	}
	if(*exp>=700){
		*recomp3=1;
	}
	menu_opc_1();
}

//Menu opc 1
void menu_opc_1(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	texto_titulo();
	cout << "\n\n";
	setColor(FOREGROUND_BLUE);
	cout << "\t1. Modo campanha" << endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\t2. Perfil" <<endl;
	cout << "\t3. Tienda" <<endl;
	cout << "\t4. Recompensas" <<endl;
	cout << "\t5. Configuracion" <<endl;
	
	//Se utilizan 2 getch() cuando se quiere usar flechas para evitar el valor basura (224)
	//Forma de detectar una tecla normal y una flecha sin tener que pedir siempre otro valor (en que caso que no sea flecha)
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 72: menu_opc_5();break; //Flecha arriba
		case 80: menu_opc_2();break; //Flecha abajo
		case 13: modo_campana();break; //Enter
		default: menu_opc_1(); break;
	}
}

//Menu opc 2
void menu_opc_2(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	texto_titulo();
	cout << "\n\n";
	cout << "\t1. Modo campanha" << endl;
	setColor(FOREGROUND_BLUE);
	cout << "\t2. Perfil" <<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\t3. Tienda" <<endl;
	cout << "\t4. Recompensas" <<endl;
	cout << "\t5. Configuracion" <<endl;
	
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 72: menu_opc_1();break; //Flecha arriba
		case 80: menu_opc_3();break; //Flecha abajo
		case 13: perfil();break; //Enter
		default: menu_opc_2(); break;
	}
}

//Menu opc 3
void menu_opc_3(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	texto_titulo();
	cout << "\n\n";
	cout << "\t1. Modo campanha" << endl;
	cout << "\t2. Perfil" <<endl;
	setColor(FOREGROUND_BLUE);
	cout << "\t3. Tienda" <<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\t4. Recompensas" <<endl;
	cout << "\t5. Configuracion" <<endl;
	
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 72: menu_opc_2();break; //Flecha arriba
		case 80: menu_opc_4();break; //Flecha abajo
		case 13: tienda();break; //Enter
		default: menu_opc_3(); break;
	}
}

//Menu opc 4
void menu_opc_4(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	texto_titulo();
	cout << "\n\n";
	cout << "\t1. Modo campanha" << endl;
	cout << "\t2. Perfil" << endl;
	cout << "\t3. Tienda" <<endl;
	setColor(FOREGROUND_BLUE);
	cout << "\t4. Recompensas" <<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\t5. Configuracion" <<endl;
	
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 72: menu_opc_3();break; //Flecha arriba
		case 80: menu_opc_5();break; //Flecha abajo
		case 13: recompensas();break; //Enter
		default: menu_opc_4(); break;
	}
}

//Menu opc 5
void menu_opc_5(){
	int tecla;
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	texto_titulo();
	cout << "\n\n";
	cout << "\t1. Modo campanha" << endl;
	cout << "\t2. Perfil" <<endl;
	cout << "\t3. Tienda" <<endl;
	cout << "\t4. Recompensas" <<endl;
	setColor(FOREGROUND_BLUE);
	cout << "\t5. Configuracion" <<endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 72: menu_opc_4();break; //Flecha arriba
		case 80: menu_opc_1();break; //Flecha abajo
		case 13: configuracion();break; //Enter
		default: menu_opc_5(); break;
	}
}

void crear_perfil() {
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("CLS");
	texto_titulo();
    cout << "\n\n\n";
    cout << "\t\t\t\t\t       ";
    setColor(0);
    cout << "Crea tu perfil de usuario" << endl;
    cout << "\n";
    cout << "\t\t\t\t\t    ";
    cout << "Nombre de usuario: "; cin >> usuario;
    //Hacer que la contraseña no sea visible (***)
    cout << "\t\t\t\t\t    ";
    cout << "Contrasenha: "; cin >> contrasenha;
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("CLS");
}

void carga_variables() {
	system("title Isla Matemagica");
	//Color
	color=&dir_color;
	//Avatar
	avatar=&dir_avatar;
		//Avatares desbloqueados
	des_avatar1=&dir_des_avatar1;
	des_avatar2=&dir_des_avatar2;
	des_avatar3=&dir_des_avatar3;
    //Recompensas
    recomp1=&dir_recomp1;
    recomp2=&dir_recomp2;
    recomp3=&dir_recomp3;
    
    //Dinero
    dinero=&dir_dinero;
    
    //Exp
    exp=&dir_exp;
    
    //Objetos
    poci_suma=&dir_poci_suma;
	poli_poder=&dir_poli_poder;
	escu_frac=&dir_escu_frac;

	ataque_extra=&dir_ataque_extra;
	proteccion=&dir_proteccion;
	//Objetos
	
	//Habilidades
		//Ataque critico
	cant_ataq_crit=&dir_cant_ataq_crit;
	
	//Vida jugador
	vida_jugador=&dir_vida_jugador;

	//Vida enemigos
	vida_enemigo1_s1=&dir_vida_enemigo1_s1;
}

#endif