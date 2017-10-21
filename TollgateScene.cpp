#include "TollgateScene.h"
#include "Player.h"
#include "MonsterManager.h"
Scene * TollgateScene::createScene() {
	auto scene = Scene::create();
	auto layer = TollgateScene::create();
	scene->addChild(layer);
	return scene;
}
bool TollgateScene::init() {
	if (!Layer::init()) { return false; }
	Size visibleSize = Director::getInstance()->getVisibleSize();
/*	
	//game title
	Sprite * titleSprite = Sprite::create("title.png");
	titleSprite->setPosition(Point(visibleSize.width * 0.5f, visibleSize.height - 50));
	this->addChild(titleSprite,2);
*/
	//Create Player
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("sprite.png"));
	m_player->setPosition(Point(200, visibleSize.height / 4));
	this->addChild(m_player, 3);
	initBG();
	loadUI();
	this->scheduleUpdate();
	MonsterManager *monsterMgr = MonsterManager::create();
	this->addChild(monsterMgr, 4);
	monsterMgr->bindPlayer(m_player);
	return true;
}
void TollgateScene::initBG() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	m_bgSprite1 = Sprite::create("tollgateBG.jpg");
	m_bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2 = Sprite::create("tollgateBG.jpg");
	m_bgSprite2->setFlippedX(true);
	m_bgSprite2->setPosition(Point(visibleSize.width*1.5f, visibleSize.height / 2));
	
	this->addChild(m_bgSprite2, 0);
}
void TollgateScene::update(float delta) {
	//log("update");
	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();
	int iSpeed = 1;
	m_iScore += 1;
	posX1 -= iSpeed;
	posX2 -= iSpeed;
	Size mapSize = m_bgSprite1->getContentSize();
//	Size mapSize = Director::getInstance()->getVisibleSize();

	if (posX1 <= -mapSize.width / 2) {
		posX1 = mapSize.width*1.5f;
	}
	if (posX2 <= -mapSize.width / 2) {
		posX2 = mapSize.width*1.5f;
	}
	m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);
	m_scoreLab->setText(Value(m_iScore).asString());
	m_hpBar->setPercent(m_player->getiHP() / 1000.0f * 100);

}
void TollgateScene::loadUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("LitterRunnerUI_1.ExportJson");
	this->addChild(UI);
	auto jumpBtn = (Button*)Helper::seekWidgetByName(UI, "JumpBtn");
	jumpBtn->addTouchEventListener(this, toucheventselector(TollgateScene::jumpEvent));
	m_scoreLab = (Text *)Helper::seekWidgetByName(UI, "scoreLab");
	m_hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "hpProgress");
}
void TollgateScene::jumpEvent(Ref *, TouchEventType type) {
	switch (type) {
	case TouchEventType::TOUCH_EVENT_ENDED:
		m_player->jump();
	}

}