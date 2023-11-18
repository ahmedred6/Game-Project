#pragma once
#include "FVector.h"
#include "UObject.h"
#include <Windows.h>
class USceneComponent;
class AActor :
    public UObject
{
public:
    AActor(COORD Position = {0}, int NumberOfComponents = 0);
    void SetPosition(COORD Position);
    COORD GetPosition();
    void SetNumberOfComponents(int NumberOfComponents);
    int GetNumberOfComponents();
    USceneComponent* GetRootComponent();
    void SetRootComponent(USceneComponent* RootComponent);
    USceneComponent* GetComponents();
    virtual void BeginPlay() = 0;
    virtual void Tick(char& InputComponent) = 0;
    ~AActor();
private:
    COORD Position;
    USceneComponent* Components;
    USceneComponent* RootComponent;
    int NumberOfComponents;
};

