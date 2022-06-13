#pragma once

#include "main.h"
#include "Vector2D.h"
#include "Target.h"

class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	void applyForce(Vector2D* force);
	void edge();
	void avoid(Target* obs);
	Vector2D getnormalPoint(Target* p, Vector2D* pos, Vector2D* vel);
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

	Vector2D* normalPoint;
	Vector2D* normal;
	Vector2D* m_end;
	float d1;
	float d2;

	int maxSpeed;
	int r;
	float maxForce;
	float dist;
};