#include "UObject.h"


UObject::UObject(string Name)
{
	SetName(Name);
}

void UObject::SetName(string Name)
{
	this->Name = Name;
}

string UObject::GetName()
{
	return Name;
}
