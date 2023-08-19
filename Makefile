# Настройки компилятора
CC = gcc
CFLAGS_COMMON = -Wall -Werror -std=c11
CFLAGS_COVERAGE = -fprofile-arcs -ftest-coverage --coverage
LIBS = -lcheck -lsubunit -lm -lgcov

# Директории
FUNCTION_DIR = function
TEST_DIR = test
OBJ_DIR = OBJ

# Исходные файлы
FUNCTION_SRCS = $(wildcard $(FUNCTION_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

# Объектные файлы для функций
FUNCTION_OBJS = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.o, $(FUNCTION_SRCS))
FUNCTION_OBJS_COV = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%_gcov.o, $(FUNCTION_SRCS))
FUNCTION_GCDA = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.gcda, $(FUNCTION_SRCS))
FUNCTION_GCOV_REPORT = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%_gcov_report, $(FUNCTION_SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
GCOV_OBJ = $(OBJ_DIR)/s21_test*.o

# Финальные библиотеки
LIBRARY = s21_string.a
LIBRARY_GCOV = s21_string_gcov.a

# Цели
.PHONY: all test clean gcov_report gcov_html

all: $(LIBRARY)

# Создание директории объектных файлов
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Компиляция исходных файлов функций для s21_string.a
$(OBJ_DIR)/%.o: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) -c $< -o $@

# Компиляция исходных файлов функций с флагами покрытия для s21_string_gcov.a
$(OBJ_DIR)/%_gcov.o: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(CFLAGS_COVERAGE) -c $< -o $@

# Компиляция исходных файлов функций с флагами покрытия для gcov_report
$(OBJ_DIR)/%.gcda: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(CFLAGS_COVERAGE) -c $< -o $@

# Компиляция исходных файлов тестов
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) -I$(FUNCTION_DIR) -c $< -o $@

# Компиляция файлов тестов для цели gcov_report
$(GCOV_OBJ): $(TEST_SRCS) | $(OBJ_DIR)
	$(foreach file,$(TEST_SRCS),$(CC) $(CFLAGS_COMMON) $(CFLAGS_COVERAGE) -I$(FUNCTION_DIR) -c $(file) -o $(OBJ_DIR)/$(notdir $(basename $(file))).o;)


# Создание статической библиотеки s21_string.a
$(LIBRARY): $(FUNCTION_OBJS)
	ar rcs $@ $(FUNCTION_OBJS)

# Создание статической библиотеки s21_string_gcov.a
$(LIBRARY_GCOV): $(FUNCTION_OBJS_COV)
	ar rcs $@ $(FUNCTION_OBJS_COV)

# Запуск тестов с использованием библиотеки check без флагов покрытия
test: CFLAGS := $(CFLAGS_COMMON)
test: $(LIBRARY) $(TEST_OBJS)
	$(CC) $(CFLAGS) -I$(FUNCTION_DIR) -o s21_test_string $(TEST_OBJS) -L. -l:s21_string.a $(LIBS)
	./s21_test_string

# Создание отчета о покрытии кода с использованием gcovr
gcov_report: CFLAGS := $(CFLAGS_COMMON) $(CFLAGS_COVERAGE)
gcov_report: $(LIBRARY_GCOV) $(FUNCTION_GCDA) $(GCOV_OBJ)
	$(CC) $(CFLAGS) -o s21_test_string $(GCOV_OBJ) -L. -l:s21_string_gcov.a $(LIBS)
	./s21_test_string
	~/.local/bin/gcovr -r . --html-details -o coverage_report.html

# Открытие отчета о покрытии кода в браузере
gcov_html: gcov_report
	xdg-open coverage_report.html

# Очистка объектных файлов, библиотек и отчетов
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.gcda
	rm -f $(OBJ_DIR)/*.gcno
	rm -f $(LIBRARY)
	rm -f $(LIBRARY_GCOV)
	rm -f $(FUNCTION_DIR)/*.o
	rm -rf s21_test_string
	rm -f *.html
	rm -f *.css
	rm -f *.gcda
	rm -f *.gcno
	clear
