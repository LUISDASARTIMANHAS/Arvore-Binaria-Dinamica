//Feito por: Lucas Garcia E Luis Augusto
#include "ArvoreBinariaDinamica.h"

//=================================================
FILE *abrirArquivo(char *nomeArq, char *modo) {
    FILE *arq = fopen(nomeArq, modo);
    if (arq == NULL) {
        printf("ERRO ao abrir o arquivo.\n");
        exit(-1);
    }
    printf("INFO: Arquivo Aberto! Bom uso.\n");
    return arq;
}

//=================================================
void calcularTempo(double ini, double fim) {
    double tempoDecorrido = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempoDecorrido);
}

//=================================================
void salvarDadosNoArquivo(NoArvore *no, FILE *arquivoLista) {
    if (no == NULL) return;

    // Salvar os dados em ordem
    salvarDadosNoArquivo(no->esquerdo, arquivoLista);
    fprintf(arquivoLista, "%s\n%lld\n", no->nome, no->matricula);
    salvarDadosNoArquivo(no->direito, arquivoLista);
}

//=================================================
void inicializarArvore(ArvoreBinaria *arvore) {
    arvore->raiz = NULL;
    arvore->tamanho = 0;
}

//=================================================
void liberarArvore(NoArvore *no) {
    if (no != NULL) {
        liberarArvore(no->esquerdo);
        liberarArvore(no->direito);
        free(no);
    }
}

//=================================================
void imprimirEmOrdem(NoArvore *no) {
    if (no == NULL) return;

    imprimirEmOrdem(no->esquerdo);
    printf("Matrícula: %lld, Nome: %s\n", no->matricula, no->nome);
    imprimirEmOrdem(no->direito);
}
//=================================================
long long int pedirOpcao() {
    int op;
    printf("\n--- Menu Principal ---\n");
    do {
        printf("1 - Inserir na Arvore\n");
        printf("2 - Exibir a Arvore\n");
        printf("3 - Excluir da Arvore\n");
        printf("4 - Pesquisar na Arvore\n");
        printf("5 - Total de Matriculas\n");
        printf("6 - Percorrer toda a Arvore\n");
        printf("7 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &op);
    } while ((op < 1) || (op > 7));
    return op;
}
//=================================================
long long int pedirNum(int caminhoASerEscolhido) {
    long long int num;
    if (caminhoASerEscolhido == 0) {
        printf("Digite um numero para ser inserido: ");
        scanf("%lld", &num);
    } else {
        printf("Digite um numero para ser excluido: ");
        scanf("%lld", &num);
    }
    return num;
}
//=================================================

//=================================================
void menuPrincipal(ArvoreBinaria *arvore) {
    long long int op, matricula;
    char nome[100];
    int repete = 0;
    do {
        op = pedirOpcao();
        switch (op) {
            case 1:
                printf("Digite o numero da matrícula: ");
                scanf("%lld", &matricula);
                printf("Digite o nome: ");
                getchar();  // Limpar buffer
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;  // Remover o '\n'
                arvore->raiz = inserirNo(arvore->raiz, matricula, nome);
                break;
            case 2:
                printf("\n\n===| Exibição da Árvore Binária (Em Ordem) |===\n\n");
                imprimirEmOrdem(arvore->raiz);
                break;
            case 3:
                printf("Digite o numero da matrícula para remover: ");
                scanf("%lld", &matricula);
                arvore->raiz = removerNo(arvore->raiz, matricula);
                break;
            case 4:
                printf("Digite o numero da matrícula para buscar: ");
                scanf("%lld", &matricula);
                buscarNo(arvore->raiz, matricula);
                break;
            case 5:
                printf("O total de matrículas na árvore é: %d\n", arvore->tamanho);
                break;
            case 6:
                repete = 1;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (repete == 0);
}
//=================================================
int contarMatriculas(FILE *arquivoLista) {
    char linha[100];
    int totalMatriculas = 0;
    while (fgets(linha, sizeof(linha), arquivoLista) != NULL) {
        totalMatriculas++;
    }
    return totalMatriculas / 2;  // Cada matrícula ocupa duas linhas (nome e matrícula)
}
//=================================================
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

//=================================================
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

//=================================================
NoArvore* encontrarMinimo(NoArvore *no) {
    while (no->esquerdo != NULL) no = no->esquerdo;
    return no;
}

//=================================================
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
//=================================================
void lerEInserirMatriculas(ArvoreBinaria *arvore, FILE *arquivoLista) {
    rewind(arquivoLista);  // Reposicionar para o início do arquivo
    long long int matricula;
    char nome[100];

    while (fgets(nome, sizeof(nome), arquivoLista) != NULL) {  // Ler o nome
        nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' do nome
        if (fscanf(arquivoLista, "%lld\n", &matricula) != EOF) {  // Ler a matrícula
            arvore->raiz = inserirNo(arvore->raiz, matricula, nome);  // Inserir na árvore binária
        }
    }
}
//=================================================
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
//=================================================
int main() {
    FILE *arquivoLista;
    ArvoreBinaria arvore;
    iniciarCodigo(arquivoLista,&arvore);
    return 0;
}
