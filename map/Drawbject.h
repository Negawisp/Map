#ifndef DRAWBJECT_H_INCLUDED
#define DRAWBJECT_H_INCLUDED


#include <SFML/Graphics.hpp>

class Drawbject
{
protected:
	sf::Sprite			sprite_;
	std::vector<sf::IntRect>	sprite_rect_;
	int				time_for_frame_;
	int				cur_time_;
	int				n_frames_;
	int				direction_;
	int				current_animation_state_;

public:
	Drawbject ()
	{}

	Drawbject (int n_sprites):
		sprite_rect_ (n_sprites)
	{}
	
	Drawbject (const Drawbject& origin);
	Drawbject (sf::Sprite sprite);
	Drawbject (const std::string texture_location);
	Drawbject (const std::string texture_location, sf::Sprite sprite);

	~Drawbject()
	{}

	sf::Vector2f get_sprite_position ();
	

	Drawbject& add_to_x (float offset);
	Drawbject& add_to_y (float offset);

	int draw_it (sf::RenderWindow& window);
	int animate ();

virtual int load () = 0;
};

//#include "Drawbject.cpp"

#endif
