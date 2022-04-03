void sortKuis(int mahasiswa[][3], int arraysize){
    int temp, i, j;
    int type = 0;
    for(i = 0; i < arraysize; i++){
        for(j = 0; j < arraysize - i - 1; j++){
            if(mahasiswa[type][j] > mahasiswa[type][j+1]){
                temp = mahasiswa[type][j];
                mahasiswa[type][j] = mahasiswa[type][j+1];
                mahasiswa[type][j+1] = temp;
            }
        }
    }
}

void sortUTS(int mahasiswa[][3], int arraysize){
    int temp, i, j;
    int type = 1;
    for(i = 0; i < arraysize; i++){
        for(j = 0; j < arraysize - i - 1; j++){
            if(mahasiswa[type][j] > mahasiswa[type][j+1]){
                temp = mahasiswa[type][j];
                mahasiswa[type][j] = mahasiswa[type][j+1];
                mahasiswa[type][j+1] = temp;
            }
        }
    }
}

void sortUAS(int mahasiswa[][3], int arraysize){
    int temp, i, j;
    int type = 2;
    for(i = 0; i < arraysize; i++){
        for(j = 0; j < arraysize - i - 1; j++){
            if(mahasiswa[type][j] > mahasiswa[type][j+1]){
                temp = mahasiswa[type][j];
                mahasiswa[type][j] = mahasiswa[type][j+1];
                mahasiswa[type][j+1] = temp;
            }
        }
    }
}