#include <stdexcept>

#include "item.h"

Item::Item( const char *n, int t ) :
		name( n ), type( t ), uid( 0 ), value ( 0 )
{
}

Item::~Item()
{
}

Item::Item( const Item& that ) :
	name( that.name ),
	type( that.type ),
	uid( that.uid ),
	value( that.value )
{
}

const std::string& Item::Name() const
{
	return name;
}

int Item::Type() const
{
	return type;
}

int Item::Uid() const
{
	return uid;
}

int Item::Value() const
{
	return value;
}

void Item::SetValue( int v )
{
	if ( v < 0 )
		throw std::invalid_argument( "Value must be non-negative" );
	this->value = v;
}

