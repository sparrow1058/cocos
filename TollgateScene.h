#pragma once
#ifndef __TOLLGATESCENE_H__
#define __TOLLGATESCENE_H__
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;
class Player;
class TollgateScene :public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	virtual void update(float delta);
	void loadUI();
	void jumpEvent(Ref *, TouchEventType  type);
	CREATE_FUNC(TollgateScene);
private:
	void initBG();
private:
	Sprite * m_bgSprite1;
	Sprite * m_bgSprite2;
	Player * m_player;
private:
	int m_iScore;
	Text* m_scoreLab;
	LoadingBar * m_hpBar;

};

#endif
