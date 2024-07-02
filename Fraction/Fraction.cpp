#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//			Constructors:
Fraction::Fraction()
{
	integer = 0;
	numerator = 0;
	set_denominator(1);
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	set_denominator(1);
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	//decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator + .1;
	reduce();
	cout << "ConstructorDouble:\t" << this << endl;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "2ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Construtor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
//		Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(Fraction& other)
{
	//this->to_improper();
	//other.to_improper();
	//this->numerator *= other.numerator;
	//this->denominator *= other.denominator;
	//this->to_proper();
	//other.to_proper();
	return *this = *this * other;
}
Fraction& Fraction::operator/=(Fraction& other)
{
	return *this = *this / other;
}
//		type-cast operators:
Fraction::operator int()
{
	return to_proper().integer;
	//return integer;
}
Fraction::operator double()const
{
	//return to_improper().numerator / (double)denominator;
	return integer + (numerator / (double)denominator);
}
//		Methods:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GSD = more; //GSD - Greatest Common Divisor
	numerator /= GSD;
	denominator /= GSD;
	return *this;
}
void Fraction::print()const
{
	if (integer) cout << integer;
	if (numerator != 0)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";

	}
	else if (integer == 0) cout << 0;
	cout << endl;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/

	//Fraction result
	//(
	//	left.get_numerator() * right.get_numerator(),
	//	left.get_denominator() * right.get_denominator()
	//);
	//result.to_proper();
	//return result;
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() / left.get_denominator()) > (right.get_numerator() / right.get_denominator());
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() / left.get_denominator()) < (right.get_numerator() / right.get_denominator());
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
bool operator>=(const Fraction& left, const Fraction right)
{
	return !(left < right);
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() / left.get_denominator()) == (right.get_numerator() / right.get_denominator());
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return !((left.get_numerator() / left.get_denominator()) == (right.get_numerator() / right.get_denominator()));
}
std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	if (obj.get_integer() == 0)return os << obj.get_numerator() << "/" << obj.get_denominator();
	else if (obj.get_numerator() == 0)return os << obj.get_integer();
	else return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	//int integer, numerator, denuminator;
	//is >> integer >> numerator >> denuminator;
	//obj = Fraction(integer, numerator, denuminator); 
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int numbers[3] = {};
	int n = 0;
	const char delimiters[] = " /()";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch); // ‘ункци€ atoi() принимает строку, и возвращает целочисленный аналог этой строки,
	// “о есть строку перобразует в число. 
//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}

	return is;
}