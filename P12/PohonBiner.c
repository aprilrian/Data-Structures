/* Program   : PohonBiner.h */
/* Deskripsi : Realisasi Pohon Biner */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : 01 Desember 2022*/
/***********************************/

#ifndef PohonBiner_C
#define PohonBiner_C
#include "PohonBiner.h"

address Alokasi (int X){
/*{ Mengirimkan address hasil alokasi sebuah elemen X }
  { Jika alokasi berhasil, maka address tidak nil, dan misalnya
    menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil
  { Jika alokasi gagal, mengirimkan Nil } */
//Kamus Lokal
    address P;

//Algoritma
    P = (address)malloc(sizeof(Node));
    if(P != Nil){
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    else {
        (P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
/*{ I.S. P terdefinisi }
  { F.S. P dikembalikan ke sistem }
  { Melakukan dealokasi/pengembalian address P }*/
//Kamus Lokal

//Algoritma
    free(P);
}

BinTree Tree (infotype Akar, BinTree L, BinTree R){
/*{ Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
    berhasil }
  { Menghasilkan pohon kosong (Nil) jika alokasi gagal }*/
//Kamus Lokal
    BinTree P;

//Algoritma
    P = Alokasi(Akar);
    if (P != Nil){
        Info(P) = Akar;
        Left(P) = L;
        Right(P) = R;
    }
    else {
        P = Nil;
    }
    return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
/*{ I.S. Sembarang }
  { F.S. Menghasilkan sebuah pohon P }
  { Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi
    berhasil }
  { Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal }*/
//Kamus Lokal

//Algoritma
    (*P) = Alokasi(Akar);
    if ((*P) != Nil){
        (*P)->info = Akar;
        (*P)->left = L;
        (*P)->right = R;
    }
    else{
        (*P) = Nil;
    }
}

boolean isTreeEmpty(BinTree P){
/*{ Mengirimkan true jika P adalah pohon biner yang kosong } */
//Kamus Lokal

//Algoritma
    return ((P == Nil) || (Akar(P) == Nil));
}

boolean isOneElmt(BinTree P){
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1
elemen } */

//Kamus Lokal

//Algoritma
    return  ((!(isTreeEmpty(P))) && (isTreeEmpty(Left(P))) && (isTreeEmpty(Right(P))));
}

boolean isUnerLeft(BinTree P){
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
    unerleft: hanya mempunyai subpohon kiri } */
//Kamus Lokal

//Algoritma
    return  ((Right(P) == Nil) && (Left(P) != Nil));
}

boolean isUnerRight(BinTree P){
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
    unerright: hanya mempunyai subpohon kanan }*/
//Kamus Lokal

//Algoritma
    return  ((Right(P) != Nil) && (Left(P) == Nil));
}

boolean isBiner(BinTree P){
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
    biner: mempunyai subpohon kiri dan subpohon kanan }*/
//Kamus Lokal

//Algoritma
    return ((Right(P) != Nil) && (Left(P) != Nil));
}

void PrintTreeL(BinTree P, int h, int CLevel){
/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
  { F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
  { Penulisan akar selalu pada baris baru (diakhiri newline) }*/
//Kamus Lokal
    int i;

//Algoritma
    if (isTreeEmpty(P)){
        printf("Tree Kosong");
    }
    else{
        for (i = 1; i<=(h*(CLevel-1)); i++){
            printf(" ");
        }
        printf("%d", Akar(P));
        if (Left(P) != Nil){
            PrintTreeL(Left(P),h,CLevel+1);
        }
        if (Right(P) != Nil){
            PrintTreeL(Right(P),h,CLevel+1);
        }
    }
}

void PrintTree(BinTree P, int h){
/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
  { F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
  { Penulisan akar selalu pada baris baru (diakhiri newline) }*/
//Kamus Lokal

//Algoritma
    PrintTreeL(P,h,1);
}

void PrintPreOrder(BinTree P){
/*{ I.S. Pohon P terdefinisi }
  { F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
    kanan }
  { Basis : Pohon kosong : tidak ada yang diproses }
  { Rekurens : Cetak Akar(P); cetak secara Preorder (Left(P)); cetak
    secara Preorder (Right(P)) }*/
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        printf(" ");
    }
    else{
        printf("%d ", Akar(P));
        PrintPreOrder(Left(P));
        PrintPreOrder(Right(P));
    }
}

void PrintInOrder(BinTree P){
/*{ I.S. Pohon P terdefinisi }
    { F.S. Semua node pohon P sudah dicetak secara InOrder: kiri, akar,
    kanan }
    { Basis : Pohon kosong : tidak ada yang diproses }
    { Rekurens : cetak secara Preorder (Left(P)); Cetak Akar(P); cetak
    secara Preorder (Right(P)) } */
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        printf(" ");
    }
    else{
        PrintPreOrder(Left(P));
        printf("%d ", Akar(P));
        PrintPreOrder(Right(P));
    }
}

