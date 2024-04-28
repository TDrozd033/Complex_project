#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(4, 3);
	Complex c2;

	cout << "Podaj liczbe zespolona :";
	cin >> c2;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	//suma
	cout << "c1 + c2 = " << c1 + c2 << endl;

	//roznica
	cout << "c1 - c2 = " << c1 - c2 << endl;

	//iloczyn
	cout << "c1 * c2 = " << c1 * c2 << endl;

	//iloraz
	cout << "c1 / c2 = " << c1 / c2 << endl;

	//modulo
	cout << "Modulo( c1 ) = " << c1.Modulo() << endl;
	cout << "Modulo( c2 ) = " << c2.Modulo() << endl;

	return 0;
}
