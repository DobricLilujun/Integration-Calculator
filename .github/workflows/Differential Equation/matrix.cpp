#include "matrix.h"
#define pi 3.1415926///////////////////
Matrix::Matrix()
{
	n_rows = 0;
	n_cols = 0;
	data = NULL;
}

Matrix::Matrix(int m, int n)
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

Matrix::Matrix(const Matrix& A)		
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
}

Matrix::~Matrix()
{
	if(data)
	{
		for(int i = 0; i < n_rows; i++)
		{
			free(data[i]);
		}
		free(data);
		data = NULL;
	}
	n_rows = 0;
	n_cols = 0;
}

Matrix& Matrix::operator =(const Matrix &A)
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

void printMatrix(Matrix A)												
{
	int m = A.n_rows;
	int n = A.n_cols;
	int i, j;
	for (i = 0; i< m; i++)
	{
		for (j = 0; j< n; j++)
		{
			cout << left<<setw(10)<<A.data[i][j]<<"  ";
		} 
		cout << endl;

	}
	cout << endl;
}

void Matrix::print()const
{ 
	int m = this->n_rows;
	int n = this->n_cols;
	int i, j;
	for (i = 0; i< m; i++)
	{
		for (j = 0; j< n; j++)
		{
			cout << left<<setw(10)<<this->data[i][j]<<"  ";
		} 
		cout << endl;

	}
	cout << endl;
}

void Matrix::clear()
{
	int m = this->n_rows;
	int n = this->n_cols;
	for (int i = 0; i< m; i++)
	{
		for (int j = 0; j< n; j++)
		{
			data[i][j] = 0;	
		} 
	}
}
void Matrix::input()const
{
	int m = n_rows;
	int n = n_cols;

	for(int i = 0; i< m; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cin >> data[i][j];
		}
	}
}

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

Matrix operator +(const Matrix &x,const Matrix &y)
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

Matrix operator -(const Matrix &x,const Matrix &y)
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

Matrix operator *(const Matrix &A,const Matrix &B)
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

Matrix operator *(float k,const Matrix &A)
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

bool operator ==(const Matrix &x,const Matrix &y)
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

Matrix operator ^(const Matrix &y,int &k)
{
	Matrix temp(y.n_rows,y.n_cols);
	temp = y;

	for(int i=1;i<=k;i++)
	{
		temp = temp*y;
	}
	return temp;
}

Matrix produceMatrixEye(Matrix A)
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

Matrix eye(int n)
{
	Matrix In(n, n);

	for (int i = 0; i < n; i++)
	{
		In.data[i][i] = 1;
	}
	return In;
}
double norm(Matrix A)
{
	if(A.n_cols == 1)
	{
		// for (int i = 0 ; i < A.n_rows ;i++)
		// {
		// 	norm = norm + A.data[i][0]*A.data[i][0];
		// }
		// return sqrt(norm);
		return sqrt( (transpose(A) * A).data[0][0] );
	}
	else if(A.n_rows == 1)
	{
		// for (int i = 0 ; i < A.n_cols ;i++)
		// {
		// 	norm = norm + A.data[0][i]*A.data[0][i];
		// }
		// return sqrt(norm);
		return sqrt( (A * transpose(A)).data[0][0] );
	}
	else
	{
		cout << "The matrix you input doesn't have a norm"<<endl;
		exit(-1);
	}
}
Matrix scaleRow(double k, int row,Matrix A)
{
	int m = A.n_rows; int n = A.n_cols;
	Matrix Out(m, n);

	Matrix Elementary_Multy = eye(m);
	Elementary_Multy.data[row - 1][row - 1] = k;
	Out = Elementary_Multy*A;

	return Out;
}

Matrix addScaleRow2Row(double k, int row_1, int row_2, Matrix A)
{
	int m = A.n_rows;
	int n = A.n_cols;
	Matrix Out(m, n);

	Matrix Elementary_Multy = eye(m);
	Elementary_Multy.data[row_2-1][row_1-1] = k;
	Out = Elementary_Multy*A;

	return Out;
}

Matrix changeRow2Row(int a, int b, Matrix A)
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

Matrix inverse(Matrix A)
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

Matrix cutRowAndColumn(int a, int b, Matrix A)
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


