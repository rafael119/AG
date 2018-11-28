#include "torneo.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

void IniciarInd(bitset<BIT_IND> array[]){
	srand (time(NULL));
	for (int i = 0; i < NUM_IND; i++)
			array[i] = 1+rand()%(101-1);
}
void printIndividuals(bitset<BIT_IND> array[]){
	for (int i = 0; i < NUM_IND; i++)
		cout << array[i].to_ulong() << endl;
}

int getIndividualValue(bitset<BIT_IND> individual){
	return individual.to_ulong();
}

float getIndividualAptitude(bitset<BIT_IND> individual){
	float result;
	float numerador;
	float denominador;
	float x = individual.to_ulong();
	float senX = sin(x);
	numerador = x - 5;
	denominador = 2 + senX;
	result = abs(numerador/denominador);
    return result;
}

void ranking(bitset<BIT_IND> individuo[],float res[]){
    float aux[NUM_IND];
    int n= sizeof(aux)/sizeof(float);
    for( int i =0; i<NUM_IND;i++){
        aux[i]= getIndividualAptitude(individuo[i]);
    }
    sort(aux,aux+n);
    float div,uno,dos,resta,multi;
    for( int i =0; i<NUM_IND;i++){
        uno=(i-1);
        dos=(NUM_IND-1);
        div = (uno/dos);
        resta= MAXIMO -(MINIM);
        multi= resta*div;
        res[i]=(float) MINIM + multi;
    }
    for( int i =0; i<NUM_IND;i++){
        printf("%f\n",res[i]);
        individuo[i]=aux[i];
       }
}


float getTotalAptitude(bitset<BIT_IND> array[]){
	float total = 0;
	for (int i = 0; i < NUM_IND; i++)
	{
		total += getIndividualAptitude(array[i]);
	}
	return total;
}
float getProbability(bitset<BIT_IND> individual,int totalAptitude){
    float aux;
    aux=(float)(getIndividualAptitude(individual)/(float)totalAptitude);

     return aux;
}


bitset<BIT_IND> rouletteSelection(bitset<BIT_IND> array[], int totalAptitude) {

    int r = rand() % (totalAptitude + 1);
    int add = 0;
    int i;
    for(i = 0; i < NUM_IND && add < r; i++) {
        add += getIndividualAptitude(array[i]);
    }
    return array[i];
}
void swapInd(bitset<BIT_IND> set[]){
	array<int, NUM_IND> arr;
	bitset<BIT_IND> aux[NUM_IND];
	for (int i = 0; i < NUM_IND; i++){
		arr[i] = set[i].to_ulong();
	}
	random_shuffle(arr.begin(), arr.end());

	for (int i = 0; i < NUM_IND; i++){
		set[i] = arr[i];
    }
}
bitset<BIT_IND> tournamentSelection(bitset<BIT_IND> &p1, bitset<BIT_IND> &p2) {

float p = (float)(rand()%NUM_RAND) /(float)NUM_RAND ;
   // printf("%.2f\n",p);
    if((getIndividualAptitude(p1) < getIndividualAptitude(p2)) && p >= 0.70){
		return p2;
	}
	else if ((getIndividualAptitude(p1) < getIndividualAptitude(p2)) && p < 0.70){
		return p1;
	}
	else if ((getIndividualAptitude(p1) > getIndividualAptitude(p2)) && p >= 0.70){
		return p1;
	}
	else{
		return p2;
    }
}


bitset<BIT_IND> crossAlgorithm(bitset<BIT_IND> &p1, bitset<BIT_IND> &p2) {

    bitset<BIT_IND> aux = p1;

    for (int i = 0; i <= PUNTO_CRUZA; i++)
    {
    	aux.set(PUNTO_CRUZA - i, p2[PUNTO_CRUZA - i]);
    }

    return aux;
}

bitset<BIT_IND> mutationAlgorithm(bitset<BIT_IND> individual){
	bitset<BIT_IND> result = individual;

	int cont = 0;

	while(cont <= MAX_SEARCH_VALUE)
	{

		int mutation_point = rand() % BIT_IND;
		if(result[mutation_point] == 0){
			result.set(mutation_point, 1);
			break;
		}
		cont++;
	}

	return result;
}

int getMinGenerationValue(bitset<BIT_IND> array[]){
	int min = 1000000, aux = 0;

	for (int i = 0; i < NUM_IND; i++)
	{
		aux = getIndividualAptitude(array[i]);

		if(aux < min){
			min = aux;
		}

	}
	return min;
}

int getMaxGenerationValue(bitset<BIT_IND> array[]){
	int max = 0, aux = 0;

	for (int i = 0; i < NUM_IND; i++)
	{
		aux = getIndividualAptitude(array[i]);

		if(aux > max){
			max = aux;
		}

	}
	return max;
}

int getGenerationAverage(bitset<BIT_IND> array[]){
	return (getTotalAptitude(array)/NUM_IND);
}
