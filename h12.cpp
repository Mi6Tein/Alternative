/*12) Напишите структуру LongInt для работы с большими целыми числами. 
Пример большого числа: “122333444455555666666777777788888888999999999”. 
Для этой структуры 
должны быть перегружены арифметические действия, 
как бинарные операторы(+ etc), так и присваивающие операторы(+= etc). */

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) {
	if (a >= b) return a;
	return b;
}

int min(int a, int b) {
	if (a <= b) return a;
	return b;
}

struct Longint {
	string str;
	Longint(string str = "0") {
		this->str = str;
	}

const Longint& operator += (const Longint& b) {
		int res = 0;
		string end;
		for (int i = 1; i <= max(b.str.length(), str.length()); i++) {
			if (i <= min(b.str.length(), str.length())) {
				end = char(((int)(b.str[b.str.length() - i]) + (int)(str[str.length() - i]) - 2 * (int)('0') + res) % 10 + '0') + end;
				res = ((int)(b.str[b.str.length() - i]) + (int)(str[str.length() - i]) - 2 * (int)('0') + res) / 10;
			}
			else {
				if (b.str.length() <= str.length()) {
					end = char(((int)(str[str.length() - i]) - (int)('0') + res) % 10 + '0') + end;
					res = ((int)(str[str.length() - i]) - (int)('0') + res) / 10;
				}
				else {
					end = char(((int)(b.str[str.length() - i]) - (int)('0') + res) % 10 + '0') + end;
					res = ((int)(b.str[str.length() - i]) - (int)('0') + res) / 10;
				}
			}
		}
		if (res != 0) end = (char)(res + '0') + end;
		str = end;
		return *this;

	}

	 Longint& operator = (const Longint& a) {

		str = a.str;
		return *this;
	}
};


 const Longint& operator + ( Longint& a, const Longint& b) { //------????????????????????????????????
	return a+=b;
}

int main()
{
	Longint a("1200"), b("701");
	b = a + a;
	cout << b.str << endl << a.str << endl;
	system("pause");
}
