#ifndef statistik
#define statistik
#include "struct.h"

float mean (MAHASISWA *headAddr, int listLength, int type){
	int n = 0;
	float ave;
	MAHASISWA *iteratorAddr;

	if(headAddr == NULL){
		return 0;
	}
	else if(type == 0){
		iteratorAddr = headAddr;
		while(iteratorAddr != NULL){
			n += (*iteratorAddr).kuis;
			iteratorAddr = (*iteratorAddr).ptr;
		}
	}
	else if(type == 1){
		iteratorAddr = headAddr;
		while(iteratorAddr != NULL){
			n += (*iteratorAddr).uts;
			iteratorAddr = (*iteratorAddr).ptr;
		}
	}
	else if(type == 2){
		iteratorAddr = headAddr;
		while(iteratorAddr != NULL){
			n += (*iteratorAddr).uas;
			iteratorAddr = (*iteratorAddr).ptr;
		}
	}
	ave = (float) n / listLength;
	return ave;
}

float median (MAHASISWA *headAddr, int listLength, int type){
	int i;
	float med;
	MAHASISWA *prevAddr;
	MAHASISWA *iteratorAddr;
	
	if(listLength == 0){
		return 0;
	}
	else if(listLength%2 == 0){

		iteratorAddr = headAddr;
		for(i = 0; i < listLength/2; i++){
			prevAddr = iteratorAddr;
			iteratorAddr = (*iteratorAddr).ptr;
		}

		if(type == 0){
			med = (float) ((*prevAddr).kuis + (*iteratorAddr).kuis)/2;
		}
		else if(type == 1){
			med = (float) ((*prevAddr).uts + (*iteratorAddr).uts)/2;
		}
		else if(type == 2){
			med = (float) ((*prevAddr).uas + (*iteratorAddr).uas)/2;
		}
	}
	else if(listLength%2 == 1){
		iteratorAddr = headAddr;
		for(i = 0; i < listLength/2 + 1; i++){
			prevAddr = iteratorAddr;
			iteratorAddr = (*iteratorAddr).ptr;
		}
		if(type == 0){
			med = (float) (*prevAddr).kuis;
		}
		else if(type == 1){
			med = (float) (*prevAddr).uts;
		}
		else if(type == 2){
			med = (float) (*prevAddr).uas;
		}
	}
	return med;
}

float modus(MAHASISWA *headAddr, int type){
	MAHASISWA *prevAddr = headAddr;
	MAHASISWA *iteratorAddr;
	int count2 = 0, count = 0;
	float mod;
	if(headAddr == NULL){
		return 0;
	}
	else if(type == 0){
		while(prevAddr != NULL){
			count2 = 0;
			iteratorAddr = prevAddr;
			while(iteratorAddr != NULL){
				if((*prevAddr).kuis == (*iteratorAddr).kuis){
					count2++;
				}
				iteratorAddr = (*iteratorAddr).ptr;
			}
			if(count2 > count){
				count = count2;
				mod = (float) (*prevAddr).kuis;
			}
			prevAddr = (*prevAddr).ptr;
		}
	}
	else if(type == 1){
		while(prevAddr != NULL){
			count2 = 0;
			iteratorAddr = prevAddr;
			while(iteratorAddr != NULL){
				if((*prevAddr).uts == (*iteratorAddr).uts){
					count2++;
				}
				iteratorAddr = (*iteratorAddr).ptr;
			}
			if(count2 > count){
				count = count2;
				mod = (float) (*prevAddr).uts;
			}
			prevAddr = (*prevAddr).ptr;
		}
	}
	else if(type == 2){
		while(prevAddr != NULL){
			count2 = 0;
			iteratorAddr = prevAddr;
			while(iteratorAddr != NULL){
				if((*prevAddr).uas == (*iteratorAddr).uas){
					count2++;
				}
				iteratorAddr = (*iteratorAddr).ptr;
			}
			if(count2 > count){
				count = count2;
				mod = (float) (*prevAddr).uas;
			}
			prevAddr = (*prevAddr).ptr;
		}
	}
	return mod;
}

#endif
