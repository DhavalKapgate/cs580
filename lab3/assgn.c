
#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define EQUAL ==

#if TRUE
#define DEBUG(x) fprintf(stderr,"DEBUG: LINE NUMBER: %d STRING: %s\n",__LINE__,x) 
#define TRACE fprintf(stderr,"TRACE:%d\n\n", __LINE__)
#else
#define DEBUG(x)
#define TRACE
#endif
int myStrStr (char  haystack[], char needle[], char buffer[]);
char* match(char  haystack[], char needle[], char buffer[], int position); 
int main(int argc, char *argv)
{	
	printf("PART 1\nSETTING UP MACRO AND DEFINE\n");
	printf("\nDEBUG MODE ON\n");
	DEBUG("HELLO");
	TRACE;
	////////////////////////////////////////////////////
     	printf("PART 2\nSTRING MANIPULATION\n");
	char haystack[100],needle[100],buffer[100]={0};
	int found;

	printf("\n1) Haystack : apple\tNeedle : app\n");
	found=myStrStr("apple","app",buffer);
        if(found EQUAL 0)
		printf("NEEDLE FOUND\n");
        else    
		printf("NEEDLE NOT FOUND\n");

	printf("\n2) Haystack : orange\tNeedle : ge\n");
        found=myStrStr("orange","ge",buffer);
        if(found EQUAL 0)
		printf("NEEDLE FOUND\n");
        else    
		printf("NEEDLE NOT FOUND\n");

	printf("\n3) Haystack : blueberry\tNeedle : ueber\n");
        found=myStrStr("blueberry","ueber",buffer);
        if(found EQUAL 0)
		printf("NEEDLE FOUND\n");
        else    
		printf("NEEDLE NOT FOUND\n");

	printf("\n4) Haystack : strawberry\tNeedle : strawberry\n");
        found=myStrStr("strawberry","strawberry",buffer);
        if(found EQUAL 0)
		printf("NEEDLE FOUND\n");
        else    
		printf("NEEDLE NOT FOUND\n");

	printf("\n1) Haystack : grapefruit\tNeedle : terrible\n");
        found=myStrStr("grapefruit","terrible",buffer);
        if(found EQUAL 0)
		printf("NEEDLE FOUND\n");
        else    
		printf("NEEDLE NOT FOUND\n");


	printf("\nENTER\nhaystack : ");
	scanf("%[^\n]%*c",haystack);
	printf("needle : ");
	scanf("%[^\n]%*c",needle);
	found=myStrStr(haystack,needle,buffer);
	if(found EQUAL 0)
		printf("\nNEEDLE FOUND\n");
	else	
		printf("\nNEEDLE NOT FOUND\n");
	return 0;
}


int myStrStr(char haystack[],char needle[],char buffer[])
{
	int hay_position;
	for(hay_position=0;hay_position<strlen(haystack);hay_position++)
	{	
		if(needle[0] EQUAL haystack[hay_position])
			match(haystack,needle,buffer,hay_position);
		if(buffer[strlen(needle)-1]!=needle[strlen(needle)-1])
		{int counter=0;
		while(counter<100)buffer[counter++]=0;
		}
	}
	printf("\nHAYSTACK : %s\nNEEDLE : %s\nBUFFER : %s\n",haystack,needle,buffer);
	if(buffer[strlen(needle)-1]!=needle[strlen(needle)-1])
		return 1;
	else return 0;
}

char* match(char haystack[], char needle[], char buffer[], int position)
{
	int needle_position,haystack_position,buffer_pos=0;
	 for(needle_position=0;needle_position<strlen(needle);needle_position++)
                for(haystack_position=position;haystack_position<strlen(needle)+position;haystack_position++)
                {	
			if(needle[needle_position] EQUAL haystack[haystack_position])
			{
				buffer[buffer_pos]=haystack[haystack_position];
				needle_position++;
				buffer_pos++;
			}
			else
				return 0;
               }
	return buffer;
}
