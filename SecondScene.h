#ifndef __SecondScene_H__
#define __SecondScene_H__
#include "cocos2d.h"
using namespace cocos2d;
class SecondScene :public Layer {
public :
	static Scene * createScene();
	virtual bool init();
	void popScene(Ref *pSender);
	CREATE_FUNC(SecondScene);
};
#endif