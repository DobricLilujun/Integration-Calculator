#include <mathfunc.h>

// Function: 定义 Element 的输出格式
ostream& operator <<(ostream& o, const Element& X)
{
	switch(X.type)
	{
		case 1: o << X.data; break;
		case 2: o << 'x'; break;
		case 0:
		{
			switch(X.identify)
			{
				case 0 : o << "#"; break;
				case 1 : o << "+"; break;
				case 2 : o << "-"; break;
				case 3 : o << "*"; break;
				case 4 : o << "/"; break;
				case 5 : o << "^"; break;
				case 6 : o << "("; break;
				case 7 : o << ")"; break;

				case 8 : o << "sin"; break;
				case 9 : o << "cos"; break;
				case 10: o << "tan"; break;
				case 11: o << "csc"; break;
				case 12: o << "sec"; break;
				case 13: o << "cot"; break;

				case 14: o << "asin"; break;
				case 15: o << "acos"; break;
				case 16: o << "atan"; break;
				case 17: o << "acsc"; break;
				case 18: o << "asec"; break;
				case 19: o << "acot"; break;

				case 20: o << "sinh"; break;
				case 21: o << "cosh"; break;
				case 22: o << "tanh"; break;
				case 23: o << "csch"; break;
				case 24: o << "sech"; break;
				case 25: o << "coth"; break;

				case 26: o << "asinh"; break;
				case 27: o << "acosh"; break;
				case 28: o << "atanh"; break;
				case 29: o << "acsch"; break;
				case 30: o << "asech"; break;
				case 31: o << "acoth"; break;

				case 32: o << "exp"; break;
				case 33: o << "log"; break;
				case 34: o << "lg"; break;
				case 35: o << "ln"; break;
				case 36: o << "sqrt"; break;
				case 37: o << "abs"; break;

				default: break;
			}
		}
		default: break;
	}

	return o;
}

// Function: 定义 MathFunc 的输出格式，是直接把成员字符串变量输出
ostream& operator <<(ostream& o, const MathFunc& f)
{
	o << f.f_str;
	return o;
}

istream& operator >>(istream& i, MathFunc& f)
{
	string str;
	getline(cin, str);
	f = str;
	return i;
}

MathFunc::MathFunc(){}

MathFunc::MathFunc(const MathFunc& g)
{
	this->Postfix = g.Postfix;
	this->f_str = g.f_str;
}

MathFunc::MathFunc(const string& str)
{
	string empty_str;

	this->f_str = str;
	this->Postfix = infix2postfix(str);

	if( this->Postfix.empty() )
	{
		this->f_str = empty_str;
	}
}

MathFunc::MathFunc(const char* c_str)
{
	string empty_str;
	string str(c_str);

	this->f_str = str;
	this->Postfix = infix2postfix(str);

	if( this->Postfix.empty() )
	{
		this->f_str = empty_str;
	}
}

MathFunc::~MathFunc()
{
	Postfix.clear();
	vector<Element>().swap(Postfix);

	f_str.clear();
	string().swap(f_str);
}

void MathFunc::clear()
{
	this->~MathFunc();
}

bool MathFunc::empty()const
{
	return Postfix.empty();
}

MathFunc& MathFunc::operator =(const MathFunc& X)
{
	this->Postfix = X.Postfix;
	this->f_str = X.f_str;
	return *this;
}

MathFunc& MathFunc::operator =(const string& str)
{
    MathFunc f = str;
    this->Postfix = f.Postfix;
    this->f_str = f.f_str;
	
    return *this;
}

MathFunc& MathFunc::operator =(const char* c_str)
{
    MathFunc f = c_str;
    this->Postfix = f.Postfix;
    this->f_str = f.f_str;
	
    return *this;
}

bool isInt(const double& x)
{
	return ( x == (int)x );
}

