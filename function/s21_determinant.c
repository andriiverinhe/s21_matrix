#include "../s21_matrix.h"
// rows_del - строка которую нужно убрать
// cols_del - столбец который нужно убрать
// A        - матрица из которой берем значения
// result   - матрица куда записываем

void s21_get_matrix_minor(const int rows_del, const int cols_del, const matrix_t *A, matrix_t *result) {
    int res_rows = 0;
    int res_cols = 0;

    for(int i = 0; i < A->rows;i++){
        if(i == rows_del) continue;
        res_cols = 0;
        for(int j = 0; j < A->columns; j++) {
            if(j == cols_del) continue;
            result->matrix[res_rows][res_cols] = A->matrix[i][j];
            res_cols++;
        }
        res_rows++;
    }

}

double s21_rec_det(matrix_t *A) {
    double result = 0.0;
    if(A->rows == 1) result = A->matrix[0][0];
    else{
        matrix_t minor = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for(int i = 0; i < A->columns; i++) {

            s21_get_matrix_minor(0, i , A, &minor);
            if(i % 2) {
                result -= A->matrix[0][i] * s21_rec_det(&minor);
            } else {
                result += A->matrix[0][i] * s21_rec_det(&minor);
            }
        }

        s21_remove_matrix(&minor);

    }
    return result;
}

int s21_determinant(matrix_t *A, double *result) {
    if(!A->matrix) return FAILURE;
    if(A->rows != A->columns) return FAILURE;

    *result = s21_rec_det(A);

    return SUCCESS;
}   
