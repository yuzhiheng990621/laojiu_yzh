#include "Shopping.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Commodity commodity[1000]={
 {1,"��������̾Ϣ",200,"�޶���ʱ���������쳣״̬",10}
,{2,"�����˵ķ�ŭ",200,"���з�����ŷ��+1",10}
,{3,"�������ñ",500,"ʹĿ��ԭ��һ��",10}
,{4,"�޵к�ְ�",1000,"�����޵�һ����",10}
,{5,"����ô?���ֵ�",298,"�����������̾ϢBuff",10}
};
int count=5;
int playercount=0;
Player *players;
void Back()//����س�����
{
    printf("����س����أ�\n\n");
    getchar();
    getchar();
}
void init()
{
static Player player[]={
{1,"������Ů",{1,.max=20,.sum=0},.money=5000,}
};
playercount=sizeof(player)/sizeof(Player);
players=player;
}



//��Ʒ��Ϣ
/*
    int id;//��Ʒ���
    char *name;//��Ʒ��
    int price;//��Ʒ�۸�
    char *effect;//��ƷЧ��
*/
void showcommodity()
{
    int i;
    printf("������Ʒ:\n");
    for(i=0;i<count;i++)
    {
    printf("%d.%s\t�۸�:%d��\t���:%d��\tЧ��:%s\n",commodity[i].id,commodity[i].name,commodity[i].price,commodity[i].sum,commodity[i].effect);
    }
}
void putcommodity()
{
    char f;
    do{
    count++;
printf("*********************************\n");
    printf("��������Ʒ��Ϣ\n");
    printf("��Ʒ%d\n",count);
    commodity[count-1].id=count;
    printf("    ����:");
    commodity[count-1].name=calloc(50,1);
    scanf("%s",commodity[count-1].name);
    printf("�۸�(��):");
    scanf("%d",&commodity[count-1].price);
    printf("��ƷЧ��:");
    commodity[count-1].effect=calloc(200,1);
    scanf("%s",commodity[count-1].effect);
    printf("��Ʒ��ʼ���:");
    scanf("%d",&commodity[count-1].sum);
printf("*********************************\n");
    printf("�Ƿ����¼����Ʒ��Ϣ(y/n)?\n");
    f=getch();
    }while(f == 'y' || f== 'Y');
}
void showplayer()
{
    int i,j;
    if(players==NULL) return;
    printf("���:\n");
    for(i=0;i<playercount;i++)
    {
    printf("���:%d\t����:%s\tǮ��:%d��\n����:\n",players[i].id,players[i].name,players[i].money);
        for(j=0;j<players->bag.sum;j++)
        {
            printf("%sX%d\tЧ��:%s\n",players->bag.playcommoditys[j].name,players->bag.playcommoditys[j].sum,players->bag.playcommoditys[j].effect);
        }
        if(j==0)
        {
            printf("��.\n");
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
    printf("������Ҫ�������Ʒ���:");
    scanf("%d",&commodityID);
    printf("������Ҫ���������:");
    scanf("%d",&number);
    //commodityID��ʾҪ�������Ʒ���
    //�жϣ���Ʒ�����û�У���ҵ�Ǯ�ҹ���������ұ�����С������
    Commodity *tradecommodity;//Ҫ�������Ʒָ��
    for(i=0;i<count;i++)
    {
        if(commodityID==commodity[i].id)
        {tradecommodity=&commodity[i];}//�������ҵ�����Ʒ
    }
    if((tradecommodity->sum)-number < 0)
    {
        printf("����Ʒ��治�㣡ʣ��%d��\n",tradecommodity->sum);
        Back();
        return;
    }
    if(player->money < (tradecommodity->price)*number)
    {
        printf("���㣬���ֵ��\n");
        Back();
        return;
    }
    if(player->bag.sum >= player->bag.max)
    {
        printf("�����Ѿ����ˣ�������������\n");
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
        //�򱳰��д���һ����Ʒ
        int n=player->bag.sum;
        player->bag.playcommoditys[n].id=tradecommodity->id;
        player->bag.playcommoditys[n].price=tradecommodity->price;
        strcpy(&player->bag.playcommoditys[n].name,&tradecommodity->name);
        strcpy(&player->bag.playcommoditys[n].effect,&tradecommodity->effect);
        player->bag.playcommoditys[n].sum+=number;
        player->bag.sum++;
    }
    printf("�Ƿ����������Ʒ(y/n)?\n");
    f=getch();
    }while(f == 'y' || f== 'Y');

    //����������ִ�в���
    /*
    1.��Ʒ���-1
    2.��ҽ�ҿ۳�
    3.��ұ����������ӣ��жϱ����Ƿ�������Ʒ��
    */
}
























