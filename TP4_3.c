#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;


struct Nodo{
struct Tarea T;
struct Nodo *Siguiente;
}typedef Nodo;


void cargarTarea(Nodo** ListaDeTareas,int cantidadDeTareas);
void cargarTarea(Nodo** cargarRealizada,int cantidadDeTareas);


int main (){

srand(time(NULL));
int cantidadDeTareas=0;

Nodo **cabecera;

cargarTarea(cabecera,2);

return 0;
}


void cargarTarea(Nodo** ListaDeTareas,int cantidadDeTareas){

    
    char * buff;
    buff=(char *) malloc(sizeof(char)*100);

    printf("Cantidad de tareas a cargar :");
    scanf("%d",&cantidadDeTareas);

    //Nodo **ListaDeTareas;
    ListaDeTareas = (Nodo**)malloc (sizeof(Nodo*)*cantidadDeTareas);
    

    for (int i = 0; i < cantidadDeTareas; i++)
    {
    struct Tarea *Tarea;
    Tarea = (struct Tarea*) malloc (sizeof(struct Tarea));
    
    ListaDeTareas[i]->T.TareaID = i;

    printf("Descripcion de la tarea %d : ",i);
    gets(buff);
    ListaDeTareas[i]->T.Descripcion = (char*)malloc(sizeof(char)*strlen(buff));
    strcpy(ListaDeTareas[i]->T.Descripcion,buff);    fflush(stdin);


    ListaDeTareas[i]->T.Duracion = rand() % 11 + 80;
    }

    free(buff);
    return;
}




void cargarRealizada(Nodo** TareasRealizadas,int cantidadDeTareas,Nodo** ListaDeTareas){

    int contadorTRealizadas=0;
    //Nodo **TareasRealizadas;
    TareasRealizadas = (Nodo**)malloc (sizeof(Nodo*)*cantidadDeTareas);

    for (int i = 0; i < cantidadDeTareas; i++)
    {   
        struct Tarea *tarea;
        tarea = (struct Tarea*)malloc (sizeof(struct Tarea));
    
        int estadoTarea = 0;
        printf("\nSe realizo la tarea %d ?? 1=Si -  2=NO : \n",i);
        scanf("%d",&estadoTarea);

        if (estadoTarea == 1)
        {   
            struct Nodo *aux=ListaDeTareas;
            TareasRealizadas[i] = aux;
            TareasRealizadas[i]->Siguiente = NULL;

            ListaDeTareas[i] = ListaDeTareas[i]->Siguiente;
            

            free(aux);
            


            contadorTRealizadas++;
        }
        
    

    }


    return;
}