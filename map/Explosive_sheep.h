#ifndef EXPLOSIVE_SHEEP_H_INCLUDED
#define EXPLOSIVE_SHEEP_H_INCLUDED

#include "NPC.h"

class Explosive_sheep : public NPC
{
private:
	Game_object*	target_;
	

public:
	Explosive_sheep (const sf::Texture& texture, Map& map, unsigned initial_x, unsigned initial_y, Game_object* target_);

	int auto_move () override;
};

#endif
