#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Array>

int BinarySearch(int data[], int a, int b, int c){
    int t = (a+b)/2;
    if(a>b){
      return -1;
    } 
    if(data[t] == c){
      return t;
    }
    if(data[t] < c){
      return BinarySearch(data, t+1, b, c);
    } else {
      return BinarySearch(data, a, t-1, c);
    }
}

void view(int i, int data[]){
    for(i=0; i<10; i++){
        printf("%d, ", data[i]);
    }
}

void urutkan(int i, int j, int data[]){
    for (i = 0; i < 10 - 1; i++) {
        for (j = 10 - 1; j > i; j--) {
        if (data[i] > data[j]) {
          int temp = data[j];
          data[j] = data[i];
          data[i] = temp;
        }
      }
    }
}

int main(){
    int bil[10] = {2,4,5,1,3,8,7,10,12,9};
    int i, j, posisi, cari;

    int n = sizeof(bil)/sizeof(bil[0]);
    printf("Jumlah data : %d", n);

    printf("\nData angka sebelum urut\n");
    view(i, bil);

    urutkan(i,j,bil);

    printf("\nData angka setelah urut\n");
    view(i, bil);

    printf("\n\nCari Angka : "); scanf("%d", &cari);
    posisi = BinarySearch(bil, 0, n-1, cari);
    
    if(posisi < 0){
      printf("Elemen %d pada array tidak ditemukan", cari);
    } else {
      printf("Elemen %d ditemukan pada indeks %d setelah diurutkan", cari, posisi+1);
    }
    getch();
    return 0;
}