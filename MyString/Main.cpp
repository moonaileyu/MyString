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

	cout << "\nMyStrCmp\n";
	MyString a("cat");
	MyString b("dog");
	cout << "Compare cat/dog: " << a.MyStrCmp(b) << endl;
	cout << "Compare dog/cat: " << b.MyStrCmp(a) << endl;
	cout << "Compare cat/cat: " << a.MyStrCmp(a) << endl;

	return 0;
}