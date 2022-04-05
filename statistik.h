#ifndef statistik
#define statistik

float mean (int mahasiswa[][3], int arraysize, int type){
	int i, n;
	float ave;
	
	for(i; i < arraysize; i++){
		n += mahasiswa[i][type];
	}
	ave = (float) n / arraysize;
	return ave;
}
float median (int mahasiswa[][3], int arraysize, int type){
	if(arraysize%2 == 0){
		float med = (float)(mahasiswa[arraysize/2 - 1][type] + mahasiswa[arraysize/2][type])/2;
	return med;
	}
	else{
		float med = (float)(mahasiswa[arraysize/2][type]+1);
		return med;
	}
}
float modus (int mahasiswa[][3], int arraysize, int type){
	int i, j;
	int count = 0, count2 = 0;
	float mod;
	
	for(i = 0; i < arraysize; i++){
		count2 = 0;
		for(j = 0; j < arraysize; j++){
			if(mahasiswa[j][type] == mahasiswa[i][type]){
				count2++;
			}
		}
		if(count2 > count){
			count = count2;
			mod = 1.0*mahasiswa[i][type];
		}
	}
	return mod;
}

#endif
