#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "purchase.h"
#include "map.h"
#include "display.h"
#include "man.h"
#include "talk.h"

int Health = 1000;                                  //血量
int Attack = 10;                                    //攻击力
int Defense = 10;                                   //防御力
float Agility = 1.0;                                //敏捷度
float DodgeProbability;
bool HasTransfer = false;                           //有跳楼层神器
bool HasDictionary = false;                         //有怪物宝典
int YellowKey = 0;                                  //黄钥匙数目
int BlueKey = 0;                                    //蓝钥匙数目
int RedKey = 0;                                     //红钥匙数目
int yman=0;                                         //英雄的y坐标
int xman=8;                                         //英雄的x坐标
int z = 1;                                          //英雄所在的楼层数
int Money = 0;                                      //金钱数
int Experience = 0;                                 //经验数
int Level = 1;                                      //等级数
int zmax = 1;
extern int map[25][17][17];

void AddAttack (int Increment)
{
	Attack += Increment;
}

void AddDefense (int Increment)
{
	Defense += Increment;
}

void AddHealth (int Increment)
{
	Health += Increment;
}

void AddAgility (int Increment)
{
	Agility += Increment;
	DodgeProbability = 10 * sqrt(Agility);
}

void AddMoney (int Increment)
{
	Money += Increment;
}

void AddExperience (int Increment)
{
	Experience += Increment;
}

void SetMap (int z,int x,int y,int ID)
{
	*(*(*(map+z)+x)+y) = ID;
}

