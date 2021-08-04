#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Triangle : public GeometricObj
	{
	public:
		void drawGeometry() override
		{
			drawFilledTriangle(color,size);
		}
	};
}
