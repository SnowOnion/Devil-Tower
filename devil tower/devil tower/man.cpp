#include <math.h>
#include <graphics.h>
#include <conio.h>

extern int Health = 1000;                                  //血量
extern int Attack = 10;                                    //攻击力
extern int Defense = 10;                                   //防御力
extern int Agility = 1;                                    //敏捷度
extern int DodgeProbability;
extern bool HasTransfer = false;                           //有跳楼层神器
extern bool HasDictionary = false;                         //有怪物宝典
extern int YellowKey = 0;                                  //黄钥匙数目
extern int BlueKey = 0;                                    //蓝钥匙数目
extern int RedKey = 0;                                     //红钥匙数目
extern int yman;                                           //英雄的y坐标
extern int xman;                                           //英雄的x坐标
extern int z = 0;                                          //英雄所在的楼层数
extern int Money = 0;                                      //金钱数
extern int Experience = 0;                                 //经验数
extern int level = 1;                                      //等级数


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
    DodgeProbablity = (int)(10 * sqrt(Agility));
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
    map[z][x][y] = ID;
}

void move (int z)
{
	char c;
	if (kbhit())
		c=_getch();
    switch (c)
    {
        case 'w':
            if (yman+1 <= 16)
            {
                SetMap(z,xman,yman,101);
                if (map[z][xman][yman+1] == 0)                                            //前方是空地
                {
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman+1] >= 300)&&(map[z][xman][yman+1] <= 500))        //前方是怪物
                {
                    fight(map[z][xman][yman+1]);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman+1] >= 200)&&(map[z][xman][yman+1] <= 299))         //前方是宝石，血药
                {
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
                    yman += 1;
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman+1] >= 2)&&(map[z][xman][yman+1] <=4 ))         //前方是门
                {
                    if ((map[z][xman][yman+1] == 2)&&(YellowKey>0))                          //黄门
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman][yman+1] == 3)&&(BlueKey>0))                       //蓝门
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman][yman+1] == 4)&&(RedKey>0))                        //红门
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman+1] == 209)                                          //跳层道具
                {
                    HasTransfer = true;
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 210)                                          //字典
                {
                    HasDictionary = true;
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 211)                                           //大金币
                {
                    AddMoney(100);
                    yman += 1;
                    SetMap(z,xman,yman,101);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman+1] == 10)                                             //花钱商店
                {
                    MoneyPurchase();
                }
                else if (map[z][xman][yman+1] == 11)                                             //经验商店
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman][yman+1] == 8)                                              //上楼
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman+1] == 9)                                                //下楼
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
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
                    TalkPrincess();
                }
                else if (map[z][xman][yman+1] == 107)                                            //与Boss谈话
                {
                    TalkBoss();
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


        case 's':
            if (yman-1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman][yman-1] == 0)                                            //前方是空地
                {
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman-1] >= 300)&&(map[z][xman][yman-1] <= 500))        //前方是怪物
                {
                    fight(map[z][xman][yman-1]);
                    SetMap(z,xman,yman-1,0);
                }
                else if ((map[z][xman][yman-1] >= 200)&&(map[z][xman][yman-1] <= 299))         //前方是宝石，血药
                {
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
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if ((map[z][xman][yman-1] >= 2)&&(map[z][xman][yman-1] <=4 ))         //前方是门
                {
                    if ((map[z][xman][yman-1] == 2)&&(YellowKey>0))                          //黄门
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman][yman-1] == 3)&&(BlueKey>0))                       //蓝门
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman][yman-1] == 4)&&(RedKey>0))                        //红门
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman-1] == 209)                                          //跳层道具
                {
                    HasTransfer = true;
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman-1] == 210)                                          //字典
                {
                    HasDictionary = true;
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman+1,0);
                }
                else if (map[z][xman][yman-1] == 211)                                           //大金币
                {
                    AddMoney(100);
                    yman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman,yman-1,0);
                }
                else if (map[z][xman][yman-1] == 10)                                             //花钱商店
                {
                    MoneyPurchase();
                }
                else if (map[z][xman][yman-1] == 11)                                             //经验商店
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman][yman-1] == 8)                                              //上楼
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman][yman-1] == 9)                                               //下楼
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
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
                    TalkPrincess();
                }
                else if (map[z][xman][yman+1] == 107)                                            //与Boss谈话
                {
                    TalkBoss();
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



        case 'a':
            if (xman-1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman-1][yman] == 0)                                            //前方是空地
                {
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 300)&&(map[z][xman-1][yman] <= 500))        //前方是怪物
                {
                    fight(map[z][xman-1][yman]);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 200)&&(map[z][xman-1][yman] <= 299))         //前方是宝石，血药
                {
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
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman-1][yman] >= 2)&&(map[z][xman-1][yman] <=4 ))         //前方是门
                {
                    if ((map[z][xman-1][yman] == 2)&&(YellowKey>0))                          //黄门
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman-1][yman] == 3)&&(BlueKey>0))                       //蓝门
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman-1][yman] == 4)&&(RedKey>0))                        //红门
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman-1][yman] == 209)                                          //跳层道具
                {
                    HasTransfer = true;
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman-1][yman] == 210)                                          //字典
                {
                    HasDictionary = true;
                    xman -= 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman-1][yman] == 211)                                           //大金币
                {
                    AddMoney(100);
                    xman -= 1;
                    SetMap(z,xman-1,yman,100);
                    SetMap(z,xman,yman,0);
                }
                else if (map[z][xman-1][yman] == 10)                                             //花钱商店
                {
                    MoneyPurchase();
                }
                else if (map[z][xman-1][yman] == 11)                                             //经验商店
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman-1][yman] == 8)                                              //上楼
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman-1][yman] == 9)                                               //下楼
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
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
                    TalkPrincess();
                }
                else if (map[z][xman-1][yman] == 107)                                            //与Boss谈话
                {
                    TalkBoss();
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



        case 'd':
            if (xman+1 >= 0)
            {
                SetMap(z,xman,yman,100);
                if (map[z][xman+1][yman] == 0)                                            //前方是空地
                {
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 300)&&(map[z][xman+1][yman] <= 500))        //前方是怪物
                {
                    fight(map[z][xman+1][yman]);
                    SetMap(z,xman+1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 200)&&(map[z][xman+1][yman] <= 299))         //前方是宝石，血药
                {
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
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if ((map[z][xman+1][yman] >= 2)&&(map[z][xman+1][yman] <=4 ))         //前方是门
                {
                    if ((map[z][xman+1][yman] == 2)&&(YellowKey>0))                          //黄门
                    {
                        YellowKey -= 1;
                    }
                    else if ((map[z][xman+1][yman] == 3)&&(BlueKey>0))                       //蓝门
                    {
                        BlueKey -= 1;
                    }
                    else if ((map[z][xman+1][yman] == 4)&&(RedKey>0))                        //红门
                    {
                        RedKey -= 1;
                    }
                    SetMap(z,xman+1,yman,0);
                }
                else if (map[z][xman+1][yman] == 209)                                          //跳层道具
                {
                    HasTransfer = true;
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman+1][yman] == 210)                                          //字典
                {
                    HasDictionary = true;
                    xman += 1;
                    SetMap(z,xman,yman,100);
                    SetMap(z,xman-1,yman,0);
                }
                else if (map[z][xman+1][yman] == 211)                                           //大金币
                {
                    AddMoney(100);
                    xman += 1;
                    SetMap(z,xman+1,yman,100);
                    SetMap(z,xman,yman,0);
                }
                else if (map[z][xman+1][yman] == 10)                                             //花钱商店
                {
                    MoneyPurchase();
                }
                else if (map[z][xman+1][yman] == 11)                                             //经验商店
                {
                    ExperiencePurchase();
                }
                else if (map[z][xman+1][yman] == 8)                                              //上楼
                {
                    z += 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 9)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
                }
                else if (map[z][xman+1][yman] == 9)                                               //下楼
                {
                    z -= 1;
                    int i=0,j=0;
                    for (i = 0;i <= 16;i++)
                    {
                        for (j = 0;j <= 16;j++)
                        {
                            if (map[z][i][j] == 10)
                            {
                                xman = i;
                                yman = j;
                                i = 17;
                                j = 17;
                            }
                        }
                    }
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
                    TalkPrincess();
                }
                else if (map[z][xman+1][yman] == 107)                                            //与Boss谈话
                {
                    TalkBoss();
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
    }
}
