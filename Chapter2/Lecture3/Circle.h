#pragma once

#include "GeometricObject.h"

namespace jm
{
	class Circle : public GeometricObject
	{
	public:
		Circle(const RGB& _color, const vec2& _pos, const float& _size)
		{
			init(_color, _pos, _size);
		}
		~Circle() 
		{
			std::cout << "circle destructor" << std::endl;
		}
		float size;
		void init(const RGB & _color, const vec2 & _pos, const float & _size)
		{
			GeometricObject::init(_color, _pos);
			size = _size;
		}

		void drawGeometry() const override
		{
			drawFilledCircle(color, size);
		}
	};
}