#include "Complex.h"

// konstruktory
Complex::Complex(double Re, double Im)
{
  m_Re = Re;
  m_Im = Im;
}

Complex::Complex(const Complex& c)
{
  SetComplex(c.GetRe(), c.GetIm());
}

// destruktor
Complex::~Complex()
{
}

// operatory
Complex& Complex::operator = (const Complex& c)
{
  m_Im = c.GetIm();
  m_Re = c.GetRe();

  return *this;
}

// input/output
istream& operator >> (istream& in, Complex& c)
{
	double nRe;
	double nIm;
	in >> nRe >> nIm;
	c.SetRe(nRe);
	c.SetIm(nIm);
	return in;
}


ostream& operator << (ostream& out, const Complex& c)
{
	out << "(" << c.GetRe() << "," << c.GetIm() << "i)";
	return out;
}


// dodawanie
const Complex operator + (const Complex& c1, const Complex& c2)  // c1 + c2
{
	Complex res(c1);
	return res += c2;
}

Complex& Complex::operator += (const Complex& c)// c1 += c2
{
	m_Im += c.GetIm();
	m_Re += c.GetRe();
	return *this;
}

// odejmowanie
const Complex operator - (const Complex& c1, const Complex& c2) // c1 - c2
{
	Complex res(c1);
	return res -= c2;
}

Complex& Complex::operator -= (const Complex& c)// c1 -= c2
{
	m_Im -= c.GetIm();
	m_Re -= c.GetRe();
	return *this;
}

// minus unarny
const Complex operator - (const Complex& c)	// -c	
{
	return Complex(-c.GetRe(), -c.GetIm());
}

// mnozenie
const Complex operator * (const Complex& c1, const Complex& c2) // c1 * c2
{
	Complex res(c1);
	return res *= c2;
}

// wzor   (a+bi)×(c+di)=(ac?bd)+(ad+bc)i
Complex& Complex::operator *= (const Complex& c)// c1 *= c2
{
	double rtemp = c.GetRe() * m_Re - c.GetIm() * m_Im;
	double itemp = c.GetIm() * m_Re + c.GetRe() * m_Im;
	SetComplex(rtemp, itemp);
	return *this;
}

// dzielenie
const Complex operator / (const Complex& c1, const Complex& c2) // c1/c2
{
	Complex res(c1);
	return res /= c2;
}
// mnozymy licznik i mianownik przez liczbe  sprzezona  do liczby  w mianowniku
// (a + bi)/(x + yi) = (a * x) + (b * y)/(x^2 + y^2) + (b * x) - (a * y)/(x^2 + y^2)i
Complex& Complex::operator /= (const Complex& c)// c1 /= c2
{
	double a = m_Re;
	double b = m_Im;
	double x = c.GetRe();
	double y = c.GetIm();

	if (x == 0 && y == 0)
	{
		cerr << "Dzielenie przez 0!" << endl;
	}

	m_Re = (a * x + b * y) / (x * x + y * y); // czesc rzeczywista
	m_Im = (b * x - a * y) / (x * x + y * y); // czesc urojona

	return *this;
}

