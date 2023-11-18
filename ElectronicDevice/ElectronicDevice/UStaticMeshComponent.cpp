#include "UStaticMeshComponent.h"

UStaticMeshComponent::UStaticMeshComponent(string Type,string Name,vector<Pixel> StaticMesh) : MaterialInstance(new Material({ 0 }, {0})),USceneComponent(Type)
{
	SetStaticMesh(StaticMesh);
	SetMaterialInstance(MaterialInstance);
	Type = "UStaticMeshComponent";
}

Material* UStaticMeshComponent::GetMaterialInstance()
{
	return MaterialInstance;
}

vector<Pixel> UStaticMeshComponent::GetStaticMesh()
{
	return StaticMesh;
}

void UStaticMeshComponent::SetMaterialInstance(Material* MaterialInstance)
{
	this->MaterialInstance = MaterialInstance;
}

void UStaticMeshComponent::SetStaticMesh(vector<Pixel> StaticMesh)
{
	this->StaticMesh = StaticMesh;
}

UStaticMeshComponent::~UStaticMeshComponent()
{
	delete MaterialInstance;
}
