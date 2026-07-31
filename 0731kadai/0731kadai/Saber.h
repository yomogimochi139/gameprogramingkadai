#pragma once
#include "character.h"

class Saber : public CharaBase
{
public:
	Saber(int faction);
	void initializeType() override;
};

