#ifndef STRUCT
#define STRUCT

typedef struct MAHASISWA{
    int no;
    int kuis;
    int uts;
    int uas;
    struct MAHASISWA *ptr;
} MAHASISWA;

#endif