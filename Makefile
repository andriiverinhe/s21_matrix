# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lcheck -lrt -lsubunit -pthread

# Директории
FUNCTION_DIR = function
TEST_DIR = test
OBJ_DIR = OBJ

# Файлы
HEADER = s21_matrix.h
FUNCTION_FILES = $(wildcard $(FUNCTION_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
OBJ_FILES = $(patsubst $(FUNCTION_DIR)/%.c,$(OBJ_DIR)/%.o,$(FUNCTION_FILES))
.PHONY: all test clean rebuild

all: s21_matrix.a

s21_matrix.a: $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(FUNCTION_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f s21_matrix.a $(TEST_DIR)/test_executable $(OBJ_DIR)/*.o
	rm -rf s21_test
	clear
	
rebuild: clean all

valgrind: test
	valgrind --tool=memcheck --leak-check=yes s21_test

test: s21_test
	./s21_test

s21_test: $(TEST_FILES) s21_matrix.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -lm