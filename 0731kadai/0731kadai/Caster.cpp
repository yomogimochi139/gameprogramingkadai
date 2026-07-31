#include "Caster.h"
#include <cstdio>

Caster::Caster(int faction) {
	faction_ = faction;
	charaId_ = 2;

	sprintf(name_, "–‚–@Žg‚¢");
}

void Caster::initializeType() {
	param_.hp = 300;
	param_.attack = 25;
}