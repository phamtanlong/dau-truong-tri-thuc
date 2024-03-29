﻿#include "TestAndroidFacebookScene.h"
#include "MenuScene.h"
#include "MyMacro.h"
#include "NDKHelper\NDKHelper.h"


TestAndroidFacebookScene::~TestAndroidFacebookScene()
{
	NDKHelper::RemoveSelectorsInGroup("HelloWorldSelectors");
}

CCScene* TestAndroidFacebookScene::scene()
{
    CCScene *scene = CCScene::create();
    TestAndroidFacebookScene *layer = TestAndroidFacebookScene::create();
    scene->addChild(layer);
    return scene;
}

bool TestAndroidFacebookScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	MY_ADD_SPRITE(bg, "menu_background.png", ccp(400, 640));

	CCMenu *menuRequest = CCMenu::create();
	menuRequest->setPosition(CCPointZero);
	addChild(menuRequest);


	// log in
	CCLabelTTF *labelPost1 = CCLabelTTF::create("Log In", "Arial", 48);
	labelPost1->setFontFillColor(ccc3(0,0,0));
	labelPost1->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost1 = CCMenuItemLabel::create(labelPost1, this, menu_selector(TestAndroidFacebookScene::LogIn));
	itemPost1->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost1->setPosition(ccp(20, 1220));
	menuRequest->addChild(itemPost1);
	

	// get Profile
	CCLabelTTF *labelPost2 = CCLabelTTF::create("Get Profile", "Arial", 48);
	labelPost2->setFontFillColor(ccc3(0,0,0));
	labelPost2->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost2 = CCMenuItemLabel::create(labelPost2, this, menu_selector(TestAndroidFacebookScene::GetProfile));
	itemPost2->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost2->setPosition(ccp(20, 1160));
	menuRequest->addChild(itemPost2);

	//Log Out
	CCLabelTTF *labelPost3 = CCLabelTTF::create("Log Out", "Arial", 48);
	labelPost3->setFontFillColor(ccc3(0,0,0));
	labelPost3->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost3 = CCMenuItemLabel::create(labelPost3, this, menu_selector(TestAndroidFacebookScene::LogOut));
	itemPost3->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost3->setPosition(ccp(20, 1100));
	menuRequest->addChild(itemPost3);

	//Publish Feed
	CCLabelTTF *labelPost4 = CCLabelTTF::create("Publish Feed", "Arial", 48);
	labelPost4->setFontFillColor(ccc3(0,0,0));
	labelPost4->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost4 = CCMenuItemLabel::create(labelPost4, this, menu_selector(TestAndroidFacebookScene::PublishFeed));
	itemPost4->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost4->setPosition(ccp(20, 1040));
	menuRequest->addChild(itemPost4);

	//Post score
	CCLabelTTF *labelPost5 = CCLabelTTF::create("Post Score", "Arial", 48);
	labelPost5->setFontFillColor(ccc3(0,0,0));
	labelPost5->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost5 = CCMenuItemLabel::create(labelPost5, this, menu_selector(TestAndroidFacebookScene::PostScore));
	itemPost5->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost5->setPosition(ccp(20, 980));
	menuRequest->addChild(itemPost5);

	//Get Scores
	CCLabelTTF *labelPost6 = CCLabelTTF::create("Get Scores", "Arial", 48);
	labelPost6->setFontFillColor(ccc3(0,0,0));
	labelPost6->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost6 = CCMenuItemLabel::create(labelPost6, this, menu_selector(TestAndroidFacebookScene::GetScores));
	itemPost6->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost6->setPosition(ccp(20, 920));
	menuRequest->addChild(itemPost6);

	//Invite
	CCLabelTTF *labelPost7 = CCLabelTTF::create("Invite All", "Arial", 48);
	labelPost7->setFontFillColor(ccc3(0,0,0));
	labelPost7->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost7 = CCMenuItemLabel::create(labelPost7, this, menu_selector(TestAndroidFacebookScene::InviteAll));
	itemPost7->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost7->setPosition(ccp(20, 860));
	menuRequest->addChild(itemPost7);

	//Get Avatar
	CCLabelTTF *labelPost8 = CCLabelTTF::create("Get Avatar", "Arial", 48);
	labelPost8->setFontFillColor(ccc3(0,0,0));
	labelPost8->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost8 = CCMenuItemLabel::create(labelPost8, this, menu_selector(TestAndroidFacebookScene::GetAvatar));
	itemPost8->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost8->setPosition(ccp(20, 800));
	menuRequest->addChild(itemPost8);

	//Delete Saved Avatar
	CCLabelTTF *labelPost9 = CCLabelTTF::create("Delete Saved Avatar", "Arial", 48);
	labelPost9->setFontFillColor(ccc3(0,0,0));
	labelPost9->setColor(ccc3(0,0,0));
	CCMenuItemLabel *itemPost9 = CCMenuItemLabel::create(labelPost9, this, menu_selector(TestAndroidFacebookScene::DeleteSavedAvatar));
	itemPost9->setAnchorPoint(ccp(0.0f, 0.5f));
	itemPost9->setPosition(ccp(20, 740));
	menuRequest->addChild(itemPost9);



	this->setKeypadEnabled(true);
    return true;
}

