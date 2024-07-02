#include"Point.h"


//#define STRICT_POINT
//#define CONSTRACTOR_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COPARISON_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRICT_POINT
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRICT_POINT

#ifdef CONSTRACTOR_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	
	Point B = 5;
	
	B.print();
	Point C(2, 3);
	C.print();
	
	Point D = C;
	D.print();

	Point E;
	E = D;
	E.print();

#endif // CONSTRACTOR_CHER

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << delimeter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distanse(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << B.distanse(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(B, A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimeter << endl;
	A.distanse(B);
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3); //Point(2,3) - явно вызываем конструктор
							 //И создаем временный безымяный объект.	
							 //Этот объект и передается как парметр
							 //В первый CopyAssignment. 
	cout << delimeter << endl;
	A.print();
	cout << delimeter << endl;
	B.print();
	cout << delimeter << endl;
	C.print();
	cout << delimeter << endl;
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();

	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COPARISON_OPERATORS_CHECK
	//cout << (2 == 3);
	Point A = (2, 3);
	Point B = (7, 8);
	cout << (A == B) << endl;;
	//cout << (Point(2, 3) == Point(7, 8)) << endl;;  
#endif // COPARISON_OPERATORS_CHECK

	
	Point A(2, 3);
	
	cout << A << endl;
	Point B(2, 4);
	cout << B <<endl;
	cout << delimeter << endl;
	cout << A + B << endl;
	cout << A.distanse(B) << endl;

}

