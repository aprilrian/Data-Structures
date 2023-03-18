/* Program   : MainPohonBiner.c */
/* Deskripsi : Driver file modul ADT Binary Tree */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : 01 Desember 2022*/
/***********************************/

#include "PohonBiner.h"
#include "PohonBiner.c"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*Kamus*/
    BinTree A1, A2; //untuk alokasi
    BinTree T1, T2, T3, T4, T5, T6, T7;//Tree

    /*Algoritma*/
    printf("~~~~~Binary Tree~~~~~\n");
    A1 = Alokasi(2);
    A2 = Alokasi(3);
    //Tree T1
    MakeTree(Nil, Nil, Nil, &T1);
    printf("Tree T1 = ");
    PrintTree(T1, 1);
    //Tree T2
    MakeTree(1, Nil, Nil, &T2);
    printf("\nTree T2 = ");
    PrintTree(T2, 1);
    //Tree T3
    MakeTree(1, A1, Nil, &T3);
    printf("\nTree T3 = ");
    PrintTree(T3, 1);
    //Tree T4
    MakeTree(1, Nil, A2, &T4);
    printf("\nTree T4 = ");
    PrintTree(T4, 1);
    //Tree T5
    T5 = Tree(1, A1, A2);
    printf("\nTree T5 = ");
    PrintTree(T5, 1);
    //Tree T6
    T6 = Tree(1, T5, A2);
    printf("\nTree T6 = ");
    PrintTree(T6, 1);
    //Tree T7
    T7 = Tree(1, A1, T5);
    printf("\nTree T7 = ");
    PrintTree(T7, 1);

    printf("\n\n~~~~~isTreeEmpty~~~~~\n");
    //cek T1
    printf("Apakah T1 merupakan Tree Kosong? %s", isTreeEmpty(T1)? "true":"false");
    //cek T2
    printf("\nApakah T2 merupakan Tree Kosong? %s", isTreeEmpty(T2)? "true":"false");
    //cek T3
    printf("\nApakah T3 merupakan Tree Kosong? %s", isTreeEmpty(T3)? "true":"false");
    //cek T4
    printf("\nApakah T4 merupakan Tree Kosong? %s", isTreeEmpty(T4)? "true":"false");
    //cek T5
    printf("\nApakah T5 merupakan Tree Kosong? %s", isTreeEmpty(T5)? "true":"false");
    //cek T6
    printf("\nApakah T6 merupakan Tree Kosong? %s", isTreeEmpty(T6)? "true":"false");
    //cek T7
    printf("\nApakah T7 merupakan Tree Kosong? %s", isTreeEmpty(T7)? "true":"false");


    printf("\n\n~~~~~isOneElmt~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 berisi 1 elemen? %s", isOneElmt(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 berisi 1 elemen? %s", isOneElmt(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 berisi 1 elemen? %s", isOneElmt(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 berisi 1 elemen? %s", isOneElmt(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 berisi 1 elemen? %s", isOneElmt(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 berisi 1 elemen? %s", isOneElmt(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 berisi 1 elemen? %s", isOneElmt(T7)? "true":"false");


    printf("\n\n~~~~~isUnerLeft~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 hanya mempunyai subpohon kiri? %s", isUnerLeft(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 hanya mempunyai subpohon kiri? %s", isUnerLeft(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 hanya mempunyai subpohon kiri? %s", isUnerLeft(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 hanya mempunyai subpohon kiri? %s", isUnerLeft(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 hanya mempunyai subpohon kiri? %s", isUnerLeft(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 hanya mempunyai subpohon kiri? %s", isUnerLeft(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 hanya mempunyai subpohon kiri? %s", isUnerLeft(T7)? "true":"false");


    printf("\n\n~~~~~isUnerRight~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 hanya mempunyai subpohon kanan? %s", isUnerRight(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 hanya mempunyai subpohon kanan? %s", isUnerRight(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 hanya mempunyai subpohon kanan? %s", isUnerRight(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 hanya mempunyai subpohon kanan? %s", isUnerRight(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 hanya mempunyai subpohon kanan? %s", isUnerRight(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 hanya mempunyai subpohon kanan? %s", isUnerRight(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 hanya mempunyai subpohon kanan? %s", isUnerRight(T7)? "true":"false");


    printf("\n\n~~~~~isBiner~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 mempunyai subpohon kiri dan kanan? %s", isBiner(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 mempunyai subpohon kiri dan kanan? %s", isBiner(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 mempunyai subpohon kiri dan kanan? %s", isBiner(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 mempunyai subpohon kiri dan kanan? %s", isBiner(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 mempunyai subpohon kiri dan kanan? %s", isBiner(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 mempunyai subpohon kiri dan kanan? %s", isBiner(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 mempunyai subpohon kiri dan kanan? %s", isBiner(T7)? "true":"false");


    printf("\n\n~~~~~PrintPreOrder~~~~~\n");
    printf("PreOrder Tree T1 = ");
    PrintPreOrder(T1);

    printf("\nPreOrder Tree T2 = ");
    PrintPreOrder(T2);

    printf("\nPreOrder Tree T3 = ");
    PrintPreOrder(T3);

    printf("\nPreOrder Tree T4 = ");
    PrintPreOrder(T4);

    printf("\nPreOrder Tree T5 = ");
    PrintPreOrder(T5);

    printf("\nPreOrder Tree T6 = ");
    PrintPreOrder(T6);

    printf("\nPreOrder Tree T7 = ");
    PrintPreOrder(T7);


    printf("\n\n~~~~~PrintInOrder~~~~~\n");
    printf("InOrder Tree T1 = ");
    PrintInOrder(T1);

    printf("\nInOrder Tree T2 = ");
    PrintInOrder(T2);

    printf("\nInOrder Tree T3 = ");
    PrintInOrder(T3);

    printf("\nInOrder Tree T4 = ");
    PrintInOrder(T4);

    printf("\nInOrder Tree T5 = ");
    PrintInOrder(T5);

    printf("\nInOrder Tree T6 = ");
    PrintInOrder(T6);

    printf("\nInOrder Tree T7 = ");
    PrintInOrder(T7);


    printf("\n\n~~~~~PrintPostOrder~~~~~\n");
    printf("PostOrder Tree T1 = ");
    PrintPostOrder(T1);

    printf("\nPostOrder Tree T2 = ");
    PrintPostOrder(T2);

    printf("\nPostOrder Tree T3 = ");
    PrintPostOrder(T3);

    printf("\nPostOrder Tree T4 = ");
    PrintPostOrder(T4);

    printf("\nPostOrder Tree T5 = ");
    PrintPostOrder(T5);

    printf("\nPostOrder Tree T6 = ");
    PrintPostOrder(T6);

    printf("\nPostOrder Tree T7 = ");
    PrintPostOrder(T7);


    printf("\n\n~~~~~SearchTree~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 mempunyai node bernilai 1? %s", SearchTree(T1, 1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 mempunyai node bernilai 1? %s", SearchTree(T2, 1)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 mempunyai node bernilai 2? %s", SearchTree(T3, 2)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 mempunyai node bernilai 2? %s", SearchTree(T4, 2)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 mempunyai node bernilai 3? %s", SearchTree(T5, 3)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 mempunyai node bernilai 3? %s", SearchTree(T6, 3)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 mempunyai node bernilai 4? %s", SearchTree(T7, 4)? "true":"false");


    printf("\n\n~~~~~NbElmt~~~~~\n");
    //cek T1
    printf("Berapa banyak node yang dimiliki Tree T1? %d", NbElmt(T1));
    //cek T2
    printf("\nBerapa banyak node yang dimiliki Tree T2? %d", NbElmt(T2));
    //cek T3
    printf("\nBerapa banyak node yang dimiliki Tree T3? %d", NbElmt(T3));
    //cek T4
    printf("\nBerapa banyak node yang dimiliki Tree T4? %d", NbElmt(T4));
    //cek T5
    printf("\nBerapa banyak node yang dimiliki Tree T5? %d", NbElmt(T5));
    //cek T6
    printf("\nBerapa banyak node yang dimiliki Tree T6? %d", NbElmt(T6));
    //cek T7
    printf("\nBerapa banyak node yang dimiliki Tree T7? %d", NbElmt(T7));


    printf("\n\n~~~~~NBDaun~~~~~\n");
    //cek T1
    printf("Berapa banyak daun yang dimiliki Tree T1? %d", NBDaun(T1));
    //cek T2
    printf("\nBerapa banyak daun yang dimiliki Tree T2? %d", NBDaun(T2));
    //cek T3
    printf("\nBerapa banyak daun yang dimiliki Tree T3? %d", NBDaun(T3));
    //cek T4
    printf("\nBerapa banyak daun yang dimiliki Tree T4? %d", NBDaun(T4));
    //cek T5
    printf("\nBerapa banyak daun yang dimiliki Tree T5? %d", NBDaun(T5));
    //cek T6
    printf("\nBerapa banyak daun yang dimiliki Tree T6? %d", NBDaun(T6));
    //cek T7
    printf("\nBerapa banyak daun yang dimiliki Tree T7? %d", NBDaun(T7));


    printf("\n\n~~~~~isSkewLeft~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 condong ke kiri? %s", isSkewLeft(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 condong ke kiri? %s", isSkewLeft(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 condong ke kiri? %s", isSkewLeft(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 condong ke kiri? %s", isSkewLeft(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 condong ke kiri? %s", isSkewLeft(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 condong ke kiri? %s", isSkewLeft(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 condong ke kiri? %s", isSkewLeft(T7)? "true":"false");


    printf("\n\n~~~~~isSkewRight~~~~~\n");
    //cek T1
    printf("Apakah Tree T1 condong ke kanan? %s", isSkewRight(T1)? "true":"false");
    //cek T2
    printf("\nApakah Tree T2 condong ke kanan? %s", isSkewRight(T2)? "true":"false");
    //cek T3
    printf("\nApakah Tree T3 condong ke kanan? %s", isSkewRight(T3)? "true":"false");
    //cek T4
    printf("\nApakah Tree T4 condong ke kanan? %s", isSkewRight(T4)? "true":"false");
    //cek T5
    printf("\nApakah Tree T5 condong ke kanan? %s", isSkewRight(T5)? "true":"false");
    //cek T6
    printf("\nApakah Tree T6 condong ke kanan? %s", isSkewRight(T6)? "true":"false");
    //cek T7
    printf("\nApakah Tree T7 condong ke kanan? %s", isSkewRight(T7)? "true":"false");


    printf("\n\n~~~~~Level~~~~~\n");
    //cek T1
    printf("Level berapa node 1 pada Tree T1? %d", Level(T1, 1));
    //cek T2
    printf("\nLevel berapa node 1 pada Tree T2? %d", Level(T2, 1));
    //cek T3
    printf("\nLevel berapa node 2 pada Tree T3? %d", Level(T3, 2));
    //cek T4
    printf("\nLevel berapa node 2 pada Tree T4? %d", Level(T4, 2));
    //cek T5
    printf("\nLevel berapa node 3 pada Tree T5? %d", Level(T5, 3));
    //cek T6
    printf("\nLevel berapa node 3 pada Tree T6? %d", Level(T6, 3));
    //cek T7
    printf("\nLevel berapa node 3 pada Tree T7? %d", Level(T7, 3));

    return 0;
}
