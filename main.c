#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodo
{
    int valor;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

typedef struct
{
    Nodo *raiz;
} Arvore;

Arvore *reset(Arvore *arv);
void inserir(Nodo **nodo, Nodo *novoNodo);
int isAVL(Nodo *raiz);
void imprimir(Nodo *nodo);
struct Nodo *criarNodo(int valor);
void clear(Nodo *nodo);

int main()
{
    int op = 1;
    int tmpValor;
    Arvore *arv = reset(arv);

    do
    {
        printf("\nDigite um numero:\n");
        scanf("%d", &tmpValor);

        inserir(&(arv->raiz), criarNodo(tmpValor));

        printf("\n----------------\n");
        imprimir(arv->raiz);
        int avl = isAVL(arv->raiz);
        if (avl == 1)
        {
            printf("Arvore eh AVL.");
        }
        else
        {
            printf("Arvore nao eh AVL.");
        }
        printf("\n----------------\n");

        printf("\nContinuar inserindo valores na arvore?\n1 - Continuar\n0 - Parar\n");
        scanf("%d", &op);
    } while (op == 1);
    printf("\n----------------");
    imprimir(arv->raiz);
    int avl = isAVL(arv->raiz);
    if (avl == 1)
    {
        printf("Arvore eh AVL.");
    }
    else
    {
        printf("Arvore nao eh AVL.");
    }
    clear(arv->raiz);
    free(arv);
}

Nodo *criarNodo(int valor)
{
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (novoNodo == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    novoNodo->valor = valor;
    novoNodo->direita = NULL;
    novoNodo->esquerda = NULL;
    return novoNodo;
}

void inserir(Nodo **atual, Nodo *novoNodo)
{

    Nodo **temp = atual;
    if (*atual == NULL)
    {
        *atual = novoNodo;
    }
    else
    {
        while ((*atual))
        {
            if (novoNodo->valor > (*atual)->valor)
            {
                if ((*atual)->direita == NULL)
                {
                    (*atual)->direita = novoNodo;
                    break;
                }
                else
                {
                    atual = &(*atual)->direita;
                }
            }
            else
            {
                if ((*atual)->esquerda == NULL)
                {
                    (*atual)->esquerda = novoNodo;
                    break;
                }
                else
                {
                    atual = &(*atual)->esquerda;
                }
            }
        }
    }
}

void imprimir(Nodo *nodo)
{
    if (nodo)
    {
        imprimir(nodo->esquerda);
        printf("%d - ", nodo->valor);
        imprimir(nodo->direita);
    }
}

void clear(Nodo *nodo)
{
    if (nodo)
    {
        clear(nodo->esquerda);
        clear(nodo->direita);
        Nodo *temp = nodo;
        free(temp);
    }
}

int fb(Nodo *nodo)
{
    if (nodo == NULL)
        return 0;

    return 1 + fb(nodo->esquerda) - fb(nodo->direita);
}

int isAVL(Nodo *raiz)
{

    int d = 0;
    int e = 0;

    if (raiz == NULL)
        return 1;

    e = fb(raiz->esquerda);
    d = fb(raiz->direita);

    if (e - d <= 1 && isAVL(raiz->esquerda) && isAVL(raiz->direita))
        return 1;
    else
    {
        return 0;
    }
}

Arvore *reset(Arvore *arv)
{
    Arvore *novaArv = (Arvore *)(malloc(sizeof(Arvore)));
    novaArv->raiz = NULL;
    return novaArv;
}