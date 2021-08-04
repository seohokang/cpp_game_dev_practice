#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Circle : public GeometricObj
	{
	public:
		void init(const RGB color_in, const vec2 pos_in, const float size_in)
		{
			GeometricObj::init(color_in, pos_in);
			size = size_in;
		}
		void drawGeometry() override
		{
			drawFilledCircle(GeometricObj::color, size);
		}

	private:
		float size;
	};
}
