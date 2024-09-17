#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task13() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №12\n";
	std::cout << "Дана целочисленная прямоуголная матрица\n";
	std::cout << "задания:\n";
	std::cout << "- количество столбцов с хотя бы 1 нулем\n";
	std::cout << "- номер строки, в которой находится самая длинная серия одинаковых элементов\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 4, m = 8;
	int b[n][m];
	int countNull = 0;
	int a[n];
	int max = 0;



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < m; j++)
			b[i][j] = rand() % 21 - 0;

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

	std::cout << "- количество столбцов с хотя бы 1 нулем:" << countNull << "\n";


	for (int i = 0; i < n; i++) {
		int maxS = 1;
		for (int j = 0; j < m - 1; j++)			//находим серию одинаковых элементов, по условию в каждой строке только одна серия.
			if (b[i][j] == b[i][j + 1]) {
				maxS++;
				if (b[i][j + 1] != b[i][j + 2])
					break;
			}
		a[i] = maxS;
	}

	for (int i = 0; i <= n - 1; i++)			//вывели массив, где каждый элемент массива - количество элементов в серии повторяющихся элементов матрицы
		std::cout << a[i] << " | ";
	
	for (int i = 1; i <= n; i++) 
		if (a[i] > max) 
			max = i;							//находим индекс максимального элемента массива - он же номер строки в матрице.


		
	std::cout << "\n" << "- строка, содержащая максимальюную серию из одинаковых элементов : " << max << "\n";






}



