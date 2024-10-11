//Feito por: Lucas Garcia E Luis Augusto
#include "ArvoreBinariaDinamica.h"

/**
 * @brief Abre um arquivo no modo especificado.
 */
FILE *abrirArquivo(char *nomeArq, char *modo) {
    FILE *arq = fopen(nomeArq, modo);
    if (arq == NULL) {
        printf("ERRO ao abrir o arquivo.\n");
        exit(-1);
    }
    printf("INFO: Arquivo Aberto! Bom uso.\n");
    return arq;
}

//=================================================================
/**
 * @brief Imprime a árvore em ordem.
 */
void caminhamento_Em_Ordem(NoArvore *R){
	if(R != NULL){
		caminhamento_Em_Ordem(R->esquerdo);
		printf("Matrícula: %lld, Nome: %s\n", R->matricula, R->nome);
		caminhamento_Em_Ordem(R->direito);
	}//if
}
//=================================================================
/**
 * @brief Imprime a árvore em Pré ordem.
 */
void caminhamento_Pre_Ordem(NoArvore *R){
	if(R != NULL){
		printf("Matrícula: %lld, Nome: %s\n", R->matricula, R->nome);
		caminhamento_Pre_Ordem(R->esquerdo);
		caminhamento_Pre_Ordem(R->direito);
	}//if
}
//=================================================================
/**
 * @brief Imprime a árvore em Pós ordem.
 */
void caminhamento_Pos_Ordem(NoArvore *R){
	if(R != NULL){
		caminhamento_Pos_Ordem(R->esquerdo);
		caminhamento_Pos_Ordem(R->direito);
		printf("Matrícula: %lld, Nome: %s\n", R->matricula, R->nome);
	}//if
}
//==================================================================

/**
 * @brief // inputs personalizados e modificados
 */

/**
 * @brief // input para captar floats e inteiros do teclado do usuario
 */
float input(){
    float value;
    scanf("%f", &value);
    return value;
}

/**
 * @brief // input para captar long long int do teclado do usuario
 */
long long int inputDLLD(){
    long long int value;
    scanf("%lld", &value);
    return value;
}

/**
 * @brief // input para captar Verdadeiro ou falso (Bloeano) do teclado do usuario
 */
float inputBoleano(){
	int value;
	do{
		fflush(stdin);
		scanf("%d", &value);
	}while(value != 1 && value != 0);
	return value;
}

/**
 * @brief // input para captar Strings do teclado do usuario
 */
void inputS(char destino[]){
    scanf(" %100[^\n]s", destino);
}


/**
 * @brief Calcula e exibe o tempo de execução.
 */
void calcularTempo(double ini, double fim) {
    double tempoDecorrido = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempoDecorrido);
}

/**
 * @brief Salva os dados dos nós da árvore em um arquivo.
 */
void salvarDadosNoArquivo(NoArvore *no, FILE *arquivoLista) {
    if (no == NULL) return;

    salvarDadosNoArquivo(no->esquerdo, arquivoLista);
    fprintf(arquivoLista, "%s\n%lld\n", no->nome, no->matricula);
    salvarDadosNoArquivo(no->direito, arquivoLista);
}

/**
 * @brief Inicializa a árvore binária.
 */
void inicializarArvore(ArvoreBinaria *arvore) {
    arvore->raiz = NULL;
    arvore->tamanho = 0;
}

/**
 * @brief Libera a memória dos nós da árvore.
 */
void liberarArvore(NoArvore *no) {
    if (no != NULL) {
        liberarArvore(no->esquerdo);
        liberarArvore(no->direito);
        free(no);
    }
}

/**
 * @brief Solicita uma opção do usuário no menu.
 */
long long int pedirOpcao() {
    int op;
    printf("\n--- Menu Principal ---\n");
    do {
        printf("1 - Inserir na Arvore\n");
        printf("2 - Excluir da Arvore\n");
        printf("3 - Pesquisar na Arvore\n");
        printf("4 - Total de Matriculas\n");
        printf("5 - Imprimir em Pre-ordem\n");
        printf("6 - Imprimir em Em-ordem\n");
        printf("7 - Imprimir em Pos-ordem\n");
        printf("0 - Sair\n");
        printf("Digite a opção: ");
        op = input();
    } while ((op < 0) || (op > 7));
    return op;
}

/**
 * @brief Solicita um número para inserção ou exclusão.
 */
long long int pedirNum(int caminhoASerEscolhido) {
    long long int num;
    if (caminhoASerEscolhido == 0) {
        printf("Digite um numero para ser inserido: ");
        num = inputDLLD();
    } else {
        printf("Digite um numero para ser excluido: ");
        num = inputDLLD();
    }
    return num;
}

/**
 * @brief Menu principal para interação com o usuário.
 */
