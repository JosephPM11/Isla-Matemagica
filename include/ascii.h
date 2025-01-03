#ifndef ASCII_H
#define ASCII_H

#include <iostream>
using namespace std;

//Color de fondo y texto
extern const int BACKGROUND_CYAN;

//FUNCION GOTOXY
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//FUNCION COLOR DE FONDO Y TEXTO
void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_CYAN | textColor);
}

//CASILLA NIVEL
void asciiCasillaNivel(int x,int y,int nivel){
    gotoxy(x,y);
    cout << "    ____   " << endl;
    gotoxy(x,y+1);
    cout << "   /    \\  " << endl;
    gotoxy(x,y+2);
    if(nivel<10){
        cout << "  |  0"<<nivel<<"  | " << endl;
    }
    else{
        if(nivel>=10){
            cout << "  |  "<<nivel<<"  | " << endl;
        }
    }
    gotoxy(x,y+3);
    cout << "   \\____/ " << endl;
}
//CASILLA NIVEL

//Titulo principal
void tituloPrincipal(){
    cout << "\t\t\t\t\t     ______            __           \n";
    cout << "\t\t\t\t\t    /      |          /  |          \n";
    cout << "\t\t\t\t\t    $$$$$$/   _______ $$ |  ______  \n";
    cout << "\t\t\t\t\t      $$ |   /       |$$ | /      \\ \n";
    cout << "\t\t\t\t\t      $$ |  /$$$$$$$/ $$ | $$$$$$  |\n";
    cout << "\t\t\t\t\t      $$ |  $$      \\ $$ | /    $$ |\n";
    cout << "\t\t\t\t\t     _$$ |_  $$$$$$  |$$ |/$$$$$$$ |\n";
    cout << "\t\t\t\t\t    / $$   |/     $$/ $$ |$$    $$ |\n";
    cout << "\t\t\t\t\t    $$$$$$/ $$$$$$$/  $$/  $$$$$$$/ \n";

    cout << "\t                           __                                                  __                     \n";
    cout << "\t                          /  |                                                /  |                    \n";
    cout << "\t _____  ____    ______   _$$ |_     ______   _____  ____    ______    ______  $$/   _______   ______  \n";
    cout << "\t/     \\/    \\  /      \\ / $$   |   /      \\ /     \\/    \\  /      \\  /      \\ /  | /       | /      \\ \n";
    cout << "\t$$$$$$ $$$$  | $$$$$$  |$$$$$$/   /$$$$$$  |$$$$$$ $$$$  | $$$$$$  |/$$$$$$  |$$ |/$$$$$$$/  $$$$$$  |\n";
    cout << "\t$$ | $$ | $$ | /    $$ |  $$ | __ $$    $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ |$$ |$$ |       /    $$ |\n";
    cout << "\t$$ | $$ | $$ |/$$$$$$$ |  $$ |/  |$$$$$$$$/ $$ | $$ | $$ |/$$$$$$$ |$$ \\__$$ |$$ |$$ \\_____ /$$$$$$$ |\n";
    cout << "\t$$ | $$ | $$ |$$    $$ |  $$  $$/ $$       |$$ | $$ | $$ |$$    $$ |$$    $$ |$$ |$$       |$$    $$ |\n";
    cout << "\t$$/  $$/  $$/  $$$$$$$/    $$$$/   $$$$$$$/ $$/  $$/  $$/  $$$$$$$/  $$$$$$$ |$$/  $$$$$$$/  $$$$$$$/ \n";
    cout << "\t                                                                    /  \\__$$ |                        \n";
    cout << "\t                                                                    $$$$$$$$/                         \n";
}

