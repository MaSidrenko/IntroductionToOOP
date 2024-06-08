#include<iostream>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

class Point 
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	
	Point()
	{
		x = y = 0;
		cout << "DefaultConstsrtuctor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Methods:
	double distanse(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "x = " << x << "\ty = " << y << endl;
	}

};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRICT_POINT
#define CONSTRACTOR_CHECK
//#define DISTANCE_CHECK

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
	A.distanse(B);

#endif // CONSTRACTOR_CHER
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << "Расстояние от точки 'A' до точки 'B':" << A.distanse(B) << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << B.distanse(A) << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

}

