#pragma once
#include "Game2D.h"

namespace jm
{
	class GeometricObj
	{
	public:
		void init(const RGB color_in, const vec2 pos_in, const float size_in)
		{
			pos = pos_in;
			color = color_in;
			size = size_in;
		}
		virtual void drawGeometry() {};

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawGeometry();
			}
			endTransformation();
		}

	public:
		vec2 pos;
		RGB color;
		float size;
	};
}