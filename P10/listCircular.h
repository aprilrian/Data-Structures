/* File : listCircular.h */
/* Deskripsi : file modul List Circular */
/* Nama : Aprilyanto Setiyawan Siburian*/
/* NIM  : 24060121120022*/
/* ADT list Circular dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listCircular_H
#define listCircular_H

#include <stdio.h>
#include <stdlib.h>

#define Nil          NULL
#define info(P)      (P)->info
#define next(P)      (P)->next
#define First(L)     (L).First

typedef enum{false,true} boolean;
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype   info;
    address    next;
}ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

typedef struct {
    address First;
}List;

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P);
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P);
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */

void DelLast (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */

void DelAfter (List *L, address * Pdel, address Prec);
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X);
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */

void InsVLast (List *L, infotype X);
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

void InsVAfter (List *L, infotype X, infotype Prec);
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

void AdrLast(List L, address *Prec, address *Last);
/*mencari alamat elemen terakhir dan sebelumnya*/

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */


void DelVLast (List *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */

void DelVAfter (List *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L);
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */

int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


#endif
