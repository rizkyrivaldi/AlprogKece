#ifndef statistik
#define statistik

float mean (int mahasiswa[], int arraysize){
		int i, n;
	float ave;
	
	for(i; i < b; i++){
		n += a[i];
	}
	ave = (float) n / b;
	return ave;
}
float median (int mahasiswa[], int arraysize){
	if(arraysize%2 == 0){
		float med = (float)(mahasiswa[arraysize/2 - 1] + mahasiswa[arraysize/2])/2;
	return med;
	}
	else{
		float med = (float)(mahasiswa[arraysize/2]);
		return med;
	}
}
float modus (int mahasiswa[], int arraysize){
	int i, j;
	int count = 0, count2 = 0;
	float mod
	
	for(i = 0; i < arraysize; i++){
		count2 = 0;
		for(j = 0; j < arraysize; j++){
			if(mahasiswa[j] == mahasiswa[i]){
				count2++;
			}
		}
		if(count2 > count){
			count = count2;
			mod = 1.0*mahasiswa[i];
		}
	}
	return mod;
}

#endif
