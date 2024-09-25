#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task18() {
	srand(unsigned(time(0)));
	std::cout << "\nЗАДАЧA №18\n";
	std::cout << "Дана целочисленная квадратная матрица 10*10\n";
	std::cout << "задания:\n";
	std::cout << "- подсчитать кол-во локальных минимумов (элемент строго меньше соседних элементов)\n";
	std::cout << "- сумма модулей элементов выше главной диагонали\n";
	std::cout << "РЕШЕНИЕ\n";

	const int n = 10;
	int b[n][n];
	int count = 0;
	int sum = 0;



	for (int i = 0; i < n; i++)									//создали матрицу
		for (int j = 0; j < n; j++)
			b[i][j] = rand() % 100 - 1;

	std::cout << "- вывели матрицу:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}
	
	for(int i = 0; i < n; i++){
		if (i == 0)
			if (b[0][0] < b[0][1] && b[0][0] < b[1][1] && b[0][0] < b[1][0])	// для верхнего левого угла
				count++;
		if (i == n - 1) {
			if (b[0][i] < b[0][i - 1] && b[0][i] < b[1][i - 1] && b[0][i] < b[1][i]) // для верхнего правого
				count++;
			if (b[i][0] < b[i - 1][0] && b[i][0] < b[i - 1][1] && b[i][0] < b[i][1]) // для нижнего левого
				count++;
			if (b[i][i] < b[i - 1][i] && b[i][i] < b[i - 1][i-1] && b[i][i] < b[i][i-1]) // для нижнего правого
				count++;
		}
		for (int j = 1; j < n - 1; j++) {
			if (i == 0) {
				if (b[i][j] < b[i][j + 1] && b[i][j] < b[i + 1][j + 1] && b[i][j] < b[i + 1][j] && b[i][j] < b[i + 1][j - 1] && b[i][j] < b[i][j - 1])	//верх
					count++;
				if (b[j][i] < b[j - 1][i] && b[j][i] < b[j - 1][i + 1] && b[j][i] < b[j][i + 1] && b[j][i] < b[j + 1][i + 1] && b[j][i] < b[j + 1][i])	//левая стенка
					count++;
			}
			else if (i == n - 1) {
				if (b[i][j] < b[i][j - 1] && b[i][j] < b[i - 1][j - 1] && b[i][j] < b[i - 1][j] && b[i][j] < b[i - 1][j + 1] && b[i][j] < b[i][j + 1])	//низ
					count++;
				if (b[j][i] < b[j - 1][i] && b[j][i] < b[j - 1][i - 1] && b[j][i] < b[j][i - 1] && b[j][i] < b[j + 1][i - 1] && b[j][i] < b[j + 1][i])	//правая стенка
					count++;
			}
			else {
				if (b[i][j] < b[i - 1][j] && b[i][j] < b[i - 1][j + 1] && b[i][j] < b[i][j + 1] && b[i][j] < b[i + 1][j + 1] && b[i][j] < b[i + 1][j] && b[i][j] < b[i + 1][j - 1] && b[i][j] < b[i][j - 1] && b[i][j] < b[i - 1][j - 1])
					count++;	//для всей остальной матрицы
			}
		}

	}
	std::cout << count << "- кол-во локальных минимумов \n";


	
	int x = n - 1;										// 'n' константа, поэтому ввел 'x', т.к. есть необходимость уменьшать 'x' с каждой итерацией

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < x; j++)
			sum += abs(b[j][j + 1 + i]);				// над главной диагональю
		x--;											// здесь происходит уменьшение шагов вложенного цикла (по строке матрицы) 
	}											
	


	std::cout << sum << " - сумма модулей элементов выше главной диагонали\n";



}

