#include <iostream>
#include <unistd.h>

using std::cin;
using std::cout;

#ifdef WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

void printmatrix(int matrix[6][6])
{
	for (int i = 0; i < 6; i++) {
		for (int ii = 0; ii < 6; ii++)
			cout << matrix[i][ii] << "  ";
		cout << "\n";
	}
}

void check(int matrix[6][6], int &j)
{
	for (int i = 0; i < 6; i++) {
		for (int ii = 0; ii < 6; ii++)
			if (matrix[i][ii] == 0) j++;
	}
}

void getfirecoordinates(int &r, int &c)
{
	do {
		cout << "\n\nFire at ROWS: ";
		cin >> r;
	} while (r < 0 || r > 6);
	
	do {
		cout << "\nFire at COLUMNS: ";
		cin >> c;
	} while (c < 0 || c > 6);
}

int main()
{
	int p1[6][6];
	int p2[6][6];

	int r, c; // Collects coordinates to fire
	int j; // Counter used to check for victory

	// Seeds the pseudo RNG with the current time
	srand((unsigned int)time(NULL));
restart:

	CLEAR;
	cout << "\n▂▃▄▅▆▇█▓▒░ CXXBattleShip ░▒▓█▇▆▅▄▃▂";
	cout << "\n\nWelcome!";
	cout << "\n\n(1) Start [2P mode]\n\n(2) Credits\n\n(3) Exit...\n";
	cin >> j;

	switch (j) {
	case 1:
		CLEAR;
		break;
	case 2:
		CLEAR;
		cout << "\n▂▃▄▅▆▇█▓▒░ CXXBattleShip ░▒▓█▇▆▅▄▃▂";
		cout << "\n\nDeveloped by: Borededdy\nSome minor help: MGislv";
		cout << "\n\nThank you for playing this!";
		cout << "\nIf you enjoyed it, please star our repo ;)";
		return 0;
	default:
		return 0;
	}

	// Populate 2d arrays
	for (int i = 0; i < 6; i++) {
		for (int ii = 0; ii < 6; ii++) {
			p1[ii][i] = rand() % 2;
			p2[ii][i] = rand() % 2;
		}
	}

	j = 0;
	while (1) {
		cout << "#-----Player 1-----#\n\n\n";
		printmatrix(p1);
		
		getfirecoordinates(r, c);

		if (p2[r][c] == 1) {
			cout << "\n\nPLAYER 1 > Scored a hit!\n";
			p2[r][c] = 0;
		} else {
			cout << "\n\nPLAYER 1 > Missed!\n";
		}
		sleep(4);

		CLEAR;
		check(p2, j);

		if (j == 36) {
			cout << "PLAYER 1 > Wins!\n";
			break;
		}
		j = 0;
		
		cout << "#-----Player 2-----#\n\n\n";
		printmatrix(p2);

		getfirecoordinates(r, c);

		if (p1[r][c] == 1) {
			cout << "\n\nPLAYER 2 > Scored a hit!\n";
			p1[r][c] = 0;
		} else {
			cout << "\n\nPLAYER 2 > Missed!\n";
		}
		sleep(4);
		
		CLEAR;
		check(p1, j);

		if (j == 36) {
			cout << "PLAYER 2 > Wins!";
			break;
		}
		j = 0;
	}

	cout << "\n\nWant to restart? [0 = yes]\n";
	cin >> j;

	if (j == 0)
		goto restart;
	else
		return 0;
}
