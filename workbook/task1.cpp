#include <stdio.h>
#include <iostream>
#include <clocale>
#include "task1.h"
using std::cin;
using std::cout;

void task1() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	const int n = 12;
	int a[n] = { -2, 0, 6, 5, -4, 8, 2, 11, 9, -3, -3, 10 };
	int sum = 0;
	int minI = 0;
	int maxI = 0;
	int min = a[0];
	int max = a[n - 1];
	int pro = 1;

	for (int i = 0; i <= n - 1; i++) {
		if (a[i] < 0)
			sum += a[i];						//считаем сумму
		if (a[i] < min) {
			minI = i;							//находим индекс минимального элемента
			min = a[i];							//находим минимальный элемент массива
		}
		if (a[i] > max) {
			maxI = i;							//находим индекс максимального элемента
			max = a[i];							//находим максимальный элемент массива
		}
	}

	for (int i = minI + 1; i < maxI; i++)		//цикл в границах между минимальным и максимальным элементами
		pro *= a[i];							//считаем произведение

	cout << "Cумма:" << "\n";
	cout << sum << "\n";

	cout << "Произведение:" << "\n";
	cout << pro << "\n";


	for (int i = 0, temp = 0; i < n; i++)		//сортировка пузырьком
		for (int j = 0; j < n - 1; j++)
			if (a[j + 1] < a[j]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

	cout << "Отсортированный по возрастанию массив:" << "\n";

	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << " "; 					//выводим массив
}
    


