#ifndef EXPLOSIVE_SHEEP_CPP_INCLUDED
#define EXPLOSIVE_SHEEP_CPP_INCLUDED

#include "Explosive_sheep.h"

	Explosive_sheep::Explosive_sheep (const sf::Texture& texture, Map& map, unsigned initial_x, unsigned initial_y, Game_object* target):
		NPC (texture, map, 8),
		target_ (target)
	{
		hitbox_.top = 0;	hitbox_.width = 100; 
		hitbox_.left = 0; 	hitbox_.height = 100;
		initial_position_.x = initial_x;	initial_position_.y = initial_y;
		globl_position_.x   = initial_x;	globl_position_.y = initial_y;
		speed_		= 4;
		n_frames_	= 2;
		time_for_frame_	= 15;
		cur_time_	= 0;


		sprite_rect_ [0] = sf::IntRect (200, 400, 50, 100);
		sprite_rect_ [1] = sf::IntRect (0, 400, 50, 100);
		sprite_rect_ [2] = sf::IntRect (200, 400, 50, 100);
		sprite_rect_ [3] = sf::IntRect (0, 400, 50, 100);
		sprite_rect_ [4] = sf::IntRect (200, 400, 50, 100);
		sprite_rect_ [5] = sf::IntRect (0, 400, 50, 100);
		sprite_rect_ [6] = sf::IntRect (200, 400, 50, 100);
		sprite_rect_ [7] = sf::IntRect (0, 400, 50, 100);

	//	hitbox_ = 
	}

#endif
