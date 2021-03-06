#ifndef BULLSLIB_H
#define BULLSLIB_H

typedef struct{
	char name[10];
	int steps;
}WinnerL;

void ShuffleArray(int* arr, int N);
int* MakeNum(int* allDigits, int a, int* madeNumber);
int* ReadAnswer(int* guess, char* answer);
int* CheckBullsCows(int *BullsCows, int* guess, int* made);
int load(WinnerL *winner,WinnerL *sortlist);
void sort(WinnerL *sortlist, int n);
int save(WinnerL *sortlist, int n);
#endif
