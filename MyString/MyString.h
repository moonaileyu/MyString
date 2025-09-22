#pragma once
class MyString
{
private:
	char* str;
	int length;

public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	MyString(const MyString& obj1);
	~MyString();

	void Print();

	void MyStrcpy(MyString& obj1);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
};