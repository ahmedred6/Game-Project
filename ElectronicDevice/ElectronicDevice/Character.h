#pragma once
#include "AActor.h"
#include "Kismet.h"
class UStaticMeshComponent;
class Character :
    public AActor
{
public:                             
    Character(int NumberOfComponents = 1);
    virtual void BeginPlay() override;
    virtual void Tick(char& InputComponent) override;
    UStaticMeshComponent* GetBodyMesh();
    ~Character();
private:
    UStaticMeshComponent* BodyMesh;
    int NumberOfSections;
    vector<Pixel> Sprite1;
    vector<Pixel> Sprite2;
    bool Flag;
    bool DontJump;
public:
    vector<Pixel> Scene1;
    vector<Pixel> Scene2;
};

