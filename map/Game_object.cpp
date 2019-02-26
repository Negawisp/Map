#ifndef CHARACTER_CPP_INCLUDED
#define CHARACTER_CPP_INCLUDED



#include "Game_object.h"
#include "Geometry.h"
#include <assert.h>

#define OOPS(message)	fprintf (stdout, "In file %s, function %s, line %d:\n" \
		               message "\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);

#define SHORT_LOG
//#define FULL_LOG
#define LOG(message)

#ifdef  SHORT_LOG
#define LOG(message)	fprintf (stdout, message "\n");
#undef  SHORT_LOG
#endif

#ifdef  FULL_LOG
#define LOG(message)	fprintf (stdout, "In file %s, function %s, line %d:\n" \
			       message "\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);
#undef  FULL_LOG
#endif

	Game_object::Game_object (const sf::Texture& texture, Map& map, int n_sprites):
		Drawbject (n_sprites),
		map_ (map)
	{
		sprite_.setTexture (texture);
	}


	Game_object::Game_object (const sf::Texture& texture, 
	                          std::vector<sf::IntRect>& sprite_rect, int n_frames, int time_for_frame,
	                          sf::IntRect hitbox,
	                          Map& map, unsigned x, unsigned y, float speed):
		hitbox_           (hitbox),
		initial_position_ (x, y),
		globl_position_   (x, y),
		map_              (map),
		speed_            (speed)
	{
		n_frames_ = n_frames;
		time_for_frame_ = time_for_frame;
		cur_time_ = 0;

		sprite_.setTexture (texture);
		sprite_rect_ = sprite_rect;
		sprite_.setTextureRect (sprite_rect[1]);
		sprite_.setPosition (1000, 400);
	}


	int Game_object::change_Sprite (int sprite_number)
	{

		LOG ("Entered  change_Sprite...");
		printf ("(w\\ parameter \"%d\")\n", sprite_number);
		sprite_.setTextureRect (sprite_rect_[sprite_number]);
		LOG ("Finished change_Sprite.");
		return 0;
	}


	int Game_object::place_to_tile (unsigned x, unsigned y)
	{
		sf::Vector2f  map_corner  = map_.get_top_left_corner  ();
		sf::Vector2u  tile_size   = map_.get_tile_size_vector ();

		sf::FloatRect sprite_rect = sprite_.getGlobalBounds ();

		hitbox_.left = (tile_size.x - hitbox_.width )/2;
		hitbox_.top  = (tile_size.y - hitbox_.height)/2;
	

		sprite_.setPosition (map_corner.x +  x  * tile_size.x + (tile_size.x - sprite_rect.width)/2,
			             map_corner.y +  y  * tile_size.y + hitbox_.top + hitbox_.height - sprite_rect.height);

		globl_position_ = initial_position_;

		printf ("Local position: {%f, %f}\n", hitbox_.left, hitbox_.top);
		return 0;
	}



	int Game_object::touches_wall (char direction)
	{
		int ret_value = 0;
		switch (direction)
		{
		case (Directions::Left):
			{
				if (hitbox_.left - speed_ <= 0)
					ret_value = Measure::Almost;

				if (hitbox_.left          <= 0)
					ret_value = Measure::Highly;

				if (ret_value)
				{
					if (!map_.tile_[globl_position_.y    ][globl_position_.x - 1].isWalkable ())
						return ret_value;
					if (hitbox_.top + hitbox_.height > map_.get_tile_size_vector ().y      &&
					    !map_.tile_[globl_position_.y + 1][globl_position_.x - 1].isWalkable ())
						return ret_value;
					if (hitbox_.top                  < 0                                   &&
					    !map_.tile_[globl_position_.y - 1][globl_position_.x - 1].isWalkable ())
						return ret_value;
				}

				return 0;
			} break;

		case (Directions::Right):
			{
				unsigned tile_width = map_.get_tile_size_vector ().x;

				if (hitbox_.left + hitbox_.width + speed_ >= tile_width)
					ret_value = Measure::Almost;
				if (hitbox_.left + hitbox_.width          >= tile_width)
					ret_value = Measure::Highly;

				if (ret_value)
				{
					if (!map_.tile_[globl_position_.y    ][globl_position_.x + 1].isWalkable ())
						return ret_value;
					if (hitbox_.top + hitbox_.height > map_.get_tile_size_vector ().y      &&
					    !map_.tile_[globl_position_.y + 1][globl_position_.x + 1].isWalkable ())
						return ret_value;
					if (hitbox_.top                  < 0                                   &&
					    !map_.tile_[globl_position_.y - 1][globl_position_.x + 1].isWalkable ())
						return ret_value;
				}

				return 0;
			}

		case (Directions::Up):
			{
				if (hitbox_.top - speed_ <= 0)
					ret_value = Measure::Almost;
				if (hitbox_.top          <= 0)
					ret_value = Measure::Highly;
				
				if (ret_value)
				{
					if (!map_.tile_[globl_position_.y - 1][globl_position_.x    ].isWalkable ())
						return ret_value;
					if (hitbox_.left + hitbox_.width > map_.get_tile_size_vector ().x       &&
					    !map_.tile_[globl_position_.y - 1][globl_position_.x + 1].isWalkable ())
						return ret_value;
					if (hitbox_.left                 < 0                                    &&
					    !map_.tile_[globl_position_.y - 1][globl_position_.x - 1].isWalkable ())
						return ret_value;
				}
				return 0;
			}

		case (Directions::Down):
			{
				unsigned tile_height = map_.get_tile_size_vector ().y;

				if (hitbox_.top + hitbox_.height + speed_ >= tile_height)
					ret_value = Measure::Almost;
				if (hitbox_.top + hitbox_.height          >= tile_height)
					ret_value = Measure::Highly;
				
				if (ret_value)
				{
					if (!map_.tile_[globl_position_.y + 1][globl_position_.x    ].isWalkable ())
						return ret_value;
					if (hitbox_.left + hitbox_.width  > map_.get_tile_size_vector ().x      &&
					    !map_.tile_[globl_position_.y + 1][globl_position_.x + 1].isWalkable ())
						return ret_value;
					if (hitbox_.left                  < 0                                   &&
					    !map_.tile_[globl_position_.y + 1][globl_position_.x - 1].isWalkable ())
						return ret_value;
				}

				return 0;
			}

		default:
			assert (direction == 'M');
		}
	}

#undef LOG
#undef OOPS


#endif
