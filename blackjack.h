#ifndef BLACKJACK_H
#define BLACKJACK_H 1

#include <iostream>
#include <time.h>

//using namespace std;

int blackjack(char usuario[20]);
int es_blackjack(int usuario, int compu);
int mas_cartas();
int sumar_cartas(int cartas[], int actual);
int maximo(int usuario, int compu);
void comparar (int usuario, int compu);

#endif

