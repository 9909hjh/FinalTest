#include "Walker.h"
#include <random>


Walker::Walker() 
{
	m_Vehicle.push_back(new Vehicle(100, 150));
	m_Target.push_back(new Target(300, 150, 50));
}

void Walker::update() 
{
	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->update();
		m_Vehicle[i]->avoid(m_Target[0]);
	}
}

void Walker::draw(SDL_Renderer* renderer)
{
	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->draw(renderer);
		m_Target[i]->draw(renderer);
	}
}
