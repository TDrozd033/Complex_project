#pragma once
#include <iostream>
using namespace std;

/*

Wykreowaæ now¹ aplikacjê konsolow¹ o nazwie ComplexTest.
Zdefiniowaæ klasê o nazwie Complex, do reprezentacji liczb zespolonych w postaci (re, im) o
sk³adowych m_re – czêœæ rzeczywista, m_im – czêœæ urojona typu double oraz metody
klasy:
 konstruktor z parametrami domyœlnymi (Re= 0, Im= 0),
 konstruktor kopiuj¹cy,
 operator podstawienia,
 SetRe( double re ); SetIm( double im ); ustawiaj¹ce odpowiednio czêœæ
rzeczywist¹ i urojon¹ liczby zespolonej.
 SetComplex( double re, double im );
 GetRe(); GetIm(); zwracaj¹ce odpowiednio czêœæ rzeczywist¹ i jej czêœæ urojon¹.
 operator dodawania i odejmowania gdzie a+bi = (a,b):
(a1,b1) ± (a2,b2),
 mno¿enia liczb zespolonych
(a1,b1) * (a2,b2)
 Dzielenia liczb zespolonych
(a1,b1) / (a2,b2)
 odpowiednie operatory += , -=, *=, /=
 Rzutowanie na typ double
 Funkcje Modulo()zwracaj¹cej wartoœæ modu³u liczy zespolonej:

 zdefiniowaæ operatory wejœcia (wczytujemy dwie liczby przedzielone bia³ym znakiem) i wyjœcia
(wypisaæ w postaci (re,im) )
W programie zdefiniowaæ liczbê zespolon¹ (4,3) oraz wczytaæ dowoln¹ drug¹. Odpowiednio
obliczyæ sumê, ró¿nicê, iloczyn, iloraz. Obliczyæ wartoœæ funkcji Modulo() dla otrzymanego
wyniku.

*/
class Complex
{
public:

	Complex(double Re = 0, double Im = 0);
	Complex(const Complex& c);


	// destruktor
	virtual ~Complex();

	// gettery
	double GetRe() const;
	double GetIm() const;

	// settery
	void SetRe(double re);
	void SetIm(double im);
	void SetComplex(double re, double im);
	double Modulo();

public: 

	Complex& operator=(const Complex& c);

	// input/output
	friend istream& operator >> (istream& in, Complex& c);
	friend ostream& operator << (ostream& out, const Complex& c);

	// dodawanie
	friend const Complex operator + (const Complex& c1, const Complex& c2); // c1 + c2
	Complex& operator += (const Complex& c);// c1 += c2

	// odejmowanie
	friend const Complex operator - (const Complex& c1, const Complex& c2); // c1 - c2
	Complex& operator -= (const Complex& c);// c1 -= c2

	// minus unarny
	friend const Complex operator - (const Complex& c);// -c	

	// mnozenie
	friend const Complex operator * (const Complex& c1, const Complex& c2);	// c1 * c2
	Complex& operator *= (const Complex& c);// c1 *= c2

	// dzielenie
	friend const Complex operator / (const Complex& c1, const Complex& c2);	// c1/c2
	Complex& operator /= (const Complex& c);// c1 /= c2

	// rzutowanie
	operator double() const;// (double)c

private:
	double m_Re;
	double m_Im;
};

//=================== INLINE FUNCTIONS


inline double Complex::GetRe() const
{
	return m_Re;
}

inline double Complex::GetIm() const
{
	return m_Im;
}

inline void Complex::SetRe(double re)
{
	m_Re = re;
}

inline void Complex::SetIm(double im)
{
	m_Im = im;
}

inline void Complex::SetComplex(double re, double im)
{
	m_Re = re;
	m_Im = im;
}


inline Complex::operator double() const
{
	return m_Re;
}


inline double Complex::Modulo()
{
	return sqrt(m_Re * m_Re + m_Im * m_Im);
}