void PrintPostOrder(BinTree P){
/*{ I.S. Pohon P terdefinisi }
  { F.S. Semua node pohon P sudah dicetak secara PostOrder: kiri, kanan,
    akar}
  { Basis : Pohon kosong : tidak ada yang diproses }
  { Rekurens : cetak secara Preorder (Left(P)); cetak secara Preorder
  (Right(P)); Cetak Akar(P) }*/
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        printf(" ");
    }
    else{
        PrintPreOrder(Left(P));
        PrintPreOrder(Right(P));
        printf("%d ", Akar(P));
    }
}

boolean SearchTree(BinTree P, infotype X){
/*{ Mengirimkan true jika ada node dari P yang bernilai X }*/
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        return false;
    }
    else{
        if (Akar(P) == X){
            return true;
        }
        else{
            return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
        }
    }
}

int NbElmt(BinTree P){
/*{ Mengirimkan banyaknya elemen (node) pohon biner P } */
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        return 0;
    }
    else {
        return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
    }
}

int NBDaun(BinTree P){
/*{ Prekondisi: Pohon Biner tidak mungkin kosong. Mengirimkan banyaknya
    daun pohon }
  { Basis: Pohon yang hanya mempunyai akar: 1 }
  { Rekurens: Punya anak kiri dan tidak punya anak kanan:
    NBDaun(Left(P)) Tidak Punya anak kiri dan punya anak kanan :
    NBDaun(Right(P)) Punya anak kiri dan punya anak kanan :
    NBDaun(Left(P)) + NBDaun(Right(P)) } */
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)) {
        return 0;
    }
    else{
        if (isOneElmt(P)) {
            return 1;
        }
        else {
            return (NBDaun(Left(P)) + NBDaun(Right(P)));
        }
    }
}

boolean isSkewLeft(BinTree P){
/*{ Mengirimkan true jika P adalah pohon condong kiri } */
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        return false;
    }
    else{
        if (NbElmt(Left(P))>NbElmt(Right(P))){
            return true;
        }
        else{
            return false;
        }
    }
}

boolean isSkewRight(BinTree P){
/*{ Mengirimkan true jika P adalah pohon condong kanan }*/
//Kamus Lokal

//Algoritma
    if (isTreeEmpty(P)){
        return false;
    }
    else{
        if (NbElmt(Right(P))>NbElmt(Left(P))){
            return true;
        }
        else{
            return false;
        }
    }
}

int Level(BinTree P, infotype X){
/*{ Mengirimkan level dari node X yang merupakan salah satu daun dari
    pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/

/*ASUMSI = JIKA TIDAK TERDAPAT NODE X PADA BINTREE P MAKA AKAN MENGIRIMKAN LEVEL 0*/
//Kamus Lokal

//Algoritma
    if(SearchTree(P,X)){
        if (X == Akar(P)){
            return 1;
        }
        else{
            if (SearchTree(Left(P), X)){
                return 1 + Level(Left(P), X);
            }
            else{
                return 1 + Level(Right(P), X);
            }
        }
    }
    else{
        return 0;
    }
}

#endif
