#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Circle.h"
#include "Triangle.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Triangle triangle;
		Circle circle;

		Example()
			: Game2D()
		{
			triangle.init(Colors::red, vec2{ -0.5f, -0.05f }, 0.3f);
			circle.init(Colors::yellow, vec2{ 0.5f, -0.05f }, 0.1f);
		}

		void update() override
		{
			triangle.draw();
			circle.draw();
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();

	return 0;
}
