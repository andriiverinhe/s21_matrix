#include "../s21_matrix.h"

int main() {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    int res_value = -1;
    // double res = 0;
    int cols = 3;
    int rows = 3;
    
    s21_create_matrix(rows, cols , &A);
    s21_create_matrix(cols, cols , &B);
    // s21_create_matrix(rows, cols , &result);
    
    srand(time(NULL));
    s21_matrix_set_value(&A);
    // srand(time(NULL));

    s21_matrix_set_value(&B);
    
    printf("matrix A\n");
    s21_print_matrix(&A);
    printf("matrix B\n");
    s21_print_matrix(&B);

// if(s21_eq_matrix(&A, &B)) printf("матрицы равны\n");
// else printf("матрицы не равны\n");
    res_value = s21_sum_matrix(&A, &B, &result);
    
    // s21_sub_matrix(&A, &B, &result);
    // s21_mult_number(&A, 12.3, &result);
    // s21_mult_matrix(&A, &B, &result);
    // s21_transpose(&A, &result);
    // s21_determinant(&A, &res);
    // printf("res = %f\n", res);
    // s21_calc_complements(&A, &result);
    printf("matrix result\n");
    s21_print_matrix(&result);
    printf("res_value: %d\n", res_value);


    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
}