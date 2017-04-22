#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Shopping.h"
extern Player *players;
int main()
{
    //putcommodity();//动态录入商品信息
    init();
    showcommodity();//打印已有商品信息
    trade(&players[0]);
    showplayer();
    //1.初始化数据
    //2.打印数据

    return 0;
}
