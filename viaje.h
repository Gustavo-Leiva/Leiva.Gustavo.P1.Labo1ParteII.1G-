
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "destino.h"


#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

} eViaje;



#endif // VIAJE_H_INCLUDED
int inicializarViaje(eViaje vec[], int tamV);
int buscarLibreViaje (eViaje vec[], int tamV, int* pIndex);
int altaViaje(eViaje vec[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,  int* pNextId);

int listarViajes(eViaje viajes[],  int tamV, eDestino destinos[], int tamD);
void mostrarViajeFila (eViaje viajes, eDestino destinos[], int tamD);

int harcodearViajes(eViaje vec[], int tamV, int cantV, int* pNextId);