void menuPrincipal(ArvoreBinaria *arvore) {
    long long int op, matricula;
    string nome;
    int repete = 0;
    do {
        op = pedirOpcao();
        switch (op) {
            case 0:
                repete = 1;
                break;
            case 1:
                printf("Digite o numero da matrícula: ");
                matricula = inputDLLD();
                printf("Digite o nome: ");
                inputS(nome);
                arvore->raiz = inserirNo(arvore->raiz, matricula, nome);
                arvore->tamanho++;
                break;
            case 2:
                printf("Digite o numero da matrícula para remover: ");
                matricula = inputDLLD();
                arvore->raiz = removerNo(arvore->raiz, matricula);
                arvore->tamanho--;
                break;
            case 3:
                printf("Digite o numero da matrícula para buscar: ");
                matricula = inputDLLD();
                buscarNo(arvore->raiz, matricula);
                break;
            case 4:
                printf("O total de matrículas na árvore é: %d\n", arvore->tamanho);
                break;
            case 5:
                printf("\n\n===| Exibição da Árvore Binária (Pre Ordem) |===\n\n");
                caminhamento_Pre_Ordem(arvore->raiz);
                break;
            case 6:
                printf("\n\n===| Exibição da Árvore Binária (Em Ordem) |===\n\n");
                caminhamento_Em_Ordem(arvore->raiz);
                break;
            case 7:
                printf("\n\n===| Exibição da Árvore Binária (Pos Ordem) |===\n\n");
                caminhamento_Pos_Ordem(arvore->raiz);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (repete == 0);
}

/**
 * @brief Conta o número de matrículas no arquivo.
 */
int contarMatriculas(FILE *arquivoLista) {
    char linha[100];
    int totalMatriculas = 0;
    while (! feof(arquivoLista)) {
        fscanf(arquivoLista, " %99[^\n]s" , linha);
        totalMatriculas++;
    }
    return totalMatriculas / 2;
}

/**
 * @brief Insere um novo nó na árvore binária.
 */
NoArvore* inserirNo(NoArvore *no, long long int matricula, char *nome) {
    if (no == NULL) {
        no = (NoArvore *)malloc(sizeof(NoArvore));
        if (no == NULL) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
        no->matricula = matricula;
        strcpy(no->nome, nome);
        no->esquerdo = no->direito = NULL;
    } else if (matricula < no->matricula) {
        no->esquerdo = inserirNo(no->esquerdo, matricula, nome);
    } else if (matricula > no->matricula) {
        no->direito = inserirNo(no->direito, matricula, nome);
    } else {
        printf("Matrícula já existente.\n");
    }
    return no;
}

/**
 * @brief Busca um nó pela matrícula.
 */
NoArvore* buscarNo(NoArvore *no, long long int matricula) {
    if (no == NULL) {
        printf("Aluno não encontrado.\n");
        return NULL;
    }
    if (matricula < no->matricula) {
        return buscarNo(no->esquerdo, matricula);
    } else if (matricula > no->matricula) {
        return buscarNo(no->direito, matricula);
    } else {
        printf("Aluno encontrado: %s (Matrícula: %lld)\n", no->nome, no->matricula);
        return no;
    }
}

/**
 * @brief Encontra o menor valor na árvore.
 */
NoArvore* encontrarMinimo(NoArvore *no) {
    while (no->esquerdo != NULL) no = no->esquerdo;
    return no;
}

/**
 * @brief Remove um nó da árvore binária.
 */
NoArvore* removerNo(NoArvore *no, long long int matricula) {
    if (no == NULL) {
        printf("Matrícula não encontrada.\n");
        return NULL;
    }

    if (matricula < no->matricula) {
        no->esquerdo = removerNo(no->esquerdo, matricula);
    } else if (matricula > no->matricula) {
        no->direito = removerNo(no->direito, matricula);
    } else {
        if (no->esquerdo == NULL) {
            NoArvore *temp = no->direito;
            free(no);
            return temp;
        } else if (no->direito == NULL) {
            NoArvore *temp = no->esquerdo;
            free(no);
            return temp;
        }

        NoArvore *temp = encontrarMinimo(no->direito);
        no->matricula = temp->matricula;
        strcpy(no->nome, temp->nome);
        no->direito = removerNo(no->direito, temp->matricula);
    }
    return no;
}

/**
 * @brief Lê as matrículas do arquivo e insere na árvore binária.
 */
void lerEInserirMatriculas(ArvoreBinaria *arvore, FILE *arquivoLista) {
    rewind(arquivoLista);  // Reposicionar para o início do arquivo
    long long int matricula;
    string nome;

    while (! feof(arquivoLista)) {  
        // Ler o nome
        fscanf(arquivoLista, " %99[^\n]s" , nome);
        // nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' do nome
        if (! feof(arquivoLista)) {  
            // Ler a matrícula
            fscanf(arquivoLista, "%lld" , &matricula);
            arvore->raiz = inserirNo(arvore->raiz, matricula, nome);  // Inserir na árvore binária
            arvore->tamanho++;
        }
    }
}

/**
 * @brief Inicializa o sistema, lendo dados e interagindo com o usuário.
 */
void iniciarCodigo(FILE *arquivoLista, ArvoreBinaria *arvore) {
    arquivoLista = abrirArquivo("nomes_matriculas.txt", "r");
    int totalMatriculas = contarMatriculas(arquivoLista);
    printf("Total de matrículas no arquivo: %d\n", totalMatriculas);
    rewind(arquivoLista); // Volta ao início do arquivo

    inicializarArvore(arvore);
    double inicio = clock();
    // Ler as matrículas e inseri-las na árvore
    lerEInserirMatriculas(arvore, arquivoLista);
    double fim = clock();
    fclose(arquivoLista);
    calcularTempo(inicio, fim);
    // Menu para interação
    menuPrincipal(arvore);

    // Salvar os dados antes de encerrar
    arquivoLista = abrirArquivo("nomes_matriculas.txt", "w");
    salvarDadosNoArquivo(arvore->raiz, arquivoLista);
    fclose(arquivoLista);

    // Liberar a memória
    liberarArvore(arvore->raiz);
}

/**
 * @brief Função principal.
 * @return 0 para indicar que o programa foi executado corretamente.
 */
int main() {
    FILE *arquivoLista;
    ArvoreBinaria arvore;
    iniciarCodigo(arquivoLista, &arvore);
    return 0;
}