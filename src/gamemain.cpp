//
// The ''game'' is a simple print test program that uses the test classes
// and prints out their state.
//
#include <iostream>

#include "item.h"
#include "player.h"

static void Print( Item& item )
{
	std::cout << item.Name() << " [T " << item.Type()
		<< ", V " << item.Value() << "]" << std::endl;
}

static void Print( Player& player )
{
	std::cout << player.Name() << " [S " << player.Strength()
		<< ", L " << player.Level() << ", H " << player.Health()
		<< "]" << std::endl;
}

int main( int, char ** )
{
	Player p( "Hobart" );
	Print( p );

	p.SetLevel( 10 );
	p.SetStrength( 25 );
	Print( p );

	Player q( p );
	Print( q );
	q.SetStrength( 12 );
	q.SetLevel( 6 );
	Print( q );

	Item i( "Hammer of Frog", Item::Weapon );
	i.SetValue( 150 );
	Print ( i );

	return 0;
}

