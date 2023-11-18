#include "Character.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "UStaticMeshComponent.h"
using namespace Kismet;

Character::Character(int NumberOfComponents):AActor({5,5},1)
{
	NumberOfSections = 0;
	BodyMesh = new UStaticMeshComponent();
	BodyMesh->SetOwnerActor(this);
	BodyMesh->SetRelativePositionAndCalculateWorldPosition({ 0 });
	BodyMesh->SetName("BodyMesh");
	Material* MaterialInstance =  BodyMesh->GetMaterialInstance();
	FColor PrimaryColor = { 44,41,532 };
	MaterialInstance->SetPrimaryColor(PrimaryColor);
	BodyMesh->SetMaterialInstance(MaterialInstance);
	SetRootComponent(BodyMesh);
	Flag = false;
	DontJump = true;
}

void Character::BeginPlay()
{

	ifstream InputFile;
	ifstream SpriteFile;
	SpriteFile.open("Sprite.txt");
	InputFile.open("InputAsset.txt");
	vector<Pixel> Entity;
	InputAsset(InputFile,Entity,GetPosition());
	Sprite1 = Entity;
	InputAsset(SpriteFile, Sprite2, GetPosition());
	BodyMesh->SetStaticMesh(Entity);
	SpriteFile.close();
	InputFile.close();
	UpdateScene(Entity, Scene1);
	
}

void Character::Tick(char& InputComponent)
{
	UpdateScene(BodyMesh->GetStaticMesh(), Scene2);
	COORD Direction = { 0 };
	if (_kbhit())
	{
		InputComponent = _getwch();
		if (InputComponent == 'd')
		{
			Direction.X = 1;
		}
		if (InputComponent == 'a')
		{
			Direction.X = -1;	
		}
		if (InputComponent == 'w')
		{
			Direction.Y = -1;
		}
		if (InputComponent == 's')
		{
			Direction.Y = 1;
		}
		AddMovementInput(Sprite1, Direction);
		AddMovementInput(Sprite2, Direction);
		if (Flag)
		{
			BodyMesh->SetStaticMesh(Sprite1);
			Flag = false;
		}
		else
		{
			BodyMesh->SetStaticMesh(Sprite2);
			Flag = true;
		}
	}
	/*if (_kbhit())
	{
		InputComponent = _getwch();
		//Sleep(60.0);
		if (InputComponent == 'd')
		{
			InputComponent = '*';
			if (Flag)
			{
				EraseShape(Sprite);
				cout << "\x1b[C";
				cout << FixShape(BodyMesh->GetStaticMesh());
				Flag = false;
			}
			else
			{
				EraseShape(BodyMesh->GetStaticMesh());
				cout << "\x1b[C";
				cout << FixShape(Sprite);
				Flag = true;
			}
			SetPosition({ GetPosition().X + 1,GetPosition().Y });
		}
		if (InputComponent == 'a')
		{
			InputComponent = '*';
			SetPosition({ GetPosition().X - 1,GetPosition().Y });
			if (Flag)
			{
				EraseShape(Sprite);
				cout << "\x1b[D";
				cout << FixShape(BodyMesh->GetStaticMesh());
				Flag = false;
			}
			else
			{
				EraseShape(BodyMesh->GetStaticMesh());
				cout << "\x1b[D";
				cout << FixShape(Sprite);
				Flag = true;
			}

		}
		if (InputComponent == 's')
		{
			InputComponent = '*';
			if (Flag)
			{
				EraseShape(Sprite);
				cout << "\x1b[B";
				cout << FixShape(BodyMesh->GetStaticMesh());
				Flag = false;
			}
			else
			{
				EraseShape(BodyMesh->GetStaticMesh());
				cout << "\x1b[B";
				cout << FixShape(Sprite);
				Flag = true;
			}
			SetPosition({ GetPosition().X,GetPosition().Y + 1 });
		}
		if (InputComponent == 'w' && !DontJump)
		{
			InputComponent = '*';
			if (Flag)
			{
				EraseShape(Sprite);
				cout << "\x1b[A\x1b[A\x1b[A\x1b[A";
				cout << FixShape(BodyMesh->GetStaticMesh());
				Flag = false;
			}
			else
			{
				EraseShape(BodyMesh->GetStaticMesh());
				cout << "\x1b[A\x1b[A\x1b[A\x1b[A";
				cout << FixShape(Sprite);
				Flag = true;
			}
			SetPosition({ GetPosition().X,GetPosition().Y - 4 });
		}
	}
	Sleep(60);
	if (GetPosition().Y < 17 && Flag)
	{
		EraseShape(Sprite);
		cout << "\x1b[B";
		cout << FixShape(Sprite);
		SetPosition({ GetPosition().X,GetPosition().Y + 1 });
		DontJump = true;
	}
	else if (GetPosition().Y<17 && !Flag)
	{
		EraseShape(BodyMesh->GetStaticMesh());
		cout << "\x1b[B";
		cout << FixShape(BodyMesh->GetStaticMesh());
		SetPosition({ GetPosition().X,GetPosition().Y + 1 });
		DontJump = true;
	}
	else
	{
		DontJump = false;
	}*/

	UpdateScene(BodyMesh->GetStaticMesh(), Scene1);
}

UStaticMeshComponent* Character::GetBodyMesh()
{
	return BodyMesh;
}

Character::~Character()
{
	delete BodyMesh;
}