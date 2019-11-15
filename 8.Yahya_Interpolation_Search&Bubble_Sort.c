#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int InterpolationSearch(int data[], int b, int f){
    int a = 0;
    int t;

    while ((f >= data[a]) && (f <= data[b])) {
        t = a + (b - a) * ((f - data[a])  / (data[b] - data[a]));
        if (data[t] < f)
            a = t + 1;
        else if (f < data[t])
            b = t - 1;
        else
            return t;
    }
    return -1;
}

void BubbleSortASC(int data[], int n){
	int i, j, simpan;
    for (i = 0; i < n; i++) {
    	for (j = 0; j < n-i-1 ; j++) {
    		if (data[j] > data[j+1]) {
    			simpan = data[j];
    			data[j] = data[j+1];
    			data[j+1] = simpan;
    		}
    	}
    }
}

void BubbleSortDSC(int data[], int n){
	int i, j, simpan;
    for (i = 0; i < n; i++) {
    	for (j = 0; j < n-i-1 ; j++) {
    		if (data[j] < data[j+1]) {
    			simpan = data[j];
    			data[j] = data[j+1];
    			data[j+1] = simpan;
    		}
    	}
    }
}

void view(int data[], int n){
	for(int i=0; i<n;i++){
		printf("%d ,", data[i]);
	}
}

int main(){

	int arr[10] = {-4,1,-1,5,6,3,2,10,8,9};
	int pos, f;
	int a = 0;
	int n = sizeof(arr)/sizeof(int);
	
	printf("Data bilangan sebelum urut: \n");
	view(arr, n);

	BubbleSortDSC(arr,n);
	printf("\nData bilangan setelah urut [DSC] : \n");
	view(arr, n);

	BubbleSortASC(arr,n);
	printf("\nData bilangan setelah urut [ASC] : \n");
	view(arr, n);

    printf("\nCari Angka : "); scanf("%d", &f);
    int posisi = InterpolationSearch(arr, n, f);
  
    if(posisi < 0){
    	printf("Elemen %d pada array tidak ditemukan", f);
    } else {
    	printf("Elemen %d ditemukan pada indeks %d setelah diurutkan ASC", f, posisi);
    }

	getch();
	return 0;
}