#ifndef GAME_PLAY_SCENE_H_
#define GAME_PLAY_SCENE_H_
#include "SystemHeader.h"
#include "cocos2d.h"
#include "BaseLayer.h"
USING_NS_CC;
class GamePlayLayer :public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayLayer);
};
#endif // !GAME_PLAY_SCENE_H_
