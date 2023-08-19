#include "../s21_matrix.h"

void s21_print_matrix(matrix_t *matrix) {
  printf("\nmatrix:\n\n");
  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      printf("%3f ", matrix->matrix[i][j]);
    }
    printf("\n\n");
  }
}

void s21_matrix_set_value(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = rand() % 10;  // Заполняем рандомным числом
    }
  }
}

bool is_empty(matrix_t *matrix) {
  bool empty = false;
  if (matrix->matrix == NULL) empty = true;
  return empty;
}

bool size_eq(matrix_t *A, matrix_t *B) {
  bool equals = false;
  if (A->rows == B->rows && A->columns == B->columns) equals = true;
  return equals;
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}