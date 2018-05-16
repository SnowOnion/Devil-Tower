#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "man.h"
#include "display.h"
extern int z;


int main()
{
	initgraph(700,544);
	RECT title={0,0,700,200};
	drawtext(_T("Devil Tower"),&title,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT start={0,200,700,400};
	drawtext(_T("Start Game"),&start,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT exit={0,400,700,500};
	drawtext(_T("Exit Game"),&exit,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	MOUSEMSG m;
	line(200,250,500,250);
	line(500,250,500,350);
	line(500,350,200,350);
	line(200,350,200,250);
	line(200,400,500,400);
	line(500,400,500,500);
	line(500,500,200,500);
	line(200,500,200,400);
	

	int control=1;
	while (control!=0)
	{
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if(m.x>=200&&m.x<=500&&m.y>=250&&m.y<=350)
			{					
				display(1);
				while(TRUE)
				{
					move();
				}
			}
			if(m.x>=200&&m.x<=500&&m.y>=400&&m.y<=500)
			{
				closegraph();
			}
			break;
		}
	}
}