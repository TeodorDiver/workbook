#include <iostream>
#include <iomanip>
#include "task6.h"

void task6() {
	std::cout << "\nЗАДАЧA №6\n";
	std::cout << "Имеется массив из вещественных чисел\n";
	std::cout << "задания:\n";
	std::cout << "- минимальный элемент массива\n";
	std::cout << "- сумма элементов, расположенных между первым и последним положительным элементами\n";
	std::cout << "- преобразовать массив таким образом, чтобы сначала располагались элементы равные нулю, а потом все остальные.\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	float a[n] = { 1.1, -2.4, 3.5, 0, -0.6, 1.2, 0, -4.3, -0.9 };
	float sum = 0;
	float min = 0;
	int lastPositiveI = 0;
	int firstPositiveI = 0;
	float temp = 0;
	int count = 0;

	for (int i = 0; i <= n - 1; i++)									//находим min элемент	
		if (a[i] <= min)
			min = a[i];
	
	for (int i = 0; i <= n -1; i++)									//находим индекс первого положительного элемента 
		if (a[i] > 0) {
			firstPositiveI = i;
			break;
		}

	for (int i = n - 1; i >= 0; i--)									//находим индекс последнего положительного элемента (он же первый с конца)
		if (a[i] > 0) {
			lastPositiveI = i;
			break;
		}

	for (int i = firstPositiveI + 1; i < lastPositiveI; i++)				//цикл в границах от первого до последнего положительно элемента
		sum += a[i];

	std::cout << "- минимальный элемент:" << min << "\n";
	std::cout << "- сумма между первым и последним положительными элементами:" << sum << "\n";


	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			count++;								//цикл по нулям



	for (int i = 0; i < count; i++)
		for (int j = n; j >= 1; j--)
			if (a[j] == 0) {							//сортировка пузырьком в обратную сторону
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}

	std::cout << "- сначала нули затем остальные элементы:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n"; 
}



