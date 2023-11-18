#pragma once
#include "UObject.h"
#include "FVector.h"
#include <string>
class AActor;
class USceneComponent:public UObject
{
public:
	USceneComponent(string Type = "USceneComponent", string Name = "", FVector RelativePostion = {0}, AActor* OwnerActor = NULL);
	AActor* GetOwnerActor();
	FVector GetWorldPosition();
	FVector GetRelativePosition();
	void SetOwnerActor(AActor* OwnerActor);
	void SetRelativePositionAndCalculateWorldPosition(FVector RelativePosition);
	string GetType() { return Type; };
protected:
	string Type;
private:
	AActor* OwnerActor;
	FVector WorldPosition;
	FVector RelativePosition;
};

