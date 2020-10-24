该目录的目录结构为：

文件 README.md
文件 stack.h
文件 stack.cpp
目录 example
	文件 README.md
	文件 example.cpp
	文件 Makefile

其中 stack.h 与 stack.cpp 构造了一个栈的模板类，可以实现如下功能：
* 用 "Stack<DataType> A;" 声明一个栈 A；
* 用 "Stack<DataType> B(A);" 或 "Stack<DataType> B = A;" 声明一个栈 B 并用 A 初始化它；
* 用 "A.push(x);" 将 DataType 类型的变量 x 压入栈 A；
* 用 "A.top()" 查看栈顶元素；
* 用 "x = A.pop()" 弹出栈顶元素，并用变量 x 接收它；
* 直接用 "A = B" 将栈 B 拷贝给栈 A；
* 用 "A.empty()" 判断栈 A 是否为空；
* 用 "A.length()" 获取栈 A 中的元素个数；
* 用 "A.inverse()" 倒转栈 A；
* 用 "A.clear()" 手动清空栈 A (包括释放内存)。

目录 example 下的文件是关于这个类使用的一个例子程序，你可以到这个目录下按照其中的 README.md 提示，编译并运行例子程序。

构造这个栈的模板类的目的是为了解析数学表达式。在解析数学表达式的类(类名:MathFunc, 文件位于../MathFunc/)中，将中缀表达式转化为后缀表达式、对后缀表达式求值的操作均用到了栈。