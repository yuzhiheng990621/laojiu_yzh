#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 7   //ϵͳ����Ա��
int main()
{
    int i;
    int j;
    int day = 1;
    int count = 5;//��ǰ��Ա����
    char name[20];//����
    int choice;//ѡ��
    char one[20];
    char names[MAX][20] = {"����","С��","����","���","����"};
    char levelnames[9][10] = {"����","����","����","�鵤","��","ԪӤ","����","�ɽ�","����"};
    char levelloves[10][10] = {"һƷ","��Ʒ","��Ʒ","��Ʒ","��Ʒ","��Ʒ","��Ʒ","��Ʒ","��Ʒ","��һ"};
    //����
    int levels[MAX] = {1,1,0,0,0,-1,-1};//��Ӧ����
    int loves[MAX] = {7,5,6,4,8,-1,-1};//��ʼƷ��
    printf("*****************************************\n");
    printf("��ӭ����504����Ӫ�t(*�㨌��*)�s\n");
    printf("*****************************************\n");
    printf("���ɣ��������Լ�������С��O(��_��)O\n");
    printf("*****************************************\n");
    printf("�����뵼ʦ���ţ�");
    scanf("%s",name);//¼���ַ�������Ҫ&
    for(;;)
    {
    printf("%s,����!�t(*�㨌��*)�s\n",name);
    printf("��ǰ��Ա״̬\n");
    printf("*****************************************\n");
    printf("����\t����\tƷ��\n");
    for(i=0;i<count;i++)
    {
        printf("%s\t%s\t%s\n",names[i],levelnames[levels[i]],levelloves[loves[i]]);
    }
    printf("*****************************************\n");
    printf("����س�����\n");
    day++;
    getchar();
    getchar();
    //��ӡ�˵�
    printf("*****************************************\n");
    printf("�㽫ѵ����Ķ��飬ʹ���Ϊ��ǿ�����Ŷ�\n");
    printf("*****************************************\n");
    printf("�����ǵ�%d��\n",day);
    printf("*****************************************\n");
    printf("1.��ѡ�µĶ�Ա.\t\t(���ӹ���)\n");
    printf("2.����ѵ����Ա.\t\t(�޸�״̬����)\n");
    printf("3.��̭��Ա!\t\t(ɾ������)\n");
    printf("4.������̶�Ա��\n");//�����
    printf("��ѡ��: \n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        //��Ӷ�Ա
        //�������飨names,loves,levels��
        if(count >= MAX)
            printf("��Ա�����޷�����\n");
        else
        {//ִ����Ӳ���
            printf("�������¶�Ա��������");
            scanf("%s",names[count]);
            //����count��Ԫ�ص�״̬��ʼ�������������ȣ�
            levels[count] = 0;//��ʼΪ��
            loves[count] = 3;//��ʼΪ��
            printf("һ���ȥ�ˡ�\n�������¾�����ɢ��ԭ��Ա�������½�10\n");
            for(i=0;i<count;i++)
    {   //���ݹ���������
        loves[i]--;
        if(loves[i]==-1)
            {
                loves[i]=9;
                levels[i]--;
                if(levels[i]==-1)
                    {   printf("�ж�Աʧȥ���ʣ��㱻������Ա������\n**********************��Ϸ����*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("��������ˮ���ۣ��������ˣ�\n%s��%s����Ϊ%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
    }
        count++;
        //������
        }
    break;
    case 2:
        //����ѵ����Ա
        //�ö�Ա����������2����������1
        printf("���뵥���Ķ�Ա�ǣ�");
        scanf("%s",one);//ʹone[]��������
        //���ҳ���Ӧ������
        for(i=0;i<count;i++)
        {   //�ַ�������strcmp(),��Ҫ����ͷ�ļ�<string.h>
            //strcmp(one��"")=0��ʾ�ַ������
            //-1��ʾǰ���ں�
            if(strcmp(one,names[i])==0)
            {
            loves[i]+=2;
            //����ע�ⲻ�ܳ�������
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
                    {   printf("�ж�Ա����ʧȥ���ʣ��㱻������Ա������\n**********************��Ϸ����*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("��������ˮ���ۣ��������ˣ�\n%s��%s����Ϊ%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
        }
        break;
    case 3://��̭��Ա
        printf("������Ҫ��̭�Ķ�Ա��");
        scanf("%s",one);
        for(i=0;i<count;i++)
        {
            if(strcmp(one,names[i])==0)
            {
                count--;
                printf("%s������ҵ�������ʦ��!\n",names[i]);
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
                    {   printf("�ж�Աʧȥ���ʣ��㱻������Ա������\n**********************��Ϸ����*******************\n");
                        for(;;)
                        {
                            return 0;
                        }
                    }
                printf("��������ˮ���ۣ��������ˣ�\n%s��%s����Ϊ%s\n",names[i],levelnames[levels[i]+1],levelnames[levels[i]]);
                }
            }
        printf("����æ�����飬�����˶Զ�Ա�Ĺ���\n");
        printf("3.��\n");
        break;
    case 4:
        printf("�ù���δ���ƴ��޸�\n");
        printf("������س�������Ϸ\n");
        getchar();
        getchar();
        break;
    }
    }
    return 0;
}
