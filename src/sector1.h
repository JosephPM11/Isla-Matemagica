#ifndef SECTOR1_H
#define SECTOR1_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
using namespace std;
char respuesta_c[10];

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
//Vida enemigo
int *p_vida_enemigo,p_dir_vida_enemigo=0;
		//Vida enemigo total (vida() )
int *vida_total_enemigo,dir_vida_total_enemigo=0;
//Boss
int *boss_s1,dir_boss_s1=0;

//Funciones externas enemigos sectores
extern void enemigo_s2();
extern void atacar_s2();
extern void ataque_critico_s2();

//Funciones externas sectores modo campana
extern void modo_campana_opc_1();
extern void modo_campana_opc_2();

//Funciones de color de fondo
extern void fillConsoleBackground(int);
extern void setColor(int);

//ENFRENTAMIENTO EN EL SECTOR 1
void enemigo_s1();
void vida();

void atacar_s1(){
	int resultado;
	system("CLS");
	enemigo_s1();
	vida();
	srand(time(NULL));
	int limite_superior = 100;
	int limite_inferior = 5;
	int num_random1 = 1 + rand()% (limite_superior + 1 - limite_inferior);
	int num_random2 = 1 + rand()% (limite_superior + 1 - limite_inferior);
	cout<<"  -> Vas a atacar"<<endl;
	cout<<"\n----Resuelve este ejercicio para poder atacar-----"<<endl;
	cout<<"\n  ¿Cuanto es "<<num_random1<<" + "<<num_random2<<"?"<<endl;
	int num_total=num_random1+num_random2;
	cout<<"    Respuesta: ";cin>>resultado;

	if(resultado==num_total){
		system("CLS");
		enemigo_s1();
		vida();
		srand(time(NULL));
		int mayor_ataque = 3;
		int menor_ataque = 1;
		int ataque = 1 + rand()% (mayor_ataque + 1 - menor_ataque);
		ataque+=*p_ataque_extra;
		*p_ataque_extra=0;
		if(*boss_s1==1){
			cout<<"\n    Has atacado a Numerion. Ha perdido "<<ataque<<" de vida!"<<endl;
		}
		else{
			cout<<"\n    Has atacado al enemigo. Ha perdido "<<ataque<<" de vida!"<<endl;
		}
		cout<<"\n";
		*p_vida_enemigo-=ataque;
		system("pause");
	}
	else{
		system("CLS");
		enemigo_s1();
		vida();
		cout<<"\n    Has fallado el ataque y te autoinflingiste 1 de danho!"<<endl;
		cout<<"\n";
		*p_vida_jugador-=1;
		system("pause");
		//Aqui va llamada a funcion para randomizar el daño inflingido?? o daño fijo?
		//Aqui va a regresar al menu de combate
	}
}
void menu_jugador(int sector);
void habilidades(int sector);

