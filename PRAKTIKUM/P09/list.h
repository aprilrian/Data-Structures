/* Nama File : list.h */
/* Deskripsi : header fungsi list */
/* Pembuat   : Aprilyanto Setiyawan Siburian (24060121120022) */
/* Tanggal   : 02 November 2022 22:11:16*/

#ifndef list_H
#define list_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

/* ----- Test List Kosong ----- */
bool ListEmpty (List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/* I.S. : sembarang
    F.S. : Terbentuk list kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
    dan misalnya menghasilkan P, maka
    Info(P) = X, Next(P) = Nil
    Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S. : P terdefinisi
    F.S. : P dikembalikan ke sistem
    Melakukan dealokasi/pengembalian address P */

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P);
/* I.S. : Sembarang, P sudah dialokasi
    F.S. : Menambahkan elemen ber-address P sebagai elemen pertama*/

void InsertAfter (List *L, address P, address Prec);
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
    P sudah dialokasi
    F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P);
/* I.S. : Sembarang, P sudah dialokasi
    F.S. : P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P);
/* I.S. : List tidak kosong
    F.S. : P adalah alamat elemen pertama list sebelum penghapusan
    Elemen list berkurang satu (mungkin menjadi kosong)
    First element yang baru adalah suksesor elemen pertama yang
    lama */

void DelLast (List *L, address *P);
/* I.S. : List tidak kosong
    F.S. : P adalah alamat elemen terakhir list sebelum penghapusan
    Elemen list berkurang satu (mungkin menjadi kosong)
    Last element baru adalah predesesor elemen pertama yang
    lama, jika ada */

void DelAfter (List *L, address * Pdel, address Prec);
/* I.S. : List tidak kosong. Prec adalah anggota list L.
    F.S. : Menghapus Next(Prec) :
    Pdel adalah alamat elemen list yang dihapus

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X);
/* I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen pertama L
    Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen
    pertama dengan nilai X jika alokasi berhasil.
    Jika alokasi gagal, maka I.S.= F.S. */

void InsVLast (List *L, infotype X);
/* I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen terakhir L
    Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list
    di akhir yaitu jika alokasi berhasil, elemen terakhir yang baru bernilai X
    Jika alokasi gagal, maka I.S.= F.S. */

void InsVAfter (List *L, infotype X, address Prec);
/* I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen setelah Prec
    Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list
    setelah Prec yaitu jika alokasi berhasil, elemen setelah Prec yang baru
    bernilai X
    Jika alokasi gagal, maka I.S.= F.S. */

void AdrLast(List *L, address *Prec, address *Last);
/*mencari alamat elemen terakhir dan sebelumnya*/

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X);
/* I.S. : List L tidak kosong
    F.S. : Elemen pertama list dihapus den nilai info disimpan pada
    X
    dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X);
/* I.S. : List L tidak kosong
    F.S. : Elemen terakhir list dihapus : nilai info disimpan pada
    X
    dan alamat elemen terakhir di-dealokasi */

void DelVAfter (List *L, infotype *X, address Prec);
/* I.S. : List L tidak kosong
    F.S. : Elemen list setelah Prec dihapus : nilai info disimpan
    pada X
    dan alamat elemen setelah Prec di-dealokasi */

/* Proses Semua Elemen List */
void PrintInfo (List L);
/* I.S. : List mungkin kosong
    F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen
    list diprint
    Jika list kosong, hanya menuliskan "list kosong" */

int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* {****************** PENCARIAN SEBUAH ELEMEN LIST ******************} */
address Search (List L, infotype X);
/*{ Mencari apakah ada elemen list dengan info(P)= X }
  { Jika ada, mengirimkan address elemen tersebut. }
  { Jika tidak ada, mengirimkan Nil } */

bool FSearch (List L, address P);
/*{ Mencari apakah ada elemen list yang beralamat P }
  { Mengirimkan true jika ada, false jika tidak ada }*/

address SearchPrec (List L, infotype X);
/*{ Mengirimkan address elemen sebelum elemen yang nilainya=X }
  { Mencari apakah ada elemen list dengan info(P)= X }
  { Jika ada, mengirimkan address Prec, dengan Next(Prec)=P }
  { dan Info(P)=X. }
  { Jika tidak ada, mengirimkan Nil }
  { Jika P adalah elemen pertama, maka Prec=Nil }
  { Search dengan spesifikasi seperti ini menghindari }
  { traversal ulang jika setelah Search akan dilakukan operasi lain}*/


/* {****************** PROSES TERHADAP LIST ******************} */
void DelAll (List *L);
/*{ I.S. sembarang }
  { F.S. Delete semua elemen list dan alamat elemen di-dealokasi }
  { List L menjadi list kosong }*/

void InversList (List *L);
/*{ I.S. sembarang. }
  { F.S. elemen list dibalik : }
  { Elemen terakhir menjadi elemen pertama, dan seterusnya. }
  { Membalik elemen list, tanpa melakukan alokasi/dealokasi. }*/

List FInversList (List L, List *M);
/*{ Mengirimkan list baru, hasil invers dari L }
  { dengan menyalin semua elemn list. Alokasi mungkin gagal. }
  { Jika alokasi gagal, hasilnya list kosong }
  { dan semua elemen yang terlanjur di-alokasi, harus didealokasi }*/

void CopyList (List *L1, List *L2);
/*{ I.S. L1 sembarang. }
  { F.S. L2=L1 }
  { L1 dan L2 "menunjuk" kepada list yang sama.}
  { Tidak ada alokasi/dealokasi elemen }*/

List FCopyList (List L, List *M);
/*{ Mengirimkan list yang merupakan salinan L }
  { dengan melakukan alokasi. }
  { Jika ada alokasi gagal, hasilnya list kosong dan }
  { semua elemen yang terlanjur di-alokasi, harus didealokasi }*/

void Konkat (List L1, List L2, List *L3);
/*{ I.S. L1 dan L2 sembarang }
  { F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 }
  { Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi}
  { Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi }
  { harus di-dealokasi dan L3=Nil}
  { Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang �baru� }
  { Elemen L3 adalah hasil alokasi elemen yang �baru�. }
  { Jika ada alokasi yang gagal, maka L3 harus bernilai Nil}
  { dan semua elemen yang pernah dialokasi didealokasi } */

void Konkat1 (List *L1, List *L2, List *L3);
/*{ I.S. L1 dan L2 sembarang }
  { F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 }
  { Konkatenasi dua buah list : L1 dan L2 }
  { menghasilkan L3 yang baru (dengan elemen list L1 dan L2)}
  { dan L1 serta L2 menjadi list kosong.}
  { Tidak ada alokasi/dealokasi pada prosedur ini }*/

void PecahList (List *L1, List *L2, List L);
/*{ I.S. L mungkin kosong }
  { F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 }
  { L tidak berubah: untuk membentuk L1 dan L2 harus alokasi }
  { L1 berisi separuh elemen L dan L2 berisi sisa elemen L }
  { Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 }*/

#endif