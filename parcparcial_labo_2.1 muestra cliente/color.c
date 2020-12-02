#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
int mostrarColores(eColor color[], int tam_c)
{
    int error = 1;
    if(color!= NULL && tam_c > 0)
    {
        system("cls");
        printf("--------------------\n");
        printf("--ID      Color   --\n");
        printf("--------------------\n");
        for(int i=0; i<tam_c; i++)
        {
            mostrarColor(color[i]);
        }
        error = 0;
    }
    return error;
}

void mostrarColor(eColor unColor)
{
    printf("   %d   %s \n",unColor.id,unColor.nombreColor);
}



int obtenerDescripcionColor(eColor colores[], int tam_c, int idColor, char nombreColor[])
{
    int error = 1;
    if(colores != NULL && tam_c > 0 && nombreColor != NULL)
    {
        for (int i = 0; i<tam_c ; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(nombreColor,colores[i].nombreColor);
                error = 0;
                break;
            }
        }
    }
    return error;
}
