/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 16 September 2022 */
/***********************************/
#include <stdio.h>
#include "matriks.h"

int main() 
{
	/*Kamus Lokal*/
	Matriks A;
	int X, Y;
	/*Algoritma*/
	printf("Tabel A\n");
	makeMatriks(&A);
	setNbbar(&A,3);
	setNbkol(&A,4);
	
	setInfoCell(&A, 1, 1, 2);
	setInfoCell(&A, 1, 2, 4);
	setInfoCell(&A, 2, 3, 10);
	setInfoCell(&A, 3, 1, 12);
	printf("Elemen ke [1][1] = %d\n", A.wadah[1][1]);
	
	if (isEmptyMatriks(A)){
	    printf("Tabel kosong\n");
	} else {
	    printf("Tabel tidak kosong\n");
	}
	
	if (isFullMatriks(A)){
	    printf("Tabel penuh\n");
	} else {
	    printf("Tabel tidak penuh\n");
	}
	
	printMatriks(A);
	printf("\n------------------------------------\n");
	viewMatriks(A);
	sumCellMatriks(A);
	avgCellMatriks(A);
	maxCellMatriks(A);
	minCellMatriks(A);
	countA(A,3);
	searchMatriks(A, 3, &X, &Y);
	transpose(&A);
	
	return 0;
}