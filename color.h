#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct //color
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

int mostrarColores(eColor color[], int tam_c);
void mostrarColor(eColor unColor);
int obtenerDescripcionColor(eColor colores[], int tam_c, int idColor, char nombreColor[]);
