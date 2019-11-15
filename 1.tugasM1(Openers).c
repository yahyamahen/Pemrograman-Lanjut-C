#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void display(char NPM[], char NamaLengkap[], char alamat[], char NoTelp[], char TTL[], char Jurusan[], char Fakultas[]){
	printf("\n===== Data Diri Mahasiswa =====\n");
	printf("NPM Mahasiswa      : %s", NPM);
	printf("\nNama Mahasiswa     : %s", NamaLengkap);
	printf("\nAlamat Mahasiswa   : %s", alamat);
	printf("\nNo. Telp Mahasiswa : %s", NoTelp);
	printf("\nTTL Mahasiswa      : %s", TTL);
	printf("\nJurusan Mahasiswa  : %s", Jurusan);
	printf("\nFakultas Mahasiswa : %s", Fakultas);
}

int main(){
	char NPM [100], NamaLengkap[100], alamat[100], NoTelp[100], TTL[100], Jurusan[100], Fakultas[100];
	//char NPM, NamaLengkap, alamat, NoTelp, TTL, Jurusan, Fakultas;
	
	char ulang[1];
	ulang[0] = 'y';

	while(ulang[0] == 'y' || ulang[0] == 'Y'){
		printf("\n\n====== Program Biodata Mahasiswa UPN Veteran Jawa Timur ======\n");
		printf("\nMasukan NPM            : ");
		gets(NPM);
		//scanf("%s", &NPM);
		printf("Masukan Nama Lengkap   : ");
		gets(NamaLengkap);
		//scanf("%s", &NamaLengkap);
		printf("Alamat                 : ");
		gets(alamat);
		//scanf("%s", &alamat);
		printf("Masukan TTL (dd/mm/yy) : ");
		gets(TTL);
		//scanf("%s", &TTL);
		printf("Masukan No. Telp       : ");
		gets(NoTelp);
		//scanf("%s", &NoTelp);
		printf("Masukan Jurusan        : ");
		gets(Jurusan);
		//scanf("%s", &Jurusan);
		printf("Masukan Fakultas       : ");
		gets(Fakultas);
		// scanf("%s", &Fakultas);
		display(NPM, NamaLengkap, alamat, NoTelp, TTL, Jurusan, Fakultas);

		ulang:
		printf("\nUlangi Masukan Data Mahasiswa? (y / n) : ");
		gets(ulang);

		if(ulang[0] == 'y' || ulang[0] == 'Y'){	
			system("cls");
		} else if(ulang[0] == 'n' || ulang[0] == 'N') {
			printf("\n ==== Terimakasih Telah Mencoba ==== \n");
		} else {
			printf("Masukan Hanya (y/n)! ");
			goto ulang;
		}
	}
	system("pause");
	return 0;	
}