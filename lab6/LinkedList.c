#include "LinkedList.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
node *createNode()
{
	node *Node;
	Node=(node *)malloc(sizeof(node));
	if(Node==NULL)
	{
		printf("No memory was allocated for Node");
		exit(0);
	}
	Node->data.number=0;
	Node->next=NULL;
	Node->prev=NULL;
	Node->index=0;
	return Node;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List *createList()
{
	List *list;
	list=(List *)malloc(sizeof(List));
	if(list==NULL)
        {
                printf("No memory was allocated for list");
                exit(0);
        }
	list->head=NULL;
	list->tail=NULL;
	return list;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
node *front(List *list)
{
	return list->head;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
node *insertData(List *list,int index,Data value)
{
	node *Node=createNode();
	node *temp;
        temp=front(list);
	if(temp==NULL)
	{
		list->head=Node;
		Node->data.number=value.number;
		Node->index=0;
	}
	else if(index==0)
	{
		Node->next=temp;
		list->head=Node;
		Node->data.number=value.number;
		Node->index=0;
		updateindex(list);
	}
	else
	{
		while((index-1)!=temp->index && temp->next!=NULL)
			temp=temp->next;
		Node->next=temp->next;
		temp->next=Node;
		Node->data.number=value.number;
		///updating index
		updateindex(list);
	}
	return Node;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display(List *list)
{
	node *Nod=front(list);
	if(Nod==NULL)
		printf("EMPTY LIST\n");
	else
	{
		while(Nod!=NULL)
		{
			printf("( %d : %d )->",Nod->index,Nod->data.number);
			Nod=Nod->next;
		}
		printf("NULL\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int removeNode(List *list, int index)
{
	node *Node=front(list);
	if(Node==NULL)//if list empty
	{
		//For the first node
		return 0;
	}
	else if(index==0)//head to be deleted
	{
		node *temp;
		temp=list->head;
		list->head=Node->next;
		free(temp);
		updateindex(list);
		return 1;
	}
	else
	{
		while((index-1)!=Node->index && Node->next!=NULL)
			Node=Node->next;
		if(Node->next!=NULL)
			if(Node->next->next!=NULL)
			{
				node *temp=Node->next;
				Node->next=Node->next->next;
				free(temp);
				updateindex(list);
				return 1;
			}
			else
			{
				free(Node->next);
				Node->next=NULL;
				return 1;
			}
		else
			 return -1;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//this function not only update indexes bt also links the list backwards
void updateindex(List *list)
{
	node *Node;
	Node=front(list);
	int counter=0;
	while(Node!=NULL)
	{
		Node->index=counter;
		counter++;
		if(Node->next!=NULL)
			Node->next->prev=Node;
		else
			list->tail=Node;
		Node=Node->next;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int searchForward(List *list,int value)
{
	node *Node=front(list);
	int counter=1;
	while(Node->data.number!=value && Node->next!=NULL)
	{
		Node=Node->next;
		counter++;
	}
	if(Node->data.number==value)
		return counter;
	else
	{
		printf("VALUE NOT FOUND\n");
		return -1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////
int searchBackward(List *list,int value)
{
        node *Node=list->tail;
	int counter=1;
        while(Node->data.number!=value && Node->prev!=NULL)
        {
	        Node=Node->prev;
        	counter++;
	}
	if(Node->data.number==value)
	        return counter;
	else
	{
		printf("VALUE NOT FOUND\n");
		return -1;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
