/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: paulo
 *
 * Created on January 26, 2021, 11:32 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>

using namespace std;

typedef struct{
    string modelo;
    string marca;
    string tipo;
    string ano;
    string km;
    string potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    float valor;
}carro;


typedef struct no_ {
	carro * car;  //'carga útil' do nó
                    //num cenario real, poderia ser: nome, endereco...
	struct no_ * prox;  // ponteiro para o próximo nó da lista encadeada
} no;

typedef struct {
	int tam;            //critério de busca da ordenação
	struct no_ * lista; // ponteiro para o próximo nó da lista encadeada
} tLista;

tLista* inicia_lista();
tLista * encerra_lista(tLista * ptlista);
void inicia_BD(tLista *ptlista);
void imprime(tLista * ptlista);
void insere_inicio(tLista * ptlista);
no * remove_inicio(tLista * ptlista);
void insere_fim(tLista * ptlista);
no * remove_fim(tLista * ptlista);
void insere_man(no * topo, tLista* baixo);


#endif /* LISTA_H */

