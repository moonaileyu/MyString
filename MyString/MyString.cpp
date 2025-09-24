#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length] {};
	count++;
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
	count++;
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	count++;
}

MyString::MyString(const MyString& obj1)
{
	length = obj1.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj1.str);
	count++;
}

MyString::~MyString()
{
	delete[] str;
	length = 0;
	count--;
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

int MyString::GetCount()
{
	return count;
}

MyString MyString::operator+(const MyString& b)
{
	MyString result(length + b.length + 1);
	strcpy_s(result.str, length + 1, str);
	strcat_s(result.str, length + b.length + 1, b.str);

	return result;
}

MyString MyString::operator+(const char* b)
{
	MyString result(length + strlen(b) + 1);
	strcpy_s(result.str, length + 1, str);
	strcat_s(result.str, length + strlen(b) + 1, b);

	return result;
}

MyString MyString::operator-(char c)
{
	int newLen = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] != c)
		{
			newLen++;
		}
	}

	MyString result(newLen + 1);

	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != c)
		{
			result.str[j++] = str[i];
		}
	}

	result.str[j] = '\0';

	return result;
}

MyString MyString::operator-(const char* s)
{
	const char* pos = strstr(str, s);

	if (!pos)
	{
		return *this;
	}

	int subLen = strlen(s);
	int newLen = length - subLen;

	MyString result(newLen + 1);

	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (&str[i] == pos)
		{
			i += subLen;
		}
		else
		{
			result.str[j++] = str[i++];
		}
	}

	result.str[j] = '\0';

	return result;
}

int MyString::count = 0;