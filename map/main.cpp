#include "Drawbject.h"
#include "map.h"
#include "tile.h"
#include "Game_object.h"
#include "Engine.h"

int main()
{	
	sf::Texture tiles_texture;
	tiles_texture.loadFromFile ("grass_tile.png");

	Engine engine (&tiles_texture);
	engine.go ();

	return 0;
}
