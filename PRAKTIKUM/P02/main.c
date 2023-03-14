/* Program   : main.c */
/* Deskripsi : aplikasi file modul tabel */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 15 September 2022 */

#include <stdio.h>
#include "tabel.h"
#include "tabel.c"

int main(){
	/*Kamus Lokal*/
	Tabel A;
	int Size, Unsize, N, Jumlah, Max, Min, X, Pos, Byk;
	float Mean;

	/*Algoritma*/
	createTable(&A);
	printf("Tabel A berhasil dibuat dengan size = %d\n", A.size);

	printTable(A);
	viewTable(A);

	Size = getSize(A);
	printf("Banyak elemen pengisi tabel adalah %d\n", Size);

	Unsize = countEmpty(A);
	printf("Banyak elemen tabel yang belum terisi adalah %d\n", Unsize);

	isEmptyTable(A);
	isFullTable(A);
	populate1(&A, N);
	searchX1 (A, X, &Pos);
	countX (A, X, &Byk);

	Jumlah = SumEl(A);
	printf("Jumlah semua pengisi elemen tabel adalah = %d\n", Jumlah);

	Mean = AverageEl(A);
	printf("Nilai rata-rata pengisi elemen tabel adalah %2.f\n", Mean);

	Max = getMaxEl(A);
	printf("Nilai elemen terbesar pengisi tabel adalah %d\n", Max);

	Min = getMinEl(A);
	printf("Nilai elemen terkecil pengisi tabel adalah %d\n", Min);

	populate2(&A);
	addXTable(&A, X);
	delXTable(&A, X);
	delAllXTable(&A, X);
	Modus(A);

}