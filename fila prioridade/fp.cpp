#include <iostream>

// Struct para representar um nó na fila de prioridade
struct Node {
    int priority;
    std::string data;
    Node* next;

    Node(int priority, const std::string& data) : priority(priority), data(data), next(nullptr) {}
};

// Classe para representar a fila de prioridade
class PriorityQueue {
private:
    Node* front;

public:
    //construtor
    PriorityQueue(){
        front = nullptr;
    }
    
    //empilhar
    void enqueue(int priority, const std::string& data) {
        Node* newNode = new Node(priority, data);
        // Caso especial: se a fila estiver vazia ou o novo nó tem prioridade maior que a frente
        if (front == nullptr || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            // Procura a posição correta para inserir o novo nó
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
    //desempilhar
    void dequeue() {
        if (!isEmpty()) {
            Node* nodeToDelete = front;
            front = front->next;
            delete nodeToDelete;
        }
    }
    
    //checa se está vazia
    bool isEmpty(){
        return front == nullptr;
    }
    
    //imprimir elementos
    void print(){
        if (isEmpty()) {
            std::cout << "Priority queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << "Priority: " << current->priority << ", Data: " << current->data << std::endl;
            current = current->next;
        }
    }
    
};

// Exemplo de uso da fila de prioridade
int main() {
    PriorityQueue priorityQueue;

    	
    priorityQueue.enqueue(2, "Data 2");
    priorityQueue.enqueue(3, "Data 3");
    priorityQueue.enqueue(5, "Data 5");
    priorityQueue.enqueue(1, "Data 1");
    priorityQueue.enqueue(4, "Data 4");
    
    priorityQueue.print();

    priorityQueue.dequeue();
    std::cout << "After dequeue:" << std::endl;
    priorityQueue.print();

    return 0;
}
