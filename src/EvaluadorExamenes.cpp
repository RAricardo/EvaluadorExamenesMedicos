#pragma once
#include <pthread.h>
#include "Cola.h"
#include <string.h>

using namespace std;

class EvaluadorExamenes
{
    
  public:
  
  Cola blood;
  Cola detritus;
  Cola skin;

  EvaluadorExamenes(){}

  EvaluadorExamenes(){
      pthread_create("blood", NULL, procesar, (void *)blood); //pasar cola como argumento
      pthread_create("skin", NULL, procesar, (void *)skin); //pasar cola como argumento 
      pthread_create("detritus", NULL, procesar, (void *)detritus); //pasar cola como argumento
  }

  void procesar(void* colaArg){
      Cola cola;
      cola = (Cola)colaArg;
      
      //LOGICA DE PROCESAR . RANDOMS
  }

  void meterExamen(string tipo, string examen){

      if (strcmp("blood", tipo) == 0){

          blood.meter(examen);

      } else if((strcmp("skin", tipo) == 0){
          
          skin.meter(examen);

      }else if((strcmp("detritus", tipo) == 0){

          detritus.meter(examen);

      }
  }
};