#include "Walker.h"
#include <random>


Walker::Walker() 
{
	m_Vehicle.push_back(new Vehicle(100, 100));
	m_Target.push_back(new Target(300, 100));

	steering = new Vector2D(0, 0);
	T_steering = new Vector2D(0, 0);
}

void Walker::update() 
{
	m_mouse = InputHandler::Instance()->getMousePosition();

	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->update();
		m_Target[i]->update();

		*T_steering = m_Target[i]->Hide(m_mouse);
		*steering = m_Vehicle[i]->arrive(T_steering);
		m_Vehicle[i]->applyForce(steering);
	}
}

void Walker::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, m_mouse->getX(), m_mouse->getY(), 10, 0xFFFFFF00);
	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->draw(renderer);
		m_Target[i]->draw(renderer);
	}
}
