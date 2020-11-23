#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include "BullsLib.h"
int load(WinnerL *winner,WinnerL *sortlist);
int save(WinnerL *sortlist, int n);
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
        
 	
	 	while (BullsCows[0] < 4){ //считывыем ответы, пока пользователь не угадает
       		 	

			while (1){
			fgets(answer, sizeof(answer), stdin);
			guess=ReadAnswer(guess, answer);	
                        for (int i=0; i<4; i++){
			printf("%d", guess[i]);
			}
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
save(sortlist,n);
free(sortlist);
}
// загрузка из файла массива структур
int load(WinnerL *winner,WinnerL *sortlist)
{
   FILE *winlist = NULL;
      
   winlist = fopen("Winlist.txt", "r");
  
    int m = sizeof(int);
    int i=0;
 
    // выделяем память для количества данных
    int *sortnum = (int *)malloc(m);
    
    if (winlist == NULL)
    {
        printf("Error while opening file\n");
        return 1;
    }
   
   while(!feof(winlist)){
		fscanf(winlist,"%s %i", &sortlist[i].name, &sortlist[i].steps);
		if (sortlist[i].name == NULL || sortlist[i].steps == NULL ){
                printf("i=%d\n", i);
		break;
		}
		i++;
	
		if (i==9){
                printf("i=%d\n", i);
		break;
		}
	}
    sortlist[i]=*winner;
    printf("winner i=%d\n", i);
    printf("\n%d people from  the file read\n\n", i);
    for (int k = 0; k<i+1; k++)
    {
        printf("%i %s %i \n", k + 1, sortlist[k].name, sortlist[k].steps);
    }
    //free(sortlist);
  
    fclose(winlist);   
return i+1;
}

int save(WinnerL * sortlist,int  n )
{
    FILE * winlist;   
    if ((winlist = fopen("Winlist.txt", "w")) == NULL)
    {
        printf("Error occured while opening file\n");
        return 1;
    }
    for (int k = 0; k<n; k++){   	
	fprintf(winlist, "%s \n", sortlist[k].name);
	fprintf(winlist, "%i \n", sortlist[k].steps);
	printf("%i %s %i \n", k + 1, sortlist[k].name, sortlist[k].steps);
   }
    fclose(winlist);
    return 0;
}
