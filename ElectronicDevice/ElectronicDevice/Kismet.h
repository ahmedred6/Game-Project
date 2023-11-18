#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;

struct Pixel
{
	char Text;
	int Color;
	COORD Position;
};

	//"\x1b[A" cursor up
//"\x1b[B" cursor down
//"\x1b[C" to the right
//"\x1b[D" cursor left
//01/11/2023 7:42 This is the hardest part, to make my classes alive and to make the engine work
namespace Kismet
{
	
	//string FixShape(string Shape);
	//void EraseShape(string Shape);
	//string InputAsset(ifstream& InputFile,int &NumberOfSections);
	//void GoUp(int NumberOfSections);
	void InputAsset(ifstream& InputFile, vector<Pixel>& Entity, COORD WorldPosition = { 0 });
	vector<Pixel> InitializeScene();
	void UpdateScene(vector<Pixel> Entity, vector<Pixel>& Scene);
	void DisplayScene(vector<Pixel> Scene1, vector<Pixel> Scene2);
	void SetCursorPosition(int x, int y);
	void DisplayInitialScene(vector<Pixel> Scene);
	void AddMovementInput(vector<Pixel>& Entity, COORD Direction);

}
