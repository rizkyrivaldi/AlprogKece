#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

#define jumlahMahasiswa 30

int main() {

	int ABSEN[jumlahMahasiswa];
	int NILAI[jumlahMahasiswa][3];
	int i, j;
	int nilaiMin = 75, nilaiMax = 100;
	int recurse;

	srand(time(0));

	for( i = 0; i < jumlahMahasiswa; i++){
		ABSEN[i] = i+1;
		for(j = 0; j < 3; j++){
			NILAI[i][j] = (rand() % (nilaiMax - nilaiMin + 1)) + nilaiMin;
		}
	}
	
	do{
		system("CLS");
		
		welcomeScreen(10);
        
        printf("Berikut Tabel Data Nilai Mahasiswa:\n");
		system("PAUSE");
	
		printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
	
		for( i = 0; i < jumlahMahasiswa; i++){
			printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n", ABSEN[i], NILAI[i][0], NILAI[i][1], NILAI[i][2]);
		}
		
		system("PAUSE");

		recurse = menu(ABSEN, NILAI, jumlahMahasiswa);
		
	} while(recurse == 1);

	return 0;
}