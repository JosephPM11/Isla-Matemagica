#ifndef UTILIDADES_SECTORES_H
#define UTILIDADES_SECTORES_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "ascii.h"
#include "../src/sector1.h"
using namespace std;

//Color de fondo y texto
extern const int BACKGROUND_CYAN;
int numero;

//Color
int *c_color,dir_c_color=0;
//Dinero
int *p_dinero,p_dir_dinero=0;
//Exp
int *p_exp,p_dir_exp=0;
//Objetos
int *p_poci_suma,p_dir_poci_suma=0;
int *p_poli_poder,p_dir_poli_poder=0;
int *p_escu_frac,p_dir_escu_frac=0;

int *p_ataque_extra,p_dir_ataque_extra=0;
int *p_proteccion,p_dir_proteccion=0;
//Habilidades
	//Ataque critico
int *p_cant_ataq_crit,p_dir_cant_ataq_crit=2;

//Vida jugador
int *p_vida_jugador,p_dir_vida_jugador=0;
		//Vida jugador total (vida() )
int *vida_total_jugador,dir_vida_total_jugador=0;
//Huida jugador
int *huida,dir_huida=0;
//Vida enemigo
int *p_vida_enemigo,p_dir_vida_enemigo=0;
		//Vida enemigo total (vida() )
int *vida_total_enemigo,dir_vida_total_enemigo=0;
//Boss
int *boss_s1,dir_boss_s1=0;

extern void enemigo_s1();
extern void atacar_s1();

extern void ataque_critico_s1();
void inventario_batalla(int sector);

void menu_jugador(int sector){
	do{
		system("CLS");
		switch(sector){
			case 1: enemigo_s1();break;
			case 2: enemigo_s2();break;
			case 3: //enemigo_s3();break;
			case 4: //enemigo_s4();break;
			case 5: //enemigo_s5();break;
			default: menu_jugador(sector);break;
		}
		vida();
		cout<<"  -> Es tu turno"<<endl;
		cout<<"\n  Que quieres hacer?"<<endl;
		cout<<"     1. Atacar"<<endl;
		cout<<"     2. Habilidades"<<endl;
		cout<<"     3. Inventario"<<endl;
		cout<<"     4. Huir"<<endl;
				
		cin>>numero;
		switch(numero){
		case 1:
			if(sector==1){
				atacar_s1();
			}
			if(sector==2){
				atacar_s2();
			}
			if(sector==3){
				//atacar_s3();
			}
			if(sector==4){
				//atacar_s4();
			}
			if(sector==5){
				//atacar_s5();
			}
			break;
		case 2:
			habilidades(sector);
			break;
		case 3:
			inventario_batalla(sector);
			break;
		case 4:
			if(sector==1){
				if(*boss_s1==1){
					cout<<"\n";
					cout<<"Numerion ha olido tus intenciones. No te permitira escapar..."<<endl;
					cout<<"\n";
					system("pause");
				}
				else{
					*huida=1;
				}
			}
			if(sector==2){
				extern int *boss_s2;
				if(*boss_s2==1){
					cout<<"\n";
					cout<<"Jefe 2 ha olido tus intenciones. No te permitira escapar..."<<endl;
					cout<<"\n";
					system("pause");
				}
				else{
					cout<<"\n";
					cout<<"Huiste de la batalla..."<<endl;
					cout<<"\n";
					system("pause");
				}
			}
			//AQUI VAN LOS NUEVOS JEFES
			//PONER CUANDO TENGA PUNTEROS *boss_s3,*boss_s4...
			break;

		default:
		    cout << "Fuera de rango"; break;
		}
	} while ((numero<1)or(numero>4));
}

void habilidades(int sector){
	do{
		system("CLS");
		switch(sector){
			case 1: enemigo_s1();break;
			case 2: enemigo_s2();break;
			case 3: //enemigo_s3();break;
			case 4: //enemigo_s4();break;
			case 5: //enemigo_s5();break;
			default: menu_jugador(sector);break;
		}
		vida();
		cout<<"  -> Es tu turno"<<endl;
		cout<<"\n  Que habilidad quieres usar?"<<endl;
		cout<<"  (Escribe 0 para salir de las habilidades)"<<endl;
		cout<<"\n     1. Explosion Numerica - Ataque critico ("<<*p_cant_ataq_crit<<"/2)"<<endl;
				
		cin>>numero;
		switch(numero){
		case 0:
			switch(sector){
				case 1: menu_jugador(1);break;
				case 2: menu_jugador(2);break;
				case 3: //menu_jugador(3);break;
				case 4: //menu_jugador(4);break;
				case 5: //menu_jugador(5);break;
				default: habilidades(sector);break;
			}
			break;
		case 1:
			switch(sector){
				case 1: ataque_critico_s1();break;
				case 2: ataque_critico_s2();;break;
				case 3: //ataque_critico_s3();break;
				case 4: //ataque_critico_s4();break;
				case 5: //ataque_critico_s5();break;
				default: habilidades(sector);break;
			}
			break;
		default:
		    cout << "Fuera de rango";
		}
	} while ((numero!=0)&&(numero!=1));
}

