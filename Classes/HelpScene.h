#ifndef HELP_SCENE_H_
#define HELP_SCENE_H_
#include "SystemHeader.h"
#include "cocos2d.h"
#include "BaseLayer.h"
USING_NS_CC;
class HelpLayer:public BaseLayer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelpLayer);
};
#endif // !HELP_SCENE_H_

