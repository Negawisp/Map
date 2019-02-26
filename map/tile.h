#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED


#include <SFML/Graphics.hpp>
#include "Drawbject.h"


class Tile: public Drawbject
{
public:
	class Tile_type
	{
	public:
		static const int	Min    = -1;
		
		static const int 	Wall   = 0;
		static const int	Water  = 1;
		static const int	Grass  = 2;
		static const int	Desert = 3;
		static const int	Sand   = 4;

		static const int	Max    = 5;
	};

private:
	int		type_;

public:
	Tile ():
		Drawbject ()
	{}

	Tile (const Tile& origin);
	Tile (sf::Sprite sprite, int tile_type);
	Tile (sf::Texture& texture, int x, int y, int width, int height,
	      int texture_x, int texture_y, int tile_type);

	~Tile ()
	{}


	sf::Sprite get_sprite ()
	{ return sprite_; }

	bool isWalkable ()
	{ return (type_ != Tile_type::Wall); }

	int load () override
	{}
};


//#include "tile.cpp"

#endif
