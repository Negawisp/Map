#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Drawbject.h"
#include "tile.h"
#include "Geometry.h"
#include "Game_object.h"

class Game_object;

class Map
{
public:
	std::vector<std::vector<Tile>> tile_;
	
private:
	sf::Texture texture_;
	std::vector<Drawbject*>        drawbjects_;

	
	sf::Vector2u	tile_size_;
	sf::Vector2u	map_size_;
	sf::Vector2u	window_size_;
	sf::Vector2u	start_position_;
public:
	Fence<unsigned> movement_border_;


	Map ();
	Map (sf::Texture& tile_texture);
	Map (std::vector<Tile>& tile_set, std::vector<std::vector<int>>& scheme, sf::Vector2u map_size, sf::Vector2u window_size);
	
	
	~Map ();


	int add_drawbject (Drawbject* drawbject);	//  Drawbject given will be moved with the map (as it is placed on map's surface)
	int reset_at_tile (unsigned x, unsigned y);	//  Makes tile with coordinates given to be in the center of the screen
	int load ();


	int draw_map (sf::RenderWindow& work_window);

	int move_up    (float speed);
	int move_down  (float speed);
	int move_left  (float speed);
	int move_right (float speed);


	sf::Vector2f get_top_left_corner ();
	sf::Vector2u get_tile_size_vector ();
};


#endif
