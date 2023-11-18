#include "AActor.h"
#include "USceneComponent.h"
AActor::AActor(COORD Position, int NumberOfComponents) : Position(Position),NumberOfComponents(NumberOfComponents), RootComponent(new USceneComponent("UStaticMeshComponent","RootComponent", { 0 }, this)), Components(new USceneComponent[NumberOfComponents])
{

}

void AActor::SetPosition(COORD Position)
{
	this->Position = Position;
}

COORD AActor::GetPosition()
{
	return Position;
}

void AActor::SetNumberOfComponents(int NumberOfComponents)
{
	this->NumberOfComponents = NumberOfComponents;
	Components = new USceneComponent[NumberOfComponents];
}

int AActor::GetNumberOfComponents()
{
	return NumberOfComponents;
}

USceneComponent* AActor::GetRootComponent()
{
	return RootComponent;
}

void AActor::SetRootComponent(USceneComponent* RootComponent)
{
	this->RootComponent = RootComponent;
}

USceneComponent* AActor::GetComponents()
{
	return Components;
}

AActor::~AActor()
{
	delete[] Components;
	delete[] RootComponent;
}
