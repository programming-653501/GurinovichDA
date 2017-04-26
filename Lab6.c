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

struct StackItem* AddList(struct StackItem* list, char digit) {
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

struct StackItem* OutStack(struct StackItem* list, char *out) {
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

struct TreeItem* TreeItemCreate(int number)
{
	struct TreeItem *item = (struct TreeItem *)malloc(sizeof(struct TreeItem));
	item->left = NULL;
	item->right = NULL;
	item->number = number;
	return item;
}

struct TreeItem* Add(struct TreeItem *current, int number)
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
	char *str = (char*) malloc(200*sizeof(char));
	char ch;
	unsigned int i, j = 0, number, n = 0, m = 0;
	FILE *f;
	f = fopen("D:\\University\\Progs\\Labs\\Programming\\Lab 6\\numbers.txt", "r");
	fgets(str, 200, f);
	for (i = 0; i <= strlen(str); i++) {
		if (str[i] == 32 || i == (strlen(str) )) {
			char *str1 = (char*) malloc(200*sizeof(char));
			int k = 0;
			for (; j < i; j++) {
				list = OutStack(list, &ch);
				str1[k] = ch;
				k++;
			}
			j++;
			number = atoi(str1);
			n = 0;
			current = root;
			while (number > 0) {
				n = n * 10 + number % 10;
				if (current && m == 1) {
					root = current;
				}
				current = Add(current, n);
				m++;
				printf("%d\n", n);
				number/=10;
			}
		}
		else
			list = AddList(list, str[i]);
	}
	puts(str);
	getch();
	fclose(f);
	free (str);
	return 0;
}
