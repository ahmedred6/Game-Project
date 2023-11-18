#include "Material.h"

Material::Material(FColor PrimaryColor, FColor SecondaryColor)
{
	SetPrimaryColor(PrimaryColor);
	SetSecondaryColor(SecondaryColor);
}

FColor Material::GetPrimaryColor()
{
	return PrimaryColor;
}

FColor Material::GetSecondaryColor()
{
	return SecondaryColor;
}

void Material::SetPrimaryColor(FColor PrimaryColor)
{
	this->PrimaryColor = PrimaryColor;
}

void Material::SetSecondaryColor(FColor SecondaryColor)
{
	this->SecondaryColor = SecondaryColor;
}
