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
	auto sprite = Sprite::create("clock_white.png");
	sprite->setPosition(ccp(300, 300));
	this->addChild(sprite);
	return true;
}