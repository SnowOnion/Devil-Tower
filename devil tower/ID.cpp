/*
地形类
1   FLOOR               地板
0   WALL                墙壁
2   YELLOW DOOR         黄门
3   BLUE DOOR           蓝门
4   RED DOOR            红门
5   MAGIC DOOR          魔法门（需要特殊条件开启）
6   STAR                星空
7   LAVA                岩浆
8   STAIR UP             上楼梯
9   STAIR DOWN           下楼梯
10  MONEY STORE          花钱商店
11  EXPERIENCE STORE     经验商店




人物类
100  HERO1              英雄朝玩家
101  HERO2              英雄背向玩家
102  HERO3              英雄朝左
103  HERO4              英雄朝右
104  ELDER              白发老人
105  MERCHANT           商人
106  PRINCESS           公主
108  YYJ                BOSS
109  LZH                BOSS


道具类
200  YELLOW KEY          黄钥匙
201  BLUE KEY            蓝钥匙
202  RED KEY             红钥匙

203  RED GEM             红宝石
204  BLUE GEM            蓝宝石
205  GREEN GEM           绿宝石
206  SMALL ELIXER        小血瓶
207  MIDIUM ELIXER       中血瓶
208  LARGE ELIXER        大血瓶

209  TRANSFER            跳层道具
210  DICTIONARY          字典
211  BIG COIN            大金币

212 YELLOW KEY           界面用黄钥匙
213 BLUE KEY             界面用蓝钥匙
214 RED KEY              界面用红钥匙



怪物类
300  GREEN SLIME         绿色史莱姆
301  RED SLIME           红色史莱姆
302  BLACK SLIME         黑色史莱姆
303  SLIME KING          史莱姆王

310  SMALL BAT           小蝙蝠
311  BIG BAT             大蝙蝠
312  RED BAT             红蝙蝠

320  SKELETON            骷髅
321  ARMED SKELETON      骷髅士兵
322  CAPTAIN SKELETON    骷髅队长

330  BLUE WITCH          蓝色女巫
331  YELLOW WITCH        黄色女巫
332  RED WITCH           红色女巫

340  YELLOW GUARD        黄色守卫
341  BLUE GUARD          蓝色守卫
342  RED GUARD           红色守卫

350  ORCISH              兽人
351  ARMED ORCISH        兽人士兵

360  YELLOW KNIGHT       黄骑士
361  RED KNIGHT          红骑士
362  DOUBLE SWORDS KNIGHT 双手剑士

370  ENCHANTER           魔法师 
371  BLACK ENCHANTER     黑魔法师 

380  YELLOW STONE FIGHTER黄石头人战士
381  BLACK STONE FIGHTER 黑石头人战士

390  GREEN SHADOW        绿影子
391  GRAY SHADOW         灰影子
392	 GREEN SHADOW FIGHTER 绿影子战士
393  GRAY SHADOW FIGHTER 灰影子战士

400  HOLY WARRIOR       圣战士
401  YELLOW HOLY WARRIOR 神圣战士
402  HOLY SWORDSMAN     圣武士
403  YELLOW HOLY SWORDSMAN神圣武士

410	 DRAGON WARRIOR      龙战士
411  DRAGON ENCHANTER    龙法师
412  DRAGON KING         龙王 
*/

