#include <stdio.h>
#include <stdlib.h>
#include "vector.c"
#include "LinkedList.c"
#include "Stack.c"
#include "Queue.c"
int main()
{
///////////////////////////////PART I//////////////////////////////////////////////////////
///////////////////////////////////////PART A///////////////////////////////////////////////////////////////////////////////////
	int i;
	printf("\n--------------------------------------------------VECTOR-------------------------------------------------------------\n");

	Vector *vec=createVector();
	printf("\nIntially Vector max_size is %d & used_size is %d\n",vec->max_size,vec->current_size);

	//Loop 1 :inserting 20 integer data
	srand(time(NULL)); //seed the random number generator only once
	for(i=0;i<20;i++){
		int randomNumber=rand()%20;  //Generate random number between 0-19
		Data new_Data;
		new_Data.number=randomNumber;
		vectorInsert(vec,i,new_Data);
	}
	printf("After insert Vector - max_size %d & used_size %d\n\n",vec->max_size,vec->current_size);
	//printf("Enter index and value:");
	/*int index1;
	Data value1;
	scanf("%d",&x);
	scanf("%d",&y);
	vectorInsert(geo_vec,x,y);*/
	//Loop 2 :reading & printing the vector
	for(i=0;i < vec->current_size;i++)
	{
		int value_at_index=vectorRead(vec,i);
		if(value_at_index==-1)
		{
			printf("There is no such index\n");
			break;
		}
		else
			printf("INDEX : %d VALUE : %d\n",i,value_at_index);
	}
	printf("\n");

	//Loop 3 : removing all the assigned values
	for(i=0;i< vec->current_size;i++)
	{
		printf("DELETED INDEX : %d VALUE : %d\n",i,vec->arr[i].number);
		vectorRemove(vec,i);
  	} 
	free(vec->arr);
	free(vec);
////////////////////////////////////////PART B////////////////////////////////////////////////////////////////////////////////
	printf("\n=======================PART B===============================\n");
  	struct timeval start, stop;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	gettimeofday(&start, NULL);
  	Vector *geo_vec=createVector();
	printf("\nIntially Vector max_size is %d & used_size is %d\n",geo_vec->max_size,geo_vec->current_size);
	//insert 10000 values
	srand(time(NULL)); //seed the random number generator only once
	for(i=0;i<10000;i++){
		int randomNumber=rand()%20;  //Generate random number between 0-19
		Data new_Data;
		new_Data.number=randomNumber;
		vectorInsert(geo_vec,i,new_Data);
	}
	printf("After insert Vector - max_size %d & used_size %d\n",geo_vec->max_size,geo_vec->current_size);
	for(i=0;i< geo_vec->current_size;i++)
		vectorRemove(geo_vec,i);
	free(geo_vec->arr);
	free(geo_vec);	
  	gettimeofday(&stop, NULL);
  	time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
  	time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
  	time_t geo_final_time = stop_time - start_time;
  	printf("TIME OF GEOMETRIC EXPANSION : %d microseconds\n",geo_final_time);
   ///////////////////////////////////////////////////////////////////////////////////////
  	gettimeofday(&start, NULL);
  	Vector *inc_vec=createVector();
	printf("\nIntially Vector max_size is %d & current_size is %d\n",inc_vec->max_size,inc_vec->current_size);
 	//insert 10000 values
	srand(time(NULL)); //seed the random number generator only once
	for(i=0;i<10000;i++)
  	{
		int randomNumber=rand()%20;  //Generate random number between 0-19
		Data new_Data;
		new_Data.number=randomNumber;
		vectorIncInsert(inc_vec,i,new_Data);
	}
	printf("After insert Vector - max_size %d & current_size %d\n",inc_vec->max_size,inc_vec->current_size);
	for(i=0;i< inc_vec->current_size;i++)
	vectorRemove(inc_vec,i);
	free(inc_vec->arr);
	free(inc_vec);	
  	gettimeofday(&stop, NULL);
  	start_time = (start.tv_sec* 1000000) + start.tv_usec;
  	stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
  	time_t inc_final_time = stop_time - start_time;
  	printf("TIME OF INCREMENTAL EXPANSION : %d microseconds\n",inc_final_time);
////////////////////////////PART II : LINKED LIST//////////////////////////////////////////////////////
	printf("\n----------------------------------------------------LINKED LISTS-----------------------------------------------------\n");
	//Generate 10 random numbers to be inserted
	List *list=createList();
	for(i=0;i<10;i++)
	{
		Data new_data;
		new_data.number=rand()%20;
		insertData(list,i,new_data);
		display(list);
	}
	//insert number at index 20
	Data new_data;
	new_data.number=rand()%20;
	printf("Trying to add a node with value %d at index 20\n",new_data.number);
	insertData(list,20,new_data);
	display(list);

	//search for a number in the list Forward and backwards
	int search_num;
	printf("Enter the value to be searched:\n");
	scanf("%d",&search_num);
	int forward,backward;
	forward=searchForward(list,search_num);
	backward=searchBackward(list,search_num);
	printf("FORWARD POSITION : %d\nBACKWARD POSITION : %d\n",forward,backward);
	//Delete a data from particular index
	int remove;
	remove=rand()%12;
	int Return=removeNode(list,remove);
	while(Return!=0)	//0 is returned if list is empty
	{
		printf("Index being removed : %d\n",remove);
		if(Return==1)
		{
			printf("After deleting data at index %d\n",remove);
			display(list);
		}
		remove=rand()%11;
		Return=removeNode(list,remove);
	}
	free(list);
	list=NULL;
///////////////////////////////////////PART III A///////////////////////////////////////////////////
	printf("\n--------------------------------------------------STACK--------------------------------------------------------------\n");
        Stack *stack=createStack();
        printf("Enter 5 values to be pushed\n");
	for(i=0;i<5;i++)
        {
                int new_data;
		printf("NEXT ELEMENT : ");
                scanf("%d",&new_data);
                push(stack,new_data);
                show(stack);
        }
	for(i=0;i<5;i++)
        {
		int poped;
            	poped=pop(stack);
		printf("poped [%d]",poped);
                show(stack);
        }
	free(stack);
///////////////////////////////////////PART B///////////////////////////////////////////////////////
	printf("\n--------------------------------------------------QUEUE--------------------------------------------------------------\n");
        Queue *queue=createQueue();
        printf("Enter 5 values to be appended\n");
        for(i=0;i<5;i++)
        {
                int new_data;
		printf("NEXT ELEMENT : ");
                scanf("%d",&new_data);
                enqueue(queue,new_data);
                Qshow(queue);
        }
        for(i=0;i<5;i++)
        {
                int remov;
                remov=dequeue(queue);
                printf("removed [%d]",remov);
                Qshow(queue);
        }
	free(queue);
	printf("\n-------------------------------------------------THE END-------------------------------------------------------------\n");
////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}
