# Calculadora de Probabilidade: Lançamento de Moedas

Um programa em C desenvolvido para calcular a probabilidade de eventos específicos em sucessivos lançamentos de moedas, demonstrando também todo o espaço amostral.

## A História do Projeto

Este projeto nasceu de uma atividade informal e de um desafio em sala de aula durante a disciplina de **Teoria das Probabilidades**, ministrada pelo **Professor João Agnaldo do Nascimento** do Departamento de Estatística do Centro de Ciências Exatas e da Natureza (**CCEN**) da **UFPB**.

Durante a resolução de um problema no quadro, surgiu a seguinte questão: *"Qual a probabilidade de, ao lançar 5 moedas, toda coroa ser precedida por uma cara?"*. O professor então questionou a turma se seria muito complicado implementar um programa de computador que calculasse essa probabilidade. Tendo afirmado que não seria complexo, aceitei a proposta de trazer a solução na aula seguinte.

## Como o programa funciona?

Busquei projetar um algoritmo generalista que permitisse o usuário de definir uma quantia qualquer de jogadas ($n$) e buscasse por diferentes padrões e regras dentro do espaço amostral gerado.
A matemática do código baseia-se em **força bruta e combinatória**:
  
-  **Sabendo que uma moeda tem 2 lados (Cara ou Coroa), o total de possibilidades para $n$ jogadas é sempre $2^n$.**
  
-   **O programa itera de $0$ até $2^n - 1$. Durante a iteração, ele utiliza decomposição binária para converter cada número inteiro do espaço de possibilidades em uma sequência de 0's e 1's, onde `0` representa **Cara ('c')** e `1` representa **Coroa ('k')**. Após montar a sequência do momento, ele verifica se ela atende à regra definida pelo usuário.**

### Modos de Busca

O programa possui dois modos de operação:

1. **Posição Exata (com curingas):** Permite verificar o que caiu em posições específicas. Você utiliza `c` (cara), `k` (coroa) e `x` (não importa). 
   * *Exemplo:* Para 4 jogadas, buscar `cxxk` trará todas as sequências que começam com cara e terminam com coroa, independentemente do meio.
2. **Subsequência / Regra Oculta:** Permite buscar um bloco específico de resultados em qualquer lugar da sequência.
   * *Exemplo:* Para 4 jogadas, buscar `ckk` encontrará todas as ocorrências onde uma cara é seguida de duas coroas (ex: `ckkk`, `cckk`, `kckk`).

### Exemplo de Uso
Digite a quantidade de jogadas: 3

Escolha 1 - para definir posicao exata (ex: cxxk)

Escolha 2 - para definir 'regra'/'subsequencia' (se n=4 e 'ckk'- engloba ckkk, ckkc, cckk, kckk)

Opcao: 1

Digite o padrao desejado: cxk

- cck
- ckk

--- Resultados ---

Casos favoraveis: 2

Total de possibilidades (2^3): 8

Probabilidade do evento: 25.00%

#### ---
*Artur Rodrigues Nunes de Almeida - Aluno de Ciência de Dados e Inteligência Artificial - Centro de Informática (CI) / UFPB*
