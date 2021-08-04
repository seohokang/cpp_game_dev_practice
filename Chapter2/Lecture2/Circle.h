#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Circle : public GeometricObj
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawFilledCircle(color, size);
			}
			endTransformation();
		}
	};
}
