#include <stdio.h>
#include <stdlib.h>
/*
    AD-SOYAD= ÖZGÜR KAN
    NUMARA=15011702
    GRUP 1
*/

void DiziOku(int *,int *,int,char);
void DiziYazdir(int *,int *,int,char);

void KesisimBul(int *,int*,int,int,int *,int *);
void BirlesimBul(int *,int*,int,int,int *,int *,int);


int i,j;//Döngüler için tanýmlandý
int sayi;//Eleman giriþleri için tanýmlandý

int main(){
	int A_elemansayisi;//A dizisi eleman sayýsý
	int B_elemansayisi;//B dizisi eleman sayýsý


            /*A VE B dizisinin eleman sayýlarý alýndý.*/
	printf("A dizisinin eleman sayisini giriniz.");
	scanf("%d",&A_elemansayisi);
	printf("B dizisinin eleman sayisini giriniz.");
	scanf("%d",&B_elemansayisi);

	/*Dizilerin 1. indisten baþlamasý için 1 eleman sayýlarý 1 arttý*/
	A_elemansayisi++;
	B_elemansayisi++;
            /*A ve B dizisi için bellekte yer açýldý.*/
	int *diziA=(int*) malloc(A_elemansayisi*sizeof(int));
    int *diziB=(int*) malloc(B_elemansayisi*sizeof(int));

            /*LÝNKLÝ LÝSTE ÝÇÝN A VE B POÝNTER DÝZÝLERÝ ÝÇÝN YER AÇILDI*/
    int *Pointer_A=(int*) malloc(A_elemansayisi*sizeof(int));
    int *Pointer_B=(int*) malloc(B_elemansayisi*sizeof(int));


    /*Dizi oku fonksiyonu çaðýrýldý*/
    DiziOku(diziA,Pointer_A,A_elemansayisi,'A');
    DiziOku(diziB,Pointer_B,B_elemansayisi,'B');


    /*Dizi yazdýr fonksiyonu çaðýrýldý*/
    DiziYazdir(diziA,Pointer_A,A_elemansayisi,'A');
    printf("\n");
    DiziYazdir(diziB,Pointer_B,B_elemansayisi,'B');


/*Kesimi bulma fonksiyonu çaðýrýldý*/
    KesisimBul(diziA,diziB,A_elemansayisi,B_elemansayisi,Pointer_A,Pointer_B);


return 0;
}


void DiziOku(int *dizi,int *Pointer,int Boyut,char DiziAdi){
    //DIZI OKUMA ELEMANLAR OKUNUP DÝZÝYE ATILDI DÖNÜÞ DEÐERÝ YOKTUR.
    printf("\n");
    dizi[0]=0;
    Pointer[0]=1;
    for(i=1;i<Boyut;i++){
        printf("%c dizisinin %d elemanini giriniz:",DiziAdi,i);
        scanf("%d",&sayi);
            while(i>0 && dizi[i-1]>=sayi ){
        		 printf("Diziyi sirali giriniz %c dizisinin %d elemani yeniden giriniz:",DiziAdi,i);
        		 scanf("%d",&sayi);
        	}
            dizi[i]=sayi;
            Pointer[i]=i+1;
    }
    Pointer[i-1]=-1;
}

void DiziYazdir(int *dizi,int *Pointer,int Boyut,char DiziAdi){
    //DÝZÝ YAZDIRMA ÝÞLEMÝ YAPILDI DÜNÜÞ DEÐERÝ YOKTUR.
    printf("\n %c DIZISI: |--",DiziAdi);

            j=*Pointer;
            while(j>0){
                printf("|%d ",dizi[j]);
                j=Pointer[j];
            }

        /*POÝNTER YAZDIRMA*/
    printf("\n %c POINTER: ",DiziAdi);
        for(i=0;i<Boyut;i++)
        {
            printf("|%d ",Pointer[i]);
        }
}

void KesisimBul(int *dizi1,int *dizi2,int Boyut1,int Boyut2,int *Pointer_A,int *Pointer_B){
    int *Kesisim_C=(int*) malloc(0*sizeof(int));
    int *Kesisim_C_Pointer=(int*) malloc(0*sizeof(int));
    Kesisim_C[0]=0;
    Kesisim_C_Pointer[0]=1;

    int *dizi11,*dizi22;
    int *Pointer1,*Pointer2;
    int kontrol=0;
    int KesisimAdeti=0;

    if(Boyut1>=Boyut2){
        dizi11=dizi1;
        dizi22=dizi2;
        Pointer1=Pointer_A;
        Pointer2=Pointer_B;
    }else{
        dizi11=dizi2;
        dizi22=dizi1;
        Pointer1=Pointer_B;
        Pointer2=Pointer_A;
    }

        i=*Pointer2;
                while(i>0){
                        j=*Pointer1;
                        kontrol=0;
                        while(j>0 && kontrol==0){
                                if(dizi22[i]==dizi11[j]){
                                    kontrol=1;
                                    KesisimAdeti++;
                                    Kesisim_C=realloc(Kesisim_C,sizeof(int)*(KesisimAdeti+1));
                                    Kesisim_C_Pointer=realloc(Kesisim_C_Pointer,sizeof(int)*(KesisimAdeti+1));

                                    Kesisim_C[KesisimAdeti]=dizi22[i];
                                    if(KesisimAdeti>1){
                                        Kesisim_C_Pointer[KesisimAdeti]=-1;
                                        Kesisim_C_Pointer[KesisimAdeti-1]=KesisimAdeti;
                                    }else{
                                        Kesisim_C_Pointer[KesisimAdeti]=-1;
                                    }

                                }
                            j=Pointer1[j];
                        }
                        i=Pointer2[i];
                }

                printf("\n");
                if(KesisimAdeti==0){
                    printf("C kesisim dizisi yoktur...\n");
                }else{
                DiziYazdir(Kesisim_C,Kesisim_C_Pointer,KesisimAdeti+1,'C');
                printf("\n");
                }

                BirlesimBul(dizi1,dizi2,Boyut1,Boyut2,Pointer_A,Pointer_B,KesisimAdeti);


}


void BirlesimBul(int *dizi1,int *dizi2,int Boyut1,int Boyut2,int *Pointer_A,int *Pointer_B,int KesisimAdeti){

   i = 0, j = 0;
   int a=0;
   int Birlesim_D[Boyut1+Boyut2-KesisimAdeti];
   int Birlesim_D_Pointer[Boyut1+Boyut2-KesisimAdeti+1];
   Birlesim_D_Pointer[0]=1;
        while (i < Boyut1 && j < Boyut2)
        {
            if (dizi1[i] < dizi2[j]){
                Birlesim_D[a]=dizi1[i++];
            }
            else if (dizi2[j] < dizi1[i]){
                Birlesim_D[a]=dizi2[j++];
            }
            else{
                Birlesim_D[a]=dizi2[j++];
                i++;
            }
        a++;
        }


        while(i < Boyut1){
            Birlesim_D[a]=dizi1[i++];
            a++;
        }
        while(j < Boyut2){
            Birlesim_D[a]=dizi2[j++];
            a++;
        }

        for(i=1;i<(Boyut1+Boyut2-KesisimAdeti+1);i++){
            Birlesim_D_Pointer[i]=i+1;
        }
        Birlesim_D_Pointer[i-3]=-1;
        DiziYazdir(Birlesim_D,Birlesim_D_Pointer,Boyut1+Boyut2-KesisimAdeti-1,'D');

}



