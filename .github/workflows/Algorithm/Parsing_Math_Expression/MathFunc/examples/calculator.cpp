#include <mathfunc.h>

int main()
{
	MathFunc f;

	cout << endl;
	while(1)
	{
		cout << ">>  ";
		cin  >> f;
		double result = f.eval();
		if(result != WRONG)
		{
			cout << endl << "  = " << result << endl << endl;
		}
	}
	cout << endl;

	return 0;
}