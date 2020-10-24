MathFuncPath := Parsing_Math_Expression/MathFunc
MathFuncHead := mathfunc.h
MathFuncSource := mathfunc.cpp
MathFuncObject := mathfunc.o

Infix2PostfixSource := infix2postfix.cpp
Infix2PostfixObject := infix2postfix.o

StackPath := Parsing_Math_Expression/Stack
StackHead := stack.h
StackSource := stack.cpp
StackObject := stack.o

MatrixPath := .
MatrixHead := matrix.h
MatrixSource := matrix.cpp
MatrixObject := matrix.o

IntegratorPath := .
IntegratorHead := integrator.h
IntegratorSource := integrator.cpp
IntegratorObject := integrator.o

ExampleSource := main.cpp
ExampleObject := main.o
ExampleExe := main

INCLUDE := -I ${MathFuncPath} -I ${StackPath} -I ${MatrixPath} -I ${IntegratorPath}

${ExampleExe}: ${ExampleObject} ${MathFuncObject} ${Infix2PostfixObject} ${StackObject} ${MatrixObject} ${IntegratorObject}
	g++ -std=c++11 *.o -o ${ExampleExe}
	
${ExampleObject}: ${ExampleSource} ${MathFuncPath}/${MathFuncHead} ${MatrixPath}/${MatrixHead}
	g++ -std=c++11 ${INCLUDE} -c ${ExampleSource}
 
${MathFuncObject}: ${MathFuncPath}/${MathFuncSource} ${MathFuncPath}/${MathFuncHead}
	g++ -std=c++11 ${INCLUDE} -c ${MathFuncPath}/${MathFuncSource}

${Infix2PostfixObject}: ${MathFuncPath}/${Infix2PostfixSource} ${MathFuncPath}/${MathFuncHead}
	g++ -std=c++11 ${INCLUDE} -c ${MathFuncPath}/${Infix2PostfixSource}

${StackObject}: ${StackPath}/${StackSource} ${StackPath}/${StackHead}
	g++ -std=c++11 ${INCLUDE} -c ${StackPath}/${StackSource}

${MatrixObject}: ${MatrixPath}/${MatrixSource} ${MatrixPath}/${MatrixHead}
	g++ -std=c++11 ${INCLUDE} -c ${MatrixPath}/${MatrixSource}

${IntegratorObject}: ${IntegratorPath}/${IntegratorSource} ${IntegratorPath}/${IntegratorHead}
	g++ -std=c++11 ${INCLUDE} -c ${IntegratorPath}/${IntegratorSource}

 
clean:
	del *.o