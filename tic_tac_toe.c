//Tic Tac Toe Game using C Programming Language

#include<stdio.h>
#include<conio.h>
#include<string.h>

void gameboard(char bd[]);
void play(char bd[], char name1[50],char name2[50]);
int win(char bd[]);
void system();

int main(){
	char bd[] = {'0','1','2','3','4','5','6','7','8','9'};
	gameboard(bd);
	char p1[50], p2[50];
	printf("\nEnter the name of Player 1 : ");
	scanf("%s",&p1);
	printf("Enter the name of Player 2 : ");
	scanf("%s",&p2);
	play(bd,p1,p2);
	return 0;
}

//A function to print the gameboard
void gameboard(char bd[])
{
	system("cls");
	printf("\n***** TIC TAC TOE BOARD *****\n");
	printf("    |    |    \n");
	printf(" %c  | %c  |  %c \n",bd[1],bd[2],bd[3]);
	printf("____|____|____\n");
	printf("    |    |	  \n");
	printf(" %c  | %c  |  %c \n",bd[4],bd[5],bd[6]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf(" %c  | %c  |  %c \n",bd[7],bd[8],bd[9]);
	printf("    |    |    \n");
	
}

void play(char bd[],char name1[50],char name2[50])
{
	printf("\n X is allocated to player named %s",name1);
	printf("\n O is allocated to player named %s",name2);
	char player[50];
	int input,count=1,status=-1;
	while(status==-1){
		(count%2!=0) ? strcpy(player,name1): strcpy(player,name2);
		char mark=((strcmp(player,name1))==0)?'X':'O';
		printf("\n\nEnter the value for %s from the board : ",player);
		scanf("%d",&input);
		if(input<1 || input>9){
			printf("Invalid Input!");
		}
		bd[input] = mark ;
		gameboard(bd);
		int result = win(bd);
		if(result==1)
		{
			printf("The Winner is %s .",player);
			system("pause");
			break;
		}
		else if(result==0)
		{
			printf("Game Tied");
			break;
		}
		count+=1;
	}
}

int win(char bd[])
{	
	//Checking game win for Rows.
	if(bd[1]==bd[2]&&bd[1]==bd[3])
		return 1;
	if(bd[4]==bd[5]&&bd[4]==bd[6])
		return 1;
	if(bd[7]==bd[8]&&bd[7]==bd[9])
		return 1;
	//Checking Game Win for Columns.
	if(bd[1]==bd[4]&&bd[1]==bd[7])
		return 1;
	if(bd[2]==bd[5]&&bd[2]==bd[8])
		return 1;
	if(bd[3]==bd[6]&&bd[3]==bd[9])
		return 1;
	//Checking Game Win For Diagonals
	if(bd[1]==bd[5]&&bd[1]==bd[9])
		return 1;
	if(bd[3]==bd[5]&&bd[7]==bd[3])
		return 1;
	
	//Checking for draw Condition 
	int counter=0;
	for(int i=1;i<=9;i++)
	{
		if(bd[i]=='X'|| bd[i]=='O')
		{
			counter++;
		}
	}
	if(counter==9)
	{
		return 0;
	}
	return -1;
}