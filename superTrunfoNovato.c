#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES_POR_ESTADO 4

typedef struct {
    char codigo[4]; // Código da carta (ex: A01, B02, etc.)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", cidade->codigo);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

void exibirCidade(Cidade cidade) {
    printf("\nCódigo: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f milhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES_POR_ESTADO];

    // Cadastro das cidades
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            printf("\nCadastrando cidade %c%d:\n", 'A' + i, j + 1);
            cadastrarCidade(&cidades[i][j]);
        }
    }

    // Exibição das cidades cadastradas
    printf("\nCidades cadastradas:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            exibirCidade(cidades[i][j]);
        }
    }

    return 0;
}