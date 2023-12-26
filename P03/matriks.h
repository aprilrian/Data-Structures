/* Program   : matriks.h */
/* Deskripsi : header file modul ADT Matriks */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 16 September 2022 */
/***********************************/
#include <stdio.h>
#include "boolean.h"

/*type Matriks=<wadah:matrix[1..10,1..10]of integer, 
nbbar:integer, nbkol:integer>*/
typedef struct {
  int wadah[11][11]; //penampung cell matriks 10x10
  int nbbar; //banyak baris efektif
  int nbkol; //banyak kolom efektif
} Matriks;
/* cara akses M:Matriks, M.nbbar, M.nbkol */
/* isian cell kosong dinyatakan dengan -999 */

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M);

/*DESTRUKTOR tidak perlu*/

/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M);

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M);

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y);


/*********MUTATOR*/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X);

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y);

/*procedure setInfoCell(input/output M:Matriks, 
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C);

/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M);

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M);

/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M);

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M);

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M);

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M);

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M);

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M);

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A);

/*procedure searchMatriks(input M:Matriks, input A:integer, 
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A, int *X, int *Y);

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks, 
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M);

