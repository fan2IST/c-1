/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-10-26 14:04:10
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-10-26 14:17:23
 * @FilePath: \c-1\d9\d92.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#define MAXLEN 255

//定义结构体类型
typedef struct
{
    char ch[MAXLEN]; //字符串数组
    int length;      //串的实际长度
} SString;

//返回串S的长度
int StrLength(SString S)
{
    int m;
    for (m = 1; S.ch[m] != '\0'; m++)
        ;
    S.length = m - 1;
    return (S.length);
}

//求模式串T的next值并存入数组next，为后面进行模式匹配做准备
void get_next(SString T, int *next)
{
    int j, k;
    j = 1;
    next[1] = 0;
    k = 0;
    while (j < StrLength(T))
    {
        if (k == 0 || T.ch[j] == T.ch[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

//利用next值求模式串T在主串S中第pos个字符之后的位置的KMP算法
int Index_KMP(SString S, SString T, int pos)
{
    int i, j;
    int next[MAXLEN];
    i = pos;
    j = 1;
    get_next(T, next);
    while (i <= StrLength(S) && j <= StrLength(T))
    {
        if (j == 0 || S.ch[i] == T.ch[j]) //继续比较下一个字符
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; //模式串向右移动
    }
    if (j > StrLength(T))
        return (i - StrLength(T)); //匹配成功，返回子串的位置
    else
        return 0; //匹配不成功，返回0
}

int main()
{
    SString S, T;
    int pos;
    int p;
    printf("输入主串S：");
    scanf("%s", S.ch + 1);
    printf("输入模式串T：");
    scanf("%s", T.ch + 1);
    printf("输入起始位置pos：");
    scanf("%d", &pos);
    if (p = Index_KMP(S, T, pos))
        printf("模式串在主串中的位置为：%d\n", p);
    else
        printf("匹配失败！\n");
}
// 【程序测试】
// 输入主串S：acabaabaabcacbc↙
// 输入模式串T：abaabc↙
// 输入起始位置pos：1↙
// 模式串在主串中的位置为：6
