#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task11() {
	srand(unsigned(time(0)));
	std::cout << "\n�����A �11\n";
	std::cout << "���� ������������� ������������ �������\n";
	std::cout << "�������:\n";
	std::cout << "- ���������� ����� ��� �����\n";
	std::cout << "- ������������ �� �����, ������������� ����� 1 ����\n";
	std::cout << "�������\n";

	const int n = 9, m = 5;
	int b[n][m];
	int i, j, countNull = 0, count, countMax = 0;



	for (i = 0; i < n; i++)									//������� �������
		for (j = 0; j < m; j++)
			b[i][j] = rand() % 101-5; 

	std::cout << "- ������ �������:\n";

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			std::cout.width(10);
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}


	
	for (i = 0; i < n; i++)									//���� �� ����
		for (j = 0; j < m; j++)
			if (b[i][j] == 0) {
				countNull += 1;
				break;
			}

	std::cout << "- ���������� ����� ��� �����:" << n - countNull << "\n";	
	
	count = 0;
	int premax;
	int max = b[0][0];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (max < b[i][j])
				max = b[i][j];

	
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (max == b[i][j])
				count++;

	if (count > 1)
		std::cout << "max " << max << "\n";
	else {
		while (1) {
			count = 0;
			premax = max;
			max = b[0][0];
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					if ((max < b[i][j])&&(b[i][j]<premax))
						max = b[i][j];

			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					if (max == b[i][j])
						count++;

			if (count > 1) {
				std::cout << "- ������������:" << max << "\n";
				break;
			}
		}
	}


	std::cout << "- ������������:" << max << "\n";
	std::cout << "- ���������� �������������:" << count << "\n";
	




}