int sgn(const double& x)
{
	if(x > 0)
	{
		return 1;
	}
	else if(x == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

double Rand(const double& a, const double& b)
{
	return 1.0 * rand() / (double)RAND_MAX * (b-a) + a;
}

// Function: 计算一元初等函数在某点处的取值
// Description: 例如计算 MathFunc 类型的变量 f 在 x = 0 的取值，即可用 f.eval(0);
// Calls: bool MathFunc::empty();
//		  bool isInt(double);
//		  double Stack<double>::push();
//		  double Stack<double>::pop();
//		  int sgn(double);
// Input: x 的值 (double)
// Output: 一元初等函数在 x 处的取值 (double)
double MathFunc::eval(double x)const
{
	if( this->empty() )
	{
		return WRONG;
	}

	Stack<double> Object;

	Element ele_temp;
	double X, Y;

	for(vector<Element>::const_iterator it = this->Postfix.begin(); it != this->Postfix.end(); it++)
	{
		ele_temp = *it;
		switch(ele_temp.type)
		{
			case 1://ele_temp 是 数字 或 PI
			{
				Object.push(ele_temp.data);
				break;
			}
			case 2://ele_temp 是 x
			{
				Object.push(x);
				break;
			}
			case 0://ele_temp 是 运算符
			{
				int ide = ele_temp.identify;
				if( ide >= 1 && ide <= 5 )
				{
					if(Object.empty())
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return WRONG;
					}
					else
					{
						Y = Object.pop();
					}
					
					if(Object.empty())
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return WRONG;
					}
					else
					{
						X = Object.pop();
					}
					
					switch(ide)
					{
						case 1:/*+*/ Object.push(X + Y); break;
						case 2:/*-*/ Object.push(X - Y); break;
						case 3:/***/ Object.push(X * Y); break;
						case 4:/*/*/
						{
							if(Y == 0)
							{
								cout << endl << "Error in X / Y, Y is 0 now!" << endl;
								return WRONG;
							}
							Object.push(X / Y);
							break;
						}
						case 5:/*^*/
						{
							if(X == 0 && Y < 0)
							{
								cout << endl << "Error in X^Y, X is 0 and Y is negtive now!" << endl;
								return WRONG;
							}
							Object.push( pow(X, Y) );
							break;
						}
					}
				}
				else
				{
					if(Object.empty())
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return WRONG;
					}
					else
					{
						X = Object.pop();
					}
					
					switch(ide)
					{
						case 8://sin
						{
							Object.push( sin(X) );
							break;
						}
						case 9://cos
						{
							Object.push( cos(X) );
							break;
						}
						case 10://tan
						{
							if( isInt( (X-PI/2)/PI ) )
							{
								cout << endl << "Error in tan(x), x is (PI/2 + k*PI) now!" << endl << endl;
								return WRONG;
							}
							Object.push( tan(X) );
							break;
						}
						case 11://csc
						{
							if(sin(X) == 0)
							{
								cout << endl << "Error in csc(x), sin(x) is 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( 1/sin(X) );
							break;
						}
						case 12://sec
						{
							if(cos(X) == 0)
							{
								cout << endl << "Error in sec(x), cos(x) is 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( 1/cos(X) );
							break;
						}
						case 13://cot
						{
							if(tan(X) == 0)
							{
								cout << endl << "Error in cot(x), tan(x) is 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( 1/tan(X) );
							break;
						}
						case 14://asin
						{
							if(X < -1 || X > 1)
							{
								cout << endl << "Error in asin(x), x is out of [-1, 1] now!" << endl << endl;
								return WRONG;
							}
							Object.push( asin(X) );
							break;
						}
						case 15://acos
						{
							if(X < -1 || X > 1)
							{
								cout << endl << "Error in acos(x), x is out of [-1, 1] now!" << endl << endl;
								return WRONG;
							}
							Object.push( acos(X) );
							break;
						}
						case 16://atan
						{
							Object.push( atan(X) );
							break;
						}
						case 17://acsc
						{
							if(X > -1 && X < 1)
							{
								cout << endl << "Error in acsc(x), x is in [-1, 1] now!" << endl << endl;
								return WRONG;
							}
							Object.push( asin(1/X) );
							break;
						}
						case 18://asec
						{
							if(X > -1 && X < 1)
							{
								cout << endl << "Error in asec(x), x is in [-1, 1] now!" << endl << endl;
								return WRONG;
							}
							Object.push( acos(1/X) );
							break;
						}
						case 19://acot
						{
							if(X < 0)
							{
								Object.push( PI + atan(1/X) );
							}
							else if(X > 0)
							{
								Object.push( atan(1/X) );
							}
							else
							{
								Object.push( PI/2 );
							}
							break;
						}
						case 20://sinh
						{
							Object.push( sinh(X) );
							break;
						}
						case 21://cosh
						{
							Object.push( cosh(X) );
							break;
						}
						case 22://tanh
						{
							Object.push( tanh(X) );
							break;
						}
						case 23://csch
						{
							if(X == 0)
							{
								cout << endl << "Error in csch(x), x is 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( 1/sinh(X) );
							break;
						}
						case 24://sech
						{
							Object.push( 1/cosh(X) );
							break;
						}
						case 25://coth
						{
							if(X == 0)
							{
								cout << endl << "Error in coth(x), x is 0  now!" << endl << endl;
								return WRONG;
							}
							Object.push(1/tanh(X));
							break;
						}
						case 26://asinh
						{
							Object.push( asinh(X) );
							break;
						}
						case 27://acosh
						{
							if(X < 1)
							{
								cout << endl << "Error in acosh(x), x < 1 now!" << endl << endl;
								return WRONG;
							}
							Object.push( acosh(X) );
							break;
						}
						case 28://atanh
						{
							if(X <= -1 || X >= 1)
							{
								cout << endl << "Error in atanh(x), x is out of ]-1, 1[ now!" << endl << endl;
								return WRONG;
							}
							Object.push( atanh(X) );
							break;
						}
						case 29://acsch
						{
							if(X == 0)
							{
								cout << endl << "Error in acsch(x), x is 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( log( (1 + sgn(X) * sqrt(1 + X*X)) / x ) );
							break;
						}
						case 30://asech
						{
							if(X <= 0 || X > 1)
							{
								cout << endl << "Error in asech(x), x is out of ]0, 1] now!" << endl << endl;
								return WRONG;
							}
							Object.push( log( (1 + sqrt(1 - X*X)) / x ) );
							break;
						}
						case 31://acoth
						{
							if(X >= -1 || X <= 1)
							{
								cout << endl << "Error in acoth(x), x is in [-1, 1], now!" << endl << endl;
								return WRONG;
							}
							Object.push( 0.5 * log( (x+1)/(x-1) ) );
							break;
						}
						case 32://exp
						{
							Object.push( exp(X) );
							break;
						}
						case 33://log
						{
							if(X <= 0)
							{
								cout << endl << "Error in log(x), x <= 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( log(X) );
							break;
						}
						case 34://lg
						{
							if(X <= 0)
							{
								cout << endl << "Error in lg(x), x <= 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( log10(X) );
							break;
						}
						case 35://ln
						{
							if(X <= 0)
							{
								cout << endl << "Error in ln(x), x <= 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( log(X) );
							break;
						}
						case 36://sqrt
						{
							if(X < 0)
							{
								cout << endl << "Error in sqrt(x), x < 0 now!" << endl << endl;
								return WRONG;
							}
							Object.push( sqrt(X) );
							break;
						}
						case 37://abs
						{
							Object.push( fabs(X) );
							break;
						}
					}
				}
				break;
			}
		}
	}
    if(Object.length()!=1)
	{
		cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
		return WRONG;
	}
	else
	{
		if( abs( Object.top() ) <= 0.0000001 )
		{
			return 0;
		}
		else
		{
			return Object.top();
		}
	}
}

double MathFunc::max(double a, double b)const
{
	int n = 2000;
	double step = (b-a)/n;
	double x = a;

    srand((unsigned)time(NULL));
    double MAX = eval(Rand(a, b));
    if(MAX == WRONG)
    {
        MAX = eval(Rand(a, b));
    }

	for(int i = 0; i < n; i++)
	{
		x += step;
		double y = eval(x);

        if(y != WRONG && y > MAX)
		{
			MAX = y;
		}
	}

	return MAX;
}

double MathFunc::min(double a, double b)const
{
	int n = 2000;
	double step = (b-a)/n;
	double x = a;

    srand((unsigned)time(NULL));
    double MIN = eval(Rand(a, b));
    if(MIN == WRONG)
    {
        MIN = eval(Rand(a, b));
    }

	for(int i = 0; i < n; i++)
	{
		x += step;
		double y = eval(x);
        if(y != WRONG && y < MIN)
		{
			MIN = y;
		}
	}

	return MIN;
}