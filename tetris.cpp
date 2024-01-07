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

// L þekli ve dömüþ þekilleri içeren kod										b
void Sekil_L(){
	if(donme_sayi>3)		{	donme_sayi=0;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// L þekli saat yönünde çevrilmiþ hali
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][4+yon]='0'; eleman[1][0]=3+yukseklik; eleman[1][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// L þekli 180 derece döndürülmüþ hali
		case 2: alan[2+yukseklik][3+yon]='0'; eleman[0][0]=2+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// L þekli saat yönü tersine çevrilmiþ hali	
		case 3: alan[3+yukseklik][4+yon]='0'; eleman[0][0]=3+yukseklik; eleman[0][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][5+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// L þekli
	}
	
}

// Ters L þekli ve dönüþ þekilleri içeren kod									u
void Sekil_Ters_L(){
	
	if(donme_sayi>3)		{	donme_sayi=0;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][2+yon]='0'; eleman[2][0]=3+yukseklik; eleman[2][1]=2+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// ters L þekli
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// ters L þekli saat yönünde döndürülmüþ hali
		case 2: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// // ters L þekli 180 derece döndürülmüþ hali
		case 3: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][5+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// ters L þekli saat yönünün tersine döndürülmüþ hali
	}
	
}

// wasd þeklinde oluþan þekil vc dönüþlerini içeren kod							r
void Sekil_wasd(){
	if(donme_sayi>3)		{	donme_sayi=0;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	else if(donme_sayi<0)	{	donme_sayi=3;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][2+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=2+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// wasd þeklinde çizilmiþ þekil
		case 1: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][4+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// wasd þeklinin saat yöününde çizilmiþ hali
		case 2: alan[1+yukseklik][2+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=2+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][3+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// wasd þeklinin 180 derece çizilmiþ hali
		case 3: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][2+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=2+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[3][0]=3+yukseklik; eleman[3][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// wasd þeklinin saat yöününün tersine çizilmiþ hali
	}
}

// | þekli ve dönüþ þekillerini içeren kod										a
void Sekil_Cubuk(){
	
	if(donme_sayi>2)		{	donme_sayi=0;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	else if(donme_sayi<0)	{	donme_sayi=1;	}	// döndürme durumunda case sýnýrý aþýlýýrsa sýfýrlama yapmak için
	
	switch(donme_sayi){
		case 0: alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[2+yukseklik][3+yon]='0'; eleman[1][0]=2+yukseklik; eleman[1][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[3+yukseklik][3+yon]='0'; eleman[2][0]=3+yukseklik; eleman[2][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[4+yukseklik][3+yon]='0'; eleman[3][0]=4+yukseklik; eleman[3][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// | þekli
		case 1: alan[1+yukseklik][2+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=2+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][3+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][4+yon]='0'; eleman[2][0]=1+yukseklik; eleman[2][1]=4+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
				alan[1+yukseklik][5+yon]='0'; eleman[3][0]=1+yukseklik; eleman[3][1]=5+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
			break;	// | þeklinin dödürülmüþ hali
	}	
}

// kare þeklini içeren kod														k
void Sekil_kare(){
	alan[1+yukseklik][3+yon]='0'; eleman[0][0]=1+yukseklik; eleman[0][1]=3+yon;		// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
	alan[1+yukseklik][4+yon]='0'; eleman[1][0]=1+yukseklik; eleman[1][1]=4+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
	alan[2+yukseklik][3+yon]='0'; eleman[2][0]=2+yukseklik; eleman[2][1]=3+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
	alan[2+yukseklik][4+yon]='0'; eleman[3][0]=2+yukseklik; eleman[3][1]=4+yon; 	// þeklin koortdinatlarý eleman isimli diziye kaydediliyor
}

// çalýþacak þekli belirleyen kod
void Sekil_Sec(bool nullmu){
	
	if(nullmu){										// tur bittiyse ve yeni þekil atanacaksa giriliyor
		srand(time(NULL));							// her turfarklý bir deðer gelmesi için
		random=rand()%20;							// 20 sayý arasýndan seçim yapýyor
		randomrenk=rand()%20;						// 20 sayý arasýndan seçim yapýyor
		randomrenk%=5;								// renk sayýmýz olan 5 e mod alýp gelen sayý kaydediliyor
		random%=5;									// þekil sayýmýz olan 5 e mod alýp gelen sayý kaydediliyor
		
	}
	switch(random){
		case 0:	Sekil_L(); 		break;				// L þekli seçildi.
		case 1:	Sekil_Ters_L(); break;				// L þekli tersi seçildi.
		case 2:	Sekil_wasd(); 	break;				// wasd þekli seçildi.
		case 3:	Sekil_Cubuk(); 	break;				// cubuk þekli seçildi.
		case 4:	Sekil_kare(); 	break;				// kare þekli seçildi. 
	}
	switch(randomrenk){
		case 0:	renk='R';		break;				// kýrmýzý rengi seçildi.
		case 1:	renk='G';		break;				// yeþil rengi seçildi.
		case 2:	renk='Y';	 	break;				// sarý rengi  seçildi.
		case 3:	renk='B'; 		break;				// mavi rengi seçildi.
		case 4:	renk='O';		break;				// turuncu rengi seçildi. 
	}
}

// þeklin q ve e tuþlarý ile dönüþünü kontrol eder								g
bool donebilir_mi(char yon){
	if(yon=='q')		{ donme_sayi--; }				// döndürülmek istenen yon bilgisi alýnýp kontrol amaçlý döndürülecek
	else if(yon=='e') 	{ donme_sayi++;	}				// döndürülmek istenen yon bilgisi alýnýp kontrol amaçlý döndürülecek
	
	int deger=-1;										// en soldayken sola en saðdayken saga dönüþü ölemek için
	for(i=0;i<4;i++){									// eleman dizisi gezmek için
		if(eleman[i][1]==0)		{ deger=0;	}			// eleman en soldaysa degeri 0 olarak sakla
		else if(eleman[i][1]==8){ deger=8;	}			// eleman en saðga ise deðeri 8 olarak sakla
	}
	Sekil_Sec(false);										// döndürme iþlemi yapýldý
	for(i=0;i<4;i++){									// eleman dizisini gezmek için
		if(deger==0 && eleman[i][1]==-1){ if(yon=='q'){ donme_sayi++; }else if(yon=='e'){ donme_sayi--;	}Sekil_Sec(false);	return false;}
		if(deger==8 && eleman[i][1]== 9){ if(yon=='q'){ donme_sayi++; }else if(yon=='e'){ donme_sayi--;	}Sekil_Sec(false);	return false;}
		// deðer 0 iken yani þekil en soldayken elemanlardan herhangi birini j deðeri -1 olursa dönüþ hatalýdýr
		// deðer 8 iken yani þekil en sagdayken elemanlardan herhangi birini j deðeri 9 olursa dönüþ hatalýdýr
	}
	
	for(i=0;i<4;i++){									// eleman dizisinde gezinmek için
		if(sabitalan[eleman[i][0]][eleman[i][1]]=='0'){	// dönüþ sonrasýndaki karelerde 0 deðeri var mý diye kontrol için sabitalan dizisi kullanýlýyor.
				if(yon=='q')		{ donme_sayi++; }	// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
				else if(yon=='e') 	{ donme_sayi--;	}	// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
				Sekil_Sec(false);							// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
			return false;								// sabitalan içerisinde kontrol edilen noktalarda 0 varsa donme iþlemi yapýlamaz. false
		}
	}
	if(yon=='q')		{ donme_sayi++; }				// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
	else if(yon=='e') 	{ donme_sayi--;	}				// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
	Sekil_Sec(false);										// sistemin çalýþmasý için yapýlan dönüþ geri alýnarak eski haline getiriliyor
	return true;										// sabitalan içerisinde kontrol edilen noktalarda 0 yoksa donme iþlemi yapýlabilir. true
}

// tüm alanýn çizimleri burada yapýlýyor										ü
void alanyaz(){
	printf("PUAN : %d\n",puan);
	printf("___________\n");						// üst sýnýr çizgisi
	for(i=0;i<20;i++){								// 20*9 luk matrýs
		printf("|");								// en sol kýsým | iþareti ile kapatýlarak sýnýr belirleniyor
		for(j=0;j<9;j++){							// matrisin ikinci kýsmý olan 20*9 luk alan	
			if(i==4 && alan[i][j]!='0'){			// þekillerin düþmeden önceki yeri ile düþecekleri oyun sýnýrý arasýný belirliyor
				alan[4][j]='_';						// sýnýr belirginleþtirmek için _ iþareti kullanýyoruz
				printf("%C",alan[i][j]);			// 4. stýrdaki sýnýr çizgisi yazdýrýlmasý için
			}
			if(sabitalan[i][j]=='0'){				// sabit alan 0 ise yani doluysa rengine göre yazdýrýlacak
				if(renkler[i][j]=='R')		{	printf(RED 	  "%c"RESET,sabitalan[i][j] );	}	// renk kýrmýzý ise
				else if(renkler[i][j]=='G')	{	printf(GREEN  "%c"RESET,sabitalan[i][j] );	}	// renk yeþil ise
				else if(renkler[i][j]=='Y')	{	printf(YELLOW "%c"RESET,sabitalan[i][j] );	}	// renk sarý ise
				else if(renkler[i][j]=='B')	{	printf(BLUE   "%c"RESET,sabitalan[i][j] );	}	// renk mavi ise
				else if(renkler[i][j]=='O')	{	printf(ORANGE "%c"RESET,sabitalan[i][j] );	}	// renk turuncu ise
			}
			else if(alan[i][j]==' '){			// alan deðeri boþ ise yaný eleman dizisi dýþýndaki karakterler için boþ yazdýrýlacak
				printf(" ");	
			}
			else if(alan[i][j]=='0'){			// elan dizisi dolu ise eleman dizisi karakterleri geliyor demektir. rengine göre yazdýrýlma iþlemi yapýlýr
				switch(renk){
					case 'R': printf(RED 	"%c" RESET,alan[i][j]); break;		// renk kýrmýzý ise
					case 'G': printf(GREEN  "%c" RESET,alan[i][j]); break;		// renk yeþil ise
					case 'Y': printf(YELLOW "%c" RESET,alan[i][j]); break;		// renk sarý ise
					case 'B': printf(BLUE 	"%c" RESET,alan[i][j]); break;		// renk mavi ise
					case 'O': printf(ORANGE "%c" RESET,alan[i][j]); break;		// renk turuncu ise
				}
			}
		}
		printf("|\n");								// sýnýr belirlemek için sað taraf | ile kapatýlýyor
	}
	printf("___________\n");						// alt sýnýr çizgisi
}

// satýr temizliði sonrasý sayýlarýn havadan yere düþmesi için gerekli kod		v
void sayidusur(){
	for(i=19;i>=0;i--){									// en aþaðýdan baþlanarak yukarý doðru gezinmek için
		for(j=0;j<9;j++){								// tum sutunlarda gezinmek için
			if(sabitalan[i][j]=='0'){					// kontrol edilen eleman 0 deðerine sahip ise
				int k=i;								// while için kullanýlacak k deðeri i ye eþitle
				while(k<19 && sabitalan[k+1][j]==' '){	// eleman en altta olmadýðý ve altý boþ olduðu sürece çalýþmaya devam edecek
					sabitalan[k+1][j]='0';				// düþme iþlemi için alt deðeri 0 yap
					sabitalan[k][j]=' ';				// düþtüðü için eski konumunu temizle
					renkler[k+1][j]=renkler[k][j];		// renkler dizisinde üstteki rengi aþaðýþa ekler
					renkler[k][j]=' ';					// yukarýda kalan renk sýfýrlanýr
					k++;								// satýr bir aþaðý indiði için k deðerini artýr.
				}
			}
		}
	}
}
	
// tamamlanan satýrlarýn temizlenme iþlemi										e
void satir_temizle(){
	int sayim=0;;						// tüm sütunlarýn dolu olup olmadýðý teyit etmek için
	for(i=0;i<20;i++){					// sabitalan dizisinde gezinmek için
		for(j=0;j<9;j++){				// sabitalan dizisinde gezinmek için
			if(sabitalan[i][j]=='0'){	// kontrol edilen eleman 0 deðerine sahip ise
				sayim++;				// sayiyi artýr ve sütünun dolu olduðunu kabul et
			}
		}
		if(sayim==9){					// sayi 9 ise tüm sutunlar doludur
			for(j=0;j<9;j++){			// bahsedilen satýrýn tüm sutunlarý gezilmesi için
				sabitalan[i][j]=' ';	// bahsedilen satýrýn temizlenmesi iþlemi
				renkler[i][j]=' ';		// bahsedilen satýrda kayýtlý renklerin temizlenmesi iþlemi
			}
			puan+=100;
			sayidusur();				// satýr temizlendiði için sayýlar düþürülmeli bunun için kullanýlan fonksiyon
		}
		sayim=0;						// bahsedilen satýrla iþlem bittiði için yeni satýrlarda da kullanýlsýn diye sayým sýfýrlanýr
	}
	
}

// oyunun kaybedilme durumunu kontrol eden kod									n
bool kaybettin(){
	for(i=0;i<9;i++){			// sutunlarda gezinmek için
		if(alan[4][i]=='0'){	// 4. satýrda herhangi bir eleman 0 deðerini almýþsa kaybetmiþ demektir.
			return true;		// bu yüzden true dönderiyoruz.
		}
	}
	return false;				// true çýktýsý alýnmazsa oyun bitmemiþ demektir. bu yuzden false döndeririz.
}

// þeklin sað sol veya aþaðý yondeki sonunu takip eden kod						ç
bool yol_bittimi(char yon){
	
	int dtut=0;											// kontrol için kullanýlan int deðiþkeni
	if(yon=='s'){										// aþaðý tuþuna basýldý ise
		for(i=0;i<4;i++){								// butun elemanlar kontrol edilmesi için 
			int a=eleman[i][0];							// eleman dizisinin i deðeri
			int b=eleman[i][1];							// eleman dizisinin j deðeri
			
			if(a==19){	return true;}					// a= 19 ise zemine ulaþýldý demektir
			if(sabitalan[a+1][b]=='0'){					// kontrol edilen elemanýn altýnda 0 deðeri var mý diye kontrol ediliyor.
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek için
					if(eleman[j][0]==eleman[a+1][0]){	// kontrol edilen elemanýn altýndaki 0 deðeri dizi içerisinde var mý diye kontrol ediliyor.
						break;							// kontrol doðru ise aþaðý inmede bir sorun olmadýðý için siradaki eleman kontrol edilir.
					}
					else{
						dtut++;							// kontrol sonucunda eþit deðil ise diðer elemanlar eþit olabilir diye sayým yapýlýyor
					}
				}
				if(dtut==4){							// sayým sonucunda kontrol elemanýnýn altýndaki 0 diðer hiçbir elemana eþit deðilse
					return true;						// bu durumda alttaki 0 deðeri sabitalandan geliyor ve yolun sonuna gelindi.
				}
			}
		}
		return false;
	}
	else if(yon=='a'){									// sol hareket tuþuna basýldý ise
		for(i=0;i<4;i++){								// butun elemanlar kontrol edilmesi için 
			int a=eleman[i][0];							// eleman dizisinin i deðeri
			int b=eleman[i][1];							// eleman dizisinin j deðeri
			
			if(b==0){	return true;}					// b= 0 ise en sola ulaþýldý demektir
			if(sabitalan[a][b-1]=='0'){					// kontrol edilen elemanýn solunda 0 deðeri var mý diye kontrol ediliyor.
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek için
					if(eleman[j][1]==eleman[a][b-1]){	// kontrol edilen elemanýn solundaki 0 deðeri dizi içerisinde var mý diye kontrol ediliyor.
						break;							// kontrol doðru ise sola gitmede bir sorun olmadýðý için siradaki eleman kontrol edilir.
					}
				}
			}
			else if(sabitalan[a+1][b-1]=='0'){			// sol kontrolü olduðu gibi sol alt kontrolü de yapýlarak 0 deðer çakýþmasýo önleniyor		
				for(j=0;j<4;j++){						// elemanlar dizisinde gezinmek için
					if(eleman[j][1]==eleman[a+1][b-1]){	// kontrol edilen sol alt kýsmýndaki 0 deðeri dizi içinde varmý kontrol ediliyor.
						break;							// kontrol doðru ise harekette bir sorun olmadýðýndan bir sonraki elemana geçiliyor
					}
					else{								// eleman eþit deðilse sayým yapýlýyor. tüm elemanlar gezildiði kesinleþtirilýyor.
						dtut++;							
					}
				}
				if(dtut==4){							// tüm elemanlar gezilmiþse ve sol çarpraz da bir 0 deðeri varsa sola harekete izin verilmiyor.
					return true;						
				}
			}
		}
		yol_bittimi('s');
	}
	else if(yon=='d'){									// sað hareket tuþuna basýldý ise
		for(i=0;i<4;i++){								// a hareketi için anlatýlan olaylar bire bir burada da gerçekleþtirilir.
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

	return false;										// eðer yukarýdaki if bloklarý doðru deðilse false deðeri dönderiyoruz
}

//oyun boyunca kullanýlan alan ile iþ bittiðinde sabit alana kopyalanýyor.
void dizikopyala(){
	for(i=0;i<20;i++){										// 20*9 luk matrsý
		for(j=0;j<9;j++){
			if(sabitalan[i][j]==' ' && alan[i][j]=='0'){	// sabit alan boþ ve alan dolu ise kopyalama yapýlýyor.
				sabitalan[i][j]=alan[i][j];					// bu sayede sabit alandaki dolu alanlar boþalmýyor.
				renkler[i][j]=renk;
			}
		}
	}
}

int main(){
	char tus;										// basýlan tuþlarýn saklanmasý için char türünde deðiþken	
	Sekil_Sec(true);								// oyunda oynanacak þeklin þeçilmesi için kulanýlan fonksiyon
	memset(sabitalan, ' ', sizeof(sabitalan));		// sabitalan dizisinin içerisi boþluk ile dolduruluyor			

	while(true){									// oyun bitene kadar devam etmesi için sonsuz döngü	
		if(tus!='s' || yol_bittimi('s')==true){		// s tuþuna basýldýktan sonra þekil en aþaðýya inene kadar tus sýfýrlamasý iptal edildi.
			tus=' ';								// basýlan tuþun kontrolu için deðer atamasý
		}
		
		system("cls");								// terminal temizleme komutu
		memset(alan, ' ', sizeof(alan));			// alan dizisinin içerisi boþluk ile dolduruluyor 
		
		Sekil_Sec(false);
		alanyaz();									// þekil atandýktan sonra görünmesi için yazdýrma iþlemi yapýyoruz
		
		if (_kbhit()){								// herhangi bir tuþa basýlýp basýlmadýðý kontrolu
			 tus = getch();							// basýlma yapýldýysa yuþ bilgisi saklanýyor
		}	
	
		if(tus!='s'){								// s tuþuna basýlmasý durumunda direkt olarak asaðý inecek
			sleep(1);								// oyun içerisinde 1 saniye bekleme yapýlýyor
		}		
								
		if(yol_bittimi('s')==true){ 				// yukrýda belirtildiði gibi þeklin asaðý veya ilgilie yere gelme kontrolu
			dizikopyala();							// þekil istenilen yere ulaþtýðýnda dizi kopyalama fonksiyonu
			if(kaybettin()){ return 0;	}			// kaybetme durumunda return 0 ile çýkýþ yapýlacak
			Sekil_Sec(true);
			yukseklik =0;							// yükseklik sýfýrlanarak þeklin yeniden yukarýdan düþmesi için baþlatýlýyor
			donme_sayi=0;							// her yeni þekil geldiðinde ilk hali ile gelmesi için sayi sýfýrlanýyor.
			yon=0;
			satir_temizle();
			
		}
		else{
			if(tus==' ' || tus=='s'){
				yukseklik+=1;							// istenilen yere gelinmemiþse þekil düþmeye devam ediyor.
			}
		}
		if(tus=='q')		{ if(donebilir_mi('q')){	donme_sayi--;	} }		// q tuþuna basýldýðýnda þekli saat yonunun tersine döndürmek için	
		else if(tus=='e')	{ if(donebilir_mi('e')){	donme_sayi++;	} }		// e tuþuna basýldýðýnda þekli saat yonune döndürmek için	
		else if(tus=='a')	{ if(!yol_bittimi('a')){	yon--; 			} }		// þeklin sola gidebilme olayý 
		else if(tus=='d')	{ if(!yol_bittimi('d')){	yon++; 			} }		// þeklin saga gidebilme olayý 
	}

	return 0;
}
