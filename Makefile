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

-include $(DEPENDS)
-include $(TESTDEP)

$(EXEC): $(SOURCES) $(DEPENDS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

$(TEST): $(TESTSRC) $(TESTDEP)
	$(CC) $(CXXFLAGS) -o $(TEST) $(TESTSRC) $(TESTLIB)

run: $(TEST)
	./$(TEST)

.PHONY: depends
depends:
	@rm -f $(EXEC).d
	$(CC) -MM -E $(SOURCES) > $(EXEC).d
	@rm -f $(TEST).d
	$(CC) -MM -E $(TESTSRC) > $(TEST).d

#$(EXEC).d : $(SOURCES)
#	@rm -f $(EXEC).d
#	$(CC) -MM -E $(SOURCES) > $@

#$(TEST).d : $(TESTSRC)
#	@rm -f $(TEST).d
#	$(CC) -MM -E $(TESTSRC) > $@

%.d : %.cpp
	$(CC) -MM -E $< -o $@

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


