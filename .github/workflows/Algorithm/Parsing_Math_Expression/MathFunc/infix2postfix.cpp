#include <mathfunc.h>
#include <algorithm>

// Function: 判断一个字符是否为数字或"."，如果是则返回 true
// Input: 一个字符 (char)
// Output: 其是否为数字或"."的指标 (bool)
bool isNumber(char ch)
{
    return ( (ch >= '0' && ch <= '9') || ch == '.');
}

// Function: 判断一个字符是否为字母，如果是则返回 true
// Input: 一个字符 (char)
// Output: 其是否为字母的指标 (bool)
bool isLetter(char ch)
{
    return ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') );
}

// Function: 判断一个字符是否为正常的运算符，如果是则返回 true
// Input: 一个字符 (char)
// Output: 其是否为正常运算符的指标 (bool)
bool isNormal(char ch)
{
	return ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
			 ch == '^' || ch == '#' || ch == '(' || ch == ')'   );
}

double string2double(const string& str)
{
	double result;
	stringstream ss;
	ss << str;
	ss >> result;
	return result;
}

// Function: 对字符串进行预处理，处理内容包括：
//			 - 删除字符串中的所有空格；
//			 - 若字符串首个字符为减号"-"，则在"-"前加"0"
//			 - 将结构 "(-" 变为 "(0-"
//			 - 在字符串结尾加上 "#"
// Input: 一个字符串 (string)
// Output: 按照指定规则将其预处理
// Return: void
bool prepare(string& str)
{
    unsigned i = 0;
	// 删除字符串中的所有空格
	while(i != str.size())
	{
        if(str[i] == '#')
        {
            return true;
        }
		if(str[i] == ' ')
		{
			str.erase(i, 1);
		}
		i++;
	}

	// 若字符串首个字符为减号"-"，则在"-"前加"0"
	i = 0;
	if(str[i] == '-')
	{
		str.insert(i, "0");
	}

	// 将结构 "(-" 变为 "(0-"
	while(i != str.size())
	{
		if(str[i] == '(' && str[i+1] == '-')
		{
			str.insert(i+1, "0");
		}
		i++;
	}

    // 将字符串所有大写字母转成小写
    transform(str.begin(), str.end(), str.begin(), ::tolower);

	// 在字符串结尾加上 "#"
	str = str + "#";

    return false;
}

