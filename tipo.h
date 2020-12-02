#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct //tipo
{
    int id;
    char descripcion[20];
} eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo tipos[], int tam_t);
void mostrarTipo(eTipo unTipo);
int obtenerDescripcionTipo(eTipo tipos[], int tam_t, int idTipo, char descripcionTipo[]);
int mostrarTiposModificar(eTipo tipos[], int tam_t);
