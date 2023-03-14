/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head dinamis */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 07 October 2022 */

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
void createQueue2(tqueue2 *Q){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    for (i = 1; i <= 5; i++){
        (*Q).wadah[i] = '@';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return ((Q.head == 0) && (Q.tail == 0)) ? true : false;
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return ((Q.head == 1) && (Q.tail == 5)) ? true : false;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return (Q.head == Q.tail) ? true : false;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return (isEmptyQueue2(Q) == false) ? Q.wadah[Q.head] : '@';
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return (isEmptyQueue2(Q) == false) ? Q.wadah[Q.tail] : '@';
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return (isEmptyQueue2(Q)) ? 0 : Q.tail;
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    int i;
    
    /*Algoritma*/
    if(isEmptyQueue2(Q)){
        printf(" Queue2 kosong");
    } else {
        for(i = 1; i <= 5; i++){
            printf(" %c; ", Q.wadah[i]);
        }
    }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    /*Kamus Lokal*/
    int i;

    /*Algoritma*/
    if(isEmptyQueue2(Q)){
        printf("\nSemua elemen Queue2 kosong");
    } else {
        printf("\n");
        for(i = 1; i <= 5; i++){
            if(Q.wadah[i] != '@'){
                printf("%c; ", Q.wadah[i]);
        }
    }
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    return (Q.tail == 5) && (Q.head > 0);
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    /*Kamus Lokal*/
    int i, jump;
    
    /*Algoritma*/
    if(((*Q).head > 0) && ((*Q).tail) == 5){
        jump = (*Q).head - 1;
        for(i = Q->head; i <= Q->tail; i++){
            (*Q).wadah[i - jump] = (*Q).wadah[i];
            (*Q).wadah[i] = '@';
        }
        Q->head = 1;
        Q->tail = Q->tail - jump;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    if(isEmptyQueue2(*Q)){
        (*Q).head = 1;
        (*Q).tail = 1;
        (*Q).wadah[(*Q).tail] = E;
    } else {
        if(!isFullQueue2(*Q)){
            if(isTailStop(*Q)){
                resetHead(&(*Q));
                (*Q).tail = (*Q).tail + 1;
                (*Q).wadah[(*Q).tail] = E;
            }
            
        }
        (*Q).tail = (*Q).tail + 1;
        (*Q).wadah[(*Q).tail] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    *E = '@';
    if(!isEmptyQueue2(*Q)){
        *E = infoHead2(*Q);
        (*Q).wadah[(*Q).head] = '@';
        (*Q).head = (*Q).head + 1;
        if((*Q).head > (*Q).tail){
            createQueue2(Q);
        }
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    /*Kamus Lokal*/
    int i;
    char inputQueue2N;

    /*Algoritma*/
    if(N <= (*Q).tail){
        if(!isFullQueue2(*Q)){
            for (i = 1; i <= N; i++)
                printf("Masukkan element : ");
                scanf("%c", &inputQueue2N);
                enqueue2(&(*Q), inputQueue2N);
        }    
    }
}