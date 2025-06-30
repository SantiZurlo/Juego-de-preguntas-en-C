#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "pregunta.h"

struct Pregunta{
char pregunta[120];
char respuesta[4][120];
int correcta;
};

int getCorrecta (PreguntaPtr p){
return p->correcta;
}

void mostrarPregunta(PreguntaPtr preg){
printf("\n");
printf("\n%s\n",preg->pregunta);
for(int i=0;i<4;i++){
printf("%d-%s\n",i+1,preg->respuesta[i]);
}


}

PreguntaPtr preguntaParametro(char pregunta[100],char respuesta[4][50],int correcta){
PreguntaPtr p1=malloc(sizeof(struct Pregunta));
strcpy(p1->pregunta,pregunta);
strcpy(p1->respuesta[0],respuesta[0]);
strcpy(p1->respuesta[1],respuesta[1]);
strcpy(p1->respuesta[2],respuesta[2]);
strcpy(p1->respuesta[3],respuesta[3]);
p1->correcta=correcta;

    return p1;

}

void cargarPreguntasArchivo(Lista lis){
  FILE* archivo = fopen("preguntasfutbol.txt", "r");

   char pregunta[120];
    char respuesta[4][50];
    int correcta;

    while (!feof(archivo)){
       char linea[550];
fgets(linea, sizeof(linea), archivo);
sscanf(linea, "%119[^,],%119[^,],%119[^,],%119[^,],%119[^,],%d", pregunta,respuesta[0],respuesta[1] ,respuesta[2] ,respuesta[3], &correcta);
     PreguntaPtr pregunta1=preguntaParametro(pregunta,respuesta,correcta);

     insertarFinal(lis, (void*)&pregunta1);
    }
    fclose(archivo);

}









