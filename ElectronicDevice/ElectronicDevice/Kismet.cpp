#include "Kismet.h"
static const int Height = 50;
static const int Width = 200;

namespace Kismet
{

	void DisplayScene(vector<Pixel> Scene1, vector<Pixel> Scene2)
	{
		for (unsigned int i = 0; i < Scene1.size(); i++)
		{
			if (Scene1[i].Text != Scene2[i].Text)
			{
				SetCursorPosition(Scene1[i].Position.X, Scene1[i].Position.Y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Scene1[i].Color);
				cout << Scene1[i].Text;
			}
		}
	}
	void UpdateScene(vector<Pixel> Entity, vector<Pixel>& Scene)
	{
		for (unsigned int i = 0; i < Scene.size(); i++)
		{
			for (unsigned int j = 0; j < Entity.size(); j++)
			{
				if (Entity[j].Position.X == Scene[i].Position.X && Entity[j].Position.Y == Scene[i].Position.Y)
				{
					Scene[i] = Entity[j];
				}
			}
		}

	}
	vector<Pixel> InitializeScene()
	{
		vector<Pixel> Scene;
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				Pixel PixelInstance;
				PixelInstance.Text = ' ';
				PixelInstance.Color = 40;
				PixelInstance.Position.X = j;
				PixelInstance.Position.Y = i;
				Scene.push_back(PixelInstance);
			}
		}
		return Scene;
	}
	void InputAsset(ifstream& InputFile, vector<Pixel>& Entity, COORD WorldPosition)
	{
		int NumberOfLines;
		InputFile >> NumberOfLines;
		for (int i = 0; i < NumberOfLines; i++)
		{
			string Line;
			getline(InputFile, Line);
			for (unsigned int j = 0; j < Line.size(); j++)
			{
				if (Line[j] != ' ')
				{
					Pixel PixelInstance;
					PixelInstance.Text = '0';
					PixelInstance.Position.X = j + WorldPosition.X;
					PixelInstance.Position.Y = i + WorldPosition.Y;
					PixelInstance.Color = 17;

					Entity.push_back(PixelInstance);
				}
			}
		}
	}
	void SetCursorPosition(int x, int y) {
		COORD coordinates;
		coordinates.X = x;
		coordinates.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
	}
	void DisplayInitialScene(vector<Pixel> Scene)
	{
		for (unsigned int i = 0; i < Scene.size(); i++)
		{
			SetCursorPosition(Scene[i].Position.X, Scene[i].Position.Y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Scene[i].Color);
			cout << Scene[i].Text;
		}
	}
	void AddMovementInput(vector<Pixel>& Entity, COORD Direction)
	{
		for (unsigned int i = 0; i < Entity.size(); i++)
		{
			Entity[i].Position.X += Direction.X;
			Entity[i].Position.Y += Direction.Y;
		}
	}
}
	/*string FixShape(string Shape)
	{
		/// <summary>
		/// The Function takes a shape 
		/// and replace '\n' and ' ' with
		/// unicodes specialized in adjusting the
		/// position of the cursor
		/// </summary>
		/// <param name="Shape">Takes the unfixed shape</param>
		/// <returns>Returns the fixed shape</returns>
		string FixedShape = "";
		int Section = 0;
		for (int i = 0; i < Shape.size(); i++)
		{
			if (Shape[i] != '\n')//&& Shape[i] != ' ')
			{
				FixedShape += Shape[i];
				Section += 1;
			}
			if (Shape[i] == '\n')
			{
				for (int j = 0; j < Section; j++)
				{
					FixedShape += '\b';
				}
				Section = 0;
				FixedShape += "\x1b[B";
			}
			/*if (Shape[i] == ' ')
			{
				FixedShape += "\x1b[C";
			}
		}
		return FixedShape;
	}
	void EraseShape(string Shape)
	{
		
		for (int i = Shape.size() - 1; i >= 0; i--)
		{
			if (Shape[i] != '\n')
			{
				cout << "\b \b";
			}
			else
			{
				int j = i - 1;
				while (j < Shape.size() && Shape[j] != '\n')
				{
					cout << "\x1b[C";
					j--;
				}
				cout << "\x1b[A";
			}
		}
		/*for (int i = 0; i < Shape.size(); i++)
		{
			cout << "\x1b[C";
			if (Shape[i] == '\n')
			{
				break;
			}
		}
	}
	string InputAsset(ifstream& InputFile,int& NumberOfSections)
	{
		NumberOfSections = 0;
		InputFile >> NumberOfSections;
		string Asset;
		string Section = "";
		for (int i = 0; i < NumberOfSections; i++)
		{
			getline(InputFile, Section);
			if (i != NumberOfSections - 1)
			{
				Asset += Section + '\n';
			}
			else
			{
				Asset += Section;
			}
		}
		return Asset;
	}
	void GoUp(int NumberOfSections)
	{
		for (int i = 0; i < NumberOfSections; i++)
		{
			cout << "\x1b[A";
		}
	}*/



/*

Sleep(60.0);
	if (InputComponent == 'd')
	{
		InputComponent = '*';
		EraseShape(BodyMesh->GetStaticMesh());
		cout << FixShape(BodyMesh->GetStaticMesh());
		//GoUp(NumberOfSections);
		SetPosition({ GetPosition().X + 1,GetPosition().Y });
	}
	if (InputComponent == 'a')
	{
		InputComponent = '*';
		SetPosition({ GetPosition().X - 1,GetPosition().Y });
		cout << "\b\b@";
	}
	if (InputComponent == 's')
	{
		InputComponent = '*';
		cout << "\n";
		for (int i = 0; i <= GetPosition().X; i++)
		{
			if (i == GetPosition().X)
			{
				cout << "@";
			}
			else
			{
				cout << "\x1b[C";
			}
		}
		SetPosition({ GetPosition().X,GetPosition().Y - 1 });
	}
	if (InputComponent == 'w')
	{
		InputComponent = '*';
		cout << "\x1b[A\b@";
		SetPosition({ GetPosition().X,GetPosition().Y + 1 });
	}
	if (InputComponent == 'l')
	{
		InputComponent = '*';
		SetPosition({ GetPosition().X + 1,GetPosition().Y});
		cout << "\b @";
	}
	if (InputComponent == 'j')
	{
		InputComponent = '*';
		SetPosition({ GetPosition().X - 1,GetPosition().Y });
		cout << "\b \b\b@";
	}
	if (InputComponent == 'k')
	{
		InputComponent = '*';
		cout << "\b \n";
		for (int i = 0; i <= GetPosition().X; i++)
		{
			if (i == GetPosition().X)
			{
				cout << "@";
			}
			else
			{
				cout << "\x1b[C";
			}
		}
		SetPosition({ GetPosition().X, GetPosition().Y - 1 });
	}
	if (InputComponent == 'i')
	{
		InputComponent = '*';
		cout << "\b \x1b[A\b@";
		SetPosition({ GetPosition().X, GetPosition().Y + 1 });
	}

*/
