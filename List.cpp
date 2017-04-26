//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

List::~List(){
	Head = NULL;
	while (First!=NULL){
		ListItem *temp;
		temp = First->next;
		delete First;
		First = temp;
	}

}

void List::Add(char *Name, char *personalAccount, char *passportNumber, char *depositType, double currentBalance){
	ListItem* item = new ListItem;
	strcpy(item->name, Name);
	strcpy(item->PersonalAccount, personalAccount);
	strcpy(item->PassportNumber, passportNumber);
	strcpy(item->DepositType, depositType);
	item->CurrentBalance = currentBalance;
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
	int j = 0;
	while (item!=NULL){
		printf("%s %s %s %s %f\n", item->name, item->PersonalAccount, item->PassportNumber, item->DepositType, item->CurrentBalance);
		item = item->next;
	}
}


void List::Deleting(char *deletingName, int &count){
	ListItem *item;
	item = First;
	int c = 0;
	while (item!=NULL){
		if (strcmp(item->name,deletingName)==0) {
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
			c = 1;
		}
		else
			item = item->next;
	}
	if (c == 0) {
		printf("The depositor hasn't been found!\n");
	}
	else
		count--;
}

void List::Search(char *searchingName){
	int c = 0;
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(item->name,searchingName)==0) {
			printf("%s %s %s %s %f\n", item->name, item->PersonalAccount, item->PassportNumber, item->DepositType, item->CurrentBalance);
			c = 1;
		}
		item = item->next;
	}
	if (c == 0) {
		printf("The employee hasn't been found!\n");
	}
}

void List::PersonalAccountInfo(char *PersonalAccount){
	int c = 0;
	ListItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(item->PersonalAccount,PersonalAccount)==0) {
			printf("Personal Account:%s\nCurrent Balance:%f\n", item->PersonalAccount, item->CurrentBalance);
			c = 1;
		}
		item = item->next;
	}
	if (c == 0) {
		printf("The account hasn't been found!\n");
	}
}

void List::SortDeposit(){

}
