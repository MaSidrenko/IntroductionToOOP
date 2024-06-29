//string
#pragma once
#include<iostream>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n|-----------------------------------------------------|\n"

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//		Constactor:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	//		Opeators:
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	const char& operator[](int i)const;
	char& operator[](int i);


	//		Methods:
	void print()const;
};

