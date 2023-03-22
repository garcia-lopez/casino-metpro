#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cctype>
#include <string.h>

// Importa librerias de menu
#include "historial.h"
#include "utils.h"
#include "blackjack.h"
#include "menuUsuario.h"
#include "ruleta.h"


void jugar(char usuario[20]);

int main(){

    struct historial **partidas_array = (struct historial **) malloc(sizeof(**partidas_array) * 50);
    int x;
    char usuario[20];
    strcpy(usuario, " ");

    do{
        x = menuUsuario(usuario);
    }while (x == 0);

    int opcion = imprimir_menu();

   while(opcion != 3){
        switch (opcion)
            {
            case 1: // Corre los juegos
                jugar(usuario);
                break;

            case 2:
                imprimir_partidas(usuario);
                break;

            case 3: // Salir (Cierra la apicación)
                std::cout << "!GRACIAS POR USAR CASINO MUNDO SLOT!\n\n";
                system("cls");
                break;
            
            default: // Vuelve a imprimir el menu
                std::cout << "\nEl numero que ingreso no es correcto.";
                opcion = imprimir_menu();
                break;
        }
        opcion = imprimir_menu();
        system("cls");
    }

    return 0;
}

void jugar(char usuario[20])
// El menu para acceder a los juegos.
{    
    int opc, juego, ganancia, apuesta; 
    std::cout << "Cuanto desea apostar?\t";
    std::cin >> apuesta;

    std::cout << "\nIngrese el numero del juego que desea jugar"
        << "\n1. Blackjack"
        << "\n2. Ruleta\n"; 
    std::cin >> opc;

    switch (opc)
    {
    case 1:
        juego = 1;
        ganancia= blackjack(usuario);
        apuesta = apuesta * ganancia; // cambia el valor a negativo si el usuario perdio y a 0 si empato (necesario para el historial)
        añadir_partida(apuesta, juego, usuario); // añade el juego que acaba de terminar al historial
        break;
        
    
    case 2:
        juego = 2;
        ganancia = ruleta();
        apuesta = apuesta * ganancia; 
        añadir_partida(apuesta, juego, usuario);
        break;
    }

}