void TestAndroidFacebookScene::keyBackClicked()
{
	CCScene *pScene = CCTransitionFade::create(0.5, MenuScene::scene());
	CCDirector::sharedDirector()->replaceScene(pScene);
}


//////////////////////////////////////////////////////////////////////////
//Menu

void TestAndroidFacebookScene::LogIn( CCObject* pSender )
{
	NDKHelper::CallJNIFunction(string("LogIn"), NULL, "onLogInCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onLogInCompleted), this);
}

void TestAndroidFacebookScene::LogOut( CCObject* pSender )
{
	NDKHelper::CallJNIFunction(string("LogOut"), NULL, "onLogOutCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onLogOutCompleted), this);
}

void TestAndroidFacebookScene::GetProfile( CCObject* pSender )
{
	NDKHelper::CallJNIFunction(string("GetProfile"), NULL, "onGetProfileCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onGetProfileCompleted), this);
}

void TestAndroidFacebookScene::PublishFeed( CCObject* pSender )
{
	string withDialog = "true";
	string message = "This is the message";
	string name = "This is the name";
	string caption = "This is the caption";
	string description = "This is the description";
	string picture = "http://vfossa.vn/tailen/news/2012_01/knowledge.jpg";
	string link = "https://play.google.com/store/apps/details?id=com.supercell.hayday";

	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create(withDialog), "withDialog");
	prms->setObject(CCString::create(message), "message");
	prms->setObject(CCString::create(name), "name");
	prms->setObject(CCString::create(caption), "caption");
	prms->setObject(CCString::create(description), "description");
	prms->setObject(CCString::create(picture), "picture");
	prms->setObject(CCString::create(link), "link");

	NDKHelper::CallJNIFunction(string("PublishFeed"), prms, "onPublishFeedCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onPublishFeedCompleted), this);
}

void TestAndroidFacebookScene::PostScore( CCObject* pSender )
{
	string score = "2020";

	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create(score), "score");

	NDKHelper::CallJNIFunction(string("PostScore"), prms, "onPostScoreCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onPostScoreCompleted), this);
}

void TestAndroidFacebookScene::GetScores( CCObject* pSender )
{
	NDKHelper::CallJNIFunction(string("GetScores"), NULL, "onGetScoresCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onGetScoresCompleted), this);
}

void TestAndroidFacebookScene::InviteAll( CCObject* pSender )
{
	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create("THIS IS THE MESSAGE :v"), "message");

	NDKHelper::CallJNIFunction(string("InviteAll"), prms, "onInviteAllCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onInviteAllCompleted), this);
}

void TestAndroidFacebookScene::GetAvatar( CCObject* pSender )
{
	string fbId = "100002844686620"; // "100006639370902";
	string w = "128";
	string h = "128";

	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create(fbId), "fbId");
	prms->setObject(CCString::create(w), "width");
	prms->setObject(CCString::create(h), "height");
	
	NDKHelper::CallJNIFunction(string("GetAvatar"), prms, "onGetAvatarCompleted", 
		callfuncND_selector(TestAndroidFacebookScene::onGetAvatarCompleted), this);
}

void TestAndroidFacebookScene::DeleteSavedAvatar( CCObject* pSender )
{
	string fbId = "100002844686620"; // "100006639370902";
	string w = "128";
	string h = "128";

	CCDictionary* prms = CCDictionary::create();
	prms->setObject(CCString::create(fbId), "fbId");
	prms->setObject(CCString::create(w), "width");
	prms->setObject(CCString::create(h), "height");

	NDKHelper::CallJNIFunction(string("DeleteSavedAvatar"), prms, "", NULL, NULL);
}




//////////////////////////////////////////////////////////////////////////
//Callback

void TestAndroidFacebookScene::onLogInCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Log In Completed: TRUE");
		} 
		else
		{
			CCLOG("CPP Log In Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onLogInCompleted");
	}
}

void TestAndroidFacebookScene::onLogOutCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Log Out Completed: TRUE");
		} 
		else
		{
			CCLOG("CPP Log Out Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onLogOutCompleted");
	}
}

