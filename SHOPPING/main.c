#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Shopping.h"
extern Player *players;
int main()
{
    //putcommodity();//��̬¼����Ʒ��Ϣ
    init();
    showcommodity();//��ӡ������Ʒ��Ϣ
    trade(&players[0]);
    showplayer();
    //1.��ʼ������
    //2.��ӡ����

    return 0;
}
