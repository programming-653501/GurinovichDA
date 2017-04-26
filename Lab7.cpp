#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <iostream.h>
#include "List.h"

int checkI(char *str);
List depositors;

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0, count1 = 0, x1 = 0, answer;
	while (count1 == 0){
		x1 = 0;
		while (!x1){
		char m1[3];
			printf("\tPriorbank Menu:\n1.Account statement\n2.The list of all clients\n3.The search in the list of clients\n4.Sort by current deposit amount\n5.The sum of all balance\n6.Add client\n7.Delete client\n8.Exit\n");
			fflush(stdin);
			fgets(m1, 3, stdin);
			answer = atoi(m1);
			if (!checkI(m1)||(answer < 1 || answer > 8))
				printf("\nEnter the right number!\n");
			else {
				x1 = 1;
			}
			if (answer == 1) {
                if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else{
					char *personalAccount = new char [21];
					cout<<"Enter the number of the account:";
					gets(personalAccount);
					depositors.PersonalAccountInfo(personalAccount);
				}
			}
			else if (answer == 2) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else
					depositors.Show();
			}
			else if (answer == 3) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *Name = new char [31];
					printf("Enter the name of the client that you want to find:");
					gets(Name);
					depositors.Search(Name);
				}
			}
			else if (answer == 4) {
				if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					depositors.SortDeposit();
				}
			}
			else if (answer == 5) {
            	if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					depositors.SortDeposit();
				}
			}
			else if (answer == 6) {
				system("cls");
				char *Name = new char [31];
				char *personalAccount = new char [21];
				char *passportNumber = new char [11];
				char *depositType = new char [21];
				double currentBalance;
				printf("Enter the name of the client:");
				gets(Name);
				printf("Enter the number of personal account:");
				gets(personalAccount);
				printf("Enter the number of the passport:");
				gets(passportNumber);
				printf("Enter the type of the deposit:");
				gets(depositType);
				printf("Enter the current balance:");
				cin>>currentBalance;
				depositors.Add(Name, personalAccount, passportNumber, depositType, currentBalance);
            	count++;
			}
			else if (answer == 7) {
				system("cls");
                if (count == 0) {
					cout<<"No clients in the list!\n";
				}
				else {
					char *Name = new char [31];
					printf("Enter the name of the client who you want to delete:");
					gets(Name);
					depositors.Deleting(Name, count);
				}
			}
			else if (answer == 8) {
				count1 = 1;
			}
		}
	}
	return 0;
}

int checkI(char *str)
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
