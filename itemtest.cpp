// itemtest.cpp
#include <cstring>
#include <stdexcept>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestSuite.h>

#include "item.h"
#include "itemtest.h"

CppUnit::Test *ItemTest::suite()
{
	CppUnit::TestSuite *testSuite = new CppUnit::TestSuite( "ItemTest" );

	testSuite->addTest( new CppUnit::TestCaller<ItemTest>(
			"testConstructor", &ItemTest::testConstructor ) );
	testSuite->addTest( new CppUnit::TestCaller<ItemTest>(
			"testType", &ItemTest::testType ) );
	testSuite->addTest( new CppUnit::TestCaller<ItemTest>(
			"testValue", &ItemTest::testValue ) );

	return testSuite;
}

void ItemTest::setUp()
{
}

void ItemTest::tearDown()
{
}

#define NAME "The Two Ring"
#define TYPE Item::Ring

void ItemTest::testConstructor()
{
	Item item( NAME, TYPE  );
	CPPUNIT_ASSERT( strcmp( item.Name().c_str(), NAME ) == 0 );
	CPPUNIT_ASSERT( item.Type() == TYPE );
	CPPUNIT_ASSERT( item.Uid() == 0 );
	CPPUNIT_ASSERT( item.Value() == 0 );
}

void ItemTest::testValue()
{
	Item item( NAME, TYPE );
	CPPUNIT_ASSERT( item.Value() == 0 );
	item.SetValue( 10 );
	CPPUNIT_ASSERT( item.Value() == 10 );
	item.SetValue( 99 );
	CPPUNIT_ASSERT( item.Value() == 99 );

	CPPUNIT_ASSERT_THROW( item.SetValue( -10 ), std::invalid_argument );
}

void ItemTest::testType()
{
	Item item( NAME, TYPE );
	CPPUNIT_ASSERT( item.Type() == TYPE );
}

#if 0
	CPPUNIT_ASSERT( condition );
	CPPUNIT_ASSERT_MESSAGE( message, condition );
	CPPUNIT_FAIL( message );
	CPPUNIT_ASSERT_EQUAL( expected, actual );
	CPPUNIT_ASSERT_EQUAL_MESSAGE( message, expected, actual );
	CPPUNIT_ASSERT_DOUBLES_EQUAL( expected, actual, delta );

	CPPUNIT_ASSERT_THROW( expression, exception-type );
	CPPUNIT_ASSERT_THROW_MESSAGE( message, expression, exception-type );
	CPPUNIT_ASSERT_NO_THROW( expression );
	CPPUNIT_ASSERT_NO_THROW_MESSAGE( message, expression );
#endif

