
// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <conio.h>


int main()
{
	int k, i = 0, j = 0, number1 = 100, number2 = 100;
	do {	//���� ����� k, ���� ��� �� ����� �������� �� ������� ������������������
		printf("Enter k:");
		scanf_s("%d", &k);
	} 
	while (k > 900 || k < 0);
	printf("Your sequence:"); //����� ������������������ ����� �� k-�� ����� 
	while (i < k) {
		printf("%d", number1);
		number1++;
		i++;
	}
	while (j < k-1) {	//���������� k-�� �����
		j++;
		number2++;
	} 
	printf("\nThe number of the %dth order is %d", k, number2);	//����� k-�� �����
	_getch();
	return 0;
}

