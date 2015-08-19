#include <stdexcept>

#include "player.h"

Player::Player( const char *n ) : strength( 0 ), level( 0 ),
	health( BASE_HEALTH ), name( n )
{
	UpdateHealth();
}

Player::~Player()
{
}

Player::Player( const Player& that ) :
	strength( that.strength ),
	level( that.level ),
	health( that.health ),
	name( that.name )
{
}

const char *Player::Name() const
{
	return name;
}

int Player::Strength() const
{
	return strength;
}

int Player::Level() const
{
	return level;
}

int Player::Health() const
{
	return health;
}


void Player::SetStrength( int str )
{
	if ( str < 0 )
		throw std::invalid_argument("Strength must be non-negative");
	strength = str;
	UpdateHealth();
}

void Player::SetLevel( int lvl )
{
	if ( lvl < 0 )
		throw std::invalid_argument("Level must be non-negative");
	level = lvl;
	UpdateHealth();
}

void Player::UpdateHealth( void )
{
	health = BASE_HEALTH + ( level * HEALTH_PER_LEVEL ) +
			( strength / HEALTH_PER_STRENGTH );
}

