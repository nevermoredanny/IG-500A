#include"stdafx.h"
#include "MyMatrix.h"

//�����д�Ļ������޷������õ�Ĭ�Ϲ��캯����
Matrix::Matrix(){
	//nothing
};

Matrix::Matrix(int mm, int nn)//���캯��
{
	m = mm;
	n = nn;
	int i, j;
	data = new double*[mm];
	for (i = 0; i<mm; i++)
		data[i] = new double[nn];
	for (i = 0; i<m; i++)//��������Ԫ������
	for (j = 0; j<n; j++)
		data[i][j] = 0.0;
} //����M��N�еľ���

Matrix::Matrix(const Matrix &src) //�������캯��
{
	m = src.m;
	n = src.n;
	int i, j;
	data = new double*[m];//��̬������ά����
	for (i = 0; i<m; i++)
		data[i] = new double[n];
	for (i = 0; i<m; i++)//��̬���鸳ֵ
	for (j = 0; j<n; j++)
		data[i][j] = src.data[i][j];
}

Matrix::~Matrix()//��������
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
	for (i = 0; i<m; i++)//��������Ԫ������
	for (j = 0; j<n; j++)
		data[i][j] = 0.0;
}

Matrix& Matrix::operator=(const Matrix &src) //����"="�����
{
	int i, j;
	for (i = 0; i<m; i++)
		delete[]data[i];
	delete[]data;
	m = src.m; n = src.n;
	data = new double*[m];//��̬������ά����
	for (i = 0; i<m; i++)
		data[i] = new double[n];
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		data[i][j] = src.data[i][j];
	return *this;
}

//����*���������
Matrix Matrix::operator *(const Matrix &m2)//����˷���ʵ��
{
	Matrix m3(this->m, m2.n);
	if (this->n != m2.m)
	{
		cout << "�������޷����г˷�����.\n" << endl;
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

//�������Ԫ��
void Matrix::input()
{
	for (int i = 0; i<m; i++)
	for (int j = 0; j<n; j++)
		cin >> data[i][j];
}

//��ʾ����Ԫ��
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