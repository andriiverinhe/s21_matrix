#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_values = 1;
  if (!is_empty(A)) {
    return_values = 2;
    if (A->rows == 1) {
      return_values = s21_create_matrix(A->rows, A->rows, result);
      if (return_values == 0) result->matrix[0][0] = 1.0 / A->matrix[0][0];
      return return_values;
    }
    double det = 0.0;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t tmp_calc = {0};
      return_values = s21_calc_complements(A, &tmp_calc);
      if (return_values == 0) {
        matrix_t tmp_trans = {0};
        return_values = s21_transpose(&tmp_calc, &tmp_trans);
        if (return_values == 0) {
          s21_mult_number(&tmp_trans, 1 / det, result);
        }
        s21_remove_matrix(&tmp_trans);
      }
      s21_remove_matrix(&tmp_calc);
    }
  }
  return return_values;
}