#include "Cube.h"
#include "MeshComponent.h"
#include "Assets.h"

Cube::Cube() :
	rotation(Vector2(0.0f, 0.0f)),
	velocite(Vector2(0.0f, 0.0f)),
	tourne(false),
	x1(0),
	xMouse(0),
	y1(0),
	yMouse(0)
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Cube"));
}

void Cube::updateActor(float dt)
{
	Quaternion q;
	if (tourne)
	{
		SDL_GetMouseState(&xMouse, &yMouse);
		rotation = Vector2((x1 - xMouse) / 20, (y1 - yMouse) / 20);
	}
	else
	{
		rotation *= 0.95;
	}
	q = Quaternion::concatenate(q, Quaternion(Vector3::unitZ, rotation.x / 100));
	q = Quaternion::concatenate(q, Quaternion(Vector3::unitY, rotation.y / 100));
	setRotation(Quaternion::concatenate(getRotation(), q));
}

void Cube::actorInput(SDL_MouseButtonEvent& mouseEvent)
{
	if (mouseEvent.button == SDL_BUTTON_LEFT && mouseEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		tourne = true;
		SDL_GetMouseState(&x1, &y1);
	}
	if (mouseEvent.button == SDL_BUTTON_LEFT && mouseEvent.type == SDL_MOUSEBUTTONUP)
	{
		tourne = false;
	}
}
