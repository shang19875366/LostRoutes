#ifndef SETTING_SCENE_H_
#define SETTING_SCENE_H_
#include "SystemHeader.h"
#include "cocos2d.h"
#include "BaseLayer.h"
#include "MyUtility.h"
USING_NS_CC;
class SettingLayer :public BaseLayer {
public:
	static Scene* createScene();
	virtual bool init();
	void menuSoundToggleCallback(Ref* pSender);
	void menuMusicToggleCallback(Ref* pSender);
	CREATE_FUNC(SettingLayer);
};
#endif // !SETTING_SCENE_H_

