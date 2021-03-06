/*4) Напишите программу, определяющую количество нулей в числе N! Известно, что N помещается в тип unsigned int. */

#include "pch.h"
#include <iostream>

int f(unsigned int n) {
	int k = 0;
	if (n <= 1) return k;
	if (n % 5 == 0) k++;
	return k + f(n - 1);
}

int main()
{
	unsigned N;
	std::cin >> N;
	std::cout << f(N) << std::endl;
	system("pause");
	return 0;
}