void ataque_critico_s1(){
	if(*p_cant_ataq_crit<=0){
		cout<<"\n";
		cout<<"  Ya no tienes ataques criticos"<<endl;
		cout<<"\n";
		system("pause");
		menu_jugador(1);
	}
	else{
		system("CLS");
		enemigo_s1();
		vida();
		cout<<"  -> Vas a atacar"<<endl;
		cout<<"\n----Resuelve este ejercicio para poder hacer un critico-----"<<endl;
		srand(time(NULL));
		int mayor_valor = 2;
		int menor_valor = 1;
		int ejercicio =  menor_valor + rand()% (mayor_valor + 1 - menor_valor);
		
		if(ejercicio==1){
		*p_cant_ataq_crit-=1;
			cout<<"\n\n";
	
			cout<<"  Clasifica los siguientes numeros como naturales, enteros o racionales: 23, -7, 1.5, 1/2, 0.75"<<endl;
			cout<<"\ta) Naturales: 23, 1.5, Enteros: 23, -7, Racionales: 1/2, 0.75"<<endl;
			cout<<"\tb) Naturales: 23, Enteros: 23, -7, 1.5, Racionales: 1/2, 0.75"<<endl;
			cout<<"\tc) Naturales: 23, Enteros: 23, -7, Racionales: 1/2, 0.75, 1.5"<<endl;
			cout<<"\td) Naturales: -7, Enteros: 23, -7, Racionales: 1.5, 1/2, 0.75"<<endl;
			cout<<"\n";
			cout<<"    Respuesta: ";cin>>respuesta_c;
			
			if(strcmp(respuesta_c, "c") == 0 || strcmp(respuesta_c, "C") == 0){
				system("CLS");
				enemigo_s1();
				vida();
				int ataque =  4;
				ataque+=*p_ataque_extra;
				*p_ataque_extra=0;
				if(*boss_s1==1){
					cout<<"\n    Has atacado a Numerion. Ha perdido "<<ataque<<" de vida!"<<endl;
				}
				else{
					cout<<"\n    Has atacado al enemigo. Ha perdido "<<ataque<<" de vida!"<<endl;
				}
				cout<<"\n";
				*p_vida_enemigo-=ataque;
				system("pause");
			}
			else{
				cout<<"\n";
				cout<<"Has fallado el ataque critico"<<endl;
				cout<<"\n";
				system("pause");
			}
		}
		else{
			if(ejercicio==2){
				*p_cant_ataq_crit-=1;
				
				cout<<"\n\n";
		
				cout<<"  ¿Que tipo de numero es 3,14159...? (Pi)"<<endl;
				cout<<"\ta) Natural"<<endl;
				cout<<"\tb) Entero"<<endl;
				cout<<"\tc) Racional"<<endl;
				cout<<"\td) Irracional"<<endl;
				cout<<"\n";
				cout<<"    Respuesta: ";cin>>respuesta_c;
		
				if(strcmp(respuesta_c, "d") == 0 || strcmp(respuesta_c, "D") == 0){
					system("CLS");
					enemigo_s1();
					vida();
					int ataque =  4;
					ataque+=*p_ataque_extra;
					*p_ataque_extra=0;
					if(*boss_s1==1){
						cout<<"\n    Has atacado a Numerion. Ha perdido "<<ataque<<" de vida!"<<endl;
					}
					else{
						cout<<"\n    Has atacado al enemigo. Ha perdido "<<ataque<<" de vida!"<<endl;
					}
					cout<<"\n";
					*p_vida_enemigo-=ataque;
					system("pause");
				}
				else{
					cout<<"\n";
					cout<<"Has fallado el ataque critico"<<endl;
					cout<<"\n";
					system("pause");
				}
			}
		}
	}
}

void habilidades(int sector){
	do{
		system("CLS");
		if(sector==1){
			enemigo_s1();
		}
		if(sector==2){
			enemigo_s2();
		}
		if(sector==3){
			//enemigo_s3();
		}
		if(sector==4){
			//enemigo_s4();
		}
		if(sector==5){
			//enemigo_s5();
		}
		vida();
		cout<<"  -> Es tu turno"<<endl;
		cout<<"\n  Que habilidad quieres usar?"<<endl;
		cout<<"  (Escribe 0 para salir de las habilidades)"<<endl;
		cout<<"\n     1. Explosion Numerica - Ataque critico ("<<*p_cant_ataq_crit<<"/2)"<<endl;
				
		cin >> numero;
		switch (numero){
		case 0:
			if(sector==1){
				menu_jugador(1);
			}
			if(sector==2){
				menu_jugador(2);
			}
			if(sector==3){
				menu_jugador(3);
			}
			if(sector==4){
				menu_jugador(4);
			}
			if(sector==5){
				menu_jugador(5);
			}
			break;
		case 1:
			if(sector==1){
				ataque_critico_s1();
			}
			if(sector==2){
				ataque_critico_s2();
			}
			if(sector==3){
				//ataque_critico_s3();
			}
			if(sector==4){
				//ataque_critico_s4();
			}
			if(sector==5){
				//ataque_critico_s5();
			}
			break;
		default:
		    cout << "Fuera de rango";
		}
	} while ((numero!=0)&&(numero!=1));
}


