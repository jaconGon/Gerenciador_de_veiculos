/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila.h
 * Author: 2022.1.08.040
 *
 * Created on 8 de Novembro de 2022, 10:55
 */

#ifndef FILA_H
#define FILA_H

#include "lista.h"

typedef tLista tFila;

inline tFila* inicia_fila(){
    return inicia_lista();
};

inline tFila * encerra_fila(tFila * p){
    return encerra_lista(p);
};

inline void in_BD(tFila * p){
    inicia_BD(p);
};

inline void queue(tFila * p){
    insere_inicio(p);
};

inline no * unqueue(tFila * p){
    return remove_fim(p);
};

inline void  print_fila(tFila * p){
   imprime(p);
};

inline void  filainsere(no * topo, tFila* baixo){
  insere_man(topo,baixo);  
};



#endif /* FILA_H */

