/*H**********************************************************************
* FILENAME :        mytime.h
*
* DESCRIPTION :		Header file defining a type Date and a collection
*					of functions for date and time manipulation.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#ifndef MYTIME_H
#define MYTIME_H

/** Date type definition. */
typedef struct {
	int year;
	int month;
	int day;
} Date;

/** Compare two Date.
 * @param d1	First Date
 * @param d2	Second Date
 * @return		an int greater than 1 if d1 is bigger than d2,
				0 if d1 is equal to d2,
				-1 if d1 is smaller than d2
 */
int compareDate(Date d1, Date d2);

void printDate(Date d);

Date getDate(void);

int minToSec(int m);

int hourToSec(int h);

int hourToMin(int h);

int yearsToMonths(int y);

/** Given a number of years it returns the correspoinding
 * number of days.
 * It answers questions like 'how many days there are in 3 years?'.
 * Each year is considered 365 days long.
 * @param y     the number of years
 * @return      the number of days in y years
 */
int yearsToDays(int y);

/** Given a number of months it returns the corresponding
 * number of days. Each month is consider 30 days long.
 * @param m     the number of months
 */
int monthsToDays(int m);

#endif // !MYTIME_H
