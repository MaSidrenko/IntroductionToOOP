#include"String.h"

//#define HOME_WORK
//#define COPY_ASSIGMENT
#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef HOME_WORK
	String str1;
	str1.print();

	//String str2 = 8;
	String str2(8);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;
	//string str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;
	cout << str5 << endl;
	cout << delimiter;
#endif // HOME_WORK

#ifdef COPY_ASSIGMENT
	String str1 = "Hello";
	String str2 = "World";
	String str3;

	cout << delimiter << endl;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;

	cout << str1 << " " << str2 << endl;
#endif // COPY_ASSIGMENT

#ifdef CALLING_CONSTRUCTORS
	String str1;			//default constractor
	str1.print();

	//string str2 = 8;		//explicit constructor ��� ������� ����������
	String str2(8);			//explicit constructor ����� ������� ������ ���
	str2.print();
	String str3 = "Hello";	//single-argiment constructor 'char'
	str3.print();

	String str4();			//����� �� ���������� ������ �����������, � �� ��������� ������
							//����� ����������� ������� str4, ������� �� ��������� ������� ����������
							// � ���������� �������� ���� 'string'
							// �.�., ����� ������� DefaulConstractor ������� ���������� 
	//str4.print();
	//���� ����� ���� ������� DefaultConstructor, ��� �������� ��������� �������:
	String str5{};			//����� ����� ������������ �� ���������
	str5.print();
	
	//string str6 = str3;		//CopyConstructor
	//string str6 (str3);		//CopyConstructor
	String str6{ str3 };		//CopyConstructor
	str6.print();
	// �������������, ��������� ����� ����������� ����� ������� ��� ������ () ��� {} 
#endif // CALLING_CONSTRUCTORS
}