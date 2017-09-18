/*               @@@@MODULO PARA OPERAÇÕES DE LEITURA E ESCRITA DE MATRIZES EM ARQUIVOS@@@@@

    AUTOR: WAGNER BARBOSA

*/

#include "../include/io.h"

int Dimensao(const char *nome)
{

    int dimensao = 0;

    FILE *file = fopen(nome,"r");

    if(!file)
    {
        perror("erro ao abrir arquivo:");
        return FALHA;
    }
    
    if(!fscanf(file,"%d",&dimensao))
        return FALHA;

    fclose(file);

    return dimensao;
}

FILE *AbreArquivo(const char *nome,const char *modo)
{
    FILE *file = fopen(nome,modo);
    if(!file)
    {
        perror("Erro ao abrir arquivo:");
        return NULL;
    }
    
    return file;

}

int FechaArquivo(FILE *file)
{
    if(!file) 
        return FALHA;

    fclose(file);

    return SUCESSO;

}

int LeMatriz(FILE *file,double *matriz,int dimensao)
{
    int i = 0;
    
    if(!file)
        return FALHA;

    fscanf(file,"%lf",matriz);// ignora o primeiro numero

    for(i = 0; i < (dimensao*dimensao); i++) 
        if( !fscanf(file,"%lf",(matriz+i)) ) return FALHA;

    return SUCESSO;

}

int EscreveMatriz(FILE *file,double *matriz,int dimensao)
{
    int i = 0, quebra;// para organização da matriz na impressão

    if(!file)
        return FALHA;

    for(i = 0; i < (dimensao*dimensao);i++)
    {
        if(!fprintf(file," %.4lf",*(matriz+i)) )return FALHA;
        quebra++;

        if( !(quebra%dimensao) )
        {
            quebra = 0;
            if(!fprintf(file,"\n")) return FALHA;// organizacao espacial
        }
    }

    return SUCESSO;

}