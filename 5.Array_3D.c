#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int main(){
	int data [3][3][3] = 
	{
		{
			{5,1,5},{6,2,8},{1,2,1}
		},
		{
			{-3,2,5},{-4,3,4},{-5,7,8}
		},
		{
			{3,1,2},{-5,2,1},{-2,5,1}
		},
	};	

	int i,j,k;
	float Fab[2], Fbc[2];
	float Dab, Dbc, Dab1, Dbc1, Dab2, Dbc2;
	for(i=0; i<3; i++){
		printf("Array 2D %d \n", i+1);
		printf("  x    y    z \n");		
		for(j=0; j<3; j++){
			for(k=0; k<3; k++){
				printf("  %d  ", data[i][j][k]);
			}
		printf("\n");
		}
	printf("\n");
	Fab[i] = sqrt((pow(data[i][0][0] - data[i][1][0],2))+(pow(data[i][0][1] - data[i][1][1],2))+(pow(data[i][0][2] - data[i][1][2],2)));
	Fbc[i] = sqrt((pow(data[i][1][0] - data[i][2][0],2))+(pow(data[i][1][1] - data[i][2][1],2))+(pow(data[i][1][2] - data[i][2][2],2)));			
	printf("Lintasan AB %d = %f \nLintasan BC %d = %f \nHasil = %f\n\n",i+1,Fab[i],i+1,Fbc[i],Fab[i]+Fbc[i]);
	}

	system("pause");
	return 0;
	
}