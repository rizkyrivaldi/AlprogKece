#include "struct.h"

void sortNilai(MAHASISWA **headAddr, int type){
    int isSorted;
    MAHASISWA *lastAddr;
    MAHASISWA *iteratorAddr;
    MAHASISWA *nextAddr;
    if(*headAddr == NULL){
        printf("List is empty!");
        return;
    }
    else if(type == 0){
        lastAddr = NULL;
        do{
            isSorted = 1;
            iteratorAddr = *headAddr;
            
            while((*iteratorAddr).ptr != lastAddr){
                nextAddr = (*iteratorAddr).ptr;
                if((*iteratorAddr).kuis < (*nextAddr).kuis){
                    swapElement(iteratorAddr, nextAddr);
                    isSorted = 0;
                }
                iteratorAddr = nextAddr;
            }
            lastAddr = iteratorAddr;
        }while(isSorted == 0);
    }
    else if(type == 1){
        lastAddr = NULL;
        do{
            isSorted = 1;
            iteratorAddr = *headAddr;
            
            while((*iteratorAddr).ptr != lastAddr){
                nextAddr = (*iteratorAddr).ptr;
                if((*iteratorAddr).uts < (*nextAddr).uts){
                    swapElement(iteratorAddr, nextAddr);
                    isSorted = 0;
                }
                iteratorAddr = nextAddr;
            }
            lastAddr = iteratorAddr;
        }while(isSorted == 0);
    }
    else if(type == 2){
        lastAddr = NULL;
        do{
            isSorted = 1;
            iteratorAddr = *headAddr;
            
            while((*iteratorAddr).ptr != lastAddr){
                nextAddr = (*iteratorAddr).ptr;
                if((*iteratorAddr).uas < (*nextAddr).uas){
                    swapElement(iteratorAddr, nextAddr);
                    isSorted = 0;
                }
                iteratorAddr = nextAddr;
            }
            lastAddr = iteratorAddr;
        }while(isSorted == 0);
    }
}

void sortAbsen(MAHASISWA **headAddr){
    int isSorted;
    MAHASISWA *lastAddr;
    MAHASISWA *iteratorAddr;
    MAHASISWA *nextAddr;
    if(*headAddr == NULL){
        printf("List is empty!");
        return;
    }
    else{
        lastAddr = NULL;
        do{
            isSorted = 1;
            iteratorAddr = *headAddr;
            
            while((*iteratorAddr).ptr != lastAddr){
                nextAddr = (*iteratorAddr).ptr;
                if((*iteratorAddr).no > (*nextAddr).no){
                    swapElement(iteratorAddr, nextAddr);
                    isSorted = 0;
                }
                iteratorAddr = nextAddr;
            }
            lastAddr = iteratorAddr;
        }while(isSorted == 0);
    } 
}