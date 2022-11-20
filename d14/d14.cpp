/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-11-16 15:02:28
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-11-16 15:12:36
 * @FilePath: \c-1\d14\d14.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// ch5-2.c  判断二叉树是否为完全二叉树
#include <stdio.h>
#include <stdlib.h>
#define MAX 50 //二叉树中最大结点数

//定义结点类型
typedef struct BTNode
{
    char data;                      //数据元素
    struct BTNode *lchild, *rchild; //指向左、右孩子的指针
} BTNode, *BTree;

//按先序算法建立二叉树
void Create(BTree *T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BTree)malloc(sizeof(struct BTNode));
        (*T)->data = ch;
        Create(&((*T)->lchild)); //创建左子树
        Create(&((*T)->rchild)); //创建右子树
    }
}

//判断二叉树是否为完全二叉树
int TestComTree(BTree T)
{
    BTree Queue[MAX], p;
    int front, rear, flag = 1, comflag = 1;
    if (T) //若二叉树不空
    {
        Queue[0] = T;        //根结点进队
        front = -1;          //队头指针置初值
        rear = 0;            //队尾指针置初值
        while (front < rear) //队列不空
        {
            p = Queue[++front];    //队头元素出队送入p
            if (p->lchild == NULL) // p的左孩子为空
            {
                if (p->rchild != NULL) // p的右孩子不空
                {
                    comflag = 0; //此树不是完全二叉树
                    break;       //退出循环
                }
                flag = 0; // p的左、右孩子均为空
            }
            else // p的左孩子不空
            {
                if (flag == 0) //如果flag为0，则该树肯定不是完全二叉树
                {
                    comflag = 0; //设置标志
                    break;       //终止循环
                }
                Queue[++rear] = p->lchild;     // p的左孩子进队
                if (p->rchild != NULL)         // p的右孩子不空
                    Queue[++rear] = p->rchild; // p的右孩子进队
                else
                    flag = 0; // p的右孩子为空
            }
        }
    }
    return comflag;
}

int main()
{
    BTree T;
    int comflag;
    printf("Input elements:\n");
    Create(&T);
    comflag = TestComTree(T);
    if (comflag == 1)
        printf("这是一棵完全二叉树！\n");
    else
        printf("这棵树不是完全二叉树！\n");
}
// 【程序测试】
// Input elements:
// ABDH##I##E##CF##G##↙
// 这是一棵完全二叉树！
