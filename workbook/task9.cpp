#include <iostream>
#include <iomanip>
#include "tasks.h"

void task9() {
	std::cout << "\nЗАДАЧA №9\n";
	std::cout << "Имеется массив из вещественных чисел\n";
	std::cout << "задания:\n";
	std::cout << "- максимальный по модулю элемент\n";
	std::cout << "- сумма элементов массива, расположенных между первым и вторым положительными элементами\n";
	std::cout << "- преобразовать массив таким образом, чтобы нулевые элементы распологались после всех остальных.\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	float a[n] = { 0.2, -0.1, 0, 1.5, 0, 2.4, 0, -0.7, 9.2 };
	float sum = 0, max = 0, temp = 0;
	int firstPluse = 0, secondPluse = 0, count = 0;


	for (int i = 0; i <= n - 1; i++)									//находим max по модулю элемент	
		if (abs(a[i]) >= max) 
			max = abs(a[i]);
	
	for (int i = 0; i <= n - 1; i++)									//находим индекс первого положительного элемента 
		if (a[i] > 0) {
			firstPluse = i;
			break;
		}

	for (int i = firstPluse + 1; i <= n - 1; i++)						//находим индекс второго положительного элемента 
		if (a[i] > 0) {
			secondPluse = i;
			break;
		}

	std::cout << "- максимальный по модулю элемент:" << max << "\n";

	for (int i = firstPluse + 1; i < secondPluse; i++)					//цикл в границах от первого '+' до второго '+' элемента
		sum += a[i];

	std::cout << "- сумма элементов в границах от первого '+' до второго '+' элемента:" << sum << "\n";


	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			count++;								//цикл по нулям



	for (int i = 0; i < count; i++)											//сортировка пузырьком
		for (int j = 0; j < n - 1; j++)
			if (a[j] == 0) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

	std::cout << "- 'элементы, равные нулю располагаются после всех остальных:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n";
}



