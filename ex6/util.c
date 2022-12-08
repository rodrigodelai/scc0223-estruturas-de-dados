#include "util.h"

int ler_inteiro(){
    int inteiro = 0;
    scanf(" %d", &inteiro);
    return inteiro;
}

char* ler_dado(){
    char separador = ','; // Caracter que sinaliza o fim do dado
    char* dado = NULL;
    char caractere_atual = getchar();
    int indice_atual = 0;

    while (caractere_atual == separador || caractere_atual == '\n' || caractere_atual == '\r') caractere_atual = getchar(); // Limpa o buffer
    if (caractere_atual == EOF) return NULL; // Sinaliza o fim do arquivo

    do{
        dado = (char*) realloc(dado, (indice_atual + 2) * sizeof(char));
        dado[indice_atual] = caractere_atual;
        
        indice_atual++;
        caractere_atual = getchar();

        if (caractere_atual == '\r') caractere_atual = getchar(); // Tratamento para ambiente Windows

    } while (caractere_atual != separador && caractere_atual != '\n' && caractere_atual != EOF);

    dado[indice_atual] = '\0';

    return dado;
}

void exibir_palavra(char* palavra){
    if (palavra == NULL) printf("Erro ao exibir palavra: %d\n", ERRO_NULL);
    else printf("%s\n", palavra);
}

boolean apagar_palavra(char** palavra){
    if (palavra == NULL || *palavra == NULL){
        printf("Erro ao excluir palavra: %d\n", ERRO_NULL);
        return FALSE;
    }

    free(*palavra);
    *palavra = NULL;

    return TRUE;
}

void exibir_booleano(boolean bool){
    if (bool == 1) printf("true\n");
    else if (bool == 0) printf("false\n");
    else printf("Erro ao imprimir booleano: Valor inesperado\n");
}