#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int mat_eq = SUCCESS;
    if(is_empty(A) || is_empty(B)) mat_eq = FAILURE;
    if(!size_eq(A, B)) mat_eq = FAILURE;
    
    bool succese = true;
    if(mat_eq == FAILURE) succese = false;

    for(int i = 0; i < A->rows && succese; i++) {
        for(int j = 0; j < A->columns && succese; j++) {

           if(fabsl(A->matrix[i][j] - B->matrix[i][j]) > PRECISION) {
            succese = false;
           }
        }
    }

    return succese? SUCCESS : FAILURE;
}