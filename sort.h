void sortNilai(int absen[], int mahasiswa[][3], int arraySize, int type){
    int temp, i, j;
    for(i = 0; i < arraySize; i++){
        for(j = 0; j < arraySize - i - 1; j++){
            if(mahasiswa[j][type] < mahasiswa[j+1][type]){

                //sort nomor absen, nilai kuis, nilai uts, dan nilai uas
                temp = absen[j];
                absen[j] = absen[j+1];
                absen[j+1] = temp;

                temp = mahasiswa[j][0];
                mahasiswa[j][0] = mahasiswa[j+1][0];
                mahasiswa[j+1][0] = temp;

                temp = mahasiswa[j][1];
                mahasiswa[j][1] = mahasiswa[j+1][1];
                mahasiswa[j+1][1] = temp;

                temp = mahasiswa[j][2];
                mahasiswa[j][2] = mahasiswa[j+1][2];
                mahasiswa[j+1][2] = temp;
            }
        }
    }
}

void sortAbsen(int absen[], int mahasiswa[][3], int arraySize){
    int temp, i, j;
    for(i = 0; i < arraySize; i++){
        for(j = 0; j < arraySize - i - 1; j++){
            if(absen[j] > absen[j+1]){

                //sort nomor absen, nilai kuis, nilai uts, dan nilai uas
                temp = absen[j];
                absen[j] = absen[j+1];
                absen[j+1] = temp;

                temp = mahasiswa[j][0];
                mahasiswa[j][0] = mahasiswa[j+1][0];
                mahasiswa[j+1][0] = temp;

                temp = mahasiswa[j][1];
                mahasiswa[j][1] = mahasiswa[j+1][1];
                mahasiswa[j+1][1] = temp;

                temp = mahasiswa[j][2];
                mahasiswa[j][2] = mahasiswa[j+1][2];
                mahasiswa[j+1][2] = temp;
            }
        }
    } 
}