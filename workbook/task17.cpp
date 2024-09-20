#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tasks.h"

void task17() {
	srand(unsigned(time(0)));
	std::cout << "\n�����A �17\n";
	std::cout << "���� ������������� ���������� ������� 8*8\n";
	std::cout << "�������:\n";
	std::cout << "- ����� ������, ����������� �� ���������\n";
	std::cout << "- ����� ��������� �� �����, ������� �������� ���� �� ���� ������������� �������\n";
	std::cout << "�������\n";

	const int n = 8;
	int b[n][n];



	for (int i = 0; i < n; i++)									//������� �������
		for (int j = 0; j < n; j++)
			b[i][j] = rand() % 2 - 1;

	std::cout << "- ������ �������:\n";

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
		for (int j = 0; j < n; j++) {			//������� ����� ��������� � ��� �������, ������� �������� ���� �� ���� ������������� �������.
			sum += b[i][j];
			if (b[i][j] < 0)
				p = true;
		}

		if (p)
			sumElements += sum;
	}
	std::cout << "\n" << sumElements << " - ����� ��������� �� �����, ������� �������� ���� �� ���� ������������� �������\n";

	bool p = false;
	for (int k = 0; k < n; k++) {				// ����� ������
		bool p = true;
		for (int i = 0; i < n; i++) {				// ����� �������
			for (int j = 0; j < n; j++)
				if (b[k][j] != b[j][i]) {
					p = false;
					break;
				}
			if (p)
				std::cout << "\n" << k + 1 << " - �����a ����� " << i + 1 << "�������\n";

		}

		

	}






}

