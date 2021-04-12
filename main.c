#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Matriz.h"

int main(int argc, char const *argv[])
{
    MatrizEsparsa j;
    
    inicializa_MatrizEsparsa(&j,4,6);

    mostra_MatrizEsparsa(j);

    return 0;
}
