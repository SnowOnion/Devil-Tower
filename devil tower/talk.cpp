#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include "talk.h"

void TalkElder(int z)
{
	TCHAR str[]=_T("欢迎来到魔塔");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkMerchant(int z)
{
	TCHAR str[]=_T("我是奸商");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkPrincess(int z)
{
	TCHAR str[]=_T("我是公主");
	outtextxy(10,400,str);
	Sleep(1000);
}

void TalkBoss(int z)
{
	TCHAR str[]=_T("我是Boss");
	outtextxy(10,400,str);
	Sleep(1000);
}