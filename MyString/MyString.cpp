#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length] {};
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
}

MyString::MyString(const MyString& obj1)
{
	length = obj1.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj1.str);
}

MyString::~MyString()
{
	delete[] str;
	length = 0;
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj1)
{
	delete[] str;
	length = obj1.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj1.str);
}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);

	if (s != nullptr)
	{
		return true;
	}
	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void MyString::MyStrCat(MyString& b)
{
	int NewLength = length + b.length;
	char* NewStr = new char[NewLength + 1];

	strcpy_s(NewStr, length + 1, str);
	strcat_s(NewStr, NewLength + 1, b.str);

	delete[] str;
	str = NewStr;
	length = NewLength;
}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			count++;
		}
	}

	int NewSize = length - count;

	char* newstr = new char[NewSize + 1];

	int j = 0;

	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] != c)
		{
			newstr[j] = str[i];
			j++;
		}
	}

	delete[] str;
	str = newstr;
	length = NewSize;
}

int MyString::MyStrCmp(MyString& b)
{
	return strcmp(str, b.str);
}