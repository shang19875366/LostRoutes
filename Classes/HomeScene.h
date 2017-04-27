#ifndef HOME_SCENE_H_
#define HOME_SCENE_H_
#include "cocos2d.h"
#include "SystemHeader.h"
#include "GamePlayScene.h"
#include "SettingScene.h"
#include "HelpScene.h"
USING_NS_CC;

typedef enum {
	MenuItemStart,
	MenuItemSetting,
	MenuItemHelp
} ActionType;

class HomeMenuLayer :public cocos2d::Layer {
public:
	static Scene* createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuItemCallback(Ref* pSender);
	CREATE_FUNC(HomeMenuLayer);
};
#endif // !HOME_SCENE_H_

