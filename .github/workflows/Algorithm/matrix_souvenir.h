#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Matrix
{
public:
	int n_rows = 0;
	int n_cols = 0;
	double **data = NULL;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Matrix()																			//此函数用于初始化矩阵
	{
		n_rows = 0;
		n_cols = 0;
		data = NULL;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Matrix(int m, int n)															//此函数用于给矩阵分配内存
	{
		this->~Matrix();

		n_rows = m;
		n_cols = n;

		data = (double**)malloc(n_rows * sizeof(double*));
		for(int i = 0; i < n_rows; i++)
		{
			data[i] = (double*)malloc(n_cols * sizeof(double));
			for(int j = 0; j < n_cols; j++)
			{
				data[i][j] = 0;
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Matrix(const Matrix& A)											//拷贝构造函数用与矩阵定义时的初始化
	{																//构造拷贝函数会使原赋值的赋给指针运算编程矩阵内部的值传递
		this->~Matrix();											//因此在	input运算中应该将形参设置为指针而不是矩阵对象，这
																	//这样才能更改输入矩阵的值
		n_rows = A.n_rows;
		n_cols = A.n_cols;

		data = (double**)malloc(n_rows * sizeof(double*));
		for(int i = 0; i < n_rows; i++)
		{
			data[i] = (double*)malloc(n_cols * sizeof(double));
			for(int j = 0; j < n_cols; j++)
			{
				data[i][j]=A.data[i][j];
			}
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																			//析构函数用于清理矩阵被malloc分配的内存
	~Matrix()
	{
		n_rows = 0;
		n_cols = 0;
		if(data)
		{
			for(int i = 0; i < n_rows; i++)
			{
				free(data[i]);
			}
			free(data);
			data = NULL;
		}
	}

	Matrix& operator =(const Matrix &A)
	{
		this->~Matrix();
		n_rows = A.n_rows;
		n_cols = A.n_cols;

		data = (double**)malloc(n_rows * sizeof(double*));
		for(int i = 0; i < n_rows; i++)
		{
			data[i] = (double*)malloc(n_cols * sizeof(double));
			for(int j = 0; j < n_cols; j++)
			{
				data[i][j]=A.data[i][j];
			}
		}

		return *this; 
	}

	const friend Matrix operator +(const Matrix &x,const Matrix &y);
	// const friend Matrix operator /(const Matrix &x,const Matrix &y);
	const friend Matrix operator -(const Matrix &x,const Matrix &y);
	const friend Matrix operator *(const Matrix &x,const Matrix &y);
	const friend Matrix operator *(float k,const Matrix &y);
	const friend bool operator ==(const Matrix &x,const Matrix &y);
	const friend Matrix operator ^(int &k,const Matrix &y);
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
	int rg1(Matrix A);
	int rg2(Matrix A);
	Matrix G_S_ortho(Matrix A);
	Matrix QrAlgorithm (Matrix A);
	bool Judge(Matrix A);
	Matrix indent(Matrix A);
	Matrix Correction (Matrix A);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printMatrix(Matrix A)
{
	int m = A.n_rows;
	int n = A.n_cols;
	int i, j;
	for (i = 0; i< m; i++)
	{
		for (j = 0; j< n; j++)
		{
			cout << A.data[i][j] << " ";
		} 
		cout << endl;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inputMatrix(Matrix& A)
{
	int m = A.n_rows;
	int n = A.n_cols;

	for(int i = 0; i< m; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cin >> A.data[i][j];
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix transpose(Matrix A)
{
	Matrix B(A.n_cols, A.n_rows);
	int i, j;
	int m = A.n_cols;
	int n  = A.n_rows;

	for (i = 0; i < m; i++)
	{
		for (j = 0;j < n; j++)
		{
			B.data[i][j] = A.data[j][i];
		}
	}

	return B;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const  Matrix operator +(const Matrix &x,const Matrix &y)
{
	Matrix temp(x.n_rows,x.n_cols);
	if((x.n_rows==y.n_rows)&&(x.n_cols==y.n_cols))
	{
		for(int i=0;i<x.n_rows;i++)
		{
			for(int j=0;j<x.n_cols;j++)
			{
				temp.data[i][j]=x.data[i][j]+y.data[i][j];
			}
		}
	}
	else
	{
		cout<<"These two matrix can't add together!"<<endl;
		exit(-1);
	}
	return temp;
}
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// const Matrix operator /(const Matrix &x,const Matrix &y)
// {
// 	Matrix temp = creatMatrix(x.n_rows,x.n_cols);
// 	if((x.n_rows==y.n_rows)&&(x.n_cols==y.n_cols))
// 	{
// 	for(int i=0;i<x.n_rows;i++)
// 	{
// 		for(int j=0;j<x.n_cols;j++)
// 		{

// 			temp.data[i][j]=x.data[i][j]/y.data[i][j];
// 		}
// 	}
// 	}
// 	else
// 	{
// 		cout<<"These two matrix can't divid together!"<<endl;
// 		exit(-1);
// 	}
// 	return temp;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const Matrix operator -(const Matrix &x,const Matrix &y)
{
	Matrix temp(x.n_rows,x.n_cols);
	if((x.n_rows==y.n_rows)&&(x.n_cols==y.n_cols))
	{
	for(int i=0;i<x.n_rows;i++)
	{
		for(int j=0;j<x.n_cols;j++)
		{
			temp.data[i][j]=x.data[i][j]-y.data[i][j];
		}
	}
	}
	else
	{
		cout<<"These two matrix can't add together!"<<endl;
		exit(-1);
	}
	return temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const Matrix operator *(const Matrix &A,const Matrix &B)
{
	int m = (A.n_rows);
	int n = (A.n_cols);
	int p = (B.n_rows);
	int q = (B.n_cols);
	Matrix C(m,q);
	
	if(n!=p)
	{
		cout<<"This two matrix can't time together!!"<<endl;
		exit(-1);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < q; j++)
		{
			double S = 0;
			for (int k = 0; k < p; k++)
			{
				S = S + A.data[i][k] * B.data[k][j];
			}
			C.data[i][j] = S;
		}
	}
	return C;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const Matrix operator *(float k,const Matrix &A)
{
	int m = A.n_rows;
	int n = A.n_cols;

	Matrix temp(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.data[i][j] = A.data[i][j] * k;
		}
	}
	return temp;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const bool operator ==(const Matrix &x,const Matrix &y)
{
	int m,n,flag;
	m=x.n_rows;
	n=x.n_cols;
	flag=0;

	if((x.n_rows!=y.n_rows)||(x.n_cols!=y.n_cols))
	{
		return false;
	}
	else
	{
		for(int i = 0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				if(x.data[i][j]!=y.data[i][j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
	}
	if(flag==1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const Matrix operator ^(const Matrix &y,int &k)
{
	Matrix temp(y.n_rows,y.n_cols);
	temp = y;

	for(int i=1;i<=k;i++)
	{
		temp = temp*y;
	}
	return temp;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix produceMatrixEye(Matrix A)												//在矩阵的右方生成一个单位阵用于求逆矩阵
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m, n + m);
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			Out.data[i][j] = A.data[i][j];
		}
	}
	for (int i = 0;i <m;i++)
	{
		Out.data[i][n+i] = 1;
	}
	return Out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix eye(int n)															//输入一个单位阵的行或列数，自动生成一个单位阵
{
	Matrix In(n, n);

	for (int i = 0; i < n; i++)
	{
		In.data[i][i] = 1;
	}
	return In;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix scaleRow(double k, int row,Matrix A)											//将A的第row行乘以k，用于做矩阵的运算
{
	int m = A.n_rows; int n = A.n_cols;
	Matrix Out(m, n);

	Matrix Elementary_Multy = eye(m);
	Elementary_Multy.data[row - 1][row - 1] = k;
	Out = Elementary_Multy*A;

	return Out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix addScaleRow2Row(double k, int row_1, int row_2, Matrix A)						//将第row_1行的k倍加到row_2行上
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m, n);

	Matrix Elementary_Multy = eye(m);
	Elementary_Multy.data[row_2-1][row_1-1] = k;
	Out = Elementary_Multy*A;

	return Out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix changeRow2Row(int a, int b, Matrix A)														//将矩阵A的a和b行互换
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m, n);
	for (int i = 0;i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Out.data[i][j] = A.data[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		Out.data[a-1][j] = A.data[b-1][j];
		Out.data[b-1][j] = A.data[a-1][j];
	}
	return Out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix inverse(Matrix A)																				//求矩阵A的逆矩阵
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m, n);

	if (m != n)
	{
		cout << "This Matrix doesn't have inverse!!" << endl;
		exit(-1);
	}
	Matrix temp(m, n + m);
	temp = produceMatrixEye(A);

	for (int j = 0;j < n - 1;j++)
	{
		int time = 0;
		for (int k = j;k < m;k++)
		{
			if (temp.data[k][j] != 0)
			{
				temp = changeRow2Row(k + 1, j + 1, temp);
				time++;
				break;
			}
		}
		if (time == 0)
		{
			cout << "error" << endl;
			exit(-1);
		}
		for (int i = j + 1;i < m;i++)
		{
			temp = addScaleRow2Row(-temp.data[i][j] / temp.data[j][j], j + 1, i + 1, temp);
		}
	}
	
		for (int i = 0;i < m;i++)
		{
			if (temp.data[i][i] == 0)
			{
				cout << "error" << endl;
				exit(-1);
			}
		}
	
	for (int i = 0;i < m;i++)
	{
		temp = scaleRow(1 / temp.data[i][i], i + 1, temp);
		
	}
	for (int j = 0;j < n - 1;j++)
	{
		for (int i = m - j - 1;i > 0;i--)
		{
			temp = addScaleRow2Row(-temp.data[i - 1][m - 1 - j],
				m - j, i, temp);
			
		}
	}
	for (int i = 0;i < m;i++)
	{
		temp = scaleRow(1 / temp.data[i][i], i + 1, temp);
		
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < m;j++)
		{
			Out.data[i][j] = temp.data[i][j + m];
		}
	}
	return Out;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix cutRowAndColumn(int a, int b, Matrix A)													//剪切掉矩阵的第a行第b列
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m - 1, n - 1);
	if (m != n)
	{
		cout << "´Ë¾ØÕó²»¿ÉµÈÇÐ" << endl;
	}
	for (int i = 0;i < a-1;i++)
	{
		for (int j = 0;j < b-1;j++)
		{
			Out.data[i][j] = A.data[i][j];
		}
		for (int j = b-1;j < n - 1;j++)
		{
			Out.data[i][j] = A.data[i][j + 1];
		}
	}
	for (int i = a-1;i < m - 1;i++)
	{
		for (int j = 0;j < b-1;j++)
		{
			Out.data[i][j] = A.data[i+1][j];
		}
		for (int j = b-1;j < n - 1;j++)
		{
			Out.data[i][j] = A.data[i+1][j + 1];
		}
	}
	return Out;	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double det(Matrix A)
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix temp = A;
	double Out = 0 ;
	if (m != n)
	{
		cout << "The matrix is not a square Matrix!!" << endl;
	}
	if (temp.n_cols == 2)
	{
		return  A.data[0][0] * A.data[1][1] - A.data[0][1] * A.data[1][0];	
	}

	for (int i = 0;i < temp.n_cols;i++)
	{
		Out = Out + pow(-1, i)*temp.data[0][i] * det(cutRowAndColumn(1, i + 1, temp));
	}

	return Out;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix permutation(int space,int sample)						//此函数将sapce个数中的sample个数取出的所有情况返回一个矩阵
// {
// 	int numOfAll = fact(space)/fact(sample)/fact(space-sample);
// 	Matrix result  = creatMatrix(numOfAll,sample);
// 	for (int i =0;i<numOfAll,i++)
// 	{

// 	}
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// int rg1(Matrix A)																	//此函数用%子式判别法%判断一个矩阵的秩
// {

// 	int matrixNumber(int rows,int cols,int son)
// 	{
// 		int result = (fact(rows)*fact(cols))/(son*son*fact(rows-son)*fact(cols-son));
// 		return result;
// 	}


	// int m = A.n_rows;
	// int n = B.n_cols;
	// int flag=m;
	// if(n<m)flag=n;
// 	for(int son = 2; son <= flag; son ++)
// 	{
// 		int number = matrixNumber(m,n,son)
// 		Matrix * A = malloc(number*sizeof(Matrix*));
// 		for (int i=0;i<number;i++)
// 		{

// 			A[i]=creatMatrix(son,son);
// 			A[i].data[][]
// 		}
// 	}
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rg2(Matrix A)																		// 此函数通过初等行变换求矩阵的秩
{
	int m = A.n_rows;
	int n = A.n_cols;
	if(m>n)
	{
		Matrix B = transpose(A);
		// bool * flag = malloc(m*sizeof(bool));
		for(int i = 0; i < n; i ++)
		{
			int j=0;
			for(; j < m; j ++)
			{
				if(B.data[i][j]!=0)
				{
					// flag[j]=true;
					break;
					// cout<<B.data[i][j]<<endl;
				}
			}
			if(j==m)
			{
				continue;	
			}
			B=scaleRow(1/B.data[i][j],i+1,B);
			for(int k=i+1;k<n;k++)
			{
				if(B.data[k][j]==0)
				{
					continue;
				}
				else
				{
					B=addScaleRow2Row(-B.data[k][j],i+1,k+1,B);
					// printMatrix(B);
				}
			}
		}
		int rg=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(B.data[i][j]!=0)
				{
					rg++;
					break;
				}
			}
			
		}
		return rg;
		

	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			// cout<<i<<endl;	
			int j=0;
			for(; j < n; j ++)
			{
				if(A.data[i][j]!=0)
				{
					// flag[j]=true;
					break;
				}

				// cout<<A.data[i][j]<<endl;
			}
			if(j==n)
			{
				continue;	
			}
			// cout<<i<<endl;
			A=scaleRow(1/A.data[i][j],i+1,A);
			// printMatrix(A);
			for(int k = 0; k < m; k ++)
			{
				if(k==i)continue;
				if(A.data[k][j]==0)
				{
					continue;

				}
				else
				{
					// cout<<k<<endl;
					A=addScaleRow2Row(-A.data[k][j],i+1,k+1,A);
					
				}	
			}
			
		}
		int rg=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(A.data[i][j]!=0)
				{
					rg++;
					break;
				}
			}

		}
		return rg;
		
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix extract(const Matrix A, int k) 														//此方程用于提取矩阵中的列向量
{
	Matrix result(A.n_rows, 1);
	if(k > A.n_cols)
	{
		cout << "The column is not exisit in your Matrix" << endl;
		exit(-1);
	}
	else
	{
		for(int i = 0; i < A.n_rows; i++)
		{
			result.data[i][0] = A.data[i][k-1];
		}
	}
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix unitization(const Matrix A)
{
	Matrix result(A.n_rows,1);
	Matrix temp;
	double module2=0;
	if(A.n_cols!=1)
	{
		cout<<"The Matrix is not a Matrix vector!!"<<endl;
		exit(-1);
	}
	else
	{
		temp=transpose(A)*A;
		
		module2 = temp.data[0][0];
		for(int i=0;i<A.n_rows;i++)
		{
			result.data[i][0]= A.data[i][0]/(sqrt(module2));
		}
		return result;
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix G_S_ortho(Matrix A)						//此方程用于对一个矩阵的每一个列向量进行单位正交化，称之为格拉姆施密特正交化
{
	Matrix result(A.n_rows,A.n_cols);
	Matrix * Temp=new Matrix[A.n_cols];

	for(int i=0;i<A.n_cols;i++)
	{
		// cout << i<<endl;
		Temp[i] = extract(A, i+1);
		// printMatrix(Temp[i]);
	}
	for(int i=1;i<A.n_cols;i++)
	{
		
		for(int j = 1; j <= i; j++)
		{
			// cout <<j<<endl;
			if((transpose(Temp[i-j]) * Temp[i-j]).data[0][0]==0)
			{
				cout<<"There exisit a vector null who means that this matrix can't be orthogonalization!!"<<endl;
				exit(-1);
			}
			double temp = ((transpose(Temp[i-j]) * Temp[i]).data[0][0])/((transpose(Temp[i-j]) * Temp[i-j]).data[0][0]);
			Temp[i] = Temp[i] - temp * Temp[i-j];
		}
	}
	for(int i=0;i<A.n_cols;i++)
	{
		Temp[i]=unitization(Temp[i]);
	}
	for(int i=0;i<A.n_rows;i++)
	{
		for(int j=0;j<A.n_cols;j++)
		{
			result.data[i][j]=Temp[j].data[i][0];
		}
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Judge(Matrix A)
{
	for(int i=0;i<A.n_cols-2;i++)
	{
		for(int j=i+2;j<A.n_cols;j++)
		{
			if(fabs(A.data[j][i])>0.000001)
			{
				return false;
			}
		}
	}

	for(int i=0;i<A.n_cols-1;i++)
	{
		if(fabs(A.data[i+1][i])>0.000001)
		{
			i++;
			if(i>=A.n_cols-1)
			{
				return true;
			}
			if(fabs(A.data[i+1][i])>0.000001)
			{
				return false;
			}
		}
	}

	// for(int i = 0;i< A.n_rows;i++)
	// {
	// 	// cout << i <<endl;
	// 	if(fabs(A.data[i+1][i])<=0.000001)
	// 	{

	// 		for(int k=i;k<A.n_rows;k++)
	// 		{
	// 			if(k>=A.n_rows)
	// 			{
	// 				break;
	// 			}
	// 			if(A.data[k][i]>0.000001)
	// 			{
	// 				flag = false;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		for(int k=i+2;k<A.n_rows;k++)
	// 		{
	// 			if(k>=A.n_rows)
	// 			{
	// 				break;
	// 			}
	// 			if(A.data[k][i]>0.000001)
	// 			{
	// 				flag = false;
	// 				break;
	// 			}
	// 		}
	// 		i++;
	// 		if(fabs(A.data[i+1][i])>0.000001)
	// 		{
	// 			flag =false;
	// 		}
	// 		for(int k=i+2;k<A.n_rows;k++)
	// 		{
	// 			if(k>=A.n_rows)
	// 			{
	// 				break;
	// 			}
	// 			if(A.data[k][i]>0.000001)
	// 			{
	// 				flag = false;
	// 				break;
	// 			}
	// 		}

	// 	}
	// 	if(!flag)
	// 	{
	// 		break;
	// 	}
	// }
	return true;
	// bool flag = true;
	// if(A.n_rows!=A.n_cols)
	// {
	// 	cout<<"Judge function can only judge the function who can be judged!!"<<endl;
	// 	exit(-1);
	// }
	// for(int i = 0; i< A.n_cols; i++)
	// {
	// 	if(i==0)
	// 	{
	// 		for(int j= 0; j< A.n_cols; j++)
	// 		{
	// 			if((j==i)||(j==i+1))
	// 			{
	// 				continue;
	// 			}
	// 			if(A.data[j][i]>=0.000001)
	// 			{
	// 				// cout << A.data[j][i];
	// 				flag = false;
	// 				return flag;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	else if(i==A.n_rows-1)
	// 	{
	// 		for(int j= 0; j< A.n_cols; j++)
	// 		{
	// 			if((j==i)||(j==i-1))
	// 			{
	// 				continue;
	// 			}
	// 			if(A.data[j][i]>=0.000001)
	// 			{
	// 				// cout << A.data[j][i];
	// 				flag = false;
	// 				return flag;
	// 				break;
	// 			}
	// 		}
			
	// 	}
	// 	else
	// 	{
	// 		for(int j= 0; j< A.n_cols; j++)
	// 		{
	// 			if((j==i)||(j==i-1)||(j==i+1))
	// 			{
	// 				continue;
	// 			}
	// 			if(A.data[j][i]>=0.000001)
	// 			{
	// 				// cout << A.data[j][i];
	// 				flag = false;
	// 				return flag;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	if(flag == false)
	// 	{
	// 		break;
	// 	}
	// }
	// return flag;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix indent(Matrix A)
{
	Matrix result(A.n_rows,A.n_cols);
	for(int i=0;i<A.n_cols-1;i++)
	{
		result.data[0][i+1]=A.data[0][i];
	}
	return result;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix Correction (Matrix A)
{
	Matrix result=A;
	for(int i=0; i < A.n_rows; i++)
	{
		for(int j=0; j < A.n_cols; j++)
		{
			// cout <<result.data[i][j]<<" ";
			if(fabs(result.data[i][j])<0.000001)
			{
				// cout << result.data[i][j] <<" ";
				result.data[i][j]=0;
			}
		}
		// printMatrix(result);
	}
	// printMatrix(result);
	// cout << "fabs(" << A.data[6][0] << ") < 0.000001 == " << ( fabs(A.data[6][0]) < 0.000001 ) << endl;
	// cout << fabs(0.021645) << endl;
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix creat_Friend_Matrix(int k)							//此函数用MALLOC 便不能调用我所定义的构造函数，必须用c++的new
{
	int n = k+1;
	Matrix result(k, k);
	Matrix *Temp = new Matrix[n];

	for(int i=0;i<n;i++)
	{
		Temp[i] = Matrix(1, n);
	}

	Temp[0].data[0][0]=1;
	Temp[1].data[0][1]=1;

	for(int i=2; i<n; i++)
	{
		Temp[i] =(1./i)*((2.*i-1.)*(indent(Temp[i-1]))-(i-1.)*(Temp[i-2]));
		// printMatrix(Temp[i]);
	}

	double An=Temp[k].data[0][k];
	// cout << "I am here!" << endl;
	for(int i=0; i<k; i++)
	{
		// cout <<An<<endl;

		result.data[k-1][i]=-(Temp[k].data[0][i])/(An);
	}

	// printMatrix(result);
	for(int i=0;i<k-1;i++)
	{
		result.data[i][i+1]=1;
	}
	result = Correction(result);
	// printMatrix(result);
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matrix QrAlgorithm (Matrix A_init)
{
	Matrix A = A_init, Q, R;

	// int i = 0;
	while(!Judge(A))
	{
		// printMatrix(Q);
		Q = G_S_ortho(A);
		Q = Correction(Q);
		// printMatrix(Q);
		R = transpose(Q) * A;
		// printMatrix(Q*R);
		A = R * Q;
		// printMatrix(Q);
		// break;
		
		A = Correction(A);
		// printMatrix(A);
		// cout << Judge(A) << endl;
		// i++;
		// cout << i << endl;
	}
	return A;
}
