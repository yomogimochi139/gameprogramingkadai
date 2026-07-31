#pragma once
#include "character.h"

class Summoner : public CharaBase
{
public:
	Summoner(int faction);
	void initializeType() override;
};

