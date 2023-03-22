#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

int ganancia; // devuelve un 1 si el usuario gano, -1 si el usuario perdio y 0 si hubo un empate

int es_blackjack(int usuario, int compu)
// Determina si la computadora o el usuario lograron un blackjack
{
    if (compu == 21){
        std::cout << "\nTu oponente tiene Blackjack, perdiste";
        ganancia = -1;
        return 1;
    }
    else if (usuario == 21){
        std::cout << "\n¡Tienes un blackjack!¡Ganaste!";
        ganancia = 1;
        return 1;
    }

    return 0;
}

int mas_cartas()
// devuelve una carta para ser agregada a la lista
{
    int cartas[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11};
    int RanIndex = rand() % 11;
    return cartas[RanIndex];
}

int sumar_cartas(int cartas[], int actual)
// suma las cartas de la lista que se le asigna y devuelve el total calculado
{
    int suma = 0;
    
    for (int i=0; i< actual; i++){
        suma = suma + cartas[i];
        
    }
    return suma;
}

int maximo(int usuario, int compu)
// determina si la computadora o el oponente superaron el maximo posible
{
    if (compu > 21)
    {
        std::cout << "\nTu oponente tiene se paso del limite, ¡Tu ganas!";
        ganancia = 1;
        return 1;
    }
    else if (usuario > 21)
    {
        std::cout << "\nTe pasaste del limite ¡Perdiste!";
        ganancia = -1;
        return 1;
    }
    return 0;
}
    
void comparar (int usuario, int compu )
// en caso de que ninguno haya superado el limite o superado el blackjack determina quien se acerco mas a 21
{
    if (usuario > compu){
        std::cout << "\n¡Tu ganas, felicidades!";
        ganancia = 1;
    }
    else if (compu > usuario){
        std::cout << "\nPerdiste esta ronda";
        ganancia = -1;
    }
    else if (compu == usuario){
        std::cout << "\n¡Es un empate!";
        ganancia = 0;
    }

}  


int blackjack (char usuario[20])
// funcion principal de blackjack
{
    srand(time(NULL));
    int act_usuario = 0, act_compu = 0;
    int usuario_cartas[13], compu_cartas[13];
    int compu_total, usuario_total;
    int busted = 0, blackjack = 0;
    char otra;

    std::cout << "\nTus cartas son: ";
    for (act_usuario; act_usuario<2; act_usuario++){
        usuario_cartas[act_usuario] = mas_cartas();
        std::cout << usuario_cartas[act_usuario] << " ";
    }
    
    for (act_compu; act_compu<2; act_compu++){
        compu_cartas[act_compu] = mas_cartas();
    }

    std::cout << "\nLa primera carta de la computadora es: " << compu_cartas[0];
    compu_total = sumar_cartas(compu_cartas, act_compu);
    usuario_total = sumar_cartas(usuario_cartas, act_usuario);
    std::cout << "\nSu total es:" << usuario_total << " ";

    blackjack = es_blackjack(usuario_total, compu_total);
    if (blackjack==1){
        return ganancia;
    }
    busted = maximo(usuario_total, compu_total);
    if (busted==1){
        return ganancia;
    }

    std::cout << "\nEscriba 's' si desea otra carta, pulse cualquier otra letra si no desea mas cartas ";
    std::cin >> otra;
    otra = tolower(otra);
    
    while (otra == 's' and busted == 0 and blackjack == 0)
    {
        usuario_cartas[act_usuario] = mas_cartas();
        act_usuario ++;
        usuario_total = sumar_cartas(usuario_cartas, act_usuario);
        std::cout << "\nSu total es:" << usuario_total << " ";

        usuario_total = sumar_cartas(usuario_cartas, act_usuario);
        busted = maximo(usuario_total, compu_total);
        blackjack = es_blackjack(usuario_total, compu_total);
        if (blackjack==1){
            return ganancia;
        }
        if (busted==1){
            return ganancia;
        }

        std::cout << "\nEscriba 's' si desea otra carta, pulse cualquier otra letra si no desea mas cartas ";
        std::cin >> otra;
        otra = tolower(otra);
        if (otra != 's'){
            break;
        }
        
    }
    
    
    while (compu_total <= 16 and blackjack == 0 and busted == 0) // una de las reglas de blackjack es que el dealer (computadora) esta obligado a sacar cartas hasta que su total equivalga a 16 o mas
    {
        compu_cartas[act_compu] = mas_cartas();
        act_compu ++;
        compu_total = sumar_cartas(compu_cartas, act_compu);

        busted = maximo(usuario_total, compu_total);
        blackjack = es_blackjack(usuario_total, compu_total);

    }
  
    if (blackjack == 0 and busted == 0){
        std::cout << "\nTu total es: " << usuario_total;
        std::cout << "\nEl total de tu oponente es: " << compu_total;
        comparar(usuario_total, compu_total);
    }

    return ganancia; 
}
