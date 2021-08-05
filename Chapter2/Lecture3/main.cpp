#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#include <vector>

namespace jm
{
	class Example : public Game2D
	{
	public:
		std::vector<GeometricObject*> my_objs;

		Example()
			: Game2D()
		{
			// Dynamic allocation, since my_tri will be deleted out of bracket
			auto* my_tri = new Triangle; // using new, created Triangle instance
			auto* my_cir = new Circle;
			auto* my_box = new Box;

			my_tri->init(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			my_cir->init(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f);
			my_box->init(Colors::blue, vec2{ 0.0f, 0.5f }, 0.15f, 0.25f);
			my_objs.push_back(my_tri);
			my_objs.push_back(my_cir);
			my_objs.push_back(my_box);
		}

		void update() override
		{

			for (auto& my_obj : my_objs)
			{
				my_obj->draw();
			}
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
