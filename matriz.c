#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Matriz.h"


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

// void insere_valorLinha (MatrizEsparsa *m){
//     Lista coluna;
//     inicializa_lista(&coluna, sizeof(EntradaMatriz));
//     insere_inicio(&m->MultiLista,&coluna);
// }

/*Modificação dos dados de uma célula da matriz (set): dadas as coordenadas 
(linha e coluna) e o valor a ser armazenado.*/
// void set_valorMatrizEsparsa(){

// }

//Leitura os dados de uma célula da matriz (get)


