

typedef struct {
     Lista MultiLista;
     int NumColunas;
} MatrizEsparsa;

typedef struct {
     int coluna;
     int info;
} EntradaMatriz;

/*
void inicializa_matriz( Matriz_esparca *m);ok
int insere_valor(Matriz_esparca *m, int l, int c, int val);
int get_valor_celula(Matriz_esparca m, int l, int c);
Matriz_esparca soma_matrizes(Matriz_esparca m1, Matriz_esparca m2);
void desaloca_matriz(Matriz_esparca *m);
void imprimi_matriz(Matriz_esparca m);ok
int matriz_vazia(Matriz_esparca m);
*/

void inicializa_MatrizEsparsa (MatrizEsparsa *m , int NumColunas, int linhas );
void mostra_MatrizEsparsa(MatrizEsparsa m);
int getValorCelula(MatrizEsparsa *m,int linha,int coluna, int *valor);
int BuscaPosição(MatrizEsparsa m,int linha,int coluna);

// void insere_valorLinha (MatrizEsparsa *m);
int compararValorMatriz(void *vl1,void *vl2);