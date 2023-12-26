/* Program   : main.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 30 September 2022 */

#include <stdio.h>
#include <stdlib.h>
#include "tqueue1.c"
#include "tqueue1.h"
#include "boolean.h"

int main()
{
    /*Kamus Lokal*/
    tqueue A, B;
    char head, tail, X, Y, Z;
    int size, panjangMana;

    /*Algoritma*/
    createQueue(&A); 
    createQueue(&B);

    head = infoHead(A);
    printf("Head dari queue A = %c", head);

    tail = infoTail(A);
    printf("\nTail dari queue A = %c", tail);

    size = sizeQueue(A);
    printf("\nSize dari queue A = %d", size);

    A.head = 1;
    A.tail = 4;
    A.wadah[1] = 'A';
    A.wadah[2] = 'B';
    A.wadah[3] = 'C';
    A.wadah[4] = 'D';

    printQueue(A);
    viewQueue(A);
    if(isEmptyQueue(A)){
        printf("\nQueue kosong");
    } else{
        printf("\nQueue tidak kosong");
    }

    if(isFullQueue(A)){
        printf("\nQueue penuh");
    } else{
        printf("\nQueue tidak penuh");
    }

    if(isOneElement(A)){
        printf("\nQueue hanya berisi 1 elemen");
    } else{
        printf("\nQueue berisi lebih dari 1 elemen");
    }

    printf("\n\nENQUEUE");
    enqueue(&A, 'X');
    printQueue(A);

    printf("\n\nDEQUEUE");
    dequeue(&A, &Z);
    printQueue(A);

    panjangMana = longer(A, B);
    printf("\nUkuran terpanjang dari 2 queue = %d", panjangMana);

    printf("\n\nENQUEUE SHORT");
    enqueueShort(&A, &B, 'Y');
    printQueue(A);
    printQueue(B);

    printf("\n\nDEQUEUE LONG");
    dequeueLong(&A, &B, &Z);
    printQueue(A);
    printQueue(B);


    return 0;
}
