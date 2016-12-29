#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *jedi_name(char *first,char *last,char *buffer);
int heap_usage=0;
struct Names
{
char *first_name;
char *last_name;
char *jedi_name;
};
void * allocate(unsigned int size)
{
        void *pointer;
        pointer=malloc(size);
        if(pointer==NULL)
                printf("OUT OF MEMORY\n");
        else
                {heap_usage=heap_usage+size;printf("(%d bytes allocated)",size);}
        return pointer;
}
void * deallocate(void *pointer, int size)
{
        free(pointer);
        heap_usage=heap_usage-size;
        printf("\t\t%d bytes freed from %d bytes>> Total memory allocated : %d\n",size,heap_usage+size,heap_usage);
        return NULL;
}
int main()
{
	struct Names Name;
	char *first,*last,*name;
	first=allocate(2*sizeof(char));
	printf("\n");
	last=allocate(3*sizeof(char));
	printf("\n");
	name=allocate(40*sizeof(char));
	printf("\n");
	Name.first_name=allocate(20*sizeof(char));
	printf("\n");
	Name.last_name=allocate(30*sizeof(char));
	//////////////////////////////////////////////////////////////////////////////////
	printf("\nEnter your first name and last name accordingly:\n");
        int count,ignore[20];
        scanf("%2s %s",first,&ignore);
	if(first[1]=='\0'){last[0]=ignore[0];last[1]=ignore[1];last[2]=ignore[2];last[3]='\0';}
        else scanf("%3s",last);
        if(first[1]=='\0')first[1]='a';
        if(last[2]=='\0'){last[2]=='\0';if(last[1]=='\0')last[1]='a';}
        char *buffer;
        buffer=allocate(5*sizeof(char));
        buffer=jedi_name(first,last,buffer);
        printf("\nYOUR JEDI NAME:\n%s\n",buffer);
        buffer=deallocate(buffer,5*sizeof(char));

	///////////////////////////////// PART 2.C /////////////////////////////////////////
	FILE *ptr1;
	FILE *ptr2;
	ptr1=fopen("names.txt","r");
	FILE *ptr3;
        ptr2=fopen("jedi.txt","w");
	ptr3=fopen("names.txt","r");
	printf("\t\t\tFULL NAME\t\t\t\tJEDI NAME\n\n");
	int i=0;
	//////////////////////////////////////////////////////////
	while(fgetc(ptr1)!=EOF)
	{
		fseek(ptr1,-1,SEEK_CUR);
		fscanf(ptr1,"%2s",first);
		fgets(name,40,ptr3);

                if(name[strlen(name)-1]=='\n')
                        name[strlen(name)-1]='\t';
		int space_pos,first_space=0,comma_pos=1;
		char current;
		while((current=fgetc(ptr1))!=',')
		{
			comma_pos++;
			if(current==' '&&first_space==0)
				{space_pos=comma_pos;first_space=1;}
			continue;
		}
		space_pos++;
		comma_pos++;
		/////////////////////seperating last name//////////////////////////
		comma_pos++;
		if(comma_pos<space_pos)space_pos=comma_pos;
		int counter;
		for(counter=0;counter<20;counter++)Name.last_name[counter]='\0';
        	for(counter=0;comma_pos<strlen(name);comma_pos++)
                	Name.last_name[counter++]=name[comma_pos];
  		/////////////////////seperating first name//////////////////////////
		for(counter=0;counter<20;counter++)Name.first_name[counter]='\0';
                for(counter=0;counter<=space_pos;counter++)
                        if(name[counter]==' ')break;
			else Name.first_name[counter]=name[counter];
		for(counter=0;counter<strlen(Name.first_name);counter++)
			if(Name.first_name[counter]==',')Name.first_name[counter]='\0';
			else if(Name.first_name[counter]=='\0')break;
		/////////////////////////////////////////////////////////

		fscanf(ptr1,"%3s",last);
		while(fgetc(ptr1)!='\n')
                        continue;

		if(last[2]=='\0')
			{last[2]='a';last[3]='\0';}

		char *buffer;
		buffer=allocate(5*sizeof(char));
		buffer=jedi_name(first,last,buffer);
	 	printf("\t<%d>%s %s\t\t\t\t\t\t\t%s",++i,Name.first_name,Name.last_name,buffer);
		fprintf(ptr2,"%s\n",buffer);
		buffer=deallocate(buffer,5*sizeof(char));
	}
	/////////////////////////////////////////////////////////
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);
	first=deallocate(first,2*sizeof(char));
	last=deallocate(last,3*sizeof(char));
        name=deallocate(name,40*sizeof(char));
        Name.first_name=deallocate(Name.first_name,20*sizeof(char));
        Name.last_name=deallocate(Name.last_name,30*sizeof(char));
	printf("\t\tMEMORY LEAK: %d bytes\n",heap_usage);
	return 0;

}
char *jedi_name(char *first,char *last,char *buffer)
{
	strcpy(buffer,last);
	strcat(buffer,first);
	return buffer;
}
