#include "Cube.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
#include "Log.h"
#include "Assets.h"

Cube::Cube() : rotationVelocity(Vector2(0.0f, 0.0f)), mousePreviousX(0), mousePreviousY(0), mousefinalX(0), mousefinalY(0),
	rotate(false) , angularSpeed(0), moveComponent(nullptr)
{
	moveComponent = new MoveComponent(this);
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Cube"));
}

void Cube::updateActor(float deltaTime) {
	
	if (rotate) {
		
		rotationVelocity = Vector2((mousePreviousX - mousefinalX) / 30, (mousePreviousY - mousefinalY) / 30);
		Log::info("PRESQUIEHDKBO");
		
	}
	else {
		rotationVelocity *= 0.50;
		
	}
	moveComponent->updateObjectRotation(rotationVelocity, deltaTime, angularSpeed);
	
	

}

void Cube::rotateActor(const Uint32 mouseState, SDL_Event& clickEvent) {

	
	if (clickEvent.button.button == SDL_BUTTON_LEFT && clickEvent.type == SDL_MOUSEBUTTONDOWN) {
		rotate = true;
		SDL_GetMouseState(&mousePreviousX, &mousePreviousY);
		
	}
	if (clickEvent.type == SDL_MOUSEMOTION) {
		SDL_GetMouseState(&mousefinalX, &mousefinalY);
	}
	if (clickEvent.type == SDL_MOUSEBUTTONUP) {
		rotate = false;
	}
}

