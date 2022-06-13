#define WIDTH (600)
#define HEIGHT (400)
#include "Vehicle.h"
#include <random>


Vehicle::Vehicle(int x, int y) : maxSpeed(4), r(16), maxForce(0.25f), d1(0), d2(0), dist(100)
{
	m_pos = new Vector2D(x, y);
	m_vel = new Vector2D(4, 0);
	m_acc = new Vector2D(0, 0);
	m_force = new Vector2D(0, 0);

	rdi1 = new Vector2D(0, 0);
	rdi2 = new Vector2D(0, 0);
	rdi3 = new Vector2D(0, 0);

	normalPoint = new Vector2D(0, 0);
	normal = new Vector2D(0, 0);
	m_end = new Vector2D(0, 0);
}

void Vehicle::update()
{
	edge();
	*m_vel += *m_acc;
	m_vel->limit(maxSpeed);
	*m_pos += *m_vel;
	*m_acc *= 0;

	radian = atan2(m_vel->getY(), m_vel->getX());
	*rdi1 = Rradian(-r, -r / 2, radian);
	*rdi2 = Rradian(-r, r / 2, radian);
	*rdi3 = Rradian(r, 0, radian);
}

void Vehicle::edge()
{
	if (m_pos->getX() > WIDTH + r)
	{
		m_pos->setX(-r);
	}
	else if (m_pos->getX() < -r)
	{
		m_pos->setX(WIDTH + r);
	}

	if (m_pos->getY() > HEIGHT + r)
	{
		m_pos->setY(-r);
	}
	else if (m_pos->getY() < -r)
	{
		m_pos->setY(HEIGHT + r);
	}
}

void Vehicle::avoid(Target* obs)
{
	*normal = getnormalPoint(obs, m_pos, m_vel);
	d1 = Vector2D(*normal - *obs).length();

	m_vel->normalize();
	*m_vel *= dist;
	*m_end = *m_pos + *m_vel;

	d2 = Vector2D(*m_end - *obs).length();
	if (d1 - 500 < obs->getR() && d2 < obs->getR())
	{
		*m_force = *m_end - *obs;

		m_force->normalize();
		*m_force *= maxForce;
		*m_force += *m_pos;

		applyForce(m_force);
	}
}

Vector2D Vehicle::getnormalPoint(Target* p, Vector2D* pos, Vector2D* vel)
{
	vel->normalize();
	*normalPoint = *pos + *vel;

	return *normalPoint;
}

void Vehicle::applyForce(Vector2D* force)
{
	*m_acc += *force;
}

Vector2D Vehicle::Rradian(float x, float y, float radian)
{
	Vector2D rota(0, 0);

	rota.setX(cos(radian) * x - sin(radian) * y);
	rota.setY(sin(radian) * x + cos(radian) * y);

	return rota;
}

void Vehicle::draw(SDL_Renderer* renderer)
{
	filledTrigonRGBA(renderer, rdi1->getX() + m_pos->getX(), rdi1->getY() + m_pos->getY(),
		rdi2->getX() + m_pos->getX(), rdi2->getY() + m_pos->getY(),
		rdi3->getX() + m_pos->getX(), rdi3->getY() + m_pos->getY(),
		255, 255, 255, 255);
}
