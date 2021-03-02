#include "matrix.hpp"

Matrix::Matrix(int n, int m)
{
    mtrx = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mtrx[i] = new int [m];
    }
    row = n;
    col = m;
}

Matrix::~Matrix()
{
    for(int i = 0; i < col; i++)
    {
        delete[] mtrx[i];
    }
    delete[] mtrx;
}

int Matrix::row_size()
{
    return row;
}

int Matrix::coll_size()
{
    return col;
}

void Matrix::kb_init()
{
    for(int i_r = 0; i_r < row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            cin >> mtrx[i_r][i_c];
        }
    }
}

void Matrix::rd_init()
{
    for(int i_r = 0; i_r < row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            mtrx[i_r][i_c] = rand() % 9;
        }
    }
}

void Matrix::output()
{
    for(int i_r = 0; i_r < row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            cout << mtrx[i_r][i_c] << ' ';
        }
        cout << endl;
    }
}

Matrix Matrix::operator*(const Matrix& B)
{
    Matrix C(B.row,col);
    for(int i_r = 0; i_r < B.row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            for (int k = 0; k < col; k++)
            {
                C.mtrx[i_r][i_c] += mtrx[i_r][k] * B.mtrx[k][i_c];
            }
        }
    }
    return C;
}

void Matrix::operator = (const Matrix& B)
{
    for(int i_r = 0; i_r < B.row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            mtrx[i_r][i_c] = B.mtrx[i_r][i_c];
        }
    }
}

void Matrix::wr_res(const char* addr)
{
    FILE* aim = fopen(addr,"w");
    if(aim != nullptr)
    {
        for(int i_r = 0; i_r < row; i_r++)
    {
        for(int i_c = 0; i_c < col; i_c++)
        {
            fprintf(aim, "%i, ", mtrx[i_r][i_c]);
        }
        cout << endl;
    }
    }
}