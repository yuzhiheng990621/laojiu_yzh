#ifndef SHOPPING_H_INCLUDED
#define SHOPPING_H_INCLUDED
//商品结构体
typedef struct _commodity
{
    int id;//商品编号
    char *name;//商品名
    int price;//商品价格
    char *effect;//商品效果
    int sum;//商品库存
}Commodity;
//背包结构体
typedef struct _bag
{
    int id;//背包对应编号
    Commodity playcommoditys[20];//道具数
    int sum;//当前背包道具的数量
    int max;//最大道具数

}Bag;
//技能结构体
typedef struct _abillity
{
    int id;
    int name;
    char *effect;
}Abillity;
//玩家结构体
typedef struct _player
{
    int id;
    char *name;
    Bag bag;
    int money;//金币
    /*int hp;
    int mo;
    Abillity abillity;
    int level;
    long long EXP;
    long long exp;
    int atk;
    int def;*/

}Player;
void init();                //用于初始化数据
void putcommodity();        //动态录入商品信息
void showcommodity();       //输出商品信息
void showplayer();          //用于打印玩家信息
void trade(Player *player);//交易函数
void Back();//输入回车返回


#endif // SHOPPING_H_INCLUDED
