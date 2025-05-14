#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular atributos derivados
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar dois atributos e determinar o vencedor
void comparar_cartas(Carta carta1, Carta carta2) {
    // Escolha do atributo para comparação (exemplo: PIB per capita)
    float atributo1 = carta1.pib_per_capita;
    float atributo2 = carta2.pib_per_capita;

    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, atributo1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, atributo2);

    if (atributo1 > atributo2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (atributo1 < atributo2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }
}

int main() {
    // Cadastro de duas cartas
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 699000000000.0, 10};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6748000, 1182.30, 364000000000.0, 8};

    // Calcular atributos derivados
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}
