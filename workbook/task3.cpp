#include <iostream>
#include <iomanip>
#include "tasks.h"

void task3() {
	std::cout << "\nЗАДАЧA №3\n";
	std::cout << "Имеется массив из целых чисел\n";
	std::cout << "задания:\n";
	std::cout << "- произведение элементов с четными номерами\n";
	std::cout << "- сумма элементов, расположенных между первым и последним нулевыми элементами\n";
	std::cout << "- сортировка: сначала все положительные и 0, затем все отрицательные\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	int a[n] = { -2, 5, -7, 0, 1, 0, -3, 0, 2 };
	int sum = 0;
	int firstNull = 0;
	int lastNull = 0;
	int pro = 1;
	int temp = 0;

	for (int i = 1; i <= n - 1; i += 2)									//цикл по четным номерам	
		pro *= a[i];					

	for (int i = 0; i <= n - 1; i++)
		if (a[i] == 0) {
			firstNull = i;											//находим индекс первого нуля
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (a[i] == 0) {
			lastNull = i;											//находим индекс последнего нуля
			break;
		}

	for (int i = firstNull + 1; i < lastNull; i++)				//цикл в границах между первым и последним нулями
		sum += a[i];											
		
	std::cout << "- произведение:" << pro << "\n";
	std::cout << "- сумма:" << sum << "\n";



	for (int i = 0; i < n; i++)											//сортировка пузырьком
		for (int j = 0; j < n - 1; j++)
			if (a[j] < 0 ){
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

	std::cout << "- отсортированный массив сначала все положительные, а потом - все отрицательные:\n";

		for (int i = 0; i <= n - 1; i++)    
			std::cout << a[i] << " | ";

	std::cout << "\n";
}



