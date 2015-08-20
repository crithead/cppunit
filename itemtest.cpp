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

#define NAME "The Two Ring"
#define TYPE Item::Ring

void ItemTest::setUp()
{
	item = new Item( NAME, TYPE );
}

void ItemTest::tearDown()
{
	delete item;
}

void ItemTest::testConstructor()
{
	CPPUNIT_ASSERT( item != 0 );
	CPPUNIT_ASSERT( strcmp( item->Name().c_str(), NAME ) == 0 );
	CPPUNIT_ASSERT( item->Type() == TYPE );
	CPPUNIT_ASSERT( item->Uid() == 0 );
	CPPUNIT_ASSERT( item->Value() == 0 );
}

void ItemTest::testValue()
{
	CPPUNIT_ASSERT( item != 0 );
	CPPUNIT_ASSERT( item->Value() == 0 );
	item->SetValue( 10 );
	CPPUNIT_ASSERT( item->Value() == 10 );
	item->SetValue( 99 );
	CPPUNIT_ASSERT( item->Value() == 99 );

	CPPUNIT_ASSERT_THROW( item->SetValue( -10 ), std::invalid_argument );
}

void ItemTest::testType()
{
	CPPUNIT_ASSERT( item != 0 );
	CPPUNIT_ASSERT( item->Type() == TYPE );
}

