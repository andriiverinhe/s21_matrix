#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {

    if(!A->matrix) return FAILURE;
    if(A->columns != A->rows) return FAILURE;
    if(!s21_create_matrix(A->rows, A->columns, result)) return FAILURE;
    
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double determinant = 0;
          s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
          s21_get_matrix_minor(i, j, A, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant;
          s21_remove_matrix(&minor);
        }
      }

      return SUCCESS;
}