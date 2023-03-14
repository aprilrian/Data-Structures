/* Program   : PohonBiner.h */
/* Deskripsi : file HEADER Pohon Biner*/
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/
#ifndef POHONBINER_H_INCLUDED
#define POHONBINER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define Nil NULL

#define Info(P) P->info
#define Akar(P) P->info
#define Left(P) P->left
#define Right(P) P->right

typedef enum{false,true} boolean;
typedef int infotype;
typedef struct tNode *address;
typedef address BinTree;
typedef struct tNode {
    infotype info;
    BinTree left;
    BinTree right;
}Node;

address Alokasi (int X);
/*{ Mengirimkan address hasil alokasi sebuah elemen X }
{ Jika alokasi berhasil, maka address tidak nil, dan misalnya
menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil
{ Jika alokasi gagal, mengirimkan Nil } */

void Dealokasi (address P);
/*{ I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P }
*/

BinTree Tree (infotype Akar, BinTree L, BinTree R);
/*{ Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon kosong (Nil) jika alokasi gagal }
*/

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
/*{ I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal }
*/

/**{*** Predikat-Predikat Penting ***} **/

boolean isTreeEmpty(BinTree P);
/*{ Mengirimkan true jika P adalah pohon biner yang kosong } */

boolean isOneElmt(BinTree P);
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1
elemen } */

boolean isUnerLeft(BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
unerleft: hanya mempunyai subpohon kiri } */

boolean isUnerRight(BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
unerright: hanya mempunyai subpohon kanan }
*/

boolean isBiner(BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
biner: mempunyai subpohon kiri dan subpohon kanan }*/

/**{*** Pemrosesan Traversal ***} **/

void PrintTreeL(BinTree P, int h, int CLevel);
/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
{ F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
{ Penulisan akar selalu pada baris baru (diakhiri newline) }
*/

void PrintTree(BinTree P, int h);
/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
{ F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
{ Penulisan akar selalu pada baris baru (diakhiri newline) }
*/

void PrintPreOrder(BinTree P);
/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : Cetak Akar(P); cetak secara Preorder (Left(P)); cetak
secara Preorder (Right(P)) }*/

void PrintInOrder(BinTree P);
/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : cetak secara Preorder (Left(P)); Cetak Akar(P); cetak
secara Preorder (Right(P)) } */

void PrintPostOrder(BinTree P);
/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : cetak secara Preorder (Left(P)); cetak secara Preorder
(Right(P)); Cetak Akar(P) }
*/

boolean SearchTree(BinTree P, infotype X);
/*{ Mengirimkan true jika ada node dari P yang bernilai X }
*/

int NbElmt(BinTree P);
/*{ Mengirimkan banyaknya elemen (node) pohon biner P } */

int NBDaun(BinTree P);
/*{ Prekondisi: Pohon Biner tidak mungkin kosong. Mengirimkan banyaknya
daun pohon }
{ Basis: Pohon yang hanya mempunyai akar: 1 }
{ Rekurens: Punya anak kiri dan tidak punya anak kanan:
NBDaun(Left(P)) Tidak Punya anak kiri dan punya anak kanan :
NBDaun(Right(P)) Punya anak kiri dan punya anak kanan :
NBDaun(Left(P)) + NBDaun(Right(P)) } */

boolean isSkewLeft(BinTree P);
/*{ Mengirimkan true jika P adalah pohon condong kiri } */

boolean isSkewRight(BinTree P);
/*{ Mengirimkan true jika P adalah pohon condong kanan }*/

int Level(BinTree P, infotype X);
/*{ Mengirimkan level dari node X yang merupakan salah satu daun dari
pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }
*/

#endif // POHONBINER_H_INCLUDED