// Function: 获取字符串在位置 i 处的三角函数名，将其作为一个表达式元素返回；同时将 i 移到三角函数名结束后的位置
// Input: 数学表达式字符串(string)，指定位置 i (int)
// Output: 返回三角函数名(Element)，将 i 移到三角函数名结束后的位置
// Return: 三角函数名(Element)
Element getTriangle(string str, int& i)
{
	switch(str[i])
	{
		case 's':
		{
			switch(str[i+1])
			{
				case 'i':
				{
					switch(str[i+2])
					{
						case 'n':
						{
							switch(str[i+3])
							{
								case 'h':
								{
									switch(str[i+4])
									{
										case '(': i += 4; return Element(0, 20, 0);//sinh
										default :
										{
											cout << endl << "The format of the input math expresion is wrong!" << endl;
											return Element(-1, 0, 0);
										}
									}
								}
								case '(': i += 3; return Element(0, 8, 0);//sin
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						default:
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
				case 'e':
				{
					switch(str[i+2])
					{
						case 'c':
						{
							switch(str[i+3])
							{
								case 'h':
								{
									switch(str[i+4])
									{
										case '(': i += 4; return Element(0, 24, 0);//sech
										default :
										{
											cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
											return Element(-1, 0, 0);
										}
									}
								}
								case '(': i += 3; return Element(0, 12, 0);//sec
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						default:
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
				default:
				{
					cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
					return Element(-1, 0, 0);
				}
			}
		}
		case 'c':
		{
			switch(str[i+1])
			{
		/*c*/	case 'o':
				{
					switch(str[i+2])
					{
						case 's':
						{
							switch(str[i+3])
							{
								case 'h':
								{
									switch(str[i+4])
									{
										case '(': i += 4; return Element(0, 21, 0);//cosh
										default :
										{
											cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
											return Element(-1, 0, 0);
										}
									}
								}
								case '(': i += 3; return Element(0, 9, 0);//cos
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						case 't':
						{
							switch(str[i+3])
							{
								case 'h':
								{
									switch(str[i+4])
									{
										case '(': i += 4; return Element(0, 25, 0);//coth
										default :
										{
											cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
											return Element(-1, 0, 0);
										}
									}
								}
								case '(': i += 3; return Element(0, 13, 0);//cot
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						default :
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
		/*c*/	case 's':
				{
					switch(str[i+2])
					{
						case 'c':
						{
							switch(str[i+3])
							{
								case '(': i += 3; return Element(0, 11, 0);//csc
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						default :
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
		/*c*/	case 't':
				{
					switch(str[i+2])
					{
						case 'h':
						{
							switch(str[i+3])
							{
								case '(': i += 3; return Element(0, 25, 0);//cth
								default :
								{
									cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
									return Element(-1, 0, 0);
								}
							}
						}
						default :
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
				default :
				{
					cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
					return Element(-1, 0, 0);
				}
			}
		}
		case 't':
		{
			switch(str[i+1])
			{
				case 'a':
				{
					switch(str[i+2])
					{
						case 'n':
						{
							switch(str[i+3])
							{
								case 'h':
								{
									switch(str[i+4])
									{
										case '(': i += 2; return Element(0, 22, 0);//tanh
										default :
										{
											cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
											return Element(-1, 0, 0);
										}
									}
								}
								case '(': i += 3; return Element(0, 10, 0);//tan
							}
						}
						default :
						{
							cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
							return Element(-1, 0, 0);
						}
					}
				}
				default :
				{
					cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
					return Element(-1, 0, 0);
				}
			}
		}
		case 'a':
		{
			i++;
			Element elem_temp = getTriangle(str, i);
            elem_temp.identify += 6;
			return elem_temp;
		}
		default:
		{
			cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
			return Element(-1, 0, 0);
		}
	}
}

// Function: 获取字符串在位置 i 处的特殊函数名，将其作为一个表达式元素返回；同时将 i 移到特殊函数名结束后的位置
// Input: 数学表达式字符串(string)，指定位置 i (int)
// Output: 返回特殊函数名(Element)，将 i 移到特殊函数名结束后的位置
// Return: 特殊函数名(Element)
Element getSpecial(string str, int& i)
{
	switch(str[i])
	{
		case 'e':
		{
			if(str[i+1] == 'x' && str[i+2] == 'p' && str[i+3] == '(')
			{
				i += 3;
				return Element(0, 32, 0);//exp
			}
			else
			{
				cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
				return Element(-1, 0, 0);
			}
		}
		case 'l':
		{
			switch(str[i+1])
			{
				case 'o':
				{
					if(str[i+2] == 'g' && str[i+3] == '(')
					{
						i += 3;
						return Element(0, 33, 0);//log
					}
					else
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return Element(-1, 0, 0);
					}
				}
				case 'g':
				{
					if(str[i+2] == '(')
					{
						i += 2;
						return Element(0, 34, 0);//lg
					}
					else
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return Element(-1, 0, 0);
					}
				}
				case 'n':
				{
					if(str[i+2] == '(')
					{
						i += 2;
						return Element(0, 35, 0);//ln
					}
					else
					{
						cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
						return Element(-1, 0, 0);
					}
				}
				default :
				{
					cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
					return Element(-1, 0, 0);
				}
			}
		}
		case 's':
		{
			if(str[i+1] == 'q' && str[i+2] == 'r' && str[i+3] == 't' && str[i+4] == '(')
			{
				i += 4;
				return Element(0, 36, 0);
			}
			else
			{
				return getTriangle(str, i);
			}
		}
		case 'p':
		case 'P':
		{
			switch(str[i+1])
			{
				case 'i':
				case 'I':
				{
					i += 2;
					return Element(1, 0, PI); // PI
				}
				default :
				{
					cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
					return Element(-1, 0, 0);
				}
			}
		}
		case 'a':
		{
			if(str[i+1] == 'b' && str[i+2] == 's' && str[i+3] == '(')
			{
				i += 3;
				return Element(0, 37, 0); // abs
			}
		}
		default: return getTriangle(str, i);
	}
}

// Function: 获取字符串在位置 i 处的数字，将其作为一个表达式元素返回；同时将 i 移到数字结束后的位置
// Input: 数学表达式字符串(string)，指定位置 i (int)
// Output: 返回数字对应的表达式元素(Element)，将 i 移到数字结束后的位置
// Return: 数字对应的表达式元素(Element)
Element getNumber(string str, int& i)
{
	int i0 = i;
	while( isNumber(str[i]) )
	{
		i++;
	}

	return Element(1, 0, string2double( str.substr(i0, i-i0) ) );
}

// Function: 获取字符串在位置 i 处的表达式元素；同时将 i 移到表达式元素结束后的位置
// Input: 数学表达式字符串(string)，指定位置 i (int)
// Output: 返回 i 处的表达式元素(Element)，将 i 移动到表达式元素结束后的位置
// Return: i 处的表达式元素(Element)
Element getElement(string str, int& i)
{
	if( isNumber(str[i]) )
	{
		return getNumber(str, i);
	}
	else if( str[i] == 'x' )
	{
		i++;
		return Element(2, 1, 0);
	}
	else if( isNormal(str[i]) )
	{
		i++;
		switch(str[i-1])
		{
			case '#': return Element(0, 0, 0);
			case '+': return Element(0, 1, 0);
			case '-': return Element(0, 2, 0);
			case '*': return Element(0, 3, 0);
			case '/': return Element(0, 4, 0);
			case '^': return Element(0, 5, 0);
			case '(': return Element(0, 6, 0);
			case ')': return Element(0, 7, 0);
            default : return Element(-1, 0, 0);
		}
	}
	else if( isLetter(str[i]) )
	{
		return getSpecial(str, i);
	}
	else
	{
		cout << endl << "The format of the input math expresion is wrong!" << endl << endl;
		return Element(-1, 0, 0);
	}
}

// Function: 计算运算符的栈内优先级
// Input: 运算符(Element)
// Return: 运算符所对应的栈内优先级(int)
int inner_priority(Element elem)
{
	switch(elem.identify)
	{
		case 0:/*#*/ return 0;
		case 1:/*+*/
		case 2:/*-*/ return 3;
		case 3:/***/
		case 4:/*/*/ return 5;
		case 5:/*^*/ return 7;
		case 6:/*(*/ return 1;
		case 7:/*)*/ return 10;
		default:	 return 9;
	}
}

// Function: 计算运算符的栈外优先级
// Input: 运算符(Element)
// Return: 运算符所对应的栈外优先级(int) 
int outer_priority(Element elem)
{
	switch(elem.identify)
	{
		case 0:/*#*/ return 0;
		case 1:/*+*/
		case 2:/*-*/ return 2;
		case 3:/***/
		case 4:/*/*/ return 4;
		case 5:/*^*/ return 6;
		case 6:/*(*/ return 10;
		case 7:/*)*/ return 1;
		default:	 return 8;
	}
}

// Function: 将中缀表达式字符串转换为后缀表达式的元素序列
// Calls: void prepare(string);
//		  Element getElement(string, int&);
//		  int inner_priority(Element);
//		  int outer_priority(Element);
// Input: 中缀表达式的字符串 (string)
// Return: 后缀表达式的元素序列 ( vector<Element> )
vector<Element> infix2postfix(const string& infix_expression)
{
	string str = infix_expression;
    Stack<Element> Operators;
    vector<Element> Postfix;
    vector<Element> Empty_Postfix;

    bool has_pound_key = prepare(str);
    if(has_pound_key)
    {
        return Empty_Postfix;
    }

	Element end(0, 0, 0);//#
	Operators.push( end );

	int n = str.size();
	int i = 0;
	Element elem = getElement(str, i);
	if( elem.type == -1 )
	{
		return Empty_Postfix;
	}
	while(i != n || Operators.top() != end)
	{
		if(elem.type == 1 || elem.type == 2)
		{
			Postfix.push_back(elem);
			elem = getElement(str, i);
			if( elem.type == -1 )
			{
				return Empty_Postfix;
			}
		}
		else
		{
			if( outer_priority(elem) > inner_priority( Operators.top() ) )
			{
				Operators.push( elem );
				elem = getElement(str, i);
				if( elem.type == -1 )
				{
					return Empty_Postfix;
				}
			}
			else if( outer_priority(elem) < inner_priority( Operators.top() ) )
			{
				Postfix.push_back( Operators.pop() );
			}
			else //if( outer_priority(elem) == inner_priority( Operators.top() ) )
			{
				Element elem_temp = Operators.pop();
				if( elem_temp.identify == 6/*(*/ )
				{
					elem = getElement(str, i);
					if( elem.type == -1 )
					{
						return Empty_Postfix;
					}
				}
			}
		}
	}

	return Postfix;
}
