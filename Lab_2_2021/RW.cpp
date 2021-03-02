/*
Даны два файла целых чисел, содержащие элементы матрицы A размерности n x n и 
B размерности n x 1 по строкам, 
причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. 
Создать файл той же структуры с именем C, содержащий произведение матриц А и В.
*/
// Start g++ Tsk1.cpp matrix.cpp -o res1 && ./res1

#include "matrix.hpp"
#include <cstdio>

int main()
{
    Matrix A(3,3), B(3,3);
    A.rd_init();
    A.output();
    A.wr_res("matrixA.txt");
    B.rd_init();
    B.output();
    B.wr_res("matrixB.txt");
    B = A * B; 
    B.output();
    B.wr_res("matrixC.txt");
    return 0;
}

