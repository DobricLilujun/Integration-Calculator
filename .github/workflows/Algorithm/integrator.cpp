#include <integrator.h>
#define pi 3.1415926


double  integrator_legend(MathFunc f,double lowerlimit,double upperlimit,unsigned n)
{
	double a = (upperlimit - lowerlimit)/2;
	double b = (upperlimit + lowerlimit)/2;
	double sum = 0;
	Matrix roots = find_root_legende(n);
	Matrix coeff = Matrix(1,n);

	for(unsigned i = 0 ;i < n ;i++)
	{
		coeff.data[0][i] = 2.0/((1.0-pow(roots.data[0][i],2))*pow((value(  derivation_polynomial( polynomial_legende(n),1),roots.data[0][i])),2));
	}
	for(unsigned i = 0 ;i < n;i++)
	{
		sum = sum + coeff.data[0][i]*f.eval(a*roots.data[0][i]+b);
	}
	return a*sum;
}

unsigned fac(unsigned n)
{
	if(n<0) return 0;
	if(n==0||n==1)return 1;
	if(n>1)
	{
		return n*fac(n-1);
	}
}

double integrator_laguerre(MathFunc f,double lowerlimit,double upperlimit,unsigned n)
{
	double sum = 0;
	double a = lowerlimit;
	double b = upperlimit;
	Matrix roots = find_root_laguerre(n);
	Matrix coeff = Matrix(1,n);
	for(unsigned i = 0 ;i < n ;i++)
	{
		coeff.data[0][i] = roots.data[0][i]/(pow(value(polynomial_laguerre(n+1),roots.data[0][i]),2)*pow(n+1,2));
		// cout << coeff.data[0][i]<<endl;
	}
	cout << a << endl;
	cout << b << endl;
	if ((a != -DBL_MAX)&&( b == DBL_MAX))
	{
		for(unsigned i = 0 ;i < n;i++)
		{
			sum = sum + coeff.data[0][i]*f.eval(roots.data[0][i]+a)*exp(roots.data[0][i]);
		}
	}
	else if((a == -DBL_MAX)&&( b != DBL_MAX))
	{
		for(unsigned i = 0 ;i < n;i++)
		{
			sum = sum + coeff.data[0][i]*f.eval(b-roots.data[0][i])*exp(roots.data[0][i]);
		}
	}
	else if ((a == -DBL_MAX)&&( b == DBL_MAX))
	{
		for(unsigned i = 0 ;i < n;i++)
		{
			sum = sum + coeff.data[0][i]*f.eval(roots.data[0][i])*exp(roots.data[0][i])+coeff.data[0][i]*f.eval(-roots.data[0][i])*exp(roots.data[0][i]);
		}
	}
	else if ((a == -DBL_MAX)&&( b ==-DBL_MAX))
	{
		return sum;
	}
	else if ((a == DBL_MAX)&&( b ==DBL_MAX))
	{
		return sum;
	}
	else
	{
		cout << "The gauss_laguerre method can only make the approximation of this kind of integration:upperlimit == infty or lower limit ==infty"<<endl;
		exit(-1);
	}
	return sum;
}

double integrator_Hermite(MathFunc f,double lowerlimit,double upperlimit,unsigned n)
{
	double a = lowerlimit;
	double b = upperlimit;
	double sum = 0;
	Matrix roots = find_root_Hermite(n);
	Matrix coeff = Matrix(1,n);

	if((a == -DBL_MAX)&&(b == DBL_MAX))
	{
		for(unsigned i = 0 ;i < n ;i++)
		{
			coeff.data[0][i] = (pow(2,n-1)*fac(n)*sqrt(pi))/(pow(n,2))/pow(value(polynomial_Hermite(n-1),roots.data[0][i]),2);
		}
		for(unsigned i = 0 ;i < n;i++)
		{
			sum = sum + coeff.data[0][i]*f.eval(roots.data[0][i])*exp(roots.data[0][i]*roots.data[0][i]);
		}
	}
	else
	{
		cout << "The integrator_Hermite can just make approximation of integration from -infty to infty !!"<<endl;
		exit (-1);
	}
	return sum;
}

double integrator_Chebyshev(MathFunc f,double lowerlimit,double upperlimit,unsigned n)
{
	double a = (upperlimit - lowerlimit)/2;
	double b = (upperlimit + lowerlimit)/2;
	double sum = 0;
	Matrix roots = find_root_Chebyshev(n);
	Matrix coeff = Matrix(1,n);

	if((lowerlimit != -DBL_MAX)&&(lowerlimit!=DBL_MAX)&&(upperlimit != -DBL_MAX)&&(upperlimit != DBL_MAX))
	{
		for(unsigned i = 0 ;i < n ;i++)
		{
			coeff.data[0][i] = pi/n;
		}
		for(unsigned i = 0 ;i < n;i++)
		{
			sum = sum + coeff.data[0][i]*f.eval(a*roots.data[0][i]+b)*sqrt(1.0-roots.data[0][i]*roots.data[0][i]);
		}
	}
	else
	{
		cout << "The integrator_Chebyshev can only make approximation for integration from a to b in which a and b isn't infty"<<endl;
		exit(-1);
	}
	return a*sum;
}

void Sort_2SortedArray(double* a, unsigned l, unsigned m, unsigned r) 
{
    unsigned i = l, j = m + 1;
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
    for(unsigned m = l,i=0; m <= r; m++)
    {
        a[m] = temp[i];
        k++;
        i++;
    }
         
}

