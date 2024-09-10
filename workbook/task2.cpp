﻿#include <iostream>
#include <iomanip>
#include "tasks.h"

void task2() {
	std::cout << "\nЗАДАЧA №2\n";
	std::cout << "Имеется массив из вещественных чисел\n";
	std::cout << "задания:\n";
	std::cout << "- сумма положительных элементов\n";
	std::cout << "- произвидение элементов от min до max по модулю\n";
	std::cout << "- сортировка по убыванию\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 12;
	float a[n] = { -2.2, 3.1, 4.0, 5.1, -6.4, 2.8, 3.1, 12.9, 10.2, -5.2, -2.6, 4.2 };
	float b[n];
	float sum = 0;
	int minI = 0;
	int maxI = 0;
	float min = a[0];
	float max = a[n - 1];
	float pro = 1;
	float temp = 0;




	for (int i = 0; i <= n - 1; i++) {
		if (a[i] >= 0) {
			sum += a[i];        // подсчет суммы положительных элементов
			b[i] = a[i];        // в новый массив b добавляем положительные элементы
		}
		else
			b[i] = -a[i];       // в новый массив b добавляем элементы, преобразуя их в положительные
		if (b[i] < min) {
			minI = i;							//находим индекс минимального элемента
			min = b[i];							//находим минимальный элемент массива
		}
		if (b[i] > max) {
			maxI = i;							//находим индекс максимального элемента
			max = b[i];							//находим максимальный элемент массива
		}
	}
	for (int i = minI + 1; i < maxI; i++)		//цикл в границах между минимальным и максимальным элементами
		pro *= b[i];							//считаем произведение

	std::cout << "- сумма положительных элементов:" << sum << "\n";
	std::cout << "- произведение:" << pro << "\n";




	for (int i = 0; i < n; i++)		//сортировка пузырьком по убыванию
		for (int j = 0; j < n - 1; j++)
			if (a[j] < a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp; 
			}

	std::cout << "- отсортированный по убыванию массив:\n";

	for (int i = 0; i <= n - 1; i++)    //выводим массив
		std::cout << a[i] << " | "; 
	
	std::cout << "\n";
}



