#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>


int N_G()
// genera el numero ganador
{
   int numero_ganador;
   srand(time(NULL));
   numero_ganador = rand ()%37;
   return numero_ganador;
}
int C_G()
// genera el color ganador
{
   int color_ganador;
   srand(time(NULL));
   color_ganador= rand ()%2;
   return color_ganador;
}
void gano()
// el mensaje a imprimir si el usuario gano
{
  std::cout<<"\n<< Ha ganado la apuesta :D >>\n";
}


void perdio()
// el mensaje a imprimir si el usuario perdio
{ 
  std::cout<<"\n<< Ha perdido la apuesta :( >>\n";
}


//Tipos de apuestas Funciones:
int pleno()
{
   int usu_pleno;
   int ganadornum = N_G();
   std::cout << "\nQue numero en el intervalo 0-36 cree sera el ganador?\n";
         std::cout <<">>";
         std::cin >> usu_pleno;
         if(usu_pleno > 36)
         {
            std::cout<<"\nNo puede apostar por numeros mayores a 36";
            exit(EXIT_SUCCESS);
         }
   if (usu_pleno == ganadornum)
   {  
      gano();
      std:: cout <<"\nEl numero ganador fue >>\n";
      std:: cout << ganadornum;
      return 1;
   }
   else 
   {  
      perdio();
      std::cout <<"\nEl numero ganador fue \n";
      std:: cout << ganadornum;
      return -1;
   }
   return 0;
}


   int par_impar()
   {
   int case2;
   int ganadornum = N_G();
   std::cout << "\n (1)Par   (2)Impar\n";
   std::cout <<">>";
   std::cin >> case2;
   switch (case2)
   { 
      case 1:
      {  
         std::cout <<"\n**Apuesta por los pares**";
         if (ganadornum % 2 == 0)
         {  
            gano();
            std::cout <<"\nEl numero ganador fue: \n";
            std::cout<< ganadornum;
            return 1;
         }
         else
         { 
            perdio();
            std::cout <<"El numero ganador fue ";
            std:: cout<< ganadornum;
           return -1;
         }
      }
      break;

      case 2:
      {  
         std::cout <<"\n**Apuesta por los impares**";
         
         if (ganadornum % 2  != 0)
         {  
            gano();
            std:: cout << ganadornum;
            return 1;
         }
         else
         {
            perdio();
            std:: cout << "\nEl numero ganador fue\n";
            std:: cout << ">>" << ganadornum;
            return -1;
         }
      }
      break;
   }
   return 0;
}


int docena()
{
   int case3;
   int ganadornum = N_G();
   std::cout << "\n(1) Docena-1  (2) Docena-2    (3) Docena-3 \n";
   std::cout <<">>";
   std::cin >> case3;
   switch(case3)
   {
      case 1:
      {  
         std::cout << "\n**Apuesta por Docena 1**\n";
         int aux = -1;
         int docena1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
          for (int i=0; i <= 12; i++){
             if (docena1[i] == ganadornum){ 
               gano();
               std::cout << "\nEl numero ganador fue\n";
               std::cout << ganadornum;
               aux = 1;
               return 1;
            }
          }
          if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< ganadornum;
             return -1;
           } 
      }
      case 2: 
      {
         std::cout << "\n**Apuesta por Docena 2**\n";
         int aux = -1;
         int docena2[12] = {13,14,15,16,17,18,19,20,21,22,23,24};
         for (int i= 0; i < 12; i++)
         {
            if (docena2[i] == ganadornum)
               {  
                  gano();
                  std::cout<< ganadornum;
                  aux = 1;
                  return 1;
               }
         }
         if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< ganadornum;
             return -1;
           } 
         break;
      }
      case 3: 
      {
         std::cout << "\n**Apuesta por Docena 3**\n";
         int aux = -1;
         int docena3[12] = {25,26,27,28,29,30,31,32,33,34,35,36};
         for (int i= 0; i < 12; i++)        
         {
            if (docena3[i] == ganadornum)
            {   
               gano();
               std::cout<< ganadornum;
               aux = 1;
               return 1;
            }
         } 
         if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< ganadornum;
             return -1;
           }   
         break;
      }
   }
   return 0;
}

