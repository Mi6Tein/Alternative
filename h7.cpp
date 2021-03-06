/*7) Напишите функцию, заполняющую двумерный прямоугольный массив
последовательными составными числами змейкой по часовой стрелке,
начиная с нижнего левого угла. Пример для массива размера 5х6:
10  12  14  15  16  18
9  33  34  35  36  20   
8  32  44  45  38  21   
6  30  42  40  39  22   
4  28  27  26  25  24 */

#include "pch.h"
#include <iostream>

using namespace std;

int f(int& N) {
	if (N < 5)  return N = 4; 
	for (int i = 2; i <= sqrt(N); i++) 	if (N % i == 0) return N;
	return ++N;
};


int main()
{
	unsigned int const a = 10, b = 10;
	int arr[a][b];
	for (int i = 0, k = 4, m = 0, n = b - 1, p=1; i < a*b; i++, k++) {
		arr[m][n] = f(k);
		if (arr[m][n - 1] < 0 && n > 0 && p == 1) {
			n--;
			continue;
		}
		p = 2;
		if (m < a - 1 && arr[m + 1][n] < 0 & p == 2) {
			m++;
			continue;
		}
		p = 3;
		if (n < b - 1 && arr[m][n + 1] < 0 && p == 3) {
			n++;
			continue;
		}
		p = 4;
		if (m > 0 && arr[m - 1][n] < 0 && p == 4) {
			m--;
			continue;
		}
		p = 1; 
		n--;
	}


	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			cout << arr[j][i] << "  ";
		}
		cout << endl << endl;
	}
	
	system("pause");
	return 0;
}

