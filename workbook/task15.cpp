#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task15() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №15\n";
	std::cout << "Дана целочисленная квадратная матрица\n";
	std::cout << "задания:\n";
	std::cout << "- сумму элементов в тех столбцах, которые не содержат отрицательных элементов\n";
	std::cout << "- минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали матрицы\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 4, m = 4;
	int b[n][m];



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < m; j++)
			b[i][j] = rand() % 15 - 0;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		bool p = true;
		for (int j = 0; j < m; j++)			//находим сумму элементов в тех столбцах, которые не содержат отрицательных элементов.
			if (b[j][i] >= 0)
				sum += b[j][i];
			else {
				p = false;
				break;
			}
		if (p)
			std::cout << "\n" << i + 1 << " - данный столбец не содержит отрицательных элементов, сумма его элементов равна: " << sum << "\n";
	}

	



	
	int min = INT_MAX;
	int sum1;
	int sum2;
	int x = n - 1;											// 'n' константа, поэтому ввел 'x'

	for (int i = 0; i < n - 1; i++) {
		sum1 = 0;										// обнуляем суммы на каждой итерации
		sum2 = 0;
		for (int j = 0; j < x; j++) {
			sum1 += b[j][x - 1 - j];				// над побочной диагональю
			sum2 += b[i + j + 1][x + i - j];		// под побочной диагональю
		}

		if (sum1 <= sum2 && sum1 <= min)				// ищем мin
			min = sum1;
		if (sum2 <= sum1 && sum2 <= min)
			min = sum2; 
		x--;											// здесь происходит уменьшение шагов вложенного цикла (по строке матрицы) 
	}

	std::cout << min << " - min\n";
	


}

