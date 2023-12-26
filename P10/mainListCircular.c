/* Nama : Aprilyanto Setiyawan Siburian*/
/* NIM  : 240601211120022*/
/* contoh ADT list circular */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listCircular.c"

int main()
{
/*Kamus*/
    List A, B;
    address P, P1, P2, P3, P4, Prec, Last;
    infotype X;

/*Algoritma*/
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||PROGRAM LIST CIRCULAR|||||||||||||||||||||\n");
	printf("|||||||||||||||Aprilyanto SS / 24060121120022||||||||||||||||\n\n");


    //CreateList
	printf("--------Membuat List A--------\n");
	CreateList(&A);
	printf("Apakah List Kosong? = %d", ListEmpty(A));

	//Insert
	printf("\n--------Penambahan Elemen Berdasarkan Alamat--------\n");
	P1 = Alokasi(21);
    InsertFirst(&B, P1);
    PrintInfo(B);
    printf("\n======\tInsert First\t======\n");
    P2 = Alokasi(22);
    InsertFirst(&B, P2);
    PrintInfo(B);
    printf("\n======\tInsert After\t======\n");
    P3 = Alokasi(23);
    Prec = First(B);
    InsertAfter(&B, P3, Prec);
    PrintInfo(B);
    printf("\n======\tInsert Last\t======\n");
    P4 = Alokasi(24);
    InsertLast(&B, P4);
    PrintInfo(B);
    printf("\n");
    printf("Jumlah elemen = %d\n", NbElmt(B));

	printf("\n--------Penambahan Elemen Berdasarkan Nilai--------\n");
	InsVFirst(&A,35);
	PrintInfo(A);
	printf("\n======\tInsVFirst\t======\n");
	InsVFirst(&A,25);
	PrintInfo(A);
	printf("\n======\tInsVAfter\t======\n");
	InsVAfter(&A,15,25);
	PrintInfo(A);
	InsVAfter(&A,55,15);
	PrintInfo(A);
	printf("\n======\tInsVLast\t======\n");
	InsVLast(&A,65);
	PrintInfo(A);
	InsVLast(&A,45);
	PrintInfo(A);
	printf("\n");
    printf("Jumlah elemen = %d\n", NbElmt(A));

	//Delete
	printf("\n--------Penghapusan elemen Berdasarkan Alamat--------\n");
	printf ("List B sebelum dihapus : ");
	PrintInfo(B);
	printf("\n======\tDelete First\t======\n");
    DelFirst(&B, &P);
    printf("Nilai yang dihapus = %d\n", info(P));
    PrintInfo(B);
    printf("\n======\tDelete Last\t======\n");
    DelLast(&B, &Last);
    printf("Nilai yang dihapus = %d\n", info(Last));
    PrintInfo(B);
    printf("\n======\tDelete After\t======\n");
    Prec = First(B);
    DelAfter(&B, &P, Prec);
    printf("Nilai yang dihapus = %d\n", info(P));
    PrintInfo(B);

	printf("\n--------Penghapusan elemen Berdasarkan Nilai--------\n");
	printf ("List A sebelum dihapus : ");
	PrintInfo(A);
	printf("\n======\tDeleteVFirst\t======\n");
	DelVFirst(&A,&X);
	printf("Nilai yang dihapus = %d\n", X);
    PrintInfo(A);
	printf("\n======\tDeleteVAfter\t======\n");
	DelVAfter(&A,&X);
	printf("Nilai yang dihapus = %d\n", X);
    PrintInfo(A);
	printf("\n======\tDeleteVLast\t======\n");
	DelVLast(&A,&X);
	printf("Nilai yang dihapus = %d\n", X);
    PrintInfo(A);

	return 0;
}



