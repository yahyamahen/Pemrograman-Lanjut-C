#include <conio.h>
#include <stdio.h>
#include <string.h>

int main(){

	long npm[50]={101,102,103,104,105};
	float ipk[50]={3.56,3.65,2.56,3.33,2.57}; 
	int pilih = 0;
	while(pilih != 1 || pilih != 2 || pilih != 3){
		printf("\nProgram Mahasiswa\n");	
		printf("1. Tampilkan Data\n2. Tampilkan Data Akhir \n3. Pencarian Mahasiswa\nPilih menu : ");
		scanf("%d", &pilih);
		if(pilih == 1){
			for(int i = 0; i < 5; i++){
				printf("\nNPM Mahasiswa : %ld", npm[i]);			
				printf("\nIPK Mahasiswa : %f", ipk[i]);
			}
		} else if(pilih == 2){
			for(int i = 4; i >= 0; i--){
				printf("\nNPM Mahasiswa : %ld", npm[i]);			
				printf("\nIPK Mahasiswa : %f", ipk[i]);
			}	
		} 
		else if(pilih == 3){
			int pencarian;
			printf("Cari NPM : "); scanf("%d", &pencarian);
			bool flag = false;
			for(int i = 0; i < 5; i++){	
				if(npm[i] == pencarian){
					flag = true;
					printf("\nNPM Mahasiswa : %ld", npm[i]);			
					printf("\nIPK Mahasiswa : %f", ipk[i]); 
					break;				
				} 
				if(flag = false){
					printf("Data Tidak Ditemukan");
					break;
				}
			}
		}
		printf("\n");  
	}
	return 0;
}