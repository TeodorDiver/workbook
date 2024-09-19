#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task14() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №14\n";
	std::cout << "Дана целочисленная квадратная матрица\n";
	std::cout << "задания:\n";
	std::cout << "- произведение элементов в тех строках, которые не содержат отрицательных элементов\n";
	std::cout << "- максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы\n";
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
		int pro = 1;
		bool p = true;
		for (int j = 0; j < m; j++)			//находим произведение элементов в тех строках, которые не содержат отрицательных элементов.
			if (b[i][j] >= 0)
				pro *= b[i][j];
			else {
				p = false;
				break;
			}
		if (p)
			std::cout << "\n" << i + 1 << " - данная строка не содержит отрицательных элементов, произведение ее элементов равно: " << pro << "\n";
	}
		
	/*for (int i = 0; i < n; i++)									//сумма главной диагонали, но по условию она нам не нужна
		sum += b[i][i];

	for (int i = 0; i < n - 1; i++)
		sum += b[i + 1][i];	*/

	
	int maxR = INT_MIN;
	int maxL = INT_MIN;
	int sumR;
	int sumL;
	int x = n;										// 'n' константа, поэтому ввел 'x'

	for (int i = 0; i < n; i++) {
		sumR = 0;
		for (int j = 0; j < x - 1; j++)
			sumR += b[j][j + 1 + i];				//	над главной диагональю
		if (sumR >= maxR)
			maxR = sumR;
		x--;
	}

	x = n;											// возвращаем значение х

	for (int i = 0; i < n; i++) {
		sumL = 0;
		for (int j = 0; j < x - 1; j++)
			sumL += b[j + 1 + i][j];				//	под главной диагональю
		if (sumL >= maxL)
			maxL = sumL;
		x--;
	}

	if(maxL >= maxR)
		std::cout << maxL << " - маx\n";
	else
		std::cout << maxR << " - маx\n";
	



}

