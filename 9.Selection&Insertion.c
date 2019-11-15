#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void selectionSort(int data[], int n){
	int i, j;
	for(i=0; i < n-1; i++){
		int l = i;
		for(j=i+1; j < n; j++){
			if(data[j] < data[l])
				l = j;
		} // searchingnya 
		int temp = data[l]; 
    	data[l] = data[i]; 
    	data[i] = temp; 
	} // pengurutannya
}

void insertionSort(int arr[], int n){
	int i,j;
	for(i=1; i<n; i++){
		int temp=arr[i];
		j=i-1;
		while(arr[j] > temp && j >= 0){
			arr[j+1]=arr[j];
			j=j-1;
		}	
		arr[j+1]=temp;
	}
}

void printArray(int arr[], int n){
	int i;
	for(i=0; i < n; i++){
		printf("%d ,", arr[i]);
	}
}

int main(){
	
	int data[] = {3,5,-1,2,9,7,10,6,4,-2};
	int n = sizeof(data)/sizeof(int);
	int i, j;

	//selectionSort(data,n);
	insertionSort(data,n);
	printArray(data,n);

	getch();
	return 0;
}