//---------------------------------------------------------------------------

#pragma hdrstop

#include "Functions.h"
#include <iostream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

int datec(int month,int days,int day,int year)
{
	switch(month)
	{
	case 1:
		days = 0 + day;
        break;
    case 2:
		days = 31 + day;
        break;
	case 3:
		if (year - (year/4) * 4 == 0) days = day + 60;
		else days=59+day;
		break;
    case 4:
		if (year - (year/4) * 4 == 0) days = 91 + day;
		else days = 90 + day;
		break;
	case 5:
		if (year - (year/4) * 4 == 0) days = 121 + day;
		else days = 120 + day;
        break;
	case 6:
		if (year - (year/4) * 4 == 0) days = 152 + day;
		else days = 151 + day;
        break;
    case 7:
		if (year - (year/4) * 4 == 0) days = 182 + day;
		else days = 181 + day;
		break;
	case 8:
		if (year - (year/4) * 4 == 0) days = 213 + day;
		else days = 212 + day;
		break;
	case 9:
		if (year - (year/4) * 4 == 0) days = 244 + day;
		else days = 243 + day;
		break;
	case 10:
		if (year - (year/4) * 4 == 0) days = 274 + day;
		else days = 273 + day;
		break;
	case 11:
		if (year - (year/4) * 4 == 0) days = 305 + day;
		else days = 304 + day;
		break;
	case 12:
		if (year - (year/4) * 4 == 0) days = 335 + day;
		else days = 334 + day;
		break;
	}
	return days;
}

int DaysDifference(int day1, int month1, int year1, int day2, int month2, int year2){
	int i, day, dayDelta, year, days = 0;
	year = year2 - year1;
	dayDelta = (year / 4);
	day = year * 365;
	day += dayDelta;
	days = datec(month1, days, day1, year1);
	day -= days;
	days = 0;
	days = datec(month2, days, day2, year2);
	day += days;
	return day;
}

void Data(char *date, int &d, int &m, int &y){
	int i = 0, j = 0;
	char *day = new char [3];
	char *month = new char [3];
	char *year = new char [5];
	while (i < 2){
		day[i] = date[i];
		i++;
	}
	i++;
	while (i < 5){
		month[j] = date[i];
		i++;
		j++;
	}
	i++;
	j = 0;
	while (i < 10){
		year[j] = date[i];
		i++;
		j++;
	}
	d = atoi(day);
	m = atoi(month);
	y = atoi(year);
}


int checkI(char *string)
{
	unsigned int i, result = 0;
	for (i = 0; i < (int) strlen(string); i++) {
		if (isdigit(string[i])||string[i]=='\n') {
			result = 1;
		}
		else {
			result = 0;
			break;}
	}
	return result;
}

int CheckF(char *string)
{
	unsigned int i, result = 0, n = 0;
	for (i = 0; i < strlen(string); i++) {
		if (isdigit(string[i])) {
			result = 1;
		}
		else if (string[i] == '.') {
			n++;
		}
		else {
			result = 0;
			break;
		}
	}
	if (n >= 2) {
		result = 0;
	}
	return result;
}


