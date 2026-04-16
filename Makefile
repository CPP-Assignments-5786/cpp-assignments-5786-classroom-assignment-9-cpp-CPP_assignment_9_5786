CXX=clang++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
TIDY_FLAGS=-checks=bugprone-*,-bugprone-easily-swappable-parameters,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=*
TIDY_EXCLUDE=test.cpp main.cpp StudentTest.cpp

SOURCES=StudentRecord.cpp CourseManager.cpp StringUtils.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

grade: test tidy

test: TestRunner.o $(OBJECTS) student_test
	$(CXX) $(CXXFLAGS) TestRunner.o $(OBJECTS) -o test
	./test

student_test: StudentTestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o student_test
	@count=$$(./student_test -ltc | grep -c "^[^[]"); \
	if [ $$count -lt 20 ]; then \
		echo "ERROR: StudentTest.cpp must contain at least 20 test cases (found $$count)"; \
		exit 1; \
	fi

TestRunner.o: test.cpp StudentRecord.hpp CourseManager.hpp StringUtils.hpp TypeTraitsUtils.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

StudentTestRunner.o: StudentTest.cpp $(wildcard *.hpp) doctest.h
	$(CXX) $(CXXFLAGS) --compile StudentTest.cpp -o StudentTestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

StudentRecord.o: StudentRecord.cpp StudentRecord.hpp

CourseManager.o: CourseManager.cpp CourseManager.hpp StudentRecord.hpp

StringUtils.o: StringUtils.cpp StringUtils.hpp

main.o: main.cpp StudentRecord.hpp CourseManager.hpp StringUtils.hpp TypeTraitsUtils.hpp

tidy:
	clang-tidy $(filter-out $(TIDY_EXCLUDE), $(wildcard *.cpp)) $(TIDY_FLAGS) -- $(CXXFLAGS)

clean:
	rm -f *.o demo test student_test

.PHONY: all test clean tidy student_test grade
