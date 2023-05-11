#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Binary search fonksiyonu
int BinarySearch(int arr[],int size,int ArananSayi,int ilk,int son){
	
	int orta=(ilk+son)/2;
	
	if(ArananSayi==arr[orta])
		return 1;
			
	if(ilk >= son)
        return 0;
	
	if(ArananSayi>arr[orta]){
		return BinarySearch(arr,size,ArananSayi,orta+1,son);
	}
	
	else
		return BinarySearch(arr,size,ArananSayi,ilk,orta-1);
	
	return 0;
}

// Dizi bubble sort kullanilarak siralanir.
void bubblesort(int arr[],int size){
	
	int i,j;
	int degistir;
	
	for(i=0;i<size;i++){
		for(j=0;j<size-(i+1);j++){
			
			if(arr[j]>arr[j+1]){
				degistir=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=degistir;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	
	// Tanimlar yapilir
	int dizi[]={4,8,3,84,47,76,9,24,68};
	int sonuc,boyut,ArananEleman;
	int i;
		
	// Dizinin boyutu bulunur, ekrana yazilir ve dizi siralanir
	
	boyut=sizeof(dizi)/sizeof(dizi[0]);
	printf("Dizi: \n");
	for(i=0;i<boyut;i++)
		printf("%d ",dizi[i]);
	
	bubblesort(dizi,boyut);
	
	printf("\n\nAranacak elemani giriniz: ");
	scanf("%d",&ArananEleman);
	
	// Arama islemi yapilir
	sonuc= BinarySearch(dizi,boyut,ArananEleman,0,boyut-1);
	
	if(sonuc==1)
		printf("\nAradiginiz eleman dizide var.");
		
	else
		printf("\nAradiginiz eleman dizide yok.");
	
	return 0;
}
