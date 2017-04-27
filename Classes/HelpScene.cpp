#include "HelpScene.h"
#include "MyUtility.h"
Scene* HelpLayer::createScene() {
	auto scene = Scene::create();
	auto layer = HelpLayer::create();
	scene->addChild(layer);
	return scene;
}

bool HelpLayer::init() {
	if (!BaseLayer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	/*auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);*/
	auto top = Sprite::createWithSpriteFrameName("help-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));
	this->addChild(top);

	auto txtTest = Label::createWithTTF(MyUtility::getUTF8Char("test"), "fonts/hanyi.ttf", 20);
	txtTest->setColor(Color3B(14, 83, 204));
	txtTest->setPosition(100, top->getPosition().y - 70);
	txtTest->setAnchorPoint(Vec2(0, 0));
	this->addChild(txtTest);

	auto test = Label::createWithTTF(MyUtility::gbk_2_utf8("ÉÐÕêÏí"), "fonts/hanyi.ttf", 20);
	test->setColor(Color3B(198, 12, 0));
	test->setPosition(txtTest->convertToWorldSpace(Vec2(0, -20)));
	test->setAnchorPoint(Vec2(0,0));
	this->addChild(test);

	auto txtMusic = Label::createWithTTF(MyUtility::getUTF8Char("music"), "fonts/hanyi.ttf", 20);
	txtMusic->setColor(Color3B(14, 83, 204));
	txtMusic->setPosition(test->convertToWorldSpace(Vec2(0, -40)));
	txtMusic->setAnchorPoint(Vec2(0, 0));
	this->addChild(txtMusic);

	auto music1 = Label::createWithTTF(MyUtility::gbk_2_utf8("ÉÐÕêÏí"), "fonts/hanyi.ttf", 20);
	music1->setColor(Color3B(198, 12, 0));
	music1->setPosition(txtMusic->convertToWorldSpace(Vec2(0, -20)));
	music1->setAnchorPoint(Vec2(0, 0));
	this->addChild(music1);

	auto music2 = Label::createWithTTF(MyUtility::gbk_2_utf8("°¬½ðÏ¼"), "fonts/hanyi.ttf", 20);
	music2->setColor(Color3B(198, 12, 0));
	music2->setPosition(music1->convertToWorldSpace(Vec2(0, -20)));
	music2->setAnchorPoint(Vec2(0, 0));
	this->addChild(music2);

	auto txtSound = Label::createWithTTF(MyUtility::getUTF8Char("sound"), "fonts/hanyi.ttf", 20);
	txtSound->setColor(Color3B(14, 83, 204));
	txtSound->setPosition(music2->convertToWorldSpace(Vec2(0, -40)));
	txtSound->setAnchorPoint(Vec2(0, 0));
	this->addChild(txtSound);

	auto sound1 = Label::createWithTTF(MyUtility::gbk_2_utf8("ÉÐîÚÐù"), "fonts/hanyi.ttf", 20);
	sound1->setColor(Color3B(198, 12, 0));
	sound1->setPosition(txtSound->convertToWorldSpace(Vec2(0, -20)));
	sound1->setAnchorPoint(Vec2(0, 0));
	this->addChild(sound1);

	auto sound2 = Label::createWithTTF(MyUtility::gbk_2_utf8("°¬½ðÏ¼"), "fonts/hanyi.ttf", 20);
	sound2->setColor(Color3B(198, 12, 0));
	sound2->setPosition(sound1->convertToWorldSpace(Vec2(0, -20)));
	sound2->setAnchorPoint(Vec2(0, 0));
	this->addChild(sound2);

	auto txtInfoService = Label::createWithTTF(MyUtility::getUTF8Char("info_service"), "fonts/hanyi.ttf", 20);
	txtInfoService->setColor(Color3B(14, 83, 204));
	txtInfoService->setPosition(sound2->convertToWorldSpace(Vec2(0, -40)));
	txtInfoService->setAnchorPoint(Vec2(0, 0));
	this->addChild(txtInfoService);

	auto info_service = Label::createWithTTF(MyUtility::gbk_2_utf8("13871021402"), "fonts/hanyi.ttf", 20);
	info_service->setColor(Color3B(198, 12, 0));
	info_service->setPosition(txtInfoService->convertToWorldSpace(Vec2(0, -20)));
	info_service->setAnchorPoint(Vec2(0, 0));
	this->addChild(info_service);
	return true;
}