#pragma once
#ifndef _MyHelloScene_H_
#define _MYHelloScene_H_
#include "cocos2d.h"
using namespace cocos2d;
class MyHelloScene :public Layer {
public:
	static Scene * createScene();
	virtual bool init();
	CREATE_FUNC(MyHelloScene);
};


#endif