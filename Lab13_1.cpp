#include <iostream>
#include <string>
#include <tuple>
using namespace std;

struct matrix
{
	size_t line;
	size_t collum;
	int** field;
};

bool bigger(int a, int b)
{
	return a > b;
}

bool smaller(int a, int b)
{
	return a < b;
}

bool same(int a, int b)
{
	return a == b;
}

void create(matrix variable)
{
	for (size_t idx = 0; idx < variable.collum; idx++)
	{
		variable.field[idx] = new int[variable.line];
	}
}

void init(matrix variable)
{
	for (size_t idx_l = 0; idx_l < variable.collum; idx_l++)
	{
		for (size_t idx_c = 0; idx_c < variable.line; idx_c++)
		{
			variable.field[idx_l][idx_c] = rand() % 5;
		}
	}
}

void outp(matrix variable)
{
	for (size_t idx_l = 0; idx_l < variable.collum; idx_l++)
	{
		for (size_t idx_c = 0; idx_c < variable.line; idx_c++)
		{
			cout << variable.field[idx_l][idx_c] << ' ';
		}
		cout << endl;
	}
}

tuple<int, int, int> check(matrix A, matrix B)
{
	int a = 0;
	int b = 0;
	int c = 0;
	for (size_t idx_l = 0; idx_l < A.collum; idx_l++)
	{
		for (size_t idx_c = 0; idx_c < A.line; idx_c++)
		{
			if (same(A.field[idx_l][idx_c], B.field[idx_l][idx_c])) b++;
			else if (smaller(A.field[idx_l][idx_c], B.field[idx_l][idx_c])) a++;
			else if (bigger(A.field[idx_l][idx_c], B.field[idx_l][idx_c])) c++;
		}
	}
	return { a, b, c };
}

int main()
{
	srand(time(0));
	matrix A;
	matrix B;
	cout << "Input your matrix size m and n: ";
	cin >> A.line;
	cin >> A.collum;
	A.field = new int* [A.collum];
	create(A);
	init(A);
	B.line = A.line;
	B.collum = A.collum;
	B.field = new int* [B.collum];
	create(B);
	init(B);
	outp(A);
	cout << endl;
	outp(B);
	auto res = check(A, B);
	cout << "a= " << get<0>(res)<< ' '  << "b= " << get<1>(res) << ' '<< "c= " << get<2>(res);
}