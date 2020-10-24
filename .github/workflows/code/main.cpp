#include <integrator.h>
#include <MathFunc.h>
#include <matrix.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string>
#include <string.h>
using namespace std;
int main()
{ 
	int i;
	cout << "***Welcome to use integrator-calculator***"<<endl<<endl;
	cout <<"Please select the integrator you use to make integration:"<<endl;
	cout <<"1.integrator_legend(From a to b which are limited numbers)"<<endl;
	cout <<"2.integrator_laguerre(From a to b which have at least 1 infty number)"<<endl;
	cout <<"3.integrator_Hermite(From -infty to infty)"<<endl;
	cout <<"4.integrator_Chebyshev(From a to b which are limited numbers)"<<endl;
	cout <<"5.integrator_Monte_Carlo(From a to b which are limited numbers)"<<endl;
	cout <<"6.integrator_Rimmen(From a to b which are limited numbers)"<<endl;
	cout << endl;
	cout <<"If you want to input the infty ,please input DBL_MAX and -DBL_MAX!!" <<endl;

	bool a = false;	
	while (!a)
	{
		cout <<"Please select the integrator you use to make integration:"<<endl;
		cin >> i;
		if (i == 1)
		{
			double upperlimit;
			double lowerlimit;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			b = false;
			while(!b)
			{
				cout<<"Please input your lowerlimit:"<<endl;
				if (cin >>lowerlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b = false ;
			while(!b)
			{
				cout<<"Please input your upperlimit:"<<endl;
				if (cin >>upperlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b=false;
			while(!b)
			{
				cout<<"Please input the order of legendre polynomial(This function can only calculate the roots of polynomial less than 17!)"<<endl;
				if ((cin>>n)&&(n<=17))  
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_legend(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else if (i == 2)
		{
			double upperlimit;
			double lowerlimit;
			string upperlimit_str;
			string lowerlimit_str;
			stringstream ss;
			stringstream yy;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			bool c = false;
			while(!c)
			{	
				b = false ;
				while(!b)
				{
					cout<<"Please input your lowerlimit:"<<endl;
					
					if (cin >> lowerlimit_str)
					{
						ss <<lowerlimit_str;
						ss >>lowerlimit;
						if (lowerlimit_str == "DBL_MAX")
						{
							lowerlimit = DBL_MAX;
							break;
						}
						else if(lowerlimit_str == "-DBL_MAX")
						{
							lowerlimit = -DBL_MAX;
							break;
						}
						else
						{
							for (int i = 0;i<lowerlimit_str.length();i++)
							{
								if (!isdigit(lowerlimit_str[i]))
								{
									cout <<"The number you input is illegal!!"<<endl;
									fflush(stdin);
									cin.clear();
									break;
								}
								if (i ==lowerlimit_str.length()-1)
								{
									b=true;
								}
							}
							
						}
					}
					else
					{
						cout <<"The number you input is illegal!!"<<endl;
						fflush(stdin);
						cin.clear();
					}
				}
				b = false ;
				while(!b)
				{
					cout<<"Please input your upperlimit:"<<endl;
					if (cin >>upperlimit_str)
					{
						yy <<upperlimit_str;
						yy >>upperlimit;
						if (upperlimit_str== "DBL_MAX")
						{
							upperlimit = DBL_MAX;
							break;
						}
						else if(upperlimit_str== "-DBL_MAX")
						{
							upperlimit = -DBL_MAX;
							break;
						}
						else
						{
							for (int i = 0;i<upperlimit_str.length();i++)
							{
								if (!isdigit(upperlimit_str[i]))
								{
									cout <<"The number you input is illegal!!"<<endl;
									fflush(stdin);
									cin.clear();
									break;
								}
								if (i ==upperlimit_str.length()-1)
								{
									b=true;
								}
							}
							
						}
					}
					else
					{
						cout <<"The number you input is illegal!!"<<endl;
						fflush(stdin);
						cin.clear();
					}
				}
				if((upperlimit == DBL_MAX)||(lowerlimit == DBL_MAX)||(upperlimit == -DBL_MAX)||(lowerlimit == -DBL_MAX))
				{
					c = true;
				}
				else
				{
					cout <<"This function can only make approximation of integration from a to b where there is at least one infinite number."<<endl;
				}

			}
			b=false;
			while(!b)
			{
				cout<<"Please input the order of laguerre polynomial"<<endl;
				if (cin>>n)  
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_laguerre(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else if (i == 3)
		{
			double upperlimit;
			double lowerlimit;
			string upperlimit_str;
			string lowerlimit_str;
			stringstream ss;
			stringstream yy;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			bool c = false;
			while(!c)
			{	
				b = false ;
				while(!b)
				{
					cout<<"Please input your lowerlimit:"<<endl;
					if (cin >>lowerlimit_str)
					{
						ss <<lowerlimit_str;
						ss >>lowerlimit;
						if (lowerlimit_str== "DBL_MAX")
						{
							lowerlimit = DBL_MAX;
							break;
						}
						else if(lowerlimit_str== "-DBL_MAX")
						{
							lowerlimit = -DBL_MAX;
							break;
						}
						else
						{
							for (int i = 0;i<lowerlimit_str.length();i++)
							{
								if (!isdigit(lowerlimit_str[i]))
								{
									cout <<"The number you input is illegal!!"<<endl;
									fflush(stdin);
									cin.clear();
									break;
								}
								if (i ==lowerlimit_str.length()-1)
								{
									b=true;
								}
							}
							
						}
					}
					else
					{
						cout <<"The number you input is illegal!!"<<endl;
						fflush(stdin);
						cin.clear();
					}
				}
				b = false ;
				while(!b)
				{
					cout<<"Please input your upperlimit:"<<endl;
					if (cin >>upperlimit_str)
					{
						yy <<upperlimit_str;
						yy >>upperlimit;
						if (upperlimit_str== "DBL_MAX")
						{
							upperlimit = DBL_MAX;
							break;
						}
						else if(upperlimit_str=="-DBL_MAX")
						{
							upperlimit = -DBL_MAX;
							break;
						}
						else
						{
							for (int i = 0;i<upperlimit_str.length();i++)
							{
								if (!isdigit(upperlimit_str[i]))
								{
									cout <<"The number you input is illegal!!"<<endl;
									fflush(stdin);
									cin.clear();
									break;
								}
								if (i ==upperlimit_str.length()-1)
								{
									b=true;
								}
							}
							
						}
					}
					else
					{
						cout <<"The number you input is illegal!!"<<endl;
						fflush(stdin);
						cin.clear();
					}
				}
				if((upperlimit == DBL_MAX)&&(lowerlimit == -DBL_MAX)||(upperlimit == -DBL_MAX)&&(lowerlimit == DBL_MAX))
				{
					c = true;
				}
				else
				{
					cout <<"This function can only make approximation of integration from a to b where there are two infinite number."<<endl;
				}
			}
			b=false;
			while(!b)
			{
				cout<<"Please input the order of Hermite polynomial"<<endl;
				if (cin>>n)  
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_Hermite(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else if (i == 4)
		{
			double upperlimit;
			double lowerlimit;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			b = false;
			while(!b)
			{
				cout<<"Please input your lowerlimit:"<<endl;
				if (cin >>lowerlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b = false ;
			while(!b)
			{
				cout<<"Please input your upperlimit:"<<endl;
				if (cin >>upperlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b=false;
			while(!b)
			{
				cout<<"Please input the order of Chebyshev polynomial"<<endl;
				if (cin>>n)  
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_Chebyshev(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else if (i == 5)
		{
			double upperlimit;
			double lowerlimit;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			b = false;
			while(!b)
			{
				cout<<"Please input your lowerlimit:"<<endl;
				if (cin >>lowerlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b = false ;
			while(!b)
			{
				cout<<"Please input your upperlimit:"<<endl;
				if (cin >>upperlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b=false;
			while(!b)
			{
				cout<<"Please input the number of points you want to scatter:(It's better to scatter more than 100000)"<<endl;
				if (cin>>n)
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_Monte_Carlo(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else if (i == 6)
		{
			double upperlimit;
			double lowerlimit;
			unsigned n;
			string f_str;
			MathFunc f;
			bool b = false;
			while(!b)
			{
				cout<<"Please input your function:"<<endl;
				cin >> f_str;
				f = f_str;
				if(!f.empty())
				{
					b=true;
				}
				fflush(stdin);
				cin.clear();

			}
			b = false;
			while(!b)
			{
				cout<<"Please input your lowerlimit:"<<endl;
				if (cin >>lowerlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b = false ;
			while(!b)
			{
				cout<<"Please input your upperlimit:"<<endl;
				if (cin >>upperlimit)
				{
					b =true;
				}
				else
				{
					cout <<"The number you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			b=false;
			while(!b)
			{
				cout<<"Please input the number of section you want to divide:(It's better to divide more than 10000)"<<endl;
				if (cin>>n)
				{
					b=true;	
				}
				else
				{
					cout<<"The order you input is illegal!!"<<endl;
					fflush(stdin);
					cin.clear();
				}
			}
			cout<<"Result = "<< integrator_Rimmen(f,lowerlimit,upperlimit,n)<<endl;
			a=true;
		}
		else
		{
			cout<<"The number you input is illegal!!"<<endl;
			a=false;
			fflush(stdin);
			cin.clear();
		}
	}
	return 0;
}