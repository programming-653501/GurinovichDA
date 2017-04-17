#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <malloc.h>

int checkI(char *str);

struct StackItem{
	char s;
	struct StackItem *next;
};

struct StackItem* list = NULL;

struct StackItem* AddList(struct StackItem* list, char s) {
	struct StackItem* item = (struct StackItem*) malloc(sizeof(struct StackItem*));
	item->s = s;
	if (list!=NULL) {
		item->next = list;
		list = item;
	}
	else {
		item->next = NULL;
		list = item;
	}
	return item;
}

struct StackItem* OutStack(struct StackItem* list, char *out) {
	struct StackItem* item = list;
	*out = list -> s;
	list = list -> next;
	free (item);
	return list;
}


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int q = 0, i, answer, j = 0, length, k, symbols, x1;
	while (q == 0) {
		char string[201], string1[101] = "", string2[101]  = "", ch;
		printf("Enter the string:");
		fflush(stdin);
		gets(string);
		length = strlen(string);
		symbols = 0;
		for (i = 0; i < length; i++) {
			if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
				symbols++;
			}
		}
        j = 0;
		for (i = 0; j < symbols/2; i++) {
			if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
				j++;
			}
			list = AddList(list, string[i]);
		}
		j = 0;
		if (symbols % 2 == 0) {
			k = i;
		}
		else
			k = i + 1;
		for (; k < strlen(string); k++) {
			if ((string[k] >= 'a' && string[k] <= 'z') || (string[k] >= 'A' && string[k] <= 'Z')) {
				string2[j] = string[k];
				j++;
			}
		}
		j = 0;
		for (i = 0; j < symbols/2; i++) {
			list = OutStack(list, &ch);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
				string1[j] = ch;
				j++;
			}
		}
		if (strcmp(string1, string2) == 0) {
			printf("This string is a palindrom\n");
		}
		else
			printf("This string is not a palindrom\n");
		x1 = 0;
		while (!x1){
		char m1[3];
			printf("Do you want to repeat?\n1-Yes\n2-No\n");
			fflush(stdin);
			fgets(m1, 3, stdin);
			answer = atoi(m1);
			if (!checkI(m1)||(answer < 1 || answer > 2))
				printf("\nEnter the right number!\n");
			else {
				x1 = 1;
			}
		}
		if (answer == 1) {
			list = NULL;
		}
		else if (answer == 2) {
			q = 1;
		}
	}
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
