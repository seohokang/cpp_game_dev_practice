#pragma once
#include "Game2D.h"

namespace jm
{
	class GeometricObj
	{
	public:
		void init(const RGB color_in, const vec2 pos_in, const float angle_in)
		{
			pos = pos_in;
			color = color_in;
			angle = angle_in;
		}
		// pure virtual function -> if drawGeometry is not overrided from Box -> spits out error in compile stage
		virtual void drawGeometry() = 0;

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				rotate(angle);
				drawGeometry();
			}
			endTransformation();
		}

	protected:
		float angle;
		vec2 pos;
		RGB color;
	};
}