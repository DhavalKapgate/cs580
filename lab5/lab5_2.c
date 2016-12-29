#include<stdio.h>
#include<stdlib.h>
void * allocate(unsigned int size);
void * deallocate(void *, int size);
int heap_usage=0;
int main()
{
	printf("Enter The size to be allocated:\n");
	unsigned int size;
	scanf("%d",&size);
	void *pointer;
	pointer=allocate(size);
	printf("Amount of memory in usage : %d\n",heap_usage);
	if(pointer!=NULL)pointer=deallocate(pointer,size);
	return 0;
}
void * allocate(unsigned int size)
{
	void *pointer;
	pointer=malloc(size);
	if(pointer==NULL)
		printf("OUT OF MEMORY\n");
	else
	{
		heap_usage=heap_usage+size;
		printf("%d bytes allocated\n",heap_usage);
	}
	return pointer;
}
void * deallocate(void *pointer, int size)
{
	free(pointer);
	heap_usage=heap_usage-size;
	printf("%d bytes freed\nthus amount of memory unger usage : %d\n",size,heap_usage);
	return NULL;
}
