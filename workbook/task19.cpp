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

	const int n = 3, m = 8;
	int b[n][m], countN = 0, countM = 0;

	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < m; j++)
			b[i][j] = rand() % 3 - 1;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}

	
	int x = n;											//для уменьшения строк

	for (int i = 0; i < x - 1; i++) {					//цикл для сортировки строк
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
			countN++;
		}
		
	}

	int y = m;											//для уменьшения столбцов

	for (int i = 0; i < y; i++) {						//цикл для сортировки столбцов
		bool columnIsNull = 1;
		for (int j = 0; j < n; j++) {
			if (b[j][i] != 0) {
				columnIsNull = 0;
				break;
			}

		}

		if (columnIsNull) {
			for (int k = i; k < y; k++)
				for (int l = 0; l < n; l++) {
					int temp = b[l][k+1];
					b[l][k] = b[l][k+1];				//столбцы с нулями на правый край матрицы
					b[l][k+1] = temp;
				}
			y--;
			countM++;
		}

	}
	

	std::cout << "- вывели матрицу:\n\n\n\n";		 //в выводе не показываем нулевые строки снизу и справа

		for (int i = 0; i < n - countN; i++) {
			for (int j = 0; j < m - countM; j++) {
				std::cout.width(10);
				std::cout << b[i][j];
			}
			std::cout << "\n";
		}

		int z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (b[i][j] > 0) {
					z = i + 1;
					break;
				}
			if (z > 0) {
				std::cout << "\n строка с положительным элементом: " << z;
				break;
			}
		}



}

