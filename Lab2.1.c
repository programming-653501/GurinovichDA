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
	printf("���� ����������\n");
	while (!y)
	{
		while (!x1) {
			printf("�������� ���, �� ������ �������: 1-������ ����� � ����������� ������, 2-����� ����� � ������, 3-������� ������ �����, 4-������� �� �������� ��� ������ ������, 5-������� ���������� � �����, 6-�����, 7-�������� �������\n!��������! ���� �� ������� ����� � ����������� �������� ������ 1, �� ��������� ����� ����� ������� ������ �����\n");
			fflush(stdin);
			fgets(num, 2, stdin);
			if (!checkI(num))
				printf("\n������� ���������� �����!\n");
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
				printf("������� ������� ����� � ����������� ������\n");
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
			printf("�������� ���������� �����!\n");
			break;
		}
	}
    return 0;
}

int checkF(char *str) 	//�������� ������������ �����
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

int checkI(char *str)		//�������� ����� �����
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
		printf("������� ����� � ����������� ������:");
        fflush(stdin);
		gets(bel);
		if (!checkF(bel))
			printf("\n������� ���������� �����!\n");
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
	printf(" ������� �� �������� \n");
	printf("USD \t\t EUR \t\t RUB\n");
	printf("%f \t %f \t %f\n", USD_rez, EUR_rez, RUB_rez);
	printf("�������� �������� ������:");
	if (USD_rez > EUR_rez && USD_rez > RUB_rez)
		printf("USD\n");
	else if (EUR_rez > USD_rez && EUR_rez > RUB_rez)
		printf("EUR\n");
	else printf("RUB\n");
}

void info()
{
	printf("��������� � ������� ������������ ���� ��������\n");
	printf("� 2014 ���� ��������� ��� �������� ������� ������ �������������� ���� � �������� �������� �������� ����� ������� ������ ������ ����������.\n");
	printf("��������� �������� 4-� ����� � �������� �� ���������� ����������� ���������� ��������� ��������.\n");
	printf("�������-�����:\n");
	printf("�������� � �� �������� �����: +375 17 289 90 90\n");
	printf("���������� �������� �������������: +375 17 289 92 92\n");
	printf("��������� velcom, life:), MTC: 487\n");
}

void exitF(int *y)
{
	*y = 1;
}

