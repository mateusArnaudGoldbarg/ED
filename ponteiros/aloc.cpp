#include <iostream>

int main() {
  int* arr = new int[5]; // Alocação dinâmica de um array de inteiros

  for (int i = 0; i < 5; i++) {
    arr[i] = i; // Atribuição de valores ao array
  }

  int* p = &arr[0]; // Atribuição do endereço do array ao ponteiro

  for (int i = 0; i < 5; i++) {
    std::cout <<*p << " "; // Imprimir o valor apontado pelo ponteiro
    p++; // Avançar o ponteiro para o próximo elemento
  }
  std::cout<<std::endl;

  delete[] arr; // Liberar a memória alocada

  return 0;
}
