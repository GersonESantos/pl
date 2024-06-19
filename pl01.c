#include <stdio.h>

// Definição da estrutura Alimento
typedef struct {
    char nomeAlim[51];
    float qtdAli;
    char undAli[4];
    float kcalAli;
} Alimento;

// Função para imprimir o plano alimentar de uma refeição
void impPlAlimentar(const char *nomeRefe, Alimento alimentos[], int numAlimentos, FILE *arquivoCSV, FILE *arquivoTXT, float *totalCaloriasGeral) {
    float totalCalorias = 0;

    // Imprime o cabeçalho da refeição
    fprintf(arquivoTXT, "### %s ###\n", nomeRefe);
    fprintf(arquivoCSV, "Refeicao: %s\n", nomeRefe);

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

    // Atualiza o total de calorias geral
    *totalCaloriasGeral += totalCalorias;
}

// Função para gerar a lista de compras
void listaDeCompras(const char *nomeLista, Alimento alimentos[], int numAlimentos, FILE *arquivoCSV, FILE *arquivoTXT) {
    // Imprime o cabeçalho da lista de compras
    fprintf(arquivoTXT, "### Lista de Compras ###\n");
    fprintf(arquivoCSV, "Lista de Compras: %s\n", nomeLista);

    // Imprime os detalhes dos alimentos para a lista de compras
    for (int i = 0; i < numAlimentos; i++) {
        Alimento a = alimentos[i];
        fprintf(arquivoTXT, "%-20s %.2f %-8s\n", a.nomeAlim, a.qtdAli, a.undAli);
        fprintf(arquivoCSV, "%s,%.2f,%s\n", a.nomeAlim, a.qtdAli, a.undAli);
    }

    fprintf(arquivoTXT, "\n");
    fprintf(arquivoCSV, "\n");
}

int main() {
    // Abrindo os arquivos de saída
    FILE *arquivoCSV = fopen("saida.csv", "w");
    FILE *arquivoTXT = fopen("saida.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // Definindo as refeições e seus alimentos
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

    float totalCaloriasGeral = 0;

    // Chamando a função para imprimir o plano alimentar de cada refeição
    impPlAlimentar("12:00 - Dejejum", dejejum, sizeof(dejejum) / sizeof(Alimento), arquivoCSV, arquivoTXT, &totalCaloriasGeral);
    impPlAlimentar("14:00 - Almoço", almoco, sizeof(almoco) / sizeof(Alimento), arquivoCSV, arquivoTXT, &totalCaloriasGeral);
    impPlAlimentar("18:30 - Lanche da tarde", lancheTarde, sizeof(lancheTarde) / sizeof(Alimento), arquivoCSV, arquivoTXT, &totalCaloriasGeral);
    impPlAlimentar("22:00 - Ceia", ceia, sizeof(ceia) / sizeof(Alimento), arquivoCSV, arquivoTXT, &totalCaloriasGeral);

    // Imprime o total de calorias geral no final do arquivo
    fprintf(arquivoTXT, "### Total de calorias Geral: %.2f Kcal ###\n", totalCaloriasGeral);
    fprintf(arquivoCSV, "Total de calorias Geral,%.2f\n", totalCaloriasGeral);

    // Fechando os arquivos de saída
    fclose(arquivoCSV);
    fclose(arquivoTXT);

    return 0;
}
