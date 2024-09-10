#include <iostream>
#include <iomanip>
#include "tasks.h"

void task7() {
	std::cout << "\nЗАДАЧA №7\n";
	std::cout << "Имеется массив из целых чисел\n";
	std::cout << "задания:\n";
	std::cout << "- номер максимального элемента массива\n";
	std::cout << "- произведение элементов, расположенных между первым и вторым нулями\n";
	std::cout << "- преобразовать массив таким образом, чтобы в первой его половине распологались элементы, стоявшие в нечетных позициях, а во второй половине - элементы, стоявшие в четных позициях.\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 9;
	int a[n] = { 0, -2, 3, -1, 6, -2, 0, -4, 9 };
	int pro = 1;
	int max = 0;
	int iMax = 0;
	int firstNull = 0;
	int secondNull = 0;
	int temp = 0;

	for (int i = 0; i <= n - 1; i++)									//находим iMax элемент	
		if (a[i] >= max) {
			max = a[i];
			iMax = i;
		}


	for (int i = 0; i <= n - 1; i++)									//находим индекс первого нулевого элемента 
		if (a[i] == 0){
			firstNull = i;
			break;
		}

	for (int i = firstNull + 1; i <= n - 1; i++)						//находим индекс второго нулевого элемента 
		if (a[i] == 0){
			secondNull = i;
			break;
		}
	
	std::cout << "- индекс максимального элемента:" << iMax << "\n";

	for (int i = firstNull + 1; i < secondNull; i++)					//цикл в границах от первого до второго нулевого элемента
		pro *= a[i];

	std::cout << "- произведение элементов в границах от первого до второго нулевого элемента:" << pro << "\n";

	
	for (int i = 1; i < n/2; i+=2) {			//сортировка пузырьком 
		temp = a[i];
		a[i] = a[n - i];
		a[n - i] = temp;
	}
	

	std::cout << "- сначала нечетные, затем четные элементы:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n";
}



