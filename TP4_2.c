#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;




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
    

    

getchar();


    return 0;
}
