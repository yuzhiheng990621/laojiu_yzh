#include "Shopping.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Commodity commodity[1000]={
 {1,"咸鱼王的叹息",200,"无动作时免疫所有异常状态",10}
,{2,"非洲人的愤怒",200,"所有非洲人欧气+1",10}
,{3,"神奇的绿帽",500,"使目标原谅一切",10}
,{4,"无敌恒爸爸",1000,"自身无敌一分钟",10}
,{5,"传火么?大兄弟",298,"解除咸鱼王的叹息Buff",10}
};
int count=5;
int playercount=0;
Player *players;
void Back()//输入回车返回
{
    printf("输入回车返回！\n\n");
    getchar();
    getchar();
}
void init()
{
static Player player[]={
{1,"龙辛少女",{1,.max=20,.sum=0},.money=5000,}
};
playercount=sizeof(player)/sizeof(Player);
players=player;
}



//商品信息
/*
    int id;//商品编号
    char *name;//商品名
    int price;//商品价格
    char *effect;//商品效果
*/
void showcommodity()
{
    int i;
    printf("已有商品:\n");
    for(i=0;i<count;i++)
    {
    printf("%d.%s\t价格:%d金\t库存:%d件\t效用:%s\n",commodity[i].id,commodity[i].name,commodity[i].price,commodity[i].sum,commodity[i].effect);
    }
}
void putcommodity()
{
    char f;
    do{
    count++;
printf("*********************************\n");
    printf("请输入商品信息\n");
    printf("商品%d\n",count);
    commodity[count-1].id=count;
    printf("    名称:");
    commodity[count-1].name=calloc(50,1);
    scanf("%s",commodity[count-1].name);
    printf("价格(金):");
    scanf("%d",&commodity[count-1].price);
    printf("商品效果:");
    commodity[count-1].effect=calloc(200,1);
    scanf("%s",commodity[count-1].effect);
    printf("商品初始库存:");
    scanf("%d",&commodity[count-1].sum);
printf("*********************************\n");
    printf("是否继续录入商品信息(y/n)?\n");
    f=getch();
    }while(f == 'y' || f== 'Y');
}
void showplayer()
{
    int i,j;
    if(players==NULL) return;
    printf("玩家:\n");
    for(i=0;i<playercount;i++)
    {
    printf("玩家:%d\t名称:%s\t钱币:%d金\n背包:\n",players[i].id,players[i].name,players[i].money);
        for(j=0;j<players->bag.sum;j++)
        {
            printf("%sX%d\t效果:%s\n",players->bag.playcommoditys[j].name,players->bag.playcommoditys[j].sum,players->bag.playcommoditys[j].effect);
        }
        if(j==0)
        {
            printf("空.\n");
        }
    }
}
void trade(Player *player)
{
    int i;
    int commodityID;
    int number;
    char f;
    do
    {
    showplayer();
    printf("请输入要购买的商品编号:");
    scanf("%d",&commodityID);
    printf("请输入要购买的数量:");
    scanf("%d",&number);
    //commodityID表示要购买的商品编号
    //判断：商品库存有没有，玩家的钱币够不够，玩家背包大小够不够
    Commodity *tradecommodity;//要购买的商品指针
    for(i=0;i<count;i++)
    {
        if(commodityID==commodity[i].id)
        {tradecommodity=&commodity[i];}//搜索并找到该商品
    }
    if((tradecommodity->sum)-number < 0)
    {
        printf("该商品库存不足！剩余%d件\n",tradecommodity->sum);
        Back();
        return;
    }
    if(player->money < (tradecommodity->price)*number)
    {
        printf("余额不足，请充值！\n");
        Back();
        return;
    }
    if(player->bag.sum >= player->bag.max)
    {
        printf("背包已经满了，请先整理背包！\n");
        Back();
        return;
    }
    tradecommodity->sum-=number;
    player->money-=(tradecommodity->price)*number;
    for(i=0;i<player->bag.sum;i++)
    {
        if(commodityID == player->bag.playcommoditys[i].id)
        {
            player->bag.playcommoditys[i].sum+=number;
            break;
        }
    }
    if(i==player->bag.sum)
    {
        //向背包中创建一个商品
        int n=player->bag.sum;
        player->bag.playcommoditys[n].id=tradecommodity->id;
        player->bag.playcommoditys[n].price=tradecommodity->price;
        strcpy(&player->bag.playcommoditys[n].name,&tradecommodity->name);
        strcpy(&player->bag.playcommoditys[n].effect,&tradecommodity->effect);
        player->bag.playcommoditys[n].sum+=number;
        player->bag.sum++;
    }
    printf("是否继续购买商品(y/n)?\n");
    f=getch();
    }while(f == 'y' || f== 'Y');

    //满足条件，执行操作
    /*
    1.商品库存-1
    2.玩家金币扣除
    3.玩家背包道具增加（判断背包是否已有商品）
    */
}
























