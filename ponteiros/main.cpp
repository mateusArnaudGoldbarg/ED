#include <iostream>

int main() {
  int x = 10;
  int *p;  // Declaração de um ponteiro para um inteiro

  p = &x; // Atribuição do endereço de memória de 'x' ao ponteiro 'p'
/*
  std::cout << "Valor de x: " << x << std::endl;
  std::cout << "Endereço de x: " << &x << std::endl;
  std::cout << "Valor para qual o p aponta: " << *p << std::endl;
  std::cout << "Valor de p: " << p << std::endl;
  std::cout << "Endereço de p: " << &p << std::endl;
*/

  
  //Qual será a saída??
  //*p+=1;
  //std::cout<<*p<<std::endl;
  



/*
  int i=3,j=5;
  int *pp, *qq;
  
  pp = &i;
  qq = &j;
  std::cout<<(pp==&i)<<std::endl;
  std::cout<<*pp-*qq<<std::endl;
  std::cout<<**&pp<<std::endl;
  std::cout<<3-*pp/(*qq)+7<<std::endl;
  std::cout<< pp<< " " <<*pp+2 << " " << 3**pp<< " "<< **&pp+4 <<std::endl;
  */
  
  
  int *ptr = nullptr; // Ponteiro nulo
  std::cout<<ptr<<std::endl;
  
  return 0;
}
