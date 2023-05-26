/*
Title: maior.hpp
Description: maior header file
Author: Mateus Arnaud Goldbarg
Date: 24/04/2023
*/

#ifndef MAIOR_HPP
#define MAIOR_HPP

const int CAPACIDADE = 100000;
class Maior{
	public:
		Maior();
		~Maior();
		void insere(int valor);
		int buscaMaior();
		void imprime();
		int size();
	private:
		int listaInteiros[CAPACIDADE];
		int tamanho;
};


#endif
