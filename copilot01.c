#include <stdio.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nomeAlim[51];
    float qtdAli;
    char undAli[4];
    float kcalAli;
} Alimento;

// Função para preencher os dados de um Alimento
void preencherAlimento(Alimento *alim) {
    printf("Digite o nome do alimento: ");
    fgets(alim->nomeAlim, 51, stdin);
    alim->nomeAlim[strcspn(alim->nomeAlim, "\n")] = 0; // Remove newline

    printf("Digite a quantidade do alimento: ");
    scanf("%f", &alim->qtdAli);
    getchar(); // Limpa o buffer do teclado

    printf("Digite a unidade do alimento (ex: kg, g, ml): ");
    fgets(alim->undAli, 4, stdin);
    alim->undAli[strcspn(alim->undAli, "\n")] = 0; // Remove newline

    printf("Digite as calorias do alimento: ");
    scanf("%f", &alim->kcalAli);
    getchar(); // Limpa o buffer do teclado
}

// Função para imprimir os dados de um Alimento
void imprimirAlimento(Alimento alim) {
    printf("\nNome do Alimento: %s\n", alim.nomeAlim);
    printf("Quantidade: %.2f\n", alim.qtdAli);
    printf("Unidade: %s\n", alim.undAli);
    printf("Calorias: %.2f kcal\n", alim.kcalAli);
}

int main() {
    Alimento meuAlim;

    // Preenche os dados do alimento
    preencherAlimento(&meuAlim);

    // Imprime os dados do alimento
    imprimirAlimento(meuAlim);

    return 0;
}