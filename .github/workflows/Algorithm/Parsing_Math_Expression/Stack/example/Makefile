StackPath := ..
StackSource := stack.cpp
StackHead := stack.h
StackObject := stack.o

ExampleSource := example.cpp
ExampleHead := example.h
ExampleObject := example.o
ExampleExe := example

${ExampleExe}: ${ExampleObject} ${StackObject}
	g++ *.o -o ${ExampleExe}

${ExampleObject}: ${ExampleSource} ${StackPath}/${StackHead}
	g++ -I${StackPath} -c ${ExampleSource}
	
${StackObject}: ${StackPath}/${StackSource} ${StackPath}/${StackHead}
	g++ -I${StackPath} -c ${StackPath}/${StackSource}
 
clean:
	rm *.o