Super Trunfo - Países - Cadastro das Cartas
Este projeto implementa um sistema de cadastro de cartas para o jogo Super Trunfo com tema de países. O sistema permite cadastrar cartas de cidades com diversos atributos e oferece três níveis de complexidade de implementação.

Descrição
O sistema permite o cadastro de cartas representando cidades com diferentes atributos. Cada carta contém informações como estado, código, nome da cidade, população, área, PIB e número de pontos turísticos. O projeto é dividido em três níveis de implementação com complexidade crescente.

Níveis de Implementação
Nível Novato
Cadastro básico de cartas com atributos fundamentais

Entrada de dados via terminal usando scanf

Exibição organizada dos dados cadastrados

Atributos suportados: população, área, PIB, pontos turísticos

Nível Aventureiro
Todos os recursos do nível Novato

Cálculo automático de densidade populacional (população/área)

Cálculo automático de PIB per capita (PIB/população)

Exibição dos atributos calculados

Nível Mestre
Todos os recursos do nível Aventureiro

Comparação entre duas cartas atributo por atributo

Cálculo do "Super Poder" (soma de todos os atributos com densidade invertida)

Regras específicas de comparação para cada atributo

Tecnologias Utilizadas
Linguagem de programação C

Estruturas de dados (struct) para representar as cartas

Funções de entrada/saída da biblioteca stdio.h

Funções de manipulação de strings da biblioteca string.h

Funções de caracteres da biblioteca ctype.h para validação

Como Compilar e Executar
Compilação
text
gcc super_trunfo.c -o super_trunfo
Execução
text
./super_trunfo