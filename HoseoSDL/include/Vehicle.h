#pragma once

#include "main.h"
#include "Vector2D.h"

class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	void applyForce(Vector2D* force);
	Vector2D arrive(Vector2D* target);
	Vector2D seek(Vector2D* target);
	Vector2D Rradian(float x, float y, float radian);

protected:
	Vector2D* m_pos;
	Vector2D* m_vel;
	Vector2D* m_acc;
	Vector2D* m_force;

	float radian = 0;
	Vector2D* rdi1;
	Vector2D* rdi2;
	Vector2D* rdi3;

	int maxSpeed;
	int r;
	float maxForce;

	float distance;
	const float dec;
	float speed;
};