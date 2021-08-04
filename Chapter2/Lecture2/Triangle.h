#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Triangle : public GeometricObj
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawFilledTriangle(color,size);
			}
			endTransformation();
		}
	};
}
