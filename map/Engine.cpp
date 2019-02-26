#ifndef ENGINE_CPP_INCLUDED
#define ENGINE_CPP_INCLUDED


#include "Engine.h"

	Engine::Engine (sf::Texture* Texture):
		game_window_ (sf::VideoMode (Window_Height, Window_Width), Game_Window_Name),
		map_ (*Texture)
	{
		texture_ = Texture;

		std::vector<sf::IntRect> sprite_rect (8);
		sprite_rect [0] = sf::IntRect (  0,   0, 100, 165);
		sprite_rect [1] = sf::IntRect (100,   0, 100, 165);
		sprite_rect [2] = sf::IntRect (200, 300, 50, 100);
		sprite_rect [3] = sf::IntRect (0, 300, 50, 100);
		sprite_rect [4] = sf::IntRect (200, 300, 50, 100);
		sprite_rect [5] = sf::IntRect (0, 300, 50, 100);
		sprite_rect [6] = sf::IntRect (200, 300, 50, 100);
		sprite_rect [7] = sf::IntRect (0, 300, 50, 100);



		sf::IntRect hitbox = sf::IntRect (0, 0, 50, 40);

		hero_ = new Main_character (*texture_, sprite_rect, 2, 20, hitbox,
	                  		 map_, 3, 10, 3);

		map_.add_drawbject (hero_);
	}


int Engine::go ()
	{	
		sf::Event event;
		
		while (game_window_.isOpen())
		{
			while (game_window_.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				game_window_.close ();
			}
			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
				game_window_.close ();
	

			if (sf::Keyboard::isKeyPressed (sf::Keyboard::H))
				map_.load ();

	
			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))
			{
				hero_->go_up ();
			}
			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))
			{
				hero_->go_down ();
			}
			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))
			{
				hero_->go_left ();
			}
			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right))
			{
				hero_->go_right ();
			}
	
		
			game_window_.clear();	
			map_.draw_map (game_window_);
			hero_->draw_it (game_window_);
			game_window_.display();
		}
		
		return 0;
	}

#endif
