#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
#include <stdio.h>

/* Program   : tabel.c */
/* Deskripsi : realisasi file program tabel */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian */
/* Tanggal   : 15 September 2022 */
				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
	(*T).size = 0; //ruang array yang terisi (panjang array terisi)
	for (i > 0; i <= 10; i++){
		(*T).wadah[i] = -999;
	}
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
	/*Kamus Lokal*/
	int i;
			
	/*Algoritma*/
	if (T.size > 0){
		for (i = 1; i <= T.size; i++){
			printf("Elemen ke%d = %d\n", i, T.wadah[i]);
		}
	} else{
		printf("Tabel kosong\n");
	}
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
	/*Kamus Lokal*/
	int i;
	
	/*Algoritma*/
	if (T.size > 0){
		for (i = 1; i <= T.size; i++){
			printf("Elemen terisi pada wadah ke-%d\n", i);
		} 
	} else{
		printf("Tidak ada elemen yang terisi\n");
	}
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
	return 10 - T.size;
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if (T.size == 0){
		printf("Tabel merupakan tabel kosong\n");
	} else{
		printf("Tabel tidak merupakan tabel kosong\n");
	}
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if (T.size == 10){
		printf("Tabel penuh\n");
	} else{
		printf("Tabel tidak penuh\n");
	}
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
	/*Kamus Lokal*/
	int i;
	int x;
	
	/*Algoritma*/
	printf("Berapa banyak elemen yang ingin dimasukkan?\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		printf("Masukkan elemen ke-%d\n", i);
		scanf("%d", &x);
		if (x > 0){
			(*T).wadah[i] = x;
		} else{
			printf("Angka harus lebih dari 0\n");
		}
	}
	(*T).size = N;
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
	/*Kamus Lokal*/
	int i;
	
	/*Algoritma*/
	*Pos = 1;
	if (T.size == 0){
		printf("Tabel tidak memiliki nilai (kosong\n");
	}
	else if (T.size > 0 && T.size <= 10)
	{
		for (i = 1; i <= T.size; i++)
		{
			if (T.wadah[i] == X)
			{
				(*Pos) = i + 1;
				break;
			}
			else
			{
				(*Pos) = -999;
			}
		}
		if (*Pos == -999)
		{
			printf("Nilai tidak ketemu (-999)\n");
		}
		else
		{
			printf("nilai yang dicari ada di posisi ke : %d\n", Pos);
		}
	}
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
	/*Kamus Lokal*/
	int i;
	
	/*Algoritma*/
	for (i = 1; i <= T.size; i++)
	{
		if (T.wadah[i] == X)
		{
			(Byk) = (Byk) + 1;
		}
	}
	printf("Nilai %d ada sebanyak : %d\n", X, Byk);
}

/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
	/*Kamus Lokal*/
	int i;
	int jumlah;
	
	/*Algoritma*/
	for (i = 1; i < T.size; i++){
		jumlah = jumlah + T.wadah[i];
	}
	return jumlah;
}

/*function AverageEl ( T:Tabel ) -> integer 
	{mengembalikan nilai rata-rata elemen pengisi T } */
int AverageEl (Tabel T){
	/*Kamus Lokal*/
	int SumE1;
	
	/*Algoritma*/
	return SumE1 / T.size;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
	/*Kamus Lokal*/
	int i, max;
	
	/*Algoritma*/
	max=T.wadah[1];
    for(i = 2; i <= 10; i++){
        if (T.wadah[i] > max){
            max = T.wadah[i];
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
	/*Kamus Lokal*/
	int i, min;
	
	/*Algoritma*/
	min = T.wadah[1];
    for(i = 2; i <= 10; i++){
        if(T.wadah[i] < min){
            min = T.wadah[i];
        }
    }
    return min;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
	/*Kamus Lokal*/
	int i, x;
	
	/*Algoritma*/
	for (i=1; i <= 10; i++){
        printf("\nisi wadah dengan elemen positif: ", i); scanf("%d", &x);
        if (x < 1){
            break;
        }
        else{
            (*T).wadah[i] = x;
        }
    }(*T).size = i;
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
	/*Kamus Lokal*/
	int i;
	
	/*Algoritma*/
	while ((*T).size != 10){
        if((*T).wadah[i] == -999){
            (*T).wadah[i] = X;
            (*T).size = (*T).size +1;
            break;
        }
        i++;
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
	/*Kamus Lokal*/
	int i;
	
	/*Algoritma*/
	if((*T).size!=0){
        i=1;
        while((*T).wadah[i]!=X && i<(*T).size){
            i++;
        }
        if((*T).wadah[i]==X){
            while(i<(*T).size){
                (*T).wadah[i]=(*T).wadah[i+1];
                i++;
            }
            (*T).wadah[i] = -999;
        }
        (*T).size-=1;
    }
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
	/*Kamus Lokal*/
	int i, Byk;
	
	/*Algoritma*/
	countX(*T, X, &Byk);
    for(i=1; i<=Byk; i++){
        delXTable(T, X);
    }
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
	/*Kamus Lokal*/
	int i, j, maxcount = 0, many;
	
	/*Algoritma*/
	 for( i=1;i<=10;i++)
    {
        int count=0;
        for( j=1;j<=10;j++)
        {
            if(T.wadah[i] == T.wadah[j]){
                count++;
            }
        }
        if(count>maxcount)
        {
            maxcount=count;
            many = T.wadah[i];
        }
    }
    return many;
}

#endif
