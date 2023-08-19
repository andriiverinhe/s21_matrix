# Compiler settings
CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Directories
SRC_DIR = .
FUNCTION_DIR = $(SRC_DIR)/function
OBJ_DIR = $(SRC_DIR)/OBJ

# Source files
FUNCTION_SRCS = $(wildcard $(FUNCTION_DIR)/*.c)

# Object files
FUNCTION_OBJS = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.o, $(FUNCTION_SRCS))

# Final library
LIBRARY = $(SRC_DIR)/s21_matrix.a

# Targets
.PHONY: all test gcov_report clean

all: $(LIBRARY)

$(OBJ_DIR)/%.o: $(FUNCTION_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(FUNCTION_OBJS)
	ar rcs $@ $(FUNCTION_OBJS)

test: CFLAGS += -I$(SRC_DIR)
test: LIBS = -lcheck -lsubunit -lm
test: $(LIBRARY)
	$(CC) $(CFLAGS) -o $(SRC_DIR)/s21_test_matrix test/s21_test.c $(LIBRARY) $(LIBS)
	$(SRC_DIR)/s21_test_matrix

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LIBRARY = $(SRC_DIR)/s21_matrix_gcov.a
gcov_report: $(LIBRARY)
	$(CC) $(CFLAGS) -o $(SRC_DIR)/s21_test_matrix_gcov test/s21_test.c $(LIBRARY) $(LIBS)
	$(SRC_DIR)/s21_test_matrix_gcov
	gcovr -r $(FUNCTION_DIR) --html-details -o $(SRC_DIR)/coverage_report.html

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(SRC_DIR)/s21_matrix.a
	rm -f $(SRC_DIR)/s21_matrix_gcov.a
	rm -f $(SRC_DIR)/s21_test_matrix
	rm -f $(SRC_DIR)/s21_test_matrix_gcov
	rm -f $(SRC_DIR)/*.gcda
	rm -f $(SRC_DIR)/*.gcno
	rm -f $(SRC_DIR)/coverage_report.html
	clear
