/* Nama File : list.c */
/* Deskripsi : driver modul fungsi list */
/* Pembuat   : Aprilyanto Setiyawan Siburian (24060121120022) */
/* Tanggal   : 02 November 2022 22:09:53*/

#ifndef list_C
#define list_C

#include "list.h"

/* ----- Test List Kosong ----- */
bool ListEmpty (List L){
/* Mengirim true jika list kosong */

/*Kamus Lokal*/

/*Algoritma*/
    return (First(L) == Nil);
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
/*  I.S. : sembarang
    F.S. : Terbentuk list kosong */

/*Kamus Lokal*/

/*Algoritma*/
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/*  Mengirimkan address hasil alokasi sebuah elemen */
/*  Jika alokasi berhasil, maka address tidak Nil,
    dan misalnya menghasilkan P, maka
    Info(P) = X, Next(P) = Nil
    Jika alokasi gagal, mengirimkan Nil */

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if(P != Nil){
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
/*  I.S. : P terdefinisi
    F.S. : P dikembalikan ke sistem
    Melakukan dealokasi/pengembalian address P */

/*Kamus Lokal*/

/*Algoritma*/
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/*  I.S. : Sembarang, P sudah dialokasi
    F.S. : Menambahkan elemen ber-address P 
    sebagai elemen pertama */

/*Kamus Lokal*/

/*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
/*  I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
    P sudah dialokasi
    F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */

/*Kamus Lokal*/

/*Algoritma*/
    if(First(*L) == Nil){
        InsertFirst(L,P);
    }
    else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void InsertLast (List *L, address P){
/*  I.S. : Sembarang, P sudah dialokasi
    F.S. : P ditambahkan sebagai elemen terakhir yang baru */

/*Kamus Lokal*/
    address Last;
/*Algoritma*/
    if (First(*L) == Nil){
        InsertFirst(L, P);
    }
    else{
        Last = First(*L);
        while (next(Last) != Nil) {
            Last = next(Last);
        }
        InsertAfter(L, P, Last);
    }
}
/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/*  I.S. : List tidak kosong
    F.S. : P adalah alamat elemen pertama list sebelum 
    penghapusan. 
    Elemen list berkurang satu (mungkin menjadi kosong)
    First element yang baru adalah suksesor elemen pertama yang 
    lama */

/*Kamus Lokal*/

/*Algoritma*/
    (*P) = First(*L);
    First(*L)=next(First(*L));
}

void DelLast (List *L, address *P){
/*  I.S. : List tidak kosong
    F.S. : P adalah alamat elemen terakhir list sebelum penghapusan
    Elemen list berkurang satu (mungkin menjadi kosong)
    Last element baru adalah predesesor elemen pertama yang
    lama, jika ada */

/*Kamus Lokal*/
    address Last, Prec;

/*Algoritma*/
    Last = First(*L);
    Prec = Nil;
    while (next(Last)!=Nil){
        Prec = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if (Prec == Nil){
        First(*L) = Nil;
    }
    else{
        next(Prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/*  I.S. : List tidak kosong. Prec adalah anggota list L.
    F.S. : Menghapus Next(Prec) :
    Pdel adalah alamat elemen list yang dihapus

/*Kamus Lokal*/

/*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X){
/*  I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen pertama L
    Proses : Melakukan alokasi sebuah elemen dan menambahkan 
    elemen pertama dengan nilai X jika alokasi berhasil.
    Jika alokasi gagal, maka I.S.= F.S. */

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = Alokasi(X);
    if (P!=Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X){
/*  I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen terakhir L
    Proses : Melakukan alokasi sebuah elemen dan menambahkan 
    elemen list di akhir yaitu jika alokasi berhasil, elemen 
    terakhir yang baru bernilai X
    Jika alokasi gagal, maka I.S.= F.S. */

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = Alokasi(X);
    if (P!=Nil){
        InsertLast(L, P);
    }
}

void InsVAfter (List *L, infotype X, address Prec){
/*  I.S. : L mungkin kosong
    F.S. : X ditambahkan sebagai elemen setelah Prec
    Proses : Melakukan alokasi sebuah elemen dan menambahkan 
    elemen list setelah Prec yaitu jika alokasi berhasil, 
    elemen setelah Prec yang baru bernilai X
    Jika alokasi gagal, maka I.S.= F.S. */

/*Kamus Lokal*/
    address P, T;

/*Algoritma*/
    if (!ListEmpty(*L)){
        P = Alokasi(X);
        T = First(*L);
        while(T != Prec){
            T = next(T);
        }
        InsertAfter(L, P, T);
    }
    else {
        InsVFirst(L, X);
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

/*Kamus Lokal*/
    address PrecLast;

/*Algoritma*/
    (*Last) = First(*L);
    PrecLast = Nil;
    while (next(*Last) != Nil){
        PrecLast = (*Last);
        (*Last) = next(*Last);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X){
/*  I.S. : List L tidak kosong
    F.S. : Elemen pertama list dihapus den nilai info 
    disimpan pada X dan alamat elemen pertama di-dealokasi */

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = First(*L);
    (*X) = info(P);
    DelFirst(&(*L),&P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
/*  I.S. : List L tidak kosong
    F.S. : Elemen terakhir list dihapus : nilai info disimpan 
    pada X dan alamat elemen terakhir di-dealokasi */

/*Kamus Lokal*/
    address P, Last, PrecLast;

/*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last) != Nil) {
        PrecLast = Last;
        Last = next(Last);
    }
    P = Last;
    (*X) = info(P);
    DelLast(&(*L), &P);
    Dealokasi(&P);
}

void DelVAfter (List *L, infotype *X, address Prec){
/*  I.S. : List L tidak kosong
    F.S. : Elemen list setelah Prec dihapus : nilai info 
    disimpan pada X dan alamat elemen setelah Prec di-dealokasi */

/*Kamus Lokal*/
    address P, T;

/*Algoritma*/
    P = First(*L);
    while (P != Prec){
        P = next(P);
    }
    T = next(P);
    (*X) = info(T);
    DelAfter(&(*L), &T, P);
    Dealokasi(&T);
}

/* Proses Semua Elemen List */
void PrintInfo (List L){
/*  I.S. : List mungkin kosong
    F.S. : Jika list tidak kosong, semua info yg disimpan pada 
    elemen list diprint
    Jika list kosong, hanya menuliskan "list kosong" */

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    if(ListEmpty(L)){
        printf("\nList Kosong\n");
    }
    else{
        P=First(L);
        do{
            printf("%d ",info(P));
            P=next(P);
        }while(P!=Nil); /* while(P!=First(L)) untuk circular*/
        printf("\n");
    }
}

int NbElmt (List L){
/*  Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*Kamus Lokal*/
    address P;
    int sum;

/*Algoritma*/
    sum = 0;
    if (First(L) != Nil) {
        P = First(L);
        while (P != Nil) {
            sum++;
            P = next(P);
        }
    }
    return sum;
}

address Search (List L, infotype X){
/*{ Mencari apakah ada elemen list dengan info(P)= X }
  { Jika ada, mengirimkan address elemen tersebut. }
  { Jika tidak ada, mengirimkan Nil } */

/*Kamus Lokal*/
    address P;
    bool cek;

/*Algoritma*/
    cek = false;
    P = First(L);
    while ((P != Nil) && (!cek)){
        if (info(P) == X){
            cek = true;
        }
        else{
            P = next(P);
        }
    }
    return P;
}

bool FSearch (List L, address P){
/*{ Mencari apakah ada elemen list yang beralamat P }
  { Mengirimkan true jika ada, false jika tidak ada }*/

/*Kamus Lokal*/
    address T;
    bool cek;

/*Algoritma*/
    cek = false;
    T = First(L);
    while ((T != Nil) && (!cek)) {
        if (T == P){
            cek = true;
        }
        else {
            T = next(T);
        }
    }
    return cek;
}

address SearchPrec (List L, infotype X){
/*{ Mengirimkan address elemen sebelum elemen yang nilainya=X }
  { Mencari apakah ada elemen list dengan info(P)= X }
  { Jika ada, mengirimkan address Prec, dengan Next(Prec)=P }
  { dan Info(P)=X. }
  { Jika tidak ada, mengirimkan Nil }
  { Jika P adalah elemen pertama, maka Prec=Nil }
  { Search dengan spesifikasi seperti ini menghindari }
  { traversal ulang jika setelah Search akan dilakukan operasi lain}*/

/*Kamus Lokal*/
    address P, Prec;
    bool cek;

/*Algoritma*/
    cek = false;
    P = First(L);
    Prec = Nil;
    while ((P != Nil) && (!cek)){
        if (info(P) == X){
            cek = true;
        }
        else{
            Prec = P;
            P = next(P);
        }
    }
    if (cek == true){
        return Prec;
    }
    else {
        return Nil;
    }
}


/* {****************** PROSES TERHADAP LIST ******************} */
void DelAll (List *L){
/*{ I.S. sembarang }
  { F.S. Delete semua elemen list dan alamat elemen di-dealokasi }
  { List L menjadi list kosong }*/

/*Kamus Lokal*/
    address P;

/*Algoritma*/
    while (First(*L) != Nil){
        P = First(*L);
        DelFirst(L, &P);
        Dealokasi(&P);
    }
}

void InversList (List *L){
/*{ I.S. sembarang. }
  { F.S. elemen list dibalik : }
  { Elemen terakhir menjadi elemen pertama, dan seterusnya. }
  { Membalik elemen list, tanpa melakukan alokasi/dealokasi. }*/

/*Kamus Lokal*/
    address Curr, Prec, NextEl;

/*Algoritma*/
    Curr = First(*L);
    Prec = Nil;
    NextEl = Nil;
    while (Curr != Nil){
        NextEl = next(Curr);
        next(Curr) = Prec;
        Prec = Curr;
        Curr = NextEl;
    }
    First(*L) = Prec;
}

List FInversList (List L, List *M){
/*{ Mengirimkan list baru, hasil invers dari L }
  { dengan menyalin semua elemn list. Alokasi mungkin gagal. }
  { Jika alokasi gagal, hasilnya list kosong }
  { dan semua elemen yang terlanjur di-alokasi, harus didealokasi }*/

/*Kamus Lokal*/
    address P, Q;
    bool gagal;

/*Algoritma*/
    P = First(L);
    gagal = false;
    CreateList(M);
    while((P != Nil) && (!gagal)){
        Q = Alokasi(info(P));
        if (Q != Nil){
            InsertFirst(M, Q);
            P = next(P);
        }
        else {
            gagal = true;
            DelAll(&L);
        }
    }
    return (*M);
}

void CopyList (List *L1, List *L2){
/*{ I.S. L1 sembarang. }
  { F.S. L2=L1 }
  { L1 dan L2 "menunjuk" kepada list yang sama.}
  { Tidak ada alokasi/dealokasi elemen }*/

/*Kamus Lokal*/

/*Algoritma*/
    First(*L2) = First(*L1);
}

List FCopyList (List L, List *M){
/*{ Mengirimkan list yang merupakan salinan L }
  { dengan melakukan alokasi. }
  { Jika ada alokasi gagal, hasilnya list kosong dan }
  { semua elemen yang terlanjur di-alokasi, harus didealokasi }*/

/*Kamus Lokal*/
    address P, Q;
    bool gagal;

/*Algoritma*/
    P = First(L);
    gagal = false;
    CreateList(M);
    while ((P!= Nil) && (!gagal)){
        Q = Alokasi(info(P));
        if (Q != Nil){
            InsertLast(M, Q);
            P = next(P);
        }
        else{
            gagal = true;
            DelAll(M);
        }
    }
    return (*M);
}

void Konkat (List L1, List L2, List *L3){
/*{ I.S. L1 dan L2 sembarang }
  { F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 }
  { Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi}
  { Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi }
  { harus di-dealokasi dan L3=Nil}
  { Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang �baru� }
  { Elemen L3 adalah hasil alokasi elemen yang �baru�. }
  { Jika ada alokasi yang gagal, maka L3 harus bernilai Nil}
  { dan semua elemen yang pernah dialokasi didealokasi } */

/*Kamus Lokal*/
    address P, Q, Aloc;

/*Algoritma*/
    CreateList(L3);
    P = First(L1);
    Q = First(L2);
    while (P != Nil){
        Aloc = Alokasi(info(P));
        if (Aloc != Nil){
            InsertLast(L3, Aloc);
            P = next(P);
        }
        else {
            Dealokasi(&Aloc);
            P = Nil;
        }
    }

    while (Q != Nil){
        Aloc = Alokasi(info(Q));
        if (Aloc != Nil){
            InsertLast(L3, Aloc);
            Q = next(Q);
        }
        else {
            Dealokasi(&Aloc);
            Q = Nil;
        }
    }
}

void Konkat1 (List *L1, List *L2, List *L3){
/*{ I.S. L1 dan L2 sembarang }
  { F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 }
  { Konkatenasi dua buah list : L1 dan L2 }
  { menghasilkan L3 yang baru (dengan elemen list L1 dan L2)}
  { dan L1 serta L2 menjadi list kosong.}
  { Tidak ada alokasi/dealokasi pada prosedur ini }*/

/*Kamus Lokal*/
    address Last;

/*Algoritma*/
    CreateList(L3);
    if (First(*L1) == Nil){
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    }
    else {
        First(*L3) = First(*L1);
        Last = First(*L1);
        while (next(Last) != Nil){
            Last = next(Last);
        }
        Last = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L){
/*{ I.S. L mungkin kosong }
  { F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 }
  { L tidak berubah: untuk membentuk L1 dan L2 harus alokasi }
  { L1 berisi separuh elemen L dan L2 berisi sisa elemen L }
  { Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 }*/

/*Kamus Lokal*/
    int i, n;
    address P,Q;
    bool gagal;

/*Algoritma*/
    gagal = false;
    i = 1;
    n = NbElmt(L)/2;
    P = First(L);
    CreateList(L1);
    CreateList(L2);
    while ((P != Nil) && (!gagal)){
        Q = Alokasi(info(P));
        if (i<=n){
            if (Q != Nil){
                InsertLast(L1, Q);
            }
            else{
                gagal = true;
                DelAll(L1);
            }
        }
        else{
            if (Q != Nil){
                InsertLast(L2, Q);
            }
            else {
                gagal = true;
                DelAll(L2);
            }
        }
        P = next(P);
        i ++;
    }
}    

#endif