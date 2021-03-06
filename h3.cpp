/*3) Сверхпростым числом будем называть такое простое число, 
что его номер в последовательности простых чисел – тоже прост.
Напишите программу, находящую k-ое сверхпростое число. */

#include "pch.h"
#include <iostream>

bool g(int N) {
	if (N < 2) return false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) return false;
	}
	return true;
}

int f(int k) {
	int n = 0;
	int i = 1;
	while (k >= 1){
		i++;
		if (!g(i)) continue;
		n++;
		if (g(n)) k--;

	}
	return i;
}

int main()
{
	int k;
	std::cin >> k;
	std::cout << f(k) << std::endl;
	system("pause");
	return 0;
}
