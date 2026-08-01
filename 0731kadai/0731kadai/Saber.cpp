#include "Saber.h"
#include <cstdio>

Saber::Saber(int faction) {
	faction_ = faction;
	charaId_ = 1;
	
	printf(name_, "Œ•Žm");
	initializeType();
}

void Saber::initializeType() {
	param_.hp = 300;
	param_.attack = 50;
}
