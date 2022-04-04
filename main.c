#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "statistik.h"

int menu();

int main() {

	int NILAI[30][3];
	int *grade = (int *)NILAI;
	int KUIS[30], UTS[30], UAS[30];
	int i, j;
	int num, a = 75, b = 100, j;
	int SIZE = sizeof(KUIS)/sizeof(KUIS[0]);
	int recurse;
	
	do{
		system("CLS");
		char title[37] = "==== CLASS GRADE SORTING SYSTEM ====";
        	char desc[33] = "\nSelamat datang di program ini!\n";
        
        for(i = 0; i < 37; i++){
            Sleep(10);
            printf("%c", title[i]);
        }

        printf("\n");
		
        for(i = 0; i < 35; i++){
            Sleep(10);
            printf("%c", desc[i]);
        }

        printf("\n");
        
        printf("Berikut Tabel Data Nilai Mahasiswa:\n");
		system("PAUSE");
		srand(time(0));
	
		printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
	
		for( i = 0; i < SIZE; i++){
				for(j = 0; j < 3; j++){
			num = (rand() % (b - a + 1)) + a;
			NILAI[i][j] = num;
		}
		KUIS[i] = grade[3*i];
		UTS[i] = grade[3*i + 1];
		UAS[i] = grade[3*i + 2];
		printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n", i+1, KUIS[i], UTS[i], UAS[i]);
		}
		
		recurse = menu();
		
	} while(recurse == 1);

}

int menu() {
	int option = 0;
	
    do{
        system("CLS");
        printf("Pilihan Menu: \n");
        printf("\n\t1) Pemeringkatan Mahasiswa\n\t2) Statistik Nilai Kelas\n\t3) Cari Nomor Absen\n\t4) Keluar");
        printf("\n\nPilihan Anda >>> ");
        scanf("%d", &option);

    	switch(option){
        case 1 :
		OpsiPemeringkatan();
		return 1;
		break;
        case 2 :
		OpsiStatistikNilai();
		return 1;
		break;
        case 3 :
		CariNomorAbsen(); 
		return 1;
		break;
        case 4 :
        	return 0;
		break;
	default :
		printf("Pilihan invalid!\n");
        	system("PAUSE");
		break;
    	}
    
    } while(option != 4);

}
