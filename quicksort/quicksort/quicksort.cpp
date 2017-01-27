#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int n = 5;
int mas[n];

void quickSort(int *arr, int count);
bool exit();

int main()
{
	setlocale(0, "");
	do
	{
		srand(time(NULL));
		cout << "old array : ";
		for (int i = 0; i < n; ++i)
		{
			mas[i] = rand() % 10;
			cout << mas[i] << ' ';
		}
		cout << endl << endl;

		quickSort(mas, n - 1);

		cout << "new array : ";
		for (int i = 0; i < n; ++i)
			cout << mas[i] << ' ';
		cout << endl << endl;

	} while (!exit());

	return 0;
}

void quickSort(int *arr, int j)
{
	int c = arr[j / 2], b = 0, i = 0, count = j;
	do
	{
		while (arr[i] < c)
			++i;
		while (arr[j] > c)
			--j;
		if (i <= j)
		{
			b = arr[i];
			arr[i] = arr[j];
			arr[j] = b;
			++i;
			--j;
		}
	} while (i <= j);

	if (j > 0)
		quickSort(arr, j);
	if (count > i)
		quickSort(arr + i, count - i);
}

bool exit()
{
	cout << "ƒл€ выхода - клавиша Esc, дл€ продолжени€ - люба€ клавиша\n";
	bool e = _getch() == 27;
	if (!e) system("cls");
	return e;
}