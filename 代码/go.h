//代码迁移自五子棋项目
#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>

#pragma comment (lib,"winmm.lib")

int Go();
void Exit();
void initGo();//初始化
void playGo();//运行游戏
void death();//检查棋子的死活
