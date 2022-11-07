#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int valor;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

typedef struct
{
    int qtdNodo;
    Nodo *raiz;
} Arvore;

Arvore *reset(Arvore *arv);
void inserir(Nodo **nodo, Nodo *novoNodo);
void isAVL(Nodo **direita, Nodo **esquerda);
void imprimir(Nodo *nodo);
Nodo *criarNodo(int valor);

int main()
{
    int op = 1, tmpValor;

    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));

    arv = reset(arv);

    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &tmpValor);

        inserir(&(arv->raiz), criarNodo(tmpValor));

        printf("Continuar inserindo valores na arvore?\n1 - Continuar\n0 - Parar\n");
        scanf("%d", &op);

    } while (op == 1);
    // imprimir(arv->raiz);
    isAVL(&(arv->raiz), &(arv->raiz));

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
    if (*temp == NULL)
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
        printf("%d, ", nodo->valor);
        imprimir(nodo->direita);
    }
}

void isAVL(Nodo **esquerda, Nodo **direita)
{
    int d = 0;
    int e = 0;
    while (*direita)
    {
        direita = &(*direita)->direita;
        d++;
    }

    while (*esquerda)
    {
        esquerda = &(*esquerda)->esquerda;
        e++;
    }

    if (d - e > 1)
    {
        printf("Arvore não é AVL.");
    }
    else
    {
        printf("Arvore é AVL.");
    }
}

Arvore *reset(Arvore *arv)
{
    Arvore *novaArv;
    novaArv->qtdNodo = 0;
    novaArv->raiz = NULL;
    return novaArv;
}