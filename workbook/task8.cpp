#include <iostream>
#include <iomanip>
#include "tasks.h"

void task8() {
	std::cout << "\n�����A �7\n";
	std::cout << "������� ������ �� ������������ �����\n";
	std::cout << "�������:\n";
	std::cout << "- ����� ������������ �������� �������\n";
	std::cout << "- ����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������\n";
	std::cout << "- ������������� ������ ����� �������, ����� ������� ������������� ��������, ������ ������� �� ��������� 1, � ����� ��� ��������� ��������.\n";
	std::cout << "�������\n";

	const int n = 9;
	float a[n] = { 0, -0.1, 3.3, 1.5, 6.8, -2.4, 0, -0.7, 9.2 };
	float sum = 0, min = 0, temp = 0;
	int iMin = 0, firstNegative = 0, secondNegative = 0, count = 0;
	

	for (int i = 0; i <= n - 1; i++)									//������� iMin �������	
		if (a[i] <= min) {
			min = a[i];
			iMin = i;
		}

	for (int i = 0; i <= n - 1; i++)									//������� ������ ������� �������������� �������� 
		if (a[i] < 0) {
			firstNegative = i;
			break;
		}

	for (int i = firstNegative + 1; i <= n - 1; i++)						//������� ������ ������� �������������� �������� 
		if (a[i] < 0) {
			secondNegative = i;
			break;
		}

	std::cout << "- ������ ������������� ��������:" << iMin << "\n";

	for (int i = firstNegative + 1; i < secondNegative; i++)					//���� � �������� �� ������� '-' �� ������� '-' ��������
		sum += a[i];

	std::cout << "- ����� ��������� � �������� �� ������� '-' �� ������� '-' ��������:" << sum << "\n";


	for (int i = 0; i < n; i++)
		if (abs(a[i]) <= 1)
			count++;								//���� �� ������ ������ 1



	for (int i = 0; i < count; i++)
		for (int j = n; j >= 1; j--)
			if (abs(a[j]) <= 1) {							//���������� ��������� � �������� �������
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}


	std::cout << "- ������� ������ ��� ���� �� ��������� 1, ����� ��� ���������:\n";

	for (int i = 0; i <= n - 1; i++)
		std::cout << a[i] << " | ";

	std::cout << "\n";
}



