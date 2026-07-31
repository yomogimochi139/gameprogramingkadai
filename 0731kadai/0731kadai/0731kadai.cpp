#include <iostream>
#include<memory>
#include "character.h"
#include "Manager.h"

int main()
{
	int playerHp = 300;
	int enemyHp = 300;
	int turn = 1;

	int playerCharachoice = 0;

	while (playerHp > 0 && enemyHp > 0) {
		std::cout << "ターン " << turn << std::endl;
		std::cout << "現在のプレイヤー戦力" << playerHp << std::endl;
		std::cout << "現在の敵戦力" << enemyHp << std::endl;

		std::cout << "使用キャラクターを選択してください (1: 剣士, 2: 魔法使い, 3: 召喚士): ";

		std::cin >> playerCharachoice;
	}

	std::cout << "行動を選択してください (1: 攻撃, 2: 防御): " << std::endl;

	int playerAction = 0;
	while (playerAction != 1 && playerAction != 2) {
		std::cin >> playerAction;
	}

	std::unique_ptr<CharaBase> playerCharacter = createCharacter(playerCharachoice, 0);
	std::unique_ptr<CharaBase> enemyCharacter = createCharacter(getRandomInt(1, 3), 1);

	int enemyAction = getRandomInt(1, 2);

	evaluatePhase(*playerCharacter, *enemyCharacter, playerAction, enemyAction);
	playerHp = playerCharacter->param().hp;
	enemyHp = enemyCharacter->param().hp;

	std::cout << "プレイヤーの残り戦力: " << playerHp << std::endl;
	std::cout << "敵の残り戦力: " << enemyHp << std::endl;

	turn++;
    
	if (playerHp > 0&&enemyHp <= 0) {
		std::cout << "勝利！" << std::endl;
	}
	else if (enemyHp > 0&&playerHp <= 0) {
		std::cout << "敗北" << std::endl;
	}
	else
	{
		std::cout << "引き分け" << std::endl;
	}
	return 0;
}