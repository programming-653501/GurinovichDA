#include <stdio.h>
#include <tchar.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int k, i,j = 0, number1 = 100, number2 = 100, t = 0, i1;
	char str[5];
	while (!t) {	//Проверка, выходит ли за границу последовательности и является ли введенное число k числом
	printf("Enter k:");
	gets(str);
	printf("%s\n", str);
	k = atoi(str);
	if (strlen(str)>=5) {
		k = 0;
	}
	else
		for (i1 = 0; i1 < strlen(str); i1++) {
			if (!isdigit(str[i1])) {
				k = 0;
				break;
			}
		}
		if (k > 2700 || k <= 0) {
		   printf("Enter right number\n");
		}
		else t = 1;
	}
 	if (k % 3 == 0){	//Выводим последовательность до числа, в котором находится k-я цифра
		for (i = 0; i < k / 3; i++) {
			printf("%d",number1);
			number1++;
		}
	}
	else
		for (i = 0; i < k / 3 + 1; i++) {
			printf("%d",number1);
			number1++;
		}
	if (k % 3 == 0) {	//Находим число, в котором находится k-я цифра
		while (j < k / 3 - 1)
		{
			number2++;
			j++;
		}
	}
	else
		while (j < k / 3)
		{
			number2++;
			j++;
		}
	printf("\nNumber with %dth digit is %d",k,number2);
	switch (k % 3) {	//Вычисляем значение kой цифры
		case 0:
			printf("\n%d", number2 % 10);
			break;
        	case 1:
			printf("\n%d", (number2 / 100) % 10);
			break;
		case 2:
			printf("\n%d", (number2 / 10) % 10);
			break;
	}
	getch();
	return 0;
}
