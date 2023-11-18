#include <vector>
#include <conio.h>
#include <Windows.h>
#include "Character.h"
#include "Gun.h"
#include "USceneComponent.h"
using namespace Kismet; 

int main()
{
	Sleep(5000);
	/*HANDLE ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandler, 16);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << "\x1b[C";
		}
		if (i == 79)
		{
			SetConsoleTextAttribute(ConsoleHandler, 32);
		}
		cout << "\n";
	}
	SetConsoleTextAttribute(ConsoleHandler, 16);
	for (int i = 0; i < 100; i++)
	{
		cout << "\x1b[D";
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "\x1b[A";
	}*/
	Character CharacterInstance;
	CharacterInstance.Scene1 = InitializeScene();

	char InputComponent;
	
	//Gun GunInstance;
	//GunInstance.BeginPlay();

	CharacterInstance.BeginPlay();
	DisplayInitialScene(CharacterInstance.Scene1);
	//DisplayInitialScene(Scene1);

	do
	{
		CharacterInstance.Scene1 = InitializeScene();
		CharacterInstance.Scene2 = InitializeScene();

		CharacterInstance.Tick(InputComponent);


		DisplayScene(CharacterInstance.Scene1, CharacterInstance.Scene2);
	} while (7>4);
	return 0;
}


/*USceneComponent* Components = CharacterInstance.GetComponents();
	for (int i = 0; i < CharacterInstance.GetNumberOfComponents(); i++)
	{
		if (Components[i].GetType() == "USceneComponent")
		{
			cout << "efe";
			UStaticMeshComponent* Mesh = static_cast<UStaticMeshComponent*>(&Components[i]);
			if (Mesh)
			{
				cout << FixShape(Mesh->GetStaticMesh());
			}
			else
			{
				cout << "Failed";
			}
		}
	}*/