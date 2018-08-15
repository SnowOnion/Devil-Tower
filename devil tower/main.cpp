#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "man.h"
#include "display.h"
#include <ctime>
#include "save.h"
extern int z;
extern bool purchasing;


int main()
{
	initgraph(700,544);
	RECT title={0,0,700,200};
	drawtext(_T("Devil Tower"),&title,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT start={0,200,700,300};
	drawtext(_T("Start Game"),&start,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT load={0,300,700,400};
	drawtext(_T("Load Game"),&load,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT exit={0,400,700,500};
	drawtext(_T("Exit Game"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	MOUSEMSG m;
	rectangle(200,225,500,275);
	rectangle(200,325,500,375);
	rectangle(200,425,500,475);

	srand((unsigned)time(NULL));

	int control=1;
	while (control!=0)
	{
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if(m.x>=200&&m.x<=500&&m.y>=225&&m.y<=275)
			{					
				display(1);
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
}