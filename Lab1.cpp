
// ConsoleApplication1.cpp: определ€ет точку входа дл€ консольного приложени€.
//
#include "stdafx.h"
#include <conio.h>


int main()
{
	int k, i = 0, j = 0, number1 = 100, number2 = 100;
	do {	//¬вод числа k, пока оно не будет выходить за границу последовательности
		printf("Enter k:");
		scanf_s("%d", &k);
	} 
	while (k > 900 || k < 0);
	printf("Your sequence:"); //¬ывод последовательности чисел до k-го числа 
	while (i < k) {
		printf("%d", number1);
		number1++;
		i++;
	}
	while (j < k-1) {	//¬ычисление k-го числа
		j++;
		number2++;
	} 
	printf("\nThe number of the %dth order is %d", k, number2);	//¬ывод k-го числа
	_getch();
	return 0;
}

