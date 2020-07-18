#ifndef CPPUNIT_EXAMPLE_ITEM_H
#define CPPUNIT_EXAMPLE_ITEM_H

#include <string>

class Item
{
public:
	enum {
		None,
		Armor,
		Weapon,
		Ring,
		Shield
	};

	Item( const char *name, int type = None );
	Item( const Item & );
	virtual ~Item();

	const std::string& Name() const;
	int Type() const;
	int Uid() const;
	int Value() const;

	void SetValue( int v );

private:

	std::string name;
	int type;
	int uid;
	int value;
};


#endif // CPPUNIT_EXAMPLE_ITEM_H

