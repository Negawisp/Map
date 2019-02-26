#ifndef TILE_CPP_INCLUDED
#define TILE_CPP_INCLUDED



#include "tile.h"

//#define DO_OOPS
//#define SHORT_LOG
#define LOG(message)

#ifdef  SHORT_LOG
#define LOG(message)	fprintf (stdout, "[%p]" message "\n", this);
#undef  SHORT_LOG
#endif

#define OOPS(message)

#define OOPS(message) fprintf (stdout, "In file %s, function %s, line %d:\n" \
                               message, __FILE__, __PRETTY_FUNCTION__, __LINE__);


	Tile::Tile (sf::Sprite sprite, int tile_type):
		Drawbject (sprite),
		type_ (tile_type)
	{
		LOG("tile entered constructor with sprite & tile_type...");
		if (type_ <= Tile_type::Min)
		{
			OOPS
	("Tile.type_ can't be less then Tile_type.Min. Setting to Tile_type.Wall ...");
			type_ = Tile_type::Wall;
		}

		if (type_ >= Tile_type::Max)
		{
			OOPS
	("Tile.type_ can't be more then Tile_type.Max. Setting to Tile_type.Wall ...");
			type_ = Tile_type::Wall;
		}
		LOG ("tile constructed.");
	}


	Tile::Tile (const Tile& origin):
		Drawbject (origin)
	{
		LOG ("tile entered copying constructor...");
		type_   = origin.type_;
		LOG ("tile constructed.");
	}


	Tile::Tile (sf::Texture& texture, int x, int y, int width, int height,
	      int texture_x, int texture_y, int tile_type):
		type_ (tile_type)
	{
		LOG ("tile entered complex constructor...");
		if (type_ <= Tile_type::Min)
		{
			OOPS
	("Tile.type_ can't be less then Tile_type.Min. Setting to Tile_type.Wall ...");
			type_ = Tile_type::Wall;
		}

		if (type_ >= Tile_type::Max)
		{
			OOPS
	("Tile.type_ can't be more then Tile_type.Max. Setting to Tile_type.Wall ...");
			type_ = Tile_type::Wall;
		}


		sprite_.setTexture (texture);
		sprite_.setTextureRect	
			(sf::IntRect (texture_x, texture_y, width, height));
		sprite_.setPosition (x, y);
		LOG ("tile constructed.");
	}


	

#undef LOG
#undef OOPS

#endif
