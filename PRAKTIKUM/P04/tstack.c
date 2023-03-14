/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 23 September 2022 */

#include <stdio.h>
#include <stdlib.h>
#include "tstack.h"
#include "boolean.h"
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    for (i = 1; i < 11; i++){
        T->wadah[i] = '#';
    }
	(*T).top = 1;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (Tstack T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return T.top;
}

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop (Tstack T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return (T.top == 0) ? '#' : T.wadah[T.top];
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if (isFullStack(*T)){
		printf("\nStack penuh"); 
	} else {
		T->top = T->top + 1; 
		T->wadah[T->top] = 'E';
	}
	
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if (isEmptyStack(*T)){
		printf("\nStack kosong");
	} else {
		*X = ((*T).wadah[top(*T)]);
		(*T).wadah[top(*T)] = '#';
		(*T).top = (*T).top - 1;
	}
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
	printf("\nElemen-elemen pada stack adalah sebagai berikut: ");
	for (i = 1; i < 11; i++){
		printf("%c; ", T.wadah[i]);
	}
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
	/*Kamus Lokal*/
	int i;	
	
	/*Algoritma*/
	printf("\nElemen-elemen tak kosong pada stack adalah sebagai berikut: ");
	for (i = 1; i < 11; i++){
		if (T.wadah[i] != '#') {
			printf("%c; ", T.wadah[i]);
		}
	}
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */
	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali, bila belum penuh }*/
void pushN (Tstack *T, int N){
    /*Kamus Lokal*/
    int i; //iterator
    char temp;

    /*Algoritma*/
    if (!isFullStack(*T) && N<=10){
		printf("\n");
        for (i=1; i<=N; i++){
            scanf(" %c", &temp);
            (*T).wadah[i]=temp;
        }
        (*T).top = N;
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if(!isFullStack(*T)){
        (*T).top = (*T).top + 1;
        (*T).wadah[(*T).top] = E;
    }
    else{
        createStack(&(*T));
    }
}