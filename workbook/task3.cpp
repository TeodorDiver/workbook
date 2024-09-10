#include <iostream>
#include <iomanip>
#include "tasks.h"

void task3() {
	std::cout << "\n�����A �3\n";
	std::cout << "������� ������ �� ����� �����\n";
	std::cout << "�������:\n";
	std::cout << "- ������������ ��������� � ������� ��������\n";
	std::cout << "- ����� ���������, ������������� ����� ������ � ��������� �������� ����������\n";
	std::cout << "- ����������: ������� ��� ������������� � 0, ����� ��� �������������\n";
	std::cout << "�������\n";

	const int n = 9;
	int a[n] = { -2, 5, -7, 0, 1, 0, -3, 0, 2 };
	int sum = 0;
	int firstNull = 0;
	int lastNull = 0;
	int pro = 1;
	int temp = 0;

	for (int i = 1; i <= n - 1; i += 2)									//���� �� ������ �������	
		pro *= a[i];					

	for (int i = 0; i <= n - 1; i++)
		if (a[i] == 0) {
			firstNull = i;											//������� ������ ������� ����
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (a[i] == 0) {
			lastNull = i;											//������� ������ ���������� ����
			break;
		}

	for (int i = firstNull + 1; i < lastNull; i++)				//���� � �������� ����� ������ � ��������� ������
		sum += a[i];											
		
	std::cout << "- ������������:" << pro << "\n";
	std::cout << "- �����:" << sum << "\n";



	for (int i = 0; i < n; i++)											//���������� ���������
		for (int j = 0; j < n - 1; j++)
			if (a[j] < 0 ){
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

	std::cout << "- ��������������� ������ ������� ��� �������������, � ����� - ��� �������������:\n";

		for (int i = 0; i <= n - 1; i++)    
			std::cout << a[i] << " | ";

	std::cout << "\n";
}



