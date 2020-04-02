/*H**********************************************************************
* FILENAME :        element.h
*
* DESCRIPTION :		element template header file.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfield.h"
#include "mytime.h"
#ifndef ELEMENT_H
#define ELEMENT_H
// read codes
#define READ_FAILED 0
#define READ_SUCCESSFUL 1
// useful #define
#define DIM_T_CAM 1024

/** Define the type READ_CODE which represents
 * the status of a read from a file (success, fail
 *  */
typedef int READ_CODE;

/** Boolean type definition */
typedef enum {
	falso,
	vero
} boolean;

/* Here goes the element definition.
 * This definition of element is only an example.
 */
typedef int element;

/** Compare two elements.
 * @return		1 if e1 is bigger than e2,
				0 if e1 is equal to e2,
				-1 if e1 is smaller than e2
 */
int compare(element e1, element e2);

/** Return a boolean that states if e1 is smaller than e2. */
boolean isLess(element e1, element e2);

/** Return a boolean that states if e1 is equal to e2. */
boolean isEqual(element e1, element e2);

/** Return a boolean that states if e1 is greater than e2. */
boolean isBigger(element e1, element e2);

void printElement(element e);

/** Read the element from a file.
 * @param *fp		pointer to the file descriptor
 * @param *dest		element ptr to put the read element
 * @return		a READ_CODE */
READ_CODE readElementFromFile(FILE *fp, element *dest);

#endif // !ELEMENT_H