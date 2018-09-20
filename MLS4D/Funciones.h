#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getInt(char mensaje[],int* dato,char mensajeError[]);
int getFloat(char mensaje[],float* dato,char mensajeError[]);
int getString(char mensaje[],char* dato,char mensajeError[]);


int validarEntero(char auxiliar[],int* dato,char mensaje[]);
int validarFloat(char auxiliar[],float* dato,char mensaje[]);
int validarString(char auxiliar[],char* dato,char mensaje[]);

void stringToUpper(char caracter[]);


#endif // FUNCIONES_H_INCLUDED
