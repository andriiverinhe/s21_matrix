#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if(!A->matrix || !B->matrix) return FAILURE;
    if(A->rows != B->rows || A->columns != B->columns) return FAILURE;
    if(!s21_create_matrix(A->rows, A->columns, result)) return FAILURE;

    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    } 
    return SUCCESS;
}