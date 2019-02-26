#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED


#include <SFML/Graphics.hpp>
#include "map.h"
#include "Game_object.h"
#include "Main_character.h"

class Engine
{
public:
	const unsigned 	Window_Height 		= 1920;
	const unsigned 	Window_Width  		= 1080;
	char*		Game_Window_Name	= "World of Warsheeps";

private:
	sf::Texture* 		texture_;
	sf::RenderWindow 	game_window_;

	Map 			map_;
	Main_character*		hero_;
public:
	Engine ();
	Engine (sf::Texture* texture);
	
	~Engine ()
	{
		//free (texture_);
		delete (hero_);
	}

	
	int get_game_ready ();
	int go ();
};


#endif
