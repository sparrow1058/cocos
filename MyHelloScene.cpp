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
/*
#if USE_TWO_SPRITE		//Crate two sprite
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *fish1 = Sprite::create("fish1.png");
	fish1->setPosition(Point(visibleSize.width*0.5f - 20, visibleSize.height*0.5f));
	this->addChild(fish1);

	Sprite *fish2 = Sprite::create("fish2.png");
	fish2->setPosition(Point(visibleSize.width*0.5f, visibleSize.height *0.5f));
	this->addChild(fish2);
#endif
	Label *logText1 = Label::create("", "Arial", 24);
	logText1->setPosition(100, 100);
	this->addChild(logText1, 1, 1);
	Label *logText2 = Label::create("", "Arial", 24);
	logText2->setPosition(100, 200);
	this->addChild(logText2, 1, 2);
	Label *logText3 = Label::create("", "Arial", 24);
	logText3->setPosition(100, 300);
	this->addChild(logText3, 1, 3);
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = [&](const std::vector<Touch *>& touches, Event *event) {
		auto logText = (Label *)this->getChildByTag(1);
		int num = touches.size();
		logText->setString(Value(num).asString() + " Touches:");
	};
	listener->onTouchesMoved = [&](const std::vector<Touch *>&touches, Event *event) {
		auto logText = (Label*)this->getChildByTag(2);
		int num = touches.size();
		std::string text=Value(num).asString() + " Touches:";
		for (auto &touch : touches) {
			auto location = touch->getLocation();
			text += "[touchId" + Value(touch->getID()).asString() + "],";
		}
		logText->setString(text);
		log("%d touches moved", num);
	};
	listener->onTouchesEnded = [&](const std::vector<Touch*>&touches, Event *event) {
		auto logText = (Label*)this->getChildByTag(3);
		int num = touches.size();
		logText->setString(Value(num).asString() + "Touches:");
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	*/

/* get which sprite touchevent
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event *event) {
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		if (target->getBoundingBox().containsPoint(pos)) {
			target->setOpacity(100);
			return true;
		}
		return false;
	};
	listener->onTouchEnded = [](Touch *touch, Event *event) {
		auto target = static_cast<Sprite *>(event->getCurrentTarget());
		target->setOpacity(255);
	};
//	listener->setSwallowTouches(true);		//touch event with more layers
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, fish1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), fish2);
*/	

/*  get the touchevent
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

*/
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