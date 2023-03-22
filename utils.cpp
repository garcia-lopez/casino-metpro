#include <iostream>
#include <string.h>
#include "historial.h"


int imprimir_menu(){
    // Imprime el menú principal y lee la opción ingresada por el usuario
    int opcion;
    printf("\n\n__________________________________________________________\n");
    printf("| ----------------BIENVENIDO A MUNDO SLOT----------------- | \n");
    printf("|==========================================================|\n");
    printf("|              DIGITE LA OPCION QUE DESEA                  |\n");
    printf("| <1> . ================   JUGAR   ========================|\n");
    printf("| <2> . ============== VER HISTORIAL ======================|\n");
    printf("| <3> . ================= SALIR ===========================|\n");
    printf("|__________________________________________________________|\n >>> ");
    scanf("%d", &opcion);
    
    return opcion;
}


void añadir_partida(int apuesta, int juego, char usuario[20]){
    // Añade la partida que se acaba de jugar al archivo de historial
    struct historial *partida = new struct historial();

    strcpy(partida->usuario, usuario);
    partida->juego = juego;
    partida->ganancia = apuesta; 

    FILE *archivo = fopen("./historiales.txt", "ab");
    if (archivo == NULL) {
        std::cout << "No se pudo abrir el archivo\n";
    return;
    }

    fwrite(partida, sizeof(struct historial), 1, archivo);
    fclose(archivo);
    return;
}


void imprimir_partidas(char usuario[20]){
    // Muestra el historial al usuario
    int i = 0;
    int val;
    //struct historial **partida = (struct historial **) malloc(sizeof(**partida) * 50);
    FILE *archivo = fopen("historiales.txt", "rb");

    do { 
        struct historial *partida = new struct historial();
        val = fread(partida, sizeof(struct historial), 1, archivo);
        if (!val) break;
        if (strcmp(partida->usuario, usuario)== 0){
            std::cout << "\n\n>>>>>>> " << i+1 << " <<<<<<<<\n";

            // Muestra el juego que se jugo en la partida
            if (partida->juego == 1){
                std::cout << "\nJugo blackjack";
            }
            else if (partida->juego == 2){
                std::cout << "\nJugo ruleta";
            }

            // Muestra la cantidad de dinero que perdió / ganó  en la partida
            if (partida->ganancia > 0){
                std::cout << "\nEsta partida gano " << partida->ganancia;
            }
            else if (partida->ganancia < 0){
                std::cout << "\nEsta partida perdio " << partida->ganancia * -1; // La multiplicación es para que el numero se muestre positivo (estetica)
            }
            else if (partida->ganancia == 0){
                std::cout << "\nEsta partida empató, no gano ni perdio dinero.";
            }
            i++;
        }
            
        }while (val);

}


