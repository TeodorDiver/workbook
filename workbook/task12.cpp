#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task12() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №12\n";
	std::cout << "Дана целочисленная прямоуголная матрица\n";
	std::cout << "задания:\n";
	std::cout << "- количество столбцов без нулей\n";
	std::cout << "- характеристика строки - сумма положительных четных элементов. Расположить строки по возрастанию характеристик\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 4, m = 8;
	int b[n][m];
	int countNull = 0;



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < m; j++)
			b[i][j] = rand() % 11 - 0;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}

	for (int i = 0; i < m; i++)									//цикл на нули
		for (int j = 0; j < n; j++)
			if (b[j][i] == 0) {
				countNull += 1;
				break;
			}

	std::cout << "- количество столбцов без нулей:" << m - countNull << "\n";

	
	for (int k = 0; k < n - 1; k++)
		for (int i = 0; i < n - 1; i++) {
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 1; j <= m; j += 2) {
				if (b[i][j] > 0)
					sum1 += b[i][j];
				if (b[i + 1][j] > 0)
					sum2 += b[i + 1][j];
			}
			if (sum2 < sum1)
				for (int j = 0; j < m; j++) {
					int temp = b[i][j];					//наполняем массив temp строкой из матрицы
					b[i][j] = b[i + 1][j];
					b[i + 1][j] = temp;
				}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout.width(10);
				std::cout << b[i][j];
			}
			std::cout << "\n";
		}







} 



