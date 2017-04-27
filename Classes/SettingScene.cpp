#include "SettingScene.h"

Scene* SettingLayer::createScene() {
	auto scene = Scene::create();
	auto layer = SettingLayer::create();
	scene->addChild(layer);
	return scene;
}

bool SettingLayer::init() {
	if (!BaseLayer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto top = Sprite::createWithSpriteFrameName("setting-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));
	this->addChild(top);
	auto soundOnSprite = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto soundOffSprite = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto soundOnMenuItem = MenuItemSprite::create(soundOnSprite, NULL);
	auto soundOffMenuItem = MenuItemSprite::create(soundOffSprite, NULL);
	MenuItemToggle* soundMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::menuSoundToggleCallback, this), soundOnMenuItem, soundOffMenuItem, NULL);

	auto musicOnSprite = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto musicOffSprite = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto musicOnMenuItem = MenuItemSprite::create(musicOnSprite, NULL);
	auto musicOffMenuItem = MenuItemSprite::create(musicOffSprite, NULL);
	auto musicMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::menuMusicToggleCallback, this), musicOnMenuItem, musicOffMenuItem, NULL);

	auto mn = Menu::create(soundMenuItem, musicMenuItem, NULL);
	mn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)+Vec2(70,50));
	mn->alignItemsVerticallyWithPadding(25.0f);
	this->addChild(mn);

	auto lblSound = Label::createWithTTF(MyUtility::getUTF8Char("lblSound"), "fonts/hanyi.ttf", 36);
	lblSound->setColor(Color3B(14, 83, 204));
	lblSound->setPosition(mn->getPosition()-Vec2(200,-20));
	lblSound->setAnchorPoint(Vec2::ZERO);
	this->addChild(lblSound);

	auto lblMusic = Label::createWithTTF(MyUtility::getUTF8Char("lblMusic"), "fonts/hanyi.ttf", 36);
	lblMusic->setColor(Color3B(14, 83, 204));
	lblMusic->setPosition(lblSound->getPosition() - Vec2(0, 70));
	lblMusic->setAnchorPoint(Vec2::ZERO);
	this->addChild(lblMusic);

	auto userDefault = UserDefault::getInstance();
	if (userDefault->getBoolForKey(MUSIC_KEY)) {
		musicMenuItem->setSelectedIndex(0);
	}
	else {
		musicMenuItem->setSelectedIndex(1);
	}
	if (userDefault->getBoolForKey(SOUND_KEY)) {
		soundMenuItem->setSelectedIndex(0);
	}
	else {
		soundMenuItem->setSelectedIndex(1);
	}
	return true;
}

void SettingLayer::menuSoundToggleCallback(Ref* pSender) {
	auto userDefault = UserDefault::getInstance();
	if (userDefault->getBoolForKey(SOUND_KEY)) {
		userDefault->setBoolForKey(SOUND_KEY, false);
	}
	else {
		userDefault->setBoolForKey(SOUND_KEY, true);
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
}

void SettingLayer::menuMusicToggleCallback(Ref* pSender) {
	auto userDefault = UserDefault::getInstance();
	if (userDefault->getBoolForKey(MUSIC_KEY)) {
		userDefault->setBoolForKey(MUSIC_KEY, false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
	else {
		userDefault->setBoolForKey(MUSIC_KEY, true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
	}
}