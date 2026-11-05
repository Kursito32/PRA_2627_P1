bin/testListArray: List.h ListArray.h testListArray.cpp
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cppç

bin/testListLinked: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp


clean:
	rm -f *.o *.pch *.gch
	rm -rf bin
