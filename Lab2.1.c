#include <stdio.h>
#include <locale.h>
#include <windows.h>

int checkF(char *str);
int checkI(char *str);
void enter_bel(char *bel);
void money_valute(char *bel, float USD_sale, float EUR_sale, float RUB_sale);
void table(float *USD_sale, float *EUR_sale, float *RUB_sale, float *USD_buy, float *EUR_buy, float *RUB_buy);
void profit(float *USD_sale, float *EUR_sale, float *RUB_sale, float *USD_buy, float *EUR_buy, float *RUB_buy);
void info();
void exitF(int *y);

int main()
{
	float USD_buy = 1.858, USD_sale = 1.883, RUB_buy = 3.140,
	RUB_sale = 3.310, EUR_buy = 1.961, EUR_sale = 1.993;
	char bel[20],num[2];
	int number, y = 0, x1 = 0, answer;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Меню Приорбанка\n");
	while (!y)
	{
		while (!x1) {
			printf("Выберите что, вы хотите сделать: 1-Ввести сумму в белорусских рублях, 2-Вывод суммы в валюте, 3-Таблица курсов валют, 4-Прибыль от операции для каждой валюты, 5-Краткая информация о банке, 6-Выход, 7-Очистить консоль\n!ВНИМАНИЕ! Если вы введете число с количеством символов больше 1, за введенное число будет принята первая цифра\n");
			fflush(stdin);
			fgets(num, 2, stdin);
			if (!checkI(num))
				printf("\nВведите правильную цифру!\n");
			else x1 = 1;
		}
			x1 = 0;
		number = atoi(num);
		switch (number)
		{
		case 1:
			enter_bel(bel);
			break;
		case 2:
			if (atof(bel)==0.0)
				printf("Сначала введите сумму в белорусских рублях\n");
			else
				money_valute(bel, USD_sale, EUR_sale, RUB_sale);
			break;
		case 3:
			table(&USD_sale, &EUR_sale, &RUB_sale, &USD_buy, &EUR_buy, &RUB_buy);
			break;
		case 4:
			profit(&USD_sale, &EUR_sale, &RUB_sale, &USD_buy, &EUR_buy, &RUB_buy);
			break;
		case 5:
			info();
			break;
		case 6:
			exitF(&y);
			break;
		case 7:
			system("cls");
			break;
		default:
			printf("Выберите правильную цифру!\n");
			break;
		}
	}
    return 0;
}

int checkF(char *str) 	//Проверка вещественных чисел
{
	int i, result = 0, n = 0;
	for (i = 0; i < (int) strlen(str); i++) {
		if (isdigit(str[i])) {
			result = 1;
		}
		else if (str[i]=='.') {
			n++;
		}
		else {
			result = 0;
			break;}
	}
	if (n>=2) {
		result = 0;
	}
	return result;
}

int checkI(char *str)		//Проверка целых чисел
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

void enter_bel(char *bel)
{
	int x = 0;
	while (!x) {
		printf("Введите сумму в белорусских рублях:");
        fflush(stdin);
		gets(bel);
		if (!checkF(bel))
			printf("\nВведите правильную сумму!\n");
		else x = 1;
	}
}

void money_valute(char *bel, float USD_sale, float EUR_sale, float RUB_sale)
{
	float bel_money = atof(bel);
	printf("USD \t\t EUR \t\t RUB\n");
	printf("%f \t %f \t %f\n", bel_money/USD_sale, bel_money/EUR_sale, 100*bel_money/RUB_sale);
}

void table(float *USD_sale, float *EUR_sale, float *RUB_sale, float *USD_buy, float *EUR_buy, float *RUB_buy)
{
	printf(" \t USD \t EUR \t RUB\n");
	printf("Buy \t%f %f %f\n", *USD_buy, *EUR_buy, *RUB_buy);
	printf("Sale \t%f %f %f\n", *USD_sale, *EUR_sale, *RUB_sale);
}

void profit(float *USD_sale, float *EUR_sale, float *RUB_sale, float *USD_buy, float *EUR_buy, float *RUB_buy)
{
	float USD_rez = *USD_sale - *USD_buy;
	float EUR_rez = *EUR_sale - *EUR_buy;
	float RUB_rez = *RUB_sale/100 - *RUB_buy/100;
	printf(" Прибыль от операции \n");
	printf("USD \t\t EUR \t\t RUB\n");
	printf("%f \t %f \t %f\n", USD_rez, EUR_rez, RUB_rez);
	printf("Наиболее выгодная сделка:");
	if (USD_rez > EUR_rez && USD_rez > RUB_rez)
		printf("USD\n");
	else if (EUR_rez > USD_rez && EUR_rez > RUB_rez)
		printf("EUR\n");
	else printf("RUB\n");
}

void info()
{
	printf("Приорбанк – ведущий коммерческий банк Беларуси\n");
	printf("В 2014 году Приорбанк был удостоен награды «Самый быстрорастущий банк в сегменте «Средние клиенты» среди сетевых банков группы Райффайзен».\n");
	printf("Приорбанк занимает 4-е место в Беларуси по количеству действующих банковских платежных карточек.\n");
	printf("Контакт-центр:\n");
	printf("Клиентам и не клиентам банка: +375 17 289 90 90\n");
	printf("Держателям карточек круглосуточно: +375 17 289 92 92\n");
	printf("Абонентам velcom, life:), MTC: 487\n");
}

void exitF(int *y)
{
	*y = 1;
}

