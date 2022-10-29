#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"


#include <string.h>
#include <ctype.h>



/*
---------------------------------------------------------------------------------------
                            VALIDAR  CONVERTIR Y PEDIR NUMEROS ENTEROS
---------------------------------------------------------------------------------------
*/



int validarNumero(char numero[])
{
    int todoOk = 1;
    int longitud;

    if(numero != NULL)
    {
        longitud = strlen(numero)-1;

        for (int i= 0; i<longitud; i++)
        {
            if(!isdigit(numero[i]))
            {
                todoOk = 0;
                break;
            }
        }
    }

    return todoOk;
}



int convertirCharAInt(char num[], int* pNumero)
{
    int todoOk = 0;

    if(num != NULL && pNumero != NULL)
    {
        *pNumero = atoi(num);
        todoOk = 1;
    }
    return todoOk;
}


int pedirValidarNumero(int* pNumero, char mensaje[])
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0 || strcmp(buffNum, "\n")==0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }


    }
    if(convertirCharAInt(buffNum, &numero))
    {
            *pNumero = numero;
            todoOk = 1;

    }
    return todoOk;
}



/*
---------------------------------------------------------------------------------------
                            VALIDAR  CONVERTIR Y PEDIR CADENA DE CARACTERES
---------------------------------------------------------------------------------------
*/


int validarLetras(char letras[])
{
    int todoOk = 1;
    int esLetra;

    if(letras != NULL)
    {
        for(int i = 0; i < strlen(letras) -1; i++)
        {
            esLetra = isalpha(letras[i]);
            if(esLetra == 0)
            {
              todoOk = 0;
              break;
            }
        }
    }

    return todoOk;
}

int pedirValidarLetras(char cadena[], int tam, char mensaje[])
{
    int todoOk = 0;
    char buffer[100];

    if(cadena != NULL && mensaje != NULL && tam > 0)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, tam, stdin);

        while(validarLetras(buffer) == 0 || stricmp(buffer , "\n") == 0)
        {
            printf("Ingreso invalido.\nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, tam, stdin);
        }

        strcpy(cadena, buffer);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            todoOk = 1;
        }
    }
    return todoOk;
}




/*
---------------------------------------------------------------------------------------
                            VALIDAR  CONVERTIR Y PEDIR NUMEROS FLOTANTES
---------------------------------------------------------------------------------------
*/



int validarNumeroFloat(char flotante[], int tam)
{
    int todoOk = 1;
    int esFloat;
    int coma = tam;

    if(flotante != NULL && tam > 0)
    {
        for(int i = 0; i < strlen(flotante) -1; i++)
        {
            if(flotante[i] == '.')
            {
                coma = i;
            }

        }
        if(coma != tam)
        {
            for(int i = 0; i < coma; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }


            for(int i = coma +1; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);
                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
    }
    return todoOk;
}



int convertirCharAFloat(float* pFlotante, char flotante[])
{

    int todoOk = 0;

    if(pFlotante != NULL)
    {
        *pFlotante = atof(flotante);
        todoOk = 1;

    }

    return todoOk;
}



int pedirValidarNumeroFlotante(float* pNumero, char mensaje[])
{
    int todoOk = 0;
    char bufferNum [100];
    float numero;


    if(pNumero  != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(bufferNum, 100, stdin);
        while(validarNumeroFloat(bufferNum,100)==0)
        {
            printf("Ingreso invalido. \nReingrese %s ", mensaje);
            fflush(stdin);
            fgets(bufferNum, 100, stdin);

        }

        if(convertirCharAFloat(&numero, bufferNum))
        {

            *pNumero = numero;
            todoOk=1;
        }

        todoOk = 1;
    }

    return todoOk;
}






/*
---------------------------------------------------------------------------------------
                                  OTRAS VALIDACIONES
---------------------------------------------------------------------------------------
*/



int validarOpcion(char opcion[])
{
    int i;
    for(i=0; i<strlen(opcion); i++)
    {
        if(!(isdigit(opcion[i])))
        {
            printf("Opcion Incorrecta!!! \nIngrese solo una de las opciones indicadas, por favor.\n\n");

            return 1;
        }
    }
    return 0;
}



int validarCaracter(char valor, char a, char b)
{
    int todoOk = 0;

    if(valor == a || valor == b)
    {

        todoOk = 1;

    }
    return todoOk;


}








int confirmarCarga (char* x)
{
    int todoOk = 0;

    if( x != NULL)
    {
        printf("confirma carga? (S/N): ");
        fflush(stdin);
        scanf("%c", x );
        *x=toupper(*x);

        while(!(*x =='S' || *x =='N'))
        {
            printf("Error!! Ingrese 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",x);
            *x = toupper(*x);
        }

        if(*x == 's' || *x == 'S')
        {
            printf("Carga exitosa\n");
            todoOk = 1;

        }

        else
        {
            printf("Carga cancelada por usuario\n");
        }

    }

    return todoOk;
}









void confirmarSalida (char* x)
{
    printf("confirma salida? (S/N): ");
    fflush(stdin);
    scanf("%c", x );
    *x=toupper(*x);

    while(!(*x =='S' || *x =='N'))
    {
        printf("Error!! Ingrese 'S' o 'N': ");
        fflush(stdin);
        scanf("%c",x);
        *x = toupper(*x);
    }


}


int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo)
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL && mensaje != NULL && minimo < maximo)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAInt(buffNum, &numero))
        {
            while(numero < minimo || numero > maximo)
            {
                printf("Ingreso invalido. \nReingrese %s: ", mensaje);
                fflush(stdin);
                fgets(buffNum, 100, stdin);
                convertirCharAInt(buffNum, &numero);
            }
            *pNumero = numero;
            todoOk = 1;

        }
    }
    return todoOk;
}

