#include "Queue.h"
////////////////////////////////////////////////////////////////
Queue *createQueue()
{
        Queue *list;
        list=(Queue *)malloc(sizeof(Queue));
	if(list==NULL)
        {
                printf("No memory was allocated for Queue");
                exit(0);
        }
        list->head=NULL;
        return list;
}

/////////////////////////////////////////////////////////////////////////////////$
void enqueue(Queue * queue, int value)
{
        node *Node=createNode();
        node *temp;
        temp=queue->head;
        if(temp==NULL)
        {
                queue->head=Node;
                Node->data.number=value;
                Node->next=NULL;
        }
        else
        {
		while(temp->next!=NULL)
			temp=temp->next;
                temp->next=Node;
		Node->next=NULL;
                Node->data.number=value;
        }

}
/////////////////////////////////////////////////////////////////////////////////$
int dequeue(Queue *queue)
{
        node *temp;
        temp=queue->head;
	      if(temp==NULL)
        {
                printf("NOTHING TO POP\n");
                return -1;
        }
        else
        {
                int val;
                val=queue->head->data.number;
                queue->head=temp->next;
                free(temp);
                return val;
        }
}
/////////////////////////////////////////////////////////////////////////////////$
void Qshow(Queue *queue)
{
        node *temp;
        temp=queue->head;
        printf("\nCURRENT Queue\n");
        while(temp!=NULL)
        {
                if(temp==queue->head)
                        printf("front of Queue\n↓↓↓\n");
		printf("[%d]",temp->data.number);
                temp=temp->next;
        }
        printf("NULL\n\n");

}
/////////////////////////////////////////////////////////////


