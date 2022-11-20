/*
 * @Author: fanIST fanISTREC2DX@outlook.com
 * @Date: 2022-10-12 14:08:00
 * @LastEditors: fanIST fanISTREC2DX@outlook.com
 * @LastEditTime: 2022-10-12 14:18:15
 * @FilePath: \c-1\d4\d4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
void move(int n, char x, char z)
{
    printf("move disk %d from %c to %c\n", n, x, z);
}
void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        move(1, x, z);
    }
    else
    {
        Hanoi(n - 1, x, z, y);
        move(n, x, z);
        Hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int n;
    printf("input u disk:");
    scanf("%d", &n);
    Hanoi(n, 'X', 'Y', 'Z');
    return 0;
}
