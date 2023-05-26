#include <iostream>
#include "maior.hpp"

using namespace std;

int main(){
	
	Maior maior = Maior();
	
	maior.insere(2);
	maior.insere(3);
	maior.insere(4);
	maior.imprime();
	int m = maior.buscaMaior();
	cout << m <<endl;
	return 0;
}
