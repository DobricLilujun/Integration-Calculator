#include <stdio.h>
#include <iostream>
#include "matrix.h"
#include "matrix.cpp"
#include "function.cpp"
using namespace std;

Matrix special_Matrix(double(*func)(double x,double t),double a,double b,int n)
{
	Matrix roots = find_root_legende(n);
	Matrix coeff = Matrix(1,n);
	double p = (b-a)/2.0;
	double q = (b+a)/2.0;
	Matrix result = Matrix(n,n);

	for(int i = 0 ;i < n ;i++)
	{
		coeff.data[0][i] = 2.0/((1.0-pow(roots.data[0][i],2))*pow((value(  derivation_polynomial( polynomial_legende(n),1),roots.data[0][i])),2));
	}

	for(int i = 0 ; i < n; i++)
	{
		for(int  j = 0; j < n;j++)
		{
			 result.data[i][j] = p*coeff.data[0][j]*(*func)(p*roots.data[0][i]+q, p*roots.data[0][j] + q);
		}
	}
	return result;
}
Matrix row_reduction(Matrix A)
{
	int m = A.n_rows;
	int n = m;
	for(int i = 0; i < m; i++)
	{
		int j=0;
		int h = i;
		int flag=h;
		double max =A.data[i][h] ;
		for(h=h+1; h < n;h++)
		{
			if(fabs(max)<fabs(A.data[h][i]))
			{
				max=A.data[h][i];
				flag = h;
			}
		}
		if(fabs(max)<1e-4)
		{
			continue;
		}
		A=changeRow2Row(i+1,flag+1,A);
		for(; j < n; j ++)
		{
			if(A.data[i][j]!=0)
			{
				break;
			}
		}
		if(j==n)
		{
			continue;	
		}
		A=scaleRow(1.0/A.data[i][j],i+1,A);
		for(int k = 0; k < m; k ++)
		{
			if(k==i)continue;
			if(fabs(A.data[k][j])<=1e-6)
			{
				continue;
			}
			else
			{
				A=addScaleRow2Row(-A.data[k][j],i+1,k+1,A);
				A= Correction(A);
			}	
		}
	}
	return A;
}

Matrix eigenvalue(double(*func)(double x,double t),double a,double b,int n)
{
	Matrix result(n,n);
	Matrix special =special_Matrix(func,a,b,n);
	Matrix eigenvalues = Findroots(special);
	return eigenvalues;
}
Matrix proper_vector(double(*func)(double x,double t),double a,double b,int n)
{
	Matrix result(n,n);
	Matrix special =special_Matrix(func,a,b,n);
	Matrix eigenvalues =eigenvalue(func,a,b,n);
	eigenvalues = Correction(eigenvalues);
	for(int i = 0 ; i < n;i++)
	{
		double lambda = eigenvalues.data[0][i];

		if(fabs(lambda)<1e-6)
		{
			Matrix special_vector(n,1);
			for(int j = 0 ; j<  n ;j++)
			{
				result.data[j][i] = special_vector.data[j][0];
			}
		}
		else
		{
			Matrix B = special - lambda*eye(n);
			B = row_reduction(B);
			Matrix special_vector = extract(B,n);
			special_vector.data[n-1][0] = -1;
			for(int j = 0 ; j<  n ;j++)
			{
				result.data[j][i] = special_vector.data[j][0];
			}
		}

	
	}
	result  = Correction (result);
	return result;
}

double function_eval(double(*func)(double x,double t),double a,double b,int n,int k,double x)
{
	Matrix roots = find_root_legende(n);
	Matrix coeff = Matrix(1,n);
	for(int i = 0 ;i < n ;i++)
	{
		coeff.data[0][i] = 2.0/((1.0-pow(roots.data[0][i],2))*pow((value(  derivation_polynomial( polynomial_legende(n),1),roots.data[0][i])),2));
	}


	Matrix eigenvalues =eigenvalue(func,a,b,n);
	Matrix proper_vectors = proper_vector(func,a,b,n);
	double sum=0;

	Matrix special_vector = extract(proper_vectors,k);
	double p = (b-a)/2.0;
	double q = (b+a)/2.0;
	double lambda = eigenvalues.data[0][k-1];
	if (fabs(lambda)<1e-6)
	{
		return 0;
	}
	else
	{
		for(int i = 0 ; i< n;i++)
		{
			sum += coeff.data[0][i] * (*func)(x, p*roots.data[0][i] + q) * special_vector.data[i][0];
		}
		return p * sum / lambda;
	}
}
