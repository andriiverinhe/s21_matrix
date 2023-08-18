#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    if(!A->matrix) return FAILURE;
    if(!s21_create_matrix(A->columns, A->rows, result)) return FAILURE;
    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < A->columns; j++) {
            result->matrix[j][i] = A->matrix[i][j];
        }
    }
    return SUCCESS;
}