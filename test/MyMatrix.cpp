#include "MyMatrix.h"
#include "stdlib.h"
//如果不写的话，是无法解析得到默认构造函数的
Matrix::Matrix(){
	//nothing
};

Matrix::Matrix(int mm, int nn)//构造函数
{
	m = mm;
	n = nn;
	int i, j;
	data = new double*[mm];
	for (i = 0; i<mm; i++)
		data[i] = new double[nn];
	for (i = 0; i<m; i++)//矩阵所有元素清零
	for (j = 0; j<n; j++)
		data[i][j] = 0.0;
} //构造M行N列的矩阵

Matrix::Matrix(const Matrix &src) //拷贝构造函数
{
	m = src.m;
	n = src.n;
	int i, j;
	data = new double*[m];//动态建立二维数组
	for (i = 0; i<m; i++)
		data[i] = new double[n];
	for (i = 0; i<m; i++)//动态数组赋值
	for (j = 0; j<n; j++)
		data[i][j] = src.data[i][j];
}

Matrix::~Matrix()//析构函数
{
	for (int i = 0; i<m; i++)
		delete[]data[i];
	delete[]data;
}

void Matrix::setInit(int mm, int nn){
	m = mm;
	n = nn;
	int i, j;
	data = new double*[mm];
	for (i = 0; i<mm; i++)
		data[i] = new double[nn];
	for (i = 0; i<m; i++)//矩阵所有元素清零
	for (j = 0; j<n; j++)
		data[i][j] = 0.0;
}

Matrix& Matrix::operator=(const Matrix &src) //重载"="运算符
{
	int i, j;
	for (i = 0; i<m; i++)
		delete[]data[i];
	delete[]data;
	m = src.m; n = src.n;
	data = new double*[m];//动态建立二维数组
	for (i = 0; i<m; i++)
		data[i] = new double[n];
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		data[i][j] = src.data[i][j];
	return *this;
}

//矩阵*运算符重载
Matrix Matrix::operator *(const Matrix &m2)//矩阵乘法的实现
{
	Matrix m3(this->m, m2.n);
	if (this->n != m2.m)
	{
		cout << "两矩阵无法进行乘法运算.\n" << endl;
		exit(0);
	}
	int i, j, k;
	for (i = 0; i<this->m; i++)
	for (j = 0; j<m2.n; j++)
	{
		for (k = 0; k<this->n; k++)
		{
			m3.data[i][j] += this->data[i][k] * m2.data[k][j];
		}
	}
	return m3;
}

//输入矩阵元素
void Matrix::input()
{
	for (int i = 0; i<m; i++)
	for (int j = 0; j<n; j++)
		cin >> data[i][j];
}

//显示矩阵元素
void Matrix::display()
{
	int i, j;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}