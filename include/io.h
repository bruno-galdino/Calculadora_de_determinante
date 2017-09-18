

#ifndef IO_H
#define IO_H

#include <stdio.h>

enum {FALHA,SUCESSO};

int Dimensao(const char *nome);

FILE *AbreArquivo(const char *nome,const char *modo);
int FechaArquivo(FILE *file);

int LeMatriz(FILE *file,double *matriz,int dimensao);
int EscreveMatriz(FILE *file,double *matriz,int dimensao);

#endif