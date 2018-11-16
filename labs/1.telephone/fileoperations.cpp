#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "header/fileoperations.h"

using namespace std;

void Dosya::ekle(Tel_Kayit *ykptr)
{
	//sondan başmak için
	fseek(teldefteri,0,SEEK_END);
	fwrite(ykptr,sizeof(Tel_Kayit),1,teldefteri);
}

void Dosya::olustur()
{
	teldefteri = fopen("teldefteri.txt","r+");
	if(!teldefteri)
	{
		if(!(teldefteri = fopen(dosyaadi, "w+")))
		{
			cerr << "File can not opened." << endl;
			exit(1);
		}
	}
}

void Dosya::kapat()
{
	fclose(teldefteri);
}


int Dosya::ara(char aranacak[])
{
	Tel_Kayit k;
	int sayac = 0;
	bool tumu = false;
	int bulunan = 0;
	//aranacak kelimesinin boş olup olmadığının kontrolünü yap.
	if(strcmp(aranacak, "*") == 0)
		tumu = true;
	//Fıle operation için pointerı dosyanın başına alıyorum
	fseek(teldefteri,0,SEEK_SET);
	while(!feof(teldefteri))
	{
			sayac++;
			//teldefteri dosyası içerisinden kişilerden birinin alınıp atanması işlemi
			fread(&k,sizeof(Tel_Kayit),1,teldefteri);
			if(feof(teldefteri))
				break;
			
			//TODO bu kısımda bi mallık var	
			if(!tumu && strncmp(k.ad,aranacak,strlen(aranacak))!=0)
				continue;
			cout << sayac << "." << k.ad << " " << k.telno << endl;	
			bulunan++;
	}
	return bulunan;
}

void Dosya::guncelle(int kayitno, Tel_Kayit *ykptr)
{
	if(fseek(teldefteri, sizeof(Tel_Kayit)*(kayitno-1), SEEK_SET)==0)
	fwrite(ykptr, sizeof(Tel_Kayit), 1, teldefteri);
}
void Dosya::sil(int kayitno)
{
	Tel_Kayit boskayit={"",""};
	if(fseek(teldefteri, sizeof(Tel_Kayit)*(kayitno-1), SEEK_SET)==0)
	fwrite(&boskayit, sizeof(Tel_Kayit), 1, teldefteri);
}









