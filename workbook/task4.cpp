#include <iostream>
#include <iomanip>
#include "task4.h"

void task4() {
	std::cout << "\nЗАДАЧA №4\n";
	std::cout << "Имеется массив из вещественных чисел\n";
	std::cout << "задания:\n";
	std::cout << "- сумма элементов с нечетными номерами\n";
	std::cout << "- сумма элементов, расположенных между первым и последним отрицательными элементами\n";
	std::cout << "- сжать массив, удалив из него все элементы, модуль которых не превышает 1. Освободившиеся в конце массива элементы заполнить 0.\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	float a[n] = { -1.1, 2.4, 3.5, 0.8, -0.6, 1.2, -8.1, 4.3, 0.9 };
	float sum = 0;
	int firstNegative = 0;
	int lastNegative = 0;
	float sumBetween = 0;
	float temp = 0;
	int count = 0;

	for (int i = 0; i <= n - 1; i += 2)									//цикл по нечетным номерам	
		sum += a[i];

	for (int i = 0; i <= n - 1; i++)
		if (a[i] < 0) {
			firstNegative = i;											//находим индекс первого отрицательного элемента
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (a[i] < 0) {
			lastNegative = i;											//находим индекс последнего отрицательного элемента
			break;
		}

	for (int i = firstNegative + 1; i < lastNegative; i++)				//цикл в границах между первым и последним нулями
		sumBetween += a[i];

	std::cout << "- сумма:" << sum << "\n";
	std::cout << "- сумма между отрицательными:" << sumBetween << "\n";


	for (int i = 0; i < n; i++)
		if (a[i] < 1 && a[i] > -1)
			count++;														//считаем количество элементов, модуль которых меньше 1		
		for (int j = 0; j < n - 1; j++)
			if (a[j] < 1 && a[j] > -1) {									//сортировка пузырьком
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

	for (int i = n - 1; i >= n - count; i--)								//цикл с конца с заменой на нули по счетчику
		a[i] = 0;

	std::cout << "- сжатый массив с 0 в конце:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n";
}



