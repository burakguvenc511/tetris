#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[94m"
#define ORANGE "\033[38;5;208m"

int i,j;
int donme_sayi;
int eleman[4][2];
int yukseklik=0;
int yon=0;
int enust;			
int random=0;
int randomrenk;
int puan=0;
char alan[20][9];
char sabitalan[20][9];
char renkler[20][9];
char renk;

// L �ekli ve d�m�� �ekilleri i�eren kod										b
void Sekil_L(){
	if(donme_sayi>3)		{	donme_sayi=0;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// L �ekli saat y�n�nde �evrilmi� hali
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][4+yon]='0'; eleman[1][0]=3+yukseklik; eleman[1][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// L �ekli 180 derece d�nd�r�lm�� hali
		case 2: alan[2+yukseklik][3+yon]='0'; eleman[0][0]=2+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// L �ekli saat y�n� tersine �evrilmi� hali	
		case 3: alan[3+yukseklik][4+yon]='0'; eleman[0][0]=3+yukseklik; eleman[0][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][5+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// L �ekli
	}
	
}

// Ters L �ekli ve d�n�� �ekilleri i�eren kod									u
void Sekil_Ters_L(){
	
	if(donme_sayi>3)		{	donme_sayi=0;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][2+yon]='0'; eleman[2][0]=3+yukseklik; eleman[2][1]=2+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// ters L �ekli
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// ters L �ekli saat y�n�nde d�nd�r�lm�� hali
		case 2: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// // ters L �ekli 180 derece d�nd�r�lm�� hali
		case 3: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// ters L �ekli saat y�n�n�n tersine d�nd�r�lm�� hali
	}
	
}

