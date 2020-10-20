#include "MoveComponent.h"
#include "Maths.h"
#include "Actor.h"
#include "Window.h"

MoveComponent::MoveComponent(Actor* ownerP, int updateOrderP)
	: Component(ownerP, updateOrderP), forwardSpeed(0.0f), angularSpeed(0.0f)
{

}

void MoveComponent::setForwardSpeed(float forwardSpeedP)
{
	forwardSpeed = forwardSpeedP;
}

void MoveComponent::setAngularSpeed(float angularSpeedP)
{
	angularSpeed = angularSpeedP;
}

void MoveComponent::update(float dt)
{
	if (!Maths::nearZero(angularSpeed))
	{
		Quaternion newRotation = owner.getRotation();
		float angle = angularSpeed * dt;
		Quaternion incrementZ(Vector3::unitZ, angle);
		newRotation = Quaternion::concatenate(newRotation, incrementZ);
		owner.setRotation(newRotation);
	}
	if (!Maths::nearZero(forwardSpeed))
	{
		Vector3 newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt;
		owner.setPosition(newPosition);
	}
}

void MoveComponent::updateObjectRotation(Vector2 rotationVelocity, float dt, float angularSpeed) {

		Quaternion newRotation = owner.getRotation();
		newRotation = Quaternion::concatenate(newRotation, Quaternion(Vector3::unitZ, rotationVelocity.x / 50));
		newRotation = Quaternion::concatenate(newRotation, Quaternion(Vector3::unitY, rotationVelocity.y / 50));
		owner.setRotation(newRotation);
}
