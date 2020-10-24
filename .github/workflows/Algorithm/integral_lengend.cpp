#include "integral.h"

string change_string(string input)
{
	string  a="(  ((b-a)/2)*x + ((b+a)/2)  )";
	int flag = 0;
	string code;
	string output;

	while(input[flag]!='\0')
	{
		if(input[flag]=='x')
		{
			code=code+a;
			flag++;
		}
		else
		{
			code=code+input[flag];
			flag++;
		}
	}

	// char result[code.length()+1];
	output = code;
	return output;
}

double integral_legende(string input_string, double upperlimit, double lowerlimit, int n)
{
    string upperlimit_str, lowerlimit_str, n_str;
	stringstream ss;
	ss << upperlimit;
	ss >> upperlimit_str;
	ss.clear();
	ss.str("");
	ss << lowerlimit;
	ss >> lowerlimit_str;
	ss.clear();
	ss.str("");
	ss << n;
	ss >> n_str;
	string mid_code = change_string(input_string);
	ofstream outfile("create.cpp");
	
	string pre_code = "#include <stdio.h>\n"
	"#include <sstream>\n"
	"#include <stdlib.h>\n"
	"#include <string>\n"
	"#include <math.h>\n"
	"#include <sstream>\n"
	"#include <fstream>\n"
    "#include <iostream>\n\n"
    "using namespace std;\n\n"
	"int main()\n"
    "{\n"
    "   double a=" + lowerlimit_str + ";\n"
    "   double b=" + upperlimit_str + ";\n"
    "   int n=" + n_str + ";\n"
    "   double sum=0;\n"
    "   double x=0;\n"
    "   double *coeff;\n"
    "   double *t;\n"
    "   switch("+n_str+")\n"
    "   {\n"
	"		case 1:\n"
	"		{\n"
	"			coeff=(double *)malloc(1*sizeof(double));\n"
	"			t=(double *)malloc(1*sizeof(double));\n"
	"			coeff[0]=2, t[0]=0;\n"
	"			break;\n"
	"		}\n"
	"		case 2:\n"
	"		{"
	"			coeff=(double *)malloc(2*sizeof(double));\n"
	"			t=(double *)malloc(2*sizeof(double));\n"
	"			coeff[0]=1,t[0]=0.5773502692;\n"
	"			coeff[1]=1,t[1]=-0.5773502692;\n"
	"			break;\n"
	"		}\n"
	"		case 3:\n"
	"		{\n"
	"			coeff=(double *)malloc(3*sizeof(double));\n"
	"			t=(double *)malloc(3*sizeof(double));\n"
	"			coeff[0]=0.5555555556,t[0]=0.77459666920;\n"
	"			coeff[1]=0.5555555556,t[1]=-0.77459666920;\n"
	"			coeff[2]=0.8888888889,t[2]=0;\n"
	"			break;\n"
	"		}\n"
	"		case 4:\n"
	"		{\n"
	"			coeff=(double *)malloc(4*sizeof(double));\n"
	"			t=(double *)malloc(4*sizeof(double));\n"
	"			coeff[0]=0.3478548451,t[0]=0.8611363116;\n"
	"			coeff[1]=0.3478548451,t[1]=-0.8611363116;\n"
	"			coeff[2]=0.6521451549,t[2]=0.3399810436;\n"
	"			coeff[3]=0.6521451549,t[3]=-0.3399810436;\n"
	"			break;\n"
	"		}\n"
	"		case 5:\n"
	"		{"
	"			coeff=(double *)malloc(5*sizeof(double));\n"
	"			t=(double *)malloc(5*sizeof(double));\n"
	"			coeff[0]=0.2369268851,t[0]=0.9061798459;\n"
	"			coeff[1]=0.2369268851,t[1]=-0.9061798459;\n"
	"			coeff[2]=0.4786286705,t[2]=0.53845931010;\n"
	"			coeff[3]=0.4786286705,t[3]=-0.53845931010;\n"
	"			coeff[4]=0.5688888889,t[4]=0;\n"
	"			break;\n"
	"		}\n"
	"		case 6:\n"
	"		{\n"
	"			coeff=(double *)malloc(6*sizeof(double));\n"
	"			t=(double *)malloc(6*sizeof(double));\n"
	"			coeff[0]=0.1713244924,t[0]=0.9324695142;\n"
	"			coeff[1]=0.1713244924,t[1]=-0.9324695142;\n"
	"			coeff[2]=0.3607615730,t[2]=0.6612093865;\n"
	"			coeff[3]=0.3607615730,t[3]=-0.6612093865;\n"
	"			coeff[4]=0.4679139346,t[4]=0.2386191816;\n"
	"			coeff[5]=0.4679139346,t[5]=-0.2386191816;\n"
	"			break;\n"
	"		}\n"
	"		case 7:\n"
	"		{\n"
	"			coeff=(double *)malloc(7*sizeof(double));\n"
	"			t=(double *)malloc(7*sizeof(double));\n"
	"			coeff[0]=0.1294849662,t[0]=0.9491079123;\n"
	"			coeff[1]=0.1294849662,t[1]=-0.9491079123;\n"
	"			coeff[2]=0.2797053915,t[2]=0.7415311856;\n"
	"			coeff[3]=0.2797053915,t[3]=-0.7415311856;\n"
	"			coeff[4]=0.3818300505,t[4]=0.4058451514;\n"
	"			coeff[5]=0.3818300505,t[5]=-0.4058451514;\n"
	"			coeff[6]=0.4179591834,t[6]=0;\n"
	"			break;"
	"		}\n"
	"		case 8:\n"
	"		{\n"
	"			coeff=(double *)malloc(8*sizeof(double));\n"
	"			t=(double *)malloc(8*sizeof(double));\n"
	"			coeff[0]=0.1012285363,t[0]=0.9602898565;\n"
	"			coeff[1]=0.1012285363,t[1]=-0.9602898565;\n"
	"			coeff[2]=0.2223810345,t[2]=0.7966664774;\n"
	"			coeff[3]=0.2223810345,t[3]=-0.7966664774;\n"
	"			coeff[4]=0.3137066459,t[4]=0.5255324099;\n"
	"			coeff[5]=0.3137066459,t[5]=-0.5255324099;\n"
	"			coeff[6]=0.3626837834,t[6]=0.1834346425;\n"
	"			coeff[7]=0.3626837834,t[7]=-0.1834346425;\n"
	"			break;\n"
	"		}\n"
	"		default:\n"
	"		{\n"
	"			printf(\"Fetal error:The accuracy is between '0'to'8'!!\");\n"
	"		}\n"	
	"	}\n"
	"	for(int i=0;i<n;i++)\n"
	"	{\n"
	"		x=t[i];\n"
	"		sum = sum + coeff[i] * (";
	outfile << pre_code;
	string temp = change_string(input_string);
	outfile << temp;
	string after_code = ");\n"
                        "	}\n"
						"	double result =(b-a)/2*sum;\n"
						"	ofstream outfile(\"result.txt\");\n"
						"	stringstream ss;\n"
						"	string result_str;\n"
						"	ss << result;\n"
						"	ss >> result_str;\n"
						"	outfile << result_str;\n"
						"}\n";
	outfile << after_code;
	outfile.close();

//    ShellExecute(NULL,TEXT("open"),TEXT("cmd.exe"),TEXT("/c g++ -o create.exe create.cpp && create.exe"),NULL,SW_HIDE);
    system("cmd /c g++ -o create.exe create.cpp && create.exe&");




	string result_str;
    ifstream infile("result.txt");
    getline(infile, result_str);
    while(result_str.empty())
    {
        infile = ifstream("result.txt");
        getline(infile, result_str);
    }

    infile.close();
//    ShellExecute(NULL,TEXT("open"),TEXT("cmd.exe"),TEXT("/c del create.cpp create.exe result.txt"),NULL,SW_HIDE);
    system("cmd /c del create.cpp create.exe result.txt");
    double result;
	ss.clear();
	ss.str("");
	ss << result_str;
	ss >> result;
	return result;
}
int main()
{
	double a=integral_legende("sin(x)",0,8);
	cout <<a<<endl;
}