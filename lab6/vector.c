
#include "vector.h"
///////////////////////////////////////////////////////////////
Vector *createVector()
{
	Vector *vec;
	vec=malloc(sizeof(Vector));
	if(vec==NULL)
	{
		printf("OUT OF MEMORY\n");
		exit(0);
	}
	vec->current_size=0;
  	vec->arr=NULL;
	vec->max_size=0;
	return vec;
}
/////////////////////////////////////////////////////////////////
void vectorInsert(Vector *array,int index,Data value)
{
	Data *element;	//element to be inserted
	/////////first element insertion in vector///////////////
	if(array->arr==NULL)
	{
		element=malloc(sizeof(Data));
		if(element==NULL)
		{
			printf("OUT OF MEMORY");
			exit(0);
		}
		array->arr=element;	//initiale pointer
		*array->arr=value;	//initiale value pointed by pointer
		array->current_size=1;
		array->max_size=1;
	}
	////////////////for elements other than first element//////////
	else
	{
		//insert value at any position within bounds
		if(index < array->max_size)
		{
			if(index < array->current_size)//shift elements to the right by 1
			{	//incase current size exceeds bounds allocate memory
				if(array->current_size+1 > array->max_size)
				{
				        Data *temp;
					array->max_size=array->max_size*2;
					element=malloc(array->max_size*sizeof(Data));
     					if(element==NULL)
					{
						printf("OUT OF MEMORY");
						exit(0);
					}
					memcpy(element,array->arr,array->max_size*sizeof(Data));
		      			temp=array->arr;
					array->arr=element;
				        free(temp);
				}
				int counter=array->current_size;
				//shift every element from index by 1 place to right
				for(;counter>=index;counter--)
					array->arr[counter+1].number=array->arr[counter].number;
				array->current_size++;
				//insert value at index
				array->arr[index]=value;
			}
			else
			{
		        	//insert value at index
        			array->arr[index]=value;
				array->current_size=index+1;
			}
		}
		else
		{
			Data *temp;
			while(array->max_size<index)
				array->max_size=array->max_size*2;
      			element=malloc(array->max_size*sizeof(Data));
			if(element==NULL)
			{
				printf("OUT OF MEMORY");
				exit(0);
			}
      			memcpy(element,array->arr,array->max_size*sizeof(Data));
      			temp=array->arr;
      			array->arr=element;
			array->arr[index]=value;
         		free(temp);
      			array->current_size=index+1;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
void vectorRemove(Vector *array,int index)
{
	if(index < array->current_size)
	{
		array->arr[index].number = EMPTY;
	}
	else
		printf("Invalid index %d\n",index);
}
/////////////////////////////////////////////////////////////////////////////////
int vectorRead(Vector *array,int index)
{
	if(index >= array->current_size)
		return -1;
	else
		return array->arr[index].number;
}
/////////////////////////////////////////////////////////////////////////////
//INCREMENTAL EXPANSION//////////////////////////////////////////////////////
void vectorIncInsert(Vector *array,int index,Data value)
{
	Data *element;	//element to be inserted
	/////////first element insertion in vector///////////////
	if(array->arr==NULL)
	{
		element=malloc(sizeof(Data));
		if(element==NULL)
		{
			printf("OUT OF MEMORY");
			exit(0);
		}
		array->arr=element;	//initiale pointer
		*array->arr=value;	//initiale value pointed by pointer
		array->current_size=1;
		array->max_size=1;
	}
	////////////////for elements other than first element//////////
	else
	{
		//insert value at any position within bounds
		if(index < array->max_size)
		{
			if(index < array->current_size)//shift elements to the right by 1
			{	//incase current size exceeds bounds allocate memory
				if(array->current_size+1 > array->max_size)
				{
					array->max_size=array->max_size+1;
					element=malloc(array->max_size*sizeof(Data));
					memcpy(element,array->arr,array->max_size*sizeof(Data));
					Data *temp;
				       	temp=array->arr;
        				free(temp);
					array->arr=element;
				}
				int counter=array->current_size;
				//shift every element from index by 1 place to right
				for(;counter>=index;counter--)
					array->arr[counter+1].number=array->arr[counter].number;
				array->current_size++;
				//insert value at index
				array->arr[index]=value;
			}
			else
			{
        			//insert value at index
		        	array->arr[index]=value;
				array->current_size=index+1;
			}
		}
		else
		{
       			//printf(" %d ",array->arr);
			while(array->max_size-1 < index)
				  array->max_size=array->max_size+1;
      			element=malloc(array->max_size*sizeof(Data));
      			memcpy(element,array->arr,array->max_size*sizeof(Data));
      			Data *temp;
       			temp=array->arr;
           		free(temp);
      			array->arr=element;
			array->arr[index]=value;
      			array->current_size=index+1;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////
