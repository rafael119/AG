#include <allegro.h>
#include "inicia.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <bitset>
#include "ruleta.h"

using namespace std;
int main ()
{
    int k=0,i=0;
    ofstream tabla;
    tabla.open("tabla.txt", fstream::out);
    int num_generaciones;
    printf("Da el numero de generaciones:");
    scanf("%d",&num_generaciones);

    bitset<BIT_IND> inicial[NUM_IND];
    bitset<BIT_IND> seleccion[NUM_IND];
    bitset<BIT_IND> cruza[NUM_IND];
    bitset<BIT_IND> mutacion_des[NUM_IND];

    int minimo[num_generaciones];
    int maximo[num_generaciones];
    int generationValuesAverage[num_generaciones];
    int ind_apti[NUM_IND];

    IniciarInd(inicial);
    for ( k = 0; k < num_generaciones; k++){

            int totalAptitude = getTotalAptitude(inicial);

            for(i=0;i<NUM_IND;i++){
                ind_apti[i]=(int)getIndividualAptitude(inicial[i]);
            }

            for ( i = 0; i < NUM_IND; i++)
            {
                seleccion[i] = rouletteSelection(inicial, totalAptitude);
            }

            for ( i = 0; i < NUM_IND; i+=2)
            {
                cruza[i] = crossAlgorithm(seleccion[i], seleccion[i + 1]);
                cruza[i + 1] = crossAlgorithm(seleccion[i + 1], seleccion[i]);

            }

            for ( i = 0; i < NUM_IND; i++)
            {
                mutacion_des[i] = cruza[i];
            }

            int mutation_value = NUM_IND / PROBABILITY;

            srand (time(NULL));

            for (i = 0; i < mutation_value; i++)
            {
                int indivual_to_mutate = rand() % NUM_IND;
                mutacion_des[indivual_to_mutate] = mutationAlgorithm(cruza[indivual_to_mutate]);
            }

            int min_gen_value = getMinGenerationValue(mutacion_des);
            int max_gen_value = getMaxGenerationValue(mutacion_des);
            int gen_average = getGenerationAverage(mutacion_des);

            minimo[k] = min_gen_value;
            maximo[k] = max_gen_value;
            generationValuesAverage[k] = gen_average;

            tabla << "Generacion: " << k+1 << endl;
            tabla << "N\t\t inicial\t\tx^2\t\tseleccion\t\tcruza\t\tmutacion\t\t"<<endl;
            int indice=1;
            for (int i = 0; i < NUM_IND; i++)
            {
                tabla << indice <<"\t\t"<< inicial[i] << "\t\t\t"<<ind_apti[i]<<"\t\t\t" << seleccion[i] << "\t\t\t"<< cruza[i] << "\t\t\t" << mutacion_des [i] << endl;
                indice++;
             }

            for (int i = 0; i < NUM_IND; i++)
            {
                inicial[i] = mutacion_des[i];
            }

    }

    int sep=600/num_generaciones;
    /*********************************************/

    inicia_allegro(800,800);
    int in=20;
    BITMAP *buffer = create_bitmap(800,800);
    clear_to_color(buffer, 0x0a6c92);
    line(buffer, 20, 600, 700, 600,  palette_color[11]);
    line(buffer, 20, 600, 20, 20,  palette_color[11]);
    textout_centre_ex(buffer, font,"histograma", 160, 25, 0xFFFFFF, 0x999999);
    textout_centre_ex(buffer, font,"Generaciones", 160, 650, 0xFFFFFF, 0x999999);
    for(i=0;i<num_generaciones-1;i++){
        line(buffer, in, 600-(minimo[i]/2), in+sep, 600-(minimo[i+1]/2),  0xbde4ff);
        line(buffer, in, 600-(maximo[i]/2), in+sep, 600-(maximo[i+1]/2),  0xe5ffdc);
        line(buffer, in, 600-(generationValuesAverage[i]/2), in+sep, 600-(generationValuesAverage[i+1]/2),  0xe5b0dc);

        line(buffer, in+sep, 605, in+sep, 595,  palette_color[11]);

        in=in+sep;
    }
    in=20;
    for(i=0;i<num_generaciones;i++){
         textprintf(buffer, font, in, 580-(minimo[i]/2), 0xFFFFFF, "%d",(minimo[i]));
         textprintf(buffer, font, in, 580-(maximo[i]/2), 0xFFFFFF, "%d",(maximo[i]));
         textprintf(buffer, font, in, 580-(generationValuesAverage[i]/2), 0xFFFFFF, "%d",(generationValuesAverage[i]));
         textprintf(buffer, font, in, 610, 0xFFFFFF, "%d",(i));
        in=in+sep;
    }




    blit(buffer, screen, 0, 0, 0, 0, 800, 800);
    readkey();

    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN ()


