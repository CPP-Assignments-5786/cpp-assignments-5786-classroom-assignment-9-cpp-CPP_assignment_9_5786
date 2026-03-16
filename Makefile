CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
SOURCES=StudentRecord.cpp CourseManager.cpp StringUtils.cpp Riddles.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp StudentRecord.hpp CourseManager.hpp StringUtils.hpp TypeTraitsUtils.hpp Riddles.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

StudentRecord.o: StudentRecord.cpp StudentRecord.hpp

CourseManager.o: CourseManager.cpp CourseManager.hpp StudentRecord.hpp

StringUtils.o: StringUtils.cpp StringUtils.hpp

Riddles.o: Riddles.cpp Riddles.hpp

main.o: main.cpp StudentRecord.hpp CourseManager.hpp StringUtils.hpp TypeTraitsUtils.hpp Riddles.hpp

clean:
	rm -f *.o demo test