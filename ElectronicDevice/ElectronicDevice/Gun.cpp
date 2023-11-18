#include "Gun.h"
#include "Character.h"
#include "Kismet.h"
using namespace Kismet;
Gun::Gun()
{
	/*OwnerCharacter = 0;
	NumberOfSections = 0;
	GunMesh = new UStaticMeshComponent();
	GunMesh->SetOwnerActor(this);
	GunMesh->SetRelativePositionAndCalculateWorldPosition({ 0 });
	GunMesh->SetName("BodyMesh");
	Material* MaterialInstance = GunMesh->GetMaterialInstance();
	FColor PrimaryColor = { 44,41,532 };
	MaterialInstance->SetPrimaryColor(PrimaryColor);
	GunMesh->SetMaterialInstance(MaterialInstance);
	SetRootComponent(GunMesh);*/
}

void Gun::BeginPlay()
{
	/*ifstream InputFile;
	InputFile.open("GunAsset.txt");
	string GunAsset = InputAsset(InputFile, NumberOfSections);
	GunMesh->SetStaticMesh(GunAsset);
	InputFile.close();*/
}

void Gun::Tick(char& InputComponent)
{
	
}

Gun::~Gun()
{
}
