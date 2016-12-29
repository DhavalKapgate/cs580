#include<stdio.h>
struct time
{
	int hours;
	int minutes;
	int seconds;
};
enum months
{January,February,March,April,May,June,July,August,September,October,November,December};
struct DateTime
{
	struct time Time;
	int day;
	int year;
	enum months month;
};

void timedisplay(struct time Time)
{
	printf("Hours : %d\t",Time.hours);
	printf("Minutes : %d\t",Time.minutes);
	printf("Seconds : %d\t",Time.seconds);
};
int numSeconds(int hours, int minutes, int seconds);
struct time timeDiff(int time1,int time2);
int main()
{
	printf("PART A : Time Difference\n\n");
	struct time time1;
	time1.hours=3;
	time1.minutes=45;
	time1.seconds=15;
	int totaltime1=numSeconds(time1.hours,time1.minutes,time1.seconds);
	printf("For time 1:\n");
	timedisplay(time1);
	printf("In Seconds : %d\n",totaltime1);

	struct time time2;
	time2.hours=9;
        time2.minutes=44;
        time2.seconds=3;
	int totaltime2=numSeconds(time2.hours,time2.minutes,time2.seconds);
        printf("For time 2:\n");
	timedisplay(time2);
	printf("In Seconds : %d\n",totaltime2);

	struct time timediff=timeDiff(totaltime1,totaltime2);
	printf("Time difference:\n");
	timedisplay(timediff);
	printf("\n");

	int time_arr1[]={1,30,45,1,23,01,0,1,1,12,0,0};
	int time_arr2[]={16,30,45,12,11,12,23,59,59,12,0,0};
	int counter;
	for(counter=0;counter<13;counter++)
	{
		time1.hours=time_arr1[counter];
		time2.hours=time_arr2[counter++];

	        time1.minutes=time_arr1[counter];
        	time2.minutes=time_arr2[counter++];

		time1.seconds=time_arr1[counter];
		time2.seconds=time_arr2[counter];

		totaltime1=numSeconds(time1.hours,time1.minutes,time1.seconds);
        	printf("For time 1:\n");
        	timedisplay(time1);
       		printf("In Seconds : %d\n",totaltime1);

		totaltime2=numSeconds(time2.hours,time2.minutes,time2.seconds);
        	printf("For time 2:\n");
        	timedisplay(time2);
        	printf("In Seconds : %d\n",totaltime2);

		timediff=timeDiff(totaltime1,totaltime2);
	        printf("Time difference:\n");
        	timedisplay(timediff);
		printf("\n\n");
	}

///////////////////////////////////////////////////////////////////////////

	printf("PART B\n\n");
	struct DateTime datetime[3];

	datetime[0].month=January;
	datetime[0].day=19;
	datetime[0].year=1809;
	datetime[0].Time.hours=12;
	datetime[0].Time.minutes=1;

	datetime[1].month=November;
	datetime[1].day=11;
        datetime[1].year=1922;
        datetime[1].Time.hours=6;
        datetime[1].Time.minutes=0;

	datetime[2].month=January;
	datetime[2].day=6;
        datetime[2].year=2000;
        datetime[2].Time.hours=8;
        datetime[2].Time.minutes=22;

	for(counter=0;counter<3;counter++)
	{
		switch(datetime[counter].month)
		{
		case 0:printf("January ");break;
		case 1:printf("February ");break;
		case 2:printf("March ");break;
		case 3:printf("April ");break;
                case 4:printf("May ");break;
                case 5:printf("June ");break;
		case 6:printf("July ");break;
                case 7:printf("August ");break;
                case 8:printf("September ");break;
                case 9:printf("October ");break;
                case 10:printf("November ");break;
                case 11:printf("December ");break;
		}
		printf("%d %d %02d:%02d\n",datetime[counter].day,datetime[counter].year,datetime[counter].Time.hours,datetime[counter].Time.minutes);
	}
///////////////////////////////////////////////////////////////////////////
	return 0;
}
int numSeconds(int hours, int minutes, int seconds)
{
	int total=(hours*60*60)+(minutes*60)+seconds;
	return total;
}
struct time timeDiff(int time1,int time2)
{
	int diff=time1-time2;
	if(diff<0)diff=(-diff);
	struct time timediff;
	timediff.hours=diff/3600;
	diff=diff-(timediff.hours*3600);
	timediff.minutes=diff/60;
	diff=diff-(timediff.minutes*60);
	timediff.seconds=diff;
	return timediff;
}
