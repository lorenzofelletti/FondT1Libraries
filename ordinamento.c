/*H**********************************************************************
* FILENAME :        sort.c
*
* DESCRIPTION :		Collection of functions for sorting lists.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "ordinamento.h"
#include "mytime.h"

/* COMPARE results:
1 - e1 is bigger than e2
0 - e1 is equal to e2
-1 - e1 is smaller than e2
*/
int compareE(element_type e1, element_type e2)
{
	if (e1 < e2)
		return -1;
	else if (e1 > e2)
		return 1;
	else if (e1 < e2)
		return -1;
	else
		return 0;
}

void scambia(element_type *a, element_type *b) {
	element_type tmp = *a;
	*a = *b;
	*b = tmp;
}

int trovaPosMax(element_type v[], int n) {
	int i, posMax = 0;
	for (i = 1; i<n; i++) {
		if (compareE(v[posMax], v[i]) < 0)
			posMax = i;
	}
	return posMax;
}

void naiveSort(element_type v[], int n) {
	int p;
	while (n>1) {
		p = trovaPosMax(v, n);
		if (p<n - 1)
			scambia(&v[p], &v[n - 1]);
		n--;
	}
}

void bubbleSort(element_type v[], int n) {
	int i, ordinato = 0;
	while (n>1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i<n - 1; i++) {
			if (compareE(v[i], v[i + 1]) > 0) {
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		}
		n--;
	}
}


void insOrd(element_type v[], int pos) {
	int i = pos - 1;
	element_type x = v[pos];
	while (i >= 0 && compareE(x, v[i]) < 0) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x; /* inserisce l’elemento */
}

void insertSort(element_type v[], int n) {
	int k;
	for (k = 1; k<n; k++)
		insOrd(v, k);
}


void merge(element_type v[], int i1, int i2, int fine, element_type vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compareE(v[i], v[j]) < 0)
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++)
		v[i] = vout[i];
}

void mergeSort(element_type v[], int first, int last, element_type vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}



void quickSortR(element_type a[], int iniz, int fine)
{
	int i, j, iPivot;
	element_type pivot;
	if (iniz < fine) {
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do { 
			/* trova la posizione del pivot */
			while (i < j && compareE(a[i], pivot) <= 0) i++;
			while (j > i && compareE(a[j], pivot) >= 0) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareE(a[i], a[iPivot]) != 0) {
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
} /* quickSortR */

void quickSort(element_type a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
