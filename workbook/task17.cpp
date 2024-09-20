#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task17() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №17\n";
	std::cout << "Дана целочисленная квадратная матрица 8*8\n";
	std::cout << "задания:\n";
	std::cout << "- найти строки, совпадающие со столбцами\n";
	std::cout << "- сумма элементов из строк, которые содержат хотя бы один отрицательный элемент\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 8;
	int b[n][n];



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < n; j++)
			b[i][j] = rand() % 2 - 1;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}
	int sumElements = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		bool p = false;
		for (int j = 0; j < n; j++) {			//находим сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент.
			sum += b[i][j];
			if (b[i][j] < 0)
				p = true;
		}

		if (p)
			sumElements += sum;
	}
	std::cout << "\n" << sumElements << " - сумма элементов из строк, которые содержат хотя бы один отрицательный элемент\n";

	bool p = false;
	for (int k = 0; k < n; k++) {				// номер строки
		bool p = true;
		for (int i = 0; i < n; i++) {				// номер столбца
			for (int j = 0; j < n; j++)
				if (b[k][j] != b[j][i]) {
					p = false;
					break;
				}
			if (p)
				std::cout << "\n" << k + 1 << " - строкa равна " << i + 1 << "столбцу\n";

		}

		

	}






}

