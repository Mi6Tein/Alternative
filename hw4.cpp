//4) Напишите программу, определяющую количество нулей в числе N! Известно, что N помещается в тип unsigned int. 
#include "pch.h"
#include <iostream>

int f(int n) {
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) k++;
	}
	return k;
}


int main()
{
	unsigned N;
	std::cin >> N;
	std::cout << f(N) << std::endl;
		system("pause");
	return 0;
}
