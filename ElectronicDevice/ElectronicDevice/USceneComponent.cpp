#include "USceneComponent.h"
#include "AActor.h"
USceneComponent::USceneComponent(string Type, string Name, FVector RelativePosition, AActor* OwnerActor): UObject(Name)
{
	SetName(Name);
	SetOwnerActor(OwnerActor);
	SetRelativePositionAndCalculateWorldPosition(RelativePosition);
	Type = "USceneComponent";
}

AActor* USceneComponent::GetOwnerActor()
{
	return OwnerActor;
}

FVector USceneComponent::GetWorldPosition()
{
	return WorldPosition;
}


FVector USceneComponent::GetRelativePosition()
{
	return RelativePosition;
}

void USceneComponent::SetOwnerActor(AActor* OwnerActor)
{
	this->OwnerActor = OwnerActor;
}

void USceneComponent::SetRelativePositionAndCalculateWorldPosition(FVector RelativePosition)
{
	this->RelativePosition = RelativePosition;
	if (OwnerActor)
	{
		WorldPosition.X = OwnerActor->GetPosition().X + RelativePosition.X;
		WorldPosition.Y = OwnerActor->GetPosition().Y + RelativePosition.Y;
	}
	else
	{
		WorldPosition.X = RelativePosition.X;
		WorldPosition.Y = RelativePosition.Y;
	}
}


