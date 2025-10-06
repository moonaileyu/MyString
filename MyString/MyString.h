#pragma once
#include <initializer_list> 

class MyString
{
private:
	char* str;
	int length;
	static int count;

public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	MyString(const MyString& obj1);
	MyString(std::initializer_list<char> list);
	~MyString();

	void Print();

	void MyStrcpy(MyString& obj1);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	static int GetCount();

	MyString operator+(const MyString& b);
	MyString operator+(const char* b);
	MyString operator-(char c);
	MyString operator-(const char* s);

	MyString operator++(int);
	MyString operator--(int);

	MyString& operator+=(const char* s);
	MyString& operator-=(const char* s);

	bool operator==(const MyString& obj) const;
	bool operator>(const MyString& obj) const;
	bool operator<(const MyString & obj) const;

	friend istream& operator>>(istream& in, MyString& obj);
	friend ostream& operator<<(ostream& out, const MyString& obj);
};