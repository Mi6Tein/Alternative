/*1) Напишите рекурсивную функцию, позволяющую вычислять значение функции Эйлера. */

#include "pch.h"
#include <iostream>

unsigned int gcd(unsigned int a, unsigned int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

unsigned int f(unsigned int N) {
	if (N == 0) return 0;
	if (N == 1) return 1;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) return f(i) * f(N / i) * gcd(i, N / i) / f(gcd(i, N / i));
	}
	return N - 1;
}

int main()
{
	int k;
	std::cin >> k;
    std::cout << f(k) << std::endl;
	system("pause");
	return 0;
}

