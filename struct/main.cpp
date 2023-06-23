#include <iostream>
#include <string>

struct Pessoa {
  std::string nome;
  int idade;
  float altura;
};

int main() {
  Pessoa pessoa1;
  pessoa1.nome = "João";
  pessoa1.idade = 25;
  pessoa1.altura = 1.75;

  std::cout << "Nome: " << pessoa1.nome << std::endl;
  std::cout << "Idade: " << pessoa1.idade << std::endl;
  std::cout << "Altura: " << pessoa1.altura << std::endl;

  return 0;
}
