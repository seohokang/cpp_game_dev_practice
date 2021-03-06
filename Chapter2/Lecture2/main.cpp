#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Circle.h"
#include "Triangle.h"
#include "Box.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Triangle triangle[5];
		Circle circle[5];
		Box box[5];

		Example()
			: Game2D()
		{
			RandomNumberGenerator random;
			for (int i = 0; i < 5; ++i)
			{
				triangle[i].init(Colors::red, random.getFloatVector(-1.5f, 1.5f), random.getFloat(-5.0f,5.0f), 0.3f);
				circle[i].init(Colors::yellow, random.getFloatVector(-1.5f, 1.5f), random.getFloat(-5.0f, 5.0f), 0.15f);
				box[i].init(Colors::blue, random.getFloatVector(-1.5f, 1.5f), random.getFloat(-5.0f, 5.0f), 0.3f, 0.3f);
			}
		}

		void update() override
		{
			for (int i = 0; i < 5; ++i)
			{
				triangle[i].draw();
				circle[i].draw();
				box[i].draw();
			}
		}
	};
}

int main(void)
{
	jm::Example().run();
	return 0;
}
