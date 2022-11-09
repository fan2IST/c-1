// ch2-2.c  求两个集合的交集
#include <stdlib.h>
#include <stdio.h>
#define ElemType int

//定义单链表结点类型
typedef struct LNode
{
    ElemType data;      //数据域
    struct LNode *next; //指针域
} LNode;

//用尾插法建立单链表，返回头指针
LNode *create(ElemType data[], int n)
{
    LNode *head, *p, *rear;
    int k;
    head = (LNode *)malloc(sizeof(LNode)); //生成头结点
    head->next = NULL;                     //第一个结点为空
    rear = head;                           //尾指针指向头结点
    for (k = 0; k < n; k++)                //用尾插法插入n个结点
    {
        p = (LNode *)malloc(sizeof(LNode)); //生成新结点
        p->data = data[k];                  //为新结点的数据域赋值
        p->next = NULL;                     //新结点的指针域为空
        rear->next = p;                     //将新结点插入链表末尾
        rear = p;                           //尾指针指向新插入结点
    }
    return head; //返回头指针
}

//输出链表中的数据元素
void display(LNode *head)
{
    LNode *p;
    p = head->next; //指针p指向链表中第一个结点
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next; //指针p指向下一结点
    }
    printf("\n");
}

//输出两个集合交集
LNode *inter(LNode *head1, LNode *head2)
{
    LNode *p, *q, *head3, *s;
    head3 = (LNode *)malloc(sizeof(LNode)); //生成新链表的头结点
    p = head1->next;                        //指针p指向链表1的第一个结点
    q = head2->next;                        //指针q指向链表2的第一个结点
    head3->next = NULL;
    while (p)
    {
        while (q)
        {
            if (p->data == q->data) //两个结点的数值相等
            {
                s = (LNode *)malloc(sizeof(LNode)); //生成新结点
                s->data = p->data;                  //为新结点的数据域赋值
                s->next = head3->next;              //将新结点插入表头
                head3->next = s;
                break;
            }
            else
                q = q->next; //指针q指向链表2中的下一结点
        }
        p = p->next;     //指针p指向链表1中的下一结点
        q = head2->next; //指针q返回到链表2中第一个结点
    }
    return head3;
}

int main()
{
    int data1[10], data2[10];
    int num1, num2, i;
    LNode *h1, *h2, *h3;
    printf("输入集合A中的元素数：");
    scanf("%d", &num1);
    printf("输入集合A中的数据元素：");
    for (i = 0; i < num1; i++)
        scanf("%d", &data1[i]);
    printf("输入集合B中的元素数：");
    scanf("%d", &num2);
    printf("输入集合B中的数据元素：");
    for (i = 0; i < num2; i++)
        scanf("%d", &data2[i]);
    h1 = create(data1, num1); //生成链表1
    h2 = create(data2, num2); //生成链表2
    printf("生成如下两个链表\n");
    printf("链表1：");
    display(h1); //输出链表1中数据元素
    printf("链表2：");
    display(h2);        //输出链表2中数据元素
    h3 = inter(h1, h2); //输出两个集合的交集
    printf("两个集合的交集：");
    display(h3);
}
/*【程序测试】
输入集合A中的元素数：5↙
输入集合A中的数据元素：9 4 0 7 1↙
输入集合B中的元素数：6↙
输入集合B中的数据元素：6 4 7 3 5 9↙
生成如下两个链表
链表1：9 4 0 7 1
链表2：6 4 7 3 5 9
两个集合的交集：7 4 9
*/