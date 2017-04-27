#include "HomeScene.h"
#include "cocos2d.h"
USING_NS_CC;

Scene* HomeMenuLayer::createScene() {
	auto scene = Scene::create();
	auto layer = HomeMenuLayer::create();
	scene->addChild(layer);
	return scene;
}

bool HomeMenuLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);

	auto top = Sprite::createWithSpriteFrameName("home-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));
	this->addChild(top);
	auto end = Sprite::createWithSpriteFrameName("home-end.png");
	end->setPosition(Vec2(visibleSize.width / 2, end->getContentSize().height / 2));
	this->addChild(end);

	auto startMenuItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("home.button.start.png"), Sprite::createWithSpriteFrameName("home.button.start-on.png"), CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
	startMenuItem->setTag(ActionType::MenuItemStart);
	auto settingMenuItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("home.button.setting.png"), Sprite::createWithSpriteFrameName("home.button.setting-on.png"), CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
	settingMenuItem->setTag(ActionType::MenuItemSetting);
	auto helpMenuItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("home.button.help.png"), Sprite::createWithSpriteFrameName("home.button.help-on.png"), CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
	helpMenuItem->setTag(ActionType::MenuItemHelp);

	auto mn = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);
	mn->alignItemsVerticallyWithPadding(12);
	mn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(mn);
	return true;
}

void HomeMenuLayer::onEnterTransitionDidFinish() {
	Layer::onEnterTransitionDidFinish();
	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
	}
	
}

void HomeMenuLayer::menuItemCallback(Ref* pSender) {
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
	MenuItem* item = (MenuItem*)pSender;
	Scene* ts = nullptr;
	switch (item->getTag())
	{
	case ActionType::MenuItemStart:
		ts = TransitionFade::create(1.0f, GamePlayLayer::createScene());
		break;

	case ActionType::MenuItemSetting:
		ts = TransitionFade::create(1.0f, SettingLayer::createScene());
		break;

	case ActionType::MenuItemHelp:
		ts = TransitionFade::create(1.0f, HelpLayer::createScene());
		break;
	default:
		break;
	}
	if (ts) {
		Director::getInstance()->pushScene(ts);
	}
}