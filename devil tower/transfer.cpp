#include "transfer.h"
#include <conio.h>
#include <graphics.h>
#include "man.h"
#include <tchar.h>
#include "display.h"

extern int floor;
extern int zmax;
extern int z;
extern int xman,yman;

void openTransfer()
{
	clearrectangle(156,0,700,544);
	int arrow = 0;
	int i = 1;
	TCHAR phrase[] = _T("Go to      floor");
	TCHAR number[10];
	RECT exit = {400,0,500,100};
	drawtext(_T("exit"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	for (i = 1;i <= zmax;i++)
	{
		outtextxy(200 + 200 * arrow,100 * (i - arrow * 5),phrase);
		_stprintf(number,TEXT("%d"),i);
		outtextxy(240 + 200 * arrow,100 * (i - arrow * 5),number);
		if (i % 5 == 0)
			arrow++;
	}

	int condition = 0;
	while (condition == 0)
	{
		if (condition == 0)
		{
			MOUSEMSG m ;
			while (!MouseHit()&&!kbhit())
			{}
			if (MouseHit())
				m = GetMouseMsg();
			if (kbhit())
			{
				char c = getch();
				if (c == 'r' || c == 'R')
				{
					condition = 1;
					display(z);
					break;
				}
			}
			arrow = 0;
			int destination = -1;
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x <= 280 && m.x >= 180 && m.y >= 80 && m.y <= 120 && zmax >= 1)
					destination = 1;
				if (m.x <= 280 && m.x >= 180 && m.y >= 180 && m.y <= 220 && zmax >= 2)
					destination = 2;
				if (m.x <= 280 && m.x >= 180 && m.y >= 280 && m.y <= 320 && zmax >= 3)
					destination = 3;
				if (m.x <= 280 && m.x >= 180 && m.y >= 380 && m.y <= 420 && zmax >= 4)
					destination = 4;
				if (m.x <= 280 && m.x >= 180 && m.y >= 480 && m.y <= 520 && zmax >= 5)
					destination = 5;
				if (m.x <= 480 && m.x >= 380 && m.y >= 80 && m.y <= 120 && zmax >= 6)
					destination = 6;
				if (m.x <= 480 && m.x >= 380 && m.y >= 180 && m.y <= 220 && zmax >= 7)
					destination = 7;
				if (m.x <= 480 && m.x >= 380 && m.y >= 280 && m.y <= 320 && zmax >= 8)
					destination = 8;
				if (m.x <= 480 && m.x >= 380 && m.y >= 380 && m.y <= 420 && zmax >= 9)
					destination = 9;
				if (m.x <= 480 && m.x >= 380 && m.y >= 480 && m.y <= 520 && zmax >= 10)
					destination = 10;
				if (m.x <= 680 && m.x >= 580 && m.y >= 80 && m.y <= 120 && zmax >= 11)
					destination = 11;
				if (m.x <= 680 && m.x >= 580 && m.y >= 180 && m.y <= 220 && zmax >= 12)
					destination = 12;
				if (m.x <= 680 && m.x >= 580 && m.y >= 280 && m.y <= 320 && zmax >= 13)
					destination = 13;
				if (m.x <= 680 && m.x >= 580 && m.y >= 380 && m.y <= 420 && zmax >= 14)
					destination = 14;
				if (m.x <= 680 && m.x >= 580 && m.y >= 480 && m.y <= 520 && zmax >= 15)
					destination = 15;
				if (m.x <= 475 && m.x >= 425 && m.y >= 25 && m.y <= 75)
					condition = 1;
			}
			if (destination >= z)
			{
				condition = 1;
				SetMap(z,xman,yman,1);
				if (destination == 2)
				{
					xman = 8;
					yman = 15;	
				}
				else if (destination == 3)
				{
					xman = 0;
					yman = 1;
				}
				else if (destination == 4)
				{
					xman = 8;
					yman = 7;
				}
				else if (destination == 5)
				{
					xman = 0;
					yman = 1;
				}
				else if (destination == 6)
				{
					xman = 1;
					yman = 16;
				}
				else if (destination == 7)
				{
					xman = 0;
					yman = 15;
				}
				else if (destination == 8)
				{
					xman = 1;
					yman = 0;
				}
				else if (destination == 9)
				{
					xman = 0;
					yman = 15;
				}
				else if (destination == 10)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 11)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 12)
				{
					xman = 15;
					yman = 0;
				}
				else if (destination == 13)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 14)
				{
					xman = 15;
					yman = 7;
				}
				z = destination;
				SetMap(z,xman,yman,100);
			}
			if (destination < z && destination >= 0)
			{
				condition = 1;
				SetMap(z,xman,yman,1);
				if (destination == 1)
				{
					xman = 8;
					yman = 15;
				}
				else if (destination == 2)
				{
					xman = 8;
					yman = 1;
				}
				else if (destination == 3)
				{
					xman = 0;
					yman = 15;
				}
				else if (destination == 4)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 5)
				{
					xman = 0;
					yman = 15;
				}
				else if (destination == 6)
				{
					xman = 9;
					yman = 1;
				}
				else if (destination == 7)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 8)
				{
					xman = 15;
					yman = 13;
				}
				else if (destination == 9)
				{
					xman = 16;
					yman = 1;
				}
				else if (destination == 10)
				{
					xman = 1;
					yman = 0;
				}
				else if (destination == 11)
				{
					xman = 0;
					yman = 1;
				}
				else if (destination == 12)
				{
					xman = 16;
					yman = 15;
				}
				else if (destination == 13)
				{
					xman = 14;
					yman = 15;
				}
				else if (destination == 14)
				{
					xman = 15;
					yman = 7;
				}
				z = destination;
				SetMap(z,xman,yman,100);
			}
			if (condition == 1)
			{
				display(z);
			}
		}
	}
}