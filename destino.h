#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{

    int id;
    char descripcion [25];
    float precio;

} eDestino;

#endif // DESTINO_H_INCLUDED

int cargarDescripcionDestino (eDestino destinos[], int tamD, int id, char desc[]);
int listarDestinos(eDestino destinos[], int tamD);
int buscarDestinos(eDestino destinos[], int tamD, int id, int* pIndex);
int validarDestinos(eDestino destinos[], int tamD, int id);