void pocion_suma(int sector){
	system("CLS");

	switch(sector){
		case 1: enemigo_s1();break;
		case 2: enemigo_s2();break;
		case 3: //enemigo_s3();break;
		case 4: //enemigo_s4();break;
		case 5: //enemigo_s5();break;
		default: pocion_suma(sector);break;
	}
	vida();
	srand(time(NULL));
		int mayor_vida = 3;
		int menor_vida = 1;
		int vida_extra = menor_vida + rand()% (mayor_vida + 1 - menor_vida);
		*p_vida_jugador+=vida_extra;
		cout<<"\n    Has utilizado una Pocion de sumas. !Has recuperado "<<vida_extra<<" de vida!"<<endl;
		cout<<"\n";
		*p_poci_suma-=1;
		system("pause");
}

void poliedro_poder(int sector){
	system("CLS");
	switch(sector){
		case 1: enemigo_s1();break;
		case 2: enemigo_s2();break;
		case 3: //enemigo_s3();break;
		case 4: //enemigo_s4();break;
		case 5: //enemigo_s5();break;
		default: poliedro_poder(sector);break;
	}
	vida();
	int mayor_ataque = 2;
	int menor_ataque = 1;
	*p_ataque_extra = menor_ataque + rand()% (mayor_ataque + 1 - menor_ataque);
	cout<<"\n    Has utilizado una Poliedro de Poder. !Tu proximo ataque aumenta en "<<*p_ataque_extra<<"!"<<endl;
	cout<<"\n";
	*p_poli_poder-=1;
	system("pause");
}

void escudo_fractal(int sector){
	system("CLS");
	switch(sector){
		case 1: enemigo_s1();break;
		case 2: enemigo_s2();break;
		case 3: //enemigo_s3();break;
		case 4: //enemigo_s4();break;
		case 5: //enemigo_s5();break;
		default: escudo_fractal(sector);break;
	}
	vida();
	int mayor_proteccion = 2;
	int menor_proteccion = 1;
	*p_proteccion = menor_proteccion + rand()% (mayor_proteccion + 1 - menor_proteccion);
	
	if(*p_proteccion==1){
		cout<<"\n    Has utilizado un Escudo Fractal. !El enemigo no puede atacarte por "<<*p_proteccion<<" turno!"<<endl;
		cout<<"\n";
		*p_escu_frac-=1;
		system("pause");
	}
	else{
		cout<<"\n    Has utilizado un Escudo Fractal. !El enemigo no puede atacarte por "<<*p_proteccion<<" turnos!"<<endl;
		cout<<"\n";
		*p_escu_frac-=1;
		system("pause");
	}
}

void inventario_batalla(int sector){
	system("CLS");
	cout<<"\n----------INVENTARIO-----------"<<endl;
	cout<<"\n";
	cout<<"1. Pocion de sumas - Cura de 1 a 3 de vida (x"<<*p_poci_suma<<")"<<endl;
	cout<<"2. Poliedro de poder - Aumenta tu ataque de 1 a 2 (x"<<*p_poli_poder<<")"<<endl;
	cout<<"3. Escudo fractal - Te protege de 1 a 2 ataques (x"<<*p_escu_frac<<")"<<endl;
	cout<<"\n";
	cout<<"---------------------------------------"<<endl;

	do{
		cout<<"(Escribe 0 para salir del inventario)"<<endl;
		cin >> numero;
		switch (numero){
		case 0:
			system("CLS");
			if(sector==1){
				enemigo_s1();
				vida();
				menu_jugador(1);
			}
			if(sector==2){
				enemigo_s2();
				vida();
				menu_jugador(2);
			}
			if(sector==3){
				//enemigo_s3();
				vida();
				menu_jugador(3);
			}
			if(sector==4){
				//enemigo_s4();
				vida();
				menu_jugador(4);
			}
			if(sector==5){
				//enemigo_s5();
				vida();
				menu_jugador(5);
			}
			break;
		case 1:
			if(*p_poci_suma>0){
				pocion_suma(sector);
			}
			else{
				cout<<"\n";
				cout<<"No tienes este objeto"<<endl;
				cout<<"\n";
				system("pause");
				inventario_batalla(sector);
			}
			break;
		case 2:
			if(*p_poli_poder>0){
				poliedro_poder(sector);
			}
			else{
				cout<<"\n";
				cout<<"No tienes este objeto"<<endl;
				cout<<"\n";
				system("pause");
				inventario_batalla(sector);
			}
			break;
		case 3:
			if(*p_escu_frac>0){
				escudo_fractal(sector);
			}
			else{
				cout<<"\n";
				cout<<"No tienes este objeto"<<endl;
				cout<<"\n";
				system("pause");
				inventario_batalla(sector);
			}
			break;
		default:
		    cout << "Fuera de rango";
		}
	} while ((numero<0)or(numero>3));
	
}

void vida(){
	cout<<"\n  Vida del enemigo: "<<*p_vida_enemigo<<"/"<<*vida_total_enemigo<<endl;
	cout<<"  Vida del jugador: "<<*p_vida_jugador<<"/"<<*vida_total_jugador<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
}

#endif