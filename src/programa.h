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

//Opción menu Actual
int *opcMenuActual,dir_opcMenuActual=1;
//Sector Actual
int *sectorActual,dir_sectorActual=1;
//Nivel Actual
int *nivelActual,dir_nivelActual=1;
//Objeto tienda seleccionado Actual
int *objTiendaActual,dir_objTiendaActual=1;
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

void menu();
void s1();
void s2();
void modo_campana();
void menu_sectores();

void modo_campana(){
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);                             
	ascii_modo_campana();
	mesa_tienda();
	titulo_sect_modo_campana();
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
	switch(*sectorActual){
		case 1: descripcion_s1();break;
		case 2: descripcion_s2();break;
		case 3: descripcion_s3();break;
		case 4: descripcion_s4();break;
		case 5: descripcion_s5();break;
		default: modo_campana();break;
	}
	menu_sectores();
}

void tokenSector(int sector,int x,int y){
	if(*sectorActual==sector){
		setColor(FOREGROUND_BLUE);
		token(sector,x,y-1);
	}
	else{
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  
		token(sector,x,y);
	}
}

void menu_sectores(){
	int tecla;
	tokenSector(1,15,10);
	tokenSector(2,35,10);
	tokenSector(3,55,10);
	tokenSector(4,75,10);
	tokenSector(5,95,10);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: menu();break; //Volver al menu
		case 77:  //Flecha derecha
		if(*sectorActual==5){ //Para pasar del último token al primero
			*sectorActual=1;
			modo_campana();
		}
		else{
			*sectorActual+=1;
			modo_campana();
		}
		case 75:  //Flecha izquierda
		if(*sectorActual==1){ //Para pasar del primer token al último
			*sectorActual=5;
			modo_campana();
		}
		else{
			*sectorActual-=1;
			modo_campana();
		}
		case 13: //Enter
			switch(*sectorActual){
				case 1: *sectorActual=1;*nivelActual=1;s1();break;
				case 2: *sectorActual=1;*nivelActual=1;s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: menu_sectores();break;
			}
		default: menu_sectores(); break;
	}
}

void casillaNivel(int dato1,int dato2,int dato3){
	if(*nivelActual==dato3){
		setColor(FOREGROUND_BLUE);
		asciiCasillaNivel(dato1,dato2,dato3);
	}
	else{
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  
		asciiCasillaNivel(dato1,dato2,dato3);
	}
}

