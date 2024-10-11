//Feito por: Lucas Garcia E Luis Augusto
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Defina constantes para as sequências de escape ANSI das cores
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SEPARETOR BLUE "\n================================================\n"  RESET

/**
 * @file ArvoreBinariaDinamica.h
 * @brief Definições e estruturas para a manipulação de uma árvore binária.
 */

/** Define um tipo string com tamanho 101 */
typedef char string[101];

/** Define um tipo para medir o tempo de processamento */
typedef clock_t processTime;

/** 
 * @struct NoArvore
 * @brief Representa um nó da árvore binária.
 * 
 * @var NoArvore::matricula
 * Matrícula do aluno.
 * 
 * @var NoArvore::nome
 * Nome do aluno.
 * 
 * @var NoArvore::direito
 * Ponteiro para o filho à direita.
 * 
 * @var NoArvore::esquerdo
 * Ponteiro para o filho à esquerda.
 */
typedef struct NoArvore {
    long long int matricula;  
    string nome;              
    struct NoArvore *direito; 
    struct NoArvore *esquerdo;
} NoArvore;

/**
 * @struct ArvoreBinaria
 * @brief Representa uma árvore binária com raiz e tamanho.
 * 
 * @var ArvoreBinaria::raiz
 * Ponteiro para o nó raiz da árvore.
 * 
 * @var ArvoreBinaria::tamanho
 * Número de nós presentes na árvore.
 */
typedef struct {
    NoArvore *raiz; 
    int tamanho;    
} ArvoreBinaria;

/**
 * @brief Abre um arquivo no modo especificado.
 * @param nomeArq Nome do arquivo a ser aberto.
 * @param modo Modo de abertura (ex: "r" para leitura).
 * @return Ponteiro para o arquivo.
 */
FILE *abrirArquivo(char *nomeArq, char *modo);

/**
 * @brief Calcula e exibe o tempo de execução.
 * @param ini Tempo inicial.
 * @param fim Tempo final.
 */
void calcularTempo(double ini, double fim);

/**
 * @brief Salva os dados de um nó em um arquivo.
 * @param no Ponteiro para o nó da árvore.
 * @param arquivoLista Ponteiro para o arquivo de saída.
 */
void salvarDadosNoArquivo(NoArvore *no, FILE *arquivoLista);

/**
 * @brief Inicializa uma árvore binária.
 * @param arvore Ponteiro para a árvore binária a ser inicializada.
 */
void inicializarArvore(ArvoreBinaria *arvore);

/**
 * @brief Libera a memória alocada para a árvore.
 * @param no Ponteiro para o nó a ser liberado.
 */
void liberarArvore(NoArvore *no);

/**
 * @brief Imprime a árvore binária em ordem.
 */
void caminhamento_Em_Ordem(NoArvore *no);
/**
 * @brief Imprime a árvore binária em Pré ordem.
 * @param no Ponteiro para o nó da árvore a ser impresso.

 */
void caminhamento_Pre_Ordem(NoArvore *no);

/**
 * @brief Imprime a árvore binária em Pós ordem.
 * @param no Ponteiro para o nó da árvore a ser impresso.
 */
void caminhamento_Pos_Ordem(NoArvore *no);

/**
 * @brief Insere um novo nó na árvore binária.
 * @param no Ponteiro para o nó da árvore.
 * @param matricula Matrícula a ser inserida.
 * @param nome Nome do aluno.
 * @return Ponteiro para o nó inserido.
 */
NoArvore* inserirNo(NoArvore *no, long long int matricula, char *nome);

/**
 * @brief Busca um nó pela matrícula.
 * @param no Ponteiro para o nó da árvore.
 * @param matricula Matrícula a ser buscada.
 * @return Ponteiro para o nó encontrado.
 */
NoArvore* buscarNo(NoArvore *no, long long int matricula);

/**
 * @brief Remove um nó da árvore binária.
 * @param no Ponteiro para o nó da árvore.
 * @param matricula Matrícula do nó a ser removido.
 * @return Ponteiro para o nó removido.
 */
NoArvore* removerNo(NoArvore *no, long long int matricula);

/**
 * @brief Encontra o menor valor em uma subárvore.
 * @param no Ponteiro para o nó da árvore.
 * @return Ponteiro para o nó com o menor valor.
 */
NoArvore* encontrarMinimo(NoArvore *no);

/**
 * @brief Lê as matrículas de um arquivo e insere na árvore.
 * @param arvore Ponteiro para a árvore binária.
 * @param arquivoLista Ponteiro para o arquivo contendo as matrículas.
 */
void lerEInserirMatriculas(ArvoreBinaria *arvore, FILE *arquivoLista);

/**
 * @brief Função principal do menu de operações.
 * @param arvore Ponteiro para a árvore binária.
 */
void menuPrincipal(ArvoreBinaria *arvore);

/**
 * @brief Conta o número de matrículas em um arquivo.
 * @param arquivoLista Ponteiro para o arquivo.
 * @return Número total de matrículas.
 */
int contarMatriculas(FILE *arquivoLista);