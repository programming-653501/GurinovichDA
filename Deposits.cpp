//---------------------------------------------------------------------------

#pragma hdrstop

#include "Deposits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Deposit::~Deposit(){
	Head = NULL;
	while (First!=NULL){
		DepositItem *temp;
		temp = First->next;
		delete First;
		First = temp;
	}
}

void Deposit::Add(char *personalAccount, char *depositType, char *date, double currentBalance){
	char *money_string = new char [21];
	DepositItem* item = new DepositItem;
	strcpy(item->PersonalAccount, personalAccount);
	strcpy(item->DepositType, depositType);
	strcpy(item->Date, date);
	item->CurrentBalance = currentBalance;
	item->info_count = 1;
	sprintf(money_string, "%f", currentBalance);
	strcpy(item->Info[item->info_count-1],"Created with ");
	strcat(item->Info[item->info_count-1], money_string);
	strcat(item->Info[item->info_count-1], " on ");
	strcat(item->Info[item->info_count-1], date);
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

void Deposit::Show(){
	DepositItem *item;
	item = First;
	while (item!=NULL){
		printf("%s %s\t%s\t%f\n", item->PersonalAccount, item->DepositType, item->Date, item->CurrentBalance);
		item = item->next;
	}
}

void Deposit::Deleting(char *deletingName){
	DepositItem *item;
	item = First;
	bool check = 0;
	while (item!=NULL){
		if (strcmp(item->PersonalAccount,deletingName)==0) {
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
			DepositItem *temp;
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
	}
}

void Deposit::PersonalAccountInfo(char *PersonalAccount){
	bool check = 0;
	DepositItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(item->PersonalAccount,PersonalAccount)==0) {
			printf("Personal Account:%s\nDeposit Type:%s\nThe date of the opening:%s\nCurrent Balance:%f\n", item->PersonalAccount, item->DepositType, item->Date, item->CurrentBalance);
			check = 1;
		}
		item = item->next;
	}
	if (check == 0) {
		printf("The account hasn't been found!\n");
	}
}

int Deposit::CheckAccountNumber(char *number){
	int check = 0;
	DepositItem *item;
	item = First;
	while (item!=NULL){
		if (strcmp(item->PersonalAccount,number) == 0) {
			check = 1;
		}
		item = item->next;
	}
	return check;
}

void Deposit::CurrentBalanceSum(){
	DepositItem *item;
	item = First;
	double sum = 0.0;
	while (item != NULL){
		sum += item->CurrentBalance;
		item = item->next;
	}
	cout<<"The sum of all balances = "<<sum<<endl;
}

void Deposit::AddMoney(char *number, double money, char *date){
	DepositItem *item;
	item = First;
	char *money_string = new char [21];
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			item->CurrentBalance += money;
			item->info_count++;
			sprintf(money_string, "%f", money);
			strcpy(item->Info[item->info_count-1],"Replenish: ");
			strcat(item->Info[item->info_count-1], money_string);
			strcat(item->Info[item->info_count-1], " on ");
			strcat(item->Info[item->info_count-1], date);
		}
		item = item->next;
	}
}

void Deposit::WithdrawMoney(char *number, double money, char *date){
	DepositItem *item;
	item = First;
	char *money_string = new char [21];
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			if (money < item->CurrentBalance){
				item->CurrentBalance -= money;
				item->info_count++;
				sprintf(money_string, "%f", money);
				strcpy(item->Info[item->info_count-1], "Withdraw: ");
				strcat(item->Info[item->info_count-1], money_string);
				strcat(item->Info[item->info_count-1], " on ");
				strcat(item->Info[item->info_count-1], date);
			}
		}
		item = item->next;
	}
}

void Deposit::ShowInfo(char *number, char *year){
	DepositItem *item;
	item = First;
	int count = 0;
	bool found = 0;
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			for (int i = 0; i < item->info_count; i++) {
				int length = strlen(item->Info[i]);
				for (int j = 4; j > 0; j--) {
					if (item->Info[i][length-j] == year[4-j]) {
						count = 1;
					}
					else {
						count = 0;
						break;
					}
				}
				if (count == 1) {
					cout<<item->Info[i]<<endl;
					found = 1;
				}
			}
		}
		item = item->next;
	}
	if (!found) {
		cout<<"Operations in such year haven't been found!\n";
	}
}

void Deposit::Transfer(char *number1, char *number2, double money, char *date){
	DepositItem *item;
	item = First;
	char *money_string = new char [21];
	while (item!=NULL){
		if (strcmp(number1, item->PersonalAccount) == 0) {
			if (money < item->CurrentBalance){
				item->CurrentBalance -= money;
				item->info_count++;
				sprintf(money_string, "%f", money);
				strcpy(item->Info[item->info_count-1], "Transfer: ");
				strcat(item->Info[item->info_count-1], money_string);
				strcat(item->Info[item->info_count-1], " to account number ");
				strcat(item->Info[item->info_count-1], number2);
				strcat(item->Info[item->info_count-1], " on ");
				strcat(item->Info[item->info_count-1], date);
			}
		}
		item = item->next;
	}
	item = First;
	while (item!=NULL){
		if (strcmp(number2, item->PersonalAccount) == 0) {
				item->CurrentBalance += money;
				item->info_count++;
				sprintf(money_string, "%f", money);
				strcpy(item->Info[item->info_count-1], "Transfer: ");
				strcat(item->Info[item->info_count-1], money_string);
				strcat(item->Info[item->info_count-1], " from account number ");
				strcat(item->Info[item->info_count-1], number1);
				strcat(item->Info[item->info_count-1], " on ");
				strcat(item->Info[item->info_count-1], date);
		}
		item = item->next;
	}
}

void Deposit::Percents(char *number, char *date){
	DepositItem *item;
	int day1, month1, year1, day2, month2, year2, daysDifference;
	item = First;
	while (item!=NULL){
		if (strcmp(number, item->PersonalAccount) == 0) {
			break;
		}
		item = item->next;
	}
	Data(item->Date, day1, month1, year1);
	Data(date, day2, month2, year2);
	daysDifference = DaysDifference(day1, month1, year1, day2, month2, year2);
	if (strcmp(item->DepositType,"Five Stars") == 0) {
		if (daysDifference >= 30 && daysDifference < 90) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.05<<endl;
		}
		else if (daysDifference >= 90 && daysDifference < 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.07<<endl;
		}
		else if (daysDifference >= 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.105<<endl;
		}
		else
			cout<<"The sum will be "<<item->CurrentBalance<<endl;
	}
	else if (strcmp(item->DepositType,"Hot money") == 0) {
		if (daysDifference >= 30 && daysDifference < 90) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.03<<endl;
		}
		else if (daysDifference >= 90 && daysDifference < 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.06<<endl;
		}
		else if (daysDifference >= 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.09<<endl;
		}
		else
			cout<<"The sum will be "<<item->CurrentBalance<<endl;
	}
	else if (strcmp(item->DepositType,"Higher.Net") == 0) {
    	if (daysDifference >= 30 && daysDifference < 90) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.065<<endl;
		}
		else if (daysDifference >= 90 && daysDifference < 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.085<<endl;
		}
		else if (daysDifference >= 480) {
			cout<<"The sum will be "<<item->CurrentBalance + item->CurrentBalance * 0.115<<endl;
		}
		else
			cout<<"The sum will be "<<item->CurrentBalance<<endl;
	}
}
