#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <tchar.h>
#include "man.h"
#include "display.h"
#include "purchase.h"

extern int Attack;
extern int Defense;
extern long Health;
extern int Level;
extern int Money;
extern int Experience;
extern int YellowKey;
extern int BlueKey;
extern int RedKey;
extern bool HasTransfer;
extern bool HasDictionary;

void MoneyPurchase(int z)
{
	if (z == 3)
	{
		int condition = 0;
		clearrectangle(156,0,700,544);
		TCHAR str[] = _T("Use 25 coins to purchase:");
		outtextxy(320,100,str);
		RECT attack = {156,200,700,250};
		drawtext(_T("add 3 atk points"),&attack,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT defense = {156,250,700,300};
		drawtext(_T("add 3 dfs points"),&defense,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT health = {156,300,700,350};
		drawtext(_T("add 500 health points"),&health,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT exit = {156,400,700,500};
		drawtext(_T("Exit"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		while(condition == 0)
		{
			if(MouseHit())
			{
				MOUSEMSG m;
				m=GetMouseMsg();
				switch(m.uMsg)
				{
				case WM_LBUTTONDOWN:
					if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Money>=25)
					{
						AddAttack(3);
						AddMoney(-25);
					}
					if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Money>=25)
					{
						AddDefense(3);
						AddMoney(-25);
					}
					if(m.x>=156&&m.x<=700&&m.y>=300&&m.y<=350&&Money>=25)
					{
						AddHealth(500);
						AddMoney(-25);
					}
					if(m.x>=156&&m.x<=700&&m.y>400&&m.y<=500)
					{
						display(z);
						condition = 1;
					}
					clearrectangle(0,0,156,544);                               //display UI in the left part 
					TCHAR name[] = _T("hero");
					outtextxy(50,20,name);

					TCHAR strfloor[] = _T("floor");
					outtextxy(10,50,strfloor);
					TCHAR floor[10];
					_stprintf(floor,TEXT("%d"),z);
					outtextxy(90,50,floor);

					TCHAR strattack[] = _T("attack");
					outtextxy(10,70,strattack);
					TCHAR attack[10];
					_stprintf(attack,TEXT("%d"),Attack);
					outtextxy(90,70,attack);

					TCHAR strdefense[] = _T("defense");
					outtextxy(10,90,strdefense);
					TCHAR defense[10];
					_stprintf(defense,TEXT("%d"),Defense);
					outtextxy(90,90,defense);

					TCHAR strhealth[] = _T("health");
					outtextxy(10,110,strhealth);
					TCHAR health[10];
					_stprintf(health,TEXT("%d"),Health);
					outtextxy(90,110,health);

					TCHAR strlevel[] = _T("level");
					outtextxy(10,130,strlevel);
					TCHAR level[10];
					_stprintf(level,TEXT("%d"),Level);
					outtextxy(90,130,level);

					TCHAR strmoney[] = _T("money");
					outtextxy(10,150,strmoney);
					TCHAR money[10];
					_stprintf(money,TEXT("%d"),Money);
					outtextxy(90,150,money);

					TCHAR strexperience[] = _T("experience");
					outtextxy(10,170,strexperience);
					TCHAR experience[10];
					_stprintf(experience,TEXT("%d"),Experience);
					outtextxy(90,170,experience);

					IMAGE imgYellowKey;
					loadimage(&imgYellowKey,_T("pictures\\212.jpg"),32,32);
					putimage(10,190,&imgYellowKey);
					IMAGE imgBlueKey;
					loadimage(&imgBlueKey,_T("pictures\\213.jpg"),32,32);
					putimage(10,230,&imgBlueKey);
					IMAGE imgRedKey;
					loadimage(&imgRedKey,_T("pictures\\214.jpg"),32,32);
					putimage(10,270,&imgRedKey);
					TCHAR yellowkey[10];
					_stprintf(yellowkey,TEXT("%d"),YellowKey);
					outtextxy(90,200,yellowkey);
					TCHAR bluekey[10];
					_stprintf(bluekey,TEXT("%d"),BlueKey);
					outtextxy(90,240,bluekey);
					TCHAR redkey[10];
					_stprintf(redkey,TEXT("%d"),RedKey);
					outtextxy(90,280,redkey);

					if (HasDictionary)
					{
						IMAGE imgDictionary;
						loadimage(&imgDictionary,_T("pictures\\210.jpg"),32,32);
						putimage(62,310,&imgDictionary);
					}

					if (HasTransfer)
					{
						IMAGE imgTransfer;
						loadimage(&imgTransfer,_T("pictures\\209.jpg"),32,32);
						putimage(62,350,&imgTransfer);
					}
				}
			}
		}
	}

	else if (z == 8)
	{
		int condition = 0;
		clearrectangle(156,0,700,544);
		TCHAR str[] = _T("Use 120 coins to purchase:");
		outtextxy(320,100,str);
		RECT attack = {156,200,700,250};
		drawtext(_T("add 20 atk points"),&attack,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT defense = {156,250,700,300};
		drawtext(_T("add 20 dfs points"),&defense,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT health = {156,300,700,350};
		drawtext(_T("add 4000 health points"),&health,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT exit = {156,400,700,500};
		drawtext(_T("Exit"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		while(condition == 0)
		{
			if(MouseHit())
			{
				MOUSEMSG m;
				m=GetMouseMsg();
				switch(m.uMsg)
				{
				case WM_LBUTTONDOWN:
					if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Money>=120)
					{
						AddAttack(20);
						AddMoney(-120);
					}
					if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Money>=120)
					{
						AddDefense(20);
						AddMoney(-120);
					}
					if(m.x>=156&&m.x<=700&&m.y>=300&&m.y<=350&&Money>=120)
					{
						AddHealth(4000);
						AddMoney(-120);
					}
					if(m.x>=156&&m.x<=700&&m.y>400&&m.y<=500)
					{
						display(z);
						condition = 1;
					}
					clearrectangle(0,0,156,544);                               //display UI in the left part 
					TCHAR name[] = _T("hero");
					outtextxy(50,20,name);

					TCHAR strfloor[] = _T("floor");
					outtextxy(10,50,strfloor);
					TCHAR floor[10];
					_stprintf(floor,TEXT("%d"),z);
					outtextxy(90,50,floor);

					TCHAR strattack[] = _T("attack");
					outtextxy(10,70,strattack);
					TCHAR attack[10];
					_stprintf(attack,TEXT("%d"),Attack);
					outtextxy(90,70,attack);

					TCHAR strdefense[] = _T("defense");
					outtextxy(10,90,strdefense);
					TCHAR defense[10];
					_stprintf(defense,TEXT("%d"),Defense);
					outtextxy(90,90,defense);

					TCHAR strhealth[] = _T("health");
					outtextxy(10,110,strhealth);
					TCHAR health[10];
					_stprintf(health,TEXT("%d"),Health);
					outtextxy(90,110,health);

					TCHAR strlevel[] = _T("level");
					outtextxy(10,130,strlevel);
					TCHAR level[10];
					_stprintf(level,TEXT("%d"),Level);
					outtextxy(90,130,level);

					TCHAR strmoney[] = _T("money");
					outtextxy(10,150,strmoney);
					TCHAR money[10];
					_stprintf(money,TEXT("%d"),Money);
					outtextxy(90,150,money);

					TCHAR strexperience[] = _T("experience");
					outtextxy(10,170,strexperience);
					TCHAR experience[10];
					_stprintf(experience,TEXT("%d"),Experience);
					outtextxy(90,170,experience);

					IMAGE imgYellowKey;
					loadimage(&imgYellowKey,_T("pictures\\212.jpg"),32,32);
					putimage(10,190,&imgYellowKey);
					IMAGE imgBlueKey;
					loadimage(&imgBlueKey,_T("pictures\\213.jpg"),32,32);
					putimage(10,230,&imgBlueKey);
					IMAGE imgRedKey;
					loadimage(&imgRedKey,_T("pictures\\214.jpg"),32,32);
					putimage(10,270,&imgRedKey);
					TCHAR yellowkey[10];
					_stprintf(yellowkey,TEXT("%d"),YellowKey);
					outtextxy(90,200,yellowkey);
					TCHAR bluekey[10];
					_stprintf(bluekey,TEXT("%d"),BlueKey);
					outtextxy(90,240,bluekey);
					TCHAR redkey[10];
					_stprintf(redkey,TEXT("%d"),RedKey);
					outtextxy(90,280,redkey);

					if (HasDictionary)
					{
						IMAGE imgDictionary;
						loadimage(&imgDictionary,_T("pictures\\210.jpg"),32,32);
						putimage(62,310,&imgDictionary);
					}

					if (HasTransfer)
					{
						IMAGE imgTransfer;
						loadimage(&imgTransfer,_T("pictures\\209.jpg"),32,32);
						putimage(62,350,&imgTransfer);
					}
					TCHAR save[] = _T("Save Game:    X");
					outtextxy(10,400,save);
					TCHAR load[] = _T("Load Game:    L");
					outtextxy(10,430,load);
				}
			}
		}
	}
}

void ExperiencePurchase(int z)
{
	if (z == 2)
	{
		int condition = 0;
		clearrectangle(156,0,700,544);
		TCHAR str1[] = _T("Use 25 experience points to purchase:");
		outtextxy(320,100,str1);
		RECT attack = {156,200,700,250};
		drawtext(_T("add 5 atk points"),&attack,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT defense = {156,250,700,300};
		drawtext(_T("add 5 dfs points"),&defense,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT levelup = {156,350,700,400};
		TCHAR str2[] = _T("Or use 100 experience points to purchase:");
		outtextxy(320,325,str2);
		drawtext(_T("Level Up"),&levelup,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT health = {156,400,700,500};
		drawtext(_T("Exit"),&health,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		while(condition == 0)
		{
			if(MouseHit())
			{
				MOUSEMSG m;
				m=GetMouseMsg();
				switch(m.uMsg)
				{
				case WM_LBUTTONDOWN:
					if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Experience>=25)
					{
						AddAttack(5);
						AddExperience(-25);
					}
					if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Experience>=25)
					{
						AddDefense(5);
						AddExperience(-25);
					}
					if(m.x>=156&&m.x<=700&&m.y>=350&&m.y<=400&&Experience>=100)
					{
						AddAttack(8);
						AddDefense(8);
						AddHealth(800);
						Level += 1;
						AddExperience(-100);
					}
					if(m.x>=156&&m.x<=700&&m.y>=400&&m.y<=500)
					{
						display(z);
						condition = 1;
					}
					clearrectangle(0,0,156,544);                               //display UI in the left part 
					TCHAR name[] = _T("hero");
					outtextxy(50,20,name);

					TCHAR strfloor[] = _T("floor");
					outtextxy(10,50,strfloor);
					TCHAR floor[10];
					_stprintf(floor,TEXT("%d"),z);
					outtextxy(90,50,floor);

					TCHAR strattack[] = _T("attack");
					outtextxy(10,70,strattack);
					TCHAR attack[10];
					_stprintf(attack,TEXT("%d"),Attack);
					outtextxy(90,70,attack);

					TCHAR strdefense[] = _T("defense");
					outtextxy(10,90,strdefense);
					TCHAR defense[10];
					_stprintf(defense,TEXT("%d"),Defense);
					outtextxy(90,90,defense);

					TCHAR strhealth[] = _T("health");
					outtextxy(10,110,strhealth);
					TCHAR health[10];
					_stprintf(health,TEXT("%d"),Health);
					outtextxy(90,110,health);

					TCHAR strlevel[] = _T("level");
					outtextxy(10,130,strlevel);
					TCHAR level[10];
					_stprintf(level,TEXT("%d"),Level);
					outtextxy(90,130,level);

					TCHAR strmoney[] = _T("money");
					outtextxy(10,150,strmoney);
					TCHAR money[10];
					_stprintf(money,TEXT("%d"),Money);
					outtextxy(90,150,money);

					TCHAR strexperience[] = _T("experience");
					outtextxy(10,170,strexperience);
					TCHAR experience[10];
					_stprintf(experience,TEXT("%d"),Experience);
					outtextxy(90,170,experience);

					IMAGE imgYellowKey;
					loadimage(&imgYellowKey,_T("pictures\\212.jpg"),32,32);
					putimage(10,190,&imgYellowKey);
					IMAGE imgBlueKey;
					loadimage(&imgBlueKey,_T("pictures\\213.jpg"),32,32);
					putimage(10,230,&imgBlueKey);
					IMAGE imgRedKey;
					loadimage(&imgRedKey,_T("pictures\\214.jpg"),32,32);
					putimage(10,270,&imgRedKey);
					TCHAR yellowkey[10];
					_stprintf(yellowkey,TEXT("%d"),YellowKey);
					outtextxy(90,200,yellowkey);
					TCHAR bluekey[10];
					_stprintf(bluekey,TEXT("%d"),BlueKey);
					outtextxy(90,240,bluekey);
					TCHAR redkey[10];
					_stprintf(redkey,TEXT("%d"),RedKey);
					outtextxy(90,280,redkey);

					if (HasDictionary)
					{
						IMAGE imgDictionary;
						loadimage(&imgDictionary,_T("pictures\\210.jpg"),32,32);
						putimage(62,310,&imgDictionary);
					}

					if (HasTransfer)
					{
						IMAGE imgTransfer;
						loadimage(&imgTransfer,_T("pictures\\209.jpg"),32,32);
						putimage(62,350,&imgTransfer);
					}
					TCHAR save[] = _T("Save Game:    X");
					outtextxy(10,400,save);
					TCHAR load[] = _T("Load Game:    L");
					outtextxy(10,430,load);
				}
			}
		}
	}

	else if (z == 8)
	{
		int condition = 0;
		clearrectangle(156,0,700,544);
		TCHAR str1[] = _T("Use 150 experience points to purchase:");
		outtextxy(320,100,str1);
		RECT attack = {156,200,700,250};
		drawtext(_T("add 35 atk points"),&attack,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT defense = {156,250,700,300};
		drawtext(_T("add 35 dfs points"),&defense,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT levelup = {156,350,700,400};
		TCHAR str2[] = _T("Or use 270 experience points to purchase:");
		outtextxy(320,325,str2);
		drawtext(_T("Level Up 3 Times"),&levelup,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		RECT health = {156,400,700,500};
		drawtext(_T("Exit"),&health,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		while(condition == 0)
		{
			if(MouseHit())
			{
				MOUSEMSG m;
				m=GetMouseMsg();
				switch(m.uMsg)
				{
				case WM_LBUTTONDOWN:
					if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Experience>=150)
					{
						AddAttack(35);
						AddExperience(-150);
					}
					if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Experience>=150)
					{
						AddDefense(35);
						AddExperience(-150);
					}
					if(m.x>=156&&m.x<=700&&m.y>=350&&m.y<=400&&Experience>=270)
					{
						AddAttack(25);
						AddDefense(25);
						AddHealth(2400);
						Level += 3;
						AddExperience(-270);
					}
					if(m.x>=156&&m.x<=700&&m.y>=400&&m.y<=500)
					{
						display(z);
						condition = 1;
					}
					clearrectangle(0,0,156,544);                               //display UI in the left part 
					TCHAR name[] = _T("hero");
					outtextxy(50,20,name);

					TCHAR strfloor[] = _T("floor");
					outtextxy(10,50,strfloor);
					TCHAR floor[10];
					_stprintf(floor,TEXT("%d"),z);
					outtextxy(90,50,floor);

					TCHAR strattack[] = _T("attack");
					outtextxy(10,70,strattack);
					TCHAR attack[10];
					_stprintf(attack,TEXT("%d"),Attack);
					outtextxy(90,70,attack);

					TCHAR strdefense[] = _T("defense");
					outtextxy(10,90,strdefense);
					TCHAR defense[10];
					_stprintf(defense,TEXT("%d"),Defense);
					outtextxy(90,90,defense);

					TCHAR strhealth[] = _T("health");
					outtextxy(10,110,strhealth);
					TCHAR health[10];
					_stprintf(health,TEXT("%d"),Health);
					outtextxy(90,110,health);

					TCHAR strlevel[] = _T("level");
					outtextxy(10,130,strlevel);
					TCHAR level[10];
					_stprintf(level,TEXT("%d"),Level);
					outtextxy(90,130,level);

					TCHAR strmoney[] = _T("money");
					outtextxy(10,150,strmoney);
					TCHAR money[10];
					_stprintf(money,TEXT("%d"),Money);
					outtextxy(90,150,money);

					TCHAR strexperience[] = _T("experience");
					outtextxy(10,170,strexperience);
					TCHAR experience[10];
					_stprintf(experience,TEXT("%d"),Experience);
					outtextxy(90,170,experience);

					IMAGE imgYellowKey;
					loadimage(&imgYellowKey,_T("pictures\\212.jpg"),32,32);
					putimage(10,190,&imgYellowKey);
					IMAGE imgBlueKey;
					loadimage(&imgBlueKey,_T("pictures\\213.jpg"),32,32);
					putimage(10,230,&imgBlueKey);
					IMAGE imgRedKey;
					loadimage(&imgRedKey,_T("pictures\\214.jpg"),32,32);
					putimage(10,270,&imgRedKey);
					TCHAR yellowkey[10];
					_stprintf(yellowkey,TEXT("%d"),YellowKey);
					outtextxy(90,200,yellowkey);
					TCHAR bluekey[10];
					_stprintf(bluekey,TEXT("%d"),BlueKey);
					outtextxy(90,240,bluekey);
					TCHAR redkey[10];
					_stprintf(redkey,TEXT("%d"),RedKey);
					outtextxy(90,280,redkey);

					if (HasDictionary)
					{
						IMAGE imgDictionary;
						loadimage(&imgDictionary,_T("pictures\\210.jpg"),32,32);
						putimage(62,310,&imgDictionary);
					}

					if (HasTransfer)
					{
						IMAGE imgTransfer;
						loadimage(&imgTransfer,_T("pictures\\209.jpg"),32,32);
						putimage(62,350,&imgTransfer);
					}
					TCHAR save[] = _T("Save Game:    X");
					outtextxy(10,400,save);
					TCHAR load[] = _T("Load Game:    L");
					outtextxy(10,430,load);
				}
			}
		}
	}
}