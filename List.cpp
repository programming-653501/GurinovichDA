//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void ShellSort(double *array,int size)
{   int i, j;
	double balance;
	int step;
	int flag;
	for (step = size/2; step > 0; step/=2)
		do
		{flag = 0;
			for (i = 0, j = step;j < size; i++,j++)
				if (array[i] > array[j]) {
					balance = array[j];
					array[j] = array[i];
					array[i] = balance;
					flag = 1;
				}
		 }while(flag);
}

List::~List(){
	Head = NULL;
	while (First!=NULL){
		ListItem *temp;
		temp = First->next;
		delete First;
		First = temp;
	}

}

void List::Add(char *Name, char *personalAccount, char *passportNumber, char *depositType, double currentBalance, char *date){
	ListItem* item = new ListItem;
	strcpy(item->name, Name);
	strcpy(item->PersonalAccount, personalAccount);
	strcpy(item->PassportNumber, passportNumber);
	strcpy(item->DepositType, depositType);
	item->CurrentBalance = currentBalance;
	strcpy(item->Date, date);
	if (Head){
		Head->next = item;
		item->prev = Head;
		item->next = NULL;
		Head = item;
	}
	else{
		item->next=NULL;
		item->prev=NULL;
		Head = item;
		First = item;
	}
}

void List::Show(){
	ListItem *item;
	item = First;
	while (item!=NULL){
		printf("%s\t%s\t%s\t%s\t%f\n", item->name, item->PersonalAccount, item->PassportNumber, item->DepositType, item->CurrentBalance);
		item = item->next;
	}
}


char* List::Deleting(char *deletingName, int &count){
	ListItem *item;
	item = First;
	char *PersonalAccount = new char [21];
	bool check = 0;
	while (item!=NULL){
		if (strcmp(item->name,deletingName)==0) {
			PersonalAccount = item->PersonalAccount;
			if (item->next) {
				item->next->prev = item->prev;
			}
			else
				Head = item->prev;
			if (item->prev) {
				item->prev->next = item->next;
			}
			else
				First = item->next;
			ListItem *temp;
			temp = item->next;
			delete item;
			item = temp;
			check = 1;
		}
		else
			item = item->next;
	}
	if (check == 0) {
		printf("The depositor hasn't been found!\n");
		return "";
	}
	else
		count--;
	return PersonalAccount;
}

void List::Search(char *searchingName){
	bool check = 0;
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(item->name,searchingName)==0) {
			printf("%s %s %s %s %f\n", item->name, item->PersonalAccount, item->PassportNumber, item->DepositType, item->CurrentBalance);
			check = 1;
		}
		item = item->next;
	}
	if (check == 0) {
		printf("The depositor hasn't been found!\n");
	}
}

void List::SortDeposit(int count){
	double *array = new double [count];
    ListItem *item;
	item = First;
	int i = 0;
	while (item!=NULL){
		array[i] = item->CurrentBalance;
		i++;
		item = item->next;
	}
	ShellSort(array, count);
	for (i = 0; i < count; i++) {
		ListItem *item;
		item = First;
		while (item!=NULL){
			if (array[i] == item->CurrentBalance) {
				printf("%s %s %s %s %f\n", item->name, item->PersonalAccount, item->PassportNumber, item->DepositType, item->CurrentBalance);
			}
		item = item->next;
		}
	}
}

void List::AddMoney(char *number, double money){
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			item->CurrentBalance += money;
		}
		item = item->next;
	}
}

void List::WithdrawMoney(char *number, double money){
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			if (money > item->CurrentBalance) {
				cout<<"Insufficient funds!\n";
			}
			else
				item->CurrentBalance -= money;
		}
		item = item->next;
	}
}

void List::Transfer(char *number1, char *number2, double money){
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(number1, item->PersonalAccount) == 0) {
			if (money > item->CurrentBalance) {
				cout<<"Insufficient funds!\n";
			}
			else {
				item->CurrentBalance -= money;
				AddMoney(number2, money);
			}
		}
		item = item->next;
	}
}

void List::FileWrite(FILE *file){
	file = fopen("D:\\University\\Progs\\Labs\\Programming\\Lab 7\\NewClients(for Lab7).txt","w");
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (item->next == NULL) {
			fprintf(file,"%s\t%s\t%s\t%s\t%f\t%s", item->name, item->PersonalAccount,
		item->PassportNumber, item->DepositType, item->CurrentBalance, item->Date);
		}
		else
			fprintf(file,"%s\t%s\t%s\t%s\t%f\t%s\n", item->name, item->PersonalAccount,
			item->PassportNumber, item->DepositType, item->CurrentBalance, item->Date);
		item = item->next;
	}
	fclose(file);
}