int columna()
{
   int case4;
   int aux;
   int numero_ganador = N_G();
   std::cout << " \n(1) Columna 1  (2) Columna 2    (3) Columna 3\n";
   std::cout <<">>";
   std::cin >> case4;
   switch (case4)
   {
      case 1:
      {
         std::cout << "\n<<Apuesta por Columna 1>>\n";
         int columna1[12] = {1,4,7,10,13,16,19,22,25,28,31,34};
         aux = -1;
         for (int i = 0; i<12; i++)
         {
            if (columna1[i] == numero_ganador)
            {  
               gano();
               std::cout<<"\nEl numero ganador fue\n";
               std::cout<< numero_ganador;
               aux = 1;
               return 1;
            }
         }
         if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< numero_ganador;
             return -1;
           } 
         break;
      }
      case 2:
      {
         std::cout << "\n<<Apuesta por Columna 2>>\n";
         int columna2[12]={2,5,8,11,14,17,20,23,26,29,32,35};
         aux = -1;
         for (int i = 0; i < 12; i++)
         {
            if (columna2[i] == numero_ganador)
            {
               aux = 1;
               gano();
               std::cout << "\nEl numero ganador fue\n";
               std::cout<< numero_ganador;
               return 1;
            }
         }
         if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< numero_ganador;
             return -1;
           } 
         break;
      }
      case 3: 
      {
         std::cout << "\n<<Apuesta por Columna 3>>\n";
         int columna3[12]={3,6,9,12,15,18,21,24,27,30,33,36}; 
         aux = -1;              
         for(int i = 0; i < 12; i++)
         {
            if (columna3[i] == numero_ganador)
            {
               gano();
               std::cout<<"\nEl numero ganador fue\n";
               std::cout<< numero_ganador;
               aux = 1;
               return 1;
            }
         }
         if (aux == -1)
           {
             perdio();
             std::cout << "\nNumero ganador "<< numero_ganador;
             return -1;
           }  
         break;
      }
   }
   
   return 0;
}

int docena_media()
{
   int case5;
   int numero_ganador = N_G();
   std::cout << "\n (1)1-18   (2)19-36.\n";
   std::cout <<">>";
   std::cin>>case5;
   switch (case5)
   { 
      case 1: 
      {
         std::cout<< "<<Usted aposto por los numeros del 1 al 18>>\n";
         int C1_18 [18]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};  
         int aux = -1;        
         for (int i = 0; i < 12; i++)
         {
            if (C1_18[i] == numero_ganador)
            {  
               aux = 1;
               gano();
               std::cout<<"El numero ganador fue\n";
               std::cout<< numero_ganador;
               return 1;
            }
         }

         if (aux == -1){
            perdio();
             std::cout<<"El numero ganador fue\n";
             std::cout<< numero_ganador;
             return -1;
         }
         break;
      }
      case  2:
      {
         std::cout<< "\n<<Usted aposto por los numeros del 19 al 36>>\n";
         int C19_36 [18] = {19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
         int aux = -1;               
          for (int i = 0; i < 18; i++)
         {
            if (C19_36[i] == numero_ganador)
            {  
               aux = 1;
               gano(); 
               std::cout<<"\nEl numero ganador fue\n";
               std::cout<< numero_ganador;
               return 1;  
            }
         }
         if (aux == -1){
            perdio();
            std::cout<<"\nEl numero ganador fue\n";
            std::cout<< numero_ganador;
            return -1;
         }
         break;
      }         
   }
   return 0;
}

