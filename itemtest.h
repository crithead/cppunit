#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include <cppunit/TestCase.h>

class ItemTest : public CppUnit::TestCase
{
public:
	static CppUnit::Test *suite();

	void setUp();
	void tearDown();

	void testConstructor();
	void testType();
	void testValue();
};

#endif // TEST_ITEM_H

