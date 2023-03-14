/* Nama File : main.c */
/* Deskripsi : driver modul main fungsi list */
/* Pembuat   : Aprilyanto Setiyawan Siburian (24060121120022) */
/* Tanggal   : 02 November 2022 22:15:20*/

#include "list.h"

int main(){
    /*Kamus Lokal*/
    List L, M, L2, L3, L4, L5, L6, L7;
    address P1, P2, P3, Q1, Q2, Q3, R1, R2, R3;
    infotype i1, i2, i3;

    /*Algoritma*/
    printf("\n~~~~~CreateList~~~~~\n");
    CreateList(&L);
    CreateList(&M);
    CreateList(&L6);
    CreateList(&L7);
    printf("Membuat List menjadi kosong \nList L: \nList M: \n");


    printf("\n\n~~~~~ListEmpty~~~~~\n");
    if (ListEmpty(L)){
        printf("True --> List L Kosong\n");
    }
    else{
        printf("False --> List L Tidak Kosong\n");
    }


    printf("\n\n~~~~~InsertFirst~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Masukkan nilai 9 (address) ke First L \nList L: ");
    P3 = Alokasi(9);
    InsertFirst(&L, P3);
    PrintInfo(L);
    printf("Masukkan nilai 3 (address) ke First L \nList L: ");
    P2 = Alokasi(3);
    InsertFirst(&L, P2);
    PrintInfo(L);
    printf("Masukkan nilai 1 (address) ke First L \nList L: ");
    P1 = Alokasi(1);
    InsertFirst(&L, P1);
    PrintInfo(L);


    printf("\n\n~~~~~InsertAfter~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Masukkan nilai 5 (address) setelah info = 3 (address)\nList L: ");
    Q1 = Alokasi(5);
    InsertAfter(&L, Q1, P2);
    PrintInfo(L);
    printf("Masukkan nilai 7 (address) setelah info = 5 (address)\nList L: ");
    Q2 = Alokasi(7);
    InsertAfter(&L, Q2, Q1);
    PrintInfo(L);


    printf("\n\n~~~~~InsertLast~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Masukkan nilai 11 (address) pada Last L\nList L: ");
    Q3 = Alokasi(11);
    InsertLast(&L, Q3);
    PrintInfo(L);


    printf("\n\n~~~~~DelFirst~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Hapus nilai First L (address) dari List L\nList L: ");
    DelFirst(&L, &P1);
    PrintInfo(L);


    printf("\n\n~~~~~DelLast~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nHapus nilai Last L (address) dari List L\nList L: ");
    DelLast(&L, &Q3);
    PrintInfo(L);


    printf("\n\n~~~~~DelAfter~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Hapus nilai 7 (address) setelah info = 5 (address)\nList L: ");
    DelAfter(&L, &Q2, Q1);
    PrintInfo(L);


    printf("\n\n~~~~~InsVFirst~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nMasukkan nilai alokasi 1 ke First L\nList L: ");
    InsVFirst(&L, 1);
    PrintInfo(L);


    printf("\n\n~~~~~InsVLast~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nMasukkan nilai alokasi 11 ke Last L\nList L: ");
    InsVLast(&L, 11);
    PrintInfo(L);


    printf("\n\n~~~~~InsVAfter~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nMasukkan nilai alokasi 7 setelah info = 5 (address)\nList L: ");
    InsVAfter(&L, 7, Q1);
    PrintInfo(L);

    printf("\n\n~~~~~DelVFirst~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Hapus nilai First L (address) dan Dealokasi\nList L: ");
    DelVFirst(&L, &i1);
    PrintInfo(L);
    printf("Nilai Dealokasi : %d\n", i1);


    printf("\n\n~~~~~DelVLast~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nHapus nilai Last L (address) dan Dealokasi\nList L: ");
    DelVLast(&L, &i2);
    PrintInfo(L);
    printf("Nilai Dealokasi : %d\n", i2);


    printf("\n\n~~~~~DelVAfter~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("\nHapus nilai 7 (address) setelah info = 5 (address) dan Dealokasi\nList L: ");
    DelVAfter(&L, &i3, Q1);
    PrintInfo(L);
    printf("Nilai Dealokasi : %d\n", i3);


    printf("\n\n~~~~~NbElmt~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Banyak elemen : %d \n", NbElmt(L));

    printf("\n\n~~~~~FSearch~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("Apakah terdapat elemen list yang beralamat 5?\n");
    
    R1 = Alokasi(5);
    if (FSearch(L, R1)){
        printf("True --> terdapat elemen list beralamat 5");
    }
    else {
        printf("False --> tidak terdapat elemen list beralamat 5");
    }

    printf("\n\n~~~~~InversList~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    InversList(&L);
    printf("List L: ");
    PrintInfo(L);

    printf("\n\n~~~~~FInversList~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("List M: ");
    PrintInfo(M);
    FInversList(L, &M);
    printf("List M: ");
    PrintInfo(M);

    printf("\n\n~~~~~CopyList~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("List L2: ");
    PrintInfo(L2);
    CopyList(&L, &L2);
    printf("List L2: ");
    PrintInfo(L2);

    printf("\n\n~~~~~FCopyList~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("List L3: ");
    PrintInfo(L3);
    FCopyList(L, &L3);
    printf("List L3: ");
    PrintInfo(L3);

    printf("\n\n~~~~~Konkat~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("List L3: ");
    PrintInfo(L3);
    Konkat(L, L3, &L4);
    printf("List L4: ");
    PrintInfo(L4);

    printf("\n\n~~~~~Konkat1~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    printf("List L3: ");
    PrintInfo(L3);
    Konkat1(&L, &L3, &L5);
    printf("List L: ");
    PrintInfo(L);
    printf("List L3: ");
    PrintInfo(L3);
    printf("List L5: ");
    PrintInfo(L5);

    printf("\n\n~~~~~PecahList~~~~~\n");
    printf("List L5: ");
    PrintInfo(L5);
    printf("List L6: ");
    PrintInfo(L6);
    printf("List L7: ");
    PrintInfo(L7);
    PecahList(&L6, &L7, L5);
    printf("List L6: ");
    PrintInfo(L6);
    printf("List L7: ");
    PrintInfo(L7);
    printf("List L5: ");
    PrintInfo(L5);

    printf("\n\n~~~~~DelAll~~~~~\n");
    printf("List L: ");
    PrintInfo(L);
    DelAll(&L);
    printf("List L: ");
    PrintInfo(L);
}