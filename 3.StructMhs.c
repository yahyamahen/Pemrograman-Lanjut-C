#include <stdio.h>
#include <conio.h>

	struct mahasiswa{
		long npm;
		float ipk;
	};
	typedef struct mahasiswa mhs;

int main(){

	

	mhs data[3];
	data[0].npm = 101;
	data[0].ipk = 3.56; 	

	data[1].npm = 102;
	data[1].ipk = 3.78; 	

	data[2].npm = 103;
	data[2].ipk = 3.99; 

	int pilih = 0;
	while(pilih != 1 || pilih != 2 || pilih != 3){
		printf("\nProgram Mahasiswa\n");	
		printf("1. Tampilkan Data\n2. Tampilkan Data Akhir \n3. Pencarian Mahasiswa\nPilih menu : ");
		scanf("%d", &pilih);
	 	if(pilih == 1){
			for(int i = 0; i < 3; i++){
				printf("NPM %ld = IPK %f\n", data[i].npm, data[i].ipk);
			}
		} else if(pilih == 2){
			for(int i = 2; i >= 0; i--){
				printf("NPM %ld = IPK %f\n", data[i].npm, data[i].ipk);
			}	
		} else if(pilih == 3){
			int cariNpm;
			bool flag = false;
			printf("Cari NPM : ");	scanf("%d", &cariNpm);
			for(int i = 0; i < 3; i++){
				if(data[i].npm == cariNpm){
					printf("NPM %ld = IPK %f\n", data[i].npm, data[i].ipk);
					flag = true;
					break;
				}
				if(flag = false){
					printf("NPM Mahasiswa tidak ditemukan\n");
				}
			}
		}
	}
	return 0;
}