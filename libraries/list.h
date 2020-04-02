/*H**********************************************************************
* FILENAME :        list.h
*
* DESCRIPTION :		List implementation header.
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
#ifndef LIST_H
#define LIST_H

/** The node of the list. It contains an element and
 * the pointer to the next one.
 */
typedef struct node {
	element info;
	struct node *next;
} listNode;

/** The list type.*/
typedef listNode *list;

/** Empty list constructor. */
list emptyList(void);

/** Returns a boolean indicating if the list is empty.
 * @return      vero if the list is empty, falso otherwise.
 */
boolean empty(list l);

/** Returns the first element of the list. */
element head(list l);

/** Returns the list without its head element. */
list tail(list l);

/** List constructor (insert an el in the head). */
list cons(element e, list l);

void showList(list l);

/** Returns if an element belongs to a list.
 * @param   e   the element
 * @param   l   the list
 * @return      1 if e is a member of the list else 0. 
 */
boolean member(element e, list l);

/** Returns the list length.
 * @param   l   the list
 * @return	the lenght of the list passed as argument.
 */
int lenght(list l);

/** Append a list l2 to another list l1. */
list append(list l1, list l2);

list reverse(list l);

list copy(list l);

/** delete an element e of the list l. */
list deleteE(element e, list l);

/** Ordered insertion, duplications may occur.*/
list insord(element e, list l); 

/** Counts the times an element occurs in the list.
 * (HMT stands for How Many Times).
 */
int member_HMT(element e, list l);

list deleteDuplicates(list l);

/** Releases the resources used by a list. */
void freelist(list l);

#endif // !LIST_H
