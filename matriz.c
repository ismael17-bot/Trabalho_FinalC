#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Matriz.h"

#define ERRO_POS_INVALIDA_Matriz_esparsa -2
#define ERRO_VAZIA_Matrizesparsa -1 
//Inicialização
void inicializa_MatrizEsparsa (MatrizEsparsa *m , int NumColunas, int linhas){
    inicializa_lista(&(m->MultiLista), sizeof(Lista));
    m->NumColunas = NumColunas;
    Lista linha;
    for (int i = 0; i < linhas; i++)
    {
        inicializa_lista(&linha, sizeof(EntradaMatriz));
        insere_fim(&m->MultiLista,&linha);
    }
}


//Impressão na tela
void mostra_MatrizEsparsa(MatrizEsparsa  m){
    int linhas = conta_elementos(m.MultiLista);
    Lista auxiliar;
    EntradaMatriz auxi;
    for (int i = 0; i < linhas; i++){
        le_valor(m.MultiLista,&auxiliar,i);
        for( int o=0;o<conta_elementos(auxiliar);o++){ 
            le_valor(auxiliar,&auxi,o);
            for (int j = 0; i < m.NumColunas; j++){
                printf("0\t");
            }   
            printf("%d\t",auxi.info);
        }
        for (int i = 0; i < m.NumColunas; i++)
        {
             printf("0\t");
        }
        printf("\n\t");
    }
}


/*Modificação dos dados de uma célula da matriz (set): dadas as coordenadas 
(linha e coluna) e o valor a ser armazenado.*/
int set_valorMatrizEsparsa(MatrizEsparsa *m,int linha ,int coluna,int valor){
    if(valor==0)
        return excluir_valor_matriz_esparsa(m,linha,coluna);

    int linhas = conta_elementos(m->MultiLista);

    for (; linhas<=linha; linhas++){
        inserir_linha_matriz_esparsa(m);
    }

    int j = 0;
    Lista aux;
    EntradaMatriz auxVl;
    le_valor(m->MultiLista,&aux,linha);
    
    j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    if(j!=ERRO_VAZIA_Matrizesparsa){
        le_valor(aux,&auxVl,j);
        auxVl.info = valor;
        j = modifica_valor(aux,&auxVl,j);
    }else{
        auxVl.coluna = coluna;
        auxVl.info = valor;
        j = insere_ordem(&aux,&auxVl,compararValorMatriz);
    }
    if(j!=1)
        return ERRO_POS_INVALIDA_Matriz_esparsa;
    modifica_valor(m->MultiLista,&aux,linha);
    
    return 1;
return 1;
}

int compararValorMatriz(void *vl1,void *vl2){
    EntradaMatriz *valor1 = (EntradaMatriz*) vl1,*valor2 = (EntradaMatriz*) vl2;
    return valor1->coluna - valor2->coluna;
}


void inserir_linha_matriz_esparsa(MatrizEsparsa *m){
    Lista coluna;
    inicializa_lista(&coluna,sizeof(EntradaMatriz));
    insere_fim(&m->MultiLista,&coluna);
}

int BuscaPosição(MatrizEsparsa m, int linha, int coluna){
    int j = 0;
    Lista aux;
    EntradaMatriz auxVl = {-1,-1};
    int colunas = conta_elementos(aux);
    if(colunas!=0)
        for (; j < colunas && auxVl.coluna<coluna; j++){
            le_valor(aux,&auxVl,j);
            if(coluna==auxVl.coluna){
                return j;
            }
        }
    return -1;
}

//Leitura os dados de uma célula da matriz (get)
int getValorCelula(MatrizEsparsa *m,int linha,int coluna, int *valor){
    int j = BuscaPosição(*m,linha,coluna);
    if(j!=ERRO_VAZIA_Matrizesparsa){
        Lista aux;
        EntradaMatriz auxiliar;
        le_valor(m->MultiLista,&aux,linha);
        le_valor(aux,&auxiliar,j);
        *valor = auxiliar.info;
    return 1;
}
