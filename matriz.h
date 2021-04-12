

typedef struct {
     Lista MultiLista;
     int NumColunas;
} MatrizEsparsa;

typedef struct {
     int coluna;
     int info;
} EntradaMatriz;



void inicializa_MatrizEsparsa (MatrizEsparsa *m , int NumColunas, int linhas );
void mostra_MatrizEsparsa(MatrizEsparsa m);
// void insere_valorLinha (MatrizEsparsa *m);
