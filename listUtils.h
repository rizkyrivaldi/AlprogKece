#ifndef LIST_UTILS
#define LIST_UITLS

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void addToList(MAHASISWA **headAddr, int no, int kuis, int uts, int uas){
    MAHASISWA *tempAddr;
    MAHASISWA *iteratorPtr;

    //Create a node
    tempAddr = malloc(sizeof(MAHASISWA));
    (*tempAddr).no = no;
    (*tempAddr).kuis = kuis;
    (*tempAddr).uts = uts;
    (*tempAddr).uas = uas;
    (*tempAddr).ptr = NULL;

    //If list is empty
    if(*headAddr == NULL){
        *headAddr = tempAddr;
    }

    //if list is not empty
    else{
        iteratorPtr = *headAddr;
        while((*iteratorPtr).ptr != NULL){
            iteratorPtr = (*iteratorPtr).ptr;
        }
        (*iteratorPtr).ptr = tempAddr;
    }
}

void freeList(MAHASISWA **headAddr){
    MAHASISWA *iteratorPtr;
    MAHASISWA *prevPtr;

    if(*headAddr == NULL){
        printf("The list is already empty!\n");
    }
    else{
        prevPtr = *headAddr;
        iteratorPtr = (*prevPtr).ptr;
        while(iteratorPtr != NULL){
            (*prevPtr).ptr = NULL;
            free(prevPtr);
            prevPtr = iteratorPtr;
            iteratorPtr = (*iteratorPtr).ptr;
        }
        (*prevPtr).ptr = NULL;
        free(prevPtr);
        *headAddr = NULL;
        printf("The list has been emptied!\n");
    }
    
}

void printRow(MAHASISWA data){
    int absen, kuis, uts, uas;
    absen = data.no;
    kuis = data.kuis;
    uts = data.uts;
    uas = data.uas;
    printf("\t%d\t||\t  %d\t\t||\t  %d\t\t||\t  %d\t\t||\n",absen, kuis, uts, uas);
}

void showDefaultTable(MAHASISWA *headAddr){
    MAHASISWA *iteratorPtr;

    if(headAddr == NULL){
        printf("The list is empty\n");
    }
    else{
        iteratorPtr = headAddr;
        printf(" No. Absen\t||\t Nilai KUIS\t||\t Nilai UTS\t||\t Nilai UAS\t||\n");
        do{
            printRow(*iteratorPtr);
            iteratorPtr = (*iteratorPtr).ptr;
        }while(iteratorPtr != NULL);
    }
}

int lengthList(MAHASISWA *headAddr){
    int length = 0;
    MAHASISWA *iteratorAddr;
    if(headAddr == NULL){
        return length;
    }
    else{
        iteratorAddr = headAddr;
        length += 1; 
        while((*iteratorAddr).ptr != NULL){
            length += 1;
            iteratorAddr = (*iteratorAddr).ptr;
        }
        return length;
    }
}

void swapElement(MAHASISWA *first, MAHASISWA *second){
    int tempNo = (*first).no;
    int tempKuis = (*first).kuis;
    int tempUTS = (*first).uts;
    int tempUAS = (*first).uas;

    (*first).no = (*second).no;
    (*first).kuis = (*second).kuis;
    (*first).uts = (*second).uts;
    (*first).uas = (*second).uas;

    (*second).no = tempNo;
    (*second).kuis = tempKuis;
    (*second).uts = tempUTS;
    (*second).uas = tempUAS;
}

#endif