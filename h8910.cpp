// h8910.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int x = 3, y = 2;
int pole[x][y];
bool GAME = true;

struct sapper {
		string POLE[x][y];
		int counter = x*y;
		float p;
	sapper(float P) {
		int sum = 0;
		this->p = P;
		for (int i = 0; i < y; i++) {
			for (int k = 0; k < x; k++) {
				pole[k][i] = 0;
				POLE[k][i] = 'A' + k ;
				POLE[k][i] += (char)((i + 1) / 10 + '0') ;
				POLE[k][i] += (char)(i % 10 + 1 + '0');
			}
		}
		for (int i = 0; i <= round(P * x * y); ) {
			int m = rand() % x, n = rand() % y;
			if (pole[m][n] == 0) { 
				pole[m][n] = -1;
				if (pole[m + 1][n + 1] != -1 && m + 1 < x && n + 1 < y ) pole[m + 1][n + 1]++;
				if (pole[m - 1][n - 1] != -1 && m > 0 && n > 0) pole[m - 1][n - 1]++;
				if (pole[m][n + 1] != -1 && n + 1 < y) pole[m][n + 1]++;
				if (pole[m + 1][n - 1] != -1 && m + 1 < x && n > 0) pole[m + 1][n - 1]++;
				if (pole[m - 1][n] != -1 && m > 0) pole[m - 1][n]++;
				if (pole[m][n - 1] != -1 && n > 0) pole[m][n - 1]++;
				if (pole[m + 1][n] != -1 && m + 1 < x) pole[m + 1][n]++;
				if (pole[m - 1][n + 1] != -1 && m > 0 && n + 1 < y) pole[m - 1][n + 1]++;
				i++;
			}
			
		}
	}

	void print() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
			    cout << POLE[j][i] << "  ";
				if (i < 9) cout << " ";
			}
			cout << endl << endl;
		}
	}

	int attack(string a) {
		for (int i = 0; i < y; i++) {
			for (int k = 0; k < x; k++) {
				if (a == POLE[k][i] && pole[k][i] != -1) { 
					counter--;
					POLE[k][i] = char(int(pole[k][i]) + '0');
					POLE[k][i] += "  ";
				};
				if (a == POLE[k][i] && pole[k][i] == -1) {
					POLE[k][i] = "-1  ";
					for (int p = 0; p < y; p++) {
						for (int j = 0; j < x; j++) if (pole[j][p] == -1) POLE[j][p] = "-1  ";
					}
					GAME = false;
					return 0;
				}
			}
		}
	}
};

int main()
{
	srand(TIME_UTC);
	sapper game(0.15);
	while (GAME) {
		system("cls");
		game.print();
		if (game.counter == 1 + round(game.p * x * y)) {
			cout << endl << "You win!" << endl;
			system("pause");
			return 0;
		}
		string a;
		cin >> a;
		game.attack(a);
	}
	system("cls");
	game.print();
	cout << endl << "You lose(" << endl;
	system("pause");
	return 0;
}

