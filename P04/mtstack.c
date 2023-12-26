/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 23 September 2022 */

#include <stdio.h>
#include <stdlib.h>
#include "tstack.c"
#include <string.h>

int main()
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char B, X;

	/* algoritma */
	createStack(&A);
	A.wadah[1] = 'C';

	printf("Posisi top stack berada pada elemen ke-%d", top(A));
	printf("\nNilai elemen top stack adalah %c", infotop(A));
	
	(isEmptyStack(A)) ? printf("\nStack A kosong") : printf("\nStack A tidak kosong");
	(isFullStack(A)) ? printf("\nStack A penuh") : printf("\nStack A tidak penuh");

	push(&A, B);
	printf("\nPosisi top stack sekarang berada pada elemen ke-%d", top(A));
	printf("\nNilai elemen top stack yang baru adalah %c", infotop(A));

	pop(&A, &X);
	printf("\nPosisi top stack sekarang berada pada elemen ke-%d dan X berisi nilai top stack sebelumnya yaitu %c", top(A), X);

	A.wadah[2] = 'M';
	A.wadah[3] = 'P';

	printStack(A);
	viewStack(A);

	boolean isPalindrom (Tstack KATA){
		/*Kamus Lokal*/
		int i;
		boolean hasil;
		char kata;
		
		/*Algoritma*/
		createStack(&KATA);
		printf("\nPENGECEKAN PALINDROM\nMasukkan kata : ");
		pushN(&KATA, 5);
		hasil = true;
		for (i = 0; i < KATA.top; i++){
			if (KATA.wadah[i + 1] != KATA.wadah[A.top - i]){
				hasil = false;
			}
		}
		return hasil;
	}

	if (isPalindrom(A)){
		printf("True");
	} else {
		printf("False");
	}
	
	

	return 0;

}



