#pragma once
#include <memory>
#include "character.h"

int getRandomInt(int min, int max);
std::unique_ptr<CharaBase> createCharacter(int type, int faction);
void evaluatePhase(CharaBase& player, CharaBase& enemy, int playerAction, int enemyAction);