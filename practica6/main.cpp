#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <bitset>
#include <random>
#include <time.h>


#define BIT_IND 10
#define MAX_VAL 1023
#define PUNTO_CRUZA 5


using namespace std;
void IniciarInd(bitset<BIT_IND> *individuo){

		*individuo = rand() % MAX_VAL;

}

bitset<BIT_IND> cruzaunpunto(bitset<BIT_IND> &p1, bitset<BIT_IND> &p2) {
    bitset<BIT_IND> aux = p1;
    for (int i = 0; i <= PUNTO_CRUZA; i++)
    {
    	aux.set(PUNTO_CRUZA - i, p2[PUNTO_CRUZA - i]);
    }
    return aux;
}
bitset<BIT_IND> cruzaDP(bitset<BIT_IND> &individuoA, bitset<BIT_IND> &individuoB) {
    bitset<BIT_IND> aux1;
    bitset<BIT_IND> aux2;
    bitset<BIT_IND> res;
    bitset<BIT_IND> and1 (string("1111000011"));
    bitset<BIT_IND> and2 (string("0000111100"));
    aux1 = individuoA & and1;
    aux2 = individuoB & and2;
    int total = aux1.to_ulong() + aux2.to_ulong();
    res = total;
    return res;
}
bitset<BIT_IND> cruzaUni(bitset<BIT_IND> &individuoA, bitset<BIT_IND> &individuoB) {
    bitset<BIT_IND> aux1;
    bitset<BIT_IND> aux2;
    bitset<BIT_IND> res;
    bitset<BIT_IND> and1 (string("1011001011"));
    bitset<BIT_IND> and2 (string("0100110100"));
    aux1 = individuoA & and1;
    aux2 = individuoB & and2;
    int total = aux1.to_ulong() + aux2.to_ulong();
    res = total;
    return res;
}
int main(){
	bitset<BIT_IND> individuo1;
	bitset<BIT_IND> individuo2;
	bitset<BIT_IND> aux1;
	bitset<BIT_IND> aux2;
	srand(time(NULL));
	IniciarInd(&individuo1);
	IniciarInd(&individuo2);
	int op=0;
	while(op!=5){

            cout<<"\t\t**********Cruzaz**********\t\t"<<endl;
            cout<<"\t\t1)Cruza por punto\t\t"<<endl;
            cout<<"\t\t2)Cruza por dos puntos\t\t"<<endl;
            cout<<"\t\t3) Cruza acentuada\t\t"<<endl;
            cout<<"\t\t4)Cambia valores de individuos"<<endl;
            cout<<"\t\tSalir"<<endl;
            cout<<"\t\t Selecciona:\t\t"<<endl;
            cin>>op;

        switch(op){
                case 1:
                    cout<<endl;
                    cout<< "Padre 1: "<<individuo1<<endl;
                    cout<< "Padre 2: "<<individuo2<<endl;
                    cout<<endl;
                    aux1= cruzaunpunto(individuo1,individuo2);
                    aux2= cruzaunpunto(individuo2,individuo1);
                    cout<<"\t\tResultados"<<endl;
                    cout<<"hijo 1:"<<aux1<<endl;
                    cout<<"hijo 2:"<<aux2<<endl;
                    cout<<endl;



                    break;
                case 2:
                    cout<<endl;
                    cout<< "Padre 1: "<<individuo1<<endl;
                    cout<< "Padre 2: "<<individuo2<<endl;
                    cout<<endl;
                    aux1=cruzaDP(individuo1,individuo2);
                    aux2=cruzaDP(individuo2,individuo1);
                    cout<<"\t\tResultados"<<endl;
                    cout<<"hijo 1:"<<aux1<<endl;
                    cout<<"hijo 2:"<<aux2<<endl;
                    cout<<endl;
                    break;
                case 3:
                    cout<<endl;
                    cout<< "Padre 1: "<<individuo1<<endl;
                    cout<< "Padre 2: "<<individuo2<<endl;
                    cout<<endl;
                    aux1=cruzaUni(individuo1,individuo2);
                    aux2=cruzaUni(individuo2,individuo1);
                    cout<<"\t\tResultados"<<endl;
                    cout<<"hijo 1:"<<aux1<<endl;
                    cout<<"hijo 2:"<<aux2<<endl;
                    cout<<endl;
                    break;
                case 4:
                    IniciarInd(&individuo1);
                    IniciarInd(&individuo2);
                    break;
                default:
                        cout << "Opcion invalida" << endl;

        }
	}
return 0;
}

