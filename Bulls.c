#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>       
#include <stdlib.h>  
#include <time.h>

void ShuffleArray(int* arr, int N) 
{
	srand(time(NULL)); 
	for (int i = N - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);

		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}
int main(void)                  
{                               
	int madeNumber[4];//Массив для загаданного числа
	int allDigits[] = { 0,1,2,3,4,5,6,7,8,9 };//наш массив с неповторяющимися числами
	int repeatedDig = 0;
	int RightDigits = 0;
	int RightPlaces = 0;

	ShuffleArray(allDigits, 10);
	for (int i = 0; i <= 3; i++) {  
		madeNumber[i] = allDigits[i];
	}
	
	for (int i = 0; i <= 3; i++) {
         printf("%d", madeNumber[i]);   //смотрим, что мы загадали
	}
