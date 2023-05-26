/* 
 * File:   main.cpp
 * Author: 
 * Leonardo Jacon Gonçalves   RA:2022.1.08.040
 *
 * Created on January 26, 2021, 11:00 AM
 */

#include <iostream>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include "lista.h"

no * busca_lista(tLista *cabeca,string placa){
    no *pont = cabeca->lista;
    int retorno =-1;
    for(int i = 0;i < cabeca->tam;i++){
        if(pont->car->placa==placa){
           return pont; 
        }else
            pont = pont->prox;
    }
    return NULL;
}

void cria_fila(tLista * topo, tFila * baixo)
{
    no * aux;
    no * q;
    aux = topo->lista;
    for(int i = 0;i < topo->tam; i ++)
    {
        if(aux->car->cambio == "Automático" )
        {
            filainsere(aux,baixo);
            cout << "Carro inserido: " << aux->car->modelo << "\nPlaca: " << aux->car->placa <<endl;
        }
        else
        {
            q = unqueue(baixo);
            if(q != NULL)
                cout << "\n\nCarro removido: " << q ->car->modelo << "\nPlaca: " << q->car->placa;
            else
                cout << "\n\nFila vazia\n"; 
        }
        aux = aux->prox;
    }
    cout << "\n\nFila final: \n";
    print_pilha(baixo);
}

/**
 * 
 * @param topo lista principal de onde será comparado os carros 
 * @param baixo pilha onde acontecerá as remoções e inserções
 */
void cria_pilha(tLista * topo, tPilha * baixo)
{
    no * aux;
    no * q;
    aux = topo->lista;
    for(int i = 0;i < topo->tam; i ++)
    {
        if(aux->car->direcao == "Hidráulica" )
        {
            pilhainsere(aux,baixo);
            cout << "Carro inserido: " << aux->car->modelo << "\nPlaca: " << aux->car->placa <<endl;
        }
        else
        {
            q = pop(baixo);
            if(q != NULL)
                cout << "\n\nCarro removido: " << q ->car->modelo << "\nPlaca: " << q->car->placa;
            else
                cout << "\n\nPilha vazia\n"; 
        }
        aux = aux->prox;
    }
    cout << "\n\nPilha final: \n";
    print_pilha(baixo);
}

/**
 * 
 * @param cabeca  Lista principal, ou seja, um nó que aponta para a lista principal.
 * @param placa Placa a ser buscada.
 */
void exclui_no_lista(tLista *cabeca,string placa){
    no * atual = busca_lista(cabeca,placa);
    if(atual != NULL){
        char q;
        cout << "\nVeículo encontrado, deseja remover? \n(Digite 's' para remover ou 'n' para cancelar a operação)" << endl;
        cin >> q;
        if(q == 's' || q == 'S'){
            no * ant = cabeca->lista;
            while(ant->prox != atual){
                ant=ant->prox;
            }
            ant->prox=atual->prox;
            delete(atual->car);
            delete(atual);
            cabeca->tam--;
        }    
     
    }
       else
            cout << "Carro não encontrado\n";
}

/**
 * 
 * @param cima -> Lista principal
 * @param baixo -> Nova lista a ser criada
 */
void insere_ord(tLista * cima, tLista * baixo)
{
    no * ptr;
    no *ant;
    no * aux;
    no * aux2;
    aux = cima->lista;
    baixo->lista = new(no);
    baixo->tam++;
    baixo->lista->prox = NULL;
    baixo->lista->car = aux->car;
    ant = baixo->lista;
    ptr = ant->prox;
   
        for(int i = 0; i < cima->tam ; i++)
    {
      
      while(ptr != NULL && aux->car->placa > ptr->car->placa ) 
      {
        ant = ptr;
        ptr = ptr->prox;
      }
      aux2 = new(no);
      aux2->car = aux->car;
      aux2->prox = ptr;
      ant -> prox = aux2;
      aux = aux->prox;
      ant = baixo->lista;
      ptr = ant->prox;
      baixo->tam++;
    }
    ptr = baixo->lista;
    baixo->lista = baixo->lista->prox;
    baixo->tam--;
    delete(ptr);
}

using namespace std;

tFila * fila1;
tPilha * pilha1;
tLista * lista1;

int main() {
    string pla;
    tLista * lista2;
    lista2 = inicia_lista();
    lista1 = inicia_lista();
    pilha1 = inicia_pilha();
    fila1 = inicia_fila();
    inicia_BD(lista1);
    int c = -1;
    while(c!=0)
    { 
        cout << "\nBem vindo ao menu:\nSe deseja procurar um carro digite 1\nSe deseja inserir um carro, digite 2\nSe deseja que os carros apareçam na tela, digite 3\nSe deseja ordenar os veículos pela placa, digite 4\n";
        cout << "Caso deseje ordenar os veiculos em forma de pilha, inserindo quando a direção for hidraulica e removendo quando for mecanica digite 5\n";
        cout << "Caso deseje ordenar os veiculos em forma de fila, inserindo quando o câmbio for automatico e removendo quando for manual digite 6\n";
        cout << "Caso deseje sair do menu, digite 0\n";
        cin >> c;
        switch(c)
        {
            case 1:
                cout << "Informe a placa a ser buscada\n";
                cin >> pla;
                exclui_no_lista(lista1,pla);
            break;
            case 2:
                cout << "Você optou por inserir um carro!" << endl;
                insere_fim(lista1);
            break;
            case 3:
                cout << "Vocẽ optou por imprimir os carros na tela:\n";
                imprime(lista1);
            break; 
            case 4:
                cout<< "Você optou por ordenar os veículos:\n";
                insere_ord(lista1,lista2);
                imprime(lista2);
            break;
            case 5:
                cout<< "você optou por gerar a pilha: \n";
                cria_pilha(lista1,pilha1);
            break;
            case 6:
                cout<< "você optou por gerar a fila \n";
                cria_fila(lista1,fila1);
            break;
        }    
    }
    cout << "Operações finalizadas e estruturas desalocadas";
    encerra_lista(lista1);
    encerra_lista(lista2);
    encerra_pilha(pilha1);
    encerra_fila(fila1);
}
