/*
 * TutorialScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#include "TutorialScene.h"
#include "MenuScene.h"
#include "AudioManager.h"
#include "Global.h"
#include "MyMacro.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* TutorialScene::scene()
{
	CCLog("scene");
	CCScene *scene = CCScene::create();
	TutorialScene *layer = TutorialScene::create();
	scene->addChild(layer);
	return scene;
}

bool TutorialScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	//background
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_pSpritebackground = CCSprite::create("guide_background.png");
	m_pSpritebackground->setPosition(ccp(CONF_INT(DESIGN_WIDTH) >> 1, CONF_INT(DESIGN_HEIGHT) >> 1));
	this->addChild(m_pSpritebackground, 0);

	//
	CCSprite* tutLine = CCSprite::create("mind_box_tut.png");
	tutLine->setPosition(ccp(400, 1280-1004));
	addChild(tutLine);

	//layerLevel
	m_index = 0;
	m_total = 7;
	initControll();
	m_pLayerContent = initLayerContent(m_index);
	this->addChild(m_pLayerContent, 5);
	//

	this->setKeypadEnabled(true);
	return true;
}

void TutorialScene::onTouchbtnNext(CCObject* pSender)
{
	PLAY_BUTTON_EFFECT;

	//do not slide around
	if(m_index < m_total - 1)
		m_index++;
	else
		return;

	CCActionInterval*  actionTo = CCMoveTo::create(0.5f, CCPointMake(- CONF_INT(DESIGN_WIDTH), 0));
	CCFiniteTimeAction* action = CCSequence::create(
		CCEaseOut::create(actionTo, 1),
		CCCallFuncN::create(this, callfuncN_selector(TutorialScene::onChangeLayerComplete)), 
		NULL);
	m_pLayerContent->runAction(action);

	m_pLayerContent = initLayerContent(m_index);
	m_pLayerContent->setPosition(ccp(CONF_INT(DESIGN_WIDTH), 0));

	actionTo = CCMoveTo::create(0.5f, CCPointMake(0, 0));	
	m_pLayerContent->runAction(CCEaseOut::create(actionTo, 1));

	this->addChild(m_pLayerContent, 5);
}

void TutorialScene::onTouchbtnPrev(CCObject* pSender)
{
	PLAY_BUTTON_EFFECT;

	//index
	if(m_index > 0)
		m_index--;
	else
		return;

	CCActionInterval*  actionTo = CCMoveTo::create(0.5f, CCPointMake(CONF_INT(DESIGN_WIDTH), 0));
	CCFiniteTimeAction* action = CCSequence::create( 
		CCEaseOut::create(actionTo, 1),
		CCCallFuncN::create(this, callfuncN_selector(TutorialScene::onChangeLayerComplete)), 
		NULL);
	m_pLayerContent->runAction(action);

	m_pLayerContent = initLayerContent(m_index);
	m_pLayerContent->setPosition(ccp(- CONF_INT(DESIGN_WIDTH),0));

	actionTo = CCMoveTo::create(0.5f, CCPointMake(0, 0));
	m_pLayerContent->runAction(CCEaseOut::create(actionTo, 1));

	this->addChild(m_pLayerContent, 5);
}

void TutorialScene::onTouchbtnHome(CCObject* pSender)
{
	PLAY_BUTTON_EFFECT;

	CCScene *pScene = CCTransitionFade::create(0.5, MenuScene::scene());
	CCDirector::sharedDirector()->replaceScene(pScene);
}

void TutorialScene::keyBackClicked()
{
	onTouchbtnHome(NULL);
}

void TutorialScene::initControll()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	m_pLayerControll = CCLayer::create();
	m_pLayerControll->setPosition(CCPointZero);
	CCMenuItemImage* pMenuItembtnNext = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this, menu_selector(TutorialScene::onTouchbtnNext));
	pMenuItembtnNext->setScaleX(-1);
	pMenuItembtnNext->setPosition(ccp(size.width - (pMenuItembtnNext->getContentSize().width/2),pMenuItembtnNext->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnPrev = CCMenuItemImage::create("btn_arrow.png","btn_arrow_select.png",this, menu_selector(TutorialScene::onTouchbtnPrev));
	pMenuItembtnPrev->setPosition(ccp((pMenuItembtnPrev->getContentSize().width/2),pMenuItembtnPrev->getContentSize().height/2));

	CCMenuItemImage* pMenuItembtnHome = CCMenuItemImage::create("btn_home.png","btn_home.png",this, menu_selector(TutorialScene::onTouchbtnHome));
	pMenuItembtnHome->setPosition(ccp(CONF_INT(DESIGN_WIDTH)>>1,pMenuItembtnHome->getContentSize().height/2));

	CCMenu* pMenucontroll = CCMenu::create(pMenuItembtnNext,pMenuItembtnPrev,pMenuItembtnHome,NULL);
	pMenucontroll->setPosition(CCPointZero);
	m_pLayerControll->addChild(pMenucontroll);

	this->addChild(m_pLayerControll, 10);
}

void TutorialScene::onChangeLayerComplete(CCNode* psender)
{
	CCLayer* layerLevel = (CCLayer*)psender;
	if(layerLevel != NULL)
	{
		layerLevel->removeFromParentAndCleanup(true);
	}
}

CCLayer* TutorialScene::initLayerContent(int pageIndex)
{
	CCLayer* layerLevel= CCLayer::create();
	layerLevel->setPosition(CCPointZero);

	CCSprite* background;

	switch(pageIndex)
	{
	case 0:
		background = CCSprite::create("st1.png");
		break;
	case 1:
		background = CCSprite::create("st2.png");
		break;
	case 2:
		background = CCSprite::create("st3.png");
		break;
	case 3:
		background = CCSprite::create("st4.png");
		break;
	case 4:
		background = CCSprite::create("st5.png");
		break;
	case 5:
		background = CCSprite::create("st6.png");
		break;
	case 6:
		background = CCSprite::create("st7.png");
		break;
	default:
		background = CCSprite::create("st1.png");
	}

	
	background->setPosition(ccp(400, 1280-440));
	layerLevel->addChild(background);

	//
	return layerLevel;
}