void move ()
{
	char c='.';
	while(!kbhit());
	c=getch();
	switch (c)
	{
	case 's':
		if (yman+1 <= 16)
		{
			SetMap(z,xman,yman,100);
			if (map[z][xman][yman+1] == 1)                                            //前方是空地
			{
				yman += 1;
				SetMap(z,xman,yman,100);
				SetMap(z,xman,yman-1,1);
			}
			else if ((map[z][xman][yman+1] >= 300)&&(map[z][xman][yman+1] <= 500))        //前方是怪物
			{
				fight(map[z][xman][yman+1]);
				SetMap(z,xman,yman+1,1);
			}
			else if ((map[z][xman][yman+1] >= 200)&&(map[z][xman][yman+1] <= 299))         //前方是宝石，血药
			{
				if(map[z][xman][yman+1] == 200)
				{
					YellowKey +=1;                                                       //黄钥匙  
				}
				else if (map[z][xman][yman+1] == 201)
				{
					BlueKey +=1;                                    					//蓝钥匙 
				}
				else if (map[z][xman][yman+1] == 202)
				{
					RedKey +=1;															//红钥匙 
				}
				if(map[z][xman][yman+1] == 206)                                           //小血瓶
				{
					AddHealth(200);
				}
				else if(map[z][xman][yman+1] == 207)                                      //中血瓶
				{
					AddHealth(500);
				}
				else if(map[z][xman][yman+1] == 208)                                      //大血瓶
				{
					AddHealth(1000);
				}
				else if(map[z][xman][yman+1] == 203)                                      //攻击宝石，红宝石
				{
					AddAttack(3);
				}
				else if(map[z][xman][yman+1] == 204)                                      //防御宝石，蓝宝石
				{
					AddDefense(3);
				}
				else if(map[z][xman][yman+1] == 205)                                      //敏捷宝石，绿宝石
				{
					AddAgility(1);
				}
				else if (map[z][xman][yman+1] == 209)                                          //跳层道具
				{
					HasTransfer = true;
				}
				else if (map[z][xman][yman+1] == 210)                                          //字典
				{
					HasDictionary = true;
				}
				else if (map[z][xman][yman+1] == 211)                                           //大金币
				{
					AddMoney(100);
				}
				yman += 1;
				SetMap(z,xman,yman,100);
				SetMap(z,xman,yman-1,1);
			}
			else if ((map[z][xman][yman+1] >= 2)&&(map[z][xman][yman+1] <=4 ))         //前方是门
			{
				if ((map[z][xman][yman+1] == 2)&&(YellowKey>0))                          //黄门
				{
					YellowKey -= 1;
					SetMap(z,xman,yman+1,1);
				}
				else if ((map[z][xman][yman+1] == 3)&&(BlueKey>0))                       //蓝门
				{
					BlueKey -= 1;
					SetMap(z,xman,yman+1,1);
				}
				else if ((map[z][xman][yman+1] == 4)&&(RedKey>0))                        //红门
				{
					RedKey -= 1;
					SetMap(z,xman,yman+1,1);
				}
			}
			else if (map[z][xman][yman+1] == 10 || map[z][xman - 1][yman + 1] == 10 ||map[z][xman - 2][yman + 1] == 10)                                             //花钱商店
			{
				MoneyPurchase(z);
			}
			else if (map[z][xman][yman+1] == 11 || map[z][xman - 1][yman + 1] == 11 ||map[z][xman - 2][yman + 1] == 11)                                             //经验商店
			{
				ExperiencePurchase(z);
			}
			else if (map[z][xman][yman+1] == 8)                                              //上楼
			{
				z += 1;
				SetMap(z-1,xman,yman,1);
				if (z == 2)
				{
					xman = 8;
					yman = 15;	
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 4)
				{
					xman = 8;
					yman = 7;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 6)
				{
					xman = 1;
					yman = 16;
				}
				else if (z == 7)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 9)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 10)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 11)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 12)
				{
					xman = 15;
					yman = 0;
				}
				else if (z == 13)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 1;
					yman = 7;
				}
				SetMap(z,xman,yman,100);
				if (z > zmax)
					zmax = z;
			}
			else if (map[z][xman][yman+1] == 9)                                                //下楼
			{
				z -= 1;
				SetMap(z+1,xman,yman,1);
				if (z == 1)
				{
					xman = 8;
					yman = 15;
				}
				else if (z == 2)
				{
					xman = 8;
					yman = 1;
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 4)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 6)
				{
					xman = 9;
					yman = 1;
				}
				else if (z == 7)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 15;
					yman = 13;
				}
				else if (z == 9)
				{
					xman = 16;
					yman = 1;
				}
				else if (z == 10)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 11)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 12)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 13)
				{
					xman = 14;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 15;
					yman = 8;
				}
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman][yman+1] == 104)                                            //与白发老人讲话
			{
				TalkElder(z);
			}
			else if (map[z][xman][yman+1] == 105)                                            //与商人谈话
			{
				TalkMerchant(z);
			}
			else if (map[z][xman][yman+1] == 106)                                            //与公主谈话
			{
				TalkPrincess(z);
			}
			else if (map[z][xman][yman+1] == 107)                                            //与Boss谈话
			{
				TalkBoss(z);
			}
			else
			{
				SetMap(z,xman,yman,100);
			}
		}
		else
		{
			SetMap(z,xman,yman,100);
		}
		display(z);
		break;


	case 'w':
		if (yman-1 >= 0)
		{
			SetMap(z,xman,yman,101);
			if (map[z][xman][yman-1] == 1)                                            //前方是空地
			{
				yman -= 1;
				SetMap(z,xman,yman,101);
				SetMap(z,xman,yman+1,1);
			}
			else if ((map[z][xman][yman-1] >= 300)&&(map[z][xman][yman-1] <= 500))        //前方是怪物
			{
				fight(map[z][xman][yman-1]);
				SetMap(z,xman,yman-1,1);
			}
			else if ((map[z][xman][yman-1] >= 200)&&(map[z][xman][yman-1] <= 299))         //前方是宝石，血药
			{
				if(map[z][xman][yman-1] == 200)
				{
					YellowKey +=1;                                                       //黄钥匙  
				}
				else if (map[z][xman][yman-1] == 201)
				{
					BlueKey +=1;                                    					//蓝钥匙 
				}
				else if (map[z][xman][yman-1] == 202)
				{
					RedKey +=1;															//红钥匙 
				}
				if(map[z][xman][yman-1] == 206)                                           //小血瓶
				{
					AddHealth(200);
				}
				else if(map[z][xman][yman-1] == 207)                                      //中血瓶
				{
					AddHealth(500);
				}
				else if(map[z][xman][yman-1] == 208)                                      //大血瓶
				{
					AddHealth(1000);
				}
				else if(map[z][xman][yman-1] == 203)                                      //攻击宝石，红宝石
				{
					AddAttack(3);
				}
				else if(map[z][xman][yman-1] == 204)                                      //防御宝石，蓝宝石
				{
					AddDefense(3);
				}
				else if(map[z][xman][yman-1] == 205)                                      //敏捷宝石，绿宝石
				{
					AddAgility(1);
				}
				else if (map[z][xman][yman-1] == 209)                                          //跳层道具
				{
					HasTransfer = true;
				}
				else if (map[z][xman][yman-1] == 210)                                          //字典
				{
					HasDictionary = true;
				}
				else if (map[z][xman][yman-1] == 211)                                           //大金币
				{
					AddMoney(100);
				}
				yman -= 1;
				SetMap(z,xman,yman,101);
				SetMap(z,xman,yman+1,1);
			}
			else if ((map[z][xman][yman-1] >= 2)&&(map[z][xman][yman-1] <=4 ))         //前方是门
			{
				if ((map[z][xman][yman-1] == 2)&&(YellowKey>0))                          //黄门
				{
					YellowKey -= 1;
					SetMap(z,xman,yman-1,1);
				}
				else if ((map[z][xman][yman-1] == 3)&&(BlueKey>0))                       //蓝门
				{
					BlueKey -= 1;
					SetMap(z,xman,yman-1,1);
				}
				else if ((map[z][xman][yman-1] == 4)&&(RedKey>0))                        //红门
				{
					RedKey -= 1;
					SetMap(z,xman,yman-1,1);
				}
			}
			else if (map[z][xman][yman-1] == 10 || map[z][xman-1][yman-1] == 10 || map[z][xman-2][yman-1] == 10)                                             //花钱商店
			{
				MoneyPurchase(z);
			}
			else if (map[z][xman][yman-1] == 11 || map[z][xman-1][yman-1] == 11 || map[z][xman-2][yman-1] == 11)                                             //经验商店
			{
				ExperiencePurchase(z);
			}
			else if (map[z][xman][yman-1] == 8)                                              //上楼
			{
				z += 1;
				SetMap(z-1,xman,yman,1);
				if (z == 2)
				{
					xman = 8;
					yman = 15;	
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 4)
				{
					xman = 8;
					yman = 7;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 6)
				{
					xman = 1;
					yman = 16;
				}
				else if (z == 7)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 9)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 10)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 11)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 12)
				{
					xman = 15;
					yman = 0;
				}
				else if (z == 13)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 1;
					yman = 7;
				}
				if (z > zmax)
					zmax = z;
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman][yman-1] == 9)                                                //下楼
			{
				z -= 1;
				SetMap(z+1,xman,yman,1);
				if (z == 1)
				{
					xman = 8;
					yman = 15;
				}
				else if (z == 2)
				{
					xman = 8;
					yman = 1;
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 4)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 6)
				{
					xman = 9;
					yman = 1;
				}
				else if (z == 7)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 15;
					yman = 13;
				}
				else if (z == 9)
				{
					xman = 16;
					yman = 1;
				}
				else if (z == 10)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 11)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 12)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 13)
				{
					xman = 14;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 15;
					yman = 8;
				}
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman][yman-1] == 104)                                            //与白发老人讲话
			{
				TalkElder(z);
			}
			else if (map[z][xman][yman-1] == 105)                                            //与商人谈话
			{
				TalkMerchant(z);
			}
			else if (map[z][xman][yman-1] == 106)                                            //与公主谈话
			{
				TalkPrincess(z);
			}
			else if (map[z][xman][yman-1] == 107)                                            //与Boss谈话
			{
				TalkBoss(z);
			}
			else
			{
				SetMap(z,xman,yman,101);
			}
		}
		else
		{
			SetMap(z,xman,yman,101);
		}
		display(z);
		break;



	case 'a':
		if (xman-1 >= 0)
		{
			SetMap(z,xman,yman,102);
			if (map[z][xman-1][yman] == 1)                                            //前方是空地
			{
				xman -= 1;
				SetMap(z,xman,yman,102);
				SetMap(z,xman+1,yman,1);
			}
			else if ((map[z][xman-1][yman] >= 300)&&(map[z][xman-1][yman] <= 500))        //前方是怪物
			{
				fight(map[z][xman-1][yman]);
				SetMap(z,xman-1,yman,1);
			}
			else if ((map[z][xman-1][yman] >= 200)&&(map[z][xman-1][yman] <= 299))         //前方是宝石，血药
			{
				if(map[z][xman-1][yman] == 200)
				{
					YellowKey +=1;                                                       //黄钥匙  
				}
				else if (map[z][xman-1][yman] == 201)
				{
					BlueKey +=1;                                    					//蓝钥匙 
				}
				else if (map[z][xman-1][yman] == 202)
				{
					RedKey +=1;															//红钥匙 
				}
				if(map[z][xman-1][yman] == 206)                                           //小血瓶
				{
					AddHealth(200);
				}
				else if(map[z][xman-1][yman] == 207)                                      //中血瓶
				{
					AddHealth(500);
				}
				else if(map[z][xman-1][yman] == 208)                                      //大血瓶
				{
					AddHealth(1000);
				}
				else if(map[z][xman-1][yman] == 203)                                      //攻击宝石，红宝石
				{
					AddAttack(3);
				}
				else if(map[z][xman-1][yman] == 204)                                      //防御宝石，蓝宝石
				{
					AddDefense(3);
				}
				else if(map[z][xman-1][yman] == 205)                                      //敏捷宝石，绿宝石
				{
					AddAgility(1);
				}
				else if (map[z][xman-1][yman] == 209)                                          //跳层道具
				{
					HasTransfer = true;
				}
				else if (map[z][xman-1][yman] == 210)                                          //字典
				{
					HasDictionary = true;
				}
				else if (map[z][xman-1][yman] == 211)                                           //大金币
				{
					AddMoney(100);
				}
				xman -= 1;
				SetMap(z,xman,yman,102);
				SetMap(z,xman+1,yman,1);
			}
			else if ((map[z][xman-1][yman] >= 2)&&(map[z][xman-1][yman] <=4 ))         //前方是门
			{
				if ((map[z][xman-1][yman] == 2)&&(YellowKey>0))                          //黄门
				{
					YellowKey -= 1;
					SetMap(z,xman-1,yman,1);
				}
				else if ((map[z][xman-1][yman] == 3)&&(BlueKey>0))                       //蓝门
				{
					BlueKey -= 1;
					SetMap(z,xman-1,yman,1);
				}
				else if ((map[z][xman-1][yman] == 4)&&(RedKey>0))                        //红门
				{
					RedKey -= 1;
					SetMap(z,xman-1,yman,1);
				}
			}
			else if (map[z][xman-1][yman] == 10 || map[z][xman - 2][yman] == 10 ||map[z][xman - 3][yman] == 10)                                             //花钱商店
			{
				MoneyPurchase(z);
			}
			else if (map[z][xman-1][yman] == 11 || map[z][xman - 2][yman] == 11 ||map[z][xman - 3][yman] == 11)                                             //经验商店
			{
				ExperiencePurchase(z);
			}
			else if (map[z][xman-1][yman] == 8)                                              //上楼
			{
				z += 1;
				SetMap(z-1,xman,yman,1);
				if (z == 2)
				{
					xman = 8;
					yman = 15;	
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 4)
				{
					xman = 8;
					yman = 7;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 6)
				{
					xman = 1;
					yman = 16;
				}
				else if (z == 7)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 9)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 10)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 11)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 12)
				{
					xman = 15;
					yman = 0;
				}
				else if (z == 13)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 1;
					yman = 7;
				}
				if (z > zmax)
					zmax = z;
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman-1][yman] == 9)                                                //下楼
			{
				z -= 1;
				SetMap(z+1,xman,yman,1);
				if (z == 1)
				{
					xman = 8;
					yman = 15;
				}
				else if (z == 2)
				{
					xman = 8;
					yman = 1;
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 4)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 6)
				{
					xman = 9;
					yman = 1;
				}
				else if (z == 7)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 15;
					yman = 13;
				}
				else if (z == 9)
				{
					xman = 16;
					yman = 1;
				}
				else if (z == 10)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 11)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 12)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 13)
				{
					xman = 14;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 15;
					yman = 8;
				}
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman-1][yman] == 104)                                            //与白发老人讲话
			{
				TalkElder(z);
			}
			else if (map[z][xman-1][yman] == 105)                                            //与商人谈话
			{
				TalkMerchant(z);
			}
			else if (map[z][xman-1][yman] == 106)                                            //与公主谈话
			{
				TalkPrincess(z);
			}
			else if (map[z][xman-1][yman] == 107)                                            //与Boss谈话
			{
				TalkBoss(z);
			}
			else
			{
				SetMap(z,xman,yman,102);
			}
		}
		else
		{
			SetMap(z,xman,yman,102);
		}
		display(z);
		break;



	case 'd':
		if (xman+1 <= 16)
		{
			SetMap(z,xman,yman,103);
			if (map[z][xman+1][yman] == 1)                                            //前方是空地
			{
				xman += 1;
				SetMap(z,xman,yman,103);
				SetMap(z,xman-1,yman,1);
			}
			else if ((map[z][xman+1][yman] >= 300)&&(map[z][xman+1][yman] <= 500))        //前方是怪物
			{
				fight(map[z][xman+1][yman]);
				SetMap(z,xman+1,yman,1);
			}
			else if ((map[z][xman+1][yman] >= 200)&&(map[z][xman+1][yman] <= 299))         //前方是宝石，血药
			{
				if(map[z][xman+1][yman] == 200)
				{
					YellowKey +=1;                                                       //黄钥匙  
				}
				else if (map[z][xman+1][yman] == 201)
				{
					BlueKey +=1;                                    					//蓝钥匙 
				}
				else if (map[z][xman+1][yman] == 202)
				{
					RedKey +=1;															//红钥匙 
				}
				if(map[z][xman+1][yman] == 206)                                           //小血瓶
				{
					AddHealth(200);
				}
				else if(map[z][xman+1][yman] == 207)                                      //中血瓶
				{
					AddHealth(500);
				}
				else if(map[z][xman+1][yman] == 208)                                      //大血瓶
				{
					AddHealth(1000);
				}
				else if(map[z][xman+1][yman] == 203)                                      //攻击宝石，红宝石
				{
					AddAttack(3);
				}
				else if(map[z][xman+1][yman] == 204)                                      //防御宝石，蓝宝石
				{
					AddDefense(3);
				}
				else if(map[z][xman+1][yman] == 205)                                      //敏捷宝石，绿宝石
				{
					AddAgility(1);
				}
				else if (map[z][xman+1][yman] == 209)                                          //跳层道具
				{
					HasTransfer = true;
				}
				else if (map[z][xman+1][yman] == 210)                                          //字典
				{
					HasDictionary = true;
				}
				else if (map[z][xman+1][yman] == 211)                                           //大金币
				{
					AddMoney(100);
				}
				xman += 1;
				SetMap(z,xman,yman,103);
				SetMap(z,xman-1,yman,1);
			}
			else if ((map[z][xman+1][yman] >= 2)&&(map[z][xman+1][yman] <=4 ))         //前方是门
			{
				if ((map[z][xman+1][yman] == 2)&&(YellowKey>0))                          //黄门
				{
					YellowKey -= 1;
					SetMap(z,xman+1,yman,1);
				}
				else if ((map[z][xman+1][yman] == 3)&&(BlueKey>0))                       //蓝门
				{
					BlueKey -= 1;
					SetMap(z,xman+1,yman,1);
				}
				else if ((map[z][xman+1][yman] == 4)&&(RedKey>0))                        //红门
				{
					RedKey -= 1;
					SetMap(z,xman+1,yman,1);
				}
			}
			else if (map[z][xman+1][yman] == 10 || map[z][xman + 2][yman] == 10 ||map[z][xman + 3][yman] == 10)                                           //花钱商店
			{
				MoneyPurchase(z);
			}
			else if (map[z][xman+1][yman] == 10 || map[z][xman + 2][yman] == 10 ||map[z][xman + 3][yman] == 10)                                           //经验商店
			{
				ExperiencePurchase(z);
			}
			else if (map[z][xman+1][yman] == 8)                                              //上楼
			{
				z += 1;
				SetMap(z-1,xman,yman,1);
				if (z == 2)
				{
					xman = 8;
					yman = 15;	
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 4)
				{
					xman = 8;
					yman = 7;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 6)
				{
					xman = 1;
					yman = 16;
				}
				else if (z == 7)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 9)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 10)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 11)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 12)
				{
					xman = 15;
					yman = 0;
				}
				else if (z == 13)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 1;
					yman = 7;
				}
				if (z > zmax)
					zmax = z;
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman+1][yman] == 9)                                                //下楼
			{
				z -= 1;
				SetMap(z+1,xman,yman,1);
				if (z == 1)
				{
					xman = 8;
					yman = 15;
				}
				else if (z == 2)
				{
					xman = 8;
					yman = 1;
				}
				else if (z == 3)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 4)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 5)
				{
					xman = 0;
					yman = 15;
				}
				else if (z == 6)
				{
					xman = 9;
					yman = 1;
				}
				else if (z == 7)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 8)
				{
					xman = 15;
					yman = 13;
				}
				else if (z == 9)
				{
					xman = 16;
					yman = 1;
				}
				else if (z == 10)
				{
					xman = 1;
					yman = 0;
				}
				else if (z == 11)
				{
					xman = 0;
					yman = 1;
				}
				else if (z == 12)
				{
					xman = 16;
					yman = 15;
				}
				else if (z == 13)
				{
					xman = 14;
					yman = 15;
				}
				else if (z == 14)
				{
					xman = 15;
					yman = 8;
				}
				SetMap(z,xman,yman,100);
			}
			else if (map[z][xman+1][yman] == 104)                                            //与白发老人讲话
			{
				TalkElder(z);
			}
			else if (map[z][xman+1][yman] == 105)                                            //与商人谈话
			{
				TalkMerchant(z);
			}
			else if (map[z][xman+1][yman] == 106)                                            //与公主谈话
			{
				TalkPrincess(z);
			}
			else if (map[z][xman+1][yman] == 107)                                            //与Boss谈话
			{
				TalkBoss(z);
			}
			else
			{
				SetMap(z,xman,yman,103);
			}
		}
		else
		{
			SetMap(z,xman,yman,103);
		}
		display(z);
		break;

	default: break;
	}


}