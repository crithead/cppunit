#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#define USE_HELPER_MACRO 1

#include <cppunit/TestCase.h>

#if USE_HELPER_MACRO
#include <cppunit/extensions/HelperMacros.h>
#endif

class ItemTest : public CppUnit::TestCase
{
#if USE_HELPER_MACRO
	CPPUNIT_TEST_SUITE( ItemTest );
	CPPUNIT_TEST( testConstructor );
	CPPUNIT_TEST( testType );
	CPPUNIT_TEST( testValue );
	CPPUNIT_TEST_SUITE_END();
#else
public:
	static CppUnit::Test *suite();
#endif // USE_HELPER_MACRO

	void testConstructor();
	void testType();
	void testValue();

public:
	void setUp();
	void tearDown();
};

#endif // TEST_ITEM_H

