#include <stdio.h>
#include <math.h>
int main()
{
	//Hello World
	printf("PART I\n\nHello World\n\nPART II\n");
	//evaluation 
	double x=2.55,y,z;
	y=3*pow(x,3)-5*pow(x,2)+6;
	printf("\nPART A\n\nValue of expression 3x^3-5x^2+6 for x=2.55 : %lf\n",y);
	z=(3.31*pow(10,-8)*2.01*pow(10,-7))/(7.16*pow(10,-6)+2.01*pow(10,-8));
	printf("Value of expression (3.31*10^-8*2.01*10^-7)/(7.16*10^-6+2.01*10^-8) : %g\n",z);

	//roundoff
	int k;
	int next_multiple[3];
	int i[3]={365,12258,996};
	int j[3]={7,28,4};
	for(k=0;k<3;k++)
		{
		next_multiple[k]=i[k]+j[k]-i[k]%j[k];
		printf("\nfor i=%ld and j=%ld next largest even multiple=%ld",i[k],j[k],next_multiple[k]);
		}

	//tempreature
	int c[4]={27,100,32,-40};
	float f[4];
	printf("\n\n");
	for(k=0;k<4;k++)
		{
		f[k]=(float)(c[k]-32)/1.8;
		printf("Tempreature in Celsius = %d and in Fahrenheit = %.2f\n",c[k],f[k]);
		}

	//Part B typecasting
	printf("\n\nPART B\n\n");
	long int large_num=9838263505978427528U;
	int n=(int)large_num;
	double d=(double)large_num;
	char ch=(char)large_num;
	printf("Typecasted values of large number(%lu) in:\nint : %d\ndouble : %f\nchar : %c\n",large_num,n,d,ch);
	
	return 0;
}
