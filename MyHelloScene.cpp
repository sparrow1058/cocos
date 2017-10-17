#include "MyHelloScene.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
using namespace cocos2d::extension;
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
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *fish2 = Sprite::create("fish2.png");
	fish2->setPosition(Point(visibleSize.width, visibleSize.height / 2));
	this->addChild(fish2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event) {
		Point pos1 = touch->getLocation();			//position in 3d
		Point pos2 = touch->getLocationInView();	//positiion in 2d
		Point pos3 = Director::getInstance()->convertToGL(pos2);
		log("touch event p1= %f,%f|p2= %f,%f|p3= %f,%f \n", pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y);
			return true;
	};
	listener->onTouchMoved = [](Touch* touch, Event* event) {
		log("touch move");
	};
	listener->onTouchEnded = [](Touch* touch, Event* event) {
		log("touch end ");
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


/* CallBack Used for animation
	MoveTo *moveToHome = MoveTo::create(10.0f, Point(visibleSize.width/4, visibleSize.height / 2));
	auto callbackFunc = [=]() {
		//	backHome();
		JumpBy *jumpBy = JumpBy::create(3.0f, Point(50, 1), 100, 5);
		fish2->runAction(jumpBy);
	};
	CallFunc * callFunc = CallFunc::create(callbackFunc);
	Action * actions = Sequence::create(moveToHome, callFunc, NULL);
	fish2->runAction(actions);
*/
/* more actions Spawn or Sequence
	MoveBy *moveBy = MoveBy::create(2.2f, Point(40, 20));
	JumpBy *jumpBy = JumpBy::create(3.0f, Point(50, 1), 100, 5);

	RotateBy * rotateBy = RotateBy::create(2.5f, 200, 10);
	//Action * actions = Spawn::create(moveBy, jumpBy, rotateBy, NULL);
	Action * actions = Sequence::create(moveBy, jumpBy, rotateBy, NULL);
	fish2->runAction(actions);
*/
/*Jump fish forever
	JumpBy *jumpBy = JumpBy::create(3.0f, Point(50, 1), 100, 1);
	RepeatForever *repeatForeverAction = RepeatForever::create(jumpBy);	//Repeat for ever
	Repeat *repeatAction = Repeat::create(jumpBy,3);
	fish2->runAction(repeatForeverAction);
*/
/* Bezier type
	ccBezierConfig bezier;
	bezier.controlPoint_1 = Point(100, 0);
	bezier.controlPoint_2 = Point(200, 250);
	bezier.endPosition = Point(300,50);
//	BezierTo * bezierTo = BezierTo::create(4.0f, bezier);
//	fish2->runAction(bezierTo);
	BezierBy * bezierBy = BezierBy::create(4.0f, bezier);
	fish2->runAction(bezierBy);
*/

//	MoveTo * moveTo = MoveTo::create(0.9f, Point(250, 250));
//	fish2->runAction(moveTo);
//	MoveBy * moveBy = MoveBy::create(0.9f, Point(250, 250));
//	fish2->runAction(moveBy);
/*
	auto sprite = Sprite::create("fish.png");
	sprite->setPosition(ccp(300, 300));
	this->addChild(sprite);
*/
/*
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
*/
/* Vector Use
	Label *label1 = Label::create("XiaoRuo.1", "Arial", 30);
	label1->setPosition(Point(250, 100));
	Label * label2 = Label::create("XiaoRuo.2", "Arial", 30);
	label2->setPosition(Point(250, 60));
	
	Vector<Label *>vec;
	vec.pushBack(label1);
	vec.pushBack(label2);

	for (auto lab : vec) {
		this->addChild(lab);
	}

*/
/*	Map type
	Map <int, Label *> xiaoRuoMap;
	for (int i = 1; i <= 100; i++) {
		std::string name = "XiaoRuoNO." + Value(i).asString();
		Label* lab = Label::create(name.c_str(), "Arial", 30);
		xiaoRuoMap.insert(i, lab);
	}
	Label * xiaoRuoLab = xiaoRuoMap.at(23);
	xiaoRuoLab->setPosition(Point(200, 100));
	this->addChild(xiaoRuoLab);
*/
//Play music	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("dxj.mp3", true);
//	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("error.mp3");		//Play short sound effect
/*Scale9Sprite*/
/* Scale9Sprite
	Scale9Sprite * nineGirl = Scale9Sprite::create("fish2.png");
	nineGirl->setContentSize(Size(200, 100));
	nineGirl->setPosition(Point(200, 20));
	this->addChild(nineGirl);
	*/

	return true;
}
void MyHelloScene::menuCloseCallback(Ref * pSender)
{
	Value valStr = Value("test string");
	Value valInt = Value(2123);
	log("%s %d", valStr.asString().c_str(), valInt.asInt());


}
void  MyHelloScene::backHome()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Label *label = Label::create("I am home!", "Arial", 24);
	label->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(label);
}