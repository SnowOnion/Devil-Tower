#include <graphics.h>
#include <conio.h>
#include "dictionary.h"
#include "map.h"
#include "man.h"
#include "ID.h"
extern int map[25][17][17];
extern int z;
extern int Attack;
extern int Defense;
extern int Health;

void Merge(int A[], int left, int mid, int right)
{
	int len = right - left + 1;
	int *temp = new int[len];       
	int index = 0;
	int i = left;                   
	int j = mid + 1;                
	while (i <= mid && j <= right)
	{
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  
	}
	while (i <= mid)
	{
		temp[index++] = A[i++];
	}
	while (j <= right)
	{
		temp[index++] = A[j++];
	}
	for (int k = 0; k < len; k++)
	{
		A[left++] = temp[k];
	}
}

void MergeSort(int A[], int left, int right)    
{
	if (left == right)    
		return;
	int mid = (left + right) / 2;
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void openDictionary()
{
	clearrectangle(156,0,700,544);
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	int monsterArray[100];
	for (n = 0;n <= 99;n++)
	{
		monsterArray[n]=0;
	}
	n = 0;
	int same = 0;
	for (i=0;i<=16;i++)
	{
		for (j=0;j<=16;j++)
		{
			for (k=0;k<=99;k++)
			{
				if (map[z][i][j] == monsterArray[k])
				{
					same = 1;
					break;
				}
			}
			if (same == 0 && map[z][i][j] <= 500 && map[z][i][j] >= 300)
			{
				monsterArray[n] = map[z][i][j];
				n++;
			}
			same = 0;
		}
	}                                                                //ÊäÈë×Öµä

	MergeSort(monsterArray,0,sizeof(monsterArray)/sizeof(int)-1);    //ÅÅÐò×Öµä

	int n0;
	for (n=0;n<=99;n++)
	{
		if (monsterArray[n] != 0)
		{
			n0 = n;
			break;
		}
		if (n == 99)
		{
			n0 = -1;
		}
	}

	for (n=0;n<=99-n0;n++)
	{
		if (n0 != -1)
		{
			monsterArray[n] = monsterArray[n+n0];
		}
	}

	int page = 0;
	int exit = 0;
	if (monsterArray[0] == 0)
		exit = 1;
	int ID = 0;
	while (exit == 0)
	{
		for (n = 5 * page;(n <= 5 * page + 4)&&(monsterArray[n]!=0);n++)
		{
			ID = monsterArray[n];
			IMAGE monster;
			RECT namerect = {200,n * 100,350,100 + n * 100};
			RECT healthrect = {340,n * 100,400,100 + n * 100};
			RECT attackrect = {400,n * 100,460,100 + n * 100};
			RECT defenserect = {460,n * 100,520,100 + n * 100};
			RECT specialrect = {520,n * 100,620,100 + n * 100};
			RECT estimaterect = {620,n * 100,700,100 + n * 100};
			if (ID==300)
			{
				loadimage(&monster,_T("pictures\\300.jpg"),32,32);
				drawtext(_T("Green Slime"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==301)
			{
				loadimage(&monster,_T("pictures\\301.jpg"),32,32);
				drawtext(_T("Red Slime"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==302)
			{
				loadimage(&monster,_T("pictures\\302.jpg"),32,32);
				drawtext(_T("Black Slime"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==303)
			{
				loadimage(&monster,_T("pictures\\303.jpg"),32,32);
				drawtext(_T("Slime King"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==310)
			{
				loadimage(&monster,_T("pictures\\310.jpg"),32,32);
				drawtext(_T("Small Bat"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==311)
			{
				loadimage(&monster,_T("pictures\\311.jpg"),32,32);
				drawtext(_T("Big Bat"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==312)
			{
				loadimage(&monster,_T("pictures\\312.jpg"),32,32);
				drawtext(_T("Red Bat"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==320)
			{
				loadimage(&monster,_T("pictures\\320.jpg"),32,32);
				drawtext(_T("Skeleton"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==321)
			{
				loadimage(&monster,_T("pictures\\321.jpg"),32,32);
				drawtext(_T("Armed Skeleton"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==322)
			{
				loadimage(&monster,_T("pictures\\322.jpg"),32,32);
				drawtext(_T("Captain Skeleton"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==330)
			{
				loadimage(&monster,_T("pictures\\330.jpg"),32,32);
				drawtext(_T("Blue Witch"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==331)
			{
				loadimage(&monster,_T("pictures\\331.jpg"),32,32);
				drawtext(_T("Yellow Witch"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==332)
			{
				loadimage(&monster,_T("pictures\\332.jpg"),32,32);
				drawtext(_T("Red Witch"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==340)
			{
				loadimage(&monster,_T("pictures\\340.jpg"),32,32);
				drawtext(_T("Yellow Guard"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==341)
			{
				loadimage(&monster,_T("pictures\\341.jpg"),32,32);
				drawtext(_T("Blue Guard"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==342)
			{
				loadimage(&monster,_T("pictures\\342.jpg"),32,32);
				drawtext(_T("Red Guard"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==350)
			{
				loadimage(&monster,_T("pictures\\350.jpg"),32,32);
				drawtext(_T("Orcish"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==351)
			{
				loadimage(&monster,_T("pictures\\351.jpg"),32,32);
				drawtext(_T("Armed Orcish"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==360)
			{
				loadimage(&monster,_T("pictures\\360.jpg"),32,32);
				drawtext(_T("Yellow Knight"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==361)
			{
				loadimage(&monster,_T("pictures\\361.jpg"),32,32);
				drawtext(_T("Red Knight"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==362)
			{
				loadimage(&monster,_T("pictures\\362.jpg"),32,32);
				drawtext(_T("Double Swords Knight"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==370)
			{
				loadimage(&monster,_T("pictures\\370.jpg"),32,32);
				drawtext(_T("Enchanter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==371)
			{
				loadimage(&monster,_T("pictures\\371.jpg"),32,32);
				drawtext(_T("Black Enchanter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==380)
			{
				loadimage(&monster,_T("pictures\\380.jpg"),32,32);
				drawtext(_T("Yellow Stone Fighter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==381)
			{
				loadimage(&monster,_T("pictures\\381.jpg"),32,32);
				drawtext(_T("Black Stone Fighter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==390)
			{
				loadimage(&monster,_T("pictures\\390.jpg"),32,32);
				drawtext(_T("Green Shadow"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==391)
			{
				loadimage(&monster,_T("pictures\\391.jpg"),32,32);
				drawtext(_T("Gray Shadow"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==392)
			{
				loadimage(&monster,_T("pictures\\392.jpg"),32,32);
				drawtext(_T("Green Shadow Fighter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==393)
			{
				loadimage(&monster,_T("pictures\\393.jpg"),32,32);
				drawtext(_T("Gray Shadow Fighter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==400)
			{
				loadimage(&monster,_T("pictures\\401.jpg"),32,32);
				drawtext(_T("Holy Warrior"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==401)
			{
				loadimage(&monster,_T("pictures\\402.jpg"),32,32);
				drawtext(_T("Yellow Holy Warrior"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==402)
			{
				loadimage(&monster,_T("pictures\\403.jpg"),32,32);
				drawtext(_T("Holy Swordsman"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==403)
			{
				loadimage(&monster,_T("pictures\\410.jpg"),32,32);
				drawtext(_T("Yellow Holy Swordsman"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==410)
			{
				loadimage(&monster,_T("pictures\\410.jpg"),32,32);
				drawtext(_T("Dragon Warrior"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else if (ID==411)
			{
				loadimage(&monster,_T("pictures\\411.jpg"),32,32);
				drawtext(_T("Dragon Enchanter"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

			}
			else if (ID==412)
			{
				loadimage(&monster,_T("pictures\\412.jpg"),32,32);
				drawtext(_T("Dragon King"),&namerect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}
			else
			{
				exit = 1;
			}

			if (exit == 0)
			{
				putimage(156,34+n*100,&monster);

				int monsterAttack = getMonsterAttack(ID);
				int monsterDefense = getMonsterDefense(ID);
				int monsterHealth = getMonsterHealth(ID);
				TCHAR strhealth[10];
				_stprintf(strhealth,TEXT("%d"),monsterHealth);
				drawtext(strhealth,&healthrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				TCHAR strattack[10];
				_stprintf(strattack,TEXT("%d"),monsterAttack);
				drawtext(strattack,&attackrect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				TCHAR strdefense[10];
				_stprintf(strdefense,TEXT("%d"),monsterDefense);
				drawtext(strdefense,&defenserect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

				int estimation = 0;
				if (Attack <= monsterDefense)
					estimation = -1;
				else if (monsterAttack <=Defense)
					estimation = 0;
				else if (Attack > monsterDefense && monsterAttack > Defense)
				{
					if (monsterHealth%(Attack - monsterDefense) == 0)
						estimation = (monsterAttack - Defense)*(monsterHealth/(Attack - monsterDefense)-1);
					else
						estimation = (monsterAttack - Defense)*(monsterHealth/(Attack - monsterDefense));
				}

				if (estimation >= 0)
				{
					TCHAR strestimation[10];
					_stprintf(strestimation,TEXT("%d"),estimation);
					drawtext(strestimation,&estimaterect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				}
				else if (estimation = -1)
				{
					drawtext(_T("???"),&estimaterect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				}
			}
			RECT previousRect = {200,500,300,544};
			RECT nextRect = {400,500,500,544};
			RECT exitRect = {600,500,700,544};
			drawtext(_T("Previous Page"),&previousRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Next Page"),&nextRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Exit"),&exitRect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			RECT name = {200,0,350,50};
			RECT health = {340,0,400,50};
			RECT attack = {400,0,460,50};
			RECT defense = {460,0,520,50};
			RECT special = {520,0,620,50};
			RECT estimate = {620,0,700,50};
			drawtext(_T("Name"),&name,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Health"),&health,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Attack"),&attack,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Defense"),&defense,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Special"),&special,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			drawtext(_T("Estimation"),&estimate,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

			MOUSEMSG m;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN && m.x <= 300 && m.x >= 200 && m.y <= 544 && m.y >= 500 && page >= 1)
				page -= 1;
			if (m.uMsg == WM_LBUTTONDOWN && m.x <= 500 && m.x >= 400 && m.y <= 544 && m.y >= 500 && page <= (99-n0)/5)
				page += 1;
			if (m.uMsg == WM_LBUTTONDOWN && m.x <= 700 && m.x >= 600 && m.y <= 544 && m.y >= 500)
			{
				exit = 1;
				display(z);
				break;
			}
		}

	}



}
