#include "character.h"
#include<string>

CharaBase::CharaBase(){
	std::memset(name_, 0, sizeof(name_));
}

CharaBase::~CharaBase() {}

int CharaBase::Attack() {
	return param_.attack;
}

void CharaBase::damage(int damageSourse) {
	param_.hp -= damageSourse;
	if (param_.hp < 0) {
		param_.hp = 0;
	}
}

bool CharaBase::deaded() const {
	return param_.hp <= 0;
}

const charaParam& CharaBase::param() const {
	return param_;
}

const char* CharaBase::name() const {
	return name_;
}

int CharaBase::faction() const {
	return faction_;
}

int CharaBase::charaId() const {
	return charaId_;
}