#pragma once
#include <check.h>
#include <unistd.h>

#include "../s21_matrix.h"

void run_tests();
void run_test_case(Suite *ptr_test);

Suite *test_transpose(void);
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_structure(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_inverse(void);
// Suite *test_helpers(void);
Suite *test_eq_matrix(void);
Suite *test_determenant(void);
Suite *test_calc_complements(void);