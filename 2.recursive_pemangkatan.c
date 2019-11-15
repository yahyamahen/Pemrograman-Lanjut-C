#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double pemangkatan(double n, double y){
	if(y == 1){
		return n;
	} else if(y < 1){
		return n;
	} else {
		return n * pemangkatan(n, y-1);
	}
}

int main(){
	
	int pilih;
	do{
		double g,n,y,hasil,hs = 1;
		printf("\nProgram Pemangkatan\n");
		printf("1. Metode Rekursif\n");
		printf("2. Metode Iterasi\n");
		printf("3. Exit\n");
		printf("Pilih Metode : ");
		scanf("%d", &pilih);
		if(pilih == 1){
			printf("\n(Rekursif)\n");
			printf("Masukan Angka       : ");  
			scanf("%lf", &n);
			printf("Masukan Pangkat     : ");   
			scanf("%lf", &y);
			if(y < 0){
				g = y * (-1);
				hs = pemangkatan(n, g);
				hasil = 1/hs;
				printf("Hasil %lf pangkat (%lf) : %lf ",n,y,hasil);
			} else if (y > 0){
				printf("Hasil %lf pangkat (%lf) : %lf", n,y,pemangkatan(n,y));
			} else if(n == 0 && y == 0){
				printf("Hasil %lf pangkat (%lf) : Tak Terhingga", n,y);
			} else if(y == 0){
				printf("Hasil %lf pangkat (%lf) : %lf", n,y,hasil=1);
			}
			printf("\n\nHit >> [Enter]\n");
			getch();
			system("cls");

		} else if(pilih == 2){
			printf("\n(Iterasi)\n");
			printf("Masukan Angka       : ");
			scanf("%lf", &n);
			printf("Masukan Pangkat     : ");
			scanf("%lf", &y);
			if (y > 0){
			    for (int i=1;i<=y;i++){
			    	hs = hs * n;    
			    }
				printf("Hasil %lf pangkat (%lf) = %lf",n,y,hs);
			} else if (n == 0 && y == 0){
				printf("Hasil %lf pangkat (%lf) : Tak Terhingga", n,y);
			} else if (n != 0 && y == 0){
				printf("Hasil %lf pangkat (%lf) : %lf", n,y,hasil=1);
			} else {				
				g = y * (-1);
				for (int i=1;i<=g;i++){
					hs = hs * n;
				}
			    hasil=1/hs;
			    printf("Hasil %lf pangkat (%lf) = %lf",n,y,hasil);
			} 
			printf("\n\nHit >> [Enter]\n");
			getch();
			system("cls");
		} else if(pilih == 3){
			printf("\nTerimakasih dan Sampai Jumpa");
			getch();
			break;
		} else {
			printf("Mohon masukan hanya (1,2,3)!\n");
			printf("\nHit >> [Enter]\n");
			getch();
			system("cls");
		}
	}while(pilih != 1 || pilih != 2 || pilih != 3);

	printf("\n");
	system("pause");
	return 0;
}
