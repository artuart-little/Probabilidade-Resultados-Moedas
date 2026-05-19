#include <stdio.h>
#include <string.h>

// fesvazia buffer do teclado e limpa Enter's que podem sobrar
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    int n = 0;
    int tipo_busca = 0;
    char padrao[30] = ""; 

    printf("Digite a quantidade de jogadas: ");
    scanf("%d", &n);
    limpar_buffer(); 

    printf("\nEscolha 1 - para definir posicao exata (ex: cxxk)\n");
    printf("Escolha 2 - para definir 'regra'/'subsequencia' (se n=4 e 'ckk'- engloba ckkk, ckkc, cckk, kckk)\n");
    printf("Opcao: ");
    scanf("%d", &tipo_busca);
    limpar_buffer(); 
    
    if ( (tipo_busca != 1 && tipo_busca != 2) || (n <= 0) ){
        printf("\nErro: Entrada invalida\n");
        return 1;
    }

    printf("\nDigite o padrao desejado: ");
    scanf("%29s", padrao);
    limpar_buffer(); 

    int tamanho_padrao = strlen(padrao);

    if ( (tipo_busca == 1) && (tamanho_padrao != n) ) {
        printf("\nErro: Tamanho do padrao incompativel (%d != %d)\n", tamanho_padrao, n);
        return 1;
    }

    int total_possibilidades = 1;
    for (int i = 0; i < n; i++) {
        total_possibilidades = total_possibilidades * 2;
    }

    int casos_favoraveis = 0;
    
    // testa todos os casos
    for (int i = 0; i < total_possibilidades; i++) {
        char sequencia_atual[30];
        int valor_temporario = i;

        //decomposicao de cada possibilidade para binario, em que 0 = 'c' e 1 = 'k'
        //ex: possibilidade 1 (0001) se torna 'ccck', possibilidade 2 (0010) se torna 'cckc', ...
        for (int j = n - 1; j >= 0; j--) {
            int resto = valor_temporario % 2;
            
            if (resto == 0) {
                sequencia_atual[j] = 'c';
            } else {
                sequencia_atual[j] = 'k';
            }
            
            valor_temporario = valor_temporario / 2;
        }
        sequencia_atual[n] = '\0'; 

        int match = 1;

        if (tipo_busca == 1) { 
            for (int j = 0; j < n; j++) {
                if (padrao[j] != 'x') { //se caractere diferente de 'x', deve ser igual a 'c'/'k' já definido
                    if (padrao[j] != sequencia_atual[j]) {
                        match = 0; //se diferente do que foi definido, não há "match'
                        break;     
                    }
                }
            }
        } 
        else if (tipo_busca == 2) {
            //a funcao strstr procura uma palavra (a 'padrao') dentro da outra (a 'sequencia_atual')
            if (strstr(sequencia_atual, padrao) == NULL) {
                match = 0; //se NULL, a palavra não foi encontrada
            }
        }

        //se passar nos testes, aparece na tela e conta mais 1 caso favoravel
        if (match == 1) {
            casos_favoraveis++;
            printf("- %s\n", sequencia_atual);
        }
    }

    double probabilidade = ((double)casos_favoraveis / total_possibilidades) * 100.0;

    printf("\n--- Resultados ---\n");
    printf("Casos favoraveis: %d\n", casos_favoraveis);
    printf("Total de possibilidades (2^%d): %d\n", n, total_possibilidades);
    printf("Probabilidade do evento: %.2f%%\n", probabilidade);

    return 0;
}