#pragma once
#include "common.h"
#include "plan.h"
#include "word.h"
#include "password.h"
#include "go.h"
#include "md2html.h"
#include "timer.h"

class User
{
public:
	char username[30];
	char password[30];
public:
	User();
	bool isUser();
	void mainMenu();
	void welcome();
	void goodbye();
};
