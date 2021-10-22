#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "bicicleta.h"
#include "color.h"
#include "menu.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "validaciones.h"
#define TAM 100
#define TAMT 4
#define TAMS 4
#define TAMC 5
#define TAMTRAB 100

int main()
{

    eTipo tipos[TAMT]= { {1000, "Rutera"}, {1001, "Carrera"},{1002, "Mountain"},{1003, "BMX"}};

    eServicio servicios[TAMS]= { {20000, "Limpieza", 30}, {20001, "Parche", 400},{20002, "Centrado", 500},{20003, "Cadena", 450}};

    eColor colores[TAMC]={ {5000, "Gris"}, {5001, "Blanco"},{5002, "Azul"},{5003, "Negro"},{5004, "Rojo"}};

    eBicicleta bicis[TAM];
    int idBici = 100;
    initBicicletas(bicis,TAM);

    eTrabajo trabajos[TAMTRAB];
    int idTrabajo =1;
    initTrabajos(trabajos, TAMTRAB);

    char salir = 'n';

    do{
            switch(menu()){
            case 1:

                if(altaBici(bicis,TAM,colores,TAMC,tipos,TAMT,&idBici))
            {
                printf("1- Alta Bici Exitosa\n");

            }
            else
            {
                printf("1-Hubo un error,  Alta Bici fallida\n");

            }
                break;
            case 2:
                modificarBicicleta(bicis,TAM, colores, TAMC, tipos,TAMT);
                break;
            case 3:
                bajaBicicleta(bicis,TAM,colores,TAMC,tipos,TAMT);
                break;
            case 4:
                mostrarBicis(bicis, TAM, colores, TAMC, tipos, TAMT);
                break;
            case 5:
                mostrarTipos(tipos, TAMT);
                break;
            case 6:
                mostrarColores(colores, TAMC);
                break;
            case 7:
                mostrarServicios(servicios,TAMS);
                break;
            case 8:
                altaTrabajo(bicis,TAM,colores,TAMC,tipos,TAMT,trabajos,TAMTRAB,servicios,TAMS, &idTrabajo);
                break;
            case 9:
                mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMS,bicis,TAM);
                break;

            case 10:
                salir = 's';
                break;
            default:
                printf("ingrese una opcion valida \n");
                break;



            }


        system("pause");
    }while(salir=='n');






    return 0;
}