void merge (double *a,int left,int right)
{  
	if(left==right)
        return;
    int middle =(right+left)/2;
    merge(a,left,middle);
    merge(a,middle+1,right);
    Sort_2SortedArray(a,left,middle,right);   
}


double violent_search_Max(MathFunc f, double lowerlimit,double upperlimit,unsigned long section)		//section的大小最少上万
{
	double length = upperlimit - lowerlimit;
	double step_length = length/section;
	unsigned flag=0;
	double * A = (double *)malloc((section+1)*sizeof(double));
	double * B = (double *)malloc((section+1)*sizeof(double));
	for(unsigned i = 0 ;i < section+1;i++)
	{
		A[i] = f.eval(lowerlimit+step_length*i);
		B[i] =  A[i];
	}
	merge(A,0,section);
	return A[section];
}

double violent_search_Min(MathFunc f, double lowerlimit,double upperlimit,unsigned long section)		//section的大小最少上万
{
	double length = upperlimit - lowerlimit;
	double step_length = length/section;

	unsigned flag=0;
	double * A = (double *)malloc((section+1)*sizeof(double));
	double * B = (double *)malloc((section+1)*sizeof(double));
	for(unsigned i = 0 ;i < section+1;i++)
	{
		A[i] = f.eval(lowerlimit+step_length*i);
		B[i] =  A[i];
	}
	merge(A,0,section);

	return A[0];
}

Matrix Scatter_function(double x_left,double x_right,double y_lower,double y_upper,unsigned long n) //本函数用于向平面中撒点
{
		double x_length = x_right-x_left;
		double y_length = y_upper-y_lower;

		Matrix locations = Matrix(2,n);
		{
			srand(rand());
			for(unsigned i = 1 ;i <= n; i++)
			{
				locations.data[0][i-1]=(rand()*1.0/RAND_MAX)*x_length+x_left;
			}

			srand(rand());
			for(unsigned i = 1 ;i <= n; i++)
			{
				locations.data[1][i-1] =(rand()*1.0/RAND_MAX)*y_length+y_lower;
			}
			return locations;
		}
		
}
double integrator_Monte_Carlo(MathFunc f,double lowerlimit,double upperlimit,unsigned long n)
{

	double a = lowerlimit;
	double b = upperlimit;
	double length = b-a;
	double min = violent_search_Min(f,a,b,100000);
	double max = violent_search_Max(f,a,b,100000);
	double value_length = max - min;
	double area_length = max-min;
	long number_p=0;
	long number_n=0;

	if((lowerlimit != -DBL_MAX)&&(lowerlimit!=DBL_MAX)&&(upperlimit != -DBL_MAX)&&(upperlimit != DBL_MAX))
	{
		if(min*max >0)
		{
			if(min > 0)
			{
				Matrix points = Scatter_function(a,b,min,max,n);
				for(unsigned i = 0 ; i < n ; i++)
				{
					if(points.data[1][i]<=f.eval(points.data[0][i]))
					{
						number_p ++;
					}
				}

				return (length*value_length)*(number_p*1.0/n);
			}
			else
			{
				Matrix points = Scatter_function(a,b,min,max,n);
				for(unsigned i = 0 ; i < n ; i++)
				{
					if(points.data[1][i]>=f.eval(points.data[0][i]))
					{
						number_n ++;
					}
				}
				return -(length*value_length)*(number_n*1.0/n);
			}
		}
		else if(min*max <0)
		{
			Matrix points = Scatter_function(a,b,min,max,n);
			for(unsigned i = 0 ; i < n ; i++)
			{
				if(points.data[1][i]>=0)
				{
					if(points.data[1][i]<=f.eval(points.data[0][i]))
					{
						number_p ++;
					}

				}
				else
				{
					if(points.data[1][i]>=f.eval(points.data[0][i]))
					{
						number_n ++;
					}
				}
			}
			return (value_length*length)*((number_p-number_n)*1.0/n);
		}
		else
		{
			if((min == 0)&&(max != 0))
			{
				Matrix points = Scatter_function(a,b,0,max,n);

				for(unsigned i = 0 ; i < n ; i++)
				{
					if(points.data[1][i]<=f.eval(points.data[0][i]))
					{
						number_p ++;
					}
				}
	
				return (length*value_length)*(number_p*1.0/n);
			}
			else if((min != 0)&&(max == 0))
			{
				Matrix points = Scatter_function(a,b,min,max,n);
				for(unsigned i = 0 ; i < n ; i++)
				{
					if(points.data[1][i]>=f.eval(points.data[0][i]))
					{
						number_n ++;
					}
				}
				return -(length*value_length)*(number_n*1.0/n);
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		cout << "The integrator_Monte_Carlo can only make approximation for integration from a to b in which a and b isn't infty"<<endl;
		exit(-1);
	}
}

double integrator_Rimmen(MathFunc f,double lowerlimit,double upperlimit,unsigned n)
{
	double a = lowerlimit;
	double b = upperlimit;
	double length = b-a;
	double stepsize = length/n;
	double sum=0;
	double x = a;
	for(unsigned i=0;i<n;i++)
	{
		x=a+i*stepsize;
		sum=sum + f.eval(x) * stepsize;
	}
	return sum;
}