#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
using namespace std;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                      "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                            origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");
	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);
	auto sprite = Sprite::createWithSpriteFrameName("loding4.png");
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(sprite);
	auto animation = Animation::create();
	for (int i = 1; i <= 4; i++) {
		__String* name = __String::createWithFormat("loding%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(name->getCString()));
	}
	animation->setDelayPerUnit(0.5);
	animation->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animation);
	sprite->runAction(RepeatForever::create(animate));

	m_nNumberOfLoaded = 0;
	Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));
	Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));
	_loadingAudioThread = new thread(&HelloWorld::loadingAudio, this);
    return true;
}

void HelloWorld::loadingTextureCallBack(cocos2d::Texture2D* texture) {
	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist",texture);
		break;

	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist", texture);
		break;

	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist", texture);
		schedule(schedule_selector(HelloWorld::delayCall), 1, 1, 3);
		break;
	default:
		break;
	}
}

void HelloWorld::loadingAudio() {
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);
	SimpleAudioEngine::getInstance()->preloadEffect(sound_1);
	SimpleAudioEngine::getInstance()->preloadEffect(sound_2);
}

void HelloWorld::onExit() {
	Layer::onExit();
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	unschedule(schedule_selector(HelloWorld::delayCall));
}

void HelloWorld::delayCall(float dt) {
	Director::getInstance()->replaceScene(HomeMenuLayer::createScene());
}
