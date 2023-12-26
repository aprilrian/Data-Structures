/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060121120022/Aprilyanto Setiyawan Siburian*/
/* Tanggal   : 2 September 2022*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include <math.h>

/*KONSTRUKTOR*/
/* procedure makeTitik(output T:Titik)*/
/*{I.S.: -}*/
/*{F.S.: T terdefinisi}*/
/*{proses: mengisi nilai komponen absis dan ordinat T dengan 0}*/
void makeTitik(Titik *T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).absis = 0;
	(*T).ordinat = 0;	
}

/*DESTRUKTOR*/

/*SELEKTOR*/
/*function getAbsis(T:Titik)->integer*/
/*{mengembalikan nilai komponen absis T}*/
int getAbsis(Titik T){
	/*Kamus Lokal*/
	int Absis;

	/*Algoritma*/
	Absis = T.absis;
	
	return Absis;
}

/*function getOrdinat(T:Titik)->integer*/
/*{mengembalikan nilai komponen ordinat T}*/
int getOrdinat(Titik T){
	/*Kamus Lokal*/
	int Ordinat;
	
	/*Algoritma*/
	Ordinat = T.ordinat;
	
	return Ordinat;
}

/*MUTATOR*/
/*procedure setAbsis(input/output T, input xx)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.absis=xx}*/
/*{proses: mengisi nilai komponen absis T}*/
void setAbsis(Titik *T, int xx){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).absis = (*T).absis + xx;
}

/*procedure setOrdinat(input/output T, input yy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.ordinat=yy}*/
/*{proses: mengisi nilai komponen ordinat T}*/
void setOrdinat(Titik *T, int yy){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).ordinat = (*T).ordinat + yy;
}

/*PREDIKAT*/
/*function isOrigin(T:Titik)->boolean*/
/*{mengembalikan true jika Titik T ada di persilangan sumbu X dan Y}*/
boolean isOrigin(Titik T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if ((T.absis == 0) && (T.ordinat == 0)){
		return true;
		
		} else{
			return false;
		}
}

/*SUBRUTIN LAIN*/
/*procedure geserXY(input/output T:Titik, input dx, input dy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T bergeser sejauh (dx,dy)}*/
/*{proses: mengubah nilai komponen absis dan ordinat T}*/
void geserXY(Titik *T, int dx, int dy){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).absis = (*T).absis + dx;
	(*T).ordinat = (*T).ordinat + dy;
}

/*procedure refleksiSumbuX(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu X }*/
/*{proses: mengubah nilai komponen ordinat T}*/
void refleksiSumbuX(Titik *T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).ordinat = (*T).ordinat * -1;
}

/*procedure refleksiSumbuY(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu Y }*/
/*{proses: mengubah nilai komponen absis T}*/
void refleksiSumbuY(Titik *T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	(*T).absis = (*T).absis * -1;
}

/*function Kuadran(T:Titik)->integer*/
/*{mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4}*/
/*{asumsi: bila titik memotong sumbu, maka nilai 0 dianggap positif}*/
int Kuadran(Titik T){
	/*Kamus Lokal*/
	
	/*Algoritma*/
	if (T.absis > 0 && T.ordinat > 0){
		return 1;
	} else if (T.absis < 0 && T.ordinat > 0){
		return 2;
	} else if (T.absis < 0 && T.ordinat < 0){
		return 3;
	} else if (T.absis > 0 && T.ordinat < 0){
		return 4;
	}
}

/*function Jarak(T1:Titik, T2:Titik)->real*/
/*{mengembalikan jarak euclidian titik T1 dan T2}*/
/*{asumsi: aplikasikan rumus Pitagoras dan fungsi akar sqrt}*/
int Jarak(Titik T1, Titik T2){
	/*Kamus Lokal*/
	float JarakTitik; //Jarak : real
	int hasilX; //hasilX : integer
	int hasilY; //hasilY : integer
	int total; //hasil : integer
	int kuadrat; //kuadrat : integer
	
	/*Algoritma*/
	hasilX = T1.absis - T2.absis;
	hasilY = T1.ordinat - T2.ordinat;
	total = hasilX + hasilY;
	kuadrat = pow(total,2);
	JarakTitik = sqrt(kuadrat);
	
	return JarakTitik;
}
