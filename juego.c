#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jugador.h"
#include "lista.h"
#include "pregunta.h"
#include "juego.h"


void casodesempate(Lista lis,int maxP){
int n1 = rand() % 150;
int n2 = rand() % 150;
int correcta;
int men=-1;
int j1[obtenerTamanio(lis)];
int rta;
int resta;
char preg[70];

correcta = (n1 + n2*n1+n2*n1+n2);
sprintf(preg, "%d + %d * %d + %d * %d + %d ", n1, n2,n1,n2,n1,n2);
printf("\n%s\n", preg);
    for (int i = 0; i < obtenerTamanio(lis); i++){
        JugadorPtr jugador=*((JugadorPtr*)obtenerDato(lis,i));
        if (getPuntos(jugador)==maxP){
            printf("Le toca a %s:",getAlias(jugador));
            scanf("%d", &rta);
            resta = abs(correcta-rta);
            j1[i]=resta;
        }
        else {
            j1[i]=-1;
        }
    }
    for (int i = 0; i < obtenerTamanio(lis); i++){
        if(i==0){
            men=j1[i];
        }
        else{
        if(men>j1[i]){
        men=j1[i];
        }
        }
    }
    for (int i = 0; i < obtenerTamanio(lis); i++){
        JugadorPtr jugador2=*((JugadorPtr*)obtenerDato(lis,i));
        if(j1[i]==men){
            setPuntos(jugador2,getPuntos(jugador2)+1);
        }
    }
}



void jugar(){
srand(time(NULL));
int tamanio=verificarCant();

Lista totaljugadores=crearLista(sizeof(JugadorPtr));
system("cls");
for (int i = 0; i < tamanio; i++){
    JugadorPtr jugador=cargarJugadorPorTeclado();
    insertarFinal(totaljugadores, (void*)&jugador);

}

Lista totalpreguntas=crearLista(sizeof(PreguntaPtr));
cargarPreguntasArchivo(totalpreguntas);

for (int i = 0; i < tamanio; i++){
JugadorPtr j1=*((JugadorPtr*)obtenerDato(totaljugadores,i));
int verifico=1;
int cant=0;
int posicion;
int total=obtenerTamanio(totalpreguntas);
while(cant<total && verifico!=0){

    posicion=(rand() % obtenerTamanio(totalpreguntas));
    PreguntaPtr p=*((PreguntaPtr*)obtenerDato(totalpreguntas,posicion));
     system("cls");
    printf("Le toca a %s, te deseo suerte",getAlias (j1));
    mostrarPregunta(p);
    remover(totalpreguntas,posicion,p);
    int opcion=0;
    printf("\n Repuesta:");
    scanf("%d",&opcion);

    if(opcion>4){
        verifico=0;
    }

    if (opcion==getCorrecta (p) ){
       setPuntos(j1,getPuntos(j1)+10);
        printf("\n Correcto =)\n");
    }
    else {
    printf("\n Incorrecto =(\n");
    printf("\n La Repuesta correcta era la opcion: %d \n\n",getCorrecta (p));
    verifico=0;

    }
cant=cant+1;
system("pause");
}
}

int repeticiones;
int maxPun;
do{
    maxPun=buscarMaximo(totaljugadores);
    repeticiones=repetidos(totaljugadores,maxPun);
    if(repeticiones>1){
    system("cls");
    printf("\nSE PRODUJO UN EMPATE\n");
    printf("\nVAMOS A HACER UNA PREGUNTA MATEMATICA PARA DESEMPATAR\n");
    casodesempate(totaljugadores,maxPun);
    }
}while(repeticiones>1);
system("cls");

printf("\n-----PUNTOS PARTIDA:-----\n");
mostrarJugadores(totaljugadores);
printf("-----GANADOR-----:\n");
ordenarLista(totaljugadores);
JugadorPtr ganador=*((JugadorPtr*)obtenerDato(totaljugadores,0));
mostrarJugador(ganador);

Lista m=crearLista(sizeof(JugadorPtr));
jugadoresDesdeArchivo(m);
    for ( int i = 0 ; i< obtenerTamanio(totaljugadores); i++){
     JugadorPtr jugador=*((JugadorPtr*)obtenerDato(totaljugadores,i));
        agregarMaximos(m,jugador);
    }
guardarEnArchivo(m);
}

void menuJuego (){
int eleccion;
printf("-------JUEGO DE SANTIAGO ZURLO DNI: 46291432----------\n");
printf("-----Bienvenido al Juego de Preguntas de Futbol-------\n");
printf("\n1) Jugar\n");
printf("2) Puntajes Maximos \n");
printf("3) Salir\n");
scanf("%d",&eleccion);

switch(eleccion){
case 1: {
system("cls");
jugar();
}
break;

case 2:{
system("cls");
Lista lis=crearLista(sizeof(JugadorPtr));
jugadoresDesdeArchivo(lis);
printf("-------PUNTAJES MAXIMOS---------");
mostrarJugadores(lis);


}
break;

case 3:
return 0;
break;
}
}
