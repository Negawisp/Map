#include <stdlib.h>

int main ()
{
	system ("g++ -c main.cpp && g++ -c Engine.cpp && g++ -c Drawbject.cpp && g++ -c Game_object.cpp && g++ -c map.cpp && g++ -c tile.cpp && g++ -c Main_character.cpp &&"
		"g++ -c NPC.cpp  && g++ -c Explosive_sheep.cpp");
	system ("g++ main.o map.o Drawbject.o Game_object.o tile.o Engine.o Main_character.o -o yoko -lsfml-graphics -lsfml-window -lsfml-system");
	return 0;
}
