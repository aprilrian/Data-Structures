/* Program   : tqueue1.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 30 September 2022 */

#include <stdio.h>
#include "tqueue1.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan '#' }*/
void createQueue(tqueue *Q){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    for(i = 1; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function infoHead(Q:tQueue)-> character
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    if(Q.head == 1){
        return Q.wadah[Q.head];
    }
    else{
        return '#';
    }
}

/*function infoTail(Q:tQueue)-> character
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    if(isEmptyQueue(Q) != true){
        return Q.wadah[Q.tail];
    } else{
        return '#';
    }
}

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    return Q.tail;
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    printf("\nElemen wadah pada queue = ");
    for(i = 1; i <= 5; i++){
        printf("%c; ", Q.wadah[i]);
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}*/
void viewQueue(tqueue Q){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    printf("\nElemen wadah tak kosong pada queue = ");
    if(isEmptyQueue(Q) != true){
        for(i = 1; i <= Q.tail; i++){
            printf("%c; ", Q.wadah[i]);
        }
    } else{
        printf("Queue kosong");
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    if(Q.head == 0 && Q.tail == 0){
        return true;
    } else{
        return false;
    }
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    if(Q.tail == 5){
        return true;
    } else{
        return false;
    }
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    if(Q.tail == 1){
        return true;
    } else{
        return false;
    }
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: Q,E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
    /*Kamus lokal*/

    /*Algoritma*/
    if(isFullQueue(*Q) == false){
        if(isEmptyQueue(*Q) == true){
            (*Q).head = 1;
        }
        (*Q).tail++;
        (*Q).wadah[(*Q).tail] = E;
    } else{
        printf("\nQueue penuh");
    }
}

/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: Q terdefinisi}
{F.S.: E=infohead(Q) atau E='#' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    if(isEmptyQueue(*Q) == false){
        *E = (*Q).wadah[(*Q).head];
        for(i = 1; i <= (*Q).tail-1; i++){
            (*Q).wadah[i] = (*Q).wadah[i+1];
        }
        (*Q).wadah[(*Q).tail] = '#';
        (*Q).tail--;
        if((*Q).tail == 0){
            (*Q).head = 0;
        }
    } else{
        *E = '#';
    }
}

/*function longer(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int longer(tqueue Q1, tqueue Q2){
    /*Kamus lokal*/

    /*Algoritma*/
    if(Q1.tail >= Q2.tail){
        return Q1.tail;
    } else{
        return Q2.tail;
    }
}

/*procedure enqueueShort( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek (salah satu, Q1 atau Q2)} */
void enqueueShort(tqueue *Q1, tqueue *Q2, char E){
    /*Kamus lokal*/

    /*Algoritma*/
    if(isEmptyQueue(*Q1) && isEmptyQueue(*Q2)){
        printf("\nSemua queue sudah penuh");
    } else {
        if((*Q1).tail > (*Q2).tail){
            enqueue((Q2),E);
        } else{
            enqueue((Q1),E);
        }
    }
}

/*procedure deQueueLong( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2, atau E='#' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeueLong(tqueue *Q1, tqueue *Q2, char *E){
    /*Kamus lokal*/

    /*Algoritma*/
    if(isEmptyQueue(*Q1) == true && isEmptyQueue(*Q2) == true){
        *E = '#';
    } else{
        if((*Q1).tail > (*Q2).tail){
            dequeue(Q1,E);
        } else{
            dequeue(Q2,E);
        }
    }
}
