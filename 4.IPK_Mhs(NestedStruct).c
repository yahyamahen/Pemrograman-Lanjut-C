#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct matakuliah{
	int sks[5] = {4,4,3,3,3};
	char mkmhs[5][100] = {{"Pemrograman Lanjut"},{"Statistik Komputasi"},{"Metode Numerik"},{"Sistem Operasi"},{"Pendidikan Bela Negara"}};
	float nilai[100][100];
	char indeksipk[3];
	float totalipk[5];
}; typedef struct matakuliah matkul;

struct mahasiswa{
	char nama[100];
	char NPM[15];
	struct matakuliah nilaimhs;
}; typedef struct mahasiswa mhs;

mhs data[50];

void viewdatamhs(int i, int n){
	printf("\nNPM Mahasiswa   : %s", data[i].NPM);
	printf("\nNama mahasiswa  : %s", data[i].nama);
}

void viewnilai(int i, int j, float ipk){
	printf("\nNilai matkul %s (sks %d) : %.2f", data[i].nilaimhs.mkmhs[j],data[i].nilaimhs.sks[j], data[i].nilaimhs.nilai[j][j]);
	if(ipk == 4.00){
		strcpy(data[i].nilaimhs.indeksipk,"A");
	} else if(ipk >= 3.70 && ipk < 4.00){
		strcpy(data[i].nilaimhs.indeksipk,"A-");
	} else if(ipk >= 3.30 && ipk < 3.70){
		strcpy(data[i].nilaimhs.indeksipk,"B+");
	} else if(ipk >= 3.00 && ipk < 3.30){
		strcpy(data[i].nilaimhs.indeksipk,"B");
	} else if(ipk >= 2.70 && ipk < 3.00){
		strcpy(data[i].nilaimhs.indeksipk,"B-");
	} else if(ipk >= 2.30 && ipk < 2.70){
		strcpy(data[i].nilaimhs.indeksipk,"C+");
	} else if(ipk >= 2.00 && ipk < 2.30){
		strcpy(data[i].nilaimhs.indeksipk,"C");
	} else if(ipk >= 1.70 && ipk < 2.00){
		strcpy(data[i].nilaimhs.indeksipk,"C-");
	} else if(ipk >= 1.00 && ipk < 1.70){
		strcpy(data[i].nilaimhs.indeksipk,"D");
	} else if(ipk >= 0 && ipk < 1.00){
		strcpy(data[i].nilaimhs.indeksipk,"E");
	} else {
		strcpy(data[i].nilaimhs.indeksipk,"Indeks Invalid");
	}
} 

int main(){	
	int i,j,k,pilih,n = -1, flag;
	int totalsks; 
	float hasil, jumlah, ipk;
	char cariNPM[15];

	do{
		printf("\n ----- Program menghitung IPK Mahasiswa -----\n");
		printf("1. Input Nilai Mahasiswa\n2. Tampilkan Nilai Mahasiswa\n3. Pencarian Mahasiswa\n4. Exit\nPilih Menu : ");
		scanf("%d", &pilih);
		if(pilih == 1){
			n++;
			printf("\n --- Input Nilai Mahasiswa --- ");
			printf("\nMasukan NPM Mahasiswa   : "); fflush(stdin);
			gets(data[n].NPM);
			printf("Masukan nama mahasiswa  : "); fflush(stdin);
			gets(data[n].nama);
			for(i=0; i<5 ; i++){
				printf("Masukan nilai matkul %s : ", data[i].nilaimhs.mkmhs[i]);
				scanf("%f", &data[n].nilaimhs.nilai[i][i]);
			}
			printf("\nPress [ENTER] to back to menu\n");
			getch();
			system("cls");
		} else if(pilih == 2){
			if(n < 0){
				printf("\n --- Data mahasiswa kosong --- \n" );
			} else {
				printf("\n --- Tampilkan Data Mahasiswa --- ");
				for(i=0; i<n+1; i++){
					totalsks = 0;
					jumlah = 0;
					ipk = 0;
					viewdatamhs(i, n);
					for(j=0; j<5; j++){
						jumlah += (data[i].nilaimhs.nilai[j][j]*data[i].nilaimhs.sks[j]);
						totalsks += data[i].nilaimhs.sks[j];
						ipk = jumlah/totalsks;
						data[i].nilaimhs.totalipk[i] = ipk;
						viewnilai(i,j,ipk);
					}
				printf("\nIPK Mahasiswa   : %.2f total sks %d indeks %s \n",data[i].nilaimhs.totalipk[i], totalsks, data[i].nilaimhs.indeksipk);
				}
			}
			printf("\nPress [ENTER] to back to menu\n");
			getch();
			system("cls");
		} else if(pilih == 3){
			if(n < 0){
				printf("\n --- Data mahasiswa kosong --- \n" );
			} else {
				printf("\n ---- Pencarian data mahasiswa ---- \n");
				printf("Masukan NPM yang dicari : ");  fflush(stdin);
				scanf("%s", &cariNPM);
				flag = 0;
				for(i=0; i<n+1; i++){
					if(!strcmp(data[i].NPM,cariNPM)){
							viewdatamhs(i, n);
							for(j=0; j<5; j++){
								viewnilai(i,j,ipk);
							}
						printf("\nIPK Mahasiswa   : %.2f total sks %d indeks %s \n", data[i].nilaimhs.totalipk[i], totalsks, data[i].nilaimhs.indeksipk);
						flag++;
						break;
					}
				}
				if(flag == 0){
					printf("\n --- NPM Mahasiswa tidak ditemukan --- \n");
				}
			}
			printf("\nPress [ENTER] to back to menu\n");
			getch();
			system("cls");
		} else if(pilih == 4){
			break;
		} else {
			printf("\nSystem error, you has been logged out\n");
			getch();
		}
	}while(pilih > 0 && pilih < 5);

	system("\n\n");
	system("pause");
	return 0;	

}