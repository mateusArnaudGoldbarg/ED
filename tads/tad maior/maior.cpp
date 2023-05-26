#include <iostream>
#include "maior.hpp"

/*
Title: maior.cpp
Description: maior cpp file
Author: Mateus Arnaud Goldbarg
Date: 24/04/2023
*/

Maior::Maior()
{
    std::cout << "Construindo objeto Padrao\n";
    listaInteiros[CAPACIDADE] = {};
}

Maior::~Maior()
{
    std::cout << "Destruindo objeto " << "\n";
}

void Maior::insere(int valor){
	if (tamanho < CAPACIDADE){
		listaInteiros[tamanho] = valor;
		tamanho++;
	}
}

int Maior::buscaMaior(){
	if (tamanho == 0){
		throw std::logic_error("A lista está vazia enquanto buscava pelo maior número");
	}

	int maiorValor = listaInteiros[0];
	for (int i = 0; i < tamanho; i++){
		maiorValor = std::max(maiorValor, listaInteiros[i]);
	}
	return maiorValor;
}

void Maior::imprime(){
	for(int i=0;i<tamanho;i++){
		std::cout<<listaInteiros[i]<<" ";
	}
	std::cout<<std::endl;
}
