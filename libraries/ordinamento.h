/*H**********************************************************************
* FILENAME :        sort.h
*
* DESCRIPTION :		Collection of functions for sorting arrays.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#ifndef ORDINAMENTO_H
#define ORDINAMENTO_H

/* Here goes the element_type definition.
 * This definition of element_type is only an example.
 */
typedef int element_type;

/* ******************** ALGORITHMS' AUXILIARY FUNCTIONS ******************** */

/** Compare function. */
int compareE(element_type e1, element_type e2);

/** Swaps two elements. */
void scambia(element_type *a, element_type *b);

/** Finds the maximum element index.
 * @param v     the array
 * @param n     v length
 * @return      the maximum element index.
 */
int trovaPosMax(element_type v[], int n);

/** Merge sort auxiliary function. */
void merge(element_type v[], int i1, int i2, int fine, element_type vout[]);

/* ******************** DIFFERENT SORTING ALGORITHMS ******************** */
void naiveSort(element_type v[], int n);

void bubbleSort(element_type v[], int n);

void insOrd(element_type v[], int pos);

void insertSort(element_type v[], int n);

void mergeSort(element_type v[], int first, int last, element_type vout[]);

void quickSortR(element_type a[], int iniz, int fine);

void quickSort(element_type a[], int dim);

#endif // !ORDINAMENTO_H

