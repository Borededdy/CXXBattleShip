#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

//Defining clear shortcut
#define CLEAR system("clear")

//Player Vars
int p1[4][4];
int p2[4][4];

void action(){
	int r, c; //Collects coordinates to fire
	int l = 0; //Counter used to check win
	int e = 0; //End Match
	while(e < 1){
		cout << "#-----Player 1-----#\n\n\n";
		for(int i = 0; i < 4; i++){
			for(int ii = 0; ii < 4; ii++){
				cout << p1[ii][i] << "  ";
			}
			cout << "\n";
		}
		cout << "\n\nFire at ROWS: ";
		cin >> r;
		cout << "\nFire at COLUMNS: ";
		cin >> c;
		if (p2[r][c] == 1){
			cout << "\n\nPLAYER 1 > Hit!\n";
			sleep(6);
			p2[r][c] = 0;
		}else{
			cout << "\n\nPLAYER 1 > Miss!\n";
			sleep(6);
		}
		cout << CLEAR;
		for(int c = 0; c < 4; c++){
			for(int cc = 0; cc < 4; cc++){
				if(p2[cc][c] == 0){
					l++;
				}
			}
		}	
		if(l == 16){
			cout << "\n\nPLAYER 1 > Wins!\n";
			sleep(6);
			exit(0);
		}
		l = 0;
		cout << "#-----Player 2-----#\n\n\n";
		for(int i = 0; i < 4; i++){
			for(int ii = 0; ii < 4; ii++){
				cout << p2[ii][i] << "  ";
			}
			cout << "\n";
		}
		cout << "\n\nFire at ROWS: ";
		cin >> r;
		cout << "\nFire at COLUMNS: ";
		cin >> c;
		if (p1[r][c] == 1){
			cout << "\n\nPLAYER 2 > Hit!\n";
			sleep(6);
			p1[r][c] = 0;
		}else{
			cout << "\n\nPLAYER 2 > Miss!\n";
			sleep(6);
		}
		cout << CLEAR;
		for(int c = 0; c < 4; c++){
			for(int cc = 0; cc < 4; cc++){
				if(p1[cc][c] == 0){
					l++;
				}
			}	
		}
		if(l == 16){
			cout << "\n\nPLAYER 1 > Wins!";
			sleep(6);
			exit(0);
		}
		l = 0;
	}
}

void charging(){
	for(int i = 0; i < 4; i++){
		for(int ii = 0; ii < 4; ii++){
			p1[ii][i] = rand() % 2;
			p2[ii][i] = rand() % 2;
		}
	}
	action();
}

void credits(){
	cout << CLEAR;
	cout << "\n▂▃▄▅▆▇█▓▒░ CXXBattleShip ░▒▓█▇▆▅▄▃▂";
	cout << "\n\nDeveloped by: Borededdy\n\nSome minor help: MGislv";
	cout << "\n\n\nThank You For Playing This!\nPlease rate to star/Watch our GIT\nrepository ;)";
	cin.ignore();
}

int main(){

	//Casting of TIME for srand
	srand((unsigned int) time(NULL));
		
	int s; //Selection Var
	
	cout << "\n▂▃▄▅▆▇█▓▒░ CXXBattleShip ░▒▓█▇▆▅▄▃▂";
	cout << "\n\nWelcome! Choose a Game mode:";
	cout << "\n\n(1) Normal Mode [2P]\n\n(2) Credits\n\n(3) Exit..";
	cin >> s;
	if(s == 1){
		cout << CLEAR;
		charging();
	} else if (s == 2){
		credits();
	}else if (s == 3){
		exit(0);
	}else{
		cout << "\n\n⚠ Uh-Oh! Seems that the option does not exist...";
	}	
}
