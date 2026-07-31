#pragma once
#include "character.h"

class Caster : public CharaBase
{
public:
	Caster(int faction);
	void initializeType() override;
};

