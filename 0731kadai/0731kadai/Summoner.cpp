#include "Summoner.h"
#include <cstdio>

Summoner::Summoner(int faction) {
	faction_ = faction;
	charaId_ = 3;

	sprintf(name_, "è¢ä´ém");
}

void Summoner::initializeType() {
	param_.hp = 300;
	param_.attack = 25;
}