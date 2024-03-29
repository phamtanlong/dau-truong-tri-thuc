#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;


#define TEST_GROUP_NAME		"HelloWorldSelectors"


class TestAndroidFacebookScene : public cocos2d::CCLayer
{    
public:
    ~TestAndroidFacebookScene();
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(TestAndroidFacebookScene);
	
	virtual void keyBackClicked();

	//menu
	void LogIn(CCObject* pSender);
	void LogOut(CCObject* pSender);
	void GetProfile(CCObject* pSender);
	void PublishFeed(CCObject* pSender);
	void PostScore(CCObject* pSender);
	void GetScores(CCObject* pSender);
	void InviteAll(CCObject* pSender);
	void GetAvatar(CCObject* pSender);
	void DeleteSavedAvatar(CCObject* pSender);

	//callback
	void onLogInCompleted(CCNode *sender, void *data);
	void onLogOutCompleted(CCNode *sender, void *data);
	void onGetProfileCompleted(CCNode *sender, void *data);
	void onPublishFeedCompleted(CCNode *sender, void *data);
	void onPostScoreCompleted(CCNode *sender, void *data);
	void onGetScoresCompleted(CCNode *sender, void *data);
	void onInviteAllCompleted(CCNode *sender, void *data);
	void onGetAvatarCompleted(CCNode* pSender, void *data);
};

#endif // __HELLOWORLD_SCENE_H__
