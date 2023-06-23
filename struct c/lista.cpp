#include <iostream>

struct Node {
  int valor;
  Node* proximo;
};

int main() {
  Node node1;  // Primeiro elemento da lista
  node1.valor = 10;
  node1.proximo = nullptr;
  
  Node node2;
  node2.valor = 20;
  node1.proximo = &node2;

  Node node3;
  node3.valor = 30;
  node2.proximo = &node3;
  node3.proximo = nullptr;

  // Percorrendo a lista e imprimindo os valores
  Node* currentNode = &node1;
  while (currentNode != nullptr) {
    std::cout << currentNode->valor << std::endl;
    currentNode = currentNode->proximo;  // Avança para o próximo elemento da lista
  }

  return 0;
}
