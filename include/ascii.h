#ifndef ASCII_H
#define ASCII_H

#include <iostream>
using namespace std;

//FUNCION GOTOXY
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Titulo principal
void texto_titulo(){
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

//Titulo Items
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

//Titulo Avatares
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

// ASCII AVATARES
void avatar0(){
	int x=7,y=13;
    gotoxy(x,y);
    cout << "(o.o)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void avatar1(){
    int x=7,y=13;
    gotoxy(x,y);
    cout << "(B.B)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void avatar2(){
    int x=7,y=13;
    gotoxy(x,y);
    cout << "(V.V)" << endl;
    gotoxy(x,y+1);
    cout << "|) )|" << endl;
    gotoxy(x,y+2);
    cout << " ) ) " << endl;
    gotoxy(x,y+3);
    cout << " | | " << endl;
}

void avatar3(){
    int x=7,y=13;
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

#endif