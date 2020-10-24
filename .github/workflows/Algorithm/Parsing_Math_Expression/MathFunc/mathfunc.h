// Copyright: 2017 TimeCoder
// Author: TimeCoder
// Date: 2017-08-5
// Description: 这个程序实现了构造一个一元初等函数类 MathFunc.
// 所谓初等函数，即是由常函数、幂函数、指数函数、对数函数、三角函数和反三角函数
// 经过有限次的有理运算（加、减、乘、除、有限次乘方、有限次开方）及有限次函数复合所产生，
// 并且在定义域上能用一个方程式表示的函数。而一元初等函数则是只有一个自变量的初等函数。
// 于是一个一元初等函数便可以由一个仅含一个未知数 x 的表达式唯一确定。
// 对数学表达式字符串进行语法分析并求值便成了程序设计的关键。该程序采用栈分析法实现了解析表达式的功能。
// 该该程序使用起来极其方便，可以直接通过字符串来定义 MathFunc 变量，
// 并可直接调用类内函数求得数学函数在某点处的函数值。例如：
//
// MathFunc f("exp(x)+(x^2-1)*sin(x)");  // 定义一个初等函数 f, 它的表达式为：f(x) = exp(x)+(x^2-1)*sin(x)
// cout << f.eval(0) << endl;  // 输出初等函数 f 在 0 处的取值

#ifndef MATHFUNC_H
#define MATHFUNC_H

#include <stack.h>

#include <cmath>
#include <math.h>
#include <sstream>
#include <vector>
#include <cfloat>
#include <time.h>

#define PI 3.1415926536
#define WRONG DBL_MAX

// 定义 Element 类(表达式元素类)，用于存储表达式中的各元素，包括运算符(如 +)、数字(如 7.68)、函数名(如 tan)、x
class Element
{
	friend ostream& operator <<(ostream&o, const Element& X);

public:
	int type;		// 用于区分某个 Element 究竟是运算符、数字还是x。0 为运算符，1 为数字，2 为 x，-1 为错误
	int identify;	// 用于给运算符编号，例如 + 的 identify 为 1，sin 的 identyfy 为 8，其他运算符的编号可在 ./Note/Element.txt 中查看
	double data;	// 如果某个 Element 是数字，data 用于存储其真实数值；其余情况 data 置 0

public:
	Element()
	{
		this->type = 0;
		this->identify = 0;
		this->data = 0;
	}

	Element(int t, int i, double d)
	{
		this->type = t;
		this->identify = i;
		this->data = d;
	}

	Element(const Element& X)
	{
		this->type = X.type;
		this->identify = X.identify;
		this->data = X.data;
	}

	Element& operator =(const Element& X)
	{
		this->type = X.type;
		this->identify = X.identify;
		this->data = X.data;
		return *this;
	}

	bool operator ==(const Element& X)
	{
		return (this->type == X.type && this->identify == X.identify && this->data == X.data);
	}

	bool operator !=(const Element& X)
	{
		return !(*this == X);
	}
};

// 定义 MathFunc 类(一元初等函数类)，这是最终目标
class MathFunc
{
	friend ostream& operator <<(ostream& o, const MathFunc& f);
	friend istream& operator >>(istream& i, MathFunc& f);

public:
	vector<Element> Postfix;	// 用于存储后缀表达式的表达式元素顺序
	string f_str;				// 用于存储原始(中缀)数学表达式的字符串

public:
    double rectangle_integral(double a, double b, int n, double* t_result=NULL);
    double trapezoid_integral(double a, double b, int n, double* t_result=NULL);
    double Simpson_integral(double a, double b, int n, double* t_result=NULL);
    double variable_step_trapezoid_integral(double a, double b, int n, double epsilon, int times_max, double* t_result=NULL, int* n_result=NULL, double* delta_result=NULL, int* times_result=NULL);
    double variable_step_Simpson_integral(double a, double b, int n, double epsilon, int times_max, double* t_result=NULL, int* n_result=NULL, double* delta_result=NULL, int* times_result=NULL);
    double Newton_Cotes_integral(double a, double b, int n, double* t_result=NULL);
    double Legendre_Gauss_integral(double a, double b, int n, double* t_result=NULL);
    double Hermite_Gauss_integral(double a, double b, int n, double* t_result=NULL);
    double Laguerre_Gauss_integral(double a, double b, int n, double* t_result=NULL);
    double Romberg_integral(double a, double b, double epsilon, int times_max, double* t_result=NULL, double* delta_result=NULL, int* times_result=NULL);
    double Monte_Carlo_integral(double a, double b, int n, double* t_result=NULL);

    double integral(double a, double b, int method=7, int n=0, double epsilon=0, int times_max=0, double* t_result=NULL, int* n_result=NULL, double* delta_result=NULL, int* times_result=NULL);

public:
    MathFunc();
	MathFunc(const string& str);
	MathFunc(const char* c_str);
	MathFunc(const MathFunc& g);
	~MathFunc();

	// Function: MathFunc 赋值运算符 "=" 的重载，使同类能相互赋值
    // Description: 对 MathFunc 类型变量，利用等号进行赋值时，直接克隆。
    // Input: 一个 MathFunc 类型的变量
    // Output: 一个 MathFunc 类型的变量
	MathFunc& operator =(const MathFunc& X);

	// Function: MathFunc 赋值运算符 "=" 的重载，使 string 能给 MathFunc 赋值
    // Description: 例如想将一个 MathFunc 类型的变量 f 定义为 "x^2+1" 所对应的 MathFunc，
    //				可直接利用语句 f = "x^2+1";
    // Input: 一个 MathFunc 类型的变量
    // Output: 一个数学表达式的字符串
    MathFunc& operator =(const string& str);
    MathFunc& operator =(const char* c_str);
	
	// Function: MathFunc 变量的析构函数
    // Description: 将 MathFunc 类型的变量 f 清空销毁，可直接用 f.clear();
    // Input: void
    // Output: void
	void clear();

	// Function: 判断一个 MathFunc 变量是否为空
    // Description: 若 MathFunc 类型变量 f 为空，则 f.empty() 返回 true
    // Input: void
    // Output: 判断变量是否为空的 bool 类型的指标
	bool empty()const;
	
	// Function: 计算一元初等函数在某点处的取值
    // Description: 例如计算 MathFunc 类型的变量 f 在 x = 0 的取值，即可用 f.eval(0);
    // Input: x 的值，double 类型
    // Output: 一元初等函数在 x 处的取值，double 类型
    double eval(double x=0.)const;

    double max(double a, double b)const;
    double min(double a, double b)const;
};

// Function: 将中缀表达式转换为后缀表达式
// Input: 中缀表达式的字符串 (string)
// Output: 后缀表达式的元素序列 ( vector<Element> )
// Return: 后缀表达式的元素序列 ( vector<Element> )
vector<Element> infix2postfix(const string& str);

#endif
