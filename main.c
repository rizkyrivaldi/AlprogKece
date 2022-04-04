#include <stdio.h>
#include <stdlib.h>
#indlude <time.h>
#include "statistik.h"

int main(){
	int array[70];
	int i, num, a = 75, b = 100, j;
	int SIZE = sizeof(array)/sizeof(array[0]);
	
	//inisialisasi 70 nilai array secara random dari 75--100
	srand(time(0));
	
	for( i = 0; i < SIZE; i++){
		num = (rand() % (b - a + 1)) + a;
		array[i] = num;
		printf(" %d ", array[i]);
	}
}
