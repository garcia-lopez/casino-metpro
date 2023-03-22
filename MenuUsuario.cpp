#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "datos.h"


int menuUsuario(char user_fin[20])
{
    int a =0;
    struct usuarios user;
    FILE *val;
    int opc=0;
    char usuario[20], contra [20], usuariotemp2 [20]; 

    do
    {
        printf(" __________________________________________________________\n");
        printf("|----------------BIENVENIDO A MUNDO SLOT-------------------| \n");
        printf("|==========================================================|\n");
        printf("|              DIGITE LA OPCION QUE DESEA                  |\n");
        printf("| <1> . ===============  ACCEDER  =========================|\n");
        printf("| <2> . =============== REGISTRAR =========================|\n");
        printf("|__________________________________________________________|\n >>> ");
        scanf("%d", &opc);
        
    
        switch(opc)
        {
        case 1: 
        // busca que el usuario y contraseña ingresados esten en el archivo de validacion, sale del menu si se logra iniciar sesion
            {
            val=fopen("validacion.txt","rb"); 
            if (val==NULL) 
            {
                printf("No existe el archivo en su computadora\n");
            }

            else 
            {
                printf(" _________________________________\n"); 
                printf("|DIGITE SU NOMBRE DE USUARIO : ");
                std::cin>>(usuario);
                printf("\n");
                printf(" _________________________________\n");
                printf("|DIGITE SU CONTRASENA: ");
                std::cin>>(contra);
                printf("\n");
               
                system("cls");
                while (!feof(val))
                {
                    fread(&user,sizeof(struct usuarios),1,val); 
                    if (((strcmp(usuario, user.usuario))==0)&&((strcmp(contra, user.contrasena))==0))
                    {
                        memmove(usuariotemp2, usuario, 20); // copia el nombre del usuario en una variable temporal
                        strupr(usuariotemp2); // convierte la variable en mayusculas
                        strcpy(user_fin, user.usuario);

                        system("cls");
                        printf("|========= BIENVENIDO %s =========| \n", usuariotemp2); 

                        a = 1; // variable que confirma que se inicio sesión correctamente
                        break;
                    }
                }
                if ((((strcmp (usuario, user.usuario )) !=0) || ((strcmp(contra, user.contrasena)) != 0 )) && (opc!=0)) 
                {
                    printf("CONTRASENA O USUARIO INGRESADOS SON INCORRECTOS\n");
                }

                fclose(val); 
            }
            break;

            }
        case 2:
        // guarda un nuevo usuario en el registro
            {
            val=fopen("validacion.txt","a+b"); 
            printf(" _______________________________\n"); 
            printf("|DIGITE SU NOMBRE DE USUARIO : ");
            std::cin>>(usuario);
            printf(" _______________________________\n");
            printf("|DIGITE SU CONTRASENA\n");
            std::cin>>contra;
            
           
            rewind(val); 
            while (fread(&user,sizeof(struct usuarios),1,val))
            {
                if ((strcmp(usuario, user.usuario))==0) 
                {
                    opc=1; 
                }
            }
            if (opc==1)
            {
                    printf("NOMBRE DE USUARIO YA SE ENCUENTRA EN USO\n");     
            }
            else 
            {
                strcpy (user.usuario,usuario);
                strcpy (user.contrasena, contra);
                fwrite(&user,sizeof(struct usuarios),1,val);
                printf("USUARIO REGISTRADO CON EXITO\n");
                system("cls");
            }
            fclose(val); 
            break;

            }

        default:
            {
            printf("LA OPCION QUE MARCO NO ES VALIDA \n");
            }

        }

    }while(a != 1); // Solo puede salir hasta que el usuario logre iniciar sesion (requisito para el historial)
    return a;
}

