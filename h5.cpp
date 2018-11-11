/*5) Напишите эффективную функцию, вычисляющую последнюю цифру числа, 
являющегося результатом возведения числа A в степень B. 
Числа A и B помещаются в тип long long. 
Количество действий выполняемых программой не должно превышать 
С1*(ln B)+ C2, где С1 и С2 – некоторые константы.*/

#include "pch.h"
#include <iostream>

int main()
{
	long long A, B;
	std::cin >> A >> B;
	for (int i = 1; i < log(B); i++) A = pow(A, exp(1));
	std::cout << A << std::endl;
	system("pause");
	return 0;
}

