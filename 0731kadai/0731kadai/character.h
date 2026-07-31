#pragma once
#include <memory>
// キャラクターのパラメータ
struct charaParam
{
int hp{}; //戦力
int attack{}; //攻撃力
};

class CharaBase {
public:
	//コンストラクタ
	CharaBase();

	//デストラクタ
	virtual ~CharaBase();

	//攻撃
	int Attack();

	//ダメージ
	void damage(int damageSourse);

	//戦力が0か
	bool deaded() const;

	//キャラ名取得
	const char* name() const;

	//キャラのパラメータを取得
	const charaParam& param() const;

	//敵か味方か
	int faction() const;

	//キャラのID取得
	int charaId() const;

public:
	//キャラの種類の初期化
	virtual void initializeType() = 0;

protected:
	charaParam param_{};  //キャラ毎のパラメータ
	char       name_[64]; //キャラの名前
	int        charaId_{};//キャラId
	int        faction_{};//敵か味方
};