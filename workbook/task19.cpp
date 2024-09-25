#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task19() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №19\n";
	std::cout << "- уплотнить заданную матрицу, удалляя из нее строки и столбцы, заполненные нулями\n";
	std::cout << "- найти номер первой из строк, содержащих хотя бы один положительный элемент\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 18, m = 3;
	int b[n][m], countN = 0, countM = 0;

	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < m; j++)
			b[i][j] = rand() % 2 - 1;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}

	int x = n;

	for (int i = 0; i < x-1; i++) {
		bool rowIsNull = 1;
		for (int j = 0; j < m; j++) {
			if (b[i][j] != 0) {
				rowIsNull = 0;
				break;
			}

		}

		if (rowIsNull) {
			for(int k = i; k < x - 1; k++)
				for (int l = 0; l < m; l++) {
					int temp = b[k][l];
					b[k][l] = b[k + 1][l];				//строки с нулями в низ матрицы
					b[k + 1][l] = temp;
				}
			x--;
		}
		
		
		std::cout << countN <<"- countN\n";
	}
	

	std::cout << "- вывели матрицу:\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout.width(10);
				std::cout << b[i][j];
			}
			std::cout << "\n";
		}


	



}

