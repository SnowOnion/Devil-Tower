#include <stdio.h>
#include <stdlib.h>
#include "man.h"
#include "save.h"
#include "display.h"
#include <graphics.h>
#include <conio.h>

extern int map[25][17][17];
extern int Attack;
extern int Defense;
extern long Health;
extern int z;
extern float Agility;
extern int Money;
extern int Experience;
extern int Level;
extern int YellowKey;                                  
extern int BlueKey;                                   
extern int RedKey;                                   
extern int yman;                                       
extern int xman;     
extern bool HasTransfer;
extern bool HasDictionary;
extern int zmax;
extern int loadmap[25][17][17];
int displayfloor;
int displayhealth = Health;
int displayattack = Attack;
int displaydefense = Defense;

bool saved1 = false;
bool saved2 = false;
bool saved3 = false;
void saveGame(void)
{
	clearrectangle(156,0,700,544);
	RECT statementr = {156,25,700,75};
	RECT firstSaver = {156,225,300,275};
	RECT secondSaver = {156,325,300,375};
	RECT thirdSaver = {156,425,300,475};
	drawtext(_T("choose your save:"),&statementr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	drawtext(_T("1st save:"),&firstSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	drawtext(_T("2nd save:"),&secondSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	drawtext(_T("3rd save:"),&thirdSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	TCHAR attackc[] = _T("Attack");
	TCHAR defensec[] = _T("Defense");
	TCHAR healthc[] = _T("Health");
	TCHAR floorc[] = _T("Floor");
	outtextxy(300,190,attackc);
	outtextxy(400,190,defensec);
	outtextxy(500,190,healthc);
	outtextxy(600,190,floorc);
	TCHAR exitc[] = _T("Exit");
	outtextxy(406,512,exitc);

	FILE* filePtr1 = fopen("save1.txt","r");
	char save1[10];
	fgets(save1,10,filePtr1);
	if(atoi(save1)==1)
		saved1 = true;
	else
		saved1 = false;
	if (saved1)
	{
		char aAttack1[10];
		fgets(aAttack1,10,filePtr1);
		displayattack = atoi(aAttack1);
		char aDefense1[10];
		fgets(aDefense1,10,filePtr1);
		displaydefense = atoi(aDefense1);
		char aHealth1[10];
		fgets(aHealth1,10,filePtr1);
		displayhealth = atoi(aHealth1);
		char az1[10];
		fgets(az1,10,filePtr1);
		displayfloor = atoi(az1);
		TCHAR strattack1[10];
		_stprintf(strattack1,TEXT("%d"),displayattack);
		outtextxy(300,242,strattack1);
		TCHAR strdefense1[10];
		_stprintf(strdefense1,TEXT("%d"),displaydefense);
		outtextxy(400,242,strdefense1);
		TCHAR strhealth1[10];
		_stprintf(strhealth1,TEXT("%d"),displayhealth);
		outtextxy(500,242,strhealth1);
		TCHAR strfloor1[10];
		_stprintf(strfloor1,TEXT("%d"),displayfloor);
		outtextxy(600,242,strfloor1);
	}
	else
	{
		TCHAR nosave1[] = _T("No Save Here!");
		outtextxy(440,242,nosave1);
	}

	FILE* filePtr2 = fopen("save2.txt","r");
	char save2[10];
	fgets(save2,10,filePtr2);
	if(atoi(save2)==1)
		saved2 = true;
	else
		saved2 = false;
	if(saved2)
	{
		char aAttack2[10];
		fgets(aAttack2,10,filePtr2);
		displayattack = atoi(aAttack2);
		char aDefense2[10];
		fgets(aDefense2,10,filePtr2);
		displaydefense = atoi(aDefense2);
		char aHealth2[10];
		fgets(aHealth2,10,filePtr2);
		displayhealth = atoi(aHealth2);
		char az2[10];
		fgets(az2,10,filePtr2);
		displayfloor = atoi(az2);
		TCHAR strattack2[10];
		_stprintf(strattack2,TEXT("%d"),displayattack);
		outtextxy(300,342,strattack2);
		TCHAR strdefense2[10];
		_stprintf(strdefense2,TEXT("%d"),displaydefense);
		outtextxy(400,342,strdefense2);
		TCHAR strhealth2[10];
		_stprintf(strhealth2,TEXT("%d"),displayhealth);
		outtextxy(500,342,strhealth2);
		TCHAR strfloor2[10];
		_stprintf(strfloor2,TEXT("%d"),displayfloor);
		outtextxy(600,342,strfloor2);
	}
	else
	{
		TCHAR nosave2[] = _T("No Save Here!");
		outtextxy(440,342,nosave2);
	}

	FILE* filePtr3 = fopen("save3.txt","r");
	char save3[10];
	fgets(save3,10,filePtr3);
	if(atoi(save3)==1)
		saved3 = true;
	else 
		saved3 = false;
	if(saved3)
	{
		char aAttack3[10];
		fgets(aAttack3,10,filePtr3);
		displayattack = atoi(aAttack3);
		char aDefense3[10];
		fgets(aDefense3,10,filePtr3);
		displaydefense = atoi(aDefense3);
		char aHealth3[10];
		fgets(aHealth3,10,filePtr3);
		displayhealth = atoi(aHealth3);
		char az3[10];
		fgets(az3,10,filePtr3);
		displayfloor = atoi(az3);
		TCHAR strattack3[10];
		_stprintf(strattack3,TEXT("%d"),displayattack);
		outtextxy(300,442,strattack3);
		TCHAR strdefense3[10];
		_stprintf(strdefense3,TEXT("%d"),displaydefense);
		outtextxy(400,442,strdefense3);
		TCHAR strhealth3[10];
		_stprintf(strhealth3,TEXT("%d"),displayhealth);
		outtextxy(500,442,strhealth3);
		TCHAR strfloor3[10];
		_stprintf(strfloor3,TEXT("%d"),displayfloor);
		outtextxy(600,442,strfloor3);
	}
	else
	{
		TCHAR nosave3[] = _T("No Save Here!");
		outtextxy(440,442,nosave3);
	}
	fclose(filePtr1);
	fclose(filePtr2);
	fclose(filePtr3);
	line(180,225,650,225);
	line(650,225,650,275);
	line(650,275,180,275);
	line(180,275,180,225);

	line(180,325,650,325);
	line(650,325,650,375);
	line(650,375,180,375);
	line(180,375,180,325);

	line(180,425,650,425);
	line(650,425,650,475);
	line(650,475,180,475);
	line(180,475,180,425);

	line(350,500,480,500);
	line(480,500,480,540);
	line(480,540,350,540);
	line(350,540,350,500);
	FILE* filePtr;
	MOUSEMSG m;
	bool proceed = false;
	while (!proceed)
	{
		while (!MouseHit()&&!kbhit())
		{}
		if (MouseHit())
			m = GetMouseMsg();
		if (kbhit())
		{
			char c = getch();
			if (c == 'x' || c == 'X')
			{
				proceed = false;
				display(z);
				break;
			}
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 275 && m.y >= 225)
		{
			filePtr = fopen("save1.txt","w");
			proceed = true;
			saved1 = true;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 375 && m.y >= 325)
		{
			filePtr = fopen("save2.txt","w");
			proceed = true;
			saved2 = true;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 475 && m.y >= 425)
		{
			filePtr = fopen("save3.txt","w");
			proceed = true;
			saved3 = true;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x <= 480 && m.x >= 350 && m.y <= 540 && m.y >= 500)
		{
			proceed = false;
			display(z);
			break;
		}
		if(proceed)
		{
			char save[10];
			sprintf(save,"%d\n",1);
			fputs(save,filePtr);

			char aAttack[10];
			sprintf(aAttack,"%d\n",Attack);
			fputs(aAttack,filePtr);

			char aDefense[10];
			sprintf(aDefense,"%d\n",Defense);
			fputs(aDefense,filePtr);

			char aHealth[10];
			sprintf(aHealth,"%d\n",Health);
			fputs(aHealth,filePtr);

			char az[10];
			sprintf(az,"%d\n",z);
			fputs(az,filePtr);

			char aAgility[10];
			sprintf(aAgility,"%f\n",Agility);
			fputs(aAgility,filePtr);

			char aMoney[10];
			sprintf(aMoney,"%d\n",Money);
			fputs(aMoney,filePtr);

			char aExperience[10];
			sprintf(aExperience,"%d\n",Experience);
			fputs(aExperience,filePtr);

			char aLevel[10];
			sprintf(aLevel,"%d\n",Level);
			fputs(aLevel,filePtr);

			char axman[10];
			sprintf(axman,"%d\n",xman);
			fputs(axman,filePtr);

			char ayman[10];
			sprintf(ayman,"%d\n",yman);
			fputs(ayman,filePtr);

			char azmax[10];
			sprintf(azmax,"%d\n",zmax);
			fputs(azmax,filePtr);

			char aYellowKey[10];
			sprintf(aYellowKey,"%d\n",YellowKey);
			fputs(aYellowKey,filePtr);

			char aBlueKey[10];
			sprintf(aBlueKey,"%d\n",BlueKey);
			fputs(aBlueKey,filePtr);

			char aRedKey[10];
			sprintf(aRedKey,"%d\n",RedKey);
			fputs(aRedKey,filePtr);

			if (HasDictionary)
				fputc('1',filePtr);
			else
				fputc('0',filePtr);
			fputc('\n',filePtr);

			if (HasTransfer)
				fputc('1',filePtr);
			else
				fputc('0',filePtr);
			fputc('\n',filePtr);

			int x = 0;
			int y = 0;
			int mapz = 0;
			for (mapz = 0;mapz <= 14;mapz++)
			{
				for (x = 0;x <= 16;x++)
				{
					for (y = 0;y<=16;y++)
					{
						char ID[10];
						sprintf(ID,"%d\n",map[mapz][x][y]);
						fputs(ID,filePtr);
					}
				}
			}
			fclose(filePtr);
			display(z);
		}
	}
}


void loadGame(int number)
{
	if(number == 1)                                                                               //正常读档
	{
		clearrectangle(156,0,700,544);
		RECT statementr = {156,25,700,75};
		RECT firstSaver = {156,225,300,275};
		RECT secondSaver = {156,325,300,375};
		RECT thirdSaver = {156,425,300,475};
		drawtext(_T("choose your save:"),&statementr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("1st save:"),&firstSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("2nd save:"),&secondSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("3rd save:"),&thirdSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		TCHAR attackc[] = _T("Attack");
		TCHAR defensec[] = _T("Defense");
		TCHAR healthc[] = _T("Health");
		TCHAR floorc[] = _T("Floor");
		outtextxy(300,190,attackc);
		outtextxy(400,190,defensec);
		outtextxy(500,190,healthc);
		outtextxy(600,190,floorc);
		TCHAR exitc[] = _T("Exit");
		outtextxy(406,512,exitc);

		FILE* filePtr1 = fopen("save1.txt","r");
		char save1[10];
		fgets(save1,10,filePtr1);
		if(atoi(save1)==1)
			saved1 = true;
		else 
			saved1 = false;
		if (saved1)
		{
			char aAttack1[10];
			fgets(aAttack1,10,filePtr1);
			displayattack = atoi(aAttack1);
			char aDefense1[10];
			fgets(aDefense1,10,filePtr1);
			displaydefense = atoi(aDefense1);
			char aHealth1[10];
			fgets(aHealth1,10,filePtr1);
			displayhealth = atoi(aHealth1);
			char az1[10];
			fgets(az1,10,filePtr1);
			displayfloor = atoi(az1);
			TCHAR strattack1[10];
			_stprintf(strattack1,TEXT("%d"),displayattack);
			outtextxy(300,242,strattack1);
			TCHAR strdefense1[10];
			_stprintf(strdefense1,TEXT("%d"),displaydefense);
			outtextxy(400,242,strdefense1);
			TCHAR strhealth1[10];
			_stprintf(strhealth1,TEXT("%d"),displayhealth);
			outtextxy(500,242,strhealth1);
			TCHAR strfloor1[10];
			_stprintf(strfloor1,TEXT("%d"),displayfloor);
			outtextxy(600,242,strfloor1);
		}
		else
		{
			TCHAR nosave1[] = _T("No Save Here!");
			outtextxy(440,242,nosave1);
		}

		FILE* filePtr2 = fopen("save2.txt","r");
		char save2[10];
		fgets(save2,10,filePtr2);
		if(atoi(save2)==1)
			saved2 = true;
		else 
			saved2 = false;
		if(saved2)
		{
			char aAttack2[10];
			fgets(aAttack2,10,filePtr2);
			displayattack = atoi(aAttack2);
			char aDefense2[10];
			fgets(aDefense2,10,filePtr2);
			displaydefense = atoi(aDefense2);
			char aHealth2[10];
			fgets(aHealth2,10,filePtr2);
			displayhealth = atoi(aHealth2);
			char az2[10];
			fgets(az2,10,filePtr2);
			displayfloor = atoi(az2);
			TCHAR strattack2[10];
			_stprintf(strattack2,TEXT("%d"),displayattack);
			outtextxy(300,342,strattack2);
			TCHAR strdefense2[10];
			_stprintf(strdefense2,TEXT("%d"),displaydefense);
			outtextxy(400,342,strdefense2);
			TCHAR strhealth2[10];
			_stprintf(strhealth2,TEXT("%d"),displayhealth);
			outtextxy(500,342,strhealth2);
			TCHAR strfloor2[10];
			_stprintf(strfloor2,TEXT("%d"),displayfloor);
			outtextxy(600,342,strfloor2);
		}
		else
		{
			TCHAR nosave2[] = _T("No Save Here!");
			outtextxy(440,342,nosave2);
		}

		FILE* filePtr3 = fopen("save3.txt","r");
		char save3[10];
		fgets(save3,10,filePtr3);
		if(atoi(save3)==1)
			saved3 = true;
		else 
			saved3 = false;
		if(saved3)
		{
			char aAttack3[10];
			fgets(aAttack3,10,filePtr3);
			displayattack = atoi(aAttack3);
			char aDefense3[10];
			fgets(aDefense3,10,filePtr3);
			displaydefense = atoi(aDefense3);
			char aHealth3[10];
			fgets(aHealth3,10,filePtr3);
			displayhealth = atoi(aHealth3);
			char az3[10];
			fgets(az3,10,filePtr3);
			displayfloor = atoi(az3);
			TCHAR strattack3[10];
			_stprintf(strattack3,TEXT("%d"),displayattack);
			outtextxy(300,442,strattack3);
			TCHAR strdefense3[10];
			_stprintf(strdefense3,TEXT("%d"),displaydefense);
			outtextxy(400,442,strdefense3);
			TCHAR strhealth3[10];
			_stprintf(strhealth3,TEXT("%d"),displayhealth);
			outtextxy(500,442,strhealth3);
			TCHAR strfloor3[10];
			_stprintf(strfloor3,TEXT("%d"),displayfloor);
			outtextxy(600,442,strfloor3);
		}
		else
		{
			TCHAR nosave3[] = _T("No Save Here!");
			outtextxy(440,442,nosave3);
		}
		line(180,225,650,225);
		line(650,225,650,275);
		line(650,275,180,275);
		line(180,275,180,225);

		line(180,325,650,325);
		line(650,325,650,375);
		line(650,375,180,375);
		line(180,375,180,325);

		line(180,425,650,425);
		line(650,425,650,475);
		line(650,475,180,475);
		line(180,475,180,425);

		line(350,500,480,500);
		line(480,500,480,540);
		line(480,540,350,540);
		line(350,540,350,500);
		bool proceed = false;
		while (!kbhit() && !proceed)
		{
			FILE* filePtr;
			while(!proceed)
			{
				MOUSEMSG m;
				while (!MouseHit()&&!kbhit())
				{}
				if (MouseHit())
					m = GetMouseMsg();
				if (kbhit())
				{
					char c = getch();
					if (c == 'l' || c == 'L')
					{
						proceed = false;
						display(z);
						break;
					}
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 275 && m.y >= 225 && saved1)
				{
					filePtr = fopen("save1.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 375 && m.y >= 325 && saved2)
				{
					filePtr = fopen("save2.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 475 && m.y >= 425 && saved3)
				{
					filePtr = fopen("save3.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 480 && m.x >= 350 && m.y <= 540 && m.y >= 500)
				{
					proceed = false;
					break;
				}
			}
			if (proceed)
			{
				char save[10];
				fgets(save,10,filePtr);

				char aAttack[10];
				fgets(aAttack,10,filePtr);
				AddAttack(atoi(aAttack)-Attack);

				char aDefense[10];
				fgets(aDefense,10,filePtr);
				AddDefense(atoi(aDefense)-Defense);

				char aHealth[10];
				fgets(aHealth,10,filePtr);
				AddHealth(atoi(aHealth)-Health);

				char az[10];
				fgets(az,10,filePtr);
				z = atoi(az);

				char aAgility[10];
				fgets(aAgility,10,filePtr);
				AddAgility(atol(aAgility)-Agility);

				char aMoney[10];
				fgets(aMoney,10,filePtr);
				AddMoney(atoi(aMoney)-Money);

				char aExperience[10];
				fgets(aExperience,10,filePtr);
				AddExperience(atoi(aExperience)-Experience);

				char aLevel[10];
				fgets(aLevel,10,filePtr);
				Level = atoi(aLevel);

				char axman[10];
				fgets(axman,10,filePtr);
				xman = atoi(axman);

				char ayman[10];
				fgets(ayman,10,filePtr);
				yman = atoi(ayman);

				char azmax[10];
				fgets(azmax,10,filePtr);
				zmax = atoi(azmax);

				char aYellowKey[10];
				fgets(aYellowKey,10,filePtr);
				YellowKey = atoi(aYellowKey);

				char aBlueKey[10];
				fgets(aBlueKey,10,filePtr);
				BlueKey = atoi(aBlueKey);

				char aRedKey[10];
				fgets(aRedKey,10,filePtr);
				RedKey = atoi(aRedKey);

				char aHasDictionary[10];
				fgets(aHasDictionary,10,filePtr);
				if (atoi(aHasDictionary) == 1)
					HasDictionary = true;
				else
					HasDictionary = false;

				char aHasTransfer[10];
				fgets(aHasTransfer,10,filePtr);
				if (atoi(aHasTransfer) == 1)
					HasTransfer = true;
				else
					HasTransfer = false;

				int x = 0;
				int y = 0;
				int mapz = 0;
				for (mapz = 0;mapz <= 14;mapz++)
				{
					for (x = 0;x <= 16;x++)
					{
						for (y = 0;y<=16;y++)
						{
							char ID[10];
							fgets(ID,10,filePtr);
							map[mapz][x][y] = atoi(ID);
						}
					}
				}
			}
			display(z);
		}
	}

	if (number == 0 || number == 2)                                                                       //加载界面读档或死亡读档
	{
		clearrectangle(156,0,700,544);
		RECT statementr = {156,25,700,75};
		RECT firstSaver = {156,225,300,275};
		RECT secondSaver = {156,325,300,375};
		RECT thirdSaver = {156,425,300,475};
		drawtext(_T("choose your save:"),&statementr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("1st save:"),&firstSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("2nd save:"),&secondSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		drawtext(_T("3rd save:"),&thirdSaver,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		TCHAR attackc[] = _T("Attack");
		TCHAR defensec[] = _T("Defense");
		TCHAR healthc[] = _T("Health");
		TCHAR floorc[] = _T("Floor");
		outtextxy(300,190,attackc);
		outtextxy(400,190,defensec);
		outtextxy(500,190,healthc);
		outtextxy(600,190,floorc);
		TCHAR exitc[] = _T("Exit");
		outtextxy(406,512,exitc);

		FILE* filePtr1 = fopen("save1.txt","r");
		char save1[10];
		fgets(save1,10,filePtr1);
		if(atoi(save1)==1)
			saved1 = true;
		else 
			saved1 = false;
		if (saved1)
		{
			char aAttack1[10];
			fgets(aAttack1,10,filePtr1);
			displayattack = atoi(aAttack1);
			char aDefense1[10];
			fgets(aDefense1,10,filePtr1);
			displaydefense = atoi(aDefense1);
			char aHealth1[10];
			fgets(aHealth1,10,filePtr1);
			displayhealth = atoi(aHealth1);
			char az1[10];
			fgets(az1,10,filePtr1);
			displayfloor = atoi(az1);
			TCHAR strattack1[10];
			_stprintf(strattack1,TEXT("%d"),displayattack);
			outtextxy(300,242,strattack1);
			TCHAR strdefense1[10];
			_stprintf(strdefense1,TEXT("%d"),displaydefense);
			outtextxy(400,242,strdefense1);
			TCHAR strhealth1[10];
			_stprintf(strhealth1,TEXT("%d"),displayhealth);
			outtextxy(500,242,strhealth1);
			TCHAR strfloor1[10];
			_stprintf(strfloor1,TEXT("%d"),displayfloor);
			outtextxy(600,242,strfloor1);
		}
		else
		{
			TCHAR nosave1[] = _T("No Save Here!");
			outtextxy(440,242,nosave1);
		}

		FILE* filePtr2 = fopen("save2.txt","r");
		char save2[10];
		fgets(save2,10,filePtr2);
		if(atoi(save2)==1)
			saved2 = true;
		else 
			saved2 = false;
		if(saved2)
		{
			char aAttack2[10];
			fgets(aAttack2,10,filePtr2);
			displayattack = atoi(aAttack2);
			char aDefense2[10];
			fgets(aDefense2,10,filePtr2);
			displaydefense = atoi(aDefense2);
			char aHealth2[10];
			fgets(aHealth2,10,filePtr2);
			displayhealth = atoi(aHealth2);
			char az2[10];
			fgets(az2,10,filePtr2);
			displayfloor = atoi(az2);
			TCHAR strattack2[10];
			_stprintf(strattack2,TEXT("%d"),displayattack);
			outtextxy(300,342,strattack2);
			TCHAR strdefense2[10];
			_stprintf(strdefense2,TEXT("%d"),displaydefense);
			outtextxy(400,342,strdefense2);
			TCHAR strhealth2[10];
			_stprintf(strhealth2,TEXT("%d"),displayhealth);
			outtextxy(500,342,strhealth2);
			TCHAR strfloor2[10];
			_stprintf(strfloor2,TEXT("%d"),displayfloor);
			outtextxy(600,342,strfloor2);
		}
		else
		{
			TCHAR nosave2[] = _T("No Save Here!");
			outtextxy(440,342,nosave2);
		}

		FILE* filePtr3 = fopen("save3.txt","r");
		char save3[10];
		fgets(save3,10,filePtr3);
		if(atoi(save3)==1)
			saved3 = true;
		else 
			saved3 = false;
		if(saved3)
		{
			char aAttack3[10];
			fgets(aAttack3,10,filePtr3);
			displayattack = atoi(aAttack3);
			char aDefense3[10];
			fgets(aDefense3,10,filePtr3);
			displaydefense = atoi(aDefense3);
			char aHealth3[10];
			fgets(aHealth3,10,filePtr3);
			displayhealth = atoi(aHealth3);
			char az3[10];
			fgets(az3,10,filePtr3);
			displayfloor = atoi(az3);
			TCHAR strattack3[10];
			_stprintf(strattack3,TEXT("%d"),displayattack);
			outtextxy(300,442,strattack3);
			TCHAR strdefense3[10];
			_stprintf(strdefense3,TEXT("%d"),displaydefense);
			outtextxy(400,442,strdefense3);
			TCHAR strhealth3[10];
			_stprintf(strhealth3,TEXT("%d"),displayhealth);
			outtextxy(500,442,strhealth3);
			TCHAR strfloor3[10];
			_stprintf(strfloor3,TEXT("%d"),displayfloor);
			outtextxy(600,442,strfloor3);
		}
		else
		{
			TCHAR nosave3[] = _T("No Save Here!");
			outtextxy(440,442,nosave3);
		}
		fclose(filePtr1);
		fclose(filePtr2);
		fclose(filePtr3);

		line(180,225,650,225);
		line(650,225,650,275);
		line(650,275,180,275);
		line(180,275,180,225);

		line(180,325,650,325);
		line(650,325,650,375);
		line(650,375,180,375);
		line(180,375,180,325);

		line(180,425,650,425);
		line(650,425,650,475);
		line(650,475,180,475);
		line(180,475,180,425);

		line(350,500,480,500);
		line(480,500,480,540);
		line(480,540,350,540);
		line(350,540,350,500);
		bool proceed = false;
		while (!proceed)
		{
			FILE* filePtr;
			while(!proceed)
			{
				MOUSEMSG m;
				while (!MouseHit())
				{}
				if (MouseHit())
					m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 275 && m.y >= 225 && saved1)
				{
					filePtr = fopen("save1.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 375 && m.y >= 325 && saved2)
				{
					filePtr = fopen("save2.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 650 && m.x >= 180 && m.y <= 475 && m.y >= 425 && saved3)
				{
					filePtr = fopen("save3.txt","r");
					proceed = true;
				}
				if (m.uMsg == WM_LBUTTONDOWN && m.x <= 480 && m.x >= 350 && m.y <= 540 && m.y >= 500)
				{
					proceed = false;
					clearrectangle(0,0,700,544);
					RECT title={0,0,700,200};
					drawtext(_T("Devil Tower"),&title,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
					RECT start={0,200,700,300};
					drawtext(_T("Start Game"),&start,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
					RECT load={0,300,700,400};
					drawtext(_T("Load Game"),&load,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
					RECT exit={0,400,700,500};
					drawtext(_T("Exit Game"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
					MOUSEMSG m;
					line(200,225,500,225);
					line(500,225,500,275);
					line(500,275,200,275);
					line(200,275,200,225);
					line(200,325,500,325);
					line(500,325,500,375);
					line(500,375,200,375);
					line(200,375,200,325);
					line(200,425,500,425);
					line(500,425,500,475);
					line(500,475,200,475);
					line(200,475,200,425);
					int control=1;
					while (control!=0)
					{
						m=GetMouseMsg();
						switch(m.uMsg)
						{
						case WM_LBUTTONDOWN:
							if(m.x>=200&&m.x<=500&&m.y>=225&&m.y<=275&&number == 0)
							{					
								display(1);
								while(TRUE)
								{
									move();
								}
							}
							if(m.x>=200&&m.x<=500&&m.y>=225&&m.y<=275&&number == 2)
							{
								Health = 1000;                                  
								Attack = 10;                                    
								Defense = 10;                                   
								Agility = 1.0;                                
								HasTransfer = false;                           
								HasDictionary = false;                         
								YellowKey = 0;                                  
								BlueKey = 0;                                    
								RedKey = 0;                                   
								yman=0;                                      
								xman=8;                                        
								z = 1;                                        
								Money = 0;                                     
								Experience = 0;                               
								Level = 1;                                    
								zmax = 1;
								int x,y,mapz;
								for (mapz = 0;mapz <= 24;mapz ++)
								{
									for (x = 0;x<=16;x++)
									{
										for (y=0;y<=16;y++)
										{
											SetMap(mapz,x,y,loadmap[mapz][x][y]);
										}
									}
								}
								display(z);
								while(TRUE)
								{
									move();
								}
							}
							if(m.x>=200&&m.x<=500&&m.y>=325&&m.y<=375)
							{
								loadGame(0);
							}
							if(m.x>=200&&m.x<=500&&m.y>=425&&m.y<=475)
							{
								closegraph();
							}
							break;
						}
					}
					break;
				}
			}
			if (proceed)
			{
				char save[10];
				fgets(save,10,filePtr);

				char aAttack[10];
				fgets(aAttack,10,filePtr);
				AddAttack(atoi(aAttack)-Attack);

				char aDefense[10];
				fgets(aDefense,10,filePtr);
				AddDefense(atoi(aDefense)-Defense);

				char aHealth[10];
				fgets(aHealth,10,filePtr);
				AddHealth(atoi(aHealth)-Health);

				char az[10];
				fgets(az,10,filePtr);
				z = atoi(az);

				char aAgility[10];
				fgets(aAgility,10,filePtr);
				AddAgility(atol(aAgility)-Agility);

				char aMoney[10];
				fgets(aMoney,10,filePtr);
				AddMoney(atoi(aMoney)-Money);

				char aExperience[10];
				fgets(aExperience,10,filePtr);
				AddExperience(atoi(aExperience)-Experience);

				char aLevel[10];
				fgets(aLevel,10,filePtr);
				Level = atoi(aLevel);

				char axman[10];
				fgets(axman,10,filePtr);
				xman = atoi(axman);

				char ayman[10];
				fgets(ayman,10,filePtr);
				yman = atoi(ayman);

				char azmax[10];
				fgets(azmax,10,filePtr);
				zmax = atoi(azmax);

				char aYellowKey[10];
				fgets(aYellowKey,10,filePtr);
				YellowKey = atoi(aYellowKey);

				char aBlueKey[10];
				fgets(aBlueKey,10,filePtr);
				BlueKey = atoi(aBlueKey);

				char aRedKey[10];
				fgets(aRedKey,10,filePtr);
				RedKey = atoi(aRedKey);

				char aHasDictionary[10];
				fgets(aHasDictionary,10,filePtr);
				if (atoi(aHasDictionary) == 1)
					HasDictionary = true;
				else
					HasDictionary = false;

				char aHasTransfer[10];
				fgets(aHasTransfer,10,filePtr);
				if (atoi(aHasTransfer) == 1)
					HasTransfer = true;
				else
					HasTransfer = false;

				int x = 0;
				int y = 0;
				int mapz = 0;
				for (mapz = 0;mapz <= 14;mapz++)
				{
					for (x = 0;x <= 16;x++)
					{
						for (y = 0;y<=16;y++)
						{
							char ID[10];
							fgets(ID,10,filePtr);
							map[mapz][x][y] = atoi(ID);
						}
					}
				}
				fclose(filePtr);
			}
			display(z);
			while(true)
			{
				move();
			}
			break;
		}
	}
}