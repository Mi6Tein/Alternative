//2) Напишите программу, вычисляющую сумму нечетных цифр целого числа
#include "pch.h"
#include <iostream>

int main()
{
	unsigned N;
	std::cin >> N;
	int sum = 0;
	while (N / 10 != 0 || N % 10 !=0) {
		if (N % 10 % 2 == 1) {
			sum += N % 10;
		}
		N /= 10;
	}
	std::cout << sum << " " << std::endl;
	system("pause");
	return 0;
}
