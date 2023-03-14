/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : 2 September 2022*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main()
{
	/*Kamus Lokal*/
		Titik A; // A : Titik
		Titik B; // B : Titik
		Titik C; // C : Titik
		int Absis; // Absis : integer
		int Ordinat; // Ordinat : integer
		float d; //d : real

	/*Algoritma*/
		makeTitik(&A);
		printf("Titik A (%d,%d)\n", A.absis, A.ordinat);
		
		makeTitik(&B);
		printf("Titik B (%d,%d)\n", B.absis, B.ordinat);
		
		makeTitik(&C);
		printf("Titik C (%d,%d)\n", C.absis, C.ordinat);
		
		A.absis = 4;
		A.ordinat = 3;
		printf("Absis = %d Ordinat = %d", A.absis, A.ordinat);
		
		Absis = getAbsis(A);
		printf("\nAbsis = %d", Absis);
		
		Ordinat = getOrdinat(A);
		printf("\nOrdinat = %d", Ordinat);
		
		setAbsis (&A, 3);
		printf("\nA.absis yang baru = %d", A.absis);
		
		setOrdinat (&A, 5);
		printf("\nA.ordinat yang baru = %d", A.ordinat);
		
		if (isOrigin(A))
		{ 
			printf("\nTitik A berada di titik origin\n");
			} else {
				printf("\nTitik A tidak berada di titik origin\n");
			}
		
		geserXY (&A, 10, 11);
		printf("Titik A setelah digeser adalah (%d,%d)\n", A.absis, A.ordinat);
		
		refleksiSumbuX (&A);
		printf("Titik A setelah direfleksi terhadap sumbu x adalah (%d,%d)\n", A.absis, A.ordinat);
		
		refleksiSumbuY (&A);
		printf("Titik A setelah direfleksi terhadap sumbu y adalah (%d,%d)\n", A.absis, A.ordinat);
		
		Kuadran(A);
		if (Kuadran(A) == 1){
			printf("Titik A berada di Kuadran 1\n");
		} else if (Kuadran(A) == 2){
			printf("Titik A berada di Kuadran 2\n");
		} else if (Kuadran(A) == 3){
			printf("Titik A berada di Kuadran 3\n");
		} else if (Kuadran(A) == 4){
			printf("Titik A berada di Kuadran 4\n");
		}
		
		B.absis = 10;
		B.ordinat = 10;
		C.absis = 8;
		C.ordinat = 8;
		
		d = Jarak(B,C);
		printf("Jarak euclidian titik B dan C adalah %.2f", d);
		
		return 0;
}
