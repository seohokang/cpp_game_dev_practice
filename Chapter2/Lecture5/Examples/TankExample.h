#pragma once

#include "Game2D.h"
#include <map>
#include <fstream>
#include <string>

namespace jm
{
	class Actor
	{
	public:
		virtual void moveUp(float dt) = 0;
		virtual void moveDown(float dt) = 0;
		virtual void moveLeft(float dt) = 0;
		virtual void moveRight(float dt) = 0;

	};

	class Command
	{
	public:
		virtual ~Command() {}
		virtual void execute(Actor& actor, float dt) = 0;
	};

	class UpCommand : public Command 
	{
	public:
		void execute(Actor& actor, float dt) override
		{
			actor.moveUp(dt);
		}
	};

	class DownCommand : public Command
	{
	public:
		void execute(Actor& actor, float dt) override
		{
			actor.moveDown(dt);
		}
	};

	class LeftCommand : public Command
	{
	public:
		void execute(Actor& actor, float dt) override
		{
			actor.moveLeft(dt);
		}
	};

	class RightCommand : public Command
	{
	public:
		void execute(Actor& actor, float dt) override
		{
			actor.moveRight(dt);
		}
	};

	class MyTank : public Actor
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);

		void moveUp(float dt) override
		{
			center.y += 0.05f * dt;
		}
		void moveDown(float dt) override
		{
			center.y -= 0.05f * dt;
		}
		void moveLeft(float dt) override
		{
			center.x -= 0.05f * dt;
		}
		void moveRight(float dt) override
		{
			center.x += 0.05f * dt;
		}

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::green, 0.25f, 0.1f); // body
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
		 		translate(0.15f, 0.0f);
				drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
			}
			endTransformation();
		}
	};

	class InputHandler
	{
	public:
		//Command * button_up = nullptr;

		std::map<int, Command *> key_command_map;

		/*InputHandler()
		{
			button_up = new UpCommand;
		}*/

		void handleInput(Game2D & game, Actor & actor, float dt)
		{
			//if (game.isKeyPressed(GLFW_KEY_UP))  button_up->execute(actor, dt);

			for (auto & m : key_command_map)
			{
				std::cout << m.first << std::endl;
				if (game.isKeyPressed(m.first)) m.second->execute(actor, dt);
			}
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;
		InputHandler input_handler;

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{
			std::string key, value;
			std::ifstream myfile("key_binding.txt");
			
			for (int i = 0; i < 4; ++i)
			{
				myfile >> key >> value;
				if (key == "W")	input_handler.key_command_map[GLFW_KEY_W] = new UpCommand;
				else if (key == "S") input_handler.key_command_map[GLFW_KEY_S] = new DownCommand;
				else if (key == "A") input_handler.key_command_map[GLFW_KEY_A] = new LeftCommand;
				else if (key == "D") input_handler.key_command_map[GLFW_KEY_D] = new RightCommand;
			}
		}

		~TankExample()
		{
		}

		void update() override
		{
			// move tank
			/*if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP))		tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();*/

			input_handler.handleInput(*this, tank, getTimeStep());

			// rendering
			tank.draw();
		}
	};
}