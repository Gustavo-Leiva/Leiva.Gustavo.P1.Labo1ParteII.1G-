#include <stdio.h>
#include <stdlib.h>

#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "destino.h"
#include "viaje.h"

#include "validaciones.h"

#define TAM_M 15 //tamanio de micros
#define TAM_E 4 //tamanio de empresas
#define TAM_T 4 //tamanio de tipos
#define TAM_D 4 //tamanio de destinos
#define TAM_V 15 //tamanio de viajes


#define CANT_M 4 //cantidad de micros lo deje en cero para no mostrar nada / indicar cantidad para listar
#define CANT_V 0 //cantidad de viajes lo deje en cero para no mostrar nada /indicar cantidad para listar


int main()
{
    char salir = 'N';
    char opcion [] = {"1,2,3,4,30"};
    int proximoId = 8000;
    int proximoIdViaje = 7000;
    //int flagMicro = 0;
    eMicro micros[TAM_M];
    eViaje viajes[TAM_V];


    inicializarMicros(micros, TAM_M);
    inicializarViaje(viajes, TAM_V);

    harcodearMicros(micros, TAM_M, CANT_M, &proximoId);
    harcodearViajes(viajes, TAM_V, CANT_V, &proximoIdViaje);



    eEmpresa empresas[TAM_E] =
    {
        {1000, "Plusmar"},
        {1001, "Flecha Bus"},
        {1002, "Tas"},
        {1003, "El Rapido"}

    };



    eTipo tipos[TAM_T] =
    {
        {5000, "Comun"},
        {5001, "CocheCama"},
        {5002, "Doble"},
        {5003, "Vip"}

    };




    eDestino destinos[TAM_D] =
    {
        {20000, "Calafate", 22250},
        {20001, "Bariloche",103000},
        {20002, "Salta", 84400},
        {20003, "Mendoza", 95600}


    };


    do
    {
        switch(menuMicro())
        {
        case 1:
            if(altaMicro(micros, TAM_M, empresas, TAM_E, tipos, TAM_T, &proximoId))
            {
                printf("Datos cargados con exito!!!\n");

            }

            else
            {
                printf("No se pudo cargar los datos\n");

            }

            break;
        case 2:
            modificarMicro(micros, TAM_M, empresas, TAM_E, tipos, TAM_T);

            break;
        case 3:
             bajaMicro(micros, TAM_M, empresas, TAM_E, tipos, TAM_T);
            break;
        case 4:
            system("cls");
            ordenarMicroXEmpresaCapacidad(micros, TAM_M);
            listarMicros(micros, TAM_M, empresas, TAM_E, tipos, TAM_T);
            break;
        case 5:
            system("cls");
            listarEmpresas(empresas, TAM_E);
            break;
        case 6:
            system("cls");
            listarTipos(tipos, TAM_T);
            break;
        case 7:
            system("cls");
            listarDestinos(destinos, TAM_D);
            break;
        case 8:



            if(altaViaje(viajes, TAM_V, micros, TAM_M, empresas, TAM_E, tipos, TAM_T,destinos, TAM_D, &proximoIdViaje))
            {
                printf("viaje cargado con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar viaje\n");
            }

            break;


        case 9:
            system("cls");
            listarViajes(viajes, TAM_V,destinos, TAM_D);
            break;

        case 30:
            confirmarSalida (&salir);
            while(salir != 'S' && salir != 'N')
            {
                printf("Error!!");
                confirmarSalida (&salir);
            }
            break;

        default:
            validarOpcion(opcion);
            break;

        }

        system("pause");//importante para mostrar los informes sino no pausa el sistema.


    }
    while(salir != 'S');



    return 0;

}









