#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>        // подключаем заголовочный файл stdio.h
#include <stdlib.h>  // чтобы пользоваться функцией rand
#include <time.h>
#include <string.h>
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
int main(void)                  // определяем функцию main
{                               // начало функции
	int madeNumber[4];//Массив для загаданного числа
	int allDigits[] = { 0,1,2,3,4,5,6,7,8,9 };//наш массив с неповторяющимися числами
	int repeatedDig = 0;//Повторяющиеся числа
	int RightDigits = 0;//правильные цифры
	int RightPlaces = 0;//правильные цифры на правильных местах

	ShuffleArray(allDigits, 10);//перемешиваем
	for (int i = 0; i <= 3; i++) {  //берём 4 первых числа
		madeNumber[i] = allDigits[i];
	}
	if (madeNumber[0] == 0) {//перемешиваем, если 0 первый
		ShuffleArray(madeNumber, 4);
	}
	//for (int i = 0; i <= 3; i++) {
	//  printf("%d", madeNumber[i]);   //смотрим, что мы загадали
	//}
	printf("Hello my friend. I  made a four-digit number. Can you guess it? Test your luck!\n");// выводим строку на консоль
	int guess1 = NULL; //догадка пользователя
	int guess[4]; //массив для догадки
	char answer[256]; // массив символов для ответа
	double mistake; //для потенциальной ошибки
	char allnum[] = "0123456789";
	int num = 0;
	while (RightPlaces < 4) { //считывыем ответы, пока пользователь не угадает
		RightDigits = 0; //правильные числа
		RightPlaces = 0; //и на своих местах
		fgets(answer, sizeof(answer), stdin); // считываем строку

// пока не будет считано целое число
		while ((sscanf(answer, "%d", &guess1) != 1) || strspn(answer, allnum) != 4 || strlen(answer) != 5) {
			if ((sscanf(answer, "%d", &guess1) == 1) && strspn(answer, allnum) < 4 && strlen(answer) < 5) {
				printf("Incorrect input. The number is too small. Try again: \n"); printf("String length^ %d , Nums^ %d\n", strlen(answer), strspn(answer, allnum));
			}
			else if (strlen(answer) - 1 > strspn(answer, allnum))
			{
				printf("Incorrect input. Input shouldn't contain letters or punctuation marks. Try again: \n");
				printf("String length^ %d , Nums^ %d\n", strlen(answer), strspn(answer, allnum));
			}
			else if ((sscanf(answer, "%d", &guess1)) == 1 && strspn(answer, allnum) > 4 && strlen(answer) - 1 >= strspn(answer, allnum)) {
				printf("Incorrect input. The number is too big. Try again: \n"); printf("String length^ %d , Nums^ %d\n", strlen(answer), strspn(answer, allnum));
			}

			// выводим сообщения об ошибке
			fgets(answer, sizeof(answer), stdin); // и заново считываем строку
		}
		printf("0 : %c\n", answer[0]);
		printf("1 : %c\n", answer[1]);
		printf("2 : %c\n", answer[2]);
		printf("3 : %c\n", answer[3]);
		printf("4 : %c\n", answer[4]);
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
		}
		printf("right digits: %d on right places: %d\n", RightDigits, RightPlaces);

	}
	printf("You're great!\n");
	return 0;                   // выходим из функции
}
