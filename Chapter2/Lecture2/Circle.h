#pragma once
#include "GeometricObj.h"

namespace jm
{
	class Circle : public GeometricObj
	{
	public:
		void drawGeometry() override
		{
			drawFilledCircle(color, size);
		}
	};
}
