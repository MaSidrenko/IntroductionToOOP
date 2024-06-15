#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Fraction 
{
	int integer;		
	int numerator;		
	int denominator;	
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->integer *= other.integer;
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}
	//			Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Construtor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//		Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	void print()const
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

};

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator+(Fraction& left, Fraction& right)
{
	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) + (left.get_denominator() * right.get_numerator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator-(Fraction& left, Fraction& right)
{
	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) - (left.get_denominator() * right.get_numerator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator==(Fraction& left, const Fraction& right)
{
	return left.get_integer() == right.get_integer() && left.get_denominator() == right.get_denominator() && left.get_numerator() == right.get_numerator();
}
Fraction operator/(Fraction& left,  Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
}
std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	if (obj.get_integer() == 0)return os << obj.get_numerator() << "/" << obj.get_denominator();
	else return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
}

//#define CONSTRATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRATORS_CHECK
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single Argument Constrictor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRATORS_CHECK

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper().print();
	B.to_improper().print();
	A.to_proper().print();

	Fraction C = A * B;
	C.print(); 
	Fraction  D = A + B;
	D.print();

	Fraction E = A - B;
	E.print();

	//Fraction F = B;
	Fraction F = A / B;

	//Fraction F = (A == B);
	cout << F << endl;
	cout << A << endl;

	//F.print();
	//++F;
	//F.print();
	//F++;
	//F.print();
	//--F;
	//F.print();
	//F--;
	//F.print();
	
}