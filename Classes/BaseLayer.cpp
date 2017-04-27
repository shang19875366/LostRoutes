#include "BaseLayer.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
Scene* BaseLayer::createScene() {
	auto scene = Scene::create();
	auto layer = BaseLayer::create();
	scene->addChild(layer);
	return scene;
}

bool BaseLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);
	auto glassesSprite = Sprite::createWithSpriteFrameName("setting.glasses.png");
	glassesSprite->setPosition(Vec2(visibleSize.width - glassesSprite->getContentSize().width / 2, 160));
	this->addChild(glassesSprite);

	auto handSprite = Sprite::createWithSpriteFrameName("setting.hand.png");
	handSprite->setPosition(Vec2(handSprite->getContentSize().width / 2, 60));
	this->addChild(handSprite);

	auto menuItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("setting.button.ok.png"), Sprite::createWithSpriteFrameName("setting.button.ok-on.png"), CC_CALLBACK_1(BaseLayer::menuBackCallback, this));
	auto mn = Menu::create(menuItem, NULL);
	mn->setPosition(Vec2(visibleSize.width-mn->getContentSize().width/2+60,45));
	this->addChild(mn);
	return true;
}

void BaseLayer::onEnterTransitionDidFinish() {
	Layer::onEnterTransitionDidFinish();
	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
	}
}

void BaseLayer::menuBackCallback(Ref* pSender) {
	Director::getInstance()->popScene();
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
}