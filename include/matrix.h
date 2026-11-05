/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами (структура + базовые операции).
 * @author Катя
 * @version 0.1
 * @date 2026
 */

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief Структура матрицы.
 *
 * Хранит двумерный динамический массив и его размеры.
 * @warning Память освобождается через free_matrix().
 */
typedef struct {
    double** data;  ///< Указатель на двумерный массив.
    int rows;       ///< Количество строк.
    int cols;       ///< Количество столбцов.
} Matrix;

/**
 * @brief Создание матрицы заданного размера.
 *
 * @param rows Количество строк (> 0).
 * @param cols Количество столбцов (> 0).
 * @return Matrix Инициализированная нулями матрица.
 *
 * @exception std::invalid_argument Если rows <= 0 или cols <= 0.
 * @exception std::bad_alloc Если не удалось выделить память.
 *
 * @note Время выполнения: O(rows * cols).
 * @see free_matrix()
 *
 * @code
 * Matrix A = create_matrix(3, 3);
 * @endcode
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождение памяти, занятой матрицей.
 *
 * @param m Матрица, память которой нужно освободить.
 *
 * @note Безопасно вызывать для матрицы с data == nullptr.
 * @warning После вызова не используйте m (use-after-free).
 * @see create_matrix()
 */
void free_matrix(Matrix m);

/**
 * @brief Складывает две матрицы.
 * 
 * @param a Первая матрица.
 * @param b Вторая матрица.
 * @return Matrix Новая матрица, содержащая сумму A + B.
 * 
 * @exception std::invalid_argument Если матрицы невалидны или их размеры не совпадают.
 * @note Сложность: O(M * N).
 * @warning Результат необходимо освободить с помощью free_matrix().
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Перемножает две матрицы.
 * 
 * @param a Первая матрица размера M × N.
 * @param b Вторая матрица размера N × K.
 * @return Matrix Новая матрица размера M × K, содержащая произведение A * B.
 * 
 * @exception std::invalid_argument Если матрицы невалидны или количество
 * столбцов A не совпадает с количеством строк B.
 * @note Сложность: O(M * N * K). Используется порядок циклов i-k-j
 * для улучшения локальности доступа к памяти.
 * @warning Результат необходимо освободить с помощью free_matrix().
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Вывод матрицы в консоль.
 *
 * Форматирует числа с 2 знаками после запятой. Для больших матриц
 * (>10 строк или >8 столбцов) выводит сокращённый вид.
 *
 * @param m Матрица для вывода.
 */
void print_matrix(Matrix m);

/**
 * @brief Создание матрицы из одномерного массива (ВАРИАНТ 25).
 *
 * @param data Указатель на одномерный массив (длиной rows*cols).
 * @param rows Количество строк (> 0).
 * @param cols Количество столбцов (> 0).
 * @return Matrix Новая матрица с данными из массива.
 *
 * @exception std::invalid_argument Если размеры <= 0 или data == nullptr.
 * @warning Результат нужно освобождать через free_matrix().
 */
Matrix matrix_from_array(double* data, int rows, int cols);

#endif // MATRIX_H