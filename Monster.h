#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Entity.h"
#include "Player.h"
class Monster :public Entity {
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();
public:
	void show();
	void hide();
	void reset();
	bool isAlive();
	bool isCollideWithPlayer(Player *player);
private:
	bool m_isAlive;

};

#endif