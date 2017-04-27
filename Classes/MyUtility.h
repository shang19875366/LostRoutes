#ifndef MY_UTILITY_H
#define MY_UTILITY_H
#include "cocos2d.h"
using namespace std;

class MyUtility
{
public:
	static string getCurrentTime();
	static string gbk_2_utf8(const string text);
	static string getUTF8Char(const string key);
};

#endif // !MY_UTILITY_H

