#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

struct StackItem{
	char digit;
	struct StackItem *next;
};

struct StackItem* list = NULL;

struct StackItem* AddList(struct StackItem* list, char digit) {	//Функция добавления цифр в стек
	struct StackItem* item = (struct StackItem*) malloc(sizeof(struct StackItem*));
	item->digit = digit;
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

struct StackItem* OutStack(struct StackItem* list, char *out) {	//Функция извлечения цифр из стека
	struct StackItem* item = list;
	*out = list -> digit;
	list = list -> next;
	free (item);
	return list;
}

struct TreeItem	
{
  struct TreeItem *left;
  struct TreeItem *right;
  int number;
};

struct TreeItem* TreeItemCreate(int number)	//Функция создания дерева
{
	struct TreeItem *item = (struct TreeItem *)malloc(sizeof(struct TreeItem));
	item->left = NULL;
	item->right = NULL;
	item->number = number;
	return item;
}

struct TreeItem* Add(struct TreeItem *current, int number)	//Функция добавления цифр в текущую позицию дерева
{
	struct TreeItem *root;
	if (current!=NULL)
		root = current;

	if(!current)
		return TreeItemCreate(number);
	while(1)
	{
		if (root->number == number)
			return current;
		if (number % 10 == 0) {
			if (root->left == NULL) {
				root->left = TreeItemCreate(number);
			}
			current = root->left;
			return current;
		}
		else
			if (root->right == NULL) {
				root->right = TreeItemCreate(number);
			}
			current = root->right;
			return current;
	}
}

struct TreeItem *root = NULL;
struct TreeItem *current = NULL;

int _tmain(int argc, _TCHAR* argv[])
{
	char *string = (char*) malloc(200*sizeof(char));
	char ch;
	unsigned int i, j = 0, number, digit = 0, m = 0;
	FILE *file;
	file = fopen("D:\\University\\Progs\\Labs\\Programming\\Lab 6\\numbers(for Lab 6).txt", "r");
	fgets(string, 200, file);
	for (i = 0; i <= strlen(string); i++) {
		if (string[i] == 32 || i == (strlen(string) )) {
			char *reverseNumber = (char*) malloc(200*sizeof(char)); //где reverseNumber - это число, записанное задом наперед
			int k = 0;
			for (; j < i; j++) {
				list = OutStack(list, &ch);
				reverseNumber[k] = ch;
				k++;
			}
			j++;
			number = atoi(reverseNumber);
			digit = 0;	//digit - текущее число, помещаемое в дерево
			current = root;
			while (number > 0) {
				digit = digit * 10 + number % 10;
				if (current && m == 1) {
					root = current;
				}
				current = Add(current, digit);
				m++;
				printf("%d\n", digit);
				number/=10;
			}
		}
		else
			list = AddList(list, string[i]);
	}
	puts(string);
	getch();
	fclose(file);
	free (string);
	return 0;
}
