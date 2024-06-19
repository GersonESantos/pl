#include <stdio.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nomeAlim[51];
    float qtdAli;
    char undAli[4];
    float kcalAli;
} Alimento;

// Função para imprimir o plano alimentar
void impPlAlimentar(const char *refeicao, Alimento alimentos[], int numAlimentos) {
    FILE *arquivoCSV = fopen("saida.csv", "a");
    FILE *arquivoTXT = fopen("saida.txt", "a");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    float totalCalorias = 0;

    // Imprime o cabeçalho da refeição
    fprintf(arquivoTXT, "### %s ###\n", refeicao);
    fprintf(arquivoCSV, "Refeicao: %s\n", refeicao);

    // Imprime os detalhes dos alimentos
    for (int i = 0; i < numAlimentos; i++) {
        Alimento a = alimentos[i];
        fprintf(arquivoTXT, "%-20s %.2f %-8s %.2f Kcal\n", a.nomeAlim, a.qtdAli, a.undAli, a.kcalAli);
        fprintf(arquivoCSV, "%s,%.2f,%s,%.2f\n", a.nomeAlim, a.qtdAli, a.undAli, a.kcalAli);

        totalCalorias += a.kcalAli;
    }

    // Imprime o total de calorias no final
    fprintf(arquivoTXT, "Total de calorias: %.2f Kcal\n\n", totalCalorias);
    fprintf(arquivoCSV, "Total de calorias,%.2f\n\n", totalCalorias);

    fclose(arquivoCSV);
    fclose(arquivoTXT);
}

// Função para gerar a lista de compras
void listaDeCompras(Alimento alimentos[], int numAlimentos) {
    FILE *arquivoCSV = fopen("lista.csv", "w");
    FILE *arquivoTXT = fopen("lista.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    // Imprime o cabeçalho da lista de compras
    fprintf(arquivoTXT, "### Lista de Compras ###\n");
    fprintf(arquivoCSV, "Lista de Compras\n");

    // Imprime os detalhes dos alimentos para a lista de compras
    for (int i = 0; i < numAlimentos; i++) {
        Alimento a = alimentos[i];
        fprintf(arquivoTXT, "%-20s %.2f %-8s\n", a.nomeAlim, a.qtdAli, a.undAli);
        fprintf(arquivoCSV, "%s,%.2f,%s\n", a.nomeAlim, a.qtdAli, a.undAli);
    }

    fclose(arquivoCSV);
    fclose(arquivoTXT);
}

int main() {
    // Definindo os alimentos para cada refeição
    Alimento dejejum[] = {
        {"Banana", 125, "g", 124},
        {"Aveia em flocos", 30, "g", 118},
        {"Coco", 20, "g", 71},
        {"Whey 3 Protein", 30, "g", 126},
        {"Yakult", 100, "g", 51}
    };

    Alimento almoco[] = {
        {"Arroz branco", 125, "g", 160},
        {"Feijão carioca", 90, "g", 68},
        {"Cenoura", 50, "g", 43},
        {"Tomate", 25, "g", 4},
        {"Carne Bife", 150, "g", 186}
    };

    Alimento lancheTarde[] = {
        {"Tapioca de goma", 15, "g", 37},
        {"Ovo", 3, "un", 189},
        {"Patinho moída", 120, "g", 160},
        {"Tomate", 25, "g", 4},
        {"Mussarela", 30, "g", 85}
    };

    Alimento ceia[] = {
        {"Banana", 125, "g", 124},
        {"Chocolate 70%", 25, "g", 245},
        {"Whey 3 Protein", 30, "g", 126},
        {"Coco", 20, "g", 71},
        {"Castanha", 5, "g", 77}
    };

    // Chamando a função para imprimir o plano alimentar de cada refeição
    impPlAlimentar("12:00 - Dejejum", dejejum, sizeof(dejejum) / sizeof(Alimento));
    impPlAlimentar("14:00 - Almoço", almoco, sizeof(almoco) / sizeof(Alimento));
    impPlAlimentar("18:30 - Lanche da tarde", lancheTarde, sizeof(lancheTarde) / sizeof(Alimento));
    impPlAlimentar("22:00 - Ceia", ceia, sizeof(ceia) / sizeof(Alimento));

    // Chamando a função para gerar a lista de compras geral
    listaDeCompras(dejejum, sizeof(dejejum) / sizeof(Alimento));
    listaDeCompras(almoco, sizeof(almoco) / sizeof(Alimento));
    listaDeCompras(lancheTarde, sizeof(lancheTarde) / sizeof(Alimento));
    listaDeCompras(ceia, sizeof(ceia) / sizeof(Alimento));

    return 0;
}
