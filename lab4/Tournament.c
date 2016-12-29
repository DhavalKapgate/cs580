#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Team
{
        char name[10];
	int handicap;
};
					
struct Team *game(struct Team *team1,struct Team *team2);
struct Team *tournament(struct Team *league[8])
{
	////////////////   LEVEL 1 MATCH /////////////////////////////////
        printf("--------------------------------------------------------------\n");
        printf("NORMAL MATCHES:\n--------------------------------------------------------------\n\n");
        struct Team *match_1=game(league[0],league[1]);
        printf("Winner of Match 1 : %s\n\n",match_1->name);

	struct Team *match_2=game(league[2],league[3]);
        printf("Winner of Match 2 : %s\n\n",match_2->name);

        struct Team *match_3=game(league[4],league[5]);
        printf("Winner of Match 3 : %s\n\n",match_3->name);

        struct Team *match_4=game(league[6],league[7]);
        printf("Winner of Match 4 : %s\n\n",match_4->name);
        printf("--------------------------------------------------------------\n");

	///////////////////  SEMIFINAL ////////////////////////////////
        printf("SEMIFINAL:\n--------------------------------------------------------------\n\n");

        struct Team *semi_1_winner=game(match_1,match_2);
        printf("Winner of semifinal 1 : %s\n\n",semi_1_winner->name);

        struct Team *semi_2_winner=game(match_3,match_4);
        printf("Winner of semifinal 2 : %s\n\n",semi_2_winner->name);

        printf("--------------------------------------------------------------\n");

	//////////////////// FINAL //////////////////////////////////////
        printf("FINALS:\n--------------------------------------------------------------\n\n");
        struct Team *final_winner=game(semi_1_winner,semi_2_winner);
        printf("Winner of FINALS : %s\nCONGRATULATIONS %s\n\n",final_winner->name,final_winner->name);
        return final_winner;

}

int main()
{
        struct Team *league[8];
        char name_main[8][10]={"Chandler","Phoebe","Monica","Ross","Joey","Raechal","Gunther","Janice"};
        int counter=0;
        for(;counter<8;counter++)
        {
                league[counter]=malloc(sizeof(struct Team));
                strcpy(league[counter]->name,name_main[counter]);
        }
	league[4]->handicap=1;					//put team Joey as handicap
	league[2]->handicap=1;					//put team monica as handicap
	srand(time(NULL));
        struct Team *winner=tournament(league);
        return 0;
}
struct Team *game(struct Team *team1,struct Team *team2)
{

        int score1,score2,temp;
        score1=rand()%20;
        score2=rand()%20;
	while(score1==score2)
	{
		score1=rand()%20;
	        score2=rand()%20;
	}
	if(team1->handicap==team2->handicap)				//fair game
	{
		printf("Score of Team %s : %d\n",team1->name,score1);
	        printf("Score of Team %s : %d\n",team2->name,score2);
        }
	else if(team1->handicap==1)					//biased to team1
	{
		if(score1<score2){temp=score1;score1=score2;score2=temp;}
		printf("Score of Team %s : %d\n",team1->name,score1);
                printf("Score of Team %s : %d\n",team2->name,score2);

	}
	else  if(team2->handicap==1)					//biased to team2
  	{ 
	    	if(score1>score2){temp=score1;score1=score2;score2=temp;}
		printf("Score of Team %s : %d\n",team1->name,score1);
        	printf("Score of Team %s : %d\n",team2->name,score2);
	}
	if(score1>score2)
                return team1;
        else
                return team2;
}

