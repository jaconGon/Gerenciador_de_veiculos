/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilha.h
 * Author: 2022.1.08.040
 *
 * Created on 8 de Novembro de 2022, 10:18
 */

#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

typedef tLista tPilha;

inline tPilha* inicia_pilha(){
    return inicia_lista();
};

inline tPilha * encerra_pilha(tPilha * p){
    return encerra_lista(p);
};

inline void push(tPilha * p){
    insere_inicio(p);
};

inline no * pop(tPilha * p){
    return remove_inicio(p);
};

inline void  print_pilha(tPilha * p){
   imprime(p);
};  

inline void  pilhainsere(no * topo, tPilha* baixo){
  insere_man(topo,baixo);  
};

#endif /* PILHA_H */

