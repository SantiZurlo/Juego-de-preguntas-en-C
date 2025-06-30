#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "lista.h"

typedef struct Jugador * JugadorPtr;

void ordenarLista(Lista lis);
JugadorPtr cargarJugadorPorTeclado();
int getPuntos (JugadorPtr j);
void jugadoresDesdeArchivo(Lista l);
int verificarCant();
void setPuntos (JugadorPtr j,int puntos);
JugadorPtr jugadorParametro(char alias[25],int dni,int puntos);
void agregarMaximos(Lista lis,JugadorPtr jug);
void mostrarJugadores(Lista lis);
char* getAlias (JugadorPtr j);
void mostrarJugador(JugadorPtr jug);
void guardarEnArchivo(Lista lis);

int buscarMaximo(Lista lis);
int repetidos(Lista lis,int maxP);



#endif // JUGADOR_H_INCLUDED
