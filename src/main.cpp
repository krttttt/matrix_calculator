#include "matrix.h"
#include <iostream>

int main() {
    try {
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        A.data[0][0] = 1; A.data[0][1] = 2;
        A.data[1][0] = 3; A.data[1][1] = 4;
        B.data[0][0] = 5; B.data[0][1] = 6;
        B.data[1][0] = 7; B.data[1][1] = 8;

        std::cout << "Matrix A:\n";
        print_matrix(A);
        std::cout << "Matrix B:\n";
        print_matrix(B);

        Matrix sum = matrix_add(A, B);
        std::cout << "A + B:\n";
        print_matrix(sum);

        Matrix prod = matrix_multiply(A, B);
        std::cout << "A * B:\n";
        print_matrix(prod);
    std::cout << "\n Вариант 25: Матрица из одномерного массива\n";
    
    double arr[] = {1, 2, 3, 4, 5, 6};
    
    Matrix M = matrix_from_array(arr, 2, 3);
    
    std::cout << "Исходный массив: {1, 2, 3, 4, 5, 6}\n";
    std::cout << "Полученная матрица 2x3:\n";
    print_matrix(M);

        free_matrix(M);
        free_matrix(A);
        free_matrix(B);
        free_matrix(sum);
        free_matrix(prod);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}