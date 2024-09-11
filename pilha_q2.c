/*questao 6.1.2 Inversão de palavras. Escreva uma função que inverta a ordem das letras
 de cada palavra de uma sentença, preservando a ordem das palavras. Suponha que as
 palavras da sentença são separadas por espaços. A aplicação da operação à sentença
 AMU MEGASNEM ATERCES, por exemplo, deve produzir UMA MENSAGEM SECRETA.*/

#include <stdio.h>
#include <string.h>

void inverter_palavra(char* inicio, char* fim) {
    while (inicio < fim) {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

void inverter_palavras(char* sentenca) {
    char* inicio_palavra = sentenca;
    char* atual = sentenca;
    
    while (*atual != '\0') {
        if (*atual == ' ') {
            inverter_palavra(inicio_palavra, atual - 1);
            inicio_palavra = atual + 1; 
        }
        atual++;
    }
    inverter_palavra(inicio_palavra, atual - 1);
}

int main() {
    char sentenca[200]; 
    
    printf("Digite uma sentença: ");
    fgets(sentenca, sizeof(sentenca), stdin);
    
    // Remover o caractere '\n'
    size_t len = strlen(sentenca);
    if (len > 0 && sentenca[len - 1] == '\n') {
        sentenca[len - 1] = '\0';
    }

    inverter_palavras(sentenca);
    printf("Sentença com palavras invertidas: %s\n", sentenca);
    
    return 0;
}