#include "stdafx.h"
#include "Searealizer.h"

using namespace std;
int indexNumIn(char arr[]);

void main()
{
	setlocale(LC_ALL, "ru");
	Serealizer serealizer;
	char Char[10];
	bool Bool = true;


	cout << "������� �������� ������� char: ";
	cin.getline(Char, 10);

	cout << "������� �������� bool: ";
	cin >> Bool;
 	

	cout << Char << " " << Bool << endl;

	serealizer.Serialize(Char, Bool);
}