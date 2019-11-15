#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct alamat{
	char jalan[256];
	char kota[20];
	char provinsi[20];
}; typedef struct alamat ALMT;

struct ttl{
	int tanggal;
	char bulan[12];
	int tahun;
}; typedef struct ttl TTL;

struct nasabah{
	char bank[100];
	char nama[100];
	char alamat[100];
	ALMT almtnsb;
	int ttl;
	TTL ttlnsb;
	int rekening;
	int saldo;
}; typedef struct nasabah nsb;

nsb a[50];
void view(int i, int n){
	printf("\nNama bank nasabah ke-%d     : %s", i, a[i].bank);
	printf("\nNama nasabah ke-%d          : %s", i, a[i].nama); 
	printf("\nAlamat nasabah ke-%d        : %s", i, a[i].almtnsb.jalan);
	printf("\nKota nasabah ke-%d          : %s", i, a[i].almtnsb.kota);
	printf("\nProvinsi nasabah ke-%d      : %s", i, a[i].almtnsb.provinsi);
	printf("\nTTL nasabah(HH-BB-TT) ke-%d : %d %s %d ", i, a[i].ttlnsb.tanggal,a[i].ttlnsb.bulan,a[i].ttlnsb.tahun);
	printf("\nNo. rekening ke-%d          : %d", i, a[i].rekening); 
	printf("\nJumlah saldo ke-%d          : Rp. %d", i, a[i].saldo);
	printf("\n");
}

void input(int n){
	printf("\n--- Input data nasabah ---\n");
	printf("Masukan nama bank nasabah ke-%d    : ", n); fflush (stdin); gets(a[n].bank);
	printf("Masukan nama nasabah ke-%d         : ", n); fflush (stdin); gets(a[n].nama);
	printf("Masukan alamat nasabah ke-%d       : ", n); fflush (stdin); gets(a[n].almtnsb.jalan);
	printf("Masukan kota nasabah ke-%d         : ", n); fflush (stdin); gets(a[n].almtnsb.kota);
	printf("Masukan provinsi nasabah ke-%d     : ", n); fflush (stdin); gets(a[n].almtnsb.provinsi);
	printf("Masukan TTL nasabah ke-%d(tanggal) : ", n); scanf("%d", &a[n].ttlnsb.tanggal);
	printf("Masukan TTL nasabah ke-%d( bulan ) : ", n); fflush (stdin); gets(a[n].ttlnsb.bulan);
	printf("Masukan TTL nasabah ke-%d( tahun ) : ", n); scanf("%d", &a[n].ttlnsb.tahun);
	printf("Masukan no. rekening ke-%d         : ", n); fflush (stdin); scanf("%d", &a[n].rekening);
	printf("Masukan jumlah saldo ke-%d         : Rp. ", n); fflush (stdin); scanf("%d", &a[n].saldo);
}

