//Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef char string[101];
typedef clock_t processTime;

typedef struct NoArvore {
    long long int matricula;  // Matrícula do aluno.
    string nome;              // Nome do aluno.
    struct NoArvore *direito; // Ponteiro para o filho à direita.
    struct NoArvore *esquerdo;// Ponteiro para o filho à esquerda.
} NoArvore;

typedef struct {
    NoArvore *raiz; // Raiz da árvore binária.
    int tamanho;    // Número de elementos na árvore.
} ArvoreBinaria;

FILE *abrirArquivo(char *nomeArq, char *modo);
void calcularTempo(double ini, double fim);
void salvarDadosNoArquivo(NoArvore *no, FILE *arquivoLista);
void inicializarArvore(ArvoreBinaria *arvore);
void liberarArvore(NoArvore *no);
void imprimirEmOrdem(NoArvore *no);
NoArvore* inserirNo(NoArvore *no, long long int matricula, char *nome);
NoArvore* buscarNo(NoArvore *no, long long int matricula);
NoArvore* removerNo(NoArvore *no, long long int matricula);
NoArvore* encontrarMinimo(NoArvore *no);
void lerEInserirMatriculas(ArvoreBinaria *arvore, FILE *arquivoLista);
void menuPrincipal(ArvoreBinaria *arvore);
int contarMatriculas(FILE *arquivoLista);
