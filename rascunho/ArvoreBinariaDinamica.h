//Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef char string[101];
typedef clock_t processTime;

typedef struct {
    long long int matricula; //Matrícula do aluno. 
    string nome;             //Nome do aluno. 
    NoArvore *direito;
    NoArvore *esquerdo; 
} NoArvore;

typedef struct {
    NoArvore *raiz;
    int tamanho;         //Número de elementos ocupados na árvore. 
    int capacidade;      //Capacidade atual da árvore. 
} ArvoreBinaria;

FILE *abrirArquivo(char *nomeArq, char *modo);
void calcularTempo(double ini, double fim);
void salvarDadosNoArquivo(ArvoreBinaria *arvore, FILE *arquivoLista);
void inicializarArvore(ArvoreBinaria *arvore, int quantidadeMatriculas);
void redimensionarArvore(ArvoreBinaria *arvore);
void imprimirEmOrdem(ArvoreBinaria *arvore, int indice);
void liberarArvore(ArvoreBinaria *arvore);
long long int pedirOpcao();
long long int pedirNum(int caminhoASerEscolhido);
void menuPrincipal(ArvoreBinaria *arvore);
int contarMatriculas(FILE *arquivoLista);
void inserirAluno(ArvoreBinaria *arvore, long long int matricula, char *nome);
void buscarAluno(ArvoreBinaria *arvore, long long int matricula);
void removerAluno(ArvoreBinaria *arvore, long long int matricula);
void lerEInserirMatriculas(ArvoreBinaria *arvore, FILE *arquivoLista);
void imprimirEmOrdem(ArvoreBinaria *arvore, int indice);
