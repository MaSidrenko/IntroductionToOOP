#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n|-----------------------------------------------------|\n"

class string
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//		Constactor:
	explicit string(int size = 80):size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	string(const char str[]):string(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		// Ф-ция strlen() возвращает размер строки в символах
		// И нам нужно добавить ещё один байт для NULL-Terminator`a
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}
	string(const string& other):string(other.str)
	{
		// Deep copy (Побитовое копирование)
		//this->size = other.size;
		//this->str = new char[size] {};
		/*for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}*/
		cout << "CopyConstructor:" << this << endl;
	}
	string(string&& other)noexcept:size(other.size), str(other.str)
	{
		//this->size = other.size;
		//this->str = other.str;	//Shallow copy 
			
		//Reset other:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~string()
	{
		delete[] str;
		cout << "Desctructor:\t" << this << endl;
	}
	//		Opeators:
	string& operator=(const string& other)
	{
		// Deep copy (Побитовое копирование)
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	string& operator=(string&& other)noexcept //r-value reference &&
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;

		//Reset other:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssigment:\t" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}


	//		Methods:
	void print()const
	{
		cout << "Obj:\t\t" << this << endl;
		cout << "Size:\t\t" << size << endl;
		cout << "Addr:\t\t" << &str << endl;
		cout << "Str:\t\t" << str << endl;
		cout << delimiter << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const string& obj)
{
	return os << obj.get_str();
	cout << delimiter;
}
string operator+(const string& left, const string& right)
{
	cout << "Operator '+'" << endl;
	//cout << delimiter;
	string buffer(left.get_size() + right.get_size() - 1);
	//buffer.print();
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer[i] = left[i];
		//buffer.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer[i + left.get_size() - 1] = right[i];
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return buffer;
}

//#define HOME_WORK
//#define COPY_ASSIGMENT
#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef HOME_WORK
	string str1;
	str1.print();

	//string str2 = 8;
	string str2(8);
	str2.print();

	string str3 = "Hello";
	str3 = str3;
	str3.print();

	string str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;
	//string str5 = str3 + str4;
	string str5;
	str5 = str3 + str4;
	cout << str5 << endl;
	cout << delimiter;
#endif // HOME_WORK

#ifdef COPY_ASSIGMENT
	string str1 = "Hello";
	string str2 = "World";
	string str3;

	cout << delimiter << endl;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;

	cout << str1 << " " << str2 << endl;
#endif // COPY_ASSIGMENT

#ifdef CALLING_CONSTRUCTORS
	string str1;			//default constractor
	str1.print();

	//string str2 = 8;		//explicit constructor так вызвать невозможно
	string str2(8);			//explicit constructor можно вызвать только так
	str2.print();
	string str3 = "Hello";	//single-argiment constructor 'char'
	str3.print();

	string str4();			//Здесь НЕ вызывается никаой конструктор, и не созадется объект
							//здесь объявляется функция str4, которая не принимает никаких параметров
							// И возвращает значение типа 'string'
							// т.е., таким образом DefaulConstractor вызвать невозможно 
	//str4.print();
	//Если нужно явно вызвать DefaultConstructor, это делается следубщим образом:
	string str5{};			//Явный вызов конструктора по умолчанию
	str5.print();
	
	//string str6 = str3;		//CopyConstructor
	//string str6 (str3);		//CopyConstructor
	string str6{ str3 };		//CopyConstructor
	str6.print();
	// Следовательно, абсолютно любой конструктор можно вызвать при помощи () или {} 
#endif // CALLING_CONSTRUCTORS


}