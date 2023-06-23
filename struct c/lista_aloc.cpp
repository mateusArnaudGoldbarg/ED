#include <iostream>

struct Node {
  int valor;
  Node* proximo;
};

int main() {
  Node* lista = nullptr;  // Ponteiro para o primeiro elemento da lista

  // Criando os elementos da lista
  Node* node1 = new Node;
  node1->valor = 10;
  node1->proximo = nullptr;
  lista = node1;  // O ponteiro da lista aponta para o primeiro elemento

  Node* node2 = new Node;
  node2->valor = 20;
  node2->proximo = nullptr;
  node1->proximo = node2;  // O ponteiro do primeiro elemento aponta para o segundo elemento

  Node* node3 = new Node;
  node3->valor = 30;
  node3->proximo = nullptr;
  node2->proximo = node3;  // O ponteiro do segundo elemento aponta para o terceiro elemento

  // Percorrendo a lista e imprimindo os valores
  Node* currentNode = lista;
  while (currentNode != nullptr) {
    std::cout << currentNode->valor << std::endl;
    currentNode = currentNode->proximo;  // Avança para o próximo elemento da lista
  }

  // Liberando a memória alocada
  currentNode = lista;
  while (currentNode != nullptr) {
    Node* proximoNode = currentNode->proximo;
    delete currentNode;
    currentNode = proximoNode;
  }

  return 0;
}

