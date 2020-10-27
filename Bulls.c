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

	ShuffleArray(allDigits, 10);//перемешиваем
	for (int i = 0; i <= 3; i++) {  //берём 4 первых числа
		madeNumber[i] = allDigits[i];
	}

	for (int i = 0; i <= 3; i++) {
		printf("%d", madeNumber[i]);   //смотрим, что мы загадали
	}
	printf("Hello my friend. I  made a four-digit number. Can you guess it? Test your luck!\n");// выводим строку на консоль
	int guess1; //догадка пользователя
	int guess[4]; //массив для догадки
	char answer[256]; // массив символов для ответа
	while (RightPlaces < 4) { //считывыем ответы, пока пользователь не угадает
		RightDigits = 0; //правильные числа
		RightPlaces = 0; //и на своих местах
		fgets(answer, sizeof(answer), stdin); // считываем строку
		sscanf(answer, "%d", &guess1);

		printf("%d", guess1);
		guess[0] = guess1 / 1000;
		guess[1] = guess1 % 1000 / 100;
		guess[2] = guess1 % 100 / 10;
		guess[3] = guess1 % 10;

		for (int i = 0; i <= 3; i++) {
			if (guess[i] == madeNumber[i]) {
				RightPlaces++;
			}
		}
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				if (madeNumber[i] == guess[j]) {
					repeatedDig++;
				}
			}
			if (repeatedDig > 0) {
				RightDigits++;
				repeatedDig = 0;
			}
		}printf("бла-бла");

		printf("right digits: %d on right places: %d\n", RightDigits, RightPlaces);

	}
	printf("You're great!\n");
	return 0;                   // выходим из функции
}