/* File : listCircular.h */
/* Deskripsi : file modul List Circular */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : 22 November 2022*/

#ifndef listCircular_C
#define listCircular_C

#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
/*Kamus Lokal*/

/*Algoritma*/
    return First(L) == Nil;
}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
void CreateList (List *L){
/*Kamus Lokal*/

/*Algoritma*/
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if(P != Nil){
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P){
/*Kamus Lokal*/

/*Algoritma*/
    info(*P) = 0;
    next(*P) = Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
/*Kamus Lokal*/
    address Prec, Last;

/*Algoritma*/
    if(ListEmpty(*L)){
        next(P) = P;
    }else{
        AdrLast(*L, &Prec, &Last);
        next(P) = First(*L);
        next(Last) = P;
    }
    First(*L) = P;
}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
/*Kamus Lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
/*Kamus Lokal*/
    address Prec, Last;

/*Algoritma*/
    if(ListEmpty(*L)){
        InsertFirst(L, P);
    }else{
        AdrLast(*L, &Prec, &Last);
        next(P) = First(*L);
        next(Last) = P;
    }
}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P){
/*Kamus Lokal*/
    address Prec, Last;

/*Algoritma*/
    AdrLast(*L, &Prec, &Last);
    *P = First(*L);
    if(next(First(*L)) == First(*L)){
        First(*L) = Nil;
    }else{
        First(*L) = next(First(*L));
        next(Last) = First(*L);
    }
    next(*P) = Nil;
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P){
/*Kamus Lokal*/
    address Prec;

/*Algoritma*/
    AdrLast(*L, &Prec, &(*P));
    if(next(First(*L)) == First(*L)){
        DelFirst(L, P);
    }else{
        next(Prec) = First(*L);
    }
    next(*P) = Nil;
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address *Pdel, address Prec){
/*Kamus Lokal*/

/*Algoritma*/
    if(next(next(Prec)) == First(*L)){
        DelLast(L, Pdel);
    }else{
        *Pdel = next(Prec);
        next(Prec) = next(*Pdel);
    }
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVFirst (List *L, infotype X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertFirst(L, P);
    }

}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertLast(L, P);
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X, infotype Prec){
/*Kamus Lokal*/
    address P, Q;

/*Algoritma*/
    if (First(*L)== Nil){
		printf("");
	}
	else {
		Q=Alokasi(X);
		P=First(*L);
		while (info(P) != Prec){
			P=next(P);
			}
		if(info(P)==Prec){
			next(Q)=next(P);
			next(P)=Q;
		}
	}
}

/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List L, address *Prec, address *Last){
/*Kamus Lokal*/

/*Algoritma*/
    *Prec = Nil;
    *Last = Nil;
    if(!ListEmpty(L)){
        *Last = First(L);
        while(next(*Last) != First(L)){
            *Prec = *Last;
            *Last = next(*Last);
        }
    }
}

/* Penghapusan ELemen */
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    DelFirst(L, &P);
    *X = info(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    DelLast(L, &P);
    *X = info(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X){
/*Kamus Lokal*/
    address Prec, P, Last;

/*Algoritma*/
    AdrLast(*L, &Prec, &Last);
    DelAfter(L, &P, Prec);
    *X = info(P);
    Dealokasi(&P);
}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    if(First(L)==Nil){
		printf("List Kosong\n");
	}
	else {
		P=First(L);
		printf("-> %d ",info(P));
		while(next(P)!=First(L)){
			P=next(P);
			printf("-> %d ",info(P));
		}
		printf("\n");
	}
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L){
/*Kamus Lokal*/
    address P;
    int total;

/*Algoritma*/
    if(!ListEmpty(L)){
        total = 1;
		P = First(L);
		while(next(P)!=First(L)){
			total = total+1;
			P = next(P);
		}
    }
    return total;
}

#endif // listCircular_C
