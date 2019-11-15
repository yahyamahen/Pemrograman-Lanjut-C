#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Array>

int main(){

	int bil[] = {2,6,9,1,5,4,3,10,12,11};
	int n = sizeof(bil)/sizeof(bil[0]);
	int i, j, cari, a = 0, b = n-1, t = (a+b)/2;

	printf("\nData angka sebelum urut\n");
	for(i=0; i<n; i++){
        printf("%d, ", bil[i]);
    }

	for (i = 0; i < n - 1; i++) {
    	for (j = n - 1; j > i; j--) {
    		if (bil[i] > bil[j]) {
    			int temp = bil[j];
    			bil[j] = bil[i];
   				bil[i] = temp;
    		}
    	}
    }
    
    printf("\nData angka setelah urut\n");
    for(i=0; i<n; i++){
        printf("%d, ", bil[i]);
    }

	printf("\nCari Angka : "); scanf("%d", &cari);
	while(a<=b){
		if(bil[t] < cari){
			a = t+1;
		} else if(bil[t] == cari){
			printf("Elemen %d ditemukan pada indeks %d setelah diurutkan", cari, t+1);
			break;
		} else {
			b = t-1;
		}
		t = (a+b)/2;
		if(a>b){
			printf("Elemen %d pada array tidak ditemukan", cari);
		}
	}

	getch();
	return 0;
}