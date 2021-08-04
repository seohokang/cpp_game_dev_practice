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
		Triangle triangle;
		Circle circle;
		Box box;

		Example()
			: Game2D()
		{
			triangle.init(Colors::red, vec2{ -0.5f, -0.05f }, 0.3f);
			circle.init(Colors::yellow, vec2{ 0.5f, 0.0f }, 0.15f);
			box.init(Colors::blue, vec2{ 0.0f, 0.0f }, 0.3f, 0.3f);
		}

		void update() override
		{
			triangle.draw();
			circle.draw();
			box.draw();
		}
	};
}

int main(void)
{
	jm::Example().run();
	return 0;
}
