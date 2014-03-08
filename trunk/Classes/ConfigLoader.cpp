#include "ConfigLoader.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

ConfigLoader* ConfigLoader::s_instance = NULL;


ConfigLoader::ConfigLoader(void)
{
	CCLOG("-----------CONFIG BEGIN------------");

	//JSON
	string s = string(CCString::createWithContentsOfFile(CONFIG_FILE)->getCString());
	CCLOG("%s", s.c_str());
	json_error_t error;

	m_configObject = json_loads(s.c_str(), strlen(s.c_str()), &error);

	CCLOG("-----------CONFIG END------------");
}

ConfigLoader::~ConfigLoader(void)
{
}

ConfigLoader* ConfigLoader::shareConfigLoader()
{
	if (s_instance == NULL)
	{
		s_instance = new ConfigLoader();
	}
	
	return s_instance;
}

const char* ConfigLoader::getStringValue(const char* key)
{
	json_t* jsonValue = json_object_get(m_configObject, key);
	return json_string_value(jsonValue);
}

int ConfigLoader::getIntValue( const char* key )
{
	json_t* jsonValue = json_object_get(m_configObject, key);
	return (int)json_number_value(jsonValue);
}

float ConfigLoader::getFloatValue( const char* key )
{
	json_t* jsonValue = json_object_get(m_configObject, key);
	return (float)json_number_value(jsonValue);
}
