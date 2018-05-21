#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <tchar.h>
#include "man.h"
#include "display.h"
#include "purchase.h"

extern int Attack;
extern int Defense;
extern int Health;
extern int Level;
extern int Money;
extern int Experience;

void MoneyPurchase(int z)
{
	int condition = 0;
	while(condition == 0)
	{
		if(MouseHit())
		{
			MOUSEMSG m;
			m=GetMouseMsg();
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

			switch(m.uMsg)
			{
			case WM_LBUTTONDOWN:
				if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Money>=25)
				{
					AddAttack(3);
					display(z);
					clearrectangle(156,0,700,544);
					AddMoney(-25);
				}
				if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Money>=25)
				{
					AddDefense(3);
					display(z);
					clearrectangle(156,0,700,544);
					AddMoney(-25);
				}
				if(m.x>=156&&m.x<=700&&m.y>=300&&m.y<=350&&Money>=25)
				{
					AddHealth(1000);
					display(z);
					clearrectangle(156,0,700,544);
					AddMoney(-25);
				}
				if(m.x>=156&&m.x<=700&&m.y>400&&m.y<=500)
				{
					display(z);
					condition = 1;
				}
			}
		}
	}
}

void ExperiencePurchase(int z)
{
	int condition = 0;
	while(condition == 0)
	{
		if(MouseHit())
		{
			MOUSEMSG m;
			m=GetMouseMsg();
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
			switch(m.uMsg)
			{
			case WM_LBUTTONDOWN:
				if(m.x>=156&&m.x<=700&&m.y>=200&&m.y<=250&&Experience>=25)
				{
					AddAttack(5);
					display(z);
					clearrectangle(156,0,700,544);
					AddExperience(-25);
				}
				if(m.x>=156&&m.x<=700&&m.y>=250&&m.y<=300&&Experience>=25)
				{
					AddDefense(5);
					display(z);
					clearrectangle(156,0,700,544);
					AddExperience(-25);
				}
				if(m.x>=156&&m.x<=700&&m.y>=350&&m.y<=400&&Experience>=100)
				{
					AddAttack(8);
					AddDefense(8);
					AddHealth(800);
					display(z);
					clearrectangle(156,0,700,544);
					AddExperience(-100);
				}
				if(m.x>=156&&m.x<=700&&m.y>=400&&m.y<=500)
				{
					display(z);
					condition = 1;
				}
			}
		}
	}
}