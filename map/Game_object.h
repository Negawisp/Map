#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED



#include <SFML/Graphics.hpp>
#include "Drawbject.h"
#include "map.h"

class Map;

class Game_object: public Drawbject
{
protected:		
	sf::Vector2u		initial_position_;
	sf::Vector2u		globl_position_;	//in an array of tiles

	sf::FloatRect		hitbox_;

	Map&			map_;

	float 			speed_;
public:

	Game_object (const sf::Texture& texture, Map& map, int n_sprites);

	Game_object (const sf::Texture& texture,
	             std::vector<sf::IntRect>& sprite_rect, int n_frames, int time_for_frame,
		     sf::IntRect hitbox,
	             Map& map, unsigned x, unsigned y, float speed);
	
	~Game_object () {}


virtual int auto_move () = 0;

	int touches_wall (char direction);
	int place_to_tile (unsigned x, unsigned y);

	int change_Sprite (int sprite_number);
};


//#include "character.cpp"

#endif
