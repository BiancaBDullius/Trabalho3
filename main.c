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
int altura(Nodo *pRaiz);

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

int altura(Nodo *raiz)
{
    int e, d;
    if (raiz == NULL)
        return 0;
    e = altura(raiz->esquerda);
    d = altura(raiz->direita);
    if (e > d)
        return e + 1;
    else
        return d + 1;
}

int isAVL(Nodo *raiz)
{

    int fb;

    if (raiz == NULL)
        return 1;

    if (!isAVL(raiz->esquerda))
        return 0;
    if (!isAVL(raiz->direita))
        return 0;

    fb = altura(raiz->esquerda) - altura(raiz->direita);
    if ((fb > 1) || (fb < -1))
        return 0;
    else
        return 1;
}

Arvore *reset(Arvore *arv)
{
    Arvore *novaArv = (Arvore *)(malloc(sizeof(Arvore)));
    novaArv->raiz = NULL;
    return novaArv;
}