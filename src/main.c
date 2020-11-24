#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include "BullsLib.h"

int main(void)                  
{                               
	
	int allDigits[] = { 0,1,2,3,4,5,6,7,8,9 };//наш массив с неповторяющимися числами
	int *madeNumber=NULL;
	int *guess=NULL; //массив для догадки
	int *BullsCows=NULL;
        char *answer=NULL; // массив символов для ответа
	int try = 0;
	 WinnerL * sortlist = (WinnerL *) malloc((11) * sizeof(WinnerL));

	BullsCows=(int*) calloc(2,sizeof(int));
	madeNumber=(int*) calloc(4,sizeof(int));
	guess=(int*) calloc(4,sizeof(int));
	answer=(char*) calloc(256,sizeof(char));
	WinnerL *winner= malloc (sizeof(WinnerL));
	ShuffleArray(allDigits, 10);//перемешиваем
	madeNumber=MakeNum(allDigits, 4, madeNumber);
        printf("Hello my friend. I  made a four-digit number. Can you guess it? Test your luck!\n");// выводим строку на консоль
        printf("Cows - digits that you guessed right, Bulls - right digits ob right places\n");
 	
	 	while (BullsCows[0] < 4){ //считывыем ответы, пока пользователь не угадает
       		 	

			while (1){
			fgets(answer, sizeof(answer), stdin);
			guess=ReadAnswer(guess, answer);	
                        //for (int i=0; i<4; i++){
			//printf("%d", guess[i]);
			//}
			printf("\n");

		        if(guess[0]!=-1&& guess[0]!=-2&&guess[0]!=-3) break;
 			}
			try++;
			BullsCows=CheckBullsCows(BullsCows,guess,madeNumber);
		
		}
	

	printf("You're great! %i\n", try);
	winner->steps = try;

        printf("Enter your name to know your score!\n");
	fgets(winner->name, sizeof(winner->name), stdin);
	
int n=load(winner, sortlist);
sort(sortlist,n);
save(sortlist,n);
free(sortlist);
return 0;
}


