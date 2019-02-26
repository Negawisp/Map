#ifndef NPC_CPP_INCLUDED
#define NPC_CPP_INCLUDED

#include "NPC.h"

	NPC::NPC (const sf::Texture& texture, Map& map, int n_sprites):
		Game_object (texture, map, n_sprites)
	{

	}

	NPC::NPC (const sf::Texture& texture,
	             std::vector<sf::IntRect>& sprite_rect, int n_frames, int time_for_frame,
		     sf::IntRect hitbox,
	             Map& map, unsigned x, unsigned y, float speed):
		Game_object (texture, sprite_rect, n_frames, time_for_frame,
		     hitbox, map, x, y, speed)
	{
	
	}

	int NPC::load ()
	{
		place_to_tile (initial_position_.x, initial_position_.y);
		return 0;
	}


	int NPC::go_up ()
	{
		int wall_touch = Game_object::touches_wall (Directions::Up);
		if (wall_touch == Measure::Highly)
			return 0;

		float curr_speed = 0;
		if (wall_touch == Measure::Almost)
			curr_speed = hitbox_.top;
		else
			curr_speed = speed_;
		

		int curr_local_y = (hitbox_.top -= curr_speed);
		if (-curr_local_y > hitbox_.height/2)
		{
			globl_position_.y -= 1;
			hitbox_.top  = map_.get_tile_size_vector().y + curr_local_y;
		}

		add_to_y (-curr_speed);

		animate ();
		change_Sprite (n_frames_*0 + current_animation_state_);
	}

	int NPC::go_down ()
	{
		int wall_touch = Game_object::touches_wall (Directions::Down);
		if (wall_touch == Measure::Highly)
			return 0;


		float tile_height = map_.get_tile_size_vector().y;
		float curr_speed = 0;
		if (wall_touch == Measure::Almost)
			curr_speed = tile_height - hitbox_.top - hitbox_.height;
		else
			curr_speed = speed_;


		int curr_local_y = (hitbox_.top += curr_speed);
		if (curr_local_y + hitbox_.height/2 > tile_height)
		{
			globl_position_.y += 1;
			hitbox_.top  = curr_local_y - tile_height;
		}
		
		add_to_y (curr_speed);

		animate ();
		change_Sprite (n_frames_*1 + current_animation_state_);
	}

	int NPC::go_left ()
	{
		int wall_touch = Game_object::touches_wall (Directions::Left);
		if (wall_touch == Measure::Highly)
			return 0;


		float tile_width = map_.get_tile_size_vector().x;
		float curr_speed = 0;
		if (wall_touch == Measure::Almost)
			curr_speed = hitbox_.left;
		else
			curr_speed = speed_;


		float curr_local_x = (hitbox_.left -= curr_speed);
		if (-curr_local_x > hitbox_.width/2)
		{
			globl_position_.x -= 1;
			hitbox_.left  = tile_width + curr_local_x;
		}
		
		add_to_x (-curr_speed);

		animate ();
		change_Sprite (n_frames_*2 + current_animation_state_);
	}

	int NPC::go_right ()
	{
		int wall_touch = Game_object::touches_wall (Directions::Right);
		if (wall_touch == Measure::Highly)
			return 0;

		float tile_width = map_.get_tile_size_vector().x;
		float curr_speed = 0;
		if (wall_touch == Measure::Almost)
			curr_speed = tile_width - hitbox_.left - hitbox_.width;
		else
			curr_speed = speed_;

		float curr_local_x = (hitbox_.left += curr_speed);
		if (curr_local_x + hitbox_.width/2 > tile_width)
		{
			globl_position_.x += 1;
			hitbox_.left  = curr_local_x - tile_width;
		}

		add_to_x (curr_speed);

		animate ();
		change_Sprite (n_frames_*3 + current_animation_state_);
	}



#endif