//ASCII MODO CAMPAÑA
void token(int sector, int x, int y){
    switch(sector){
        case 1:
            gotoxy(x, y);
            cout << "________"<<endl;
            gotoxy(x-1, y+1);
            cout << "/        \\"<<endl;
            gotoxy(x-2, y+2);
            cout << "/    ---   \\"<<endl;
            gotoxy(x-3, y+3);
            cout << "/      |     \\"<<endl;
            gotoxy(x-3, y+4);
            cout << "\\     ---    /"<<endl;
            gotoxy(x-2, y+5);
            cout << "\\          /"<<endl;
            gotoxy(x-1, y+6);
            cout << "\\________/"<<endl;
            break;
        case 2:
            gotoxy(x, y);
            cout << "________"<<endl;
            gotoxy(x-1, y+1);
            cout << "/        \\"<<endl;
            gotoxy(x-2, y+2);
            cout << "/   ----   \\"<<endl;
            gotoxy(x-3, y+3);
            cout << "/     ||     \\"<<endl;
            gotoxy(x-3, y+4);
            cout << "\\    ----    /"<<endl;
            gotoxy(x-2, y+5);
            cout << "\\          /"<<endl;
            gotoxy(x-1, y+6);
            cout << "\\________/"<<endl;
            break;
        case 3:
            gotoxy(x, y);
            cout << "________"<<endl;
            gotoxy(x-1, y+1);
            cout << "/        \\"<<endl;
            gotoxy(x-2, y+2);
            cout << "/   -----  \\"<<endl;
            gotoxy(x-3, y+3);
            cout << "/     |||    \\"<<endl;
            gotoxy(x-3, y+4);
            cout << "\\    -----   /"<<endl;
            gotoxy(x-2, y+5);
            cout << "\\          /"<<endl;
            gotoxy(x-1, y+6);
            cout << "\\________/"<<endl;
            break;
        case 4:
            gotoxy(x, y);
            cout << "________"<<endl;
            gotoxy(x-1, y+1);
            cout << "/        \\"<<endl;
            gotoxy(x-2, y+2);
            cout << "/  ------  \\"<<endl;
            gotoxy(x-3, y+3);
            cout << "/    ||||    \\"<<endl;
            gotoxy(x-3, y+4);
            cout << "\\   ------   /"<<endl;
            gotoxy(x-2, y+5);
            cout << "\\          /"<<endl;
            gotoxy(x-1, y+6);
            cout << "\\________/"<<endl;
            break;
        case 5:
            gotoxy(x, y);
            cout << "________"<<endl;
            gotoxy(x-1, y+1);
            cout << "/        \\"<<endl;
            gotoxy(x-2, y+2);
            cout << "/          \\"<<endl;
            gotoxy(x-3, y+3);
            cout << "/    \\   /   \\"<<endl;
            gotoxy(x-3, y+4);
            cout << "\\     \\_/    /"<<endl;
            gotoxy(x-2, y+5);
            cout << "\\          /"<<endl;
            gotoxy(x-1, y+6);
            cout << "\\________/"<<endl;
            break;
        default:token(sector,x,y);
    }
}


/*
void token_s1(int x, int y){
    gotoxy(x, y);
    cout << "________"<<endl;
	gotoxy(x-1, y+1);
    cout << "/        \\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/    ---   \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/      |     \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\     ---    /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\          /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\________/"<<endl;
}

void token_s2(int x, int y){
    gotoxy(x, y);
    cout << "________"<<endl;
	gotoxy(x-1, y+1);
    cout << "/        \\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/   ----   \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/     ||     \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\    ----    /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\          /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\________/"<<endl;
}

void token_s3(int x, int y){
    gotoxy(x, y);
    cout << "________"<<endl;
	gotoxy(x-1, y+1);
    cout << "/        \\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/   -----  \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/     |||    \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\    -----   /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\          /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\________/"<<endl;
}

void token_s4(int x, int y){
    gotoxy(x, y);
    cout << "________"<<endl;
	gotoxy(x-1, y+1);
    cout << "/        \\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/  ------  \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/    ||||    \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\   ------   /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\          /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\________/"<<endl;
}

void token_s5(int x, int y){
    gotoxy(x, y);
    cout << "________"<<endl;
	gotoxy(x-1, y+1);
    cout << "/        \\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/          \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/    \\   /   \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\     \\_/    /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\          /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\________/"<<endl;
}
*/

void titulo_sect_modo_campana(){
	gotoxy(72, 21);
	cout<<"  ___ ___ ___ _____ ___  ___ ___ ___ "<<endl;
	gotoxy(72, 22);
	cout<<" / __| __/ __|_   _/ _ \\| _ \\ __/ __|"<<endl;
	gotoxy(72, 23);
	cout<<" \\__ \\ _| (__  | || (_) |   / _|\\__ \\"<<endl;
	gotoxy(72, 24);
	cout<<" |___/___\\___| |_| \\___/|_|_\\___|___/"<<endl;
}

