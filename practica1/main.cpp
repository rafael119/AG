#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "inicia.h"

int main ()
{
    inicia_allegro(600,320);
    int i=0,n=20,in=20;
    BITMAP *buffer = create_bitmap(600,320);
    clear_to_color(buffer, 0x999999);
    int array[10];
    srand (time(NULL));
    int k;
    for(k=0;k<10;k++){
        array[k]=rand()%270;
        printf("%d\n",array[k]);
    }

    int tam= sizeof(array)/sizeof(*array);
    printf("tamaño: %d",tam);
    line(buffer, 20, 300, 580, 300,  palette_color[11]);
    line(buffer, 20, 300, 20, 20,  palette_color[11]);
    textout_centre_ex(buffer, font,"histograma", 160, 25, 0xFFFFFF, 0x999999);
    textout_centre_ex(buffer, font,"X", 160, 315, 0xFFFFFF, 0x999999);
    for(i=0;i<tam-1;i++){
    line(buffer, in, 300-array[i], in+50, 300-array[i+1],  palette_color[12]);
    line(buffer, in+50, 305, in+50, 295,  palette_color[11]);
    in=in+50;
    n=n+20;
    }
    n=20;in=20;
    for(i=0;i<tam;i++){
        textprintf(buffer, font, in, 290-array[i], 0xFFFFFF, "%d",(array[i]));
        in=in+50;
        n=n+20;
    }
    blit(buffer, screen, 0, 0, 0, 0, 600, 480);
    readkey();
    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN ()


