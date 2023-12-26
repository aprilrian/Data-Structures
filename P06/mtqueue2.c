/* Program   : mtqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head dinamis */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 07 October 2022 */

#include <stdio.h>
#include "tqueue2.c"
#include "tqueue2.h"
#include "boolean.h"

int main(){
    /*Kamus Lokal*/
    tqueue2 A, B, C;
    int i;
    char Y;

    /*Algoritma*/
    createQueue2(&A); /*Queue A kosong*/
    createQueue2(&B); /*Queue B penuh*/
    createQueue2(&C); /*Queue C hanya memiliki 1 elemen*/

    for (i = 1; i <= 5; i++){
        B.wadah[i] = 'X';
        B.head = 1;
        B.tail = 5;
    }

    C.wadah[1] = 'X';
    C.head = C.tail = 1;

    (isEmptyQueue2(A)) ? printf("Queue2 A kosong\n") : printf("Queue2 A tidak kosong\n");
    (isFullQueue2(B)) ? printf("Queue2 B penuh\n") : printf("Queue2 B tidak penuh\n");
    (isOneElement2(C)) ? printf("Queue2 C hanya memiliki 1 elemen\n") : printf("Queue2 C tidak hanya memiliki 1 elemen\n");

    printf("\nPosisi head dari queue2 A = %d\n", head2(A));
    printf("Posisi head dari queue2 B = %d\n", head2(B));
    printf("Posisi head dari queue2 C = %d\n", head2(C));

    printf("\nPosisi tail dari queue2 A = %d\n", tail2(A));
    printf("Posisi tail dari queue2 B = %d\n", tail2(B));
    printf("Posisi tail dari queue2 C = %d\n", tail2(C));

    printf("\nNilai elemen head dari queue2 A = %c\n", infoHead2(A));
    printf("Nilai elemen head dari queue2 B = %c\n", infoHead2(B));
    printf("Nilai elemen head dari queue2 C = %c\n", infoHead2(C));

    printf("\nNilai elemen tail dari queue2 A = %c\n", infoTail2(A));
    printf("Nilai elemen tail dari queue2 B = %c\n", infoTail2(B));
    printf("Nilai elemen tail dari queue2 C = %c\n", infoTail2(C));

    printf("\nPanjang queue2 A = %d\n", sizeQueue2(A));
    printf("Panjang queue2 B = %d\n", sizeQueue2(B));
    printf("Panjang queue2 C = %d\n", sizeQueue2(C));

    printf("\nSeluruh isi wadah queue2 A adalah :");
    printQueue2(A);
    printf("\nSeluruh isi wadah queue2 B adalah :");
    printQueue2(B);
    printf("\nSeluruh isi wadah queue2 C adalah :");
    printQueue2(C);

    printf("\nSeluruh elemen tidak kosong queue2 A : ");
    viewQueue2(A);

    printf("\n\nSeluruh elemen tidak kosong queue2 B : ");
    viewQueue2(B);

    printf("\n\nSeluruh elemen tidak kosong queue2 C : ");
    viewQueue2(C);
    
    printf("\n");
    (isTailStop(A)) ? printf("\nTail queue2 A tidak dapat digeser") : printf("\nTail queue2 A masih bisa digeser");
    (isTailStop(B)) ? printf("\nTail queue2 B tidak dapat digeser") : printf("\nTail queue2 B masih bisa digeser");
    (isTailStop(C)) ? printf("\nTail queue2 C tidak dapat digeser") : printf("\nTail queue2 C masih bisa digeser");

    enqueue2(&A, 'A');
    enqueue2(&C, 'X');

    printf("\n");
    printQueue2(A);
    printf("\n");
    printQueue2(C);

    dequeue2(&B, &Y);

    printf("\n");
    printQueue2(B);

    enqueue2N(&A, 3);



    
    return 0;



}