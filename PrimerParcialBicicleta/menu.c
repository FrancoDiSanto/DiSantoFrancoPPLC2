#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int menu()
{
    int opcion;


    system("cls");
    printf("******menu de opciones********\n");
    printf("1- Alta Bicicleta\n");
    printf("2- Modificar Bicicleta\n");
    printf("3- Baja Bicicleta\n");
    printf("4- Listar Bicicleta\n");
    printf("5- Listar tipos\n\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios \n");
    printf("8- ALta trabajo \n");
    printf("9- Listar trabajo \n");

    printf("10- Salir \n");
    printf("ingrese su opcion : ");
    scanf("%d", &opcion );

    /*while(opcion < 1 || opcion > 10 )
    {
        opcion= 150;
    }*/

    return opcion;
}


int submenu()
{
    int opcion;


    system("cls");
    printf("******menu de opciones********\n");
    printf("1- Modificar tipo\n");
    printf("2- Modificar material\n");

    printf("3- Salir \n");
    printf("ingrese su opcion : ");
    scanf("%d", &opcion );

    return opcion;



}
