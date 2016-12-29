#include<stdio.h>
#include<limits.h>

int fibo(int,int,int);
int main()
{	
	//fibbonaci series
	int count=20;
	printf("PART I\n\nFibonnaci series (First 20 elements):\n0 1");
	int fi2=fibo(0,1,count);
	

	printf("\n\nPART II\n");
	int number[6]={2,255,32,-1,INT_MAX,INT_MIN};
	int i,mask;

	printf("\nPART A) BINARY PRINTER\nBINARY VALUE OF %d :\t\t",number[0]);
        for(i=31;i>=0;i--)				//for 2
        {
                mask=1 & (number[0]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");

	printf("BINARY VALUE OF %d :\t\t",number[1]);	//for 255
        for(i=31;i>=0;i--)
        {
                mask=1 & (number[1]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");
	
        printf("BINARY VALUE OF %d :\t\t",number[2]);	//for 32
        for(i=31;i>=0;i--)
        {
                mask=1 & (number[2]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");
	
        printf("BINARY VALUE OF %d :\t\t",number[3]);	//for -1
        for(i=31;i>=0;i--)
        {
                mask=1 & (number[3]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");

        printf("BINARY VALUE OF %d :\t",number[4]);	//for INT_MAX
        for(i=31;i>=0;i--)
        {
                mask=1 & (number[4]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");

        printf("BINARY VALUE OF %d :\t",number[5]);	//for INT_MIN
        for(i=31;i>=0;i--)
        {
                mask=1 & (number[5]>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");
	printf("\nPART B) BINARY VALUE OF A RANDOM NUMBER\nTHE RANDOM NUMBER :\t\t");
	
	int random_num;					
	srand(time(NULL));				//seed random number generator
	random_num = rand() % INT_MAX;			//generate random number
	
	int sign;
	sign = rand()%2;				//generating  sign of number 
	if(sign==1)random_num=(-1)*random_num;		//if sign is 0 its positive else negative
	printf("%d\n",random_num);
        
	printf("BINARY VALUE OF %d :\t",random_num);
        for(i=31;i>=0;i--)				//for random number
        {
                mask=1 & (random_num>>i);
                printf("%d",mask);
                if(i%4==0)printf(" ");
        }
        printf(" \n");

	return 0;
}

int fibo(int fi,int fi1,int count)	//f(ith element) ,f(i+1th element) ,counter
{
	int i;
	for(i=count;i>0;i--)
		{
		fi1=fi+fi1;		//f(i+2)=f(i)+f(i+1) and here we used f(i+1) for f(i+2)
					//so f(i+1)=f(i)+f(i+1)
		fi=fi1-fi;		//f(i)=f(i+1)-f(i) as we to get f(i+1) before the 
					//above command which is now f(i)+f(i+1) so subtract f(i)
		printf(" %d",fi);
		}
	return 0;
}
