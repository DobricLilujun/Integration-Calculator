#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

class Matrix
{
	public:
		int n_rows = 0;
		int n_cols = 0;
		double **data = NULL;

	public:
		Matrix(); 											
		Matrix(int m, int n); 								
		Matrix(const Matrix& A); 																															
		~Matrix(); 
		
		Matrix& operator =(const Matrix &A);
		Matrix friend operator  +(const Matrix &x,const Matrix &y);
		Matrix friend operator  -(const Matrix &x,const Matrix &y);
		Matrix friend operator  *(const Matrix &x,const Matrix &y);
		Matrix friend operator  *(float k,const Matrix &y);
		bool   friend operator ==(const Matrix &x,const Matrix &y);
		Matrix friend operator  ^(int &k,const Matrix &y);
};

void printMatrix(Matrix A);
void inputMatrix(Matrix& A);
Matrix transpose(Matrix A);
Matrix eye(int n);
Matrix scaleRow(double k, int row, Matrix A);
Matrix addScaleRow2Row(double k, int row_1, int row_2, Matrix A);
Matrix changeRow2Row(int a, int b, Matrix A);
Matrix produceMatrixEye(Matrix A);
Matrix inverse(Matrix A);
Matrix cutRowAndColumn(int a,int b,Matrix A);
double det(Matrix A);
Matrix permutation(int n);
Matrix G_S_ortho(Matrix A);
Matrix QrAlgorithm (Matrix A);
Matrix creat_Friend_Matrix_lengend(int k);
bool Judge(Matrix A);
Matrix indent(Matrix A);
Matrix Correction (Matrix A);
Matrix equation_two_unknowns (double a,double b,double c);
Matrix Findroots(Matrix friendMatrix);
Matrix find_root_legende(int n);
Matrix integration_polynomial(Matrix A);
Matrix derivation_polynomial(Matrix A,int n);
Matrix polynomial_legende (int k);
Matrix polynomial_laguerre (int k);
Matrix polynomial_Hermite(int k);
double value(Matrix A,double x);
double dichotomy (Matrix A,double left,double right);
Matrix find_root_laguerre(int n);
Matrix creat_Friend_Matrix_Hermite(int k);
Matrix find_root_Hermite(int n);
Matrix find_root_Chebyshev(int n);

#endif