int main(){
	
	//nsb a[50];
	//almt b[50];
	int pilih, n = 0, cariNoRek, pilihLokasi, cariUmur, tahun, flag = 0, i;
	char cariLokasi[50];

	do{
		printf(" \n ======= Program Database Rekening ======= ");
		printf("\n1. Input data nasabah\n2. Tampilkan data nasabah\n3. Pencarian Data Nasabah\n4. Akumulasi saldo seluruh nasabah\n5. Tampilkan data nasabah menurut kota/provinsi\n6. Tampilkan data nasabah melalui umur\n7. Tampilkan data nasabah saldo tertinggi dan terendah\n8.Exit\nPilih menu : ");
		scanf("%d", &pilih);
		//system("cls");
		if(pilih == 1){
			n++;
			input(n);
			printf("Press [ENTER] to back to menu\n");
			getch();
			system("cls"); 
		} else if(pilih == 2) {
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Tampilkan seluruh data nasabah ---");
				for(i=1; i<=n; i++){
					view(i,n);
				}
			}
			printf("\nPress [ENTER] to back to menu\n");
			getch();
			system("cls");  
		} else if(pilih == 3) {
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Pencarian Data Nasabah dari (No. Rekening) --- \n");
				printf("Masukan No. Rek yang dicari : ");  scanf("%d", &cariNoRek);
				flag = 0;
				for(i=1; i<=n; i++){
					if(cariNoRek == a[i].rekening){
						view(i,n);
						flag++;
						break;
					}
				}
				if(flag == 0){
					printf("\nNo. Rek Nasabah tidak ditemukan");
				}
			}
			printf("\nPress [ENTER] to back to menu\n");			
			getch();
			system("cls"); 
		} else if(pilih == 4){
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Akumulasi Saldo Nasabah  --- ");
				int akumulasi = 0;
				for(i=1;i<=n;i++){
					printf("\nRekening %d = Rp. %d",a[i].rekening,a[i].saldo);
					akumulasi += a[i].saldo;
				}
				printf("\nAkumulasi Saldo = Rp. %d",akumulasi);
			}
			printf("\nPress [ENTER] to back to menu\n");			
			getch();
			system("cls"); 
		} else if(pilih == 5) {
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Tampilkan data nasabah menurut kota/provinsi  --- ");
				printf("\nPilih menurut (1. Kota/2. Provinsi) : "); scanf("%d", &pilihLokasi);
				if(pilihLokasi == 1){
				 	printf("\nMasukan kota nasabah yang dicari : "); fflush(stdin);
					scanf ("%s", &cariLokasi);
					flag = 0;
					for(i=1; i<=n; i++){
						if(!strcmp(a[i].almtnsb.kota,cariLokasi)){
							view(i,n);
							flag++;
						}
					}
					if(flag == 0){
						printf("Kota nasabah tidak ditemukan\n");
					}
				} else if(pilihLokasi == 2){
					printf("\nMasukan provinsi nasabah yang dicari : "); fflush(stdin);
					scanf ("%[^\n]s", &cariLokasi);
					flag = 0;
					for(i=1; i<=n; i++){
						if(!strcmp(a[i].almtnsb.provinsi,cariLokasi)){
							view(i,n);
							flag++;
						}
					}
					if(flag == 0){
							printf("Provinsi nasabah tidak ditemukan\n");
					}
				} else if(pilihLokasi == 3){
					printf("\nMasukan provinsi nasabah yang dicari : "); fflush(stdin);
					scanf ("%[^\n]s", &cariLokasi);
					flag = 0;
					for(i=1; i<=n; i++){
						if(!strcmp(a[i].almtnsb.provinsi,cariLokasi)){
							view(i,n);
							flag++;
						}
					}
					if(flag == 0){
						printf("Provinsi nasabah tidak ditemukan\n");
					}

				}
			}
			printf("\nPress [ENTER] to back to menu\n");
			getch();
			system("cls");
		} else if(pilih == 6) {
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Tampilkan data nasabah menurut umur --- \n");
				printf("Masukan umur nasabah yang dicari : "); scanf("%d", &cariUmur);
				tahun = 2019 - cariUmur;
				flag = 0;
				for(i=1; i<=n; i++){
					if(a[i].ttlnsb.tahun == tahun){
						view(i,n);
						flag++;
					}
					if(flag == 0){
						printf("Umur nasabah tidak ditemukan\n");
					}
				}
			}
			printf("\nPress [ENTER] to back to menu\n");			
			getch();
			system("cls");
		} else if(pilih == 7) {
			if(n==0){
				printf("\nMasukan Data Nasabah Terlebih Dahulu!");
			} else {
				printf("\n--- Tampilkan data nasabah saldo tertinggi dan terendah --- ");
				int tkc=a[1].saldo;
				int tbs=a[1].saldo;

				for (i = 1; i <= n; i++){
					if (tkc > a[i].saldo){
						tkc = a[i].saldo;
						
					}  else if (tbs <= a[i].saldo){
						tbs = a[i].saldo;
					}
				}

				for(i=1; i<=n; i++){
					if(tkc == a[i].saldo){
						printf("\nSaldo tersedikit adalah : Rp. %d dari Rekening %d", tkc, a[i].rekening);
					}
					if(tbs == a[i].saldo){
						printf("\nSaldo terbanyak adalah  : Rp. %d dari Rekening %d\n", tbs, a[i].rekening);
					}
				}
			}	
			printf("\nPress [ENTER] to back to menu\n");			
			getch();
			system("cls");
		} else if (pilih == 8){
			printf("\nTeriakasih dan Sampai Jumpa");
			getch();
			return 0;
		} else {
			printf("\nSystem error, your account has been logged out");
			getch();
			return 0;
		}
	}while(pilih >= 1 && pilih <= 8);
	system("pause");
	return 0;
}
