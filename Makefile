CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

tests: WordCount.o tddFuncs.o labTests.o
	$(CXX) $(CXXFLAGS) WordCount.o tddFuncs.o labTests.o -o labTests

WordCount.o: WordCount.cpp WordCount.h
	$(CXX) $(CXXFLAGS) -c WordCount.cpp

tddFuncs.o: tddFuncs.cpp tddFuncs.h
	$(CXX) $(CXXFLAGS) -c tddFuncs.cpp

labTests.o: labTests.cpp WordCount.h tddFuncs.h
	$(CXX) $(CXXFLAGS) -c labTests.cpp

clean:
	rm -f *.o labTests
