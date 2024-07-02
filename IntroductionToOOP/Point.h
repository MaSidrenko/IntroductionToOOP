#pragma once
#include<iostream>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define delimeter "\n|--------------------------------------------------------------|\n"

class Point;
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
std::ostream& operator<<(std::ostream& os, const Point& obj);

class Point
{
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);
	//		Operators:
	Point& operator=(const Point& other);
	Point& operator++();
	Point operator++(int);
	//			Methods:
	double distanse(const Point& other);

	void print()const;
	Point();
	Point(double x);
	Point(double x, double y);
	Point(const Point& other);
	~Point();

};
