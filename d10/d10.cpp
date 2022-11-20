/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-11-09 14:06:27
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-11-09 14:19:33
 * @FilePath: \c-1\d10\d10.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-11-09 14:06:27
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-11-09 14:06:51
 * @FilePath: \c-1\d10\d10.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// ch5-2.c  输出二叉树中的叶子结点
#include <stdlib.h>
#include <stdio.h>
#define ElemType int

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

//求二叉树的高度
int Depth(BTree bt)
{
    int hl, hr;
    if (bt == NULL) // bt为空树，高度为0
        return 0;
    else // bt为非空
    {
        hl = Depth(bt->lchild); //求左子树的高度
        hr = Depth(bt->rchild); //求右子树的高度
        if (hl > hr)
            return (hl + 1);
        else
            return (hr + 1);
    }
}

int main()
{
    BTree T;
    int height;
    printf("输入二叉树中所有结点：\n");
    Create(&T);
    height = Depth(T);
    printf("该二叉树的高度为：%d\n", height);
}
// 【程序测试】
// 输入二叉树中所有结点：
// ABD#G###CE##FH###↙
// 该二叉树的高度为：4