void ascii_modo_campana(){
	cout<<"                                                                     _____"<<endl;
	cout<<"    _____  _____  ____   _____    _____  _____  _____  _____  _____  _____  _____ "<<endl; 
	cout<<"   |     ||     ||    \\ |     |  |     ||  _  ||     ||  _  ||  _  ||   | ||  _  |"<<endl;
	cout<<"   | | | ||  |  ||  |  ||  |  |  |   --||     || | | ||   __||     || | | ||     |"<<endl;
	cout<<"   |_|_|_||_____||____/ |_____|  |_____||__|__||_|_|_||__|   |__|__||_|___||__|__|"<<endl;

}

void titulo_sect1_campana(){
	cout << "\n     ___ ___ ___ _____ ___  ___    _ " << endl;
    cout << "    / __| __/ __|_   _/ _ \\| _ \\  / |" << endl;
    cout << "    \\__ \\ _| (__  | || (_) |   /  | |" << endl;
    cout << "    |___/___\\___| |_| \\___/|_|_\\  |_|" << endl;
}

void titulo_sect2_campana(){
	cout << "\n     ___ ___ ___ _____ ___  ___   ___ " << endl; 
    cout << "    / __| __/ __|_   _/ _ \\| _ \\ |_  )" << endl;
    cout << "    \\__ \\ _| (__  | || (_) |   /  / /" << endl; 
    cout << "    |___/___\\___| |_| \\___/|_|_\\ /___|" << endl;	
}
//ASCII MODO CAMPAÑA

void titulo_perfil(){
	cout<<"\n     _____ _____ _____ _____ __ __"<<endl; 
	cout<<"    |  _  |   __| __  |   __|  |  |  "<<endl;
	cout<<"    |   __|   __|    -|   __|  |  |_"<<endl;
	cout<<"    |__|  |_____|__|__|__|  |__|_____|"<<endl;	
}

//ASCII TIENDA
void titulo_tienda(){
	cout<<"\n    _____  __  _____  _____  ____   _____"<<endl; 
	cout<<"   |_   _||  ||   __||   | ||    \\ |  _  |"<<endl;
	cout<<"     | |  |  ||   __|| | | ||  |  ||     |"<<endl;
	cout<<"     |_|  |__||_____||_|___||____/ |__|__|"<<endl;	
}

void mesa_tienda(){
	gotoxy(4, 13);
	cout << "________________________________________________________________________________________________________________" << endl;
	gotoxy(3, 14);
	cout<<"/                                                                                                                \\"<<endl;
	gotoxy(2, 15);
	cout<<"/                                                                                                                  \\"<<endl;
	gotoxy(1, 16);
	cout<<"/                                                                                                                    \\"<<endl;
	gotoxy(0, 17);
	cout << "/______________________________________________________________________________________________________________________\\" << endl;
	gotoxy(0, 18);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 19);                                           
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 20);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 21);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 22);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 23);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 24);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 25);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 26);
	cout<<"|                                                         |                                                            |"<<endl;
	gotoxy(0, 27);
	cout<<"|                                                         |                                                            |"<<endl;                                                                                                                   
	gotoxy(0, 28);
	cout<<"|                                                         |                                                            |"<<endl;     
}

void titulo_items_tienda(){
	gotoxy(74, 21);
	cout<<"  ___ _____ ___ __  __ ___ "<<endl;
	gotoxy(74, 22);
	cout<<" |_ _|_   _| __|  \\/  / __|"<<endl;
	gotoxy(74, 23);
	cout<<"  | |  | | | _|| |\\/| \\__ \\"<<endl;
	gotoxy(74, 24);
	cout<<" |___| |_| |___|_|  |_|___/"<<endl;
}

void titulo_avatares_tienda(){
	gotoxy(71, 21);
	cout<<"    ___   ___ _____ _   ___ ___ ___ "<<endl;
	gotoxy(71, 22);
	cout<<"   /_\\ \\ / /_\\_   _/_\\ | _ \\ __/ __|"<<endl;
	gotoxy(71, 23);
	cout<<"  / _ \\ V / _ \\| |/ _ \\|   / _|\\__ \\"<<endl;
	gotoxy(71, 24);
	cout<<" /_/ \\_\\_/_/ \\_\\_/_/ \\_\\_|_\\___|___/"<<endl;
}
//ASCII TIENDA

