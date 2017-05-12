//---------------------------------------------------------------------------

#pragma hdrstop

#include "OtherFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void FileRead(FILE *file, int &count, List &depositors, Deposit &deposits){
	file = fopen("D:\\University\\Progs\\Labs\\Programming\\Lab 7\\Clients(for Lab7).txt","r");
	while (!feof(file)){
		char *string = new char [100];
		char *name = new char [31];
		char *account = new char [21];
		char *passport = new char [10];
		char *type = new char [16];
		char *balance = new char [10];
		char *date = new char [11];
		int j;
		fgets(string, 100, file);
		for (j = 0; string[j] != '\t'; j++) {
			name[j] = string[j];
		}
		int k;
		for (j = j + 1, k = 0; isdigit(string[j]); j++, k++) {
			account[k] = string[j];
		}
		for (j = j + 1, k = 0; string[j]!='\t'; j++, k++) {
			passport[k] = string[j];
		}
		for (j = j + 1, k = 0; string[j]!='\t'; j++, k++) {
			type[k] = string[j];
		}
		for (j = j + 1, k = 0; string[j]!='\t'; j++, k++) {
			balance[k] = string[j];
		}
		for (j = j + 1, k = 0; string[j]!='\n'; j++, k++) {
			date[k] = string[j];
		}
		double money = atof(balance);
		if (name[0] == '\0') {
        	for (j = 0; string[j]!='\t'; j++) {
				name[j] = string[j];
			}
		}
		deposits.Add(account, type, date, money);
		depositors.Add(name, account, passport, type, money, date);
		count++;
		delete string, name, account, passport, type, balance, date;
		}
	fclose(file);
}

void CheckAccount(char *number, Deposit deposits){
	bool check = 0;
	while (!check){
		printf("Enter the number of personal account:");
		fflush(stdin);
		gets(number);
		if (deposits.CheckAccountNumber(number) == 0) {
			cout<<"There is no account with such number!\n";
		}
		else
		check = 1;
	}
}
