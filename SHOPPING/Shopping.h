#ifndef SHOPPING_H_INCLUDED
#define SHOPPING_H_INCLUDED
//��Ʒ�ṹ��
typedef struct _commodity
{
    int id;//��Ʒ���
    char *name;//��Ʒ��
    int price;//��Ʒ�۸�
    char *effect;//��ƷЧ��
    int sum;//��Ʒ���
}Commodity;
//�����ṹ��
typedef struct _bag
{
    int id;//������Ӧ���
    Commodity playcommoditys[20];//������
    int sum;//��ǰ�������ߵ�����
    int max;//��������

}Bag;
//���ܽṹ��
typedef struct _abillity
{
    int id;
    int name;
    char *effect;
}Abillity;
//��ҽṹ��
typedef struct _player
{
    int id;
    char *name;
    Bag bag;
    int money;//���
    /*int hp;
    int mo;
    Abillity abillity;
    int level;
    long long EXP;
    long long exp;
    int atk;
    int def;*/

}Player;
void init();                //���ڳ�ʼ������
void putcommodity();        //��̬¼����Ʒ��Ϣ
void showcommodity();       //�����Ʒ��Ϣ
void showplayer();          //���ڴ�ӡ�����Ϣ
void trade(Player *player);//���׺���
void Back();//����س�����


#endif // SHOPPING_H_INCLUDED
