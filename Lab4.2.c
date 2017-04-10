#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>

int check(char ch1, char *text);
int length(char *str);

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *f;
	char *text = (char*)malloc(sizeof(char)*200);
	int q = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	f = fopen("D:\\University\\Progs\\Labs\\Programming\\Lab 4\\4.2\\text.txt","r");
	if (f == NULL) {
		printf("Невозможно открыть файл!\n");
		getch();
		return 0;
	}
	while (!feof(f)) {
		fgets(text,200,f);
		printf("%s", text);
		if (check(')', text)) {
			printf("\nНеправильно расставлены () %d раз(a)",check(')', text));
			q = 0;
		}
		else
			q = 1;
		if (check('}', text)) {
			printf("\nНеправильно расставлены {} %d раз(a)",check('}', text));
			q = 0;
		}
		else
			q = 1;
		if (check(']', text)) {
			printf("\nНеправильно расставлены [] %d раз(a)",check(']', text));
			q = 0;
		}
		else
			q = 1;
		if (q==1) {
			printf("\nВсе скобки расставлены правильно\n");
		}
	}
	fclose(f);
	getch();
	return 0;
}

int check_right(char ch1, char *text)
{
	int i, len = length(text), count = 0, q, k = -1;
	char ch;
	switch (ch1) {
	case ')':
		ch = '(';
		break;
	case '}':
		ch = '{';
		break;
	case ']':
		ch = '[';
		break;
	}
	for (i = 0; i < len; i++) {
		if (text[i] == ch1) {
			int j = i - 1;
			while (j >= 0){
				if (j == k) {
					q = 0;
					break;
				}
				else if (text[j] == ch) {
					k = j;
					q = 1;
					break;
				}
				q = 0;
				j--;
			}
			if (q == 0) {
				count++;
			}
		}
	}
	return count;
}

int check_left(char ch1, char *text)
{
	int i, len = length(text), count = 0, q, k = -1;
	char ch;
	switch (ch1) {
	case '(':
		ch = ')';
		break;
	case '{':
		ch = '}';
		break;
	case '[':
		ch = ']';
		break;
	}
	for (i = 0; i < len; i++) {
		if (text[i] == ch1) {
			int j = i + 1;
			while (j < len){
				if (j == k) {
					q = 0;
					break;
				}
				else if (text[j] == ch) {
					k = j;
					q = 1;
					break;
				}
				q = 0;
				j++;
			}
			if (q == 0) {
				count++;
			}
		}
	}
	return count;
}

int check(char ch1, char *text){
	char ch;
	switch (ch1) {
		case ')':
			ch = '(';
			break;
		case '}':
			ch = '{';
			break;
		case ']':
			ch = '[';
			break;
	}
	return check_left(ch, text) + check_right(ch1, text);
}

int length(char *str)
{
	int i=0;
		while (*str!='\0')
		   {str++;
			i++;}
	return i;
}

