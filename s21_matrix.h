#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// PRECISION нужна для сравнения чисел
#define PRECISION 0.0000001
// Сравнение матриц (eq_matrix)
#define SUCCESS 1
#define FAILURE 0
// Все операции (кроме сравнения матриц) должны возвращать результирующий код:  
// - 0 - OK
// - 1 - Ошибка, некорректная матрица   
// - 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)
#define TRULY 0
#define INCORRECT 1
#define CALCULATION 2


typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

bool is_empty(matrix_t *matrix);
bool size_eq(matrix_t *A, matrix_t *B);


int s21_create_matrix(int rows, int columns, matrix_t *result);      // Создание матриц
void s21_remove_matrix(matrix_t *A);                                 // Очистка матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);                         // Сравнение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);      // Сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);      // Вычитание матриц
int s21_mult_number(matrix_t *A, double number, matrix_t *result);   // Умножение матрицы на число
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // Умножение двух матриц
int s21_transpose(matrix_t *A, matrix_t *result);                    // Транспонирование матрицы
int s21_calc_complements(matrix_t *A, matrix_t *result);             // Минор матрицы и матрица алгебраических дополнений 
int s21_determinant(matrix_t *A, double *result);                    // Определитель матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result);               // Обратная матрица

void s21_get_matrix_minor(const int rows_del, const int cols_del, const matrix_t *A, matrix_t *result);
double s21_rec_det(matrix_t *A);


// Напечатать матрицу
void s21_print_matrix(matrix_t *matrix);
void s21_matrix_set_value(matrix_t *matrix);