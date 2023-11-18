#pragma once
#include "FColor.h"
class Material
{
public:
	Material(FColor PrimaryColor, FColor SecondaryColor);
	FColor GetPrimaryColor();
	FColor GetSecondaryColor();
	void SetPrimaryColor(FColor PrimaryColor);
	void SetSecondaryColor(FColor SecondaryColor);
private:
	FColor PrimaryColor;
	FColor SecondaryColor;
};

