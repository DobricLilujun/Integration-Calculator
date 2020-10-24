#include "integral_equation.cpp"
int main()
{
	double(*func)(double x,double t);
	func = & function;
	double a,b,x;
	unsigned n ,k;
	char c;
	bool flag=true;
	cout <<"Attention please:If you want to change your function ,you can open file function.cpp to change it!"<<endl;
	cout <<"********************************"<<endl;
	cout <<"**Welcome to integral_equation**"<<endl;
	cout <<"********************************"<<endl;
	cout <<"Please input your lowerlimit:"<<endl;
	cin >> a;
	cout <<"Please input your upperlimit:"<<endl; 
	cin >>b;
	cout <<"Please input the order of legendre polynomial:"<<endl;
	cin >> n ;
	cout << "The eigenvalues are:"<<endl;
	eigenvalue(func,a,b,n).print();
	cout <<"Please input the eigenvalue you want to use:"<<endl;
	cin >> k;
	while ((k>n)||(k<0))
	{
		cout << "Please input the right number:"<<endl;
		fflush(stdin);
		cin.clear();
		cin >> k ;
	}
	while(flag)
	{
		cout << "please input x to find the value of the special function:"<<endl;
		cin >>x;
		cout <<function_eval(func,a,b,n,k,x)<<endl; 
		cout << "continue? Y or N"<<endl;
		cin >>c;
		bool a = true;
		while (a)
		{
			a = false;
			if (c == 'N')
			{
				flag = false;
			}
			else if(c == 'Y')
			{
				flag = true;
			}
			else
			{
				a = true;
				cout <<"The  character input is illegal"<<endl;
				cout <<"Please reinput the character:"<<endl;
				fflush(stdin);
				cin.clear();
				cout << "continue? Y or N"<<endl;
				cin >>c;
			}
		}
	}
	// Matrix A = Matrix(1,100);
	// Matrix B = Matrix(1,100);
	// for(int i = 0 ;i< 100;i++)
	// {
	// 	A.data[0][i] = 1+ i ;
	// 	B.data[0][i] = function_eval(func,a,b,n,k,A.data[0][i]);
	// }
	// B.print();
	
	cout << "Thank you for using!"<<endl;
	return 0;

}