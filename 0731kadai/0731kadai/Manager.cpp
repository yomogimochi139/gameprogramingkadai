#include "Manager.h"
#include "Saber.h"
#include "Caster.h"
#include "Summoner.h"
#include<iostream>
#include<random>
#include<chrono>

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int getRandom(int min, int max) {
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

std::unique_ptr<CharaBase> createCharacter(int type, int fction) {
	switch(type) {
		case 1:
			return std::make_unique<Saber>(fction);
		case 2:
			return std::make_unique<Caster>(fction);
		case 3:
			return std::make_unique<Summoner>(fction);
		default: 
			return std::make_unique<Saber>(fction);
	}
}

static int getCompatibility(int atkId, int defId) {
	if (atkId == defId) return 0;//引き分け

	if ((atkId == 1 && defId == 3) ||
		(atkId == 2 && defId == 1) ||
		(atkId == 3 && defId == 2)) {
		return 1; //クリティカル
	}
	return 2;//カウンター
}

void evaluatePhase(CharaBase& player, CharaBase& enemy, int playerAction, int enemyAction) {

	const char* pActStr = (playerAction == 1) ? "攻撃" : "防御";
	const char* eActStr = (enemyAction == 1)  ? "攻撃" : "防御";

	std::cout << "プレイヤー" << player.name() << "の" << pActStr << std::endl;
	std::cout << "敵" << enemy.name() << "の" << eActStr << std::endl;

	int pAtk = player.Attack();
	int eAtk = enemy.Attack();

	if(playerAction == 1 && enemyAction == 1){
		
		if (pAtk > eAtk) {
			enemy.damage(pAtk);
			std::cout << "プレイヤーの攻撃！敵に" << pAtk << "のダメージ！" << std::endl;
		}
		else if (pAtk < eAtk) {
			player.damage(eAtk);
			std::cout << "敵の攻撃！プレイヤーに" << eAtk << "のダメージ！" << std::endl;
		}
		else {
			std::cout << "引き分け！" << std::endl;
		}
	}
	else if (playerAction == 2 && enemyAction == 2) {
		std::cout << "何も起こらなかった" << std::endl;
	}
	else if (playerAction == 1 && enemyAction == 2) {
		int comp = getCompatibility(player.charaId(), enemy.charaId());
		int damage = pAtk * 2;

		if (comp == 1) {
			enemy.damage(damage);
			std::cout << "クリティカル！敵に" << damage << "のダメージ！" << std::endl;
		}
		else if (comp == 2) {
			player.damage(damage);
			std::cout << "カウンター！プレイヤーに" << damage << "のダメージ！" << std::endl;
		}
		else {
			std::cout << "引き分け！" << std::endl;	
		}
	}
	else if (playerAction == 2 && enemyAction == 1) {
		int comp = getCompatibility(enemy.charaId(), player.charaId());
		int damage = eAtk * 2;
		if (comp == 1) {
			player.damage(damage);
			std::cout << "クリティカル！プレイヤーに" << damage << "のダメージ！" << std::endl;
		}
		else if (comp == 2) {
			enemy.damage(damage);
			std::cout << "カウンター！敵に" << damage << "のダメージ！" << std::endl;
		}
		else {
			std::cout << "引き分け！" << std::endl;	
		}
	}