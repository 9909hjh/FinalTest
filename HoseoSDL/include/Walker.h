#pragma once

#include "main.h"
#include "Game.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "Target.h"
#include "Vehicle.h"
#include <vector>

class Walker 
{
public:
  Walker();
  void draw(SDL_Renderer* renderer);
  void update();

private:
	std::vector<Vehicle*> m_Vehicle;
	std::vector<Target*> m_Target;
};