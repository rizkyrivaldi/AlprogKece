#include <stdio.h>
#include <windows.h>
#include "statistik.h"
#include "sort.h"
#include "searchAlgo.h"

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

void printTabel(MAHASISWA *headAddr){
	int absen, kuis, uts, uas;
	MAHASISWA *iteratorPtr;
	system("CLS");
	printf("Tabel hasil sorting\n");
	printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
	if(headAddr == NULL){
        printf("The list is empty\n");
    }
	else{
		iteratorPtr = headAddr;
        do{
            absen = (*iteratorPtr).no;
            kuis = (*iteratorPtr).kuis;
            uts = (*iteratorPtr).uts;
            uas = (*iteratorPtr).uas;
            printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n",absen, kuis, uts, uas);
            iteratorPtr = (*iteratorPtr).ptr;
        }while(iteratorPtr != NULL);
	}
	system("PAUSE");
}

void Pemeringkatan(MAHASISWA **headAddr) {
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
				sortNilai(headAddr, 0);
				printTabel(*headAddr);
				sortAbsen(headAddr);
				break;
			case 2 :
				//Cari nomor absen untuk cari peringkat nilai UTS tertinggi
				printf("Hasil pemeringkatan nilai UTS.\n\n");
				sortNilai(headAddr, 1);
				printTabel(*headAddr);
				sortAbsen(headAddr);
				break;
			case 3 :
				//Cari nomor absen untuk cari peringkat nilai UAS tertinggi
				printf("Hasil pemeringkatan nilai UAS.\n\n");
				sortNilai(headAddr, 2);
				printTabel(*headAddr);
				sortAbsen(headAddr);
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

void StatistikNilai(MAHASISWA **headAddr, int listLength) {
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
				sortNilai(headAddr, 0);
				printf("\n Nilai KUIS:");
				printf("\n mean: %.2f", mean(*headAddr, listLength, 0));
				printf("\n median: %.2f", median(*headAddr, listLength, 0));
				printf("\n modus: %.2f", modus(*headAddr, 0));
				sortAbsen(headAddr);
				printf("\n");
				system("PAUSE");
				break;
			case 2 :
				//Print hasil mean, median, modus untuk nilai UTS
				printf("Hasil kalkulasi mean, median dan modus untuk nilai UTS.\n\n");
				sortNilai(headAddr, 1);
				printf("\n Nilai UTS:");
				printf("\n mean: %.2f", mean(*headAddr, listLength, 1));
				printf("\n median: %.2f", median(*headAddr, listLength, 1));
				printf("\n modus: %.2f", modus(*headAddr, 1));
				sortAbsen(headAddr);
				printf("\n");
				system("PAUSE");
				break;
			case 3 :
				//Print hasil mean, median, modus untuk nilai UAS
				printf("Hasil kalkulasi mean, median dan modus untuk nilai UAS.\n\n");
				sortNilai(headAddr, 2);
				printf("\n Nilai UAS:");
				printf("\n mean: %.2f", mean(*headAddr, listLength, 2));
				printf("\n median: %.2f", median(*headAddr, listLength, 2));
				printf("\n modus: %.2f", modus(*headAddr, 2));
				printf("\n");
				sortAbsen(headAddr);
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

void cariNomorAbsen(MAHASISWA **headAddr, int listLength){
	MAHASISWA *iteratorAddr;
	int option;
	int isValid = 0;
	int index;
	int cariMahasiswa;

	//Mengubah linked list ke dalam bentuk array
	int i;
	int *ABSEN = malloc(listLength*sizeof(int));
	int *NILAI = malloc(listLength*3*sizeof(int));

	sortAbsen(headAddr);
	printf("Jumlah Mahasiswa : %d\n", listLength);
	iteratorAddr = *headAddr;
	for(i = 0; i < listLength; i++){
		ABSEN[i] = (*iteratorAddr).no;
		NILAI[i*3 + 0] = (*iteratorAddr).kuis;
		NILAI[i*3 + 1] = (*iteratorAddr).uts;
		NILAI[i*3 + 2] = (*iteratorAddr).uas;
		iteratorAddr = (*iteratorAddr).ptr;
	}

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

				index = binarySearch(ABSEN, 0, listLength, cariMahasiswa);
				if(index==-1){
					printf("Mahasiswa tidak ditemukan!\n");
					system("Pause");
				}
				else{
					printf("\nMahasiswa dengan nomor absen %d mendapatkan nilai: \n", cariMahasiswa);
					printf("Kuis\t: %d\n", NILAI[index*3 + 0]);
					printf("UTS\t: %d\n", NILAI[index*3 + 1]);
					printf("UAS\t: %d\n", NILAI[index*3 + 2]);
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

	free(ABSEN);
	free(NILAI);
}

void inputMahasiswa(MAHASISWA **headAddr, int *jumlahMahasiswa){
	int kuis, uts, uas;
	short isValid;

	//Meminta nilai kuis
	system("CLS");
	printf("Masukkan nilai kuis mahasiswa!\n");
	printf(">>> ");
	do{
		fflush(stdin);
		isValid = scanf("%d", &kuis);
		if(isValid == 0){
			printf("Tidak boleh memasukkan huruf!\n");
			printf(">>> ");
		}
		else if(kuis > 100 || kuis < 0){
			printf("Nilai hanya boleh berada di rentang 0 - 100\n");
			printf(">>> ");
			isValid = 0;
		}
		else{
			isValid = 1;
		}
	}while(isValid == 0);

	//meminta nilai uts
	system("CLS");
	printf("Masukkan nilai UTS mahasiswa!\n");
	printf(">>> ");
	do{
		fflush(stdin);
		isValid = scanf("%d", &uts);
		if(isValid == 0){
			printf("Tidak boleh memasukkan huruf!\n");
			printf(">>> ");
		}
		else if(uts > 100 || uts < 0){
			printf("Nilai hanya boleh berada di rentang 0 - 100\n");
			printf(">>> ");
			isValid = 0;
		}
		else{
			isValid = 1;
		}
	}while(isValid == 0);

	//meminta nilai uas
	system("CLS");
	printf("Masukkan nilai UAS mahasiswa!\n");
	printf(">>> ");
	do{
		fflush(stdin);
		isValid = scanf("%d", &uas);
		if(isValid == 0){
			printf("Tidak boleh memasukkan huruf!\n");
			printf(">>> ");
		}
		else if(uas > 100 || uas < 0){
			printf("Nilai hanya boleh berada di rentang 0 - 100\n");
			printf(">>> ");
			isValid = 0;
		}
		else{
			isValid = 1;
		}
	}while(isValid == 0);

	//menginput nilai pada urutan terakhir linked list
	*jumlahMahasiswa += 1;
	addToList(headAddr, *jumlahMahasiswa, kuis, uts, uas);
	printf("Mahasiswa berhasil dimasukkan!\n");
	system("PAUSE");

}

int menu(MAHASISWA **headAddr, int *jumlahMahasiswa) {
	int option = 0;
	int isValid = 0;
	
    do{
        system("CLS");
		panduanMenu();
        printf("Pilihan Menu: \n");
        printf("\n\t1) Pemeringkatan Mahasiswa\n\t2) Statistik Nilai Kelas\n\t3) Cari Nomor Absen\n\t4) Input Mahasiswa\n\t5) Keluar");
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
				Pemeringkatan(headAddr);
				return 1;
				break;
        	case 2 :
				StatistikNilai(headAddr, *jumlahMahasiswa);
				return 1;
				break;
        	case 3 :
				cariNomorAbsen(headAddr, lengthList(*headAddr)); 
				return 1;
				break;
        	case 4 :
				inputMahasiswa(headAddr, jumlahMahasiswa);
        		return 1;
			break;
			case 5 :
				//Keluar
				return 0;
		default :
			printf("Pilihan invalid!\n");
        		system("PAUSE");
			break;
    	}
    
    } while(option != 5);

}