// ch5-3.c 构造哈夫曼编码
#include <stdio.h>
#define MAX 50

//定义哈夫曼树的存储结构
typedef struct
{
    char data;  //结点的值
    int weight; //结点的权值
    int parent; //结点的双亲
    int lch;    //结点的左孩子
    int rch;    //结点的右孩子
} HuffNode;

//定义哈夫曼编码的存储结构
typedef struct
{
    char bit[MAX]; //存储叶子结点的二进制编码
    int start;     //二进制编码的起始位
} HuffCode;

HuffNode ht[2 * MAX];
HuffCode hcd[MAX];
int n;

//构造哈夫曼树
void HuffmanTree()
{
    int i, k, left, right, min1, min2;
    printf("输入叶子结点个数：");
    scanf("%d", &n);
    for (i = 1; i <= 2 * n - 1; i++) //对哈夫曼树中的结点进行初始化
    {
        ht[i].parent = ht[i].lch = ht[i].rch = 0;
    }
    for (i = 1; i <= n; i++)
    {
        getchar();
        printf("输入第%d个叶子结点的值：", i);
        scanf("%c", &ht[i].data);
        printf("输入该结点的权值：");
        scanf("%d", &ht[i].weight);
    }
    for (i = n + 1; i <= 2 * n - 1; i++)
    {                      //在前n个结点中选取权值最小的两个结点构成一棵二叉树
        min1 = min2 = 100; //为min1和min2设置一个比所有权值都大的值
        left = right = 0;
        for (k = 1; k <= i - 1; k++)
            if (ht[k].parent == 0) //若是根结点
                //令min1和min2为最小的两个权值，left和right为权值最小的两个						//结点的位置
                if (ht[k].weight < min1)
                {
                    min2 = min1;
                    right = left;
                    min1 = ht[k].weight;
                    left = k;
                }
                else if (ht[k].weight < min2)
                {
                    min2 = ht[k].weight;
                    right = k;
                }
        //把找到的两个结点构造成一棵二叉树
        ht[left].parent = i; //找到的两个结点的双亲为i
        ht[right].parent = i;
        ht[i].weight = ht[left].weight + ht[right].weight; // i的权值为两个结点的权值之和
        ht[i].lch = left;                                  //找到的两个结点分别为i的左、右孩子
        ht[i].rch = right;
    }
}

//构造哈夫曼编码
void HuffmanCode()
{
    int i, c, k, f;
    HuffCode cd;
    for (i = 1; i <= n; i++)
    {
        cd.start = n;
        c = i;            // c为要求编码的叶子结点
        f = ht[i].parent; // f为该叶子结点的双亲
        while (f != 0)
        {
            if (ht[f].lch == c) //若当前结点为左孩子，则编码为0
                cd.bit[cd.start] = '0';
            else //若当前结点为右孩子，则编码为1
                cd.bit[cd.start] = '1';
            cd.start--;
            c = f;            //令c为双亲结点
            f = ht[f].parent; //令f为双亲结点的双亲
        }
        hcd[i] = cd;
    }
    printf("输出哈夫曼编码：\n");
    for (i = 1; i <= n; i++) //逐个输出各叶子结点的哈夫曼编码
    {
        printf("%c: ", ht[i].data);
        for (k = hcd[i].start + 1; k <= n; k++) //逐位输出叶子结点的哈夫曼编码
            printf("%c", hcd[i].bit[k]);
        printf("\n");
    }
}

int main()
{
    HuffmanTree();
    HuffmanCode();
}
// 【程序测试】
// 输入叶子结点个数：8↙
// 输入第1个叶子结点的值：a↙
// 输入该结点的权值：7↙
// 输入第2个叶子结点的值：b↙
// 输入该结点的权值：3↙
// 输入第3个叶子结点的值：c↙
// 输入该结点的权值：5↙
// 输入第4个叶子结点的值：d↙
// 输入该结点的权值：8↙
// 输入第5个叶子结点的值：e↙
// 输入该结点的权值：2↙
// 输入第6个叶子结点的值：f↙
// 输入该结点的权值：6↙
// 输入第7个叶子结点的值：g↙
// 输入该结点的权值：9↙
// 输入第8个叶子结点的值：h↙
// 输入该结点的权值：10↙
// 输出哈夫曼编码：
// a: 101
// b: 0111
// c: 010
// d: 110
// e: 0110
// f: 100
// g: 111
// h: 00
