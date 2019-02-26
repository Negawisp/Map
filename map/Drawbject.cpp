#ifndef DRAWBJECT_CPP_INCLUDED
#define DRAWBJECT_CPP_INCLUDED

#include "Drawbject.h"

#define SHORT_LOG
#define LOG(message)

#ifdef  SHORT_LOG
#define LOG(message)	fprintf (stdout, "[%p]" message "\n", this);
#endif


Drawbject::Drawbject (const Drawbject& origin)
	{
		sprite_		= origin.sprite_;
		sprite_rect_	= origin.sprite_rect_;
	}


Drawbject::Drawbject (sf::Sprite sprite)
	{
		sprite_ = sprite;
	}

sf::Vector2f Drawbject::get_sprite_position ()
	{
		return sprite_.getPosition ();
	}



Drawbject& Drawbject::add_to_x (float offset)
	{
		float x = sprite_.getPosition().x;
		float y = sprite_.getPosition().y;
		sprite_.setPosition (x + offset, y);
		
		return *this;
	}

Drawbject& Drawbject::add_to_y (float offset)
	{
		float x = sprite_.getPosition().x;
		float y = sprite_.getPosition().y;
		sprite_.setPosition (x, y + offset);
		
		return *this;
	}


int Drawbject::draw_it (sf::RenderWindow& window)
	{
		window.draw (sprite_);
	}

int Drawbject::animate ()
	{
		cur_time_ = ++cur_time_ % time_for_frame_;
		if (cur_time_ != 0)
			return 0;

		LOG ("Entered animation...");
		current_animation_state_ = (current_animation_state_ + 1) % n_frames_;
		LOG ("Animated successfully.");
		return 0;
	}


#undef SHORT_LOG
#undef LOG
#undef DUMP


#endif
