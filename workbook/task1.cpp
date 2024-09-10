#include <iostream>
#include "tasks.h"

using std::cin;
using std::cout;

void task1() {
	std::cout << "ЗАДАЧA №1\n";
	std::cout << "Имеется массив из целых чисел\n";
	std::cout << "задания:\n";
	std::cout << "- сумма отрицательных элементов\n";
	std::cout << "- произвидение элементов, расположенных от min до max\n";
	std::cout << "- сортировка по возрастанию\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 12;
	int a[n] = { -2, 0, 6, 5, -4, 8, 2, 11, 9, -3, -3, 10 };
	int sum = 0;
	int iMin = 0;
	int iMax = 0;
	int min = a[0];
	int max = a[n - 1];
	int pro = 1;

	for (int i = 0; i <= n - 1; i++) {
		if (a[i] < 0)
			sum += a[i];						//считаем сумму
		if (a[i] < min) {
			iMin = i;							//находим индекс минимального элемента
			min = a[i];							//находим минимальный элемент массива
		}
		if (a[i] > max) {
			iMax = i;							//находим индекс максимального элемента
			max = a[i];							//находим максимальный элемент массива
		}
	}

	for (int i = iMin + 1; i < iMax; i++)		//цикл в границах между минимальным и максимальным элементами
		pro *= a[i];							//считаем произведение

	cout << "Cумма:" << "\n";
	cout << sum << "\n";

	cout << "Произведение:" << "\n";
	cout << pro << "\n";


	for (int i = 0, temp = 0; i < n; i++)		//сортировка пузырьком по возрастанию
		for (int j = 0; j < n - 1; j++)
			if (a[j + 1] < a[j]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

	cout << "Отсортированный по возрастанию массив:" << "\n";

	for (int i = 0; i <= n - 1; i++)
		cout << a[i] << " "; 					//выводим массив
	cout << "\n";
}
    


