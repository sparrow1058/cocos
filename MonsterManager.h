#ifndef __MONSTERMANAGER_H__
#define __MONSTERMANAGER_H__
#include "cocos2d.h"
#include "Monster.h"
#include "Player.h"
USING_NS_CC;
#define MAX_MONSTER_NUM	10
class MonsterManager :public Node {
public:
	CREATE_FUNC(MonsterManager);
	virtual bool init();
	virtual void update(float dt);
	void bindPlayer(Player *player);
private:
	void createMonsters();
private:
	Player *m_player;
	Vector<Monster *> m_monsterArr;
};


#endif // 
