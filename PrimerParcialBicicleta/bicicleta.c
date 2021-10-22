#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "bicicleta.h"
int initBicicletas(eBicicleta listt[], int tam)
{
    int todoOK=0;
    for(int i =0; i <tam ; i++)
    {
        listt[i].isEmpty=1;
        todoOK=1;
    }
    return todoOK;
}

int altaBici(eBicicleta bikes[],int  tam, eColor colors[] ,int tamc ,eTipo types[] , int tamt, int* pIdNuevaBici)
{
    int todoOk=0;
    int i;
    eBicicleta nuevaBici;
    int idTipo;
    int idColor;

    system("cls");
    printf("Alta Bicicleta\n");
    printf("id  %d \n", *pIdNuevaBici);

    if(bikes != NULL && tam >0 && pIdNuevaBici != NULL)
    {
        i= buscarLibre(bikes, tam);
        printf("%d", i);
        if(i == -1)
        {
            printf("NO hay lugar en el sistema");
        }
        else
        {


            printf("ingrese marca: ");
            fflush(stdin);
            gets(nuevaBici.marca);

            mostrarColores(colors, tamc);
            printf("ingrese id Color: ");
            scanf("%d", &idColor);
            while(idColor < 5000 || idColor > 5004)
            {
                printf("Error, ingrese id color valido: ");
                scanf("%d", &idColor);
            }

            mostrarTipos(types, tamt );
            printf("ingrese ID tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
            while(idTipo< 1000 || idTipo > 1003)
            {
                printf("Error, ingrese ID tipo valido: ");
                fflush(stdin);
                scanf("%d", &idTipo);

            }

            printf("ingrese material (c O a): ");
            fflush(stdin);
            scanf("%c", &nuevaBici.material);
            while(nuevaBici.material != 'c' && nuevaBici.material != 'a')
            {
                printf("Error, ingrese material valido (c O a): ");
                fflush(stdin);
                scanf("%c", &nuevaBici.material);
            }



            nuevaBici.idTipo = idTipo;
            nuevaBici.idColor = idColor;
            nuevaBici.id= *pIdNuevaBici;
            (*pIdNuevaBici)++;
            nuevaBici.isEmpty=0;

            bikes[i] = nuevaBici;
            todoOk=1;
        }


}
return todoOk;
}

int buscarLibre(eBicicleta lista[],int tam)
{
     int LLibre=-1;
    for(int i =0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            LLibre=i;
            break;
        }
    }
return LLibre;
}

void mostrarBicis(eBicicleta lista[], int tam, eColor colors[], int tamc, eTipo tipos[], int tamt)
{
    int flag=1;
    printf("----------***  LISTA DE BICICLETAS  ***------------ \n");
    printf("id       marca        tipo         color           material (c -> carbono   a -> aluminio)\n");
    printf("-------------------------------------------------------------------------------------\n");
    for(int i =0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarBici(lista[i],colors , tamc, tipos, tamt);
            flag=0;
        }

    }

    if(flag)
    {
        printf("\n");
        printf("\n");
        printf("--------No hay bicicletas para mostar------ \n");
    }

    printf("\n");
    printf("\n");

}




void mostrarBici(eBicicleta unaBici,eColor colors[], int ttamc, eTipo ttipos[], int ttamt)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char nombre[20];
    //cargarNombre(unaNoteookk.idCliente, clients, tamc, nombre);
    cargarDescripcionColor(unaBici.idColor, colors, ttamc, descripcionColor);
    cargarDescripcionTipo(unaBici.idTipo, ttipos, ttamt, descripcionTipo);
    printf("%d      %-10s     %-10s   %-10s     %c",
            unaBici.id , unaBici.marca , descripcionTipo,
            descripcionColor, unaBici.material);
    printf("\n");





}

int modificarBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt)
{
    int todoOK=0;
    if(lista != NULL && tam > 0 && colorss != NULL && tamc > 0 && tipos != NULL && tamt > 0 )
    {
         int idAModificar;

         mostrarBicis(lista,tam,colorss,tamc,tipos,tamt);
         printf("ingrese el numero de id de la bici a modificar \n");
         scanf("%d", &idAModificar);

         while(!validarIDBici(idAModificar,lista, tam))
            {
                printf("ingrese id bici valido: ");
                fflush(stdin);
                scanf("%d", &idAModificar);

            }


        for(int i =0; i<tam; i++)
        {


            if(lista[i].id == idAModificar)
            {
                int AM = i;
                char salir = 'n';
                    do{

                        switch(submenu())
                        {
                            case 1:
                                mostrarTipos(tipos, tamt);
                                printf("reingrese id tipo");
                                scanf("%d", &lista[AM].idTipo);
                                while(lista[AM].idTipo > 1003 || lista[AM].idTipo < 1000)
                                {
                                    printf("Tipo invalido reingrese id tipo");
                                    scanf("%d", &lista[AM].idTipo);

                                }
                            break;
                            case 2:
                                printf("ingrese material (c O a): ");
                                fflush(stdin);
                                scanf("%c", &lista[AM].material);
                                while(lista[AM].material != 'c' && lista[AM].material != 'a')
                                {
                                    printf("ingrese material (c O a): ");
                                    fflush(stdin);
                                    scanf("%c", &lista[AM].material);
                                }
                            break;
                            case 3:
                                printf("Desea salir/ dejar de modificar ingrese 's' de asi serlo : ");
                                fflush(stdin);
                                scanf("%c", &salir);
                            break;
                            default:
                                printf("ingrese opcion valida");
                            break;
                        }



                    }while(salir!= 's');
                todoOK =1;
            }

        }
    }

    return todoOK;
}

int bajaBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt)
{
    int idABorrar;
    int todoOk=0;
    mostrarBicis(lista, tam, colorss, tamc, tipos, tamt);
    printf("ingrese el numero de id de la bici a eliminar \n");
    scanf("%d", &idABorrar);
    while(!validarIDBici(idABorrar, lista, tam))
    {
        printf("Reingrese el numero de id de la bici a eliminar \n");
        scanf("%d", &idABorrar);

    }

    for(int i =0; i<tam; i++)
    {


        if(lista[i].id == idABorrar)
        {
            lista[i].isEmpty=1;
            todoOk=1;
            mostrarBici(lista[i],colorss, tamc, tipos, tamt);

        }

    }

    return todoOk;
}

int cargarMarcaBici(int id, eBicicleta lista[], int tam, char marca[])
{
    int todoOk=0;

    for(int i =0; i < tam ; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(marca, lista[i].marca);
            todoOk=1;
            break;
        }
    }


    return todoOk;
}
