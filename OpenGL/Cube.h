#pragma once
#include "Actor.h"
class Cube : public Actor
{
public:
	Cube();

	void updateActor(float deltaTime) override;
	void rotateActor(const Uint32 mouseState, SDL_Event& clickEvent) override;

private:
	Vector2 rotationVelocity;
	int mousePreviousX, mousePreviousY;
	int mousefinalX, mousefinalY;
	bool rotate;
	float angularSpeed;

	class MoveComponent* moveComponent;
};

