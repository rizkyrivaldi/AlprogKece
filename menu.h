#include <stdio.h>
#include <windows.h>
#include "statistik.h"
#include "sort.h"
#include "searchAlgo.h"

void welcomeScreen(int delay);
void panduanMenu();
void printTabel(int ABSEN[], int NILAI[][3], int arraySize);
void Pemeringkatan(int ABSEN[], int NILAI[][3], int arraySize);
void StatistikNilai(int ABSEN[], int NILAI[][3], int arraySize);
void cariNomorAbsen(int ABSEN[], int NILAI[][3], int arraySize);
int menu(int ABSEN[], int NILAI[][3], int arraySize);


void welcomeScreen(int delay){
	int i;
	char title[37] = "==== CLASS GRADE SORTING SYSTEM ====";
    char desc[33] = "\nSelamat datang di program ini!\n";
        
	for(i = 0; i < 37; i++){
		Sleep(delay);
		printf("%c", title[i]);
	}

	printf("\n");
	
	for(i = 0; i < 33; i++){
		Sleep(delay);
		printf("%c", desc[i]);
	}

	printf("\n");
}

void panduanMenu(){
	printf("Program ini akan menyortir seluruh nilai mahasiswa yang mencakup KUIS, UTS, dan UAS dengan beberapa pilihan metode.\n");
	printf("\nPilihan pertama akan melakukan pemeringkatan nilai mahasiswa berdasarkan jenis ujiannya dengan metode bubble sort.\n");
	printf("\nPilihan kedua akan menampilkan statistik nilai mahasiswa yang meliputi mean, modus, dan median.\n");
	printf("\nPilihan ketiga akan melakukan pencarian nomor absen untuk mengetahui nilai mahasiswa tersebut.\n");
	printf("\nPilihan keempat akan mengakhiri program.\n\n");
}

void printTabel(int ABSEN[], int NILAI[][3], int arraySize){
	int i;
	system("CLS");
	printf("Tabel hasil sorting\n");
	printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
	for( i = 0; i < arraySize; i++){
		printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n", ABSEN[i], NILAI[i][0], NILAI[i][1], NILAI[i][2]);
	}
	system("PAUSE");
}

