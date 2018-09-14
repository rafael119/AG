#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

void bina();

void bina(){
	int alelobin[10];

	srand (time(NULL));

	for (int j = 0; j < 10; j++)
	{
		printf("Individuo No. %d\n",j+1);
		for (int i = 0; i < 10; i++)
		{
		alelobin[i] = rand() % 2;
		}
		for (int i = 0; i < 10; i++)
		{
			if(i == 0)
				printf("\t[ %d | ", alelobin[i]);
			else if(i < 9){
				printf(" %d | ", alelobin[i]);
			}
			else
				printf(" %d ]\n", alelobin[i]);
		}
		printf("\n");
	}
	
}
