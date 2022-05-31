int sequentialSearch(int mahasiswa[][3], int arraysize, int value, int type){
    int i;
    for(i = 0; i < arraysize; i++){
        if(mahasiswa[i][type] == value){
            return 1;
        }
    }
    return 0;
}

int binarySearch(int mahasiswa[], int lowerIndex, int upperIndex, int dicari){
    if (upperIndex >= lowerIndex){
        int middle;
        middle = lowerIndex + ((upperIndex - lowerIndex) / 2);

        if(mahasiswa[middle] == dicari){
            return middle;
        }
        else if(mahasiswa[middle] > dicari){
            return binarySearch(mahasiswa, lowerIndex, middle - 1, dicari);
        }
        else if(mahasiswa[middle] < dicari){
            return binarySearch(mahasiswa, middle + 1, upperIndex, dicari);
        }
    }
    else{
        return -1;
    }
}