// wasd �eklinde olu�an �ekil vc d�n��lerini i�eren kod							r
void Sekil_wasd(){
	if(donme_sayi>3)		{	donme_sayi=0;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][2+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=2+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// wasd �eklinde �izilmi� �ekil
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// wasd �eklinin saat y��n�nde �izilmi� hali
		case 2: alan[1+yukseklik][2+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=2+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][3+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// wasd �eklinin 180 derece �izilmi� hali
		case 3: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][2+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=2+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// wasd �eklinin saat y��n�n�n tersine �izilmi� hali
	}
}

// | �ekli ve d�n�� �ekillerini i�eren kod										a
void Sekil_Cubuk(){
	
	if(donme_sayi>2)		{	donme_sayi=0;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	else if(donme_sayi<0)	{	donme_sayi=1;	}	// d�nd�rme durumunda case s�n�r� a��l��rsa s�f�rlama yapmak i�in
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[2][0]=3+yukseklik; eleman[2][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[4+yukseklik][3+yon]='0'; eleman[3][0]=4+yukseklik; eleman[3][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// | �ekli
		case 1: alan[1+yukseklik][2+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=2+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][3+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
			break;	// | �eklinin d�d�r�lm�� hali
	}	
}

// kare �eklini i�eren kod														k
void Sekil_kare(){
	alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
	alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
	alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
	alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon; 	// �eklin koortdinatlar� eleman isimli diziye kaydediliyor
}

// �al��acak �ekli belirleyen kod
void Sekil_Sec(bool nullmu){
	
	if(nullmu){										// tur bittiyse ve yeni �ekil atanacaksa giriliyor
		srand(time(NULL));							// her turfarkl� bir de�er gelmesi i�in
		random=rand()%20;							// 20 say� aras�ndan se�im yap�yor
		randomrenk=rand()%20;						// 20 say� aras�ndan se�im yap�yor
		randomrenk%=5;								// renk say�m�z olan 5 e mod al�p gelen say� kaydediliyor
		random%=5;									// �ekil say�m�z olan 5 e mod al�p gelen say� kaydediliyor
		
	}
	switch(random){
		case 0:	Sekil_L(); 		break;				// L �ekli se�ildi.
		case 1:	Sekil_Ters_L(); break;				// L �ekli tersi se�ildi.
		case 2:	Sekil_wasd(); 	break;				// wasd �ekli se�ildi.
		case 3:	Sekil_Cubuk(); 	break;				// cubuk �ekli se�ildi.
		case 4:	Sekil_kare(); 	break;				// kare �ekli se�ildi. 
	}
	switch(randomrenk){
		case 0:	renk='R';		break;				// k�rm�z� rengi se�ildi.
		case 1:	renk='G';		break;				// ye�il rengi se�ildi.
		case 2:	renk='Y';	 	break;				// sar� rengi  se�ildi.
		case 3:	renk='B'; 		break;				// mavi rengi se�ildi.
		case 4:	renk='O';		break;				// turuncu rengi se�ildi. 
	}
}

// �eklin q ve e tu�lar� ile d�n���n� kontrol eder								g
bool donebilir_mi(char yon){
	if(yon=='q')		{ donme_sayi--; }				// d�nd�r�lmek istenen yon bilgisi al�n�p kontrol ama�l� d�nd�r�lecek
	else if(yon=='e') 	{ donme_sayi++;	}				// d�nd�r�lmek istenen yon bilgisi al�n�p kontrol ama�l� d�nd�r�lecek
	
	int deger=-1;										// en soldayken sola en sa�dayken saga d�n��� �lemek i�in
	for(i=0;i<4;i++){									// eleman dizisi gezmek i�in
		if(eleman[i][1]==0)		{ deger=0;	}			// eleman en soldaysa degeri 0 olarak sakla
		else if(eleman[i][1]==8){ deger=8;	}			// eleman en sa�ga ise de�eri 8 olarak sakla
	}
	Sekil_Sec(false);										// d�nd�rme i�lemi yap�ld�
	for(i=0;i<4;i++){									// eleman dizisini gezmek i�in
		if(deger==0 && eleman[i][1]==-1){ if(yon=='q'){ donme_sayi++; }else if(yon=='e'){ donme_sayi--;	}Sekil_Sec(false);	return false;}
		if(deger==8 && eleman[i][1]== 9){ if(yon=='q'){ donme_sayi++; }else if(yon=='e'){ donme_sayi--;	}Sekil_Sec(false);	return false;}
		// de�er 0 iken yani �ekil en soldayken elemanlardan herhangi birini j de�eri -1 olursa d�n�� hatal�d�r
		// de�er 8 iken yani �ekil en sagdayken elemanlardan herhangi birini j de�eri 9 olursa d�n�� hatal�d�r
	}
	
	for(i=0;i<4;i++){									// eleman dizisinde gezinmek i�in
		if(sabitalan[eleman[i][0]][eleman[i][1]]=='0'){	// d�n�� sonras�ndaki karelerde 0 de�eri var m� diye kontrol i�in sabitalan dizisi kullan�l�yor.
				if(yon=='q')		{ donme_sayi++; }	// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
				else if(yon=='e') 	{ donme_sayi--;	}	// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
				Sekil_Sec(false);							// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
			return false;								// sabitalan i�erisinde kontrol edilen noktalarda 0 varsa donme i�lemi yap�lamaz. false
		}
	}
	if(yon=='q')		{ donme_sayi++; }				// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
	else if(yon=='e') 	{ donme_sayi--;	}				// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
	Sekil_Sec(false);										// sistemin �al��mas� i�in yap�lan d�n�� geri al�narak eski haline getiriliyor
	return true;										// sabitalan i�erisinde kontrol edilen noktalarda 0 yoksa donme i�lemi yap�labilir. true
}

// t�m alan�n �izimleri burada yap�l�yor										�
void alanyaz(){
	printf("PUAN : %d\n",puan);
	printf("___________\n");						// �st s�n�r �izgisi
	for(i=0;i<20;i++){								// 20*9 luk matr�s
		printf("|");								// en sol k�s�m | i�areti ile kapat�larak s�n�r belirleniyor
		for(j=0;j<9;j++){							// matrisin ikinci k�sm� olan 20*9 luk alan	
			if(i==4 && alan[i][j]!='0'){			// �ekillerin d��meden �nceki yeri ile d��ecekleri oyun s�n�r� aras�n� belirliyor
				alan[4][j]='_';						// s�n�r belirginle�tirmek i�in _ i�areti kullan�yoruz
				printf("%C",alan[i][j]);			// 4. st�rdaki s�n�r �izgisi yazd�r�lmas� i�in
			}
			if(sabitalan[i][j]=='0'){				// sabit alan 0 ise yani doluysa rengine g�re yazd�r�lacak
				if(renkler[i][j]=='R')		{	printf(RED 	  "%c"RESET,sabitalan[i][j] );	}	// renk k�rm�z� ise
				else if(renkler[i][j]=='G')	{	printf(GREEN  "%c"RESET,sabitalan[i][j] );	}	// renk ye�il ise
				else if(renkler[i][j]=='Y')	{	printf(YELLOW "%c"RESET,sabitalan[i][j] );	}	// renk sar� ise
				else if(renkler[i][j]=='B')	{	printf(BLUE   "%c"RESET,sabitalan[i][j] );	}	// renk mavi ise
				else if(renkler[i][j]=='O')	{	printf(ORANGE "%c"RESET,sabitalan[i][j] );	}	// renk turuncu ise
			}
			else if(alan[i][j]==' '){			// alan de�eri bo� ise yan� eleman dizisi d���ndaki karakterler i�in bo� yazd�r�lacak
				printf(" ");	
			}
			else if(alan[i][j]=='0'){			// elan dizisi dolu ise eleman dizisi karakterleri geliyor demektir. rengine g�re yazd�r�lma i�lemi yap�l�r
				switch(renk){
					case 'R': printf(RED 	"%c" RESET,alan[i][j]); break;		// renk k�rm�z� ise
					case 'G': printf(GREEN  "%c" RESET,alan[i][j]); break;		// renk ye�il ise
					case 'Y': printf(YELLOW "%c" RESET,alan[i][j]); break;		// renk sar� ise
					case 'B': printf(BLUE 	"%c" RESET,alan[i][j]); break;		// renk mavi ise
					case 'O': printf(ORANGE "%c" RESET,alan[i][j]); break;		// renk turuncu ise
				}
			}
		}
		printf("|\n");								// s�n�r belirlemek i�in sa� taraf | ile kapat�l�yor
	}
	printf("___________\n");						// alt s�n�r �izgisi
}

// sat�r temizli�i sonras� say�lar�n havadan yere d��mesi i�in gerekli kod		v
void sayidusur(){
	for(i=19;i>=0;i--){									// en a�a��dan ba�lanarak yukar� do�ru gezinmek i�in
		for(j=0;j<9;j++){								// tum sutunlarda gezinmek i�in
			if(sabitalan[i][j]=='0'){					// kontrol edilen eleman 0 de�erine sahip ise
				int k=i;								// while i�in kullan�lacak k de�eri i ye e�itle
				while(k<19 && sabitalan[k+1][j]==' '){	// eleman en altta olmad��� ve alt� bo� oldu�u s�rece �al��maya devam edecek
					sabitalan[k+1][j]='0';				// d��me i�lemi i�in alt de�eri 0 yap
					sabitalan[k][j]=' ';				// d��t��� i�in eski konumunu temizle
					renkler[k+1][j]=renkler[k][j];		// renkler dizisinde �stteki rengi a�a���a ekler
					renkler[k][j]=' ';					// yukar�da kalan renk s�f�rlan�r
					k++;								// sat�r bir a�a�� indi�i i�in k de�erini art�r.
				}
			}
		}
	}
}
	
// tamamlanan sat�rlar�n temizlenme i�lemi										e
void satir_temizle(){
	int sayim=0;;						// t�m s�tunlar�n dolu olup olmad��� teyit etmek i�in
	for(i=0;i<20;i++){					// sabitalan dizisinde gezinmek i�in
		for(j=0;j<9;j++){				// sabitalan dizisinde gezinmek i�in
			if(sabitalan[i][j]=='0'){	// kontrol edilen eleman 0 de�erine sahip ise
				sayim++;				// sayiyi art�r ve s�t�nun dolu oldu�unu kabul et
			}
		}
		if(sayim==9){					// sayi 9 ise t�m sutunlar doludur
			for(j=0;j<9;j++){			// bahsedilen sat�r�n t�m sutunlar� gezilmesi i�in
				sabitalan[i][j]=' ';	// bahsedilen sat�r�n temizlenmesi i�lemi
				renkler[i][j]=' ';		// bahsedilen sat�rda kay�tl� renklerin temizlenmesi i�lemi
			}
			puan+=100;
			sayidusur();				// sat�r temizlendi�i i�in say�lar d���r�lmeli bunun i�in kullan�lan fonksiyon
		}
		sayim=0;						// bahsedilen sat�rla i�lem bitti�i i�in yeni sat�rlarda da kullan�ls�n diye say�m s�f�rlan�r
	}
	
}

// oyunun kaybedilme durumunu kontrol eden kod									n
bool kaybettin(){
	for(i=0;i<9;i++){			// sutunlarda gezinmek i�in
		if(alan[4][i]=='0'){	// 4. sat�rda herhangi bir eleman 0 de�erini alm��sa kaybetmi� demektir.
			return true;		// bu y�zden true d�nderiyoruz.
		}
	}
	return false;				// true ��kt�s� al�nmazsa oyun bitmemi� demektir. bu yuzden false d�ndeririz.
}

// �eklin sa� sol veya a�a�� yondeki sonunu takip eden kod						�
bool yol_bittimi(char yon){
	
	int dtut=0;											// kontrol i�in kullan�lan int de�i�keni
	if(yon=='s'){										// a�a�� tu�una bas�ld� ise
		for(i=0;i<4;i++){								// butun elemanlar kontrol edilmesi i�in 
			int a=eleman[i][0];							// eleman dizisinin i de�eri
			int b=eleman[i][1];							// eleman dizisinin j de�eri
			
			if(a==19){	return true;}					// a= 19 ise zemine ula��ld� demektir
			if(sabitalan[a+1][b]=='0'){					// kontrol edilen eleman�n alt�nda 0 de�eri var m� diye kontrol ediliyor.
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek i�in
					if(eleman[j][0]==eleman[a+1][0]){	// kontrol edilen eleman�n alt�ndaki 0 de�eri dizi i�erisinde var m� diye kontrol ediliyor.
						break;							// kontrol do�ru ise a�a�� inmede bir sorun olmad��� i�in siradaki eleman kontrol edilir.
					}
					else{
						dtut++;							// kontrol sonucunda e�it de�il ise di�er elemanlar e�it olabilir diye say�m yap�l�yor
					}
				}
				if(dtut==4){							// say�m sonucunda kontrol eleman�n�n alt�ndaki 0 di�er hi�bir elemana e�it de�ilse
					return true;						// bu durumda alttaki 0 de�eri sabitalandan geliyor ve yolun sonuna gelindi.
				}
			}
		}
		return false;
	}
	else if(yon=='a'){									// sol hareket tu�una bas�ld� ise
		for(i=0;i<4;i++){								// butun elemanlar kontrol edilmesi i�in 
			int a=eleman[i][0];							// eleman dizisinin i de�eri
			int b=eleman[i][1];							// eleman dizisinin j de�eri
			
			if(b==0){	return true;}					// b= 0 ise en sola ula��ld� demektir
			if(sabitalan[a][b-1]=='0'){					// kontrol edilen eleman�n solunda 0 de�eri var m� diye kontrol ediliyor.
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek i�in
					if(eleman[j][1]==eleman[a][b-1]){	// kontrol edilen eleman�n solundaki 0 de�eri dizi i�erisinde var m� diye kontrol ediliyor.
						break;							// kontrol do�ru ise sola gitmede bir sorun olmad��� i�in siradaki eleman kontrol edilir.
					}
				}
			}
			else if(sabitalan[a+1][b-1]=='0'){			// sol kontrol� oldu�u gibi sol alt kontrol� de yap�larak 0 de�er �ak��mas�o �nleniyor		
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek i�in
					if(eleman[j][1]==eleman[a+1][b-1]){	// kontrol edilen sol alt k�sm�ndaki 0 de�eri dizi i�inde varm� kontrol ediliyor.
						break;							// kontrol do�ru ise harekette bir sorun olmad���ndan bir sonraki elemana ge�iliyor
					}
					else{								// eleman e�it de�ilse say�m yap�l�yor. t�m elemanlar gezildi�i kesinle�tiril�yor.
						dtut++;							
					}
				}
				if(dtut==4){							// t�m elemanlar gezilmi�se ve sol �arpraz da bir 0 de�eri varsa sola harekete izin verilmiyor.
					return true;						
				}
			}
		}
		yol_bittimi('s');
	}
	else if(yon=='d'){									// sa� hareket tu�una bas�ld� ise
		for(i=0;i<4;i++){								// a hareketi i�in anlat�lan olaylar bire bir burada da ger�ekle�tirilir.
			int a=eleman[i][0];
			int b=eleman[i][1];
			
			if(b==8){	return true;}
			if(sabitalan[a][b+1]=='0'){
				for(j=0;j<4;j++){
					if(eleman[j][1]==eleman[a][b+1]){
						break;
					}
				}
			}
			else if(sabitalan[a+1][b+1]=='0'){
				for(j=0;j<4;j++){
					if(eleman[j][1]==eleman[a+1][b+1]){
						break;
					}
					else{
						dtut++;
					}
				}
				if(dtut==4){
					return true;
				}
			}
		}
		yol_bittimi('s');
	}

	return false;										// e�er yukar�daki if bloklar� do�ru de�ilse false de�eri d�nderiyoruz
}

//oyun boyunca kullan�lan alan ile i� bitti�inde sabit alana kopyalan�yor.
void dizikopyala(){
	for(i=0;i<20;i++){										// 20*9 luk matrs�
		for(j=0;j<9;j++){
			if(sabitalan[i][j]==' ' && alan[i][j]=='0'){	// sabit alan bo� ve alan dolu ise kopyalama yap�l�yor.
				sabitalan[i][j]=alan[i][j];					// bu sayede sabit alandaki dolu alanlar bo�alm�yor.
				renkler[i][j]=renk;
			}
		}
	}
}

int main(){
	char tus;										// bas�lan tu�lar�n saklanmas� i�in char t�r�nde de�i�ken	
	Sekil_Sec(true);								// oyunda oynanacak �eklin �e�ilmesi i�in kulan�lan fonksiyon
	memset(sabitalan, ' ', sizeof(sabitalan));		// sabitalan dizisinin i�erisi bo�luk ile dolduruluyor			

	while(true){									// oyun bitene kadar devam etmesi i�in sonsuz d�ng�	
		if(tus!='s' || yol_bittimi('s')==true){		// s tu�una bas�ld�ktan sonra �ekil en a�a��ya inene kadar tus s�f�rlamas� iptal edildi.
			tus=' ';								// bas�lan tu�un kontrolu i�in de�er atamas�
		}
		
		system("cls");								// terminal temizleme komutu
		memset(alan, ' ', sizeof(alan));			// alan dizisinin i�erisi bo�luk ile dolduruluyor 
		
		Sekil_Sec(false);
		alanyaz();									// �ekil atand�ktan sonra g�r�nmesi i�in yazd�rma i�lemi yap�yoruz
		
		if (_kbhit()){								// herhangi bir tu�a bas�l�p bas�lmad��� kontrolu
			 tus = getch();							// bas�lma yap�ld�ysa yu� bilgisi saklan�yor
		}	
	
		if(tus!='s'){								// s tu�una bas�lmas� durumunda direkt olarak asa�� inecek
			sleep(1);								// oyun i�erisinde 1 saniye bekleme yap�l�yor
		}		
								
		if(yol_bittimi('s')==true){ 				// yukr�da belirtildi�i gibi �eklin asa�� veya ilgilie yere gelme kontrolu
			dizikopyala();							// �ekil istenilen yere ula�t���nda dizi kopyalama fonksiyonu
			if(kaybettin()){ return 0;	}			// kaybetme durumunda return 0 ile ��k�� yap�lacak
			Sekil_Sec(true);
			yukseklik =0;							// y�kseklik s�f�rlanarak �eklin yeniden yukar�dan d��mesi i�in ba�lat�l�yor
			donme_sayi=0;							// her yeni �ekil geldi�inde ilk hali ile gelmesi i�in sayi s�f�rlan�yor.
			yon=0;
			satir_temizle();
			
		}
		else{
			if(tus==' ' || tus=='s'){
				yukseklik+=1;							// istenilen yere gelinmemi�se �ekil d��meye devam ediyor.
			}
		}
		if(tus=='q')		{ if(donebilir_mi('q')){	donme_sayi--;	} }		// q tu�una bas�ld���nda �ekli saat yonunun tersine d�nd�rmek i�in	
		else if(tus=='e')	{ if(donebilir_mi('e')){	donme_sayi++;	} }		// e tu�una bas�ld���nda �ekli saat yonune d�nd�rmek i�in	
		else if(tus=='a')	{ if(!yol_bittimi('a')){	yon--; 			} }		// �eklin sola gidebilme olay� 
		else if(tus=='d')	{ if(!yol_bittimi('d')){	yon++; 			} }		// �eklin saga gidebilme olay� 
	}

	return 0;
}
