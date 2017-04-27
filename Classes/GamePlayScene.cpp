#include "GamePlayScene.h"

Scene* GamePlayLayer::createScene() {
	auto scene = Scene::create();
	auto layer = GamePlayLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GamePlayLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto top = Sprite::createWithSpriteFrameName("help-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));
	this->addChild(top);
	return true;
}