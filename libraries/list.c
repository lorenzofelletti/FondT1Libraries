/*H**********************************************************************
* FILENAME :        list.c
*
* DESCRIPTION :		List implementation.
*
* AUTHOR :			Lorenzo Felletti
*
*H*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfield.h"
#include "element.h"
#include "list.h"


list emptyList(void) {
	return NULL;
}

boolean empty(list l) {
	if (l == NULL)
		return vero;
	else
		return falso;
}

element head(list l) {
	if (empty(l))
		abort();
	else
		return l->info;
}

list tail(list l) {
	if (empty(l))
		abort();
	else
		return l->next;
}

list cons(element e, list l) {
	list t;
	t = (list)malloc(sizeof(listNode));
	t->info = e;
	t->next = l;
	return t;
}

void showList(list l) {
	printf("[");
	while (!empty(l)) {
		printElement(l->info);
		l = tail(l);
		if (!empty(l))
			printf(", ");
	}
	printf("]\n");
}

boolean member(element e, list l) {
	if (empty(l))
		return falso;
	else if (compare(e, head(l)) == 0)
		return vero;
	else
		return member(e, tail(l));
}

int lenght(list l) {
	if (empty(l))
		return 0;
	else
		return 1 + lenght(tail(l));
}

list append(list l1, list l2) {
	if (empty(l1))
		return l2;
	else
		return cons(head(l1), append(tail(l1), l2));
}

list reverse(list l) {
	if (empty(l))
		return emptyList();
	else
		return append(reverse(tail(l)), cons(head(l), emptyList()));
}

list copy(list l) {
	if (empty(l))
		return l;
	else
		return cons(head(l), copy(tail(l)));
}

list deleteE(element e, list l) {
	if (empty(l))
		return emptyList();
	else if (compare(e, head(l)) == 0)
		return tail(l);
	else
		return cons(head(l), deleteE(e, tail(l)));
}

list insord(element e, list l) {
	// duplications may occcurs
	if (empty(l))
		return cons(e, l);
	else if (isLess(e, head(l)))
		return cons(e, l);
	else
		return cons(head(l), insord(e, tail(l)));
}

int member_HMT(element e, list l) {
	if (empty(l))
		return 0;
	else if (isEqual(e, head(l)))
		return 1 + member_HMT(e, tail(l));
	else
		return 0 + member_HMT(e, tail(l));
}

list deleteDuplicates(list l) {
	if (empty(l))
		return emptyList();
	else if (member_HMT(head(l), l) > 1)
		return deleteDuplicates(tail(l));
	else
		return cons(head(l), deleteDuplicates(tail(l)));
}

void freelist(list l) {
	if (empty(l)) {
		return;
	}
	else {
		freelist(tail(l));
		free(l);
	}
}