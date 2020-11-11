#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>        // подключаем заголовочный файл stdio.h
#include <stdlib.h>  // чтобы пользоваться функцией rand
#include <time.h>
#include <string.h>
#include <stddef.h>

void ShuffleArray(int* arr, int N) //функция для перетасовки элементов массива
{
	srand(time(NULL)); // инициализация генератора случайных чисел
	for (int i = N - 1; i >= 1; i--)// реализация алгоритма перестановки 
	{
		int j = rand() % (i + 1);

		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}

int* MakeNum(int* allDigits, int a, int* madeNumber){

for (int i = 0; i <= a-1; i++) { 
		 madeNumber[i] = allDigits[i];
	}
return madeNumber;
}

int* ReadAnswer(int* guess,char* answer){
char allnum[] = "0123456789";
int guess1;
 // считываем строку

		guess[0] = 0;
		guess[1] = 0;
		guess[2] = 0;
		guess[3] = 0;
// пока не будет считано целое число
		//while ((sscanf(answer, "%d", &guess1) != 1) || strspn(answer, allnum) != 4 || strlen(answer) != 5) {
			if ((sscanf(answer, "%d", &guess1) == 1) && strspn(answer, allnum) < 4 && strlen(answer) < 5) {
				printf("Incorrect input. The number is too small. Try again: \n"); 
				guess[0]=-1;
			}
			else if (strlen(answer) - 1 > strspn(answer, allnum))
			{
				printf("Incorrect input. Input shouldn't contain letters or punctuation marks. Try again: \n");
				guess[0]=-2;
			}
			else if ((sscanf(answer, "%d", &guess1)) == 1 && strspn(answer, allnum) > 4 && strlen(answer) > 5) {
				printf("Incorrect input. The number is too big. Try again: \n"); 
				guess[0]=-3;
			}

			// выводим сообщения об ошибке
			//fgets(answer, sizeof(answer), stdin); // и заново считываем строку
		else if ((sscanf(answer, "%d", &guess1)) == 1 && strspn(answer, allnum) == 4 && strlen(answer) == 5) {
		guess=(int*) calloc(4,sizeof(int));
                guess[0] = guess1 / 1000;
		guess[1] = guess1 % 1000 / 100;
		guess[2] = guess1 % 100 / 10;
		guess[3] = guess1 % 10;
}
return guess;

}

int* CheckBullsCows(int *BullsCows, int* guess, int* made){


int repeatedDig = 0;//Повторяющиеся числа
	int RightDigits = 0;//правильные цифры
	int RightPlaces = 0;//правильные цифры на правильных местах
	
for (int i = 0; i <= 3; i++) {
			if (guess[i] == made[i]) {
				RightPlaces++;
			}
		}
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				if (made[i] == guess[j]) {
					repeatedDig++;
				}
			}
			if (repeatedDig > 0) {
				RightDigits++;
				repeatedDig = 0;
			}
		}
	printf("right digits: %d on right places: %d\n", RightDigits-RightPlaces, RightPlaces);
BullsCows[0] = RightPlaces;
BullsCows[1] = RightDigits-RightPlaces;
return BullsCows;
}

