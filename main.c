#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "statistik.h"

int main(){
	int KUIS[30], UTS[30], UAS[30];
	int i, num, num1, num2, a = 75, b = 100, j;
	int SIZE = sizeof(KUIS)/sizeof(KUIS[0]);
	
	//inisialisasi 70 nilai array secara random dari 75--100
	srand(time(0));
	
	printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
	
	for( i = 0; i < SIZE; i++){
		num = (rand() % (b - a + 1)) + a;
		num1 = (rand() % (b - a + 1)) + a;
		num2 = (rand() % (b - a + 1)) + a;
		KUIS[i] = num;
		UTS[i] = num1;
		UAS[i] = num2;
		
		printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n", i+1, KUIS[i], UTS[i], UAS[i]);
	}
	
	
}
