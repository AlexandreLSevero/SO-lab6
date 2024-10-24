#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de uma célula
struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

// Função para imprimir os valores da lista
void imprimir_lista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para remover a lista e liberar a memória
void remover_lista(celula **inicio) {
    celula *atual = *inicio;
    celula *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
    printf("Todos os elementos foram removidos e a memória foi liberada.\n");
}

// Função para calcular o número máximo de elementos na lista com base na memória disponível
long calcular_max_elementos(long memoria_total) {
    long tamanho_celula = sizeof(int) + sizeof(celula *);
    return memoria_total / tamanho_celula;
}

int main() {
    // Criação de três instâncias de células
    celula *primeira = (celula *)malloc(sizeof(celula));
    celula *segunda = (celula *)malloc(sizeof(celula));
    celula *terceira = (celula *)malloc(sizeof(celula));

    // Atribuindo valores
    primeira->conteudo = 10;
    segunda->conteudo = 20;
    terceira->conteudo = 30;

    // Ligação das células
    primeira->prox = segunda;
    segunda->prox = terceira;
    terceira->prox = NULL;

    // Imprimir os valores da lista
    printf("Valores da lista:\n");
    imprimir_lista(primeira);

    // Calcular a memória utilizada por cada célula (int + ponteiro)
    printf("\nCada célula ocupa %lu bytes de memória.\n", sizeof(int) + sizeof(celula *));

    // Exemplo: calcular o máximo de elementos possíveis com 8GB de RAM
    long memoria_total = 8L * 1024 * 1024 * 1024; // 8 GB
    long max_elementos = calcular_max_elementos(memoria_total);
    printf("Máximo de elementos possíveis na lista com 8GB de RAM: %ld\n", max_elementos);

    // Remover elementos e liberar memória
    remover_lista(&primeira);

    return 0;
}
