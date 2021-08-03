#pragma once
#include <vector>
#include "Game2D.h"

namespace jm
{
	/*
	TODO:
	- add left arm and left leg
	- add bottom
	- jump with space key
	- make a Person class and use it to draw many people.
	- make an Ironman and allow for him to shoot repulsor beam with his right hand
	*/

	class MyBeam
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;
		}
	};

	class MyPerson
	{
	public:
		//float time = 0.0f;
		//int curr_count = -1;
		//int jump_up_count = 200;
		//int jump_down_count = 0;
	public:
		vec2 center = vec2(0.0f, 0.0f);
		void draw(float time, float start_x, float curr_height)
		{
			beginTransformation();
			{
				translate(start_x, 0.0f);
				beginTransformation();
				scale(20.0f, 1.0f);
				translate(0.0f, -0.75f);
				drawFilledBox(Colors::black, 0.1f, 0.1f);
				endTransformation();

				// gold face
				beginTransformation();
				translate(0.0f, curr_height);
				translate(0.0f, 0.12f);
				drawFilledCircle(Colors::gold, 0.08f);
				translate(0.05f, 0.03f);
				drawFilledCircle(Colors::white, 0.01f); // while eye

				endTransformation();

				// yellow right arm
				beginTransformation();
				translate(0.0f, curr_height);
				rotate(-sin(time * 0.5f) * 30.0f);					// animation!
				scale(1.0f, 2.0f);
				translate(0.0f, -0.1f);
				drawFilledBox(Colors::yellow, 0.05f, 0.18f);
				endTransformation();

				// green rigth leg
				beginTransformation();
				translate(0.0f, curr_height);

				translate(0.0f, -0.6f);
				translate(0.0f, 0.2f);
				rotate(sinf(-time * 0.5f + 3.141592f) * 30.0f);	// animation!
				translate(0.0f, -0.2f);
				drawFilledBox(Colors::green, 0.1f, 0.4f);
				endTransformation();


				// red body
				beginTransformation();
				translate(0.0f, curr_height);

				scale(1.0f, 2.0f);
				translate(0.0f, -0.1f);
				drawFilledBox(Colors::red, 0.13f, 0.2f);
				endTransformation();

				// yellow left arm
				beginTransformation();

				translate(0.0f, curr_height);

				rotate(sin(time * 0.5f) * 30.0f);					// animation!
				scale(1.0f, 2.0f);
				translate(0.0f, -0.1f);
				drawFilledBox(Colors::yellow, 0.05f, 0.18f);
				endTransformation();

				// green left leg
				beginTransformation();

				translate(0.0f, curr_height);

				translate(0.0f, -0.6f);
				translate(0.0f, 0.2f);
				rotate(sinf(time * 0.5f + 3.141592f) * 30.0f);	// animation!
				translate(0.0f, -0.2f);
				drawFilledBox(Colors::green, 0.1f, 0.4f);
				endTransformation();
			}			
			endTransformation();
		}
	};

	class WalkingPerson : public Game2D
	{
	public:
		float time = 0.0f;
		MyPerson person;
		std::vector <MyBeam*> bullets;
		MyBeam* bullet = nullptr;

		float curr_height = 0.0f;
		int curr_count = -1;
		int jump_up_count = 200;
		int jump_down_count = 0;
	public:
		void update() override
		{
			if (isKeyPressedAndReleased(GLFW_KEY_SPACE))
			{
				bullet = new MyBeam;
				bullets.push_back(bullet);
				bullet->center.x = 0.2f;
				bullet->center.y = 0.1f;
				bullet->velocity = vec2(0.05f, 0.0f);

				// curr_count starts once space pressed
				if (curr_count==-1) curr_count = 0;
				// in one press
				jump_up_count += curr_count;
				jump_down_count = jump_up_count*2;
			}
			if (curr_count <= jump_up_count && curr_count >= 0)
			{
				curr_height += 0.001f;
				curr_count += 1;
			}
			if (curr_count > jump_up_count)
			{
				curr_height -= 0.001f;
				curr_count += 1;
				if (curr_count >= jump_down_count || curr_height < 0.0)
				{
					curr_height = 0.0f;
					curr_count = -1;
					jump_down_count = 0;
					jump_up_count = 200;
				}
			}
			//std::cout << "ch" << curr_height << "cc" << curr_count << "juc" << jump_up_count << "jdc" << jump_down_count << std::endl;

			person.draw(time, 0.0, curr_height);
			person.draw(time, 0.3f, curr_height);
			for (auto& bullet : bullets)
			{
				bullet->update(getTimeStep());
				if (bullet->center.x > 1.4)
				{
					delete bullet;
					bullets.erase(bullets.begin());
				}
				bullet->draw();
				std::cout << "Bullet Memory Size:" << bullets.size() << std::endl;
			}
			time += this->getTimeStep();
		}
	};
}