#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h>

int checkI(char *str);

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n, k, l, i, j, y, p, x1 = 0, y1 = 0;
	char m1[3], n1[3], k1[3], l1[3];
	int **array;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (!x1){
		printf("!ВНИМАНИЕ Если вы введете число с количеством знаков больше 2, то за введенное число будет принято две первых цифры\nВведите размер матрицы(m*n):");
		fflush(stdin);
		fgets(m1, 3, stdin);
		fflush(stdin);
		fgets(n1, 3, stdin);
			if (!checkI(m1)||!checkI(n1))
				printf("\nВведите правильный размер!\n");
			else x1 = 1;
	}
	while (!y1){
		printf("\nВведите номер элемента(k*l):");
		fflush(stdin);
		fgets(k1, 3, stdin);
		fflush(stdin);
		fgets(l1, 3, stdin);
			if (!checkI(k1)||!checkI(l1))
				printf("\nВведите правильный номер!\n");
			else y1 = 1;
	}
	m = atoi(m1);
	n = atoi(n1);
	k = atoi(k1);
	l = atoi(l1);
	array = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
		array[i] = (int*)malloc(n * sizeof(int));
	k = k - 1;
	l = l - 1;
	if (k < m && l < n)
		array[k][l] = 1;
	for (j = 1; l + j < n || k + j < m || l - j >= 0 || k - j >= 0; j++) {
		y = k - j;
		while (y <= k + j && y < m) {
			if (y >= 0) {
				if (l + j < n)
					array[y][l + j] = j + 1;
				if (l - j >= 0 && l - j < n)
					array[y][l - j] = j + 1;
			}
			y++;
		}
		p = l - j;
		while (p <= l + j && p < n) {
			if (p >= 0) {
				if (k + j < m)
					array[k + j][p] = j + 1;
				if (k - j >= 0 && k - j < m)
					array[k - j][p] = j + 1;
			}
			p++;
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t", array[i][j]);
		printf("\n");
	}
	for (i = 0; i < m; i++)
		free(array[i]);
	free(array);
	_getch();
	return 0;
}

int checkI(char *str)		//Проверка целых чисел
{
	int i, result = 0;
	for (i = 0; i < (int) strlen(str); i++) {
		if (isdigit(str[i])||str[i]=='\n') {
			result = 1;
		}
		else {
			result = 0;
			break;}
	}
	return result;
}
