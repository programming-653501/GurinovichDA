#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <iostream.h>
#include "List.h"
#include "Deposits.h"
#include "Functions.h"
#include "OtherFunctions.h"

List depositors;
Deposit deposits;

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0, answer, type;
	bool menu = 0, checkMenu = 0;
	FILE *file;
	FileRead(file, count, depositors, deposits);
	while (menu == 0){
		checkMenu = 0;
		while (!checkMenu){
		char answer_string[3];
			printf("\t\t\t\tPriorbank Menu:\n\
			1.Account information\n\
			2.The list of all clients\n\
			3.The search in the list of clients\n\
			4.Sort by current deposit amount\n\
			5.The sum of all balances\n\
			6.Add client\n\
			7.Delete client\n\
			8.Replenish the deposit\n\
			9.Withdraw money from the deposit\n\
			10.Account statement\n\
			11.Transfer money\n\
			12.View money on the certain date\n\
			13.Exit\n");
			fflush(stdin);
			fgets(answer_string, 3, stdin);
			answer = atoi(answer_string);
			if (!checkI(answer_string)||(answer < 1 || answer > 13))
				printf("\nEnter the right number!\n");
			else {
				checkMenu = 1;
			}
			if (answer == 1) {
                if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else{
					char *personalAccount = new char [21];
					cout<<"Enter the number of the account:";
					gets(personalAccount);
					deposits.PersonalAccountInfo(personalAccount);
				}
			}
			else if (answer == 2) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					cout<<"Name\t\tAccount number\t\tPassport number\tDeposit type\tCurrent balance\n";
					depositors.Show();
				}
			}
			else if (answer == 3) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *Name = new char [31];
					cout<<"Enter the name of the client that you want to find:";
					fflush(stdin);
					gets(Name);
					depositors.Search(Name);
				}
			}
			else if (answer == 4) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					depositors.SortDeposit(count);
				}
			}
			else if (answer == 5) {
            	if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					deposits.CurrentBalanceSum();
				}
			}
			else if (answer == 6) {
				char *Name = new char [31];
				char *personalAccount = new char [21];
				char *passportNumber = new char [11];
				char *depositType = new char [21];
				char *date = new char [11];
				double money;
				printf("Enter the name of the client:");
				fflush(stdin);
				gets(Name);
				bool checkAccount = 0;
				while (!checkAccount){
					printf("Enter the number of personal account:");
					fflush(stdin);
					gets(personalAccount);
					if (deposits.CheckAccountNumber(personalAccount) == 1) {
						cout<<"The number is already taken!\n";
					}
					else
						checkAccount = 1;
				}
				printf("Enter the number of the passport:");
				fflush(stdin);
				gets(passportNumber);
				bool checkTypeAnswer = 0;
				while (!checkTypeAnswer){
					char type_string[3];
					printf("Choose the type of the deposit:\n1.Five Stars\n2.Hot money\n3.Higher.net\n");
					fflush(stdin);
					fgets(type_string, 3, stdin);
					type = atoi(type_string);
					if (!checkI(type_string)||(type < 1 || type > 3))
						printf("Enter the right number!\n");
					else {
						checkTypeAnswer = 1;
					}
				}
				bool checkMoney = 0;
				char *money_string = new char [10];
				while (!checkMoney) {
					printf("Enter the amount of money:");
					fflush(stdin);
					gets(money_string);
					if (!CheckF(money_string))
						printf("Enter the right amount!\n");
					else{
						money = atof(money_string);
						if (type == 1) {
							strcpy(depositType,"Five Stars");
							if (money >= 100) {
								checkMoney = 1;
							}
							else
								printf("To open this type of deposit you have to put on the acount more than 100!\n");
						}
						else if (type == 2) {
							strcpy(depositType,"Hot money");
							if (money >= 1) {
								checkMoney = 1;
							}
							else
								printf("To open this type of deposit you have to put on the acount more than 1!\n");
						}
						else if (type == 3) {
							strcpy(depositType,"Higher.Net");
							if (money >= 50) {
								checkMoney = 1;
							}
							else
								printf("To open this type of deposit you have to put on the acount more than 50!\n");
						}
					}
				}
				printf("Enter the date of the opening of the account:");
				fflush(stdin);
				gets(date);
				depositors.Add(Name, personalAccount, passportNumber,
				depositType, money, date);
				deposits.Add(personalAccount, depositType, date, money);
				count++;
			}
			else if (answer == 7) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *Name = new char [31];
					char *Account = new char [21];
					printf("Enter the name of the client who you want to delete:");
					fflush(stdin);
					gets(Name);
					if ((Account = depositors.Deleting(Name, count)) != "") {
						deposits.Deleting(Account);
					}
				}
			}
			else if (answer == 8) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *personalAccount = new char [21];
					CheckAccount(personalAccount, deposits);
					bool check = 0;
					char *money_string = new char [10];
					char *date = new char [11];
					while (!check) {
						printf("Enter the amount of money to add to the deposit:");
						fflush(stdin);
						gets(money_string);
						if (!CheckF(money_string))
							printf("Enter the right amount!\n");
						else{
							printf("Enter the date of the replenishing:");
							fflush(stdin);
							gets(date);
							depositors.AddMoney(personalAccount, atof(money_string));
							deposits.AddMoney(personalAccount, atof(money_string), date);
							check = 1;
						}
					}
				}
			}
			else if (answer == 9) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *personalAccount = new char [21];
					CheckAccount(personalAccount, deposits);
					bool check = 0;
					char *money_string = new char [10];
					char *date = new char [11];
					while (!check) {
						printf("Enter the amount of money to withdraw from the deposit:");
						fflush(stdin);
						gets(money_string);
						if (!CheckF(money_string))
							printf("Enter the right amount!\n");
						else{
							printf("Enter the date of the withdraw:");
							fflush(stdin);
							gets(date);
							depositors.WithdrawMoney(personalAccount, atof(money_string));
							deposits.WithdrawMoney(personalAccount, atof(money_string), date);
							check = 1;
						}
					}
				}
			}
			else if (answer == 10) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					bool check = 0;
					char *personalAccount = new char [21];
					CheckAccount(personalAccount, deposits);
					while (!check){
						char year[5];
						cout<<"Enter the year:";
						fflush(stdin);
						fgets(year, 5, stdin);
						if (!checkI(year)||( atoi(year) > 2017))
							printf("Enter the right year!\n");
						else {
							check = 1;
						}
						deposits.ShowInfo(personalAccount, year);
					}
				}
			}
			else if (answer == 11) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else if (count == 1) {
					cout<<"You need to have at least 2 clients to transfer money!\n";
				}
				else {
					bool check = 0;
					char *firstPersonalAccount = new char [21];
					char *secondPersonalAccount = new char [21];
					char *date = new char [11];
					CheckAccount(firstPersonalAccount, deposits);
					CheckAccount(secondPersonalAccount, deposits);
					char *money_string = new char [10];
					while (!check) {
						printf("Enter the amount of money to transfer:");
						fflush(stdin);
						gets(money_string);
						if (!CheckF(money_string))
							printf("Enter the right amount!\n");
						else{
							printf("Enter the date of the transfer:");
							fflush(stdin);
							gets(date);
							depositors.Transfer(firstPersonalAccount, secondPersonalAccount,
							atof(money_string));
							deposits.Transfer(firstPersonalAccount, secondPersonalAccount,
							atof(money_string), date);
							check = 1;
						}
					}
				}
			}
			else if (answer == 12) {
            	if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *PersonalAccount = new char [21];
					char *date = new char [11];
					CheckAccount(PersonalAccount, deposits);
					printf("Enter the date:");
					fflush(stdin);
					gets(date);
					deposits.Percents(PersonalAccount, date);
				}
			}
			else if (answer == 13) {
				menu = 1;
				depositors.FileWrite(file);
			}
		}
	}
	return 0;
}




