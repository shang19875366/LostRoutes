#ifndef BASE_LAYBER_H_
#define BASE_LAYBER_H_
#include "cocos2d.h"
#include "SystemHeader.h"
USING_NS_CC;
using namespace std;
class BaseLayer:public cocos2d::Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuBackCallback(Ref* pSender);
	CREATE_FUNC(BaseLayer);
private:

};
#endif // !BASE_LAYBER_H_
