#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "Game_object.h"

class NPC : public Game_object
{
protected:
	int	health_;

public:
	NPC (const sf::Texture& texture, Map& map, int n_sprites);
	NPC (const sf::Texture& texture,
	             std::vector<sf::IntRect>& sprite_rect, int n_frames, int time_for_frame,
		     sf::IntRect hitbox,
	             Map& map, unsigned x, unsigned y, float speed);

	~NPC ();

	int load () override;

	int go_up ();
	int go_down ();
	int go_left ();
	int go_right ();
};

#endif