extern int Attack;
extern int Defense;
#include "ID.h"
#include <string.h>
int getMonsterAttack(int ID)
{
	if (ID == 300)
		return 17;
	else if (ID == 301)
		return 22;
	else if (ID == 302)
		return 30;
	else if (ID == 303)
		return 100;
	else if (ID == 310)		
		return 50;
	else if (ID == 311)
		return 75;
	else if (ID == 312)
		return 150;
	else if (ID == 320)
		return 40;
	else if (ID == 321)
		return 80;
	else if (ID == 322)
		return 120;
	else if (ID == 330)
		return Defense + 15;
	else if (ID == 331)
		return Defense + 30;
	else if (ID == 332)
		return Defense + 50;
	else if (ID == 340)
		return 90;
	else if (ID == 341)
		return 180;
	else if (ID == 342)
		return 250;
	else if (ID == 350)
		return 120;
	else if (ID == 351)
		return 240;
	else if (ID == 360)
		return 0;
	else if (ID == 361)
		return 0;
	else if (ID == 362)
		return 0;
	else if (ID == 370)
		return Defense + 150;
	else if (ID == 371)
		return Defense + 300;
	else if (ID == 380)
		return 400;
	else if (ID == 381)
		return 550;
	else if (ID == 390)
		return 400;
	else if (ID == 391)
		return 500;
	else if (ID == 392)
		return 600;
	else if (ID == 393)
		return 700;
	else if (ID == 400)
		return 150;
	else if (ID == 401)
		return 600;
	else if (ID == 402)
		return 1200;
	else if (ID == 403)
		return 1500;
	else if (ID == 410)
		return 800;
	else if (ID == 411)
		return 1200;
	else if (ID == 412)
		return 1500;
	else if (ID == 108)
		return 2000;
	else if (ID == 109)
		return 1500;
}

int getMonsterDefense(int ID)
{
	if (ID == 300)
		return 5;
	else if (ID == 301)
		return 5;
	else if (ID == 302)
		return 10;
	else if (ID == 303)
		return 100;
	else if (ID == 310)		
		return 0;
	else if (ID == 311)
		return 0;
	else if (ID == 312)
		return 0;
	else if (ID == 320)
		return 20;
	else if (ID == 321)
		return 35;
	else if (ID == 322)
		return 50;
	else if (ID == 330)
		return 10;
	else if (ID == 331)
		return 20;
	else if (ID == 332)
		return 40;
	else if (ID == 340)
		return 40;
	else if (ID == 341)
		return 100;
	else if (ID == 342)
		return 150;
	else if (ID == 350)
		return 10;
	else if (ID == 351)
		return 50;
	else if (ID == 360)
		return 0;
	else if (ID == 361)
		return 0;
	else if (ID == 362)
		return 0;
	else if (ID == 370)
		return 50;
	else if (ID == 371)
		return 80;
	else if (ID == 380)
		return Attack-5;
	else if (ID == 381)
		return Attack-1;
	else if (ID == 390)
		return 300;
	else if (ID == 391)
		return 400;
	else if (ID == 392)
		return 500;
	else if (ID == 393)
		return 600;
	else if (ID == 400)
		return 50;
	else if (ID == 401)
		return 100;
	else if (ID == 402)
		return 200;
	else if (ID == 403)
		return 400;
	else if (ID == 410)
		return 500;
	else if (ID == 411)
		return 750;
	else if (ID == 412)
		return 1000;
	else if (ID == 108)
		return 1500;
	else if (ID == 109)
		return 1200;
}

int getMonsterHealth(int ID)
{
		if (ID == 300)
		return 50;
	else if (ID == 301)
		return 80;
	else if (ID == 302)
		return 100;
	else if (ID == 303)
		return 500;
	else if (ID == 310)		
		return 200;
	else if (ID == 311)
		return 400;
	else if (ID == 312)
		return 1200;
	else if (ID == 320)
		return 125;
	else if (ID == 321)
		return 250;
	else if (ID == 322)
		return 500;
	else if (ID == 330)
		return 100;
	else if (ID == 331)
		return 200;
	else if (ID == 332)
		return 400;
	else if (ID == 340)
		return 500;
	else if (ID == 341)
		return 1000;
	else if (ID == 342)
		return 1500;
	else if (ID == 350)
		return 1000;
	else if (ID == 351)
		return 2000;
	else if (ID == 360)
		return 0;
	else if (ID == 361)
		return 0;
	else if (ID == 362)
		return 0;
	else if (ID == 370)
		return 800;
	else if (ID == 371)
		return 1000;
	else if (ID == 380)
		return 100;
	else if (ID == 381)
		return 120;
	else if (ID == 390)
		return 500;
	else if (ID == 391)
		return 800;
	else if (ID == 392)
		return 1000;
	else if (ID == 393)
		return 1500;
	else if (ID == 400)
		return 1000;
	else if (ID == 401)
		return 2000;
	else if (ID == 402)
		return 3000;
	else if (ID == 403)
		return 4000;
	else if (ID == 410)
		return 2000;
	else if (ID == 411)
		return 3500;
	else if (ID == 412)
		return 5000;
	else if (ID == 108)
		return 10000;
	else if (ID == 109)
		return 10000;
}