void TestAndroidFacebookScene::onGetProfileCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Get Profile Completed: TRUE");

			CCString* s;
			s = (CCString*)convertedData->objectForKey("id");			CCLOG("id = %s", s->getCString());
			s = (CCString*)convertedData->objectForKey("firstName");	CCLOG("firstName = %s", s->getCString());
			s = (CCString*)convertedData->objectForKey("name");			CCLOG("name = %s", s->getCString());
			s = (CCString*)convertedData->objectForKey("birthday");		CCLOG("birthday = %s", s->getCString());
			s = (CCString*)convertedData->objectForKey("picture");		CCLOG("picture = %s", s->getCString());
		} 
		else
		{
			CCLOG("CPP Get Profile Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onGetProfileCompleted");
	}
}

void TestAndroidFacebookScene::onPublishFeedCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Publish Feed Completed: TRUE");
			s = (CCString*)convertedData->objectForKey("postId");
			CCLOG("postId: %s", s->getCString());
		} 
		else
		{
			CCLOG("CPP Publish Feed Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onPublishFeedCompleted");
	}
}

void TestAndroidFacebookScene::onPostScoreCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Post Score Completed: TRUE");
		} 
		else
		{
			CCLOG("CPP Post Score Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onPostScoreCompleted");
	}
}

void TestAndroidFacebookScene::onGetScoresCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Get Scores Completed: TRUE");

			CCArray *arrScore = (CCArray *)convertedData->objectForKey("scores");
			for (int i = 0; i < arrScore->count(); ++i)
			{
				CCLOG("------ USER %d -------", i);
				CCDictionary *element = (CCDictionary *)arrScore->objectAtIndex(i);
				{
					CCString* score = (CCString*)element->objectForKey("score");		CCLOG("%s", score->getCString());
				
					CCDictionary *user = (CCDictionary *)element->objectForKey("user");
					{
						CCString* user_id = (CCString*)user->objectForKey("id");		CCLOG("%s", user_id->getCString());
						CCString* user_name = (CCString*)user->objectForKey("name");	CCLOG("%s", user_name->getCString());
					}

					CCDictionary *application = (CCDictionary *)element->objectForKey("application");
					{
						CCString* app_id = (CCString*)application->objectForKey("id");			CCLOG("%s", app_id->getCString());
						CCString* app_namespace = (CCString*)application->objectForKey("namespace");		CCLOG("%s", app_namespace->getCString());
						CCString* app_name = (CCString*)application->objectForKey("name");		CCLOG("%s", app_name->getCString());
					}
				}
			}			
		} 
		else
		{
			CCLOG("CPP Get Scores Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onGetScoresCompleted");
	}
}

void TestAndroidFacebookScene::onInviteAllCompleted( CCNode *sender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Invite All Completed: TRUE");
			CCString* requestId = (CCString*)convertedData->objectForKey("requestId");
			CCLOG("requestId: %s", requestId->getCString());

			CCArray *arrFriends = (CCArray *)convertedData->objectForKey("invitedFriends");
			for (int i = 0; i < arrFriends->count(); ++i)
			{
				CCString* friendId = (CCString*)arrFriends->objectAtIndex(i);

				CCLOG("CPP: %s", friendId->getCString());
			}			
		} 
		else
		{
			CCLOG("CPP Invite All Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onInviteAllCompleted");
	}
}

void TestAndroidFacebookScene::onGetAvatarCompleted( CCNode* pSender, void *data )
{
	if (data != NULL)
	{
		CCDictionary *convertedData = (CCDictionary *)data;
		CCString* s = (CCString*)convertedData->objectForKey("isSuccess");
		if (s->boolValue())
		{
			CCLOG("CPP Get Avatar Completed: TRUE");

			CCString* path = (CCString*)convertedData->objectForKey("path");
			CCSprite* sprAvatar = CCSprite::create(path->getCString());
			sprAvatar->setPosition(ccp(64, 64));
			this->addChild(sprAvatar);
		} 
		else
		{
			CCLOG("CPP Get Avatar Completed: FALSE");
		}

		NDKHelper::RemoveSelector(TEST_GROUP_NAME, "onGetAvatarCompleted");
	}
}
