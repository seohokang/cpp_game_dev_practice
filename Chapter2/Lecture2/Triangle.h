#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Triangle : public GeometricObj
	{
	public:
		void init(const RGB color_in, const vec2 pos_in, const float angle_in, const float size_in)
		{
			GeometricObj::init(color_in, pos_in, angle_in);
			size = size_in;
		}

		void drawGeometry() override
		{
			drawFilledTriangle(GeometricObj::color,size);
		}
	private:
		float size;
	};
}