int getMoney(int ID)
{
	if (ID == 300)
		return 1;
	else if (ID == 301)
		return 2;
	else if (ID == 302)
		return 3;
	else if (ID == 303)
		return 20;
	else if (ID == 310)		
		return 5;
	else if (ID == 311)
		return 10;
	else if (ID == 312)
		return 20;
	else if (ID == 320)
		return 5;
	else if (ID == 321)
		return 10;
	else if (ID == 322)
		return 20;
	else if (ID == 330)
		return 5;
	else if (ID == 331)
		return 8;
	else if (ID == 332)
		return 15;
	else if (ID == 340)
		return 10;
	else if (ID == 341)
		return 25;
	else if (ID == 342)
		return 40;
	else if (ID == 350)
		return 20;
	else if (ID == 351)
		return 40;
	else if (ID == 360)
		return 0;
	else if (ID == 361)
		return 0;
	else if (ID == 362)
		return 0;
	else if (ID == 370)
		return 25;
	else if (ID == 371)
		return 30;
	else if (ID == 380)
		return 40;
	else if (ID == 381)
		return 60;
	else if (ID == 390)
		return 65;
	else if (ID == 391)
		return 75;
	else if (ID == 392)
		return 90;
	else if (ID == 393)
		return 110;
	else if (ID == 400)
		return 30;
	else if (ID == 401)
		return 70;
	else if (ID == 402)
		return 100;
	else if (ID == 403)
		return 140;
	else if (ID == 410)
		return 65;
	else if (ID == 411)
		return 110;
	else if (ID == 412)
		return 160;
	else if (ID == 108)
		return 2000;
	else if (ID == 109)
		return 1000;
}

int getExperience(int ID)
{
		if (ID == 300)
		return 1;
	else if (ID == 301)
		return 1;
	else if (ID == 302)
		return 2;
	else if (ID == 303)
		return 10;
	else if (ID == 310)		
		return 4;
	else if (ID == 311)
		return 5;
	else if (ID == 312)
		return 10;
	else if (ID == 320)
		return 4;
	else if (ID == 321)
		return 8;
	else if (ID == 322)
		return 15;
	else if (ID == 330)
		return 4;
	else if (ID == 331)
		return 5;
	else if (ID == 332)
		return 8;
	else if (ID == 340)
		return 8;
	else if (ID == 341)
		return 15;
	else if (ID == 342)
		return 25;
	else if (ID == 350)
		return 15;
	else if (ID == 351)
		return 25;
	else if (ID == 360)
		return 0;
	else if (ID == 361)
		return 0;
	else if (ID == 362)
		return 0;
	else if (ID == 370)
		return 15;
	else if (ID == 371)
		return 22;
	else if (ID == 380)
		return 30;
	else if (ID == 381)
		return 45;
	else if (ID == 390)
		return 35;
	else if (ID == 391)
		return 42;
	else if (ID == 392)
		return 50;
	else if (ID == 393)
		return 65;
	else if (ID == 400)
		return 20;
	else if (ID == 401)
		return 35;
	else if (ID == 402)
		return 50;
	else if (ID == 403)
		return 80;
	else if (ID == 410)
		return 50;
	else if (ID == 411)
		return 75;
	else if (ID == 412)
		return 100;
	else if (ID == 108)
		return 2000;
	else if (ID == 109)
		return 1000;
}
