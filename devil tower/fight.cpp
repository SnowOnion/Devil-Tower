#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include "string.h"
#include <tchar.h>
#include <math.h>
#include "man.h"
#include "ID.h"
#include <ctime>
extern int Attack;
extern int Defense;
extern int Health;
extern int z;
extern float Agility;
extern float DodgeProbability;

void fight (int ID)
{
	clearrectangle(156,0,700,544);
	int monsterattack = getMonsterAttack(ID);
	int monsterdefense = getMonsterDefense(ID);
	int monsterhealth = getMonsterHealth(ID);
	RECT herorect = {210,200,250,250};
	RECT monsterrect = {560,200,700,250};
	RECT herohealthrect = {210,250,230,250};
	RECT monsterhealthrect = {560,250,580,250};
	RECT heroDodgeRect = {150,350,310,400};
	RECT monsterDodgeRect = {500,350,700,400};

	IMAGE hero,monster;
	loadimage(&hero,_T("pictures\\100.jpg"),64,64);
	if (ID==300)
	{
		loadimage(&monster,_T("pictures\\300.jpg"),64,64);
		drawtext(_T("Green Slime"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==301)
	{
		loadimage(&monster,_T("pictures\\301.jpg"),64,64);
		drawtext(_T("Red Slime"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==302)
	{
		loadimage(&monster,_T("pictures\\302.jpg"),64,64);
		drawtext(_T("Black Slime"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==303)
	{
		loadimage(&monster,_T("pictures\\303.jpg"),64,64);
		drawtext(_T("Slime King"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==310)
	{
		loadimage(&monster,_T("pictures\\310.jpg"),64,64);
		drawtext(_T("Small Bat"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==311)
	{
		loadimage(&monster,_T("pictures\\311.jpg"),64,64);
		drawtext(_T("Big Bat"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==312)
	{
		loadimage(&monster,_T("pictures\\312.jpg"),64,64);
		drawtext(_T("Red Bat"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==320)
	{
		loadimage(&monster,_T("pictures\\320.jpg"),64,64);
		drawtext(_T("Skeleton"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==321)
	{
		loadimage(&monster,_T("pictures\\321.jpg"),64,64);
		drawtext(_T("Armed Skeleton"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==322)
	{
		loadimage(&monster,_T("pictures\\322.jpg"),64,64);
		drawtext(_T("Captain Skeleton"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==330)
	{
		loadimage(&monster,_T("pictures\\330.jpg"),64,64);
		drawtext(_T("Blue Witch"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==331)
	{
		loadimage(&monster,_T("pictures\\331.jpg"),64,64);
		drawtext(_T("Yellow Witch"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==332)
	{
		loadimage(&monster,_T("pictures\\332.jpg"),64,64);
		drawtext(_T("Red Witch"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==340)
	{
		loadimage(&monster,_T("pictures\\340.jpg"),64,64);
		drawtext(_T("Yellow Guard"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==341)
	{
		loadimage(&monster,_T("pictures\\341.jpg"),64,64);
		drawtext(_T("Blue Guard"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==342)
	{
		loadimage(&monster,_T("pictures\\342.jpg"),64,64);
		drawtext(_T("Red Guard"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==350)
	{
		loadimage(&monster,_T("pictures\\350.jpg"),64,64);
		drawtext(_T("Orcish"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==351)
	{
		loadimage(&monster,_T("pictures\\351.jpg"),64,64);
		drawtext(_T("Armed Orcish"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==360)
	{
		loadimage(&monster,_T("pictures\\360.jpg"),64,64);
		drawtext(_T("Yellow Knight"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==361)
	{
		loadimage(&monster,_T("pictures\\361.jpg"),64,64);
		drawtext(_T("Red Knight"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==362)
	{
		loadimage(&monster,_T("pictures\\362.jpg"),64,64);
		drawtext(_T("Double Swords Knight"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==370)
	{
		loadimage(&monster,_T("pictures\\370.jpg"),64,64);
		drawtext(_T("Enchanter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==371)
	{
		loadimage(&monster,_T("pictures\\371.jpg"),64,64);
		drawtext(_T("Black Enchanter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==380)
	{
		loadimage(&monster,_T("pictures\\380.jpg"),64,64);
		drawtext(_T("Yellow Stone Fighter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==381)
	{
		loadimage(&monster,_T("pictures\\381.jpg"),64,64);
		drawtext(_T("Black Stone Fighter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==390)
	{
		loadimage(&monster,_T("pictures\\390.jpg"),64,64);
		drawtext(_T("Green Shadow"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==391)
	{
		loadimage(&monster,_T("pictures\\391.jpg"),64,64);
		drawtext(_T("Gray Shadow"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==392)
	{
		loadimage(&monster,_T("pictures\\392.jpg"),64,64);
		drawtext(_T("Green Shadow Fighter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==393)
	{
		loadimage(&monster,_T("pictures\\393.jpg"),64,64);
		drawtext(_T("Gray Shadow Fighter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}

	else if (ID==400)
	{
		loadimage(&monster,_T("pictures\\400.jpg"),64,64);
		drawtext(_T("Holy Warrior"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==401)
	{
		loadimage(&monster,_T("pictures\\401.jpg"),64,64);
		drawtext(_T("Yellow Holy Warrior"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==402)
	{
		loadimage(&monster,_T("pictures\\402.jpg"),64,64);
		drawtext(_T("Holy Swordsman"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==403)
	{
		loadimage(&monster,_T("pictures\\403.jpg"),64,64);
		drawtext(_T("Yellow Holy Swordsman"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==410)
	{
		loadimage(&monster,_T("pictures\\410.jpg"),64,64);
		drawtext(_T("Dragon Warrior"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==411)
	{
		loadimage(&monster,_T("pictures\\411.jpg"),64,64);
		drawtext(_T("Dragon Enchanter"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==412)
	{
		loadimage(&monster,_T("pictures\\412.jpg"),64,64);
		drawtext(_T("Dragon King"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==108)
	{
		loadimage(&monster,_T("pictures\\108.jpg"),64,64);
		drawtext(_T("YYJ"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	else if (ID==109)
	{
		loadimage(&monster,_T("pictures\\109.jpg"),64,64);
		drawtext(_T("LZH"),&monsterrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}

	putimage(200, 150, &hero);
	putimage(600, 150, &monster);

	settextcolor(WHITE);
	drawtext(_T("Hero"),&herorect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	TCHAR hp[]=_T("health");
	outtextxy(170,250,hp);
	outtextxy(570,250,hp);

	settextcolor(RED);
	TCHAR atk[]=_T("attack");
	outtextxy(170,280,atk);
	TCHAR strattack[10];
	_stprintf(strattack,TEXT("%d"),Attack);
	outtextxy(250,280,strattack);
	outtextxy(570,280,atk);
	TCHAR strmonsterattack[10];
	_stprintf(strmonsterattack,TEXT("%d"),monsterattack);
	outtextxy(650,280,strmonsterattack);

	settextcolor(BLUE);

	TCHAR dfs[]=_T("defense");
	outtextxy(170,310,dfs);
	TCHAR strdefense[10];
	_stprintf(strdefense,TEXT("%d"),Defense);
	outtextxy(250,310,strdefense);

	outtextxy(570,310,dfs);
	TCHAR strmonsterdefense[10];
	_stprintf(strmonsterdefense,TEXT("%d"),monsterdefense);
	outtextxy(650,310,strmonsterdefense);

	settextcolor(WHITE);
	DodgeProbability = 4 * sqrt(Agility);
	float monsterDodgeProbability = 0.0;
	if (ID<=393&&ID>=390)
		monsterDodgeProbability = 25.0;
	bool Dodge = false;
	int i = 0;
	double random = 0;
	while (monsterhealth > 0&& Health > 0)
	{
		Sleep(50);
		if (i%2==0)
		{
			clearrectangle(650,240,700,270);
			TCHAR strmonsterhealth[10];
			_stprintf(strmonsterhealth,TEXT("%d"),monsterhealth);
			outtextxy(650,250,strmonsterhealth);
			i++;
			random = rand()/(double)RAND_MAX;
			if (random <= monsterDodgeProbability/100.0 && random >= 0)
				Dodge = true;
			if (Attack - monsterdefense >= 0 && !Dodge)
				monsterhealth = monsterhealth - (Attack - monsterdefense);
			if (Dodge)
			{
				drawtext(_T("Monster Dodged Attack!"),&monsterDodgeRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				Sleep(200);
				clearrectangle(500,350,700,400);
				Dodge = false;
			}
		}
		else 
		{
			clearrectangle(250,240,300,270);
			TCHAR strhealth[10];
			_stprintf(strhealth,TEXT("%d"),Health);
			outtextxy(250,250,strhealth);
			i++;
			random = rand()/(double)RAND_MAX;
			if (random <= DodgeProbability/100.0 && random >= 0)
				Dodge = true;
			if (monsterattack - Defense >= 0 && !Dodge)
				Health = Health - (monsterattack - Defense);
			if (Dodge)
			{
				drawtext(_T("Hero Dodged Attack!"),&heroDodgeRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				Sleep(200);
				clearrectangle(150,350,310,400);
				Dodge = false;
			}
		}
		if (monsterhealth <= 0)
		{
			monsterhealth = 0;
			TCHAR strmonsterhealth[10];
			_stprintf(strmonsterhealth,TEXT("%d"),monsterhealth);
			outtextxy(650,250,strmonsterhealth);
			Sleep(50);
			int moneyincrement = getMoney(ID);
			int experiecneincrement = getExperience(ID);
			AddMoney(moneyincrement);
			AddExperience(experiecneincrement);
			if (ID == 108)
			{
				TCHAR str[]=_T("NO!!!!!");
				outtextxy(10,400,str);
				Sleep(1000);
				clearrectangle(0,400,156,425);
				TCHAR str1[]=_T("她只是纸片人啊");
				outtextxy(10,400,str1);
				Sleep(1000);
				SetMap(3,15,13,1);
				display(z);
			}
			if (ID == 109)
			{
				TCHAR str[]=_T("哈哈哈，你以为我死了");
				outtextxy(10,400,str);
				Sleep(1000);
				clearrectangle(0,400,200,425);
				TCHAR str1[]=_T("太天真了");
				outtextxy(10,400,str1);
				Sleep(1000);
				clearrectangle(0,400,200,425);
				TCHAR str2[]=_T("被你说对了");
				outtextxy(10,400,str2);
				Sleep(1000);
				SetMap(3,14,13,1);
				display(z);
			}
			
		}
		if (Health <= 0)
		{
			Health = 0;
			Sleep(500);
			clearrectangle(0,0,700,544);
			RECT dieRect = {0,0,700,544};
			drawtext(_T("You Died!"),&dieRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			Sleep(100000);
		}
	}
}