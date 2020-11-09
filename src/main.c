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
	BullsCows=(int*) calloc(2,sizeof(int));
	madeNumber=(int*) calloc(4,sizeof(int));
	guess=(int*) calloc(4,sizeof(int));

	ShuffleArray(allDigits, 10);//перемешиваем
	madeNumber=MakeNum(allDigits, 4, madeNumber);
        
 	
	 while (BullsCows[0] < 4){ //считывыем ответы, пока пользователь не угадает
	guess=ReadAnswer(guess);	
		
	BullsCows=CheckBullsCows(BullsCows,guess,madeNumber);
		
		
	}

	printf("You're great!\n");
	return 0;                   // выходим из функции
}
