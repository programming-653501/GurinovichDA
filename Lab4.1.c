#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>

int length(char *str);
void reverse(char *word);

int _tmain(int argc, _TCHAR* argv[])
{
	char text[201];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите текст:\n");
	gets(text);
	reverse(text);
	puts(text);
	getch();
	return 0;
}

int length(char *str)
{
	int i=0;
		while (*str!='\0')
		   {str++;
			i++;}
	return i;
}

void reverse(char *word)
{
	int l = length(word);
	int i;
	char letter;
	for (i = 0; i < l/2; i++) {
		letter=word[i];
		word[i]=word[l-1-i];
		word[l-1-i]=letter;
	}
}
