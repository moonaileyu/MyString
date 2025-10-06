#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	MyString obj1;
	MyString obj2(25);
	MyString obj3("Hello world!");
	MyString obj4 = obj3;

	cout << "Third string: ";
	obj3.Print();

	cout << "Fourth string: ";
	obj4.Print();

	cout << "\nMyStrcpy\n";
	obj2.MyStrcpy(obj3);
	cout << "Result: ";
	obj2.Print();

	cout << "\nMyStrStr\n";
	cout << (obj3.MyStrStr("world") ? "Found\n" : "Not found\n");

	cout << "\nMyChr\n";
	cout << "Index of 'o': " << obj3.MyChr('o') << endl;

	cout << "\nMyStrLen\n";
	cout << "Length: " << obj3.MyStrLen() << endl;

	cout << "\nMyStrCat\n";
	MyString obj5("!!!");
	obj3.MyStrCat(obj5);
	cout << "Concatenated: ";
	obj3.Print();

	cout << "\nMyDelChr\n";
	obj3.MyDelChr('l');
	cout << "After deletion: ";
	obj3.Print();

	//cout << "\nMyStrCmp\n";
	//MyString a("cat");
	//MyString b("dog");
	//cout << "Compare cat/dog: " << a.MyStrCmp(b) << endl;
	//cout << "Compare dog/cat: " << b.MyStrCmp(a) << endl;
	//cout << "Compare cat/cat: " << a.MyStrCmp(a) << endl;

	//cout << "\nObject counter\n";
	//cout << "Number of objects now: " << MyString::GetCount() << endl;

	//MyString obj6("1");
	//MyString obj7("2");

	//cout << "Number of objects now: " << MyString::GetCount() << endl;

	//cout << "\nOperator Overloading\n";

	//MyString a("Hello");
	//MyString b(" world");

	//MyString c = a + b;
	//c.Print();

	//MyString c1 = a + " world";
	//c1.Print();

	//MyString c2 = a - 'l';
	//c2.Print();

	//MyString d = a - "lo";
	//d.Print();

	MyString a("Hello");
	MyString b("world");

	a++;
	a.Print();

	a--;
	a.Print();

	a += "world";
	a.Print();

	a -= "lo";
	a.Print();

	cout << (a == b ? "Equal\n" : "Not equal\n");
	cout << (a > b ? "a > b\n" : "a <= b\n");

	MyString inputStr;
	cout << "\nEnter a string: ";
	cin >> inputStr;
	cout << "You entered: " << inputStr << endl;

	MyString fromList = { 'H', 'e', 'l', 'l', 'o', '!' };
	cout << "String from initializer_list: " << fromList << endl;

	return 0;
}