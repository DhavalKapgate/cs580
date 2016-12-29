#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	Data data;
	int index;
	struct Node *next;
	struct Node *prev; 
}node;

typedef struct list
{
 	struct Node *head;
	struct Node *tail;
}List;

node *createNode();
List *createList();
node *front(List *list);
node *insertData(List *list,int index,Data value);
void display(List *list);
int removeData(List *list, int index);
void updateindex(List *list);
int searchForward(List *list,int value);
int searchBackward(List *list,int value);
