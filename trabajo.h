#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "cliente.h"

typedef struct //trabajo
{
    int id;
    int idMascota;
    int idServicio;
    int isEmpty;
    eFecha fecha;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo trabajos[], int tam_t);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam_t);
int buscarTrabajo(eTrabajo trabajos[], int tam_t);
int altaTrabajo(eMascota mascotas[],int tam_m,int idTrabajo,eTipo tipos[],int tam_t,eColor color[],int tam_c, eServicio servicios[],int tam_s, eTrabajo trabajos[],int tam_tra,eCliente clientes[],int tam_cli);
//int mostrarTrabajos(eTrabajo trabajos[], int tam_t, eServicio servicios[], int tam_s, eMascota mascotas[], int tam_m);
int mostrarTrabajos(eTrabajo trabajos[], int tam_t, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli);
//void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli);
int listarTrabajosParaCadaMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli);
//int listarTrabajosRealizadosEnUnaFecha(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s);
int listarTrabajosRealizadosEnUnaFecha(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli);
//int listarDineroInvertidoPorMascota (eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s);
//int listarDineroInvertidoPorMascota (eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s);
int listarDineroInvertidoPorMascota (eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s, eCliente clientes[], int tam_cli);
