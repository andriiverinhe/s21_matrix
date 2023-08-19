#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_values = TRULY;  // 0 || 1 || 2

  if (is_empty(A) || is_empty(B)) return_values = INCORRECT;
  if (!size_eq(A, B) && !return_values) return_values = CALCULATION;
  if (!return_values &&
      s21_create_matrix(A->rows, A->columns, result) == INCORRECT)
    return_values = INCORRECT;

  for (int i = 0; i < A->rows && !return_values; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return return_values;
}