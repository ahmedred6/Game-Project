#pragma once
#include "AActor.h"
class Gun :
    public AActor
{
public:
    Gun();
    virtual void BeginPlay() override;
    virtual void Tick(char& InputComponent) override;
    ~Gun();
private:
    class UStaticMeshComponent* GunMesh;
    int NumberOfSections;
    class Character* OwnerCharacter;
};

