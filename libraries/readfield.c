#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "readfield.h"

char readField(char buffer[], int dimBuffer, char sep, FILE *f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != 10 && ch != EOF && i < (dimBuffer-1)) {
		buffer[i++] = ch;
		ch = fgetc(f);
	}
	buffer[i] = '\0';
	return ch;
}