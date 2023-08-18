#include "../s21_matrix.h" 

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if(rows < 1 || columns < 1 || result == NULL) return INCORRECT;

    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **) calloc(rows, sizeof(double *));
    for(int i = 0; i < rows; i++) {
        result->matrix[i] = (double *) calloc(columns, sizeof(double));
    }

    return TRULY;
}

void s21_remove_matrix(matrix_t *A) {
    if(A->matrix){ 
    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);
    }
}