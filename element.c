/*H**********************************************************************
* FILENAME :        element.c
*
* DESCRIPTION :		element template.
*       
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "readfield.h"
#include "mytime.h"

/* Here goes the compare implementation. Once compare is
 * implemented, there is NO need to change the functions
 * relying on it.
 */
int compare(element e1, element e2) {
	
}

// The implementation relies on compare
boolean isLess(element e1, element e2) {
	if (compare(e1, e2) == -1)
		return vero;
	else
		return falso;
}

// The implementation relies on compare
boolean isEqual(element e1, element e2) {
	if (compare(e1, e2) == 0)
		return vero;
	else
		return falso;
}

// The implementation relies on compare
boolean isBigger(element e1, element e2) {
	if (compare(e1, e2) == 1)
		return vero;
	else
		return falso;
}

/** Prints the element. */
void printElement(element e) {
	
}

READ_CODE readElementFromFile(FILE* fp, element* dest) {
	int result = READ_SUCCESSFUL;
	char sepRead;
}
