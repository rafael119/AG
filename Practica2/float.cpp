
void floatf();




void floatf(){
	srand (time(NULL));
	float f[10];

	for (int j = 0; j < 10; j++)
	{
		printf("Individuo No. %d\n",j+1);
		for (int i = 0; i < 10; i++)
		{
			f[i] = (float) (rand() % (90))/((rand() % (10))+1);
		}
		for (int i = 0; i < 10; i++)
		{
			if(i == 0)
				printf("\t[ %.02f | ", f[i]);
			else if(i < 9){
				printf(" %.02f | ", f[i]);
			}
			else
				printf(" %.02f ]\n", f[i]);
		}
	}
	
}
