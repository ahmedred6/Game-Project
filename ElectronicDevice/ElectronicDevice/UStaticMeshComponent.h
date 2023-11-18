#pragma once
#include "USceneComponent.h"
#include "Material.h"
#include "Kismet.h"

class UStaticMeshComponent :
    public USceneComponent
{
public:
    UStaticMeshComponent(string Name = "", string Type = "UStaticMeshComponent", vector<Pixel> StaticMesh = {});
    Material* GetMaterialInstance();
    vector<Pixel> GetStaticMesh();
    void SetMaterialInstance(Material* MaterialInstance);
    void SetStaticMesh(vector<Pixel> StaticMesh);
    ~UStaticMeshComponent();
private:
    Material* MaterialInstance;
    vector<Pixel> StaticMesh;
};

