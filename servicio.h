#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct //servicio
{
    int id;
    char descripcion[20];
    int precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio servicios[], int tam_s);
void mostrarServicio(eServicio unServicio);
int buscarServicios(eServicio servicios[],int tam_s,int idServicio);
int obtenerDescripcionServicio(eServicio servicios[], int tam_s, int idServicio, char nombreServicio[]);
int obtenerPrecioServicio(eServicio servicios[], int tam_s, int idServicio, char precio);
int getIdServicio(eServicio servicios[],int tam_s);
