#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{
	class House
	{
	public:
		void setPos(const vec2 &position_in)
		{
			position = position_in;
		}
		void setAngle(const float& angle_in)
		{
			angle = angle_in;
		}
		void setRoofColor(const RGB& roof_color_in)
		{
			roof_color = roof_color_in;
		}
		void setWallColor(const RGB& wall_color_in)
		{
			wall_color = wall_color_in;
		}
		void draw()
		{
			// draw a house
			beginTransformation();
			{
				translate(position);
				rotate(angle);
				// wall
				drawFilledBox(wall_color, 0.2f, 0.2f);

				// roof
				drawFilledTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
				drawWiredTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

				// window
				drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
				drawWiredBox(Colors::gray, 0.1f, 0.1f);
				drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
				drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });
			}
			endTransformation();
		}
	private:
		vec2 position = {0.0f, 0.0f};
		float angle = 0.0f;
		RGB roof_color = Colors::red;
		RGB wall_color = Colors::yellow;

	};

	class Example : public Game2D
	{
	public:
		Example()
		{
			for (int i = 0; i < 50; ++i)
			{
				house[i].setPos({ rand_num.getFloat(-1.0f,1.0f), rand_num.getFloat(-1.0f,1.0f) });
				house[i].setRoofColor(color_list[rand_num.getInt(0,5)]);
				house[i].setWallColor(color_list[rand_num.getInt(0,5)]);
				house[i].setAngle({ rand_num.getFloat(-90.0f,90.0f) });
			}
		}
	public:
		void update() override
		{
			//House house[10];
			for (int i = 0; i < 50; ++i)
			{
				house[i].draw();
			}	
		}
	private:
		House house[10];
		RandomNumberGenerator rand_num;
		RGB color_list[5] = {Colors::red, Colors::blue, Colors::yellow,Colors::gray,Colors::olive};
	};
}

int main(void)
{
	jm::Example().run();

	return 0;
}