void pocion_suma(int sector){
	system("CLS");
	if(sector==1){
		enemigo_s1();
	}
	if(sector==2){
		enemigo_s2();
	}
	if(sector==3){
		//enemigo_s3();
	}
	if(sector==4){
		//enemigo_s4();
	}
	if(sector==5){
		//enemigo_s5();
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
	if(sector==1){
		enemigo_s1();
	}
	if(sector==2){
		enemigo_s2();
	}
	if(sector==3){
		//enemigo_s3();
	}
	if(sector==4){
		//enemigo_s4();
	}
	if(sector==5){
		//enemigo_s5();
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
	if(sector==1){
		enemigo_s1();
	}
	if(sector==2){
		enemigo_s2();
	}
	if(sector==3){
		//enemigo_s3();
	}
	if(sector==4){
		//enemigo_s4();
	}
	if(sector==5){
		//enemigo_s5();
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

void enemigo_s1(){
	//Verificar el color actual
	if(*c_color==1){
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	 	SetConsoleTextAttribute(hConsole, 7);
	}
	else{
		if(*c_color==2){
		HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	 	SetConsoleTextAttribute(hConsole, 3);
	 	}
	 		else{
	 			if(*c_color==3){
	 				HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	 				SetConsoleTextAttribute(hConsole, 11);
			 	}
			 	else{
					if(*c_color==4){
						HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	 					SetConsoleTextAttribute(hConsole, 13);
	 				}
				}
			}
		}
	cout<<"Te has cruzado con un enemigo."<<endl;
	cout<<"\n"<<endl;
	if(*boss_s1==1){
		fillConsoleBackground(BACKGROUND_CYAN);
		setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<<"\n\n\n";   
		cout<<"\t\t\t\t\t\t Numerion, El felino arcano"<<endl;
		cout<<"\n\t\t\t\t\t\t	 __      __"<<endl;
		cout<<"\t\t\t\t\t\t       _|||-----|||_"<<endl;
		cout<<"\t\t\t\t\t\t   __-||| ||||||| |-- __"<<endl;
		cout<<"\t\t\t\t\t\t  |__| |||*||T||*||| |__|"<<endl;
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	else{
		fillConsoleBackground(BACKGROUND_CYAN);
		setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"\n\n\n";
		cout<<"\t\t\t\t\t\t      Subdito numerico"<<endl;
		cout<<"\n\t\t\t\t\t\t\t    ___"<<endl;
		cout<<"\t\t\t\t\t\t\t    | |"<<endl;
		cout<<"\t\t\t\t\t\t\t  |||||||"<<endl;
		cout<<"\t\t\t\t\t\t\t  |||||||"<<endl;
		cout<<"\t\t\t\t\t\t\t    |||"<<endl;
		cout<<"\t\t\t\t\t\t\t    |||"<<endl;
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}

	
}

/*
GUIARSE CON ESTO PARA PUNTEROS - RECORDAR QUE TAMBIEN SE PONE EN EL MAIN()
int *fin_s1,*fin_s2,*fin_s3,*fin_s4,*fin_s5;
int direccion_s1=0,direccion_s2=0,direccion_s3=0,direccion_s4=0,direccion_s5=0;
*/

void vida(){
	cout<<"\n  Vida del enemigo: "<<*p_vida_enemigo<<"/"<<*vida_total_enemigo<<endl;
	cout<<"  Vida del jugador: "<<*p_vida_jugador<<"/"<<*vida_total_jugador<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
}

void menu_jugador(int sector){
	do{
		system("CLS");
		if(sector==1){
			enemigo_s1();
		}
		if(sector==2){
			enemigo_s2();
		}
		if(sector==3){
			//enemigo_s3();
		}
		if(sector==4){
			//enemigo_s4();
		}
		if(sector==5){
			//enemigo_s5();
		}
		vida();
		cout<<"  -> Es tu turno"<<endl;
		cout<<"\n  Que quieres hacer?"<<endl;
		cout<<"     1. Atacar"<<endl;
		cout<<"     2. Habilidades"<<endl;
		cout<<"     3. Inventario"<<endl;
		cout<<"     4. Huir"<<endl;
				
		cin >> numero;
		switch (numero){
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
					cout<<"\n";
					cout<<"Huiste de la batalla..."<<endl;
					cout<<"\n";
					system("pause");
					modo_campana_opc_1();
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
					modo_campana_opc_2();
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

void turno_enemigo_s1(){
	if(*p_proteccion==0){
		if(*boss_s1==1){
			srand(time(NULL));
			int mayor_ataque = 5;
			int menor_ataque = 3;
			int ataque = 1 + rand()% (mayor_ataque + 1 - menor_ataque);
			cout<<"  -> Es el turno de Numerion"<<endl;
			cout<<"\n  Numerion te ha atacado inflingiendote "<<ataque<<" de danho"<<endl;
			cout<<"\n";
			*p_vida_jugador-=ataque;
			system("pause");
		}
		else{
			srand(time(NULL));
			int mayor_ataque = 3;
			int menor_ataque = 1;
			int ataque = 1 + rand()% (mayor_ataque + 1 - menor_ataque);
			cout<<"  -> Es el turno del enemigo"<<endl;
			cout<<"\n  El enemigo te ha atacado inflingiendote "<<ataque<<" de danho"<<endl;
			cout<<"\n";
			*p_vida_jugador-=ataque;
			system("pause");	
		}
	}
	else{
		if(*p_proteccion>0){
			cout<<"  -> Es el turno del enemigo"<<endl;
			if(*p_proteccion==1){
				cout<<"\n";
				cout<<"  --Escudo fractal (0 turnos restantes)--"<<endl;
			}
			else{
				cout<<"\n";
				cout<<"  --Escudo fractal (1 turno restante)--"<<endl;
			}
			*p_proteccion-=1;
			cout<<"\n  El enemigo no puede atacarte por el Escudo Fractal"<<endl;
			cout<<"\n";
			system("pause");
		}
	}
}

void batalla_s1(){
	fillConsoleBackground(BACKGROUND_CYAN);
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	*p_cant_ataq_crit=2;
	int turno=0;
	while((*p_vida_enemigo>0)&&(*p_vida_jugador>0)){
		system("CLS");
		
		enemigo_s1();
		vida();

		if(turno==0){
			menu_jugador(1);
			turno=1;
		}
		else{
			if(turno==1){
				turno_enemigo_s1();
				turno=0;
			}		
		}
	}
	if(*p_vida_enemigo<=0){
		if(*boss_s1==1){
			*boss_s1=0;
			srand(time(NULL));
			int mayor_monedas = 150;
			int menor_monedas = 200;
			int aumento_monedas = menor_monedas + rand()% (mayor_monedas + 1 - menor_monedas);
	
			int mayor_exp = 150;
			int menor_exp = 300;
			int aumento_exp = menor_exp + rand()% (mayor_exp + 1 - menor_exp);
	
			system("CLS");
			cout<<"Numerion ha sido derrotado"<<endl;
			cout<<"!Has ganado "<<aumento_monedas<<" monedas!"<<endl;
			*p_dinero+=aumento_monedas;
			
			cout<<"!Has ganado "<<aumento_exp<<" de experiencia!"<<endl;
			*p_exp+=aumento_exp;
			cout<<"\n";
			system("pause");
			modo_campana_opc_1();
		}
		else{
			srand(time(NULL));
			int mayor_monedas = 30;
			int menor_monedas = 80;
			int aumento_monedas = menor_monedas + rand()% (mayor_monedas + 1 - menor_monedas);
	
			int mayor_exp = 30;
			int menor_exp = 80;
			int aumento_exp = menor_exp + rand()% (mayor_exp + 1 - menor_exp);
	
			system("CLS");
			cout<<"El enemigo ha sido derrotado"<<endl;
			cout<<"!Has ganado "<<aumento_monedas<<" monedas!"<<endl;
			*p_dinero+=aumento_monedas;
			
			cout<<"!Has ganado "<<aumento_exp<<" de experiencia!"<<endl;
			*p_exp+=aumento_exp;
			cout<<"\n";
			system("pause");
			modo_campana_opc_1();
		}
	}
	else{
		if(*p_vida_jugador<=0){
			system("CLS");
			cout<<"Has sido derrotado"<<endl;
			cout<<"\n";
			//Poner que has perdido monedas
			system("pause");
			modo_campana_opc_1();
		}
	}
}
//ENFRENTAMIENTO EN EL SECTOR 1


void batallas_s1(int num_batalla,int color,int& vida_jugador,int& dinero,int& suexp,int& poci_suma,int& poli_poder,int& escu_frac){
	//Color
	c_color=&dir_c_color;
	*c_color=color;
	//Dinero
	p_dinero=&p_dir_dinero;
		//Guardamos el valor pasado como parametro en el puntero de este programa.
	*p_dinero=dinero;
	//Exp
	p_exp=&p_dir_exp;
	*p_exp=suexp;
	//Objetos
    p_poci_suma=&p_dir_poci_suma;
    *p_poci_suma=poci_suma;
    
	p_poli_poder=&p_dir_poli_poder;
	*p_poli_poder=poli_poder;
	
	p_escu_frac=&p_dir_escu_frac;
	*p_escu_frac=escu_frac;
	
		//Para Poliedro Poder
	p_ataque_extra=&p_dir_ataque_extra;
		//Para Escudo Fractal
	p_proteccion=&p_dir_proteccion;
	//Habilidades
		//Ataque critico
	p_cant_ataq_crit=&p_dir_cant_ataq_crit;
	
	//Vida jugador
	p_vida_jugador=&p_dir_vida_jugador;
	*p_vida_jugador=vida_jugador;
		//Vida jugador total (vida() )
	vida_total_jugador=&dir_vida_total_jugador;
	*vida_total_jugador=*p_vida_jugador;
	
	//Vida enemigo
	p_vida_enemigo=&p_dir_vida_enemigo;
		//Vida enemigo total (vida() )
	vida_total_enemigo=&dir_vida_total_enemigo;
	//Boss
	boss_s1=&dir_boss_s1;
	
	switch(num_batalla){
		case 1:
		*p_vida_enemigo=10;
		*vida_total_enemigo=*p_vida_enemigo; 
		*boss_s1=0; break;
		case 2:
		*p_vida_enemigo=15;
		*vida_total_enemigo=*p_vida_enemigo; 
		*boss_s1=0; break;
		case 3:
		*p_vida_enemigo=20;
		*vida_total_enemigo=*p_vida_enemigo;
		*boss_s1=0; break;
		case 4:
		*p_vida_enemigo=25;
		*vida_total_enemigo=*p_vida_enemigo;
		*boss_s1=0; break;
		case 5:
		*boss_s1=1;
		*p_vida_enemigo=40;
		*vida_total_enemigo=*p_vida_enemigo; break;
		default: cout<<"Fuera de rango"; break;
	}
	batalla_s1();
	
	//Pasando valores finales al paso por parametros
	dinero=*p_dinero;
	suexp=*p_exp;
	poci_suma=*p_poci_suma;
	poli_poder=*p_poli_poder;
	escu_frac=*p_escu_frac;
}

#endif