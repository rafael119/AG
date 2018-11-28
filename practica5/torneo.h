#include <bitset>
#include <random>


#define BIT_IND 5
#define NUM_IND 32
#define MAX_VAL 31
#define PUNTO_CRUZA 2
#define PROBABILITY 10
#define MAX_SEARCH_VALUE 100
#define NUM_RAND 10
#define NUM_BARA 2
#define MAXIMO 1.1
#define MINIM 2 - MAXIMO

using namespace std;

void IniciarInd(bitset<BIT_IND> array[]);

void fillIndividuals(bitset<BIT_IND> array[]);

void printIndividuals(bitset<BIT_IND> array[]);

int getIndividualValue(bitset<BIT_IND> individual);

float getIndividualAptitude(bitset<BIT_IND> individual);

void ranking(bitset<BIT_IND> individuo[],float res[]);

float getTotalAptitude(bitset<BIT_IND> array[]);

float getProbability(bitset<BIT_IND> individual,int totalAptitude);

bitset<BIT_IND> rouletteSelection(bitset<BIT_IND> array[], int totalAptitude);

void swapInd(bitset<BIT_IND> array[]);

bitset<BIT_IND> tournamentSelection(bitset<BIT_IND> &p1, bitset<BIT_IND> &p2);

bitset<BIT_IND> crossAlgorithm(bitset<BIT_IND> &p1, bitset<BIT_IND> &p2);

bitset<BIT_IND> mutationAlgorithm(bitset<BIT_IND> individual);

int getMinGenerationValue(bitset<BIT_IND> array[]);

int getMaxGenerationValue(bitset<BIT_IND> array[]);

int getGenerationAverage(bitset<BIT_IND> array[]);
