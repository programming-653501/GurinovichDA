#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#define PI 3.14159265

int checkI(char *str);
int checkF(char *str);
double factorial(int a);
double recursion(double x, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1, i, answer, j = 0;
	double sin_left, sin_right, e, x, x1;
	char e1[20], angle[20], answer1[2];
	clock_t time1, time2, time3, time4;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (!j){	//Проверка на правильность ввода угола и погрешности
		printf("Введите угол(в градусах):");
		fflush(stdin);
		gets(angle);
		printf("Введите погрешность e:");
		fflush(stdin);
		gets(e1);
		e=atof(e1);
		j = 1;
			if (!checkF(angle)){
				printf("Введите правильный угол!\n");
				j = 0;}
			if (!checkF(e1)||e < 0){
				printf("Введите правильную погрешность!\n");
				j = 0;}
	}
	x = atof(angle);
	x1 = x;
	if (fabs(x)>=360) {	//Если угол по модулю >= 360, переводим его к уголу диапозона (-360,360)
		x = x - ((int)x/360)*360;
	}
	sin_left = sin(x*PI/180);
	time1=clock();
	do {	//Вычисление разложения функции и поиск числа n
		sin_right = 0.0;
		for (i = 1; i <= n; i++)
				sin_right += powl(-1, i - 1)*powl(x*PI/180, 2 * i - 1) / factorial(2 * i - 1);
		n++;
	}
	while (fabs(fabs(sin_right) - fabs(sin_left))>e);
	time2=clock();
	printf("sin(%lf) по формуле равен %.10f\n", x1, sin_left);
	printf("sin(%lf) по разложению итерационно равен %.10f\n", x1, sin_right);
	printf("При n=%d исследуемое выражение отличается от sin(%lf) менее чем на %.10f\n", n - 1, x, e);
	n = 1;
	time3=clock();
	do {	//Вычисление разложения функции и поиск числа n
		sin_right = 0.0;
		for (i = 1; i <= n; i++)
			sin_right = recursion(x*PI/180,n);
		n++;
	}
	while (fabs(fabs(sin_right) - fabs(sin_left))>e);
	time4=clock();
	printf("sin(%lf) по разложению рекурсионно равен %.10f\n", x1, sin_right);
	printf("При n=%d исследуемое выражение отличается от sin(%lf) менее чем на %.10f\n", n - 1, x, e);
	if ((time4-time3)<(time2-time1))
		printf("Рекурсивный подход эффективнее");
	else
		printf("Итерационный подход эффективнее");
	getch();
	return 0;
}

int checkI(char *str)	//Проверка чисел типа int
{
	int i, result = 0;
	for (i = 0; i < (int) strlen(str); i++) {
		if (isdigit(str[i])) {
			result = 1;
		}
		else {
			result = 0;
			break;}
	}
	return result;
}

int checkF(char *str)	//Проверка чисел типа double
{
	int i, result = 0, n = 0, d = 0;
	for (i = 0; i < (int) strlen(str); i++) {
		if (isdigit(str[i])) {
			result = 1;
		}
		else if (str[i]=='-')
			d++;
		else if (str[i]=='.') {
			n++;
		}
		else {
			result = 0;
			break;}
	}
	if (n >= 2 || d>=2 || (d==1 && str[0]!='-')) {
		result = 0;
	}
	return result;
}

double factorial(int a)	//Рекурсивная функция факториала
{
	if (a <= 1) {
		return 1;
	}
	else return factorial(a - 1)*a;
}

double recursion(double x, int n)	//Рекурсивное вычисление разложения
{
	if (n==0) {
		return 0.0;
	}
	else return recursion(x,n-1)+powl(-1, n - 1)*powl(x, 2 * n - 1) / factorial(2 * n - 1);
}


