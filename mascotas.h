#include "tipo.h"
#include "color.h"
#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include "cliente.h"

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
    int idCliente;
}eMascota;



int inicializarMascotas(eMascota mascotas[], int tam_m);
int buscarLibre(eMascota mascotas[], int tam_m);
int bajaMascota(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor color[],int tam_c, eCliente clientes[],int tam_cli);
//int mostrarMascotas(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c);
//int mostrarMascotas(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c);
int buscarMascota(eMascota mascotas[],int tam_m,int idMascotas);
//void mostrarMascota(eMascota mascota, eTipo tipos[],int tam_t,eColor colores[],int tam_c);
int harcodearMascotas(eMascota mascotas[],int tam_m,int cantidad);
//void mostrarMascota(eMascota mascota, eTipo tipos[],int tam_t,eColor colores[],int tam_c);
int altaMascota(eMascota mascotas[],int tam_m,int idMascota,eTipo tipos[],int tam_t,eColor color[],int tam_c, eCliente clientes[], int tam_cli);
//int modificarMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t, eColor colores[], int tam_c);
int modificarMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t, eColor colores[], int tam_c,eCliente clientes[], int tam_cli);

int ordenarMascotas(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t);
int modificarTipo(eMascota mascotas[], int tam_m, int indice,eTipo tipos[],int tam_t);
int modificarEdad(eMascota mascotas[],int tam_m,int indice);
//int modificarEdad(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,int indice,eCliente clientes[],int tam_cli);
int obtenerNombreMascota(eMascota mascotas[], int tam_m, int idMascotas, char nombreMascota[]);
int listarMascotasXColor(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli);
//int listarMascotasXTipo(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t);
int listarMascotasXTipo(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli);
int contarMascotasXTipoYColor(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c);
int listarTodasLasMascotasXtipo(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli);
int modificarCliente(eMascota mascotas[],int tam_m,int indice,eCliente clientes[],int tam_cli);
//int modificarCliente(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,int indice,eCliente clientes[],int tam_cli);
int listarMascotaMasJoven(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli);
int coloresConMasMascotas(eMascota mascotas[], int tamM, eColor color[], int tamC);
int menuModificar();
int buscarMascotaXId(eMascota mascotas[],int tamMas,int id);
int getIdMascota(eMascota mascotas[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli);
int buscarCliente(eCliente clientes[],int tam_cli,int idCliente);
void mostrarMascota(eMascota mascota, eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli);
int mostrarMascotas(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli);
#endif // MASCOTAS_H_INCLUDED
