#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <tchar.h>
#include "map.h"
#include "display.h"
#include "man.h"
#include "dictionary.h"
#include "transfer.h"

extern int map[25][17][17];
extern int Attack;
extern int Defense;
extern long Health;
extern int Level;
extern int Money;
extern int Experience;
extern int YellowKey;
extern int BlueKey;
extern int RedKey;
extern int xman,yman;
extern bool HasDictionary;
extern bool HasTransfer;

//z应当从1开始，也就是说map的0层不应有东西
void display(int z)
{
	clearrectangle(0,0,156,544);

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
		putimage(10,310,&imgDictionary);
		TCHAR f[] = _T("F");
		outtextxy(90,316,f);
	}

	if (HasTransfer)
	{
		IMAGE imgTransfer;
		loadimage(&imgTransfer,_T("pictures\\209.jpg"),32,32);
		putimage(10,350,&imgTransfer);
		TCHAR r[] = _T("R");
		outtextxy(90,356,r);
	}

	TCHAR save[] = _T("Save Game:    X");
	outtextxy(10,400,save);
	TCHAR load[] = _T("Load Game:    L");
	outtextxy(10,430,load);

	int x,y;
	IMAGE img0,img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,
		img100,img101,img102,img103,img104,img105,img106,
		img200,img201,img202,img203,img204,img205,img206,img207,img208,img209,img210,img211,
		img300,img301,img302,img303,
		img310,img311,img312,
		img320,img321,img322,
		img330,img331,img332,
		img340,img341,img342,
		img350,img351,
		img360,img361,img362,
		img370,img371,
		img380,img381,
		img390,img391,
		img392,img393,
		img400,img401,img402,img403,
		img410,img411,img412,
		img107;
	loadimage(&img0,_T("pictures\\0.jpg"),32,32);
	loadimage(&img1,_T("pictures\\1.jpg"),32,32);
	loadimage(&img2,_T("pictures\\2.jpg"),32,32);
	loadimage(&img3,_T("pictures\\3.jpg"),32,32);
	loadimage(&img4,_T("pictures\\4.jpg"),32,32);
	loadimage(&img5,_T("pictures\\5.jpg"),32,32);
	loadimage(&img6,_T("pictures\\6.jpg"),32,32);
	loadimage(&img7,_T("pictures\\7.jpg"),32,32);
	loadimage(&img8,_T("pictures\\8.jpg"),32,32);
	loadimage(&img9,_T("pictures\\9.jpg"),32,32);
	loadimage(&img10,_T("pictures\\10.jpg"),96,32);
	loadimage(&img11,_T("pictures\\11.jpg"),96,32);
	loadimage(&img100,_T("pictures\\100.jpg"),32,32);
	loadimage(&img101,_T("pictures\\101.jpg"),32,32);
	loadimage(&img102,_T("pictures\\102.jpg"),32,32);
	loadimage(&img103,_T("pictures\\103.jpg"),32,32);
	loadimage(&img104,_T("pictures\\104.jpg"),32,32);
	loadimage(&img105,_T("pictures\\105.jpg"),32,32);
	loadimage(&img106,_T("pictures\\106.jpg"),32,32);
	loadimage(&img200,_T("pictures\\200.jpg"),32,32);
	loadimage(&img201,_T("pictures\\201.jpg"),32,32);
	loadimage(&img202,_T("pictures\\202.jpg"),32,32);
	loadimage(&img203,_T("pictures\\203.jpg"),32,32);
	loadimage(&img204,_T("pictures\\204.jpg"),32,32);
	loadimage(&img205,_T("pictures\\205.jpg"),32,32);
	loadimage(&img206,_T("pictures\\206.jpg"),32,32);
	loadimage(&img207,_T("pictures\\207.jpg"),32,32);
	loadimage(&img208,_T("pictures\\208.jpg"),32,32);
	loadimage(&img209,_T("pictures\\209.jpg"),32,32);
	loadimage(&img210,_T("pictures\\210.jpg"),32,32);
	loadimage(&img211,_T("pictures\\211.jpg"),32,32);
	loadimage(&img300,_T("pictures\\300.jpg"),32,32);
	loadimage(&img301,_T("pictures\\301.jpg"),32,32);
	loadimage(&img302,_T("pictures\\302.jpg"),32,32);
	loadimage(&img303,_T("pictures\\303.jpg"),32,32);
	loadimage(&img310,_T("pictures\\310.jpg"),32,32);
	loadimage(&img311,_T("pictures\\311.jpg"),32,32);
	loadimage(&img312,_T("pictures\\312.jpg"),32,32);
	loadimage(&img320,_T("pictures\\320.jpg"),32,32);
	loadimage(&img321,_T("pictures\\321.jpg"),32,32);
	loadimage(&img322,_T("pictures\\322.jpg"),32,32);
	loadimage(&img330,_T("pictures\\330.jpg"),32,32);
	loadimage(&img331,_T("pictures\\331.jpg"),32,32);
	loadimage(&img332,_T("pictures\\332.jpg"),32,32);
	loadimage(&img340,_T("pictures\\340.jpg"),32,32);
	loadimage(&img341,_T("pictures\\341.jpg"),32,32);
	loadimage(&img342,_T("pictures\\342.jpg"),32,32);
	loadimage(&img350,_T("pictures\\350.jpg"),32,32);
	loadimage(&img351,_T("pictures\\351.jpg"),32,32);
	loadimage(&img360,_T("pictures\\360.jpg"),32,32);
	loadimage(&img361,_T("pictures\\361.jpg"),32,32);
	loadimage(&img362,_T("pictures\\362.jpg"),32,32);
	loadimage(&img370,_T("pictures\\370.jpg"),32,32);
	loadimage(&img371,_T("pictures\\371.jpg"),32,32);
	loadimage(&img380,_T("pictures\\380.jpg"),32,32);
	loadimage(&img381,_T("pictures\\381.jpg"),32,32);
	loadimage(&img390,_T("pictures\\390.jpg"),32,32);
	loadimage(&img391,_T("pictures\\391.jpg"),32,32);
	loadimage(&img392,_T("pictures\\392.jpg"),32,32);
	loadimage(&img393,_T("pictures\\393.jpg"),32,32);
	loadimage(&img400,_T("pictures\\400.jpg"),32,32);
	loadimage(&img401,_T("pictures\\401.jpg"),32,32);
	loadimage(&img402,_T("pictures\\402.jpg"),32,32);
	loadimage(&img403,_T("pictures\\403.jpg"),32,32);
	loadimage(&img410,_T("pictures\\410.jpg"),32,32);
	loadimage(&img411,_T("pictures\\411.jpg"),32,32);
	loadimage(&img412,_T("pictures\\412.jpg"),32,32);
	loadimage(&img107,_T("pictures\\107.jpg"),32,32);
	for (x = 0;x <= 16; x++)
	{
		for (y = 0;y <= 16;y++)
		{
			if (map[z][x][y] == 0)
			{
				putimage(156+x*32,y*32,&img0);
			}
			else if(map[z][x][y] == 1)
			{
				putimage(156+x*32,y*32,&img1);
			}
			else if(map[z][x][y] == 2)
			{
				putimage(156+x*32,y*32,&img2);
			}
			else if(map[z][x][y] == 3)
			{
				putimage(156+x*32,y*32,&img3);
			}
			else if(map[z][x][y] == 4)
			{
				putimage(156+x*32,y*32,&img4);
			}
			else if(map[z][x][y] == 5)
			{
				putimage(156+x*32,y*32,&img5);
			}
			else if(map[z][x][y] == 6)
			{
				putimage(156+x*32,y*32,&img6);
			}
			else if(map[z][x][y] == 7)
			{
				putimage(156+x*32,y*32,&img7);
			}
			else if(map[z][x][y] == 8)
			{
				putimage(156+x*32,y*32,&img8);
			}
			else if(map[z][x][y] == 9)
			{
				putimage(156+x*32,y*32,&img9);
			}
			else if(map[z][x][y] == 10)
			{
				putimage(156+x*32,y*32,&img10);
			}
			else if(map[z][x][y] == 11)
			{
				putimage(156+x*32,y*32,&img11);
			}
			else if(map[z][x][y] == 100)
			{
				putimage(156+x*32,y*32,&img100);
			}
			else if(map[z][x][y] == 101)
			{
				putimage(156+x*32,y*32,&img101);
			}
			else if(map[z][x][y] == 102)
			{
				putimage(156+x*32,y*32,&img102);
			}
			else if(map[z][x][y] == 103)
			{
				putimage(156+x*32,y*32,&img103);
			}
			else if(map[z][x][y] == 104)
			{
				putimage(156+x*32,y*32,&img104);
			}
			else if(map[z][x][y] == 105)
			{
				putimage(156+x*32,y*32,&img105);
			}
			else if(map[z][x][y] == 106)
			{
				putimage(156+x*32,y*32,&img106);
			}
			else if(map[z][x][y] == 200)
			{
				putimage(156+x*32,y*32,&img200);
			}
			else if(map[z][x][y] == 201)
			{
				putimage(156+x*32,y*32,&img201);
			}
			else if(map[z][x][y] == 202)
			{
				putimage(156+x*32,y*32,&img202);
			}
			else if(map[z][x][y] == 203)
			{
				putimage(156+x*32,y*32,&img203);
			}
			else if(map[z][x][y] == 204)
			{
				putimage(156+x*32,y*32,&img204);
			}
			else if(map[z][x][y] == 205)
			{
				putimage(156+x*32,y*32,&img205);
			}
			else if(map[z][x][y] == 206)
			{
				putimage(156+x*32,y*32,&img206);
			}
			else if(map[z][x][y] == 207)
			{
				putimage(156+x*32,y*32,&img207);
			}
			else if(map[z][x][y] == 208)
			{
				putimage(156+x*32,y*32,&img208);
			}
			else if(map[z][x][y] == 209)
			{
				putimage(156+x*32,y*32,&img209);
			}
			else if(map[z][x][y] == 210)
			{
				putimage(156+x*32,y*32,&img210);
			}
			else if(map[z][x][y] == 211)
			{
				putimage(156+x*32,y*32,&img211);
			}
			else if(map[z][x][y] == 300)
			{
				putimage(156+x*32,y*32,&img300);
			}
			else if(map[z][x][y] == 301)
			{
				putimage(156+x*32,y*32,&img301);
			}
			else if(map[z][x][y] == 302)
			{
				putimage(156+x*32,y*32,&img302);
			}
			else if(map[z][x][y] == 303)
			{
				putimage(156+x*32,y*32,&img303);
			}
			else if(map[z][x][y] == 310)
			{
				putimage(156+x*32,y*32,&img310);
			}
			else if(map[z][x][y] == 311)
			{
				putimage(156+x*32,y*32,&img311);
			}
			else if(map[z][x][y] == 312)
			{
				putimage(156+x*32,y*32,&img312);
			}
			else if(map[z][x][y] == 320)
			{
				putimage(156+x*32,y*32,&img320);
			}
			else if(map[z][x][y] == 321)
			{
				putimage(156+x*32,y*32,&img321);
			}
			else if(map[z][x][y] == 322)
			{
				putimage(156+x*32,y*32,&img322);
			}
			else if(map[z][x][y] == 330)
			{
				putimage(156+x*32,y*32,&img330);
			}
			else if(map[z][x][y] == 331)
			{
				putimage(156+x*32,y*32,&img331);
			}
			else if(map[z][x][y] == 332)
			{
				putimage(156+x*32,y*32,&img332);
			}
			else if(map[z][x][y] == 340)
			{
				putimage(156+x*32,y*32,&img340);
			}
			else if(map[z][x][y] == 341)
			{
				putimage(156+x*32,y*32,&img341);
			}
			else if(map[z][x][y] == 342)
			{
				putimage(156+x*32,y*32,&img342);
			}
			else if(map[z][x][y] == 350)
			{
				putimage(156+x*32,y*32,&img350);
			}
			else if(map[z][x][y] == 351)
			{
				putimage(156+x*32,y*32,&img351);
			}
			else if(map[z][x][y] == 360)
			{
				putimage(156+x*32,y*32,&img360);
			}
			else if(map[z][x][y] == 361)
			{
				putimage(156+x*32,y*32,&img361);
			}
			else if(map[z][x][y] == 362)
			{
				putimage(156+x*32,y*32,&img362);
			}
			else if(map[z][x][y] == 370)
			{
				putimage(156+x*32,y*32,&img370);
			}
			else if(map[z][x][y] == 371)
			{
				putimage(156+x*32,y*32,&img371);
			}
			else if(map[z][x][y] == 380)
			{
				putimage(156+x*32,y*32,&img380);
			}
			else if(map[z][x][y] == 381)
			{
				putimage(156+x*32,y*32,&img381);
			}
			else if(map[z][x][y] == 390)
			{
				putimage(156+x*32,y*32,&img390);
			}
			else if(map[z][x][y] == 391)
			{
				putimage(156+x*32,y*32,&img391);
			}
			else if(map[z][x][y] == 392)
			{
				putimage(156+x*32,y*32,&img392);
			}
			else if(map[z][x][y] == 393)
			{
				putimage(156+x*32,y*32,&img393);
			}
			else if(map[z][x][y] == 400)
			{
				putimage(156+x*32,y*32,&img400);
			}
			else if(map[z][x][y] == 401)
			{
				putimage(156+x*32,y*32,&img401);
			}
			else if(map[z][x][y] == 402)
			{
				putimage(156+x*32,y*32,&img402);
			}
			else if(map[z][x][y] == 403)
			{
				putimage(156+x*32,y*32,&img403);
			}
			else if(map[z][x][y] == 410)
			{
				putimage(156+x*32,y*32,&img410);
			}
			else if(map[z][x][y] == 411)
			{
				putimage(156+x*32,y*32,&img411);
			}
			else if(map[z][x][y] == 412)
			{
				putimage(156+x*32,y*32,&img412);
			}
			else if(map[z][x][y] == 108)
			{
				putimage(156+x*32,y*32,&img107);
			}
			else if(map[z][x][y] == 109)
			{
				putimage(156+x*32,y*32,&img107);
			}
		}
	}
	while (!kbhit())
	{
		if(MouseHit())
		{
			MOUSEMSG m;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN && m.x <= 156 && m.x >= 0 && m.y <= 330 && m.y >= 290 && HasDictionary)
			{
				openDictionary();
			}
			else if (m.uMsg == WM_LBUTTONDOWN && m.x <= 156 && m.x >= 0 && m.y <= 370 && m.y >= 330 && HasTransfer)
			{
				openTransfer();
			}
		}
	}
}