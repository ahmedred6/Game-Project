#pragma once
#include <string>
using namespace std;
class UObject
{
public:
	UObject(string Name  = "");
	void SetName(string Name);
	string GetName();
private:
	string Name;
};

