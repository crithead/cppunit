#ifndef CPPUNIT_EXAMPLE_PLAYER_H
#define CPPUNIT_EXAMPLE_PLAYER_H

class Player
{
public:
	static const int BASE_HEALTH = 20;
	static const int HEALTH_PER_LEVEL = 10;
	static const int HEALTH_PER_STRENGTH = 5;

	Player( const char *name );
	Player( const Player & );
	~Player();

	const char *Name() const;
	int Strength() const;
	int Level() const;
	int Health() const;

	void SetStrength( int str );
	void SetLevel( int lvl );

private:
	void UpdateHealth();

	int strength;
	int level;
	int health;
	const char *name;
};


#endif // CPPUNIT_EXAMPLE_PLAYER_H

