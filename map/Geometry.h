#ifndef GEOMETRY_H
#define GEOMETRY_H

template <typename type>
class Fence
{
public:
	type up_;
	type down_;
	type left_;
	type right_;

	Fence ():
		up_ (200),
		down_ (700),
		left_ (400),
		right_ (1800)
	{}

	Fence (type up, type down, type left, type right):
		up_ (up),
		down_ (down),
		left_ (left),
		right_ (right)
	{}
};


class Directions
{
public:
	static const char Up    = 'U';
	static const char Down  = 'D';
	static const char Left  = 'L';
	static const char Right = 'R';
};

class Measure
{
public:
	static const int  Almost = 1;
	static const int  Highly = 2;
};

#endif
