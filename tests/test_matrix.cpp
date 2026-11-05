#include <gtest/gtest.h>
#include "matrix.h"
#include <stdexcept>

// 
// 1. ТЕСТЫ create_matrix
//
TEST(MatrixTest, CreateMatrix_NormalCase) {
    Matrix A = create_matrix(3, 4);
    
    EXPECT_EQ(A.rows, 3);
    EXPECT_EQ(A.cols, 4);
    EXPECT_NE(A.data, nullptr); // Память выделена
    
    // Проверяем, что матрица заполнена нулями
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            EXPECT_DOUBLE_EQ(A.data[i][j], 0.0);
        }
    }
    free_matrix(A);
}

TEST(MatrixTest, CreateMatrix_InvalidArgs) {
    // Проверяем, что при некорректных размерах выбрасывается исключение
    EXPECT_THROW(create_matrix(0, 3), std::invalid_argument);
    EXPECT_THROW(create_matrix(3, -1), std::invalid_argument);
}

// 
// 2. ТЕСТЫ matrix_add
// 
TEST(MatrixTest, Addition_NormalCase) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    // Заполняем A = [1, 2; 3, 4]
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    // Заполняем B = [5, 6; 7, 8]
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_add(A, B);

    // Ожидаем C = [6, 8; 10, 12]
    EXPECT_DOUBLE_EQ(C.data[0][0], 6.0);
    EXPECT_DOUBLE_EQ(C.data[0][1], 8.0);
    EXPECT_DOUBLE_EQ(C.data[1][0], 10.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 12.0);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

TEST(MatrixTest, Addition_SizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    
    // Складывать матрицы разных размеров нельзя
    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);

    free_matrix(A);
    free_matrix(B);
}

// 
// 3. ТЕСТЫ matrix_multiply
// 
TEST(MatrixTest, Multiplication_NormalCase) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    Matrix C = matrix_multiply(A, B);

    // Ожидаем C = [19, 22; 43, 50]
    EXPECT_DOUBLE_EQ(C.data[0][0], 19.0);
    EXPECT_DOUBLE_EQ(C.data[0][1], 22.0);
    EXPECT_DOUBLE_EQ(C.data[1][0], 43.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 50.0);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
}

// 
// 4. ТЕСТЫ ВАРИАНТА 25 (matrix_from_array)
//
TEST(MatrixTest, FromArray_NormalCase) {
    double arr[] = {1, 2, 3, 4, 5, 6};
    Matrix M = matrix_from_array(arr, 2, 3);

    // Проверяем размеры
    EXPECT_EQ(M.rows, 2);
    EXPECT_EQ(M.cols, 3);

    // Проверяем элементы
    EXPECT_DOUBLE_EQ(M.data[0][0], 1.0);
    EXPECT_DOUBLE_EQ(M.data[0][1], 2.0);
    EXPECT_DOUBLE_EQ(M.data[0][2], 3.0);
    EXPECT_DOUBLE_EQ(M.data[1][0], 4.0);
    EXPECT_DOUBLE_EQ(M.data[1][1], 5.0);
    EXPECT_DOUBLE_EQ(M.data[1][2], 6.0);

    free_matrix(M);
}

TEST(MatrixTest, FromArray_NullPointer) {
    // Проверяем, что если передать пустой указатель, будет ошибка
    EXPECT_THROW(matrix_from_array(nullptr, 2, 2), std::invalid_argument);
}