#ifndef MAIN_CHARACTER_H_INCLUDED
#define MAiN_CHARACTER_H_INCLUDED

#include "Game_object.h"

class Main_character: public Game_object
{
private:


public:
	Main_character (const sf::Texture& texture,
	                std::vector<sf::IntRect>& sprite_rect, int n_frames, int time_for_frame,
		        sf::IntRect hitbox,
	                Map& map, unsigned x, unsigned y, float speed);

	int 	load  () override;
	int	auto_move () override {}

	int go_up ();
	int go_down ();
	int go_left ();
	int go_right ();
};

#endif
