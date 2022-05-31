#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "listUtils.h"
#include "menu.h"

int main() {
	//Inisialisasi jumlah mahasiswa awal
	int jumlahMahasiswa = 30;

	//Inisialisasi pointer head address
	MAHASISWA *headAddr = NULL;

	//Inisialisasi lainnya
	int i, j;
	int nilaiMin = 75, nilaiMax = 100;
	int recurse;

	//Random seed
	srand(time(0));

	//Memasukkan nilai secara random ke setiap mahasiswa
	for( i = 0; i < jumlahMahasiswa; i++){
		int kuis = (rand() % (nilaiMax - nilaiMin + 1)) + nilaiMin;
		int uts = (rand() % (nilaiMax - nilaiMin + 1)) + nilaiMin;
		int uas = (rand() % (nilaiMax - nilaiMin + 1)) + nilaiMin;
		addToList(&headAddr, i+1, kuis, uts, uas);
	}
	
	do{
		system("CLS");
		
		welcomeScreen(10);
        
        printf("Berikut Tabel Data Nilai Mahasiswa:\n");
		system("PAUSE");
	
		showDefaultTable(headAddr);
		
		system("PAUSE");

		recurse = menu(&headAddr, &jumlahMahasiswa);
		
	} while(recurse == 1);

	freeList(&headAddr);

	return 0;
}