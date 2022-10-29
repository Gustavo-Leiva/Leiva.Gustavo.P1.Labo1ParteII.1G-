#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;


} eFecha;

#endif // FECHA_H_INCLUDED
int validoDia(int dia);
int validoMes(int mes);
int validoAnio(int anio);
int validoAnioBisiesto(int anio);
int validoDiaMes(int mes, int dia, int anio);
int pidoValidoFecha(eFecha* fecha);
