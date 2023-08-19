#include "../s21_matrix.h" 

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if(rows < 1 || columns < 1 || result == NULL) return INCORRECT;

    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **) calloc(rows, sizeof(double *));
    if(!result->matrix) return INCORRECT;
    for(int i = 0; i < rows; i++) {
        result->matrix[i] = (double *) calloc(columns, sizeof(double));
    }

    return result->matrix == NULL? INCORRECT : TRULY;
}

void s21_remove_matrix(matrix_t *A) {
    if(!is_empty(A)){ 
    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);
    }
}