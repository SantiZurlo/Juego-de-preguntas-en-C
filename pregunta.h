#ifndef PREGUNTA_H_INCLUDED
#define PREGUNTA_H_INCLUDED
#include "lista.h"

typedef struct Pregunta * PreguntaPtr;


PreguntaPtr preguntaParametro(char pregunta[120],char posibles[4][50],int correcta);
void cargarPreguntasArchivo(Lista lis);
void mostrarPregunta(PreguntaPtr preg);
int getCorrecta (PreguntaPtr p);

#endif // PREGUNTA_H_INCLUDED
