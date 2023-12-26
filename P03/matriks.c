/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : Jumat,16 September 2022*/
/***********************************/

#include <stdio.h>
#include "matriks.h"

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M){
    /*Kamus lokal*/
    int i,j;

    /*Algoritma*/
    (*M).nbbar = 0;
    (*M).nbkol = 0;
    for(i=1; i<=10;i++){
        for(j=1; j<=10; j++){
            (*M).wadah[i][j] = -999;
        }
    }
}

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
    /*Kamus lokal*/
    
    /*Algoritma*/
    return M.nbbar;
}

/*function getNbkol(M:Matriks)->integer*/
/*{mengembalikan nilai banyak kolom matriks M}*/
int getNbkol(Matriks M){
    /*Kamus lokal*/
    
    /*Algoritma*/
    return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
    /*Kamus lokal*/
    
    /*Algoritma*/
    return M.wadah[X][Y];

}

/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X){
    /*Kamus lokal*/
    
    /*Algoritma*/
    (*M).nbbar = X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y){
    /*Kamus lokal*/
    
    /*Algoritma*/
    (*M).nbkol = Y;
}

/*procedure setInfoCell(input/output M:Matriks,
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C){
    /*Kamus lokal*/
    
    /*Algoritma*/
    (*M).wadah[X][Y] = C;
}

/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M){
    /*Kamus lokal*/
    
    /*Algoritma*/
    return (getNbbar(M)==0 && getNbkol(M)==0);
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M){
    /*Kamus lokal*/
    
    /*Algoritma*/
    return (getNbbar(M)==10 && getNbkol(M)==10);
}

/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
    /*Kamus lokal*/
    int i,j;

    /*Algoritma*/
    for(i=1; i<=getNbbar(M);i++){
        printf("\n");
        for(j=1; j<=getNbkol(M); j++){
            printf("%d ", M.wadah[i][j]);
        }
    }
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M){
    /*Kamus lokal*/
    int i,j;

    /*Algoritma*/
    if(isEmptyMatriks(M)){
        printf("Tabel Kosong");
    }else{
        for(i=1; i<=getNbbar(M);i++){
            printf("\n");
            for(j=1; j<=getNbkol(M); j++){
                if(M.wadah[i][j] != -999){
                    printf("%d ", M.wadah[i][j]);
                }
            }
        }
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
    /*Kamus lokal*/
    int sum,i,j;

    /*Algoritma*/
    sum = 0;
    for(i=1; i<getNbbar(M);i++){
        for(j=1; j<=getNbkol(M); j++){
            if(M.wadah[i][j] != -999 && M.wadah[i][j] != 0){
                sum += M.wadah[i][j];
            }
        }
    }
    return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M){
    /*Kamus lokal*/
    int i,j;
    float sum, temp;

    /*Algoritma*/
    sum = 0; temp=0;
    for(i=1; i<=getNbbar(M);i++){
        for(j=1; j<=getNbkol(M); j++){
            if(M.wadah[i][j] != -999 && M.wadah[i][j] != 0){
                sum += M.wadah[i][j];
                temp++;
            }
        }
    }
    return sum/temp;
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
    /*Kamus lokal*/
    int i, j, max;

    /*Algoritma*/
    max = M.wadah[1][1];
    for(i=1; i<=getNbbar(M); i++){
        for(j=1; j<=getNbkol(M); j++){
            if(M.wadah[i][j] > max){
                max = M.wadah[i][j];
            }
        }
    }
    return max;
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M){
    /*Kamus lokal*/
    int i, j, min;

    /*Algoritma*/
    min = M.wadah[1][1];
    for(i=1; i<=getNbbar(M); i++){
        for(j=1; j<=getNbkol(M);j++){
            if(M.wadah[i][j] < min && M.wadah[i][j] != -999){
                min = M.wadah[i][j];
            }
        }
    }
    return min;
}

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A){
    /*Kamus lokal*/
    int i, j, temp;

    /*Algoritma*/
    temp = 0;
    for(i=1; i<=getNbbar(M); i++){
        for(j=1; j<=getNbkol(M); j++){
            if(M.wadah[i][j] == A){
                temp++;
            }
        }
    }
    return temp;
}

/*procedure searchMatriks(input M:Matriks, input A:integer,
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A, int *X, int *Y){
    /*Kamus lokal*/
    int i,j;

    /*Algoritma*/
    *X = -999;
    *Y = -999;
    for(i=1; i<=getNbbar(M); i++){
        for(j=1; j<=getNbkol(M); j++){
            if(getInfoCell(M, i,j) == A){
                *X = i;
                *Y = j;
            }
        }
    }
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks,
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M){
    /*Kamus lokal*/
    int i,j;
    int temp, temp1; //temp berfungsi sebagai temporary variabel
    //menyimpan value secara sementara

    /*Algoritma*/
    for(i=1; i<=(*M).nbbar; i++){
        for(j=i+1; j<=(*M).nbkol; j++){
            temp = (*M).wadah[i][j];
            (*M).wadah[i][j] = (*M).wadah[j][i];
            (*M).wadah[j][i] = temp;
        }
    }
    temp1 = (*M).nbbar;
    (*M).nbbar = (*M).nbkol;
    (*M).nbkol = temp1;

}