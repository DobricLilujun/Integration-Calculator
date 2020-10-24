#include <stack.h>

int main()
{
	Stack<double> S1;

	// 使用 push 将元素压栈
	S1.push(0.75);
	S1.push(8.64);
	S1.push(9.67);
	S1.push(4.51);
	S1.push(4.63);
	S1.push(8.53);
	S1.push(4.90);

	// 使用 cout 打印栈结构
	cout << "S1 = " << S1 << endl;

	// 调用拷贝构造函数声明一个新栈 S2，并用 S1 初始化它
	Stack<double> S2 = S1;

	cout << "S2 = " << S2 << endl;

	Stack<double> S3;

	// 使用 empty 函数判断栈是否为空
	if(S3.empty())
	{
		cout << "赋值前，S3 为空栈" << endl;
	}

	// 使用 "=" 拷贝 S2 给空栈 S3
	S3 = S2;

	if(!S3.empty())
	{
		cout << "赋值后，S3 = " << S3 << endl;
	}

	// 使用 top 函数查看栈顶元素
	cout << "S3 的栈顶元素为：" << S3.top() << endl;

	// 使用 pop 函数将栈顶元素弹出
	double x = S3.pop();
	cout << "将栈顶元素 " << x << " 弹出后，S3 = " << S3 << endl;

	// 使用 length 函数查看栈的长度
	cout << "S3 的长度为：" << S3.length() << endl;

	S3.inverse();

	// 使用 inverse 函数将栈倒转
	cout << "S3 倒转后为：" << S3 << endl;

	// 使用 clear 函数手动清空栈
	S3.clear();
	cout << "S3 被清空后，S3 = " << S3 << endl;

	return 0;
}