#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *jedi_name(char *first,char *last,char *buffer);
int main()
{
	char first[2],last[3],name[40],last_name[20],first_name[20],ignore[20];
	/////////////////////////// PART 1.A ////////////////////////////////
	printf("Enter your first name and last name accordingly:\n");
	int count;
	scanf("%2s %s",&first,&ignore);
	if(first[1]=='\0'){last[0]=ignore[0];last[1]=ignore[1];last[2]=ignore[2];last[3]='\0';}
	else scanf("%3s",&last);
	if(first[1]=='\0')first[1]='a';
	if(last[2]=='\0'){if(last[1]=='\0')last[1]='a';}
	char *buffer;
        buffer=malloc(5*sizeof(char));
        buffer=jedi_name(first,last,buffer);
	printf("\nYOUR JEDI NAME:\n%s\n",buffer);
	free(buffer);
	///////////////////////// Part 1.B /////////////////////////////////////
	FILE *ptr1;
	FILE *ptr2;
	ptr1=fopen("names.txt","r");
	FILE *ptr3;
        ptr2=fopen("jedi.txt","w");
	ptr3=fopen("names.txt","r");
	printf("FULL NAME\t\t\t\t\tJEDINAME\n\n");
	int i=0;
	//////////////////////////////////////////////////////////
	while(fgetc(ptr1)!=EOF)
	{
		fseek(ptr1,-1,SEEK_CUR);
		fscanf(ptr1,"%2s",&first);
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
		for(counter=0;counter<20;counter++)last_name[counter]='\0';
        	for(counter=0;comma_pos<strlen(name);comma_pos++)
                	last_name[counter++]=name[comma_pos];
  		/////////////////////seperating first name//////////////////////////
		for(counter=0;counter<20;counter++)first_name[counter]='\0';
                for(counter=0;counter<=space_pos;counter++)
                        if(name[counter]==' ')break;
			else first_name[counter]=name[counter];
		for(counter=0;counter<strlen(first_name);counter++)
			if(first_name[counter]==',')first_name[counter]='\0';
			else if(first_name[counter]=='\0')break;
		/////////////////////////////////////////////////////////

		fscanf(ptr1,"%3s",&last);
		while(fgetc(ptr1)!='\n')
                        continue;

		if(last[2]=='\0')
			{last[2]='a';last[3]='\0';}

		char *buffer;
		buffer=malloc(5*sizeof(char));
		buffer=jedi_name(first,last,buffer);
	 	printf("%d>%s %s\t\t\t\t\t%s\n",++i,first_name,last_name,buffer);
		fprintf(ptr2,"%s\n",buffer);
		free(buffer);
	}
	/////////////////////////////////////////////////////////
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);
	return 0;

}
char *jedi_name(char *first,char *last,char *buffer)
{
strcpy(buffer,last);
strcat(buffer,first);
return buffer;
}
