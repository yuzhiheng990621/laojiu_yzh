#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 7   //系统最多队员数
int main()
{
    int i;
    int j;
    int day = 1;
    int count = 5;//当前队员个数
    char name[20];//名字
    int choice;//选择
    char one[20];
    char names[MAX][20] = {"大乔","小乔","赵云","李白","韩信"};
    char levelnames[9][10] = {"锻体","练气","筑基","虚丹","金丹","元婴","化身","渡劫","飞升"};
    char levelloves[10][10] = {"一品","二品","三品","四品","五品","六品","七品","八品","九品","归一"};
    //级别
    int levels[MAX] = {1,1,0,0,0,-1,-1};//对应级别
    int loves[MAX] = {7,5,6,4,8,-1,-1};//初始品级
    printf("*****************************************\n");
    printf("欢迎来到504修仙营╰(*°▽°*)╯\n");
    printf("*****************************************\n");
    printf("来吧！创造你自己的修仙小队O(∩_∩)O\n");
    printf("*****************************************\n");
    printf("请输入导师名号：");
    scanf("%s",name);//录入字符串不需要&
    for(;;)
    {
    printf("%s,您好!╰(*°▽°*)╯\n",name);
    printf("当前队员状态\n");
    printf("*****************************************\n");
    printf("名字\t级别\t品级\n");
    for(i=0;i<count;i++)
    {
        printf("%s\t%s\t%s\n",names[i],levelnames[levels[i]],levelloves[loves[i]]);
    }
    printf("*****************************************\n");
    printf("输入回车继续\n");
    day++;
    getchar();
    getchar();
    //打印菜单
    printf("*****************************************\n");
    printf("你将训练你的队伍，使其成为最强修仙团队\n");
    printf("*****************************************\n");
    printf("现在是第%d天\n",day);
    printf("*****************************************\n");
    printf("1.挑选新的队员.\t\t(增加功能)\n");
    printf("2.单独训练队员.\t\t(修改状态功能)\n");
    printf("3.淘汰队员!\t\t(删除功能)\n");
    printf("4.恶意调教队员。\n");//待添加
    printf("请选择: \n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        //添加队员
        //增加数组（names,loves,levels）
        if(count >= MAX)
            printf("队员已满无法招新\n");
        else
        {//执行添加操作
            printf("请输入新队员的姓名：");
            scanf("%s",names[count]);
            //将第count个元素的状态初始化（级别，熟练度）
            levels[count] = 0;//初始为零
            loves[count] = 3;//初始为零
            printf("一天过去了。\n由于招新精力分散，原成员熟练度下降10\n");
            for(i=0;i<count;i++)
    {   //根据规则处理数据
        loves[i]--;
        if(loves[i]==-1)
            {
                loves[i]=9;
                levels[i]--;
                if(levels[i]==-1)
                    {   printf("有队员失去仙资，你被其他队员抛弃了\n**********************游戏结束*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("修炼如逆水行舟，不进则退！\n%s由%s掉级为%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
    }
        count++;
        //添加完毕
        }
    break;
    case 2:
        //单独训练队员
        //该队员熟练度增加2，其他减少1
        printf("您想单练的队员是：");
        scanf("%s",one);//使one[]储存名字
        //查找出相应的数据
        for(i=0;i<count;i++)
        {   //字符串查找strcmp(),需要引入头文件<string.h>
            //strcmp(one，"")=0表示字符串相等
            //-1表示前大于后
            if(strcmp(one,names[i])==0)
            {
            loves[i]+=2;
            //级别注意不能超过上限
            if(loves[i]>10)
            {
                levels[i]++;
            loves[i]=0;
            }
            }
            else
            loves[i]--;
            if(loves[i]==-1)
            {
                levels[i]--;
                loves[i]=9;
                if(levels[i]==-1)
                    {   printf("有队员因你失去仙资，你被其他队员抛弃了\n**********************游戏结束*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("修炼如逆水行舟，不进则退！\n%s由%s掉级为%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
        }
        break;
    case 3://淘汰队员
        printf("请输入要淘汰的队员：");
        scanf("%s",one);
        for(i=0;i<count;i++)
        {
            if(strcmp(one,names[i])==0)
            {
                count--;
                printf("%s不务正业，被逐出师门!\n",names[i]);
                for(j=i;j<count;j++)
                {
                    strcpy(names[j],names[i+1]);
                    loves[j]=loves[j+1];
                    levels[j]=levels[j+1];
                }
            }
            loves[i]--;
        if(loves[i]==-1)
            {
                loves[i]=9;
                levels[i]--;
                if(levels[i]==-1)
                    {   printf("有队员失去仙资，你被其他队员抛弃了\n**********************游戏结束*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("修炼如逆水行舟，不进则退！\n%s由%s掉级为%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
            }
        printf("由于忙于事情，忽视了对队员的管理\n");
        printf("3.！\n");
        break;
    case 4:
        printf("该功能未完善待修复\n");
        printf("请输入回车继续游戏\n");
        getchar();
        getchar();
        break;
    }
    }
    return 0;
}
