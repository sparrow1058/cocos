#include "MyHelloScene.h"
Scene * MyHelloScene::createScene() {
	//Create a scene
	auto scene = Scene::create();
	//Create a Layer
	auto layer = MyHelloScene::create();
	scene->addChild(layer);
	return scene;
}
bool MyHelloScene::init() {
	if (!Layer::init()) {
		return false;
	}
	auto sprite = Sprite::create("fish.png");
	sprite->setPosition(ccp(300, 300));
	this->addChild(sprite);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	MenuItemImage * pCloseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(MyHelloScene::menuCloseCallback));
		
	Label *label = Label::create("label item", "Arial", 30);
	MenuItemLabel *pLabelItem = MenuItemLabel::create(label);
	Menu *pMenu = Menu::create(pCloseItem, pLabelItem, NULL);

	pMenu->alignItemsVertically();
	pMenu->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(pMenu, 1);

	return true;
}
void MyHelloScene::menuCloseCallback(Ref * pSender)
{

}