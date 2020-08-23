//命名：驼峰式
//类名大写字母开头
//函数和成员都是小写字母开头
//bool命名一定是is....
//文件名全小写

#pragma warning(disable:4996)
#include "user.h"

int main()
{
	srand((unsigned int)time(0));
	User user;
	if (user.isUser())
	{
		user.welcome();
		user.goodbye();
	}

	return 0;
}
