
#include "MPC5606B.h"

#include "Timer.h"
#include "IntcInterrupts.h"
#include "stdtypedef.h"
#include "Leds.h"
#include "INIT.h"

typedef void(*FuncPtr)(void);
extern tickflag;

void task1(void);
void task2(void);
void task3(void);
void task4(void);
void scheduler(void);


typedef enum {
	
	E_ISK_TASK0,
	//E_ISK_TASK1,
	//E_ISK_TASK2,
	//E_ISK_TASK3,
	
	/*DONT MODIFY THIS LINE*/	
	E_ISK_TASK_NUM
} tareas;


typedef struct{
	
	FuncPtr puntero;//puntero a la funcion de la tarea
	int periodo;//periodo
	int offset;//offset
	
} S_TASKS;

const S_TASKS TASK_LIST[E_ISK_TASK_NUM]={
		{task1, 200, 1},
		//{task2, 400, 3},
		//{task3, 800, 5},
		//{task4, 1600, 17}
				
};


void task1(void)
{
	
	SIU.GPDO[LED_1].B.PDO ^= 1;//led1 on  si esta apagado que lo prenda y viceversa
	SIU.GPDO[0].B.PDO =1;
	
}

void task2(void)
{
	SIU.GPDO[69].B.PDO ^= 1;//led2 on  si esta apagado que lo prenda y viceversa
}


void task3(void)
{
	SIU.GPDO[70].B.PDO ^= 1;//led3 on  si esta apagado que lo prenda y viceversa
}

void task4(void)
{
	SIU.GPDO[71].B.PDO ^= 1;//led4 on  si esta apagado que lo prenda y viceversa
}



void scheduler(void){

char indice;
int contador_de_tareas[E_ISK_TASK_NUM];

for (indice=0; indice<E_ISK_TASK_NUM; indice++)	{
	contador_de_tareas [indice]=TASK_LIST[indice].offset;
}
	while (1){
	 if (tickflag){ // si bandera del tick de 1 ms es 1 
		 
		 tickflag=0;  // resetear bandera del lick
		 
		 for(indice=0; indice<E_ISK_TASK_NUM; indice++){
			 if (contador_de_tareas[indice]>0){
				
				 contador_de_tareas[indice] -= 1; 
			 }
			 else{
				 
				 contador_de_tareas[indice]=TASK_LIST[indice].periodo;
				 TASK_LIST[indice].puntero();
			}
		   }
		  }
	 else
	 {
		 //nada
	 }
		 }
		}

int main(void) {
	INIT();  //initialises the system modes (reloj interno, modos de ejecucion)
	init_leds ();
	STM_config_clock();
	INTC.CPR.B.PRI = 0;
	INTC_InstallINTCInterruptHandler(function_time,30,1);
	scheduler();
}



