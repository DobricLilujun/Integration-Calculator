MathFuncPath := ..
MathFuncHead := mathfunc.h
MathFuncSource := mathfunc.cpp
MathFuncObject := mathfunc.o

Infix2PostfixSource := infix2postfix.cpp
Infix2PostfixObject := infix2postfix.o

StackPath := ../../Stack
StackHead := stack.h
StackSource := stack.cpp
StackObject := stack.o

ExampleSource := calculator.cpp
ExampleObject := calculator.o
ExampleExe := calculator


${ExampleExe}: ${ExampleObject} ${MathFuncObject} ${Infix2PostfixObject} ${StackObject}
	g++ *.o -o ${ExampleExe}
	
${ExampleObject}: ${ExampleSource} ${MathFuncPath}/${MathFuncHead}
	g++ -I ${MathFuncPath} -I ${StackPath} -c ${ExampleSource}
 
${MathFuncObject}: ${MathFuncPath}/${MathFuncSource} ${MathFuncPath}/${MathFuncHead}
	g++ -I ${MathFuncPath} -I ${StackPath} -c ${MathFuncPath}/${MathFuncSource}

${Infix2PostfixObject}: ${MathFuncPath}/${Infix2PostfixSource} ${MathFuncPath}/${MathFuncHead}
	g++ -I ${MathFuncPath} -I ${StackPath} -c ${MathFuncPath}/${Infix2PostfixSource}

${StackObject}: ${StackPath}/${StackSource} ${StackPath}/${StackHead}
	g++ -I ${StackPath} -c ${StackPath}/${StackSource}
 
clean:
	del *.o