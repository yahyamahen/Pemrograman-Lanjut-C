#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){

	printf("Program Pemangkatan (Iterasi)\n");
	long int n, y, hasil;

	printf("Masukan Angka   : ");
	scanf("%ld", &n);
	printf("Masukan Pangkat : ");
	scanf("%ld", &y);
	hasil = n;

	for(int i=1; i<y; i++){
		hasil = hasil * n;
	}

	printf("\nHasil %ld pangkat (%ld) : %ld", n, y, hasil);
	printf("\n\n");
	system("pause");
	return 0;
}