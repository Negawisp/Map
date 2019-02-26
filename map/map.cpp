#ifndef MAP_CPP_INCLUDED
#define MAP_CPP_INCLUDED

#include "map.h"



#define SHORT_LOG
#define LOG(message)

#ifdef  SHORT_LOG
#define LOG(message)	fprintf (stdout, "[%p]" message "\n", this);
#endif

	Map::Map (sf::Texture& tiles_texture):
		movement_border_  (450, 600, 800, 1050),
		window_size_      (1080, 720),
		start_position_	  (10, 3)
	{
		LOG ("map entered DEFAULT constructor...");


	Tile tile1 (tiles_texture, 0, 0, 100, 100,  0,   0, Tile::Tile_type::Grass);
	Tile tile2 (tiles_texture, 0, 0, 100, 100, 48, 250, Tile::Tile_type::Wall);

	
	std::vector<Tile> tiles_set (2);
	tiles_set [0] = tile1;
	tiles_set [1] = tile2;

	std::vector<std::vector<int>> scheme = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
		{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, 
		{1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
		{1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1},
		{1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}, 
		{1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1}, 
		{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, 
		{1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
		{1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}, 
		{1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1}, 
		{1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1}, 
		{1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
		{1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}, 
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

		map_size_ = sf::Vector2u (scheme[0].size(), scheme.size());

		Tile initial_tile;

		std::vector<Tile> initial_row 
			(map_size_.x, initial_tile);
		
		tile_ = std::vector<std::vector<Tile>>
			(map_size_.y, initial_row);

		int width  = tiles_set[0].get_sprite().getTextureRect().width;
		int height = tiles_set[0].get_sprite().getTextureRect().height;

		tile_size_.x = width;
		tile_size_.y = height;

		

		for (int i = 0; i < map_size_.y; i++)
		{
			for (int j = 0; j < map_size_.x; j++)
			{
				tile_[i][j] = tiles_set[scheme[i][j]];
				tile_[i][j].add_to_y ((i-2) * height);
				tile_[i][j].add_to_x ((j-2) * width);
			}
		}

		LOG ("map constructed.");
	}

	Map::Map (std::vector<Tile>& tile_set, std::vector<std::vector<int>>& scheme, sf::Vector2u map_size, sf::Vector2u window_size):
		map_size_         (scheme[0].size(), scheme.size()),
		movement_border_  (450, 600, 800, 1050),
		window_size_      (window_size),
		start_position_	  (10, 3)
	{
		LOG ("map entered MATRIX constructor...");

		Tile initial_tile;

		std::vector<Tile> initial_row 
			(map_size_.x, initial_tile);
		
		tile_ = std::vector<std::vector<Tile>>
			(map_size_.y, initial_row);

		int width  = tile_set[0].get_sprite().getTextureRect().width;
		int height = tile_set[0].get_sprite().getTextureRect().height;

		tile_size_.x = width;
		tile_size_.y = height;

		

		for (int i = 0; i < map_size_.y; i++)
		{
			for (int j = 0; j < map_size_.x; j++)
			{
				tile_[i][j] = tile_set[scheme[i][j]];
				tile_[i][j].add_to_y ((i-2) * height);
				tile_[i][j].add_to_x ((j-2) * width);
			}
		}

		LOG ("map constructed.");
	}

Map::~Map ()
	{}



int Map::add_drawbject (Drawbject* drawbject)
	{
		drawbjects_.push_back (drawbject);
		return 0;
	}


int Map::reset_at_tile (unsigned x, unsigned y)
	{
		LOG ("RESETTING...");
		long int dx = (long int)window_size_.x/2 - tile_[x][y].get_sprite_position().x - tile_size_.x/2;
		long int dy = (long int)window_size_.y/2 - tile_[x][y].get_sprite_position().y - tile_size_.y/2;

		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (unsigned i = 0; i < map_size_y_; i++)
			for (unsigned j = 0; j < map_size_x_; j++)
			{
				tile_[i][j].add_to_x (dx);
				tile_[i][j].add_to_y (dy);
			}

		unsigned n_of_drawbjects = drawbjects_.size();
		for (unsigned i = 0; i < n_of_drawbjects; i++)
		{
			drawbjects_[i] -> add_to_x (dx);
			drawbjects_[i] -> add_to_y (dy);
		}
		return 0;
	}


int Map::draw_map (sf::RenderWindow& work_window)
	{
		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (unsigned i = 0; i < map_size_y_; i++)
			for (unsigned j = 0; j < map_size_x_; j++)
			{
				work_window.draw (tile_[i][j].get_sprite ());
			}

		return 0;
	}


int Map::load ()
	{
		reset_at_tile (start_position_.x, start_position_.y);

		unsigned n_drawbjects = drawbjects_.size();
		for (unsigned i = 0; i < n_drawbjects; i++)
		{
			drawbjects_[i] -> load ();
		}
	}


sf::Vector2f Map::get_top_left_corner ()
	{
		return tile_[0][0].get_sprite_position ();
	}


	int Map::move_up (float speed)
	{
		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (int i = 0; i < map_size_y_; i++)
			for (int j = 0; j < map_size_x_; j++)
			{
				tile_[i][j].add_to_y (-speed);
			}

		unsigned n_of_drawbjects = drawbjects_.size();
		for (int i = 0; i < n_of_drawbjects; i++)
		{
			drawbjects_[i] -> add_to_y (-speed);
		}
	}

	int Map::move_down (float speed)
	{
		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (int i = 0; i < map_size_y_; i++)
			for (int j = 0; j < map_size_x_; j++)
			{
				tile_[i][j].add_to_y (speed);
			}

		unsigned n_of_drawbjects = drawbjects_.size();
		for (int i = 0; i < n_of_drawbjects; i++)
		{
			drawbjects_[i] -> add_to_y (speed);
		}
	}

	int Map::move_left (float speed)
	{
		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (int i = 0; i < map_size_y_; i++)
			for (int j = 0; j < map_size_x_; j++)
			{
				tile_[i][j].add_to_x (-speed);
			}

		unsigned n_of_drawbjects = drawbjects_.size();
		for (int i = 0; i < n_of_drawbjects; i++)
		{
			drawbjects_[i] -> add_to_x (-speed);
		}
	}

	int Map::move_right (float speed)
	{
		unsigned map_size_x_ = map_size_.x;
		unsigned map_size_y_ = map_size_.y;
		for (int i = 0; i < map_size_y_; i++)
			for (int j = 0; j < map_size_x_; j++)
			{
				tile_[i][j].add_to_x (speed);
			}

		unsigned n_of_drawbjects = drawbjects_.size();
		for (int i = 0; i < n_of_drawbjects; i++)
		{
			drawbjects_[i] -> add_to_x (speed);
		}
	}


	sf::Vector2u Map::get_tile_size_vector ()
	{
		return tile_size_;
	}



#undef SHORT_LOG
#undef LOG
#undef DUMP


#endif
