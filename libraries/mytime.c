/*H**********************************************************************
* FILENAME :        mytime.c
*
* DESCRIPTION :		Collection of functions for Date and Time 
*					manipulation.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ordinamento.h"
#include "element.h"
#include "mytime.h"

int compareDate(Date d1, Date d2) {
	if (d1.year != d2.year)
		return d1.year - d2.year;
	else if (d1.month != d2.month)
		return d1.month - d2.month;
	else if (d1.day |= d2.day)
		return d1.day - d2.day;
	else
		return 0;
}

void printDate(Date d)
{
	printf("%d/%d/%d", d.day, d.month, d.year);
}

Date getDate(void)
{
	Date d;
	puts("Insert dd/mm/yyyy:");
	scanf("%d%d%d", &d.day, &d.month, &d.year);
	return d;
}

int minToSec(int m)
{
	return m * 60;
}

int hourToSec(int h)
{
	return h * 60 * 60;
}

int hourToMin(int h)
{
	return h * 60;
}

int yearsToMonths(int y)
{
	return y * 12;
}

int yearsToDays(int y)
{
	return y * 365;
}

int monthsToDays(int m)
{
	return m * 30;
}