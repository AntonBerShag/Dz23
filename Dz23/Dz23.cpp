#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void show(int arr[], int length);
void threeMax(int &a, int &b, int &c);
int minNum(int arr[], int length);
void nullEle(int arr1[], int length1, int arr2[], int length2);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//Задача 1
	cout << "Задача 1\nВведите три переменные: ";
	int a, b, c;
	cin >> a >> b >> c;
	threeMax(a, b, c);
	cout << a << " " << b << " " << c << "\n\n";

	//Задача 2
	cout << "Задача 2\n";
	int arr[10];
	cout << "Исходный массив:\n[";
	for (int i = 0; i < 10; i++) {
		*(arr + i) = rand() % (10 - (-10) + 1) - 10;
		cout << *(arr + i) << ", ";
	}
	cout << "\b\b]\n";
	cout << "Минимальное число = " << minNum(arr, 10) << "\n\n";

	//Задача 3
	cout << "Задача 3\n";
	int arr1[7] = { 3, 6, 4, 1, 4, 8, 2};
	int arr2[6] = { 5, 3, 1, 5, 10, 8 };
	cout << "Массив 1\n";
	show(arr1, 7);
	cout << "Массив 2\n";
	show(arr2, 6);
	cout << "Массив 2 после работы функции:\n";
	nullEle(arr2, 6, arr1, 7);

	return 0;
}

//Задача 3
void nullEle(int arr1[], int length1, int arr2[], int length2) {
	cout << "[";
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			if (*(arr1 + i) == *(arr2 + j))
				*(arr1 + i) = 0;
		}
		cout << *(arr1 + i) << ", ";
	}
	cout << "\b\b]\n\n";
}

//Задача 2
int minNum(int arr[], int length) {
	for (int i = 0; i < length; i++)
		if (*(arr + i) < 0)
			return *(arr + i);
	return *(arr + 0);
}

//Задача 1
void threeMax(int &a, int &b, int &c) {
	if (a >= b && a >= c) {
		b = a;
		c = a;
	} 
	else {
		if (b > a && b >= c) {
			a = b;
			c = b;
		}
		else {
			a = c;
			b = c;
		}
	}
}

void show(int arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << *(arr + i) << ", ";
	}
	cout << "\b\b]\n";
}