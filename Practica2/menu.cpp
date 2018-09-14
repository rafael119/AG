#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "int.cpp"
#include "gray.cpp"
#include "float.cpp"
#include "binario.cpp"


int main()
{
	fflush(stdin);
	int a,b;

	printf("Seleccione una opcion: \n1)Binario \n2)Gray \n3)Real \n4)Entero \n");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			bina();
		break;
			
		case 2:
			grayf();
		break;
			
		case 3:
			floatf();
		break;
		
		case 4:
			aleloint();
		break;
		
		default:
		break;	
	}
	
	printf("Desea volver a calcular algo: 1=Si 2=No \n");
	scanf("%d",&b);
	if(b==1)
	{
		system("cls");
		main();
	}
	
return 0;	
}
