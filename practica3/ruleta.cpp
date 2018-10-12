#include "ruleta.h"
#include <iostream>
#include <time.h>
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

int getIndividualAptitude(bitset<BIT_IND> individual){
	return (individual.to_ulong()*individual.to_ulong());
}

int getTotalAptitude(bitset<BIT_IND> array[]){
	int total = 0;
	for (int i = 0; i < NUM_IND; i++)
	{
		total += getIndividualAptitude(array[i]);
	}
	return total;
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
