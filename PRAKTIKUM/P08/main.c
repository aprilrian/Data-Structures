/* Nama File : main.c */
/* Deskripsi : driver modul main fungsi list */
/* Pembuat   : Aprilyanto Setiyawan Siburian (24060121120022) */
/* Tanggal   : 02 November 2022 22:15:20*/

#include "list.c"

int main(){
    /*Kamus Lokal*/
    List A;
    address X, Y, Z, U, Last, temp;
    int temp_nilai;
    char temp_alamat, jwb;
    infotype P,Q,R,S;
    
    /*Algoritma*/
    printf("----- Pembuatan dan Test List Kosong -----\n");
    CreateList(&A);
    ListEmpty(A) ? printf("List A kosong\n") : printf("List A tidak kosong\n");
    printf("\n");

    printf("----- Manajemen Memori -----\n");
    printf("Masukkan nilai alokasi untuk alamat X : ");
    scanf("%d", &temp_nilai);
    X = Alokasi(temp_nilai);
    printf("Info alamat X setelah dialokasi= %d\n", info(X));
    Dealokasi(&X);
    info(X) != temp_nilai ? printf("Info alamat X setelah didealokasi = Nil\n"): 
                   printf("Proses dealokasi gagal\n");
    printf("\n");

    printf("----- InsertFirst ------\n");
    printf("List A sebelumnya kosong\n");
    printf("Masukkan nilai alokasi alamat X yang akan ditambahkan ke List A : ");
    scanf("%d", &temp_nilai);
    X = Alokasi(temp_nilai);
    InsertFirst(&A, X);
    printf("Masukkan nilai alokasi alamat Y yang akan ditambahkan ke List A : ");
    scanf("%d", &temp_nilai);
    Y = Alokasi(temp_nilai);
    InsertFirst(&A, Y);
    printf("Masukkan nilai alokasi alamat Z yang akan ditambahkan ke List A : ");
    scanf("%d", &temp_nilai);
    Z = Alokasi(temp_nilai);
    InsertFirst(&A, Z);
    printf("List A : ");
    PrintInfo(A);
    printf("\n");

    printf("----- InsertAfter ------\n");
    printf("Masukkan alamat sebagai Prec (X/Y/Z) : ");
    fflush(stdin);
    scanf("%c", &temp_alamat);
    printf("Masukkan nilai alokasi alamat U yang akan ditambahkan setelah Prec ke List A : ");
    scanf("%d", &temp_nilai);
    U = Alokasi(temp_nilai);
    if(temp_alamat == 'X'){
        InsertAfter(&A, U, X);
    }
    else if (temp_alamat == 'Y'){
        InsertAfter(&A, U, Y);
    }
    else if (temp_alamat == 'Z'){
        InsertAfter(&A, U, Z);
    }
    else {
        printf("Hanya ada alamat X, Y, dan Z pada List A\n");
    }
    printf("List A : ");
    PrintInfo(A);
    printf("\n");

    printf("----- InsertLast ------\n");
    printf("Masukkan nilai alokasi alamat Last yang akan ditambahkan sebagai elemen terakhir List A : ");
    scanf("%d", &temp_nilai);
    X = Alokasi(temp_nilai);
    InsertLast(&A, X);
    printf("List A : ");
    PrintInfo(A);
    printf("\n");

    printf("----- DelFirst ------\n");
    printf("Apakah anda ingin menghapus elemen pertama dari List A?\nJawab [Y/N] : ");
    fflush(stdin);
    scanf("%c", &jwb);
    jwb == 'Y' ? printf("List A : ") : printf("Maaf, tetapi supaya programnya berjalan dan saya tidak terlalu telat jadi List A : ");
    DelFirst(&A, &X);
    PrintInfo(A);
    printf("\n");

    printf("----- DelLast ------\n");
    printf("Apakah anda ingin menghapus elemen terakhir dari List A?\nJawab [Y/N] : ");
    fflush(stdin);
    scanf("%c", &jwb);
    jwb == 'Y' ? printf("List A : ") : printf("Maaf, tetapi supaya programnya berjalan dan saya tidak terlalu telat jadi List A : ");
    DelLast(&A, &X);
    PrintInfo(A);
    printf("\n");

    printf("----- DelAfter ------\n");
    printf("Masukkan alamat sebagai Prec (U/X/Y): ");
    fflush(stdin);
    scanf("%c", &temp_alamat);
    if (temp_alamat == 'X'){
        DelAfter(&A, &temp, X);
    }
    else if (temp_alamat == 'Y'){
        DelAfter(&A, &temp, Y);
    }
    else if (temp_alamat == 'U'){
        DelAfter(&A, &temp, U);
    }
    else {
        printf("Hanya ada alamat U, X, dan pada List A.\n");
    }
    printf("List A : ");
    PrintInfo(A);
    printf("\n");

    printf("----- InsVFirst ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Masukkan nilai alokasi 1 ke First A\nList A: ");
    InsVFirst(&A, 1);
    PrintInfo(A);


    printf("\n\n----- InsVLast ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Masukkan nilai alokasi 11 ke Last A\nList A: ");
    InsVLast(&A, 11);
    PrintInfo(A);


    printf("\n\n----- InsVAfter ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Masukkan nilai alokasi 7 setelah info = 5 (address)\nList A: ");
    InsVAfter(&A, P);
    PrintInfo(A);

    printf("\n\n----- DelVFirst ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Hapus nilai First A (address) dan Dealokasi\nList A: ");
    DelVFirst(&A, &Q);
    PrintInfo(A);
    printf("Nilai Dealokasi : %d\n", Q);


    printf("\n\n----- DelVLast ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Hapus nilai Last A (address) dan Dealokasi\nList A: ");
    DelVLast(&A, &R);
    PrintInfo(A);
    printf("Nilai Dealokasi : %d\n", R);

    printf("\n\n----- DelVAfter ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Hapus nilai 7 (address) setelah info = 5 (address) dan Dealokasi\nList A: ");
    DelVAfter(&A, &S);
    PrintInfo(A);
    printf("Nilai Dealokasi : %d\n", S);


    printf("\n\n----- NbElmt ------\n");
    printf("List A: ");
    PrintInfo(A);
    printf("Banyak elemen : %d\n\n", NbElmt(A));
}