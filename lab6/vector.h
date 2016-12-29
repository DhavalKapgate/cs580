#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>	/* time_t */
#include <sys/time.h>	/* timeval, gettimeofday() */

#define EMPTY 0
typedef struct data
{
	int number;
}Data;

typedef struct vector{
	Data *arr;
	unsigned int current_size;
	unsigned int max_size;
}Vector;

Vector *createVector();
void vectorInsert(Vector *array,int index,Data value);
void vectorRemove(Vector *array,int index);
int vectorRead(Vector *array,int index);
