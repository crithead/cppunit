CC = g++
CXXFLAGS = -Wall --std=c++11

SOURCES := gamemain.cpp
SOURCES += item.cpp
SOURCES += player.cpp

OBJECTS := $(SOURCES:.cpp=.o)
DEPENDS := $(SOURCES:.cpp=.d)

EXEC = game

TESTSRC := testmain.cpp
TESTSRC += item.cpp
TESTSRC += itemtest.cpp
TESTSRC += player.cpp
TESTSRC += playertest.cpp

TESTOBJ := $(TESTSRC:.cpp=.o)
TESTDEP := $(TESTSRC:.cpp=.d)

TESTLIB = -lcppunit

TEST = test

all: $(EXEC) $(TEST)

$(EXEC): $(OBJECTS) $(DEPENDS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

$(TEST): $(TESTOBJ) $(TESTDEP)
	$(CC) $(CXXFLAGS) -o $(TEST) $(TESTOBJ) $(TESTLIB)

run: $(TEST)
	./$(TEST)

%.d : %.cpp
	$(CC) -MM -E $< -o $@

-include $(DEPENDS)
-include $(TESTDEP)

.PHONY: print
print:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "DEPENDS: $(DEPENDS)"
	@echo "TESTSRC: $(TESTSRC)"
	@echo "TESTOBJ: $(TESTOBJ)"
	@echo "TESTDEP: $(TESTDEP)"

.PHONY: clean
clean:
	@rm -f *.o *.d
	@rm -f $(EXEC)
	@rm -f $(TEST)