int c0a3 ()
{
   std::cout<<"\n<*Usted aposto que el numero se encuentra entre el 0 y el 3*>\n";
   int numero_ganador = N_G();
   int aux = -1;
   int D0_3[4] {0,1,2,3};
   for (int i = 0; i < 4; i++)
   {
      if (D0_3[i] == numero_ganador)
      {   
         aux = 1;
         gano(); 
         std::cout<<"\nEl numero ganador fue\n";
         std::cout<< numero_ganador;
         return 1;
      }
   }
   if (aux == -1){
      perdio();
      std::cout<<"\nEl numero ganador fue\n";
      std::cout<< numero_ganador;
      return -1;
   }
   return 0;
}

int color()
{ std::cout<<"\n***Usted ha decidido apostar por colores***\n";
   int usu_color;
   int color_ganador = C_G();
   std::cout<<"(1)Rojo   (0)Negro\n";
   std::cout <<">>";
   std::cin>>usu_color;
   if(usu_color == color_ganador)
   {
      gano();
      if(color_ganador == 1)
      {
         std::cout << "\n<<El color ganador es rojo>>\n";
      }
      else{
         std::cout << "\n<<El color ganador es negro>>\n";
      }
      return 1;
   }
   else
   {
     perdio();
      if(color_ganador == 1)
      {
         std::cout << "\n<<El color ganador es rojo>>\n";
      }
      else{
         std::cout << "\n<<El color ganador es negro>>\n";
      }
      
      return -1;
   }
 return 0;
}

void tabla()
{
   system("cls");
   //Tabla de la ruleta//
   std::cout <<"\n<><><><>Bienvenido a la Ruleta de Casino Mundo Slot<><><><>\n";
   std:: cout <<"\n<><><>Tabla de la Ruleta<><><>\n";
   std::cout<<"\n   |0| ";
   std::cout<<"\n  -----";
   std::cout<<"\n |1|2|3|   --      --";
   std::cout<<"\n |4|5|6|   |1ra    |";
   std::cout<<"\n |7|8|9|   |Docena |1";
   std::cout<<"\n|10|11|12| --      |al 18";
   std::cout<<"\n|13|14|15| --      |";
   std::cout<<"\n|16|17|18| |2da    --";
   std::cout<<"\n|19|20|21| |Docena --";
   std::cout<<"\n|22|23|24| --      |";
   std::cout<<"\n|25|26|27| --      |19";
   std::cout<<"\n|28|29|30| |3ra    |al 36";
   std::cout<<"\n|31|32|33| |Docena |";
   std::cout<<"\n|34|35|36| --      --";
   std::cout<<"\n 1r 2d 3r";
   std::cout<<"\n Columnas";
   std::cout<<"\nRojo/Negro\n";
}

int menu_ruleta()
{ 
    int opcion;
    printf("\n------------------\n");
    printf("\n<><>Elija el tipo de apuesta<><>\n\n(1)Pleno\n(2)Par/Impar\n(3)Docena\n(4)Columna\n(5)1-18/19_36\n(6)0-3\n(7)Color\n");
    printf("\n------------------\n");
    std::cout << ">>";
    std::cin >> opcion;

    return opcion;
    system("cls");

}

int ruleta()
{
    int ruleta;
    int opc;
    opc = menu_ruleta();
    system("cls"); 
    tabla();
   
   switch(opc)
   {
    case 1://Pleno   
        ruleta = pleno();
        break;

    case 2://Par/Impar   
        ruleta = par_impar();
        break;

    case 3://Docena
        ruleta = docena(); 
        break;
   
    case 4:
        //columna
        ruleta = columna();
        break;
         
    case 5:
        ruleta = docena_media();
        break;

    case 6://0 a 3
        ruleta = c0a3(); 
        break;
      
    case 7://Colores
        ruleta = color();
        break;

    default: 
        system("cls");
        std::cout << "\nEl numero que ingreso no es correcto.";
        opc = menu_ruleta();
        break;     
   }
   return ruleta; 
}