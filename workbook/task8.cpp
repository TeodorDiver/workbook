#include <iostream>
#include <iomanip>
#include "tasks.h"

void task8() {
	std::cout << "\nЗАДАЧA №7\n";
	std::cout << "Имеется массив из вещественных чисел\n";
	std::cout << "задания:\n";
	std::cout << "- номер минимального элемента массива\n";
	std::cout << "- сумма элементов массива, расположенных между первым и вторым отрицательными элементами\n";
	std::cout << "- преобразовать массив таким образом, чтобы сначала распологались элементы, модуль которых не превышает 1, а потом все остальные элементы.\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	float a[n] = { 0, -0.1, 3.3, 1.5, 6.8, -2.4, 0, -0.7, 9.2 };
	float sum = 0, min = 0, temp = 0;
	int iMin = 0, firstNegative = 0, secondNegative = 0, count = 0;
	

	for (int i = 0; i <= n - 1; i++)									//находим iMin элемент	
		if (a[i] <= min) {
			min = a[i];
			iMin = i;
		}

	for (int i = 0; i <= n - 1; i++)									//находим индекс первого отрицательного элемента 
		if (a[i] < 0) {
			firstNegative = i;
			break;
		}

	for (int i = firstNegative + 1; i <= n - 1; i++)						//находим индекс второго отрицательного элемента 
		if (a[i] < 0) {
			secondNegative = i;
			break;
		}

	std::cout << "- индекс мминимального элемента:" << iMin << "\n";

	for (int i = firstNegative + 1; i < secondNegative; i++)					//цикл в границах от первого '-' до второго '-' элемента
		sum += a[i];

	std::cout << "- сумма элементов в границах от первого '-' до второго '-' элемента:" << sum << "\n";


	for (int i = 0; i < n; i++)
		if (abs(a[i]) <= 1)
			count++;								//цикл по модулю меньше 1



	for (int i = 0; i < count; i++)
		for (int j = n; j >= 1; j--)
			if (abs(a[j]) <= 1) {							//сортировка пузырьком в обратную сторону
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}


	std::cout << "- сначала модуль кот орых не превышает 1, затем все остальные:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n";
}



