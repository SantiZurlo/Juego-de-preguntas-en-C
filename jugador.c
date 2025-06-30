#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "jugador.h"
#include "lista.h"

struct Jugador {

int puntos;
char alias[25];
int dni;
};

char* getAlias (JugadorPtr j){
return j->alias;
}

void setPuntos (JugadorPtr j,int puntos){
j->puntos=puntos;
}

int getPuntos (JugadorPtr j){
return j->puntos ;
}

JugadorPtr jugadorParametro(char alias[25],int dni,int puntos){
JugadorPtr j1=malloc(sizeof(struct Jugador));
strcpy(j1->alias,alias);
j1->dni=dni;
j1->puntos=puntos;
return j1;
}

void agregarMaximos(Lista lis,JugadorPtr jug){
char auxA[25];
int auxP;

for( int i = 0 ; i<obtenerTamanio(lis);i++){
    JugadorPtr nuevo=*((JugadorPtr*)obtenerDato(lis,i));
    if(jug->dni==nuevo->dni){
        if(jug->puntos>nuevo->puntos){
            strcpy(auxA, jug->alias);
            strcpy(jug->alias, nuevo->alias);
            strcpy( nuevo->alias,auxA);
            auxP= jug->puntos;
            jug->puntos = nuevo->puntos;
            nuevo->puntos = auxP;
        }
    return;
    }
}
insertarFinal(lis,(void*)&jug);
 }

void mostrarJugadores(Lista lis){
for ( int i = 0 ; i< obtenerTamanio(lis) ; i++){
    JugadorPtr jugadores = *((JugadorPtr*) obtenerDato(lis, i));
    mostrarJugador(jugadores);
}
}


void guardarEnArchivo(Lista lis){
FILE* archivo = fopen("maximos.txt", "w");

for( int i = 0; i<obtenerTamanio(lis); i++){
   JugadorPtr jugador = *((JugadorPtr*) obtenerDato(lis, i));
   fprintf(archivo, "%s,%d,%d \n",jugador->alias,jugador->dni,jugador->puntos );
    }
fclose(archivo);
}

void mostrarJugador(JugadorPtr jug){
printf("\n");
printf("Nombre: %s\n",jug->alias);
printf("DNI: %d\n",jug->dni);
printf("Puntos: %d \n",jug->puntos);
printf("\n");
}

int verificarCant() {
int aux;
printf("Cuantos jugadores van a jugar (entre 2 y 4): ");
scanf("%d",&aux);

    while (aux < 2 || aux > 4) {
    printf("Cantidad incorrecta ");
    printf("Recorda que la cantidad es entre 2 y 4 jugadores: ");
    scanf("%d",&aux);
    }
return aux;
}

void ordenarLista(Lista lis){
char auxA[25];
int auxD;
int auxP;

    for ( int i = 0 ; i<obtenerTamanio(lis);i++){
    for ( int j = 0 ; j<obtenerTamanio(lis)-1;j++){
        JugadorPtr a=*((JugadorPtr*)obtenerDato(lis,i));
        JugadorPtr b=*((JugadorPtr*)obtenerDato(lis,j));
        if (a->puntos > b->puntos){
            strcpy(auxA, a->alias);
            strcpy(a->alias, b->alias);
            strcpy( b->alias,auxA);
            auxD = a->dni;
            a->dni = b->dni;
            b->dni = auxD;
            auxP = a->puntos;
            a->puntos = b->puntos;
            b->puntos = auxP;
        }

    }

    }
}

JugadorPtr cargarJugadorPorTeclado() {
   char alias[25];
   int dni;
   int puntos;
    printf("\Ingresa tus datos: \n");
    printf("Nombre: ");
    fflush(stdin);
    gets(alias);
    printf("DNI: ");
    scanf("%d",&dni);
    puntos=0;
    printf("\n");
return jugadorParametro(alias,dni,puntos);

}

void jugadoresDesdeArchivo(Lista lis){
FILE* archivo = fopen("maximos.txt", "r");
char alias[25];
int dni;
int puntos;
char aux[300];

    while (!feof(archivo)) {
        fgets(aux, sizeof(aux), archivo);
        if(sscanf(aux, "%24[^,],%d,%d", alias, &dni, &puntos)==3){
            JugadorPtr  j=jugadorParametro(alias,dni,puntos);
            insertarFinal(lis, (void*)&j);
        }
    strcpy(aux,"");
    }
fclose(archivo);
}

int buscarMaximo(Lista lis){
int maxP=0;
    for ( int i = 0 ; i< obtenerTamanio(lis); i++){
        JugadorPtr jugador=*((JugadorPtr*)obtenerDato(lis,i));
        if(getPuntos(jugador)>maxP){
            maxP=getPuntos(jugador);
        }
    }
return maxP;
}

int repetidos(Lista lis,int maxP){
int contador=0;
    for ( int i = 0 ; i< obtenerTamanio(lis); i++){
        JugadorPtr jugador=*((JugadorPtr*)obtenerDato(lis,i));
        if(getPuntos(jugador)==maxP){
            contador=contador+1;
        }
    }
return contador;
}

