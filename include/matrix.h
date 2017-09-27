/*                           ***** MODULO DE OPERAÇÕES COM MATRIZES*****

    FUNÇÕES: -----------------------------------------------------------------------------------|
    | Cofactor : retorna o cofator de um elemento da matriz. Opera em conjunto com Determinant    |
    | Determinant: retorna o determinante de uma matriz n x n. Opera em conjunto com Cofactor     |
    |---------------------------------------------------------------------------------------------|

    AUTOR: Bruno Soares Galdino
    DATA: 21/05/2017

*/

#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>

double Cofactor( double *matrix,const int dimension,const  double element, const int position_i, const int position_j);
double Determinant( double *matrix,const int dimension);

#endif