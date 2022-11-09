/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-10-19 14:07:00
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-10-19 14:31:12
 * @FilePath: \c-1\d7\d7.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// ch3-4.c 打印杨辉三角
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20 //定义循环队列的最大长度

//定义循环队列的类型
typedef struct
{
    int elem[MAXSIZE];
    int front; //头指针
    int rear;  //尾指针
} SeqQueue;

//将 Q初始化为一个空的循环队列
void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}

//将数据元素e插入到队列中
void EnQueue(SeqQueue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) //队列已满，插入失败
        printf("Queue is full!\n");
    Q->elem[Q->rear] = e;              //将e插入队尾
    Q->rear = (Q->rear + 1) % MAXSIZE; //重新设置尾指针
}

//若队列不空，则删除Q的队头元素，并用e返回其值
void DeQueue(SeqQueue *Q, int *e)
{
    if (Q->front == Q->rear) //队列空，删除失败
        printf("Queue is empty!\n");
    *e = Q->elem[Q->front];              //用e返回队头元素
    Q->front = (Q->front + 1) % MAXSIZE; //重新设置头指针
}

//若队列不空，则用e返回队头元素
void GetFront(SeqQueue *Q, int *e)
{
    if (Q->front == 0 && Q->rear == 0)
        printf("Queue is empty!\n");
    *e = Q->elem[Q->front]; //保存队头元素
}

//打印杨辉三角
void YangHui(int n)
{
    int i, j, k = 0;
    int temp, x;
    SeqQueue Q;
    InitQueue(&Q);           //初始化队列
    EnQueue(&Q, 1);          //第一行数据进队
    for (i = 2; i <= n; i++) //打印第n-1行数据，同时得到第n行数据并进队
    {
        for (k = 1; k <= 40 - (i - 2) * 2; k++) //打印前导空格
            printf(" ");
        EnQueue(&Q, 1); //第n行的第一个数据1进队
        for (j = 1; j <= i - 2; j++)
        { //第i－1行数据逐个出队并打印，同时生成第i行的中间i－2个数据并进队
            DeQueue(&Q, &temp);
            printf("%d  ", temp);
            GetFront(&Q, &x); //取队头元素
            temp = temp + x;
            EnQueue(&Q, temp);
        }
        DeQueue(&Q, &temp); //第n-1行最后一个元素出队
        printf("%d\n", temp);
        EnQueue(&Q, 1); //第n行最后一个元素进队
    }
    for (k = 1; k <= 40 - (n - 1) * 2; k++) //打印前导空格
        printf(" ");
    for (i = 1; i <= n; i++) //打印第n行数据
    {
        DeQueue(&Q, &temp);
        printf("%d  ", temp);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("请输入杨辉三角的行数：");
    scanf("%d", &n);
    YangHui(n);
}
