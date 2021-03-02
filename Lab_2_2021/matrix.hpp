#pragma once
#include <iostream>
using namespace std;
class Matrix
{
public:
    int** mtrx;
    Matrix(int n, int m);
    ~Matrix();
    int row_size();
    int coll_size();
    void kb_init();
    void rd_init();
    void output();
    void wr_res(const char* addr);
    Matrix operator * (const Matrix& B);
    void operator = (const Matrix& B);
private:
    int row;
    int col; 
};