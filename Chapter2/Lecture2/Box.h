#pragma once

#include "GeometricObj.h"

namespace jm
{
	class Box : public GeometricObj
	{
	public:
		void init(const RGB color_in, const vec2 pos_in, const float angle_in, const float width_in, const float height_in)
		{
			GeometricObj::init(color_in, pos_in, angle_in);
			width = width_in;
			height = height_in;
		}
		void drawGeometry() override
		{
			drawFilledBox(GeometricObj::color, width, height);
		}

	private:
		float width, height;
	};
}
