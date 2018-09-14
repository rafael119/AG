#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

void aleloint(){
	int aleloint[10];
	srand (time(NULL));
	

	for (int j = 0; j < 10; j++)
	{
		printf("Individuo No. %d\n",j+1);
		for (int i = 0; i < 10; i++)
		{
		aleloint[i] = rand() % (100)+1;
		}
		
		for (int i = 0; i < 10; i++)
		{
			if(i == 0)
				printf("\t[ %d | ", aleloint[i]);
			else if(i < 9){
				printf(" %d | ", aleloint[i]);
			}
			else
				printf(" %d ] \n", aleloint[i]);
		}
	}
	
	
}
