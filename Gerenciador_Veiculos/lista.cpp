/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista *inicia_lista() {
  tLista *tmp = new (tLista);
  tmp->tam = 0;
  tmp->lista = NULL;
  return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista *encerra_lista(tLista *ptlista) {
  no *ant = ptlista->lista;
  no *pont = ptlista->lista;

  while (ant != NULL) {
    pont = ant->prox;
    delete(ant->car);
    delete (ant);
    ant = pont;
  }
  delete (ptlista);

  return NULL;
}

/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista *ptlista){
    no *p = new (no);
    p->car = new(carro);
    cout << "\nInforme:\nModelo: ";
    cin >> p->car->modelo;
    cout << "\nMarca: ";
    cin >> p->car->marca;
    cout << "\nTipo: ";
    cin >> p->car->tipo;
    cout << "\nAno: ";
    cin >> p->car->ano;
    cout << "\nKm: ";
    cin >> p->car->km;
    cout << "\nPotência: ";
    cin >> p->car->potencia;
    cout << "\nCombustível: ";
    cin >> p->car->combustivel;
    cout << "\nCâmbio: ";
    cin >> p->car->cambio;
    cout << "\nDireção: ";
    cin >> p->car->direcao;
    cout << "\nCor: ";
    cin >> p->car->cor;
    cout << "\nPortas: ";
    cin >> p->car->portas;
    cout << "\nPlaca: ";
    cin >> p->car->placa;
    cout << "\nValor: ";
    cin >> p->car->valor;
    p->prox = ptlista->lista;
    ptlista->lista = p;
    ptlista->tam++;
    cout << "inserção bem sucedida" << endl;
}

void insere_man(no * topo, tLista* baixo)
{
    no *p = new (no);
    p->car = new(carro);
    p->car->modelo = topo->car->modelo;
    p->car->marca = topo->car->marca;
    p->car->tipo = topo->car->tipo;
    p->car->ano = topo->car->ano;
    p->car->km = topo->car->km;
    p->car->potencia = topo->car->potencia;
    p->car->combustivel = topo->car->combustivel;
    p->car->cambio = topo->car->cambio;
    p->car->direcao = topo->car->direcao;
    p->car->cor = topo->car->cor;
    p->car->portas = topo->car->portas;
    p->car->placa = topo->car->placa;
    p->car->valor = topo->car->valor;
    p->prox = baixo->lista;
    baixo->lista = p;
    baixo->tam++;
    cout << "\n\ninserção bem sucedida" << endl;
}

void inicia_BD(tLista *ptlista) {
  ifstream myfile ("BD_veiculos_2.txt");
  if(myfile.is_open()){
    while( !myfile.eof()){
        no * ant;
        no *atual = new(no);
        atual->car = new(carro);
        myfile >> atual->car->modelo;
        myfile >> atual->car->marca;
        myfile >> atual->car->tipo;
        myfile >> atual->car->ano;
        myfile >> atual->car->km;
        myfile >> atual->car->potencia;
        myfile >> atual->car->combustivel;
        myfile >> atual->car->cambio;
        myfile >> atual->car->direcao;
        myfile >> atual->car->cor;
        myfile >> atual->car->portas;
        myfile >> atual->car->placa;
        myfile >> atual->car->valor;
        if(ptlista->tam == 0){
            ptlista->lista=atual;
            ant = atual;
            ptlista->tam++;
        }else{
            ant->prox = atual;
            ant = ant->prox;
            ptlista->tam++;
        }    
    }
    myfile.close();
    ptlista->tam--;
    }else{
      cout << "Erro ao abrir arquivo";
    }
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista *ptlista) {
  if (ptlista->tam == 0) {
    insere_inicio(ptlista);
  }

  no *ptr = ptlista->lista;

  for (int i = 1; i < ptlista->tam ; i++) {
    ptr = ptr->prox;
  }
  no *p = new (no);
  p->car = new (carro);
  ptr->prox = p;
  cout << "\nInforme:\nModelo: ";
  cin >> p->car->modelo;
  cout << "\nMarca: ";
  cin >> p->car->marca;
  cout << "\nTipo: ";
  cin >> p->car->tipo;
  cout << "\nAno: ";
  cin >> p->car->ano;
  cout << "\nKm: ";
  cin >> p->car->km;
  cout << "\nPotência: ";
  cin >> p->car->potencia;
  cout << "\nCombustível: ";
  cin >> p->car->combustivel;
  cout << "\nCâmbio: ";
  cin >> p->car->cambio;
  cout << "\nDireção: ";
  cin >> p->car->direcao;
  cout << "\nCor: ";
  cin >> p->car->cor;
  cout << "\nPortas: ";
  cin >> p->car->portas;
  cout << "\nPlaca: ";
  cin >> p->car->placa;
  cout << "\nValor: ";
  cin >> p->car->valor;
  p->prox = NULL;
  ptlista->tam++;
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no *remove_inicio(tLista *ptlista) {
  if (ptlista->tam == 0) {
    return NULL;
  }
  no *ptr = ptlista->lista;
  if (ptlista->tam == 1) {
    ptlista->lista = NULL;
    ptlista->tam--;
    return ptr;
  }
  ptlista->lista = ptr->prox;
  ptlista->tam--;
  return ptr;
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no *remove_fim(tLista *ptlista) {
  no *ant = ptlista->lista;
  if (ptlista->tam == 0) {
    return ant;
  }
  if (ptlista->tam == 1) {
    return remove_inicio(ptlista);
  }

  for (int i = 2; i <= ptlista->tam - 1; i++) {
    ant = ant->prox;
  }
  no * ptr = ant->prox;
  ant->prox = NULL;
  ptlista->tam--;
  return ptr;
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista *ptlista) {
  if (ptlista->tam == 0) {
    printf("Lista vazia!\n");
  } else {
    no *pont = ptlista->lista;
    for (int i = 0; i < ptlista->tam; i++) {
        cout << pont->car->modelo << " ";
        cout << pont->car->marca << " ";
        cout << pont->car->tipo << " ";
        cout << pont->car->ano << " ";
        cout << pont->car->km<< " ";
        cout << pont->car->potencia << " ";
        cout << pont->car->combustivel << " ";
        cout << pont->car->cambio << " ";
        cout << pont->car->direcao << " ";
        cout << pont->car->cor << " ";
        cout << pont->car->portas << " ";
        cout << pont->car->placa << " ";
        cout << pont->car->valor << " " << endl;
        pont = pont->prox;
    }
  }
}
