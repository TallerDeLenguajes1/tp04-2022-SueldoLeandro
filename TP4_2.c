#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;


void BusquedaPorPalabra(Tarea ** ArregloDeTareas,int cantidadDeTareas);
void BusquedaPorId (Tarea** ArregloDeTareas,int cantidadDeTareas);

int main (){

srand(time(NULL));
int cantidadDeTareas=0;
char *buff;

buff=(char *) malloc(sizeof(char)*100);

printf("Cantidad de tareas a cargar :");
scanf("%d",&cantidadDeTareas);


Tarea **ArregloDeTareas,**TareasRealizadas;
ArregloDeTareas = (Tarea**)malloc (sizeof(Tarea*)*cantidadDeTareas);
TareasRealizadas = (Tarea**)malloc (sizeof(Tarea*)*cantidadDeTareas);

fflush(stdin);
for (int i = 0; i < cantidadDeTareas; i++)
{
    ArregloDeTareas[i] = (Tarea*)malloc (sizeof(Tarea));
    ArregloDeTareas[i]->TareaID = i ;
    

    printf("Descripcion de la tarea %d : ",i);
    gets(buff);
    ArregloDeTareas[i]->Descripcion = (char*)malloc(sizeof(char)*strlen(buff));
    strcpy(ArregloDeTareas[i]->Descripcion,buff);fflush(stdin);

    ArregloDeTareas[i]->Duracion = rand() % 11 + 80;
}

int contadorTRealizadas=0;
for (int i = 0; i < cantidadDeTareas; i++)
{   
    int estadoTarea = 0;
    printf("\nSe realizo la tarea %d ?? 1=Si -  2=NO : \n",i);
    scanf("%d",&estadoTarea);
    if (estadoTarea == 1)
    {
        TareasRealizadas[i] = ArregloDeTareas[i];
        ArregloDeTareas[i] = NULL;

        contadorTRealizadas++;
    }
    
 

}

fflush(stdin);

// MOSTRAR TAREAS
    printf("\n\nTAREAS REALIZADAS:\n");
    for (int i = 0; i < contadorTRealizadas; i++)
    {
        
        printf("\n\nTarea id : %d\n",TareasRealizadas[i]->TareaID = i);
     

        printf("Descripcion de la tarea : %s \n",TareasRealizadas[i]->Descripcion);
    
        printf("Duracion de la tarea : %d \n",TareasRealizadas[i]->Duracion);
    }

fflush(stdin);
printf("\n\nTAREAS PENDIENTES:\n");

     for (int i = 0; i < cantidadDeTareas; )
    {   
        
        if (ArregloDeTareas[i] == NULL)
        {
            i++;
           
        }else{

            printf("\n\nTarea id : %d\n",ArregloDeTareas[i]->TareaID = i);
     

            printf("Descripcion de la tarea : %s \n",ArregloDeTareas[i]->Descripcion);
        
            printf("Duracion de la tarea : %d \n",ArregloDeTareas[i]->Duracion);
            i++;
        }
    }
fflush(stdin);
// BUSQUEDA POR ID  Y POR PALABRA
    BusquedaPorId(ArregloDeTareas,cantidadDeTareas);
    BusquedaPorPalabra(ArregloDeTareas,cantidadDeTareas);

    
fflush(stdin);
getchar();


    return 0;
}



void BusquedaPorPalabra(Tarea ** ArregloDeTareas,int cantidadDeTareas){

    char *aux = (char*) malloc(sizeof(char)*100);

    int i= 0,id=0;
    printf("\ningrese la palabra clave de la tarea a buscar : ");
    gets(aux);
    while (i < cantidadDeTareas)
    {
        if (ArregloDeTareas[i] == NULL)
        {
            i++;
        }else{

            if (strstr(ArregloDeTareas[i]->Descripcion, aux) != NULL)
            {
                printf("\nTarea id es : %d \n",ArregloDeTareas[i]->TareaID);
                printf("La descripcion es : %s \n",ArregloDeTareas[i]->Descripcion);
                printf("La duracion de la tarea es : %d \n\n",ArregloDeTareas[i]->Duracion);
                return;
            }
            i++;
        }
        
        
    }
    printf("\nEsa palabra clave no corresponde a ninguna tarea.\n\n");
    free(aux);
    return;
}



void BusquedaPorId (Tarea** ArregloDeTareas,int cantidadDeTareas) {

    int i= 0,id=0;
    printf("\n\ningrese el ID de la tarea a buscar : ");
    scanf("%d",&id);
    while (i < cantidadDeTareas)
    {
        if (ArregloDeTareas[i] == NULL)
        {
            i++;
        }else{

            if (ArregloDeTareas[i]->TareaID == id)
            {
                printf("\nTarea id es : %d \n",ArregloDeTareas[i]->TareaID);
                printf("La descripcion es : %s \n",ArregloDeTareas[i]->Descripcion);
                printf("La duracion de la tarea es : %d \n\n",ArregloDeTareas[i]->Duracion);
                return;
            }
            i++;
        }
        
        
    }
    printf("\nEse id no corresponde a ninguna tarea.\n\n");
    return;
}