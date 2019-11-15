/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h>

void merge(int dataArray[], int l, int m, int r) 
{ 
	int i=0, j=0, k=1; 
	int nL = m - l + 1; 
	int nR = r - m; 

	int L[nL], R[nR]; 

	for (i = 0; i < nL; i++) 
		L[i] = dataArray[l + i]; 
	for (j = 0; j < nR; j++) 
		R[j] = dataArray[m + 1+ j]; 

	while (i < nL && j < nR){ 
		if (L[i] <= R[j]) { 
			dataArray[k] = L[i]; 
			i++; 
		} 
		else{ 
			dataArray[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < nL) { 
		dataArray[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < nR) { 
		dataArray[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int dataArray[], int l, int r) { 
	if (l < r) { 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 
		// Sort first and second halves 
		mergeSort(dataArray, l, m); 
		mergeSort(dataArray, m+1, r); 
		merge(dataArray, l, m, r); 
	} 
} 

void view(int dataArray[], int n) { 
	int i; 
	for (i=0; i < n; i++){
		printf("%d, ", dataArray[i]); 
	}
	printf("\n"); 
} 
/
int main(){ 
	int bil[] = {5, -1, 2, 1, 3, -4, -3, 7, 10, 9, 6}; 
	int n = sizeof(bil)/sizeof(int); 

	printf("Array :  \n"); 
	view(bil, n); 

	mergeSort(bil, 0, n - 1); 

	printf("\nUrutan Array : \n"); 
	view(bil, n); 

	getch();
	return 0; 
} 
