#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
void grayf();
int xorOp(int a, int b);



int xorOp(int a, int b){
		return(a==b)?0:1;
}


void grayf(){
	srand (time(NULL));
	int original[10];
	int gray[10];
	

	for (int j = 0; j < 10; j++)
	{
		printf("Individuo No. %d\n",j+1);
		
		for (int i = 0; i < 10; i++)
		{
			original[i] = rand() % 2;
		}

		gray [0] = original[0];

		for (int i = 1; i < 10; i++)
		{
			gray[i] = xorOp(original[i-1], original[i]);
		}
		for (int i = 0; i < 10; i++)
		{
			if(i == 0)
				printf("\t| %d | ", original[i]);
			else if(i < 9){
				printf(" %d | ", original[i]);
			}
			else
				printf(" %d | \n", original[i]);
		}
		printf("gray");
		for (int i = 0; i < 10; i++)
		{
			if(i == 0)
				printf("\t[ %d | ", gray[i]);
			else if(i < 9){
				printf(" %d | ", gray[i]);
			}
			else
				printf(" %d ] \n", gray[i]);
		}
	}	


	
}







