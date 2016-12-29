#include "Stack.h"
////////////////////////////////////////////////////////////////
Stack *createStack()
{
        Stack *list;
        list=(Stack *)malloc(sizeof(Stack));
        if(list==NULL)
        {
                printf("No memory was allocated for Stack");
                exit(0);
        }
	list->tail=NULL;
        return list;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void push(Stack * stack, int value)
{
	node *Node=createNode();
        node *temp;
        temp=stack->tail;
        if(temp==NULL)
        {
                stack->tail=Node;
                Node->data.number=value;
                Node->prev=NULL;
        }
	else
	{
		Node->prev=stack->tail;
		stack->tail=Node;
		Node->data.number=value;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int pop(Stack *stack)
{
	node *temp;
	temp=stack->tail;
	if(temp==NULL)
	{
		printf("NOTHING TO POP\n");
		return -1;
	}
	else
	{
		int val;
		val=stack->tail->data.number;
		stack->tail=temp->prev;
		free(temp);
		return val;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void show(Stack *stack)
{
	node *temp;
	temp=stack->tail;
	printf("\nCURRENT STACK\n");
	while(temp!=NULL)
	{
		printf("[%d]",temp->data.number);
		if(temp==stack->tail)
			printf("<-top of stack");
		temp=temp->prev;
		printf("\n");
	}
	printf("NULL\n\n");

}
/////////////////////////////////////////////////////////////
