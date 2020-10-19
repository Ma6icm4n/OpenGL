#pragma once
#include "Actor.h"

class Cube : public Actor
{
public:
	Cube();

	void updateActor(float dt) override;
	void actorInput(SDL_MouseButtonEvent& keyState) override;

private:
	bool tourne;
	Vector2 rotation;
	Vector2 velocite;
	int x1, xMouse, y1, yMouse;
};

