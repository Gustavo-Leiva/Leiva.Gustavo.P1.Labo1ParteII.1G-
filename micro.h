
#include "empresa.h"
#include "tipo.h"


#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

typedef struct
{

    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;



} eMicro;

#endif // MICRO_H_INCLUDED

int inicializarMicros(eMicro vec[], int tam);
int harcodearMicros(eMicro vec[], int tam, int cantM, int* pNextId);
int buscarLibreMicros(eMicro vec[], int tam, int* pIndex);
int menuMicro();
int altaMicro(eMicro vec[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pNextId);


int modificarMicro(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int listarMicros(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
void mostrarMicroFila(eMicro micros, int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int buscarMicro(eMicro micros[], int tamM, int id, int* pIndex);
int validarMicro (eMicro micros[], int tamM, int id);
void mostrarMicro(eMicro micros, int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int menuModificarMicro();
int bajaMicro (eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);


int ordenarMicroXEmpresaCapacidad(eMicro vec[], int tam);