int rg2(Matrix A)
{
	int m = A.n_rows;
	int n = A.n_cols;
	if(m>n)
	{
		Matrix B = transpose(A);
		for(int i = 0; i < n; i ++)
		{
			int j=0;
			for(; j < m; j ++)
			{
				if(B.data[i][j]!=0)
				{
					break;
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
			int j=0;
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
			A=scaleRow(1/A.data[i][j],i+1,A);
			for(int k = 0; k < m; k ++)
			{
				if(k==i)continue;
				if(A.data[k][j]==0)
				{
					continue;

				}
				else
				{
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


Matrix extract(const Matrix A, int k)
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
		if(temp.data[0][0]!=0)
		{
			for(int i=0;i<A.n_rows;i++)
			{
				result.data[i][0]= A.data[i][0]/(sqrt(module2));
			}
		}
		return result;
	}

}

// Matrix G_S_ortho(Matrix A)
// {
// 	Matrix result(A.n_rows,A.n_cols);
// 	Matrix * Temp=new Matrix[A.n_cols];

// 	for(int i=0;i<A.n_cols;i++)
// 	{
// 		Temp[i] = extract(A, i+1);
// 	}
// 	Matrix temp = Matrix(1,A.n_cols-1);
// 	for(unsigned i=1; i<A.n_cols;i++)
// 	{
// 		for(int j = 0; j < i; j++)
// 		{
// 			Temp[j].print();
// 			cout <<(transpose(Temp[j]) * Temp[j]).data[0][0]<<endl;
// 			// if(fabs((transpose(Temp[j]) * Temp[j]).data[0][0])<=1e-6)
// 			// {
// 			// 	temp.data[0][j] = 0;
// 			// 	continue;
// 			// }
// 			temp.data[0][j] = ((transpose(Temp[j]) * Temp[i]).data[0][0])/((transpose(Temp[j]) * Temp[j]).data[0][0]);	
// 			cout<<"temp["<<j<<"]" << temp.data[0][j]<<endl;
// 			cout << "i="<<i<<endl;
// 			cout << "j="<<j<<endl;
// 		}
// 		for (unsigned j = 0 ;j < i ; j++)
// 		{
// 			Temp[i] = Temp[i] - temp.data[0][j]*Temp[j];
			
// 		}
// 	}

// 	for(int i=0;i<A.n_cols;i++)
// 	{
// 		Temp[i]=Correction(Temp[i]);
// 		Temp[i]=unitization(Temp[i]);

// 	}
// 	for(int i=0;i<A.n_rows;i++)
// 	{
// 		// cout << "temp["<<i<<"]*temp["<<i+1<<"]:"<<(transpose(Temp[i])*Temp[i+1]).data[0][0]<<endl;
// 		for(int j=0;j<A.n_cols;j++)
// 		{
// 			result.data[i][j]=Temp[j].data[i][0];
// 		}
// 	}
// 	return result;
// }
// Matrix G_S_ortho(Matrix A)
// {
// 	Matrix * Temp=new Matrix[A.n_cols];
// 	Matrix * Base=new Matrix[A.n_cols];
// 	for(int i=0; i<A.n_cols; i++)
// 	{
// 		Temp[i] = extract(A, i+1);
// 	} 
// 	Base[0] = unitization(Temp[0]);
// 	for (int i = 1;i < A.n_cols ; i++)
// 	{
// 		Matrix vk = Temp[i];
// 		Matrix S(A.n_rows,1);
// 		for(int j = 0 ; j< i;j++)
// 		{

// 			Matrix ei = Base[i];
// 			cout << "ei.n_cols" << ei.n_cols<<endl;
// 			cout << "ei.n_rows" << ei.n_rows<<endl;
// 			cout << "vk.n_cols" << vk.n_cols<<endl;
// 			cout << "vk.n_rows" << vk.n_rows<<endl;

// 			double num = (transpose(ei)*vk).data[0][0];
// 			cout <<"i am here"<<endl;
// 			double den = (transpose(ei)*ei).data[0][0];
// 			if (den!=0)
// 			{
// 				S = S + num / den * ei;
// 			}
// 		}
// 		Base[i] = unitization(vk - S);
// 		S.clear();
// 	}
// }
Matrix ortho(Matrix A)
{
	Matrix H = eye(A.n_rows);

	for(int j = 1; j < A.n_cols; j++)
	{
		int n = A.n_rows - j + 1;
	    Matrix e(n, 1);
	    e.data[0][0] = 1;

	    Matrix v(n, 1);
	    for(int i = 0; i < n; i++)
	    {
	    	v.data[i][0] = A.data[i+j-1][j-1];
	    }

	    Matrix u = v - norm(v) * e;
	    u = unitization(u);

	    Matrix h = eye(n) - 2 * u * transpose(u);   

	    Matrix K = eye(A.n_rows);
	    for(int sub_i = j-1; sub_i < A.n_rows; sub_i++)
	    {
	    	for(int sub_j = j-1; sub_j < A.n_cols; sub_j++)
	    	{
	    		K.data[sub_i][sub_j] = h.data[sub_i-j+1][sub_j-j+1];
	    	}
	    }

	    H = K * H;
	    A = H * A;
	}
	return transpose(H);
}

bool Judge(Matrix A)
{
	double epsilon = 1E-7;
	for(int i=0;i<A.n_cols-2;i++)
	{
		for(int j=i+2;j<A.n_cols;j++)
		{
			if(fabs(A.data[j][i])>epsilon)
			{
				return false;
			}
		}
	}

	for(int i=0;i<A.n_cols-1;i++)
	{
		if(fabs(A.data[i+1][i])>epsilon)
		{
			i++;
			if(i>=A.n_cols-1)
			{
				return true;
			}
			if(fabs(A.data[i+1][i])>epsilon)
			{
				return false;
			}
		}
	}
	return true;
}
Matrix indent(Matrix A)
{
	Matrix result(A.n_rows,A.n_cols);
	for(int i=0;i<A.n_cols-1;i++)
	{
		result.data[0][i+1]=A.data[0][i];
	}
	return result;
}
Matrix Correction (Matrix A)
{
	Matrix result=A;
	for(int i=0; i < A.n_rows; i++)
	{
		for(int j=0; j < A.n_cols; j++)
		{
			if(fabs(result.data[i][j])<1e-6)
			{
				result.data[i][j]=0;
			}
		}
	}
	return result;
}

Matrix creat_Friend_Matrix_lengend(int k)
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
	}

	double An=Temp[k].data[0][k];
	
	for(int i=0; i<k; i++)
	{
		result.data[k-1][i]=-(Temp[k].data[0][i])/(An);
	}
	for(int i=0;i<k-1;i++)
	{
		result.data[i][i+1]=1;
	}
	result = Correction(result);
	return result;
}

Matrix QrAlgorithm (Matrix A_init)
{
	Matrix A = A_init, Q, R, In= eye(A.n_rows);
	while(!Judge(A))
	{
		double u = A.data[A.n_rows-1][A.n_cols-1];
		A = A - u * In;
		Q = ortho(A);
		// cout <<"Q = "<<endl;
		// 	Q.print();

		R = transpose(Q) * A;
		R = Correction(R);
		A = R * Q;
		A = A + u * In;
		// cout << "A"<<endl;
		// A.print();
	}
	A = Correction(A);
	return A;
}

Matrix equation_two_unknowns (double a,double b,double c)
{
	Matrix result = Matrix(2,2);
	if(a==0)
	{
		if(b==0)
		{
			if(c!=0)
			{
				cout<<"This equation has no meaning!!"<<endl;
				exit(-1);
			}
			else
			{
				cout<<"This equation has infty roots!!"<<endl;
				exit(-1);
			}
		}
		else
		{
			result.data[0][0]=-c/b;
		}
	}
	else
	{
		double theta = b*b - 4 * a * c;
		if(theta >=0)
		{
			result.data[0][0]=(-b/(2*a))+sqrt(theta)/(2*a);
			result.data[0][1]=(-b/(2*a))-sqrt(theta)/(2*a); 
		}
		else
		{
			result.data[0][0]=-b/(2*a);
			result.data[0][1]=sqrt(-theta)/(2*a);
			result.data[1][0]=-b/(2*a);
			result.data[1][1]=-sqrt(-theta)/(2*a);
		}
	}
	return result;
}
Matrix Findroots(Matrix friendMatrix)
{
	unsigned n = friendMatrix.n_cols;
	Matrix result = Matrix(2,n);
	Matrix aft_Qr = QrAlgorithm(friendMatrix);

	for(unsigned i=0;i<n;i++)
	{
		if(i==n-1)
		{
			result.data[0][i]=aft_Qr.data[i][i];
			result.data[1][i]=0;
			break;
		}
		if(fabs(aft_Qr.data[i+1][i])>0)
		{
			double a = aft_Qr.data[i][i];
			double b = aft_Qr.data[i][i+1];
			double c = aft_Qr.data[i+1][i];
			double d = aft_Qr.data[i+1][i+1];

			Matrix Root = equation_two_unknowns(1,-(a+d),a*d-c*b);
			result.data[0][i] = Root.data[0][0];
			result.data[0][i+1]=Root.data[0][1];
			result.data[1][i]=Root.data[1][0];
			result.data[1][i+1]=Root.data[1][1];

			i++;
		}
		else
		{
			result.data[0][i]=aft_Qr.data[i][i];
			result.data[1][i]=0;
		}
		
	}
	return result;
}
void merge (double *a,int left,int right)
{
    void Sort_2SortedArray(double* a, int l, int m, int r);
    
    if(left==right)
        return;
    int middle =(right+left)/2;
    
        merge(a,left,middle);
        merge(a,middle+1,right);
        Sort_2SortedArray(a,left,middle,right);
    
}

void Sort_2SortedArray(double* a, int l, int m, int r) // 定义排序两个已经排好序的数组的函数
{
    int i = l, j = m + 1;
    int k = 0;

    double * temp = (double*)malloc( (r-l+1) * sizeof(double) );


    while( (i <= m) && (j <= r) )
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    if(i<=m)
    {
        for(;i<=m;i++)
        {
            temp[k]= a[i];
            k++;
        }
    }
    if(j<=r)
    {
        for(;j<=r;j++)
        {
            temp[k]= a[j];
            k++;

        }
    }
    for(int m = l,i=0; m <= r; m++)
    {
        a[m] = temp[i];
        k++;
        i++;
    }
         
}

// Matrix find_root_legende(int n)
// {
// 	Matrix A =Findroots(creat_Friend_Matrix_lengend(n));
// 	double * a = (double *)malloc(n*sizeof(double));
// 	for(int i = 0 ;i< n ;i++)
// 	{
// 		a[i] = A.data[0][i];
// 		// cout << a[i]<<endl;
// 	}
// 	// cout <<"roots"<<endl;
// 	// A.printf();
// 	merge(a,0,A.n_cols-1);
// 	for(int i = 0 ;i< n ;i++)
// 	{
// 		 A.data[0][n-i-1]= a[i];
// 	}
// 	// cout <<"root"<<endl;
// 	// A.print();
// 	return A;
// }
double legende_polynomial_eval(int n,double x)
{
	double p0 = 1;
	double p1 = x;
	if(n == 0)
	{
		return p0;
	}
	else if(n == 1)
	{
		return p1;
	}
	else
	{
		double temp;
		for (int i = 2;i <= n;i++)
		{
			temp = p1;
			p1 = (2 - 1./i) * x * p1 - (1 - 1./i) * p0;
			p0 = temp;
		}
		// cout << p1 <<endl;
		return p1;
	}

}
double legende_polynomial_derivation_eval(int n,double x)
{
	if(x == 1)
	{
		return 0.5 * n * (n + 1);
	}
	else if(x == -1)
	{
		return pow(-1, n-1) * 0.5 * n * (n + 1);
	}
	else
	{
		return n*1.0/(x*x-1)*(x*legende_polynomial_eval(n,x)-legende_polynomial_eval(n-1,x));
	}
}


Matrix find_root_legende(int n)
{
	Matrix result(2,n);
	double x0=0;
	double x1=0;
	for(int i = 1; i <=n ;i++)
	{
		x1 = cos(pi*(i*1.0- 1.0/4.0)/(n*1.0+1.0/2.0));
		do
		{
			x0 = x1;
			x1 = x0  - legende_polynomial_eval(n,x0)/legende_polynomial_derivation_eval(n,x0);
		}while(fabs(x1-x0)>1e-10);
		// printf("%.10lf\n", x1);
		result.data[0][i-1] = x1;
	}
	return result;
}

Matrix derivation_polynomial(Matrix A,int n)
{
	if(A.n_rows != 1)
	{
		cout << "Error of derivation_polynomial function:The matrix you use is not a polynomial matrix!!"<<endl;
		exit(-1);
	}

	Matrix result = Matrix(1,A.n_cols);
	Matrix temp = Matrix(1,A.n_cols);
	for(int times = 1 ; times <= n ;times ++)
	{
		if(times == 1)
		{
			for(int i = 1 ; i < A.n_cols ; i ++)
			{
				temp.data[0][i-1] =  A.data[0][i]*i;
			} 
		}
		else
		{
			for(int i = 1 ; i < A.n_cols ; i ++)
			{
				temp.data[0][i-1] =  result.data[0][i]*i;
			} 
		}
		result = temp;
	}

	return result;
}
Matrix integration_polynomial(Matrix A)
{
	if(A.n_rows != 1)
	{
		cout << "Error of derivation_polynomial function:The matrix you use is not a polynomial matrix!!"<<endl;
		exit(-1);
	}

	Matrix result = Matrix(1,A.n_cols+1);
	for(int i = 1 ; i < A.n_cols+1 ; i ++)
	{
		result.data[0][i] =  A.data[0][i-1]*(1.0/i); 
	}

	return result;
}
Matrix polynomial_legende (int k)
{
	int n = k+1;
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
	}
	return Temp[k];
}
Matrix polynomial_laguerre (int k)
{
	Matrix *Temp = new Matrix[k+1];

	for(int i=0;i<k+1;i++)
	{
		Temp[i] = Matrix(1, k+1);
	}

	Temp[0].data[0][0] = 1;
	Temp[1].data[0][1] = -1;
	Temp[1].data[0][0] = 1;
	for(int i = 2; i < k + 1; i++)
	{
		Temp[i] = (1.0/i)*((2*i-1)*Temp[i-1] - indent(Temp[i-1]) - (i-1)*Temp[i-2]);
	}
	return Temp[k];
}
Matrix polynomial_Hermite(int k)
{
	Matrix *Temp = new Matrix[k+1];

	for(int i=0;i<k+1;i++)
	{
		Temp[i] = Matrix(1, k+1);
	}

	Temp[0].data[0][0] = 1;
	Temp[1].data[0][1] = 2;
	for(int i = 2; i < k + 1; i++)
	{
		Temp[i] = 2.0*indent(Temp[i-1]) - 2*(i-1)*Temp[i-2];
	}
	return Temp[k];
}
double value(Matrix A,double x)
{
	double result ;
	for(int i = 0 ; i < A.n_cols ; i++)
	{
		result = result + A.data[0][i]*pow(x,i);
	}
	return result;
}
double dichotomy (Matrix A,double left,double right)
{
	double middle;
	while((right - left)>0.000001)
	{
		middle = (left + right)/2.0;
		if( value(A,left)*value(A,middle)< 0 )
		{
			right = middle;
		}
		else if(  value(A,middle)*value(A,right)< 0 )
		{
			left = middle;
		}
		else if (value(A,left)==0)
		{
			return left;
		}
		else if (value(A,middle)==0)
		{
			return middle;
		}
		else if(value(A,right)==0)
		{
			return right;
		}
		else
		{
			cout << "This polynomial doesn't have a root in your section !!"<<endl;
			exit(-1);
		}
	}
	return (right + left)/2.0;
}
Matrix find_root_laguerre(int n)										
{
	if( n == 1 )
	{
		Matrix root = Matrix(2,1);
		root.data[0][0] = dichotomy(polynomial_laguerre(1),0,4*n+2*n+2);
		return root;
	}
	else
	{
		Matrix temp = Matrix(2,n-1);
		temp = find_root_laguerre(n-1);
		Matrix root = Matrix(2,n);
		for(int k = 0;k < n; k++ )
		{
			if(k == 0)
			{
				root.data[0][k]=dichotomy(polynomial_laguerre(n),0,temp.data[0][0]);
				root.data[1][k]=0;
			}
			else if(k == n-1)
			{
				root.data[0][k]=dichotomy(polynomial_laguerre(n),temp.data[0][n-2],4*n+2*n+2);
				root.data[1][k]=0;
			}
			else
			{
				root.data[0][k]=dichotomy(polynomial_laguerre(n),temp.data[0][k-1],temp.data[0][k]);
				root.data[1][k]=0;
			}
		}
		return root;

	}
}
Matrix creat_Friend_Matrix_Hermite(int k)
{
	Matrix result(k, k);
	Matrix Temp = polynomial_Hermite(k);
	double An=Temp.data[0][k];
	
	for(int i=0; i<k; i++)
	{
		result.data[k-1][i]=-(Temp.data[0][i])/An;
	}
	for(int i=0;i<k-1;i++)
	{
		result.data[i][i+1]=1;
	}
	result = Correction(result);
	return result;
}
Matrix find_root_Hermite(int n)
{
	Matrix A =Findroots(creat_Friend_Matrix_Hermite(n));
	return A;
}

Matrix find_root_Chebyshev(int n)
{
	Matrix result = Matrix(2,n);
	for(int k =0;k <n;k ++)
	{
		if(fabs(cos((2.0*k+1.0)/(2.0*(n-1.0)+2)*pi))<0.000001)
		{
		result.data[0][k]= 0 ;
		result.data[1][k]= 0 ;
		}
		else
		{
			result.data[0][k]=cos((2.0*k+1.0)/(2.0*(n-1.0)+2)*pi);
			result.data[1][k]= 0;
		}
	}
	return result;
}
