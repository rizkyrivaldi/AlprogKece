int sequentialSearch(int mahasiswa[], int arraysize, int value){
    int i;
    for(i = 0; i < arraysize; i++){
        if(mahasiswa[i] == value){
            return 1;
        }
    }
    return 0;
}