//ASCII ITEMS
void ascii_poci_suma(int x,int y);
void ascii_poli_poder(int x,int y);
void ascii_escu_frac(int x,int y);

void items(int num, int x,int y){
    switch(num){
        case 1: ascii_poci_suma(x,y);break;
        case 2: ascii_poli_poder(x,y);break;
        case 3: ascii_escu_frac(x,y);break;
        default: items(num,x,y);break;
    }
}

void ascii_poci_suma(int x,int y){
    gotoxy(x, y);
	cout << "_____" << endl;
	gotoxy(x, y+1);
    cout << "|___|" << endl;
    gotoxy(x, y+2);
    cout << "/   \\" << endl;
    gotoxy(x-1, y+3);
    cout << "/ +  +\\" << endl;
    gotoxy(x-2, y+4);
    cout << "/   +   \\" << endl;
    gotoxy(x-3, y+5);
    cout << "(_________)" << endl;
}

void ascii_poli_poder(int x,int y){
	gotoxy(x, y);
    cout << "_______"<<endl;
	gotoxy(x-1, y+1);
    cout << "/\\     /\\"<<endl;
    gotoxy(x-2, y+2);
    cout << "/  \\___/  \\"<<endl;
    gotoxy(x-3, y+3);
    cout << "/   /   \\   \\"<<endl;
    gotoxy(x-3, y+4);
    cout << "\\   \\___/   /"<<endl;
    gotoxy(x-2, y+5);
    cout << "\\  /   \\  /"<<endl;
    gotoxy(x-1, y+6);
    cout << "\\/_____\\/"<<endl;
}

void ascii_escu_frac(int x,int y){
	gotoxy(x, y);
	cout << "*****"<<endl;
	gotoxy(x-1, y+1);
    cout << "*     *"<<endl;
    gotoxy(x-3, y+2);
    cout << "*   * *   *"<<endl;
    gotoxy(x-4, y+3);
    cout << "*  * * * *  *"<<endl;
    gotoxy(x-3, y+4);
    cout << "*   * *   *"<<endl;
    gotoxy(x-1, y+5);
    cout << "*     *"<<endl;
    gotoxy(x, y+6);
    cout << "*****"<<endl;
}

//ASCII ITEMS

// ASCII AVATARES
void ascii_avatar1(int x,int y);
void ascii_avatar2(int x,int y);
void ascii_avatar3(int x,int y);

void asciiAvatares(int num, int x,int y){
    switch(num){
        case 1: ascii_avatar1(x,y);break;
        case 2: ascii_avatar2(x,y);break;
        case 3: ascii_avatar3(x,y);break;
        default: asciiAvatares(num,x,y);break;
    }
}

void ascii_avatar0(int x,int y){
    gotoxy(x,y);
    cout << "(o.o)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void ascii_avatar1(int x,int y){
    gotoxy(x,y);
    cout << "(B.B)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void ascii_avatar2(int x,int y){
    gotoxy(x,y);
    cout << "(V.V)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void ascii_avatar3(int x,int y){
    gotoxy(x,y);
    cout << "(UwU)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}
// ASCII AVATARES

//ASCII BOSSES
void bossNumerion(){
		cout<<"\n\t\t\t\t\t\t	 __      __"<<endl;
		cout<<"\t\t\t\t\t\t       _|||-----|||_"<<endl;
		cout<<"\t\t\t\t\t\t   __-||| ||||||| |-- __"<<endl;
		cout<<"\t\t\t\t\t\t  |__| |||*||T||*||| |__|"<<endl;
}

void bossReyMomonga(){
    cout << "   o____o   " << endl;
    cout << "  /v    v\\  " << endl;
    cout << " />      <\\ " << endl;
    cout << " \\        / " << endl;
    cout << "  o______o  " << endl;
}
//ASCII BOSSES

//ASCII ENEMIGOS
void subditoNumerico(){
    	cout<<"\n\t\t\t\t\t\t\t    ___"<<endl;
		cout<<"\t\t\t\t\t\t\t    | |"<<endl;
		cout<<"\t\t\t\t\t\t\t  |||||||"<<endl;
		cout<<"\t\t\t\t\t\t\t  |||||||"<<endl;
		cout<<"\t\t\t\t\t\t\t    |||"<<endl;
		cout<<"\t\t\t\t\t\t\t    |||"<<endl;
}
//ASCII ENEMIGOS

#endif