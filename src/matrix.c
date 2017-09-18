/*                        ***** MODULO DE OPERAÇÕES COM MATRIZES*****

    FUNÇÕES: -----------------------------------------------------------------------------------|
    | Cofactor : retorna o cofator de um elemento da matriz. Opera em conjunto com determinative    |
    | Determinative: retorna o determinativee de uma matriz n x n. Opera em conjunto com Cofactor     |
    |---------------------------------------------------------------------------------------------|

    AUTOR: Bruno Soares Galdino
    DATA: 21/05/2017

*/

#include "../include/matrix.h"

double Cofactor(double *matrix,const int dimension,const double element,const int position_i,const int position_j)
{

    int i = 0,j = 0,k = 0; // indices para as matrizes
    double cofactor = 0.0;
    double auxiliar_matrix[ (dimension-1) * (dimension -1) ];// matriz auxiliar uma ordem menor que a original


    //copia elementos da matriz original para a auxiliar excluindo os da i-esima e j-esima linhas
    for(i = 0; i < dimension;i++) // opera nas linhas
    {
        if ( i+1 == (position_i) )
            continue;//ignora os elementos da i-esima linha da matriz

        for(j = 0; j < dimension; j++)// opera nas colunas
        {
        
            if ( j+1 == (position_j) )
                continue;//igonora os elementos da j-esima coluna da matriz
        
            auxiliar_matrix[k++] =  *(matrix + (i*dimension) + j);// copia os elemento de indices i e j da matrix original para a auxiliar 

        }

    }

    cofactor = pow(-1, (position_i+position_j) ) * Determinative(auxiliar_matrix,dimension-1);
    // o cofator de a(ij) eh dado por : -1^(i+j) * D(ij), em que D(ij) é o determinativee da matriz formada pelos
    // elementos da matriz original excluindo-se os da linha i e coluna j.

    return cofactor;

}

double Determinative(double *matrix,const int dimension)
{
    int j = 0;
    double determinative = 0.0;

    if( dimension == 2)
        determinative = ( *(matrix) * *(matrix+3) ) - ( *(matrix+1) * *(matrix+2) );
        //a diferenca entre o produto dos extremos e dos meios


    for( j = 0; j < dimension; j++)
        determinative += *(matrix+j) * Cofactor(matrix,dimension,*(matrix+j),1,j+1);
        // o determinativee eh dados pelo somatorio
        // dos produtos dos elementos, de uma linha ou //coluna, pelos seus respectivos cofactores

    return determinative;

}