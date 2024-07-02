#include"Fraction.h"

//#define CONSTRATORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTREAM_CHEK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_HOME_WORK

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

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper().print();
	B.to_improper().print();

	Fraction C = A / B;
	C.print();
	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK
	
#ifdef IOSTREAM_CHEK
	cout << (Fraction(1, 5, 2) != Fraction(1, 5, 2)) << endl;
	Fraction A;
	cout << "¬ведите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // IOSTREAM_CHEK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;

	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;
	cout << delimiter << endl;
	B = (Fraction)8;
	cout << delimiter << endl;

	cout << B << endl;
	cout << delimiter << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_HOME_WORK

	Fraction A = 3.333;
	cout << A << endl;
#endif // CONVERSIONS_HOME_WORK

	Fraction A(2,3,4);
	A.to_improper();
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;
	cout << A << endl;

	double da = (double)A;
	cout << da << endl;

}