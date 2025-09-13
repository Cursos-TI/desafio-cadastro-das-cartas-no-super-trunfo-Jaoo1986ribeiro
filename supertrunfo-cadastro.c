#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[3];
    int codigo;
    char cidade[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
    double densidade;        // Calculado: população/área
    double pib_per_capita;   // Calculado: PIB/população
    double super_poder;      // Calculado: soma dos atributos com densidade invertida
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    
    // Estado (sigla com 2 letras)
    do {
        printf("Estado (sigla 2 letras): ");
        scanf("%2s", carta->estado);
        limparBuffer();
        
        // Converter para maiúsculas
        for (int i = 0; i < 2; i++) {
            carta->estado[i] = toupper(carta->estado[i]);
        }
    } while (strlen(carta->estado) != 2 || !isalpha(carta->estado[0]) || !isalpha(carta->estado[1]));
    
    // Código (número entre 1 e 4)
    do {
        printf("Código (1-4): ");
        scanf("%d", &carta->codigo);
        limparBuffer();
    } while (carta->codigo < 1 || carta->codigo > 4);
    
    // Cidade
    printf("Cidade: ");
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;
    
    // População
    printf("População: ");
    scanf("%lld", &carta->populacao);
    
    // Área
    printf("Área (km²): ");
    scanf("%lf", &carta->area);
    
    // PIB
    printf("PIB: ");
    scanf("%lld", &carta->pib);
    
    // Pontos turísticos
    printf("Pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    limparBuffer();
    
    // Cálculos adicionais (para níveis Aventureiro e Mestre)
    carta->densidade = (carta->area > 0) ? carta->populacao / carta->area : 0;
    carta->pib_per_capita = (carta->populacao > 0) ? (double)carta->pib / carta->populacao : 0;
    
    // Cálculo do Super Poder (para nível Mestre)
    // Soma de todos os atributos com densidade invertida
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos;
    if (carta->densidade > 0) {
        carta->super_poder += (1 / carta->densidade);
    }
    carta->super_poder += carta->pib_per_capita;
}

// Função para exibir uma carta
void exibirCarta(struct Carta carta, int nivel) {
    printf("\n--- Carta %s-%02d: %s ---\n", carta.estado, carta.codigo, carta.cidade);
    printf("População: %lld\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %lld\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    
    if (nivel >= 2) { // Nível Aventureiro e Mestre
        printf("Densidade populacional: %.2f hab/km²\n", carta.densidade);
        printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    }
    
    if (nivel >= 3) { // Nível Mestre
        printf("Super Poder: %.2f\n", carta.super_poder);
    }
}

// Função para comparar duas cartas (nível Mestre)
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    
    // População
    printf("População: ");
    if (c1.populacao > c2.populacao) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // Área
    printf("Área: ");
    if (c1.area > c2.area) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.area > c1.area) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // PIB
    printf("PIB: ");
    if (c1.pib > c2.pib) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.pib > c1.pib) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // Pontos turísticos
    printf("Pontos turísticos: ");
    if (c1.pontos_turisticos > c2.pontos_turisticos) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.pontos_turisticos > c1.pontos_turisticos) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // Densidade populacional (menor valor vence)
    printf("Densidade populacional: ");
    if (c1.densidade < c2.densidade) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.densidade < c1.densidade) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // PIB per capita
    printf("PIB per capita: ");
    if (c1.pib_per_capita > c2.pib_per_capita) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.pib_per_capita > c1.pib_per_capita) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
    
    // Super Poder
    printf("Super Poder: ");
    if (c1.super_poder > c2.super_poder) {
        printf("%s vence!\n", c1.cidade);
    } else if (c2.super_poder > c1.super_poder) {
        printf("%s vence!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
}

// Função principal
int main() {
    int nivel;
    struct Carta carta1, carta2;
    
    printf("=========================================\n");
    printf("    SUPER TRUNFO - PAÍSES\n");
    printf("=========================================\n");
    
    // Seleção de nível
    printf("Selecione o nível de desafio:\n");
    printf("1 - Novato (Cadastro básico)\n");
    printf("2 - Aventureiro (Cálculo de atributos)\n");
    printf("3 - Mestre (Comparação e Super Poder)\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    limparBuffer();
    
    if (nivel < 1 || nivel > 3) {
        printf("Nível inválido! Usando nível Novato como padrão.\n");
        nivel = 1;
    }
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas
    printf("\n\n=========================================\n");
    printf("          CARTAS CADASTRADAS\n");
    printf("=========================================\n");
    
    exibirCarta(carta1, nivel);
    exibirCarta(carta2, nivel);
    
    // Comparação (apenas para nível Mestre)
    if (nivel == 3) {
        compararCartas(carta1, carta2);
    }
    
    printf("\n=========================================\n");
    printf("        FIM DO SUPER TRUNFO\n");
    printf("=========================================\n");
    
    return 0;
}