#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
//
// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash

// Struct Sala com nome e dois ponteiros (esquerda e direita)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função criarSala()
Sala* criarSala(char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Função conectarSalas() 
// Conecta uma sala filha à sala pai em uma direção ('e' ou 'd')
void conectarSalas(Sala* pai, Sala* filho, char direcao) {
    if (direcao == 'e' || direcao == 'E') {
        pai->esquerda = filho;
    } else if (direcao == 'd' || direcao == 'D') {
        pai->direita = filho;
    }
}

// Função explorarSalas() com Loop
void explorarSalas(Sala* inicial) {
    Sala* atual = inicial;
    char opcao;

    printf("\n--- JOGO INICIADO ---\n");

    //  Uso de laços para caminhar pela árvore
    while (atual != NULL) {
        // Exiba o nome da sala a cada movimento
        printf("\n📍 Voce esta em: [ %s ]\n", atual->nome);

        // Verifica se é fim de jogo (folha)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("\nEsta sala nao tem saidas. Fim da exploracao!\n");
            break;
        }

        // Mostra opções
        printf("Caminhos: ");
        if (atual->esquerda) printf("(e) Esquerda ");
        if (atual->direita)  printf("(d) Direita ");
        printf("\n");

        //Jogador explora ou 5. Sai (s)
        printf("Digite 'e', 'd' ou 's' para sair: ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            printf("Saindo do jogo...\n");
            break;
        } 
        else if ((opcao == 'e' || opcao == 'E') && atual->esquerda) {
            atual = atual->esquerda;
        } 
        else if ((opcao == 'd' || opcao == 'D') && atual->direita) {
            atual = atual->direita;
        } 
        else {
            printf("Opcao invalida ou caminho fechado!\n");
        }
    }
}


int main() {

// --- ESTRUTURA DO NÓ (SALA) ---
// Árvore fixa, nenhuma inserção dinâmica pelo usuário
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblio = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sotao");
    Sala* porao = criarSala("Porao");

    // Uso da função conectarSalas
    conectarSalas(hall, biblio, 'e');   // Biblioteca à esquerda do Hall
    conectarSalas(hall, cozinha, 'd');  // Cozinha à direita do Hall
    conectarSalas(biblio, sotao, 'e');  // Sótão à esquerda da Biblioteca
    conectarSalas(cozinha, porao, 'd'); // Porão à direita da Cozinha

    /* Mapa:
             [Hall]
             /    \
        [Biblio] [Cozinha]
          /          \
       [Sotao]      [Porao]
    */

    explorarSalas(hall);

    return 0;
}
     