void Pemeringkatan(int ABSEN[], int NILAI[][3], int arraySize) {
	int option;
	int isValid = 0;
	
	do{
		system("CLS");
		printf("Pilihlah salah satu dari ketiga jenis pemeringkatan yang diinginkan dengan menginput angka 1, 2, atau 3.\n");
		printf("\nInput angka 4 untuk mengakhiri program.\n");
		printf("\n\nJenis Pemeringkatan Nilai Kelas: \n");
		printf("\n\t1) Nilai Kuis\n\t2) Nilai UTS\n\t3) Nilai UAS\n\t4) Kembali ke menu");
		printf("\n\nPilihan Anda >>> ");

		do{
			fflush(stdin);
			isValid = scanf("%d", &option);
			if(isValid==0){
				printf("Tidak boleh memasukkan huruf!\n");
				printf("\n\nPilihan Anda >>> ");
				isValid = 0;
			}
			else{
				isValid = 1;
			}
		}while(isValid==0);
		
		switch(option) {
			case 1 : 
				//Cari nomor absen untuk cari peringkat nilai KUIS tertinggi
				printf("Hasil pemeringkatan nilai KUIS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 0);
				printTabel(ABSEN, NILAI, arraySize);
				sortAbsen(ABSEN, NILAI, arraySize);
				break;
			case 2 :
				//Cari nomor absen untuk cari peringkat nilai UTS tertinggi
				printf("Hasil pemeringkatan nilai UTS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 1);
				printTabel(ABSEN, NILAI, arraySize);
				sortAbsen(ABSEN, NILAI, arraySize);
				break;
			case 3 :
				//Cari nomor absen untuk cari peringkat nilai UAS tertinggi
				printf("Hasil pemeringkatan nilai UAS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 2);
				printTabel(ABSEN, NILAI, arraySize);
				sortAbsen(ABSEN, NILAI, arraySize);
				break;
			case 4 :
				break;
			default :
				printf("Pilihan invalid!\n");
        			system("PAUSE");
			break;
		}
	} while(option != 4);
}

void StatistikNilai(int ABSEN[], int NILAI[][3], int arraySize) {
	int option;
	int isValid = 0;
	
	do{
		system("CLS");
		printf("Pilihlah salah satu dari ketiga jenis statistik nilai kelas yang diinginkan dengan menginput angka 1, 2, atau 3\n");
		printf("\nInput angka 4 untuk mengakhiri program.\n");
		printf("\n\nJenis Statistik Nilai Kelas: \n");
		printf("\n\t1) Nilai Kuis\n\t2) Nilai UTS\n\t3) Nilai UAS\n\t4) Kembali ke menu");
		printf("\n\nPilihan Anda >>> ");

		do{
			fflush(stdin);
			isValid = scanf("%d", &option);
			if(isValid==0){
				printf("Tidak boleh memasukkan huruf!\n");
				printf("\n\nPilihan Anda >>> ");
				isValid = 0;
			}
			else{
				isValid = 1;
			}
		}while(isValid==0);
		
		switch(option) {
			case 1 :
				//Print hasil mean, median, modus untuk nilai KUIS
				printf("Hasil kalkulasi mean, median dan modus untuk nilai KUIS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 0);
				printf("\n Nilai KUIS:");
				printf("\n mean: %.2f", mean(NILAI, arraySize, 0));
				printf("\n median: %.2f", median(NILAI, arraySize, 0));
				printf("\n modus: %.2f", modus(NILAI, arraySize, 0));
				sortAbsen(ABSEN, NILAI, arraySize);
				printf("\n");
				system("PAUSE");
				break;
			case 2 :
				//Print hasil mean, median, modus untuk nilai UTS
				printf("Hasil kalkulasi mean, median dan modus untuk nilai UTS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 1);
				printf("\n Nilai UTS:");
				printf("\n mean: %.2f", mean(NILAI, arraySize, 1));
				printf("\n median: %.2f", median(NILAI, arraySize, 1));
				printf("\n modus: %.2f", modus(NILAI, arraySize, 1));
				sortAbsen(ABSEN, NILAI, arraySize);
				printf("\n");
				system("PAUSE");
				break;
			case 3 :
				//Print hasil mean, median, modus untuk nilai UAS
				printf("Hasil kalkulasi mean, median dan modus untuk nilai UAS.\n\n");
				sortNilai(ABSEN, NILAI, arraySize, 2);
				printf("\n Nilai UAS:");
				printf("\n mean: %.2f", mean(NILAI, arraySize, 2));
				printf("\n median: %.2f", median(NILAI, arraySize, 2));
				printf("\n modus: %.2f", modus(NILAI, arraySize, 2));
				printf("\n");
				sortAbsen(ABSEN, NILAI, arraySize);
				system("PAUSE");
				break;
			case 4 :
				//do nothing
				break;
			default :
				printf("Pilihan invalid!\n");
        			system("PAUSE");
			break;
		}
	} while (option != 4);
}

void cariNomorAbsen(int ABSEN[], int NILAI[][3], int arraySize){
	int option;
	int isValid = 0;
	int index;
	int cariMahasiswa;

	do{
		system("CLS");
		printf("Input angka 1 agar program melakukan pencarian nomor absen tiap mahasiswa.\n");
		printf("\nInput angka 2 untuk mengakhiri program.\n");
		printf("\nMencari nilai dari nomor absen mahasiswa: \n1.) Cari nomor absen mahasiswa\n2.) Kembali ke menu");
		printf("\n\nPilihan Anda >>> ");

		do{
			fflush(stdin);
			isValid = scanf("%d", &option);
			if(isValid==0){
				printf("Tidak boleh memasukkan huruf!\n");
				printf("\n\nPilihan Anda >>> ");
				isValid = 0;
			}
			else{
				isValid = 1;
			}
		}while(isValid==0);
		
		switch(option) {
			case 1 :
				//Print nilai mahasiswanya
				do{
					printf("Masukkan nomor absen Mahasiswa yang ingin dicari!\n");
					printf(">>> ");
					fflush(stdin);
					isValid = scanf("%d", &cariMahasiswa);
					if(isValid==0){
						printf("Tidak boleh memasukkan huruf!\n");
						printf("\n\nPilihan Anda >>> ");
						isValid = 0;
					}
					else{
						isValid = 1;
					}
				}while(isValid==0);
				printf("\n");

				sortAbsen(ABSEN, NILAI, arraySize);
				index = binarySearch(ABSEN, 0, arraySize, cariMahasiswa);
				if(index==-1){
					printf("Mahasiswa tidak ditemukan!");
					system("Pause");
				}
				else{
					printf("\nMahasiswa dengan nomor absen %d mendapatkan nilai: \n", cariMahasiswa);
					printf("Kuis\t: %d\n", NILAI[index][0]);
					printf("UTS\t: %d\n", NILAI[index][1]);
					printf("UAS\t: %d\n", NILAI[index][2]);
					printf("\n");
					system("PAUSE");
				}
				break;
			case 2 :
				//do nothing
				break;
			default :
				printf("Pilihan invalid!\n");
        			system("PAUSE");
			break;
		}
	} while (option != 2);
}

int menu(int ABSEN[], int NILAI[][3], int arraySize) {
	int option = 0;
	int isValid = 0;
	
    do{
        system("CLS");
		panduanMenu();
        printf("Pilihan Menu: \n");
        printf("\n\t1) Pemeringkatan Mahasiswa\n\t2) Statistik Nilai Kelas\n\t3) Cari Nomor Absen\n\t4) Keluar");
        printf("\n\nPilihan Anda >>> ");

		do{
			fflush(stdin);
			isValid = scanf("%d", &option);
			if(isValid==0){
				printf("Tidak boleh memasukkan huruf!\n");
				printf("\n\nPilihan Anda >>> ");
				isValid = 0;
			}
			else{
				isValid = 1;
			}
		}while(isValid==0);

    	switch(option){
        	case 1 :
				Pemeringkatan(ABSEN, NILAI, arraySize);
				return 1;
				break;
        	case 2 :
				StatistikNilai(ABSEN, NILAI, arraySize);
				return 1;
				break;
        	case 3 :
				cariNomorAbsen(ABSEN, NILAI, arraySize); 
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
