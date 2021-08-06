#pragma once

#include "GeometricObject.h"

namespace jm
{
	class Box : public GeometricObject
	{
	public:
		Box(const RGB& _color, const vec2& _pos, const float& _width,
			const float& _height)
		{
			init(_color, _pos, _width, _height);
		}
		~Box()
		{
			std::cout << "box destructor" << std::endl;
		}
		float width, height;

		void init(const RGB & _color, const vec2 & _pos, const float & _width, 
			const float &_height)
		{
			GeometricObject::init(_color, _pos);
			width = _width;
			height = _height;
		}

		void drawGeometry() const override
		{
			drawFilledBox(color, this->width, this->height);
		}
	};
}