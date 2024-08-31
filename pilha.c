#include <stdio.h>
#include <stdlib.h>

int tamanho = 10;
int pilha [10];
int posicaoAtual = -1;

int isFull() {
    return posicaoAtual == tamanho
- 1;}

int isEmpty() {
    return posicaoAtual == -1;
}

void empilha (int x){
    if (isFull()) {
        printf("Pilha cheia\n");
        return;
    }
    pilha[++posicaoAtual] = x;
}

int desempilha() {
    if (isEmpty()) {
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha[posicaoAtual--];
}

void incrementa(int valor) {
    if (isEmpty()) {
        printf("Pilha vazia não é possivel incrementar.\n");
        return;
    }
    pilha[posicaoAtual] += valor;
}

void decrementa(int valor) {
    if (isEmpty()) {
        printf("Pilha vazia Não é possível decrementar.\n");
        return;
    }
    pilha[posicaoAtual] -= valor;
}

void imprimirPilha() {
    if (isEmpty()) {
        printf("Pilha Vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= posicaoAtual; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    empilha(10);
    empilha(20);
    empilha(30);

    imprimirPilha();

    incrementa(7);
    imprimirPilha();

    decrementa(2);
    imprimirPilha();

    desempilha();
    imprimirPilha();

    return 0;
}