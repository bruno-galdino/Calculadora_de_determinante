
#include "../include/io.h"
#include "../include/matrix.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{



    if(argc < 2)
    {
        printf("Uso: %s <file_in> <file_out> ou %s <file_in>",*argv,*argv);
        return EXIT_SUCCESS;
    }


    FILE *file_in = AbreArquivo(argv[1],"r");

    if(!file_in) 
    {
        fputs("Erro ao abrir arquivdo de entrada",stderr);
        return EXIT_FAILURE;
    }

    
    int dimensao = Dimensao( file_in );
    
    if(!dimensao)
        return 	EXIT_FAILURE;

    
    double matriz[dimensao*dimensao];
    
    double determinant;

    if( !(LeMatriz(file_in,matriz,dimensao)) )
        return EXIT_FAILURE;
    
    
    if( !( FechaArquivo(file_in) ) )
        return EXIT_FAILURE;

    determinant = Determinant(matriz,dimensao);

    if(argc > 2)// saida em arquivo
    {

        FILE *file_out = AbreArquivo(argv[2],"w");

        if(!file_out) 
        {
            fputs("Erro ao abrir arquivo de saida",stderr);
            return EXIT_FAILURE;
        }

        fprintf(file_out,"%.2lf",determinant);
        FechaArquivo(file_out);

    }

    else
        printf("%.2lf",determinant);// saida pelo console

    return EXIT_SUCCESS;
}