void mapa_casillas(int sector){
	int tecla;
	casillaNivel(5,12,1);
	casillaNivel(11,16,2);
	casillaNivel(18,12,3);
	casillaNivel(24,16,4);
	casillaNivel(30,20,5);
	casillaNivel(37,16,6);
	casillaNivel(43,12,7);
	casillaNivel(51,9,8);
	casillaNivel(57,13,9);
	casillaNivel(64,17,10);
	casillaNivel(70,13,11);
	casillaNivel(76,17,12);
	casillaNivel(86,17,13);
	casillaNivel(94,14,14);
	casillaNivel(104,14,15);

	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  
	gotoxy(72, 1);
    cout<< "Volver a la seleccion de sectores (Presiona 0)" << endl;
	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48:  //Volver a la pantalla anterior
			switch(sector){
				case 1: *sectorActual=1;modo_campana();break;
				case 2: *sectorActual=2;modo_campana();break;
				/*case 3: *sectorActual=3;modo_campana();break;
				case 4: *sectorActual=4;modo_campana();break;
				case 5: *sectorActual=5;modo_campana();break;*/
				default: mapa_casillas(sector);break;
			}
		case 77:  //Flecha derecha
		if(*nivelActual==15){ //Para pasar del último nivel al primero
			*nivelActual=1;
			switch(sector){
				case 1: s1();break;
				case 2: s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
		}
		else{
			*nivelActual+=1;
			switch(sector){
				case 1: s1();break;
				case 2: s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
		}
		case 75:  //Flecha izquierda
		if(*nivelActual==1){ //Para pasar del primer nivel al último
			*nivelActual=15;
			switch(sector){
				case 1: s1();break;
				case 2: s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
		}
		else{
			*nivelActual-=1;
			switch(sector){
				case 1: s1();break;
				case 2: s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
		}
		case 13: //Enter
			switch(sector){
				case 1: batallas_s1(*nivelActual,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac);s1();break;
				case 2: batallas_s2(*nivelActual,*color,*vida_jugador,*dinero,*exp,*poci_suma,*poli_poder,*escu_frac);
				cout<<"PELOTASSSSSSS";
				system("pause");
				s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
		default:
			switch(sector){
				case 1: s1();break;
				case 2: s2();break;
				/*case 3: s3();break;
				case 4: s4();break;
				case 5: s5();break;*/
				default: mapa_casillas(sector);break;
			}
	}
}

//S1
void s1(){
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect1_campana();
	mapa_casillas(1);
}

//S2
void s2(){
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	titulo_sect2_campana();
	mapa_casillas(2);
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
			default:cambio_avatar();break;
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
			case 0: ascii_avatar0(7,13);break;
			case 1: ascii_avatar1(7,13);break;
			case 2: ascii_avatar2(7,13);break;
			case 3: ascii_avatar3(7,13);break;
			default:perfil();break;
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
void avatares();

void menuItemsTienda();
void menuAvataresTienda();

//TIENDA: ITEMS
int precioPociSuma = 20;
int precioPoliPoder = 40;
int precioEscuFrac = 30;

void tienda(){
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	titulo_tienda();
	mesa_tienda();
	titulo_items_tienda();
	menuItemsTienda();
}


void itemsTienda(int num, int x, int y){
	if(num==*objTiendaActual){
		setColor(FOREGROUND_BLUE);
		items(num,x,y-1);
	}
	else{
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		items(num,x,y);
	}
}

void menuItemsTienda(){
	int tecla;
	itemsTienda(1,35,11);
	itemsTienda(2,55,10);
	itemsTienda(3,79,10);
	descripcion_items(*objTiendaActual);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//Dinero
	gotoxy(5,7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
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
		case 48: *objTiendaActual=1;menu();break; //Volver al menu
		case 77: //Flecha derecha
			if(*objTiendaActual==3){
				*objTiendaActual=1;
				tienda();
			}
			else{
				*objTiendaActual+=1;
				tienda();
			}
			break;
		case 75:  //Flecha izquierda
			if(*objTiendaActual==1){
				*objTiendaActual=3;
				tienda();
			}
			else{
				*objTiendaActual-=1;
				tienda();
			}
			break;
		case 13: //Enter
			switch(*objTiendaActual){
				case 1:
					if(*dinero>=precioPociSuma){
						*dinero-=precioPociSuma;
						*poci_suma+=1;
						gotoxy(5,27);
						cout<<"-> !Has comprado una Pocion de Sumas!"<<endl;
						gotoxy(8,28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						tienda();
					}
					else{
						gotoxy(5,27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8,28);
						cout<<"para comprar este objeto :("<<endl;
						cout<<"\n";
						getch();
						tienda();
					}
					break;
				case 2:
					if(*dinero>=precioPoliPoder){
						*dinero-=precioPoliPoder;
						*poli_poder+=1;
						gotoxy(5, 27);
						cout<<"-> !Has comprado un Poliedro de Poder!"<<endl;
						gotoxy(8, 28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						tienda();
					}
					else{	
						gotoxy(5, 27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8, 28);
						cout<<"para comprar este objeto :("<<endl;
						cout<<"\n";
						getch();
						tienda();
					}
					break;
				case 3:
					if(*dinero>=precioEscuFrac){
						*dinero-=precioEscuFrac;
						*escu_frac+=1;
						gotoxy(5, 27);
						cout<<"-> !Has comprado un Escudo Fractal!"<<endl;
						gotoxy(8, 28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						tienda();
					}
					else{
						gotoxy(5, 27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8, 28);
						cout<<"para comprar este objeto :("<<endl;
						cout<<"\n";
						getch();
						tienda();
					}
					break;
				default: tienda();break;
			}
			break;
		case 81:*objTiendaActual=1;avatares();break;//Tecla q //Avatares
		case 113:*objTiendaActual=1;avatares();break;//Tecla Q //Avatares
		default:menuItemsTienda();break;
	}
}

//TIENDA: AVATARES
int precioAvatar1 = 500;
int precioAvatar2 = 500;
int precioAvatar3 = 500;

void avatares(){
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	titulo_tienda();
	mesa_tienda();
	titulo_avatares_tienda();
	menuAvataresTienda();
}

void avataresTienda(int num, int x, int y){
	if(num==*objTiendaActual){
		setColor(FOREGROUND_BLUE);
		asciiAvatares(num,x,y-1);
	}
	else{
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		asciiAvatares(num,x,y);
	}
}

void menuAvataresTienda(){
	int tecla;
	avataresTienda(1,35,12);
	avataresTienda(2,55,12);
	avataresTienda(3,79,12);
	descripcion_avatares(*objTiendaActual);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//Dinero
	gotoxy(5,7);
	if(*dinero==1){
		cout<< "Dinero: "<<*dinero<<" moneda"<<endl;
	} else{
		cout<< "Dinero: "<<*dinero<<" monedas"<<endl;
	}
	//Volver al menu (Presiona 0)
	gotoxy(91, 1);
    cout<< "Volver al menu (Presiona 0)" << endl;
    //Ir a la seccion Avatares (Presiona q/Q)
    gotoxy(100, 2);
    cout<< "Items (Presiona Q)" << endl;

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}
	//Teclas posibles
	switch (tecla){
		case 48: *objTiendaActual=1;menu();break; //Volver al menu
		case 77: //Flecha derecha
			if(*objTiendaActual==3){
				*objTiendaActual=1;
				avatares();
			}
			else{
				*objTiendaActual+=1;
				avatares();
			}
			break;
		case 75:  //Flecha izquierda
			if(*objTiendaActual==1){
				*objTiendaActual=3;
				avatares();
			}
			else{
				*objTiendaActual-=1;
				avatares();
			}
			break;
		case 13: //Enter
			switch(*objTiendaActual){
				case 1:
					if(*dinero>=precioAvatar1){
						*dinero-=precioAvatar1;
						*des_avatar1=1;
						gotoxy(5, 27);
						cout<<"-> !Has comprado el Avatar 1!"<<endl;
						gotoxy(8, 28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						avatares();
					}
					else{
						gotoxy(5, 27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8, 28);
						cout<<"para comprar este avatar :("<<endl;
						cout<<"\n";
						getch();
						avatares();
					}
					break;
				case 2:
					if(*dinero>=precioAvatar2){
						*dinero-=precioAvatar2;
						*des_avatar2=1;
						gotoxy(5, 27);
						cout<<"-> !Has comprado el Avatar 2!"<<endl;
						gotoxy(8, 28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						avatares();
					}
					else{	
						gotoxy(5, 27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8, 28);
						cout<<"para comprar este avatar :("<<endl;
						cout<<"\n";
						getch();
						avatares();
					}
					break;
				case 3:
					if(*dinero>=precioAvatar3){
						*dinero-=precioAvatar3;
						*des_avatar3=1;
						gotoxy(5, 27);
						cout<<"-> !Has comprado el Avatar 3!"<<endl;
						gotoxy(8, 28);
						cout<<"Se ha agregado a tu inventario"<<endl;
						getch();
						avatares();
					}
					else{
						gotoxy(5, 27);
						cout<<"-> No cuentas con el dinero suficiente"<<endl;
						gotoxy(8, 28);
						cout<<"para comprar este avatar :("<<endl;
						cout<<"\n";
						getch();
						avatares();
					}
					break;
				default: avatares();break;
			}
			break;
		case 81:*objTiendaActual=1;tienda();break;//Tecla q //Avatares
		case 113:*objTiendaActual=1;tienda();break;//Tecla Q //Avatares
		default:menuAvataresTienda();break;
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
			default: recompensas();break;
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
	    	case 0: menu();break;
	        case 1: cambiar_nombre();break;
	        case 2:cambiar_contrasenha();break;
	        default: configuracion();break;
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

void menuPrincipal();

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
	system("CLS");
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  
	tituloPrincipal();
	menuPrincipal();
}

void opcionMenu(int opcion){
	if(*opcMenuActual==opcion){
		setColor(FOREGROUND_BLUE);
		switch(opcion){
			case 1: cout << "\n\t1. Modo campanha" << endl; break;
			case 2: cout << "\t2. Perfil" <<endl;; break;
			case 3: cout << "\t3. Tienda" <<endl;; break;
			case 4: cout << "\t4. Recompensas" <<endl;; break;
			case 5: cout << "\t5. Configuracion" <<endl;; break;
			default: opcionMenu(opcion);break;
		}
	}
	else{
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  
		switch(opcion){
			case 1: cout << "\n\t1. Modo campanha" << endl; break;
			case 2: cout << "\t2. Perfil" <<endl;; break;
			case 3: cout << "\t3. Tienda" <<endl;; break;
			case 4: cout << "\t4. Recompensas" <<endl;; break;
			case 5: cout << "\t5. Configuracion" <<endl;; break;
			default: opcionMenu(opcion);break;
		}
	}
}

void menuPrincipal(){
	int tecla;
	opcionMenu(1);
	opcionMenu(2);
	opcionMenu(3);
	opcionMenu(4);
	opcionMenu(5);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  

	tecla= getch();
	if(tecla==224){
		tecla= getch();
	}

	//Teclas posibles
	switch (tecla){
		case 72:  //Flecha arriba
			if(*opcMenuActual==1){ //Para pasar de la primera opción a la última
				*opcMenuActual=5;
				menu();
			}
			else{
				*opcMenuActual-=1;
				menu();
			}
			break;
		case 80:  //Flecha abajo
			if(*opcMenuActual==5){ //Para pasar de la última opción a la primera
				*opcMenuActual=1;
				menu();
			}
			else{
				*opcMenuActual+=1;
				menu();
			}
			break;
		case 13: //Enter
			switch(*opcMenuActual){
				case 1: *opcMenuActual=1;*sectorActual=1;modo_campana();break;
				case 2: *opcMenuActual=1;perfil();break;
				case 3: *opcMenuActual=1;tienda();break;
				case 4: *opcMenuActual=1;recompensas();break;
				case 5: *opcMenuActual=1;configuracion();break;
				default: menuPrincipal();break;
			}
			break;
		default: menu(); break;
	}
}

void crear_perfil() {
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("CLS");
	tituloPrincipal();
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
	//Opción menu Actual
	opcMenuActual=&dir_opcMenuActual;
	//Sector Actual
	sectorActual=&dir_sectorActual;
	//Nivel Actual
	nivelActual=&dir_nivelActual;
	//Objeto tienda seleccionado Actual
	objTiendaActual=&dir_objTiendaActual;
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