#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_values = TRULY;
  if (is_empty(A)) return_values = INCORRECT;
  if (A->columns != A->rows && !return_values) return_values = CALCULATION;
  if (s21_create_matrix(A->rows, A->columns, result) && !return_values)
    return_values = INCORRECT;

  for (int i = 0; i < A->rows && !return_values; i++) {
    for (int j = 0; j < A->columns && !return_values; j++) {
      matrix_t minor = {0};
      double determinant = 0;
      return_values = s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
      if (!return_values) {
        s21_get_matrix_minor(i, j, A, &minor);
        return_values = s21_determinant(&minor, &determinant);
        result->matrix[i][j] = pow(-1, (i + j)) * determinant;
      }
      s21_remove_matrix(&minor);
    }
  }

  return return_values;
}