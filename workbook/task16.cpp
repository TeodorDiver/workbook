#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task16() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №16\n";
	std::cout << "Дана целочисленная квадратная матрица\n";
	std::cout << "задания:\n";
	std::cout << "- сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент\n";
	std::cout << "- номера строк и столбцов всех седловых точек матрицы\n";
	std::cout << "РЕШЕНИЕ\n"; 

	const int n = 2;
	int b[n][n];



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < n; j++)
			b[i][j] = rand() % 10 - 0;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		bool p = false;
		for (int j = 0; j < n; j++) {			//находим сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент.
			sum += b[i][j];
			if (b[i][j] < 0)
				p = true;
			}
		
		if (p)
			std::cout << "\n" << i + 1 << " - данная строка содержит хотя бы один отрицательный элемент, сумма его элементов равна: " << sum << "\n";
		else
			std::cout << "\n" << i + 1 << " - данная строка не содержит ни одного отрицательного элемента\n";
	}


	for (int i = 0; i < n; i++) {
		int max = INT_MIN;
		int min = INT_MAX;
		int column;
		for (int j = 0; j < n; j++) {
			if (b[i][j] < min)
				min = b[i][j];
			if (b[j][i] > max) {
				max = b[j][i];
				column = j;
			}

		}
		if(max == min)
			std::cout << "\n" << i  << " - строка " << column << " - столбец у седловой точки матрицы \n";

	}


